#pragma once

#include <stddef.h>
#include <stdint.h>

#if defined(_WIN32) || defined(__CYGWIN__)
#  if defined(AIKERNEL_RH_BUILD)
#    define AIKERNEL_RH_API __declspec(dllexport)
#  else
#    define AIKERNEL_RH_API __declspec(dllimport)
#  endif
#else
#  define AIKERNEL_RH_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef enum AIKernelPhase {
    AIKERNEL_PHASE_NONE = 0,
    AIKERNEL_PHASE_PP = 1,
    AIKERNEL_PHASE_PM = 2,
    AIKERNEL_PHASE_MP = 3,
    AIKERNEL_PHASE_MM = 4
} AIKernelPhase;

AIKERNEL_RH_API uint64_t get_interference_energy(uint64_t n);

AIKERNEL_RH_API uint8_t is_prime_phase(uint64_t n);

AIKERNEL_RH_API uint64_t get_phase_residue(uint64_t n);

AIKERNEL_RH_API uint8_t get_phase(uint64_t n);

AIKERNEL_RH_API void get_interference_detail(
    uint64_t n,
    uint8_t* phase,
    uint64_t* energy,
    uint64_t* residue);

AIKERNEL_RH_API void search_stable_points(
    uint64_t start,
    uint64_t end,
    uint64_t* buffer,
    size_t* count);

AIKERNEL_RH_API uint64_t get_phase_difference(uint64_t a, uint64_t b);

AIKERNEL_RH_API uint64_t estimate_period(uint64_t n);

AIKERNEL_RH_API void get_interference_energy_batch(
    const uint64_t* inputs,
    uint64_t* outputs,
    size_t count);

AIKERNEL_RH_API void map_to_phase(
    const uint64_t* inputs,
    uint8_t* outputs,
    size_t count);

#ifdef __cplusplus
}
#endif
