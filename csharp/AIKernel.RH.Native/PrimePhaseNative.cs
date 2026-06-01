using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace AIKernel.RH.Native;

public static partial class PrimePhaseNative
{
    private const string LibraryName = "AIKernel_RH";

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "get_interference_energy")]
    public static extern ulong GetInterferenceEnergy(ulong n);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "is_prime_phase")]
    [return: MarshalAs(UnmanagedType.I1)]
    public static extern bool IsPrimePhase(ulong n);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "get_interference_energy_batch")]
    private static extern void GetInterferenceEnergyBatchNative(
        [In]
        ulong[] inputs,
        [Out]
        ulong[] outputs,
        UIntPtr count);

    public static ulong[] GetInterferenceEnergyBatch(ReadOnlySpan<ulong> inputs)
    {
        var inputArray = inputs.ToArray();
        var outputArray = new ulong[inputArray.Length];
        GetInterferenceEnergyBatchNative(inputArray, outputArray, (UIntPtr)inputArray.Length);
        return outputArray;
    }

    public static ulong[] GetInterferenceEnergyParallel(
        IReadOnlyList<ulong> inputs,
        int? maxDegreeOfParallelism = null)
    {
        var outputs = new ulong[inputs.Count];
        var options = new ParallelOptions();

        if (maxDegreeOfParallelism is { } degree)
        {
            options.MaxDegreeOfParallelism = degree;
        }

        Parallel.For(
            0,
            inputs.Count,
            options,
            i => outputs[i] = GetInterferenceEnergy(inputs[i]));

        return outputs;
    }
}
