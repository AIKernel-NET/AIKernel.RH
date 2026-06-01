import ILA.Primegenerator.InterferenceEnergyFast

namespace ILA.Primegenerator.FFI

/--
Lean-side declaration for the stable C ABI entry point.

`@[extern]` tells Lean that calls to this declaration are implemented by the
C symbol `get_interference_energy`. The public P/Invoke ABI is provided by the
native shim in `native/AIKernel_RH`.
-/
@[extern "get_interference_energy"]
opaque interferenceEnergyExtern (n : UInt64) : UInt64

/--
Lean-compiled fallback symbol with Lean's generated-code ABI.

Use `lean -c` to emit C for this definition. For direct C# interop, prefer the
plain C ABI shim because Lean-generated exports are runtime-aware and not a
stable P/Invoke boundary by themselves.
-/
@[export lean_interference_energy_fast_u64]
def interferenceEnergyFastU64 (n : UInt64) : UInt64 :=
  UInt64.ofNat (interferenceEnergy_fast n.toNat)

end ILA.Primegenerator.FFI
