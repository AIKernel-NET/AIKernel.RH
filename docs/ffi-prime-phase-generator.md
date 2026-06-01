# Prime Phase Generator Native ABI

This note describes the native ABI boundary for integrating the Lean Prime
Phase Generator with AIKernel operators through C and C#.

## Exported API

The stable DLL/shared-library surface is:

```c
uint64_t get_interference_energy(uint64_t n);

void get_interference_energy_batch(
    const uint64_t* input,
    uint64_t* output,
    size_t count);

uint64_t get_phase(uint64_t n);

void get_interference_detail(
    uint64_t n,
    uint64_t* phase,
    uint64_t* energy,
    uint64_t* residue);

void search_stable_points(
    uint64_t start,
    uint64_t end,
    uint64_t* buffer,
    size_t* count);

uint64_t get_phase_difference(uint64_t a, uint64_t b);

uint64_t estimate_period(uint64_t n);

void map_to_phase(
    const uint64_t* input,
    uint64_t* output,
    size_t count);
```

`phase` is `n % 24`, `residue` is `n % 12`, and phase difference is the
shortest circular distance on the 24-phase ring. `estimate_period` returns `24`
for the current phase map. For `search_stable_points`, `*count` is an input
capacity and is replaced with the number of values written.

## Lean Boundary

Lean declarations live in `lean/ILA/Primegenerator/FFI.lean`.

Scalar functions use direct `UInt64` declarations:

```lean
@[extern "get_interference_energy"]
opaque interferenceEnergyExtern (n : UInt64) : UInt64

@[extern "get_phase"]
opaque phaseExtern (n : UInt64) : UInt64

@[extern "get_phase_difference"]
opaque phaseDifferenceExtern (a b : UInt64) : UInt64

@[extern "estimate_period"]
opaque estimatePeriodExtern (n : UInt64) : UInt64
```

Pointer-oriented ABI entries are also named at the Lean boundary. Lean does not
provide a stable public raw-pointer type in this project, so these declarations
use address-width `UInt64` parameters and the type-safe pointer handling is kept
in the C/C# layer.

Lean-generated fallback symbols are exported with `@[export]` for scalar helper
functions. The toolchain in this repository is Lean 4.31.0-rc1. It does not
expose a `--export-c` flag; use `-c` for C emission:

```powershell
cd lean
lake env lean -c ..\native\AIKernel_RH\generated\ffi.c ILA\Primegenerator\FFI.lean
```

If generated Lean C is linked directly, initialize the Lean runtime according to
Lean's generated-code ABI before invoking generated symbols. The shipped
`native/AIKernel_RH` library is a plain stateless C ABI shim and therefore does
not require Lean runtime initialization for normal C# P/Invoke use.

## C Build

MSVC:

```powershell
cmd.exe /d /s /c '"C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64 && cmake -S native\AIKernel_RH -B native\AIKernel_RH\build -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build native\AIKernel_RH\build --config Release'
```

clang, Linux, or macOS:

```sh
cmake -S native/AIKernel_RH -B native/AIKernel_RH/build -DCMAKE_BUILD_TYPE=Release
cmake --build native/AIKernel_RH/build --config Release
```

Windows produces `AIKernel_RH.dll`, Linux produces `libAIKernel_RH.so`, and
macOS produces `libAIKernel_RH.dylib`.

## C# P/Invoke

The C# wrapper lives in `csharp/AIKernel.RH.Native/PrimePhaseNative.cs`. It uses
`CallingConvention.Cdecl` for every native entry and exposes allocation-free
`Span<ulong>` overloads for batch operations:

```csharp
var inputs = new ulong[] { 2, 12, 97 };
Span<ulong> outputs = stackalloc ulong[inputs.Length];
PrimePhaseNative.GetInterferenceEnergyBatch(inputs, outputs);
```

Run the smoke-test console after building the native library:

```powershell
dotnet run --project csharp\AIKernel.RH.Native.SmokeTest\AIKernel.RH.Native.SmokeTest.csproj -- native\AIKernel_RH\build\AIKernel_RH.dll
```

## ABI And Safety Notes

- All exported C functions use fixed-width integer types and `cdecl`.
- The DLL implementation is stateless and thread-safe.
- Batch APIs accept null pointers as no-ops to keep the ABI defensive.
- Output spans and buffers are owned by the caller.
- `search_stable_points` never writes more than the input capacity in `*count`.
- For high-volume .NET workloads, prefer batch APIs over per-value P/Invoke.
