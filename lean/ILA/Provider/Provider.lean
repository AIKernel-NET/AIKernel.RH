import Mathlib.LinearAlgebra.LinearIndependent
import Mathlib.Data.Real.Basic

namespace ILA.Provider

/--
UniformPhaseProvider
N 個の周波数ベクトルを持ち、それらが Q 上で線形独立であることを要求する。

これは ILA における「位相を提供する Provider」の数学的 Contract。
-/
class UniformPhaseProvider (N : Nat) where
  /-- 周波数ベクトル（Fin N → ℝ） -/
  freqs : Fin N → ℝ

  /-- Q 上の線形独立性（Fail-Closed の数学的保証） -/
  linearIndependent : LinearIndependent ℚ freqs

end ILA.Provider
