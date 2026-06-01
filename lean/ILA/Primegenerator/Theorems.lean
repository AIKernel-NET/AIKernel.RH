import ILA.Primegenerator.FixedPoint

namespace ILA.Primegenerator

private theorem interferenceEnergy_eq_zero_iff_no_nontrivial_divisors (n : Nat) :
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
