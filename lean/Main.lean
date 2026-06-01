import ILA.Primegenerator.Phase
import ILA.Primegenerator.Energy
import ILA.Primegenerator.Field
import ILA.Primegenerator.FixedPoint
import ILA.Primegenerator.InterferenceEnergyFast

open ILA.Primegenerator

#eval interferenceEnergy_fast 2
#eval interferenceEnergy_fast 12
#eval interferenceEnergy_fast 97
#eval interferenceEnergy_fast 9973
#eval interferenceEnergy_fast 2 == interferenceEnergy 2
#eval interferenceEnergy_fast 12 == interferenceEnergy 12
#eval interferenceEnergy_fast 97 == interferenceEnergy 97
#eval interferenceEnergy_fast 9973 == interferenceEnergy 9973

def main : IO Unit := do
  IO.println s!"Phase.ofNat?(5) = {Phase.ofNat? 5}"
  IO.println s!"Energy(12) = {interferenceEnergy 12}"
  IO.println s!"localField(10,2) = {localField 10 2}"
