import ILA.Primegenerator.Energy

namespace ILA.Primegenerator

/--
局所場 σ(n,r)
半径 r の範囲にある干渉エネルギーの総和
-/
def localField (n r : Nat) : Nat :=
  let start := n - r
  let stop := n + r + 1
  let range := List.range (stop - start) |>.map (· + start)
  range.foldl (fun acc x => acc + interferenceEnergy x) 0

end ILA.Primegenerator
