namespace ILA.Primegenerator

/--
位相基底（クラインの四元群 V₄ と同型）
12進の互いに素な剰余 {1,5,7,11} を (±1,±1) として表現
-/
inductive Phase where
  | pp : Phase  -- (+,+) : 1 mod 12
  | pm : Phase  -- (+,-) : 5 mod 12
  | mp : Phase  -- (-,+) : 7 mod 12
  | mm : Phase  -- (-,-) : 11 mod 12
  deriving Repr, DecidableEq

namespace Phase

/-- 位相の乗算（クライン群の演算） -/
def mul : Phase → Phase → Phase
  | pp, x  => x
  | x, pp  => x
  | pm, pm => pp
  | mp, mp => pp
  | mm, mm => pp
  | pm, mp => mm
  | mp, pm => mm
  | pm, mm => mp
  | mm, pm => mp
  | mp, mm => pm
  | mm, mp => pm

instance : Mul Phase := ⟨mul⟩

/--
自然数を位相に射影する
2 と 3 の倍数は位相崩壊として none
-/
def ofNat? (n : Nat) : Option Phase :=
  match n % 12 with
  | 1  => some pp
  | 5  => some pm
  | 7  => some mp
  | 11 => some mm
  | _  => none

end Phase
instance : ToString Phase where
  toString
    | Phase.pp => "pp"
    | Phase.pm => "pm"
    | Phase.mp => "mp"
    | Phase.mm => "mm"

instance : ToString (Option Phase) where
  toString
    | some p => s!"some {p}"
    | none   => "none"
end ILA.Primegenerator
