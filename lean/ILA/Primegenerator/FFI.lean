import ILA.Primegenerator.InterferenceEnergyFast
import ILA.Primegenerator.Phase

namespace ILA.Primegenerator.FFI

/--
Lean-side declaration for the stable C ABI entry point.

`@[extern]` tells Lean that calls to this declaration are implemented by the
C symbol `get_interference_energy`. The public P/Invoke ABI is provided by the
native shim in `native/AIKernel_RH`.
-/
@[extern "get_interference_energy"]
opaque interferenceEnergyExtern (n : UInt64) : UInt64

@[extern "get_interference_energy_batch"]
opaque interferenceEnergyBatchExtern
  (input output count : UInt64) : Unit

@[extern "get_phase"]
opaque phaseExtern (n : UInt64) : UInt8

@[extern "get_phase_residue"]
opaque phaseResidueExtern (n : UInt64) : UInt64

@[extern "get_interference_detail"]
opaque interferenceDetailExtern
  (n phase energy residue : UInt64) : Unit

@[extern "search_stable_points"]
opaque searchStablePointsExtern
  (start stop buffer count : UInt64) : Unit

@[extern "get_phase_difference"]
opaque phaseDifferenceExtern (a b : UInt64) : UInt64

@[extern "estimate_period"]
opaque estimatePeriodExtern (n : UInt64) : UInt64

@[extern "map_to_phase"]
opaque mapToPhaseExtern
  (input output count : UInt64) : Unit

/--
Lean-compiled fallback symbol with Lean's generated-code ABI.

Use `lean -c` to emit C for this definition. For direct C# interop, prefer the
plain C ABI shim because Lean-generated exports are runtime-aware and not a
stable P/Invoke boundary by themselves.
-/
@[export lean_interference_energy_fast_u64]
def interferenceEnergyFastU64 (n : UInt64) : UInt64 :=
  UInt64.ofNat (interferenceEnergy_fast n.toNat)

@[export lean_get_phase_u64]
def phaseU64 (n : UInt64) : UInt64 :=
  match Phase.ofNat? n.toNat with
  | none => 0
  | some Phase.pp => 1
  | some Phase.pm => 2
  | some Phase.mp => 3
  | some Phase.mm => 4

@[export lean_get_phase_u8]
def phaseU8 (n : UInt64) : UInt8 :=
  match Phase.ofNat? n.toNat with
  | none => 0
  | some Phase.pp => 1
  | some Phase.pm => 2
  | some Phase.mp => 3
  | some Phase.mm => 4

@[export lean_get_phase_residue_u64]
def phaseResidueU64 (n : UInt64) : UInt64 :=
  UInt64.ofNat (n.toNat % 24)

@[export lean_get_phase_difference_u64]
def phaseDifferenceU64 (a b : UInt64) : UInt64 :=
  let pa := a.toNat % 24
  let pb := b.toNat % 24
  let forward := (pa + 24 - pb) % 24
  let backward := (pb + 24 - pa) % 24
  UInt64.ofNat (Nat.min forward backward)

@[export lean_estimate_period_u64]
def estimatePeriodU64 (_n : UInt64) : UInt64 :=
  24

end ILA.Primegenerator.FFI
