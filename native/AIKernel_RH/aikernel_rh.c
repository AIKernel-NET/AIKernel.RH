#include "aikernel_rh.h"

static uint8_t is_residue_candidate_24(uint64_t n) {
    switch (n % 24u) {
    case 1u:
    case 5u:
    case 7u:
    case 11u:
    case 13u:
    case 17u:
    case 19u:
    case 23u:
        return 1u;
    default:
        return 0u;
    }
}

static uint8_t is_pg1224_candidate(uint64_t n) {
    return n == 2u || n == 3u || is_residue_candidate_24(n);
}

static uint64_t count_nontrivial_divisors(uint64_t n) {
    uint64_t count = 0u;

    if (n <= 3u) {
        return 0u;
    }

    for (uint64_t d = 2u; d <= n / d; ++d) {
        if (n % d != 0u) {
            continue;
        }

        const uint64_t q = n / d;
        if (d < n) {
            ++count;
        }

        if (q != d && q < n) {
            ++count;
        }
    }

    return count;
}

AIKERNEL_RH_API uint64_t get_interference_energy(uint64_t n) {
    if (n <= 1u) {
        return 0u;
    }

    return count_nontrivial_divisors(n);
}

AIKERNEL_RH_API uint8_t is_prime_phase(uint64_t n) {
    if (n <= 1u) {
        return 0u;
    }

    if (!is_pg1224_candidate(n)) {
        return 0u;
    }

    return get_interference_energy(n) == 0u ? 1u : 0u;
}

AIKERNEL_RH_API uint64_t get_phase(uint64_t n) {
    return n % 24u;
}

AIKERNEL_RH_API void get_interference_detail(
    uint64_t n,
    uint64_t* phase,
    uint64_t* energy,
    uint64_t* residue) {
    if (phase != 0) {
        *phase = get_phase(n);
    }

    if (energy != 0) {
        *energy = get_interference_energy(n);
    }

    if (residue != 0) {
        *residue = n % 12u;
    }
}

AIKERNEL_RH_API void search_stable_points(
    uint64_t start,
    uint64_t end,
    uint64_t* buffer,
    size_t* count) {
    if (count == 0) {
        return;
    }

    const size_t capacity = *count;
    size_t written = 0u;

    if (buffer == 0 || capacity == 0u || end < start) {
        *count = 0u;
        return;
    }

    for (uint64_t n = start; n <= end; ++n) {
        if (is_prime_phase(n)) {
            if (written >= capacity) {
                break;
            }

            buffer[written] = n;
            ++written;
        }

        if (n == UINT64_MAX) {
            break;
        }
    }

    *count = written;
}

AIKERNEL_RH_API uint64_t get_phase_difference(uint64_t a, uint64_t b) {
    const uint64_t pa = get_phase(a);
    const uint64_t pb = get_phase(b);
    const uint64_t forward = (pa + 24u - pb) % 24u;
    const uint64_t backward = (pb + 24u - pa) % 24u;

    return forward < backward ? forward : backward;
}

AIKERNEL_RH_API uint64_t estimate_period(uint64_t n) {
    (void)n;
    return 24u;
}

AIKERNEL_RH_API void get_interference_energy_batch(
    const uint64_t* inputs,
    uint64_t* outputs,
    size_t count) {
    if (inputs == 0 || outputs == 0) {
        return;
    }

    for (size_t i = 0u; i < count; ++i) {
        outputs[i] = get_interference_energy(inputs[i]);
    }
}

AIKERNEL_RH_API void map_to_phase(
    const uint64_t* inputs,
    uint64_t* outputs,
    size_t count) {
    if (inputs == 0 || outputs == 0) {
        return;
    }

    for (size_t i = 0u; i < count; ++i) {
        outputs[i] = get_phase(inputs[i]);
    }
}
