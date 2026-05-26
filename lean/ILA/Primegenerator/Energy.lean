namespace ILA.Primegenerator

/--
  干渉エネルギー（暫定版）:
  自明でない約数の個数を「干渉エネルギー」として定義する。
-/
def interferenceEnergy (n : Nat) : Nat :=
  if h : n > 1 then
    let candidates := List.range n
    let divisors :=
      candidates.filter (fun k => k > 1 ∧ k < n ∧ n % k = 0)
    divisors.length
  else
    0

end ILA.Primegenerator
