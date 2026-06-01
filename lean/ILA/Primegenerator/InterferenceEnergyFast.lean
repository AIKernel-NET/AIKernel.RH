import Mathlib.Data.Finset.Card
import Mathlib.Data.Finset.Filter
import Mathlib.Data.Finset.Range
import ILA.Primegenerator.FixedPoint

namespace ILA.Primegenerator

private def interferenceEnergy_old : Nat → Nat :=
  interferenceEnergy

/--
Finset-based implementation of interference energy.

The semantic predicate is identical to `interferenceEnergy`; only the
enumeration structure is expressed through `Finset.range` and
`Finset.filter`.
-/
def interferenceEnergy_fast (n : Nat) : Nat :=
  if _h : n > 1 then
    Finset.card
      (Finset.filter
        (fun k => k > 1 ∧ k < n ∧ n % k = 0)
        (Finset.range n))
  else
    0

lemma interferenceEnergy_fast_eq_old (n : Nat) :
    interferenceEnergy_fast n = interferenceEnergy_old n := by
  unfold interferenceEnergy_fast interferenceEnergy_old interferenceEnergy
  by_cases hn : n > 1
  · simp [hn, Finset.card_def, Finset.filter_val, Finset.range_val,
      Multiset.range, Multiset.filter_coe, Multiset.coe_card]
  · simp [hn]

lemma interferenceEnergy_fast_eq_interferenceEnergy (n : Nat) :
    interferenceEnergy_fast n = interferenceEnergy n := by
  simpa [interferenceEnergy_old] using interferenceEnergy_fast_eq_old n

lemma interferenceEnergy_fast_nonneg (n : Nat) :
    0 ≤ interferenceEnergy_fast n := by
  exact Nat.zero_le (interferenceEnergy_fast n)

private lemma mod12_not_candidate_dvd_two_or_three
    (n : Nat) (h : n % 12 ∉ ({1, 5, 7, 11} : Finset Nat)) :
    2 ∣ n ∨ 3 ∣ n := by
  let r := n % 12
  have hlt : r < 12 := Nat.mod_lt n (by decide)
  have hrnot : r ≠ 1 ∧ r ≠ 5 ∧ r ≠ 7 ∧ r ≠ 11 := by
    simpa [r] using h
  have hr :
      r = 0 ∨ r = 2 ∨ r = 3 ∨ r = 4 ∨
        r = 6 ∨ r = 8 ∨ r = 9 ∨ r = 10 := by
    omega
  rcases hr with h0 | h2 | h3 | h4 | h6 | h8 | h9 | h10
  · left
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 2 ∣ 12)]
    change r % 2 = 0
    rw [h0]
  · left
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 2 ∣ 12)]
    change r % 2 = 0
    rw [h2]
  · right
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 3 ∣ 12)]
    change r % 3 = 0
    rw [h3]
  · left
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 2 ∣ 12)]
    change r % 2 = 0
    rw [h4]
  · left
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 2 ∣ 12)]
    change r % 2 = 0
    rw [h6]
  · left
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 2 ∣ 12)]
    change r % 2 = 0
    rw [h8]
  · right
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 3 ∣ 12)]
    change r % 3 = 0
    rw [h9]
  · left
    apply Nat.dvd_of_mod_eq_zero
    rw [← Nat.mod_mod_of_dvd n (by decide : 2 ∣ 12)]
    change r % 2 = 0
    rw [h10]

lemma interferenceEnergy_fast_prune_mod12
  (n : Nat)
  (hgt : 3 < n)
  (h : n % 12 ∉ ({1, 5, 7, 11} : Finset Nat)) :
  interferenceEnergy_fast n > 0 := by
  have hdiv := mod12_not_candidate_dvd_two_or_three n h
  have hold_pos : interferenceEnergy n > 0 := by
    rcases hdiv with htwo | hthree
    · have h2lt : 2 < n := Nat.lt_trans (by decide : 2 < 3) hgt
      have hge : interferenceEnergy n ≥ 1 :=
        interferenceEnergy_ge_one_of_has_nontrivial_divisor n 2 (by decide) h2lt htwo
      exact Nat.lt_of_lt_of_le Nat.zero_lt_one hge
    · have h3lt : 3 < n := hgt
      have hge : interferenceEnergy n ≥ 1 :=
        interferenceEnergy_ge_one_of_has_nontrivial_divisor n 3 (by decide) h3lt hthree
      exact Nat.lt_of_lt_of_le Nat.zero_lt_one hge
  simpa [interferenceEnergy_fast_eq_interferenceEnergy n] using hold_pos

lemma finset_mem_filtered_divisors_iff (n m : Nat) :
    m ∈ Finset.filter
      (fun k => k > 1 ∧ k < n ∧ n % k = 0)
      (Finset.range n)
      ↔ m < n ∧ 1 < m ∧ m ∣ n := by
  constructor
  · intro hm
    have hmem := (Finset.mem_filter.mp hm)
    have hlt_range : m < n := Finset.mem_range.mp hmem.1
    have hprop : m > 1 ∧ m < n ∧ n % m = 0 := hmem.2
    exact ⟨hlt_range, hprop.1, Nat.dvd_of_mod_eq_zero hprop.2.2⟩
  · intro hm
    rcases hm with ⟨hm_lt, hm_gt, hm_dvd⟩
    apply Finset.mem_filter.mpr
    exact ⟨Finset.mem_range.mpr hm_lt,
      ⟨hm_gt, hm_lt, Nat.mod_eq_zero_of_dvd hm_dvd⟩⟩

end ILA.Primegenerator
