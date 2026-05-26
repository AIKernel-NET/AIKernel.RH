namespace ILA.Provider

/-!
### Radix Residue Filter
Generic filter restricting candidates by allowed residues.
-/
def isResidueCandidate (b : Nat) (allowed : List Nat) (n : Nat) : Prop :=
  n % b ∈ allowed

def base12Allowed : List Nat := [1, 5, 7, 11]
def base24Allowed : List Nat := [1, 5, 7, 11, 13, 17, 19, 23]

def isPrimeCandidate12 (n : Nat) : Prop :=
  isResidueCandidate 12 base12Allowed n

def isPrimeCandidate24 (n : Nat) : Prop :=
  isResidueCandidate 24 base24Allowed n

end ILA.Provider
