using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace AIKernel.RH.Native;

public static partial class PrimePhaseNative
{
    private const string LibraryName = "AIKernel_RH";

    public readonly record struct InterferenceDetail(
        ulong Phase,
        ulong Energy,
        ulong Residue);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "get_interference_energy")]
    public static extern ulong GetInterferenceEnergy(ulong n);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "is_prime_phase")]
    [return: MarshalAs(UnmanagedType.I1)]
    public static extern bool IsPrimePhase(ulong n);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "get_phase")]
    public static extern ulong GetPhase(ulong n);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "get_phase_difference")]
    public static extern ulong GetPhaseDifference(ulong a, ulong b);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "estimate_period")]
    public static extern ulong EstimatePeriod(ulong n);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "get_interference_detail")]
    private static extern unsafe void GetInterferenceDetailNative(
        ulong n,
        ulong* phase,
        ulong* energy,
        ulong* residue);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "get_interference_energy_batch")]
    private static extern unsafe void GetInterferenceEnergyBatchNative(
        ulong* inputs,
        ulong* outputs,
        UIntPtr count);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "map_to_phase")]
    private static extern unsafe void MapToPhaseNative(
        ulong* inputs,
        ulong* outputs,
        UIntPtr count);

    [DllImport(LibraryName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "search_stable_points")]
    private static extern unsafe void SearchStablePointsNative(
        ulong start,
        ulong end,
        ulong* buffer,
        UIntPtr* count);

    public static unsafe InterferenceDetail GetInterferenceDetail(ulong n)
    {
        ulong phase = 0;
        ulong energy = 0;
        ulong residue = 0;

        GetInterferenceDetailNative(n, &phase, &energy, &residue);
        return new InterferenceDetail(phase, energy, residue);
    }

    public static ulong[] GetInterferenceEnergyBatch(ReadOnlySpan<ulong> inputs)
    {
        var outputArray = new ulong[inputs.Length];
        GetInterferenceEnergyBatch(inputs, outputArray);
        return outputArray;
    }

    public static unsafe void GetInterferenceEnergyBatch(
        ReadOnlySpan<ulong> inputs,
        Span<ulong> outputs)
    {
        if (outputs.Length < inputs.Length)
        {
            throw new ArgumentException("Output span must be at least as long as input span.", nameof(outputs));
        }

        if (inputs.Length == 0)
        {
            return;
        }

        fixed (ulong* inputPtr = inputs)
        fixed (ulong* outputPtr = outputs)
        {
            GetInterferenceEnergyBatchNative(inputPtr, outputPtr, (UIntPtr)inputs.Length);
        }
    }

    public static ulong[] MapToPhase(ReadOnlySpan<ulong> inputs)
    {
        var outputArray = new ulong[inputs.Length];
        MapToPhase(inputs, outputArray);
        return outputArray;
    }

    public static unsafe void MapToPhase(ReadOnlySpan<ulong> inputs, Span<ulong> outputs)
    {
        if (outputs.Length < inputs.Length)
        {
            throw new ArgumentException("Output span must be at least as long as input span.", nameof(outputs));
        }

        if (inputs.Length == 0)
        {
            return;
        }

        fixed (ulong* inputPtr = inputs)
        fixed (ulong* outputPtr = outputs)
        {
            MapToPhaseNative(inputPtr, outputPtr, (UIntPtr)inputs.Length);
        }
    }

    public static unsafe ulong[] SearchStablePoints(ulong start, ulong end, int capacity)
    {
        if (capacity < 0)
        {
            throw new ArgumentOutOfRangeException(nameof(capacity));
        }

        var buffer = new ulong[capacity];
        var count = (UIntPtr)buffer.Length;

        if (buffer.Length == 0)
        {
            return [];
        }

        fixed (ulong* bufferPtr = buffer)
        {
            SearchStablePointsNative(start, end, bufferPtr, &count);
        }

        var written = checked((int)count);
        Array.Resize(ref buffer, written);
        return buffer;
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
