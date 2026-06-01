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
lean_object* lean_nat_mod(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* lean_nat_sub(lean_object*, lean_object*);
uint8_t lean_nat_dec_le(lean_object*, lean_object*);
uint64_t lean_uint64_of_nat(lean_object*);
lean_object* lp_primegenerator_ILA_Primegenerator_interferenceEnergy__fast(lean_object*);
uint64_t get_interference_energy(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyExtern___boxed(lean_object*);
lean_object* get_interference_energy_batch(uint64_t, uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyBatchExtern___boxed(lean_object*, lean_object*, lean_object*);
uint64_t get_phase(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseExtern___boxed(lean_object*);
lean_object* get_interference_detail(uint64_t, uint64_t, uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceDetailExtern___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* search_stable_points(uint64_t, uint64_t, uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_searchStablePointsExtern___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
uint64_t get_phase_difference(uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseDifferenceExtern___boxed(lean_object*, lean_object*);
uint64_t estimate_period(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_estimatePeriodExtern___boxed(lean_object*);
lean_object* map_to_phase(uint64_t, uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_mapToPhaseExtern___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint64_t lean_interference_energy_fast_u64(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyFastU64___boxed(lean_object*);
LEAN_EXPORT uint64_t lean_get_phase_u64(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseU64___boxed(lean_object*);
LEAN_EXPORT uint64_t lean_get_phase_difference_u64(uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseDifferenceU64___boxed(lean_object*, lean_object*);
LEAN_EXPORT uint64_t lean_estimate_period_u64(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_estimatePeriodU64___boxed(lean_object*);
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
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyBatchExtern___boxed(lean_object* v_input_9_, lean_object* v_output_10_, lean_object* v_count_11_){
_start:
{
uint64_t v_input_boxed_12_; uint64_t v_output_boxed_13_; uint64_t v_count_boxed_14_; lean_object* v_res_15_; 
v_input_boxed_12_ = lean_unbox_uint64(v_input_9_);
lean_dec_ref(v_input_9_);
v_output_boxed_13_ = lean_unbox_uint64(v_output_10_);
lean_dec_ref(v_output_10_);
v_count_boxed_14_ = lean_unbox_uint64(v_count_11_);
lean_dec_ref(v_count_11_);
v_res_15_ = get_interference_energy_batch(v_input_boxed_12_, v_output_boxed_13_, v_count_boxed_14_);
return v_res_15_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseExtern___boxed(lean_object* v_n_17_){
_start:
{
uint64_t v_n_boxed_18_; uint64_t v_res_19_; lean_object* v_r_20_; 
v_n_boxed_18_ = lean_unbox_uint64(v_n_17_);
lean_dec_ref(v_n_17_);
v_res_19_ = get_phase(v_n_boxed_18_);
v_r_20_ = lean_box_uint64(v_res_19_);
return v_r_20_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceDetailExtern___boxed(lean_object* v_n_25_, lean_object* v_phase_26_, lean_object* v_energy_27_, lean_object* v_residue_28_){
_start:
{
uint64_t v_n_boxed_29_; uint64_t v_phase_boxed_30_; uint64_t v_energy_boxed_31_; uint64_t v_residue_boxed_32_; lean_object* v_res_33_; 
v_n_boxed_29_ = lean_unbox_uint64(v_n_25_);
lean_dec_ref(v_n_25_);
v_phase_boxed_30_ = lean_unbox_uint64(v_phase_26_);
lean_dec_ref(v_phase_26_);
v_energy_boxed_31_ = lean_unbox_uint64(v_energy_27_);
lean_dec_ref(v_energy_27_);
v_residue_boxed_32_ = lean_unbox_uint64(v_residue_28_);
lean_dec_ref(v_residue_28_);
v_res_33_ = get_interference_detail(v_n_boxed_29_, v_phase_boxed_30_, v_energy_boxed_31_, v_residue_boxed_32_);
return v_res_33_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_searchStablePointsExtern___boxed(lean_object* v_start_38_, lean_object* v_stop_39_, lean_object* v_buffer_40_, lean_object* v_count_41_){
_start:
{
uint64_t v_start_boxed_42_; uint64_t v_stop_boxed_43_; uint64_t v_buffer_boxed_44_; uint64_t v_count_boxed_45_; lean_object* v_res_46_; 
v_start_boxed_42_ = lean_unbox_uint64(v_start_38_);
lean_dec_ref(v_start_38_);
v_stop_boxed_43_ = lean_unbox_uint64(v_stop_39_);
lean_dec_ref(v_stop_39_);
v_buffer_boxed_44_ = lean_unbox_uint64(v_buffer_40_);
lean_dec_ref(v_buffer_40_);
v_count_boxed_45_ = lean_unbox_uint64(v_count_41_);
lean_dec_ref(v_count_41_);
v_res_46_ = search_stable_points(v_start_boxed_42_, v_stop_boxed_43_, v_buffer_boxed_44_, v_count_boxed_45_);
return v_res_46_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseDifferenceExtern___boxed(lean_object* v_a_49_, lean_object* v_b_50_){
_start:
{
uint64_t v_a_boxed_51_; uint64_t v_b_boxed_52_; uint64_t v_res_53_; lean_object* v_r_54_; 
v_a_boxed_51_ = lean_unbox_uint64(v_a_49_);
lean_dec_ref(v_a_49_);
v_b_boxed_52_ = lean_unbox_uint64(v_b_50_);
lean_dec_ref(v_b_50_);
v_res_53_ = get_phase_difference(v_a_boxed_51_, v_b_boxed_52_);
v_r_54_ = lean_box_uint64(v_res_53_);
return v_r_54_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_estimatePeriodExtern___boxed(lean_object* v_n_56_){
_start:
{
uint64_t v_n_boxed_57_; uint64_t v_res_58_; lean_object* v_r_59_; 
v_n_boxed_57_ = lean_unbox_uint64(v_n_56_);
lean_dec_ref(v_n_56_);
v_res_58_ = estimate_period(v_n_boxed_57_);
v_r_59_ = lean_box_uint64(v_res_58_);
return v_r_59_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_mapToPhaseExtern___boxed(lean_object* v_input_63_, lean_object* v_output_64_, lean_object* v_count_65_){
_start:
{
uint64_t v_input_boxed_66_; uint64_t v_output_boxed_67_; uint64_t v_count_boxed_68_; lean_object* v_res_69_; 
v_input_boxed_66_ = lean_unbox_uint64(v_input_63_);
lean_dec_ref(v_input_63_);
v_output_boxed_67_ = lean_unbox_uint64(v_output_64_);
lean_dec_ref(v_output_64_);
v_count_boxed_68_ = lean_unbox_uint64(v_count_65_);
lean_dec_ref(v_count_65_);
v_res_69_ = map_to_phase(v_input_boxed_66_, v_output_boxed_67_, v_count_boxed_68_);
return v_res_69_;
}
}
LEAN_EXPORT uint64_t lean_interference_energy_fast_u64(uint64_t v_n_70_){
_start:
{
lean_object* v___x_71_; lean_object* v___x_72_; uint64_t v___x_73_; 
v___x_71_ = lean_uint64_to_nat(v_n_70_);
v___x_72_ = lp_primegenerator_ILA_Primegenerator_interferenceEnergy__fast(v___x_71_);
v___x_73_ = lean_uint64_of_nat(v___x_72_);
lean_dec(v___x_72_);
return v___x_73_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyFastU64___boxed(lean_object* v_n_74_){
_start:
{
uint64_t v_n_boxed_75_; uint64_t v_res_76_; lean_object* v_r_77_; 
v_n_boxed_75_ = lean_unbox_uint64(v_n_74_);
lean_dec_ref(v_n_74_);
v_res_76_ = lean_interference_energy_fast_u64(v_n_boxed_75_);
v_r_77_ = lean_box_uint64(v_res_76_);
return v_r_77_;
}
}
LEAN_EXPORT uint64_t lean_get_phase_u64(uint64_t v_n_78_){
_start:
{
lean_object* v___x_79_; lean_object* v___x_80_; lean_object* v___x_81_; uint64_t v___x_82_; 
v___x_79_ = lean_uint64_to_nat(v_n_78_);
v___x_80_ = lean_unsigned_to_nat(24u);
v___x_81_ = lean_nat_mod(v___x_79_, v___x_80_);
lean_dec(v___x_79_);
v___x_82_ = lean_uint64_of_nat(v___x_81_);
lean_dec(v___x_81_);
return v___x_82_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseU64___boxed(lean_object* v_n_83_){
_start:
{
uint64_t v_n_boxed_84_; uint64_t v_res_85_; lean_object* v_r_86_; 
v_n_boxed_84_ = lean_unbox_uint64(v_n_83_);
lean_dec_ref(v_n_83_);
v_res_85_ = lean_get_phase_u64(v_n_boxed_84_);
v_r_86_ = lean_box_uint64(v_res_85_);
return v_r_86_;
}
}
LEAN_EXPORT uint64_t lean_get_phase_difference_u64(uint64_t v_a_87_, uint64_t v_b_88_){
_start:
{
lean_object* v___x_89_; lean_object* v___x_90_; lean_object* v_pa_91_; lean_object* v___x_92_; lean_object* v_pb_93_; lean_object* v___x_94_; lean_object* v___x_95_; lean_object* v_forward_96_; lean_object* v___x_97_; lean_object* v___x_98_; lean_object* v_backward_99_; uint8_t v___x_100_; 
v___x_89_ = lean_uint64_to_nat(v_a_87_);
v___x_90_ = lean_unsigned_to_nat(24u);
v_pa_91_ = lean_nat_mod(v___x_89_, v___x_90_);
lean_dec(v___x_89_);
v___x_92_ = lean_uint64_to_nat(v_b_88_);
v_pb_93_ = lean_nat_mod(v___x_92_, v___x_90_);
lean_dec(v___x_92_);
v___x_94_ = lean_nat_add(v_pa_91_, v___x_90_);
v___x_95_ = lean_nat_sub(v___x_94_, v_pb_93_);
lean_dec(v___x_94_);
v_forward_96_ = lean_nat_mod(v___x_95_, v___x_90_);
lean_dec(v___x_95_);
v___x_97_ = lean_nat_add(v_pb_93_, v___x_90_);
lean_dec(v_pb_93_);
v___x_98_ = lean_nat_sub(v___x_97_, v_pa_91_);
lean_dec(v_pa_91_);
lean_dec(v___x_97_);
v_backward_99_ = lean_nat_mod(v___x_98_, v___x_90_);
lean_dec(v___x_98_);
v___x_100_ = lean_nat_dec_le(v_forward_96_, v_backward_99_);
if (v___x_100_ == 0)
{
uint64_t v___x_101_; 
lean_dec(v_forward_96_);
v___x_101_ = lean_uint64_of_nat(v_backward_99_);
lean_dec(v_backward_99_);
return v___x_101_;
}
else
{
uint64_t v___x_102_; 
lean_dec(v_backward_99_);
v___x_102_ = lean_uint64_of_nat(v_forward_96_);
lean_dec(v_forward_96_);
return v___x_102_;
}
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseDifferenceU64___boxed(lean_object* v_a_103_, lean_object* v_b_104_){
_start:
{
uint64_t v_a_boxed_105_; uint64_t v_b_boxed_106_; uint64_t v_res_107_; lean_object* v_r_108_; 
v_a_boxed_105_ = lean_unbox_uint64(v_a_103_);
lean_dec_ref(v_a_103_);
v_b_boxed_106_ = lean_unbox_uint64(v_b_104_);
lean_dec_ref(v_b_104_);
v_res_107_ = lean_get_phase_difference_u64(v_a_boxed_105_, v_b_boxed_106_);
v_r_108_ = lean_box_uint64(v_res_107_);
return v_r_108_;
}
}
LEAN_EXPORT uint64_t lean_estimate_period_u64(uint64_t v___n_109_){
_start:
{
uint64_t v___x_110_; 
v___x_110_ = 24ULL;
return v___x_110_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_estimatePeriodU64___boxed(lean_object* v___n_111_){
_start:
{
uint64_t v___n_boxed_112_; uint64_t v_res_113_; lean_object* v_r_114_; 
v___n_boxed_112_ = lean_unbox_uint64(v___n_111_);
lean_dec_ref(v___n_111_);
v_res_113_ = lean_estimate_period_u64(v___n_boxed_112_);
v_r_114_ = lean_box_uint64(v_res_113_);
return v_r_114_;
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
