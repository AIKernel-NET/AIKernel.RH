import ILA.Primegenerator.Theorems

namespace ILA.Primegenerator

/--
OS-style normalization gate for the dynamic prime generator.

Inputs `0` and `1` are treated as unnormalized and sent to `2`.
For normalized inputs, energy-zero points are fixed; all other points
are sent to the canonical stable prime `2`.
-/
def step (n : Nat) : Nat :=
  if _h : n < 2 then
    2
  else if _hE : interferenceEnergy n = 0 then
    n
  else
    2

theorem interferenceEnergy_two_eq_zero :
  interferenceEnergy 2 = 0 := by
  apply (interferenceEnergy_eq_zero_iff_no_nontrivial_divisors 2).2
  intro m hm hlt _
  have hm_le_one : m ≤ 1 := Nat.le_of_lt_succ hlt
  exact (Nat.not_lt_of_ge hm_le_one) hm

theorem two_isStableFixedPoint :
  isStableFixedPoint 2 := by
  exact ⟨by decide, interferenceEnergy_two_eq_zero⟩

theorem step_zero :
  step 0 = 2 := by
  simp [step]

theorem step_one :
  step 1 = 2 := by
  simp [step]

private theorem not_lt_two_of_one_lt {n : Nat} (h : 1 < n) :
    ¬ n < 2 := by
  intro hn
  have hn_le_one : n ≤ 1 := Nat.le_of_lt_succ hn
  exact (Nat.not_lt_of_ge hn_le_one) h

private theorem one_lt_of_not_lt_two {n : Nat} (h : ¬ n < 2) :
    1 < n := by
  exact Nat.lt_of_lt_of_le (by decide : 1 < 2) (Nat.le_of_not_gt h)

theorem step_of_one_lt (n : Nat) (h : 1 < n) :
    step n = if _hE : interferenceEnergy n = 0 then n else 2 := by
  unfold step
  have hnlt : ¬ n < 2 := not_lt_two_of_one_lt h
  simp [hnlt]

theorem step_eq_self_of_energy_zero (n : Nat) (h : 1 < n)
    (hE : interferenceEnergy n = 0) :
    step n = n := by
  rw [step_of_one_lt n h]
  simp [hE]

theorem step_fixed_iff (n : Nat) (h : 1 < n) :
    step n = n ↔ interferenceEnergy n = 0 := by
  constructor
  · intro hfixed
    by_cases hE : interferenceEnergy n = 0
    · exact hE
    · have hstep : step n = 2 := by
        rw [step_of_one_lt n h]
        simp [hE]
      have hn_eq_two : n = 2 := hfixed.symm.trans hstep
      have hzero : interferenceEnergy n = 0 := by
        rw [hn_eq_two]
        exact interferenceEnergy_two_eq_zero
      exact (hE hzero).elim
  · intro hE
    exact step_eq_self_of_energy_zero n h hE

theorem step_eq_two_of_energy_pos (n : Nat) (hE : interferenceEnergy n > 0) :
    step n = 2 := by
  unfold step
  by_cases hnlt : n < 2
  · simp [hnlt]
  · have hne : ¬ interferenceEnergy n = 0 := Nat.ne_of_gt hE
    simp [hnlt, hne]

theorem step_fixed_iff_energy_zero_on_normalized (n : Nat) :
    1 < n → (step n = n ↔ interferenceEnergy n = 0) := by
  intro h
  exact step_fixed_iff n h

theorem iterate_converges_to_prime :
    ∀ n, ∃ k, isStableFixedPoint (Nat.iterate step k n) := by
  intro n
  by_cases hnlt : n < 2
  · refine ⟨1, ?_⟩
    have hstep : step n = 2 := by
      unfold step
      simp [hnlt]
    change isStableFixedPoint (step n)
    rw [hstep]
    exact two_isStableFixedPoint
  · by_cases hE : interferenceEnergy n = 0
    · refine ⟨0, ?_⟩
      change isStableFixedPoint n
      exact ⟨one_lt_of_not_lt_two hnlt, hE⟩
    · refine ⟨1, ?_⟩
      have hstep : step n = 2 := by
        unfold step
        simp [hnlt, hE]
      change isStableFixedPoint (step n)
      rw [hstep]
      exact two_isStableFixedPoint

theorem iterate_converges_to_prime' :
    ∀ n, ∃ k, isPrime (Nat.iterate step k n) := by
  intro n
  rcases iterate_converges_to_prime n with ⟨k, hstable⟩
  exact ⟨k, (prime_iff_stable_fixed_point (Nat.iterate step k n)).2 hstable⟩

end ILA.Primegenerator
