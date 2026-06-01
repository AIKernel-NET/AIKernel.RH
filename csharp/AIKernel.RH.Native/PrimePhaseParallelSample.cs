using System;
using System.Linq;

namespace AIKernel.RH.Native;

public static class PrimePhaseParallelSample
{
    public static ulong[] RunSingleCallParallel(ulong count, int? maxDegreeOfParallelism = null)
    {
        var inputs = Enumerable.Range(0, checked((int)count))
            .Select(i => (ulong)i)
            .ToArray();

        return PrimePhaseNative.GetInterferenceEnergyParallel(inputs, maxDegreeOfParallelism);
    }

    public static ulong[] RunBatched(ulong count)
    {
        var inputs = Enumerable.Range(0, checked((int)count))
            .Select(i => (ulong)i)
            .ToArray();

        return PrimePhaseNative.GetInterferenceEnergyBatch(inputs);
    }
}
