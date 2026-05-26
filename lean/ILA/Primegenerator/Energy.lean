namespace ILA.Primegenerator

/--
干渉エネルギー
（モック版：自明でない約数の数）
-/
def interferenceEnergy (n : Nat) : Nat :=
  let divisors := (List.range n).filter (fun k => k > 1 ∧ n % k = 0)
  divisors.length

end ILA.Primegenerator
