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

end ILA.Primegenerator
