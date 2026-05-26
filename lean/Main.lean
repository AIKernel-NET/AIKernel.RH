import ILA.Primegenerator.Phase
import ILA.Primegenerator.Energy
import ILA.Primegenerator.Field
import ILA.Primegenerator.FixedPoint

open ILA.Primegenerator

def main : IO Unit := do
  IO.println s!"Phase.ofNat?(5) = {Phase.ofNat? 5}"
  IO.println s!"Energy(12) = {interferenceEnergy 12}"
  IO.println s!"localField(10,2) = {localField 10 2}"
