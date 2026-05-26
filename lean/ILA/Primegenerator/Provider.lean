import Mathlib.LinearAlgebra.LinearIndependent
import Mathlib.Data.Real.Basic

namespace ILA.Provider

/-!
### Uniform Phase Provider
Q-linear independence of frequencies.
-/
class UniformPhaseProvider (N : Nat) where
  freqs : Fin N → ℝ
  linearIndependent : LinearIndependent ℚ freqs

end ILA.Provider
