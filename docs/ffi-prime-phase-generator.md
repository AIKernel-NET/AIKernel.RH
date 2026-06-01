# Prime Phase Generator Native ABI

This note describes the v1.4.0 native ABI boundary for integrating the Lean
Prime Phase Generator with AIKernel operators through C and C#.

## Lean boundary

Lean exposes a C symbol declaration through `@[extern]` in
`lean/ILA/Primegenerator/FFI.lean`:

```lean
@[extern "get_interference_energy"]
opaque interferenceEnergyExtern (n : UInt64) : UInt64
```

This declaration is for Lean code that wants to call the native ABI symbol.
Lean-generated C symbols are runtime-aware, so the stable P/Invoke surface is
implemented by the plain C shim in `native/AIKernel_RH`.

The toolchain in this repository is Lean 4.31.0-rc1. It does not expose a
`--export-c` flag; use `-c` for C emission:

```powershell
cd lean
lake env lean -c ..\native\AIKernel_RH\generated\ffi.c ILA\Primegenerator\FFI.lean
```

If you use the generated Lean C directly, include the Lean runtime and initialize
it according to Lean's generated-code ABI. For .NET interop, prefer the C shim
below because it exports plain `uint64_t` functions with `cdecl`.

## C ABI

Header:

```c
uint64_t get_interference_energy(uint64_t n);
uint8_t is_prime_phase(uint64_t n);
void get_interference_energy_batch(
    const uint64_t* inputs,
    uint64_t* outputs,
    size_t count);
```

Build the portable DLL/shared library:

```powershell
cmake -S native/AIKernel_RH -B native/AIKernel_RH/build
cmake --build native/AIKernel_RH/build --config Release
```

Linux/macOS use the same commands and produce `libAIKernel_RH.so` or
`libAIKernel_RH.dylib`. Windows produces `AIKernel_RH.dll`.

The C implementation is stateless and thread-safe. `get_interference_energy`
counts nontrivial divisors exactly, matching the Lean semantics of
`interferenceEnergy`.

## C# P/Invoke

```csharp
[DllImport("AIKernel_RH", CallingConvention = CallingConvention.Cdecl,
    EntryPoint = "get_interference_energy")]
public static extern ulong GetInterferenceEnergy(ulong n);
```

Use `PrimePhaseNative.GetInterferenceEnergyParallel` for TPL-based parallel
calls. For millions of inputs, prefer `GetInterferenceEnergyBatch` to reduce
P/Invoke transition overhead by crossing the ABI boundary once per batch.
