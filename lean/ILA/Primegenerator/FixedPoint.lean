import ILA.Primegenerator.Energy
import ILA.Primegenerator.PrimeGen

namespace ILA.Primegenerator

open ILA.Provider

/-- 位相干渉場における安定固定点（エネルギー極小） -/
def isStableFixedPoint (n : Nat) : Prop :=
  n > 1 ∧ interferenceEnergy n = 0

/-- 従来の素数定義 -/
def isPrime (n : Nat) : Prop :=
  n > 1 ∧ ∀ m, 1 < m → m < n → n % m ≠ 0

/-- PrimeGenerator が生成する値の固定点契約。 -/
def generates (_g : PrimeGenerator) (n : Nat) : Prop :=
  n > 1 ∧ ∀ m, 1 < m → m < n → n % m ≠ 0

theorem interferenceEnergy_eq_zero_iff_no_nontrivial_divisors (n : Nat) :
    interferenceEnergy n = 0 ↔ ∀ m, 1 < m → m < n → n % m ≠ 0 := by
  unfold interferenceEnergy
  by_cases hn : n > 1
  · simp [hn, List.length_eq_zero_iff, List.filter_eq_nil_iff, List.mem_range]
    constructor
    · intro h m hm_gt_one hm_lt_n
      exact h m hm_lt_n hm_gt_one hm_lt_n
    · intro h m _ hm_gt_one hm_lt_n
      exact h m hm_gt_one hm_lt_n
  · simp [hn]
    intro m hm_gt_one hm_lt_n _
    exact (hn (Nat.lt_trans hm_gt_one hm_lt_n)).elim

theorem PrimeGenerator_stable_sound
  (g : PrimeGenerator) (n : Nat) :
  generates g n → isStableFixedPoint n := by
  intro hgenerated
  exact
    ⟨hgenerated.1,
      (interferenceEnergy_eq_zero_iff_no_nontrivial_divisors n).2 hgenerated.2⟩

theorem PrimeGenerator_complete
  (g : PrimeGenerator) (n : Nat) :
  isPrime n → generates g n := by
  intro hprime
  unfold isPrime at hprime
  unfold generates
  exact hprime

theorem PrimeGenerator_generates_iff_prime
  (g : PrimeGenerator) (n : Nat) :
  generates g n ↔ isPrime n := by
  constructor
  · intro hgenerated
    unfold generates at hgenerated
    unfold isPrime
    exact hgenerated
  · exact PrimeGenerator_complete g n

theorem interferenceEnergy_nonneg (n : Nat) :
  0 ≤ interferenceEnergy n := by
  exact Nat.zero_le (interferenceEnergy n)

theorem interferenceEnergy_pos_of_composite
  (n : Nat) (hgt : 1 < n) (hnot_prime : ¬ isPrime n) :
  interferenceEnergy n > 0 := by
  have hne : interferenceEnergy n ≠ 0 := by
    intro hzero
    apply hnot_prime
    exact ⟨hgt, (interferenceEnergy_eq_zero_iff_no_nontrivial_divisors n).1 hzero⟩
  exact Nat.pos_of_ne_zero hne

theorem interferenceEnergy_divisor_monotone
  {m n : Nat} (hdiv : m ∣ n) (h1 : 1 < m) (h2 : m < n) :
  interferenceEnergy m ≤ interferenceEnergy n := by
  unfold interferenceEnergy
  have hm : m > 1 := h1
  have hn : n > 1 := Nat.lt_trans h1 h2
  simp [hm, hn]
  let pm : Nat → Bool :=
    fun k => decide (1 < k) && (decide (k < m) && decide (m % k = 0))
  let pn : Nat → Bool :=
    fun k => decide (1 < k) && (decide (k < n) && decide (n % k = 0))
  change ((List.range m).filter pm).length ≤ ((List.range n).filter pn).length
  apply List.Subperm.length_le
  apply List.subperm_of_subset
  · exact List.Nodup.filter pm List.nodup_range
  · intro k hk
    have hmem : k ∈ List.range m ∧ pm k = true := (List.mem_filter).mp hk
    have hk_range_m : k ∈ List.range m := hmem.1
    have hpm_true : pm k = true := hmem.2
    have hk_lt_m : k < m := (List.mem_range).mp hk_range_m
    have hpm_prop : 1 < k ∧ k < m ∧ m % k = 0 := by
      simp [pm] at hpm_true
      exact hpm_true
    have hk_gt_one : 1 < k := hpm_prop.1
    have hm_mod : m % k = 0 := hpm_prop.2.2
    have hk_dvd_m : k ∣ m := Nat.dvd_of_mod_eq_zero hm_mod
    have hk_dvd_n : k ∣ n := Nat.dvd_trans hk_dvd_m hdiv
    have hn_mod : n % k = 0 := Nat.mod_eq_zero_of_dvd hk_dvd_n
    apply (List.mem_filter).mpr
    constructor
    · exact (List.mem_range).mpr (Nat.lt_trans hk_lt_m h2)
    · simp [pn, hk_gt_one, Nat.lt_trans hk_lt_m h2, hn_mod]

theorem interferenceEnergy_ge_one_of_has_nontrivial_divisor
  (n m : Nat) (h1 : 1 < m) (h2 : m < n) (hdiv : m ∣ n) :
  interferenceEnergy n ≥ 1 := by
  unfold interferenceEnergy
  have hn : n > 1 := Nat.lt_trans h1 h2
  simp [hn]
  let p : Nat → Bool :=
    fun k => decide (1 < k) && (decide (k < n) && decide (n % k = 0))
  change 1 ≤ ((List.range n).filter p).length
  apply Nat.succ_le_of_lt
  apply List.length_pos_of_mem (a := m)
  apply (List.mem_filter).mpr
  constructor
  · exact (List.mem_range).mpr h2
  · have hmod : n % m = 0 := Nat.mod_eq_zero_of_dvd hdiv
    simp [p, h1, h2, hmod]

end ILA.Primegenerator
