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
    if (!is_pg1224_candidate(n)) {
        return 0u;
    }

    return get_interference_energy(n) == 0u ? 1u : 0u;
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
