import ILA.Primegenerator.Energy

namespace ILA.Primegenerator

/--
  対称クリッピング付き局所場 localField(n, r):

  本来の区間 [n - r, n + r] を取りたいが、
  Lean の Nat は負数を持たないため n < r のとき左端が 0 に潰れる。

  そこで対称クリッピングを行う：

  - n ≥ r のとき: [n - r, n + r]
  - n < r のとき: [0, 2n]（n を中心とした左右対称）

  これにより常に「左右対称の局所場」が得られる。
-/
def localField (n r : Nat) : Nat :=
  let left  := n - r
  let right := n + r
  let deficit := if _h : n ≥ r then 0 else (r - n)
  let right' := right - deficit
  let range := List.range (right' - left + 1) |>.map (· + left)
  range.foldl (fun acc x => acc + interferenceEnergy x) 0

end ILA.Primegenerator
