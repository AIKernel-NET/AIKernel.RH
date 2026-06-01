using System.Runtime.InteropServices;
using AIKernel.RH.Native;

var nativePath = args.Length > 0
    ? Path.GetFullPath(args[0])
    : FindNativeLibrary();

NativeLibrary.SetDllImportResolver(
    typeof(PrimePhaseNative).Assembly,
    (libraryName, assembly, searchPath) =>
        libraryName == "AIKernel_RH"
            ? NativeLibrary.Load(nativePath)
            : IntPtr.Zero);

Console.WriteLine($"Native library: {nativePath}");

Console.WriteLine("Single API: n, phase, residue, energy");
for (ulong n = 1; n <= 100; ++n)
{
    Console.WriteLine(
        $"{n,3}: phase={PrimePhaseNative.GetPhase(n),4}, residue={PrimePhaseNative.GetPhaseResidue(n),2}, energy={PrimePhaseNative.GetInterferenceEnergy(n)}");
}

Console.WriteLine();
Console.WriteLine("Batch API: first 32 of 1000 energies");
var batchInput = Enumerable.Range(1, 1000).Select(static n => (ulong)n).ToArray();
var batchOutput = PrimePhaseNative.GetInterferenceEnergyBatch(batchInput);
Console.WriteLine(string.Join(", ", batchOutput.Take(32)));

Console.WriteLine();
Console.WriteLine("Interference detail");
foreach (var n in new ulong[] { 2, 12, 97, 9973 })
{
    var detail = PrimePhaseNative.GetInterferenceDetail(n);
    Console.WriteLine($"{n}: phase={detail.Phase}, energy={detail.Energy}, residue={detail.Residue}");
}

Console.WriteLine();
Console.WriteLine("Stable points in [1, 10000]");
var stable = PrimePhaseNative.SearchStablePoints(1, 10_000, capacity: 10_000);
Console.WriteLine(string.Join(", ", stable));

Console.WriteLine();
Console.WriteLine("Phase difference");
Console.WriteLine($"diff(97, 101) = {PrimePhaseNative.GetPhaseDifference(97, 101)}");

Console.WriteLine();
Console.WriteLine("Period estimate");
Console.WriteLine($"period(9973) = {PrimePhaseNative.EstimatePeriod(9973)}");

Console.WriteLine();
Console.WriteLine("Map to phase");
var phaseInputs = new ulong[] { 1, 2, 3, 12, 24, 97, 101 };
var phases = PrimePhaseNative.MapToPhase(phaseInputs);
Console.WriteLine(string.Join(", ", phaseInputs.Zip(phases, static (n, p) => $"{n}->{p}")));

static string FindNativeLibrary()
{
    var root = AppContext.BaseDirectory;
    for (var dir = new DirectoryInfo(root); dir is not null; dir = dir.Parent)
    {
        var candidate = Path.Combine(dir.FullName, "native", "AIKernel_RH", "build", RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
            ? "AIKernel_RH.dll"
            : RuntimeInformation.IsOSPlatform(OSPlatform.OSX)
                ? "libAIKernel_RH.dylib"
                : "libAIKernel_RH.so");

        if (File.Exists(candidate))
        {
            return candidate;
        }
    }

    throw new FileNotFoundException(
        "Native AIKernel_RH library was not found. Build native/AIKernel_RH first or pass the library path as the first argument.");
}
