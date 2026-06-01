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

AIKERNEL_RH_API uint64_t get_interference_energy(uint64_t n);

AIKERNEL_RH_API uint8_t is_prime_phase(uint64_t n);

AIKERNEL_RH_API void get_interference_energy_batch(
    const uint64_t* inputs,
    uint64_t* outputs,
    size_t count);

#ifdef __cplusplus
}
#endif
