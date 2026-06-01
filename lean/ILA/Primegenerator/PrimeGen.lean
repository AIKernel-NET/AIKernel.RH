import Mathlib.Data.Nat.Prime.Basic
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

end ILA.Provider
