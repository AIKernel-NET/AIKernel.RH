import ILA.Primegenerator.FixedPoint

namespace ILA.Primegenerator

/--
核心命題：
「素数である」ことと
「干渉場におけるエネルギー極小の固定点である」ことは同値
-/
theorem prime_iff_stable_fixed_point (n : Nat) :
  isPrime n ↔ isStableFixedPoint n := by
  unfold isPrime isStableFixedPoint
  constructor
  · intro hprime
    exact ⟨hprime.1, (interferenceEnergy_eq_zero_iff_no_nontrivial_divisors n).2 hprime.2⟩
  · intro hstable
    exact ⟨hstable.1, (interferenceEnergy_eq_zero_iff_no_nontrivial_divisors n).1 hstable.2⟩

end ILA.Primegenerator
