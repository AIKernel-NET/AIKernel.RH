using System;
using System.Linq;
using System.Threading.Tasks;

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

    public static ulong[] RunChunkedBatchedParallel(
        ulong count,
        int chunkSize = 10_000,
        int? maxDegreeOfParallelism = null)
    {
        if (chunkSize <= 0)
        {
            throw new ArgumentOutOfRangeException(nameof(chunkSize));
        }

        var length = checked((int)count);
        var inputs = Enumerable.Range(0, length)
            .Select(i => (ulong)i)
            .ToArray();
        var outputs = new ulong[length];
        var numberOfChunks = (length + chunkSize - 1) / chunkSize;
        var options = new ParallelOptions();

        if (maxDegreeOfParallelism is { } degree)
        {
            options.MaxDegreeOfParallelism = degree;
        }

        Parallel.For(
            0,
            numberOfChunks,
            options,
            chunkIndex =>
            {
                var start = chunkIndex * chunkSize;
                var chunkLength = Math.Min(chunkSize, length - start);
                var inputSpan = inputs.AsSpan(start, chunkLength);
                var outputSpan = outputs.AsSpan(start, chunkLength);

                PrimePhaseNative.GetInterferenceEnergyBatch(inputSpan, outputSpan);
            });

        return outputs;
    }
}
