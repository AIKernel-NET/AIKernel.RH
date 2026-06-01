import Mathlib.Data.Nat.Prime.Basic
import Mathlib.Tactic
import ILA.Primegenerator.RadixFilter

namespace ILA.Provider

/-!
### Prime Generator (Fail-Closed)
Defined strictly as conjunction `∧`.
-/
def primeGen12 (n : Nat) : Prop :=
  isPrimeCandidate12 n ∧ Nat.Prime n

def primeGen24 (n : Nat) : Prop :=
  isPrimeCandidate24 n ∧ Nat.Prime n

structure PrimeGenerator where
  candidate : Nat → Prop
  actual : Nat → Prop
  generate : Nat → Prop := fun n => candidate n ∧ actual n

def PG12 : PrimeGenerator :=
  { candidate := isPrimeCandidate12,
    actual := Nat.Prime }

def PG24 : PrimeGenerator :=
  { candidate := isPrimeCandidate24,
    actual := Nat.Prime }

/-- Implementation-level generation predicate, preserving the spec-level `generates`. -/
def generatesImpl (g : PrimeGenerator) (n : Nat) : Prop :=
  g.generate n

def PG1224 : PrimeGenerator :=
  { candidate := fun n =>
      n = 2 ∨ n = 3 ∨ isPrimeCandidate12 n ∨ isPrimeCandidate24 n,
    actual := Nat.Prime }

/-!
### Minimal Lemmas
Verifying generator–prime relationship.
-/
theorem primeGen12_implies_prime {n : Nat} (h : primeGen12 n) : Nat.Prime n :=
  h.right

theorem primeGen24_implies_prime {n : Nat} (h : primeGen24 n) : Nat.Prime n :=
  h.right

theorem prime_not_always_primeGen12 : ¬ ∀ n, Nat.Prime n → primeGen12 n := by
  intro h
  have h2 := h 2 Nat.prime_two
  have h_false : ¬ isPrimeCandidate12 2 := by
    unfold isPrimeCandidate12 isResidueCandidate base12Allowed
    decide
  exact h_false h2.left

theorem prime_not_always_primeGen24 : ¬ ∀ n, Nat.Prime n → primeGen24 n := by
  intro h
  have h2 := h 2 Nat.prime_two
  have h_false : ¬ isPrimeCandidate24 2 := by
    unfold isPrimeCandidate24 isResidueCandidate base24Allowed
    decide
  exact h_false h2.left

private theorem not_two_dvd_of_prime_ne_two {n : Nat}
    (hp : Nat.Prime n) (hne : n ≠ 2) : ¬ 2 ∣ n := by
  intro hdiv
  have htwo_ne_one : (2 : Nat) ≠ 1 := by decide
  have heq : n = 2 := (hp.dvd_iff_eq htwo_ne_one).mp hdiv
  exact hne heq

private theorem not_three_dvd_of_prime_ne_three {n : Nat}
    (hp : Nat.Prime n) (hne : n ≠ 3) : ¬ 3 ∣ n := by
  intro hdiv
  have hthree_ne_one : (3 : Nat) ≠ 1 := by decide
  have heq : n = 3 := (hp.dvd_iff_eq hthree_ne_one).mp hdiv
  exact hne heq

private theorem isPrimeCandidate24_of_prime_ne_two_ne_three {n : Nat}
    (hp : Nat.Prime n) (hne2 : n ≠ 2) (hne3 : n ≠ 3) :
    isPrimeCandidate24 n := by
  have hnot2 : ¬ 2 ∣ n := not_two_dvd_of_prime_ne_two hp hne2
  have hnot3 : ¬ 3 ∣ n := not_three_dvd_of_prime_ne_three hp hne3
  let r := n % 24
  have hlt : r < 24 := Nat.mod_lt n (by decide)
  have hmod2_ne_zero : r % 2 ≠ 0 := by
    intro hr
    have hn : n % 2 = 0 := by
      rw [← Nat.mod_mod_of_dvd n (by decide : 2 ∣ 24)]
      exact hr
    exact hnot2 (Nat.dvd_of_mod_eq_zero hn)
  have hmod3_ne_zero : r % 3 ≠ 0 := by
    intro hr
    have hn : n % 3 = 0 := by
      rw [← Nat.mod_mod_of_dvd n (by decide : 3 ∣ 24)]
      exact hr
    exact hnot3 (Nat.dvd_of_mod_eq_zero hn)
  have hr :
      r = 1 ∨ r = 5 ∨ r = 7 ∨ r = 11 ∨
        r = 13 ∨ r = 17 ∨ r = 19 ∨ r = 23 := by
    omega
  unfold isPrimeCandidate24 isResidueCandidate base24Allowed
  rcases hr with h | h | h | h | h | h | h | h <;> simp [r, h]

theorem PG1224_sound (n : Nat) :
  generatesImpl PG1224 n → Nat.Prime n := by
  intro hgenerated
  exact hgenerated.2

theorem PG1224_complete (n : Nat) :
  Nat.Prime n → generatesImpl PG1224 n := by
  intro hp
  constructor
  · by_cases h2 : n = 2
    · exact Or.inl h2
    · by_cases h3 : n = 3
      · exact Or.inr (Or.inl h3)
      · exact Or.inr (Or.inr (Or.inr
          (isPrimeCandidate24_of_prime_ne_two_ne_three hp h2 h3)))
  · exact hp

end ILA.Provider
