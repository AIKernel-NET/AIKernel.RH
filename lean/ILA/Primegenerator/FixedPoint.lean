import ILA.Primegenerator.Energy

namespace ILA.Primegenerator

/-- 位相干渉場における安定固定点（エネルギー極小） -/
def isStableFixedPoint (n : Nat) : Prop :=
  n > 1 ∧ interferenceEnergy n = 0

/-- 従来の素数定義 -/
def isPrime (n : Nat) : Prop :=
  n > 1 ∧ ∀ m, 1 < m → m < n → n % m ≠ 0

end ILA.Primegenerator
