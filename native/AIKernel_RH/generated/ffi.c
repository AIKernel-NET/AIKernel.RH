// Lean compiler output
// Module: ILA.Primegenerator.FFI
// Imports: public import Init public meta import Init public import ILA.Primegenerator.InterferenceEnergyFast
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* lean_uint64_to_nat(uint64_t);
lean_object* lp_primegenerator_ILA_Primegenerator_interferenceEnergy__fast(lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
uint64_t get_interference_energy(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyExtern___boxed(lean_object*);
LEAN_EXPORT uint64_t lean_interference_energy_fast_u64(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyFastU64___boxed(lean_object*);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyExtern___boxed(lean_object* v_n_2_){
_start:
{
uint64_t v_n_boxed_3_; uint64_t v_res_4_; lean_object* v_r_5_; 
v_n_boxed_3_ = lean_unbox_uint64(v_n_2_);
lean_dec_ref(v_n_2_);
v_res_4_ = get_interference_energy(v_n_boxed_3_);
v_r_5_ = lean_box_uint64(v_res_4_);
return v_r_5_;
}
}
LEAN_EXPORT uint64_t lean_interference_energy_fast_u64(uint64_t v_n_6_){
_start:
{
lean_object* v___x_7_; lean_object* v___x_8_; uint64_t v___x_9_; 
v___x_7_ = lean_uint64_to_nat(v_n_6_);
v___x_8_ = lp_primegenerator_ILA_Primegenerator_interferenceEnergy__fast(v___x_7_);
v___x_9_ = lean_uint64_of_nat(v___x_8_);
lean_dec(v___x_8_);
return v___x_9_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyFastU64___boxed(lean_object* v_n_10_){
_start:
{
uint64_t v_n_boxed_11_; uint64_t v_res_12_; lean_object* v_r_13_; 
v_n_boxed_11_ = lean_unbox_uint64(v_n_10_);
lean_dec_ref(v_n_10_);
v_res_12_ = lean_interference_energy_fast_u64(v_n_boxed_11_);
v_r_13_ = lean_box_uint64(v_res_12_);
return v_r_13_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_primegenerator_ILA_Primegenerator_InterferenceEnergyFast(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_ILA_Primegenerator_FFI(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_primegenerator_ILA_Primegenerator_InterferenceEnergyFast(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
