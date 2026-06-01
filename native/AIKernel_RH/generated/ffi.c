// Lean compiler output
// Module: ILA.Primegenerator.FFI
// Imports: public import Init public meta import Init public import ILA.Primegenerator.InterferenceEnergyFast public import ILA.Primegenerator.Phase
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
lean_object* lp_primegenerator_ILA_Primegenerator_Phase_ofNat_x3f(lean_object*);
lean_object* lp_primegenerator_ILA_Primegenerator_interferenceEnergy__fast(lean_object*);
uint64_t get_interference_energy(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyExtern___boxed(lean_object*);
lean_object* get_interference_energy_batch(size_t, size_t, size_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyBatchExtern___boxed(lean_object*, lean_object*, lean_object*);
uint8_t get_phase(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseExtern___boxed(lean_object*);
uint64_t get_phase_residue(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseResidueExtern___boxed(lean_object*);
lean_object* get_interference_detail(uint64_t, size_t, size_t, size_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceDetailExtern___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* search_stable_points(uint64_t, uint64_t, size_t, size_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_searchStablePointsExtern___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
uint64_t get_phase_difference(uint64_t, uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseDifferenceExtern___boxed(lean_object*, lean_object*);
uint64_t estimate_period(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_estimatePeriodExtern___boxed(lean_object*);
lean_object* map_to_phase(size_t, size_t, size_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_mapToPhaseExtern___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint64_t lean_interference_energy_fast_u64(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyFastU64___boxed(lean_object*);
LEAN_EXPORT uint64_t lean_get_phase_u64(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseU64___boxed(lean_object*);
LEAN_EXPORT uint8_t lean_get_phase_u8(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseU8___boxed(lean_object*);
LEAN_EXPORT uint64_t lean_get_phase_residue_u64(uint64_t);
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseResidueU64___boxed(lean_object*);
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
size_t v_input_boxed_12_; size_t v_output_boxed_13_; size_t v_count_boxed_14_; lean_object* v_res_15_; 
v_input_boxed_12_ = lean_unbox_usize(v_input_9_);
lean_dec(v_input_9_);
v_output_boxed_13_ = lean_unbox_usize(v_output_10_);
lean_dec(v_output_10_);
v_count_boxed_14_ = lean_unbox_usize(v_count_11_);
lean_dec(v_count_11_);
v_res_15_ = get_interference_energy_batch(v_input_boxed_12_, v_output_boxed_13_, v_count_boxed_14_);
return v_res_15_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseExtern___boxed(lean_object* v_n_17_){
_start:
{
uint64_t v_n_boxed_18_; uint8_t v_res_19_; lean_object* v_r_20_; 
v_n_boxed_18_ = lean_unbox_uint64(v_n_17_);
lean_dec_ref(v_n_17_);
v_res_19_ = get_phase(v_n_boxed_18_);
v_r_20_ = lean_box(v_res_19_);
return v_r_20_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseResidueExtern___boxed(lean_object* v_n_22_){
_start:
{
uint64_t v_n_boxed_23_; uint64_t v_res_24_; lean_object* v_r_25_; 
v_n_boxed_23_ = lean_unbox_uint64(v_n_22_);
lean_dec_ref(v_n_22_);
v_res_24_ = get_phase_residue(v_n_boxed_23_);
v_r_25_ = lean_box_uint64(v_res_24_);
return v_r_25_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceDetailExtern___boxed(lean_object* v_n_30_, lean_object* v_phase_31_, lean_object* v_energy_32_, lean_object* v_residue_33_){
_start:
{
uint64_t v_n_boxed_34_; size_t v_phase_boxed_35_; size_t v_energy_boxed_36_; size_t v_residue_boxed_37_; lean_object* v_res_38_; 
v_n_boxed_34_ = lean_unbox_uint64(v_n_30_);
lean_dec_ref(v_n_30_);
v_phase_boxed_35_ = lean_unbox_usize(v_phase_31_);
lean_dec(v_phase_31_);
v_energy_boxed_36_ = lean_unbox_usize(v_energy_32_);
lean_dec(v_energy_32_);
v_residue_boxed_37_ = lean_unbox_usize(v_residue_33_);
lean_dec(v_residue_33_);
v_res_38_ = get_interference_detail(v_n_boxed_34_, v_phase_boxed_35_, v_energy_boxed_36_, v_residue_boxed_37_);
return v_res_38_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_searchStablePointsExtern___boxed(lean_object* v_start_43_, lean_object* v_stop_44_, lean_object* v_buffer_45_, lean_object* v_count_46_){
_start:
{
uint64_t v_start_boxed_47_; uint64_t v_stop_boxed_48_; size_t v_buffer_boxed_49_; size_t v_count_boxed_50_; lean_object* v_res_51_; 
v_start_boxed_47_ = lean_unbox_uint64(v_start_43_);
lean_dec_ref(v_start_43_);
v_stop_boxed_48_ = lean_unbox_uint64(v_stop_44_);
lean_dec_ref(v_stop_44_);
v_buffer_boxed_49_ = lean_unbox_usize(v_buffer_45_);
lean_dec(v_buffer_45_);
v_count_boxed_50_ = lean_unbox_usize(v_count_46_);
lean_dec(v_count_46_);
v_res_51_ = search_stable_points(v_start_boxed_47_, v_stop_boxed_48_, v_buffer_boxed_49_, v_count_boxed_50_);
return v_res_51_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseDifferenceExtern___boxed(lean_object* v_a_54_, lean_object* v_b_55_){
_start:
{
uint64_t v_a_boxed_56_; uint64_t v_b_boxed_57_; uint64_t v_res_58_; lean_object* v_r_59_; 
v_a_boxed_56_ = lean_unbox_uint64(v_a_54_);
lean_dec_ref(v_a_54_);
v_b_boxed_57_ = lean_unbox_uint64(v_b_55_);
lean_dec_ref(v_b_55_);
v_res_58_ = get_phase_difference(v_a_boxed_56_, v_b_boxed_57_);
v_r_59_ = lean_box_uint64(v_res_58_);
return v_r_59_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_estimatePeriodExtern___boxed(lean_object* v_n_61_){
_start:
{
uint64_t v_n_boxed_62_; uint64_t v_res_63_; lean_object* v_r_64_; 
v_n_boxed_62_ = lean_unbox_uint64(v_n_61_);
lean_dec_ref(v_n_61_);
v_res_63_ = estimate_period(v_n_boxed_62_);
v_r_64_ = lean_box_uint64(v_res_63_);
return v_r_64_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_mapToPhaseExtern___boxed(lean_object* v_input_68_, lean_object* v_output_69_, lean_object* v_count_70_){
_start:
{
size_t v_input_boxed_71_; size_t v_output_boxed_72_; size_t v_count_boxed_73_; lean_object* v_res_74_; 
v_input_boxed_71_ = lean_unbox_usize(v_input_68_);
lean_dec(v_input_68_);
v_output_boxed_72_ = lean_unbox_usize(v_output_69_);
lean_dec(v_output_69_);
v_count_boxed_73_ = lean_unbox_usize(v_count_70_);
lean_dec(v_count_70_);
v_res_74_ = map_to_phase(v_input_boxed_71_, v_output_boxed_72_, v_count_boxed_73_);
return v_res_74_;
}
}
LEAN_EXPORT uint64_t lean_interference_energy_fast_u64(uint64_t v_n_75_){
_start:
{
lean_object* v___x_76_; lean_object* v___x_77_; uint64_t v___x_78_; 
v___x_76_ = lean_uint64_to_nat(v_n_75_);
v___x_77_ = lp_primegenerator_ILA_Primegenerator_interferenceEnergy__fast(v___x_76_);
v___x_78_ = lean_uint64_of_nat(v___x_77_);
lean_dec(v___x_77_);
return v___x_78_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_interferenceEnergyFastU64___boxed(lean_object* v_n_79_){
_start:
{
uint64_t v_n_boxed_80_; uint64_t v_res_81_; lean_object* v_r_82_; 
v_n_boxed_80_ = lean_unbox_uint64(v_n_79_);
lean_dec_ref(v_n_79_);
v_res_81_ = lean_interference_energy_fast_u64(v_n_boxed_80_);
v_r_82_ = lean_box_uint64(v_res_81_);
return v_r_82_;
}
}
LEAN_EXPORT uint64_t lean_get_phase_u64(uint64_t v_n_83_){
_start:
{
lean_object* v___x_84_; lean_object* v___x_85_; 
v___x_84_ = lean_uint64_to_nat(v_n_83_);
v___x_85_ = lp_primegenerator_ILA_Primegenerator_Phase_ofNat_x3f(v___x_84_);
lean_dec(v___x_84_);
if (lean_obj_tag(v___x_85_) == 0)
{
uint64_t v___x_86_; 
v___x_86_ = 0ULL;
return v___x_86_;
}
else
{
lean_object* v_val_87_; uint8_t v___x_88_; 
v_val_87_ = lean_ctor_get(v___x_85_, 0);
lean_inc(v_val_87_);
lean_dec_ref_known(v___x_85_, 1);
v___x_88_ = lean_unbox(v_val_87_);
lean_dec(v_val_87_);
switch(v___x_88_)
{
case 0:
{
uint64_t v___x_89_; 
v___x_89_ = 1ULL;
return v___x_89_;
}
case 1:
{
uint64_t v___x_90_; 
v___x_90_ = 2ULL;
return v___x_90_;
}
case 2:
{
uint64_t v___x_91_; 
v___x_91_ = 3ULL;
return v___x_91_;
}
default: 
{
uint64_t v___x_92_; 
v___x_92_ = 4ULL;
return v___x_92_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseU64___boxed(lean_object* v_n_93_){
_start:
{
uint64_t v_n_boxed_94_; uint64_t v_res_95_; lean_object* v_r_96_; 
v_n_boxed_94_ = lean_unbox_uint64(v_n_93_);
lean_dec_ref(v_n_93_);
v_res_95_ = lean_get_phase_u64(v_n_boxed_94_);
v_r_96_ = lean_box_uint64(v_res_95_);
return v_r_96_;
}
}
LEAN_EXPORT uint8_t lean_get_phase_u8(uint64_t v_n_97_){
_start:
{
lean_object* v___x_98_; lean_object* v___x_99_; 
v___x_98_ = lean_uint64_to_nat(v_n_97_);
v___x_99_ = lp_primegenerator_ILA_Primegenerator_Phase_ofNat_x3f(v___x_98_);
lean_dec(v___x_98_);
if (lean_obj_tag(v___x_99_) == 0)
{
uint8_t v___x_100_; 
v___x_100_ = 0;
return v___x_100_;
}
else
{
lean_object* v_val_101_; uint8_t v___x_102_; 
v_val_101_ = lean_ctor_get(v___x_99_, 0);
lean_inc(v_val_101_);
lean_dec_ref_known(v___x_99_, 1);
v___x_102_ = lean_unbox(v_val_101_);
lean_dec(v_val_101_);
switch(v___x_102_)
{
case 0:
{
uint8_t v___x_103_; 
v___x_103_ = 1;
return v___x_103_;
}
case 1:
{
uint8_t v___x_104_; 
v___x_104_ = 2;
return v___x_104_;
}
case 2:
{
uint8_t v___x_105_; 
v___x_105_ = 3;
return v___x_105_;
}
default: 
{
uint8_t v___x_106_; 
v___x_106_ = 4;
return v___x_106_;
}
}
}
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseU8___boxed(lean_object* v_n_107_){
_start:
{
uint64_t v_n_boxed_108_; uint8_t v_res_109_; lean_object* v_r_110_; 
v_n_boxed_108_ = lean_unbox_uint64(v_n_107_);
lean_dec_ref(v_n_107_);
v_res_109_ = lean_get_phase_u8(v_n_boxed_108_);
v_r_110_ = lean_box(v_res_109_);
return v_r_110_;
}
}
LEAN_EXPORT uint64_t lean_get_phase_residue_u64(uint64_t v_n_111_){
_start:
{
lean_object* v___x_112_; lean_object* v___x_113_; lean_object* v___x_114_; uint64_t v___x_115_; 
v___x_112_ = lean_uint64_to_nat(v_n_111_);
v___x_113_ = lean_unsigned_to_nat(24u);
v___x_114_ = lean_nat_mod(v___x_112_, v___x_113_);
lean_dec(v___x_112_);
v___x_115_ = lean_uint64_of_nat(v___x_114_);
lean_dec(v___x_114_);
return v___x_115_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseResidueU64___boxed(lean_object* v_n_116_){
_start:
{
uint64_t v_n_boxed_117_; uint64_t v_res_118_; lean_object* v_r_119_; 
v_n_boxed_117_ = lean_unbox_uint64(v_n_116_);
lean_dec_ref(v_n_116_);
v_res_118_ = lean_get_phase_residue_u64(v_n_boxed_117_);
v_r_119_ = lean_box_uint64(v_res_118_);
return v_r_119_;
}
}
LEAN_EXPORT uint64_t lean_get_phase_difference_u64(uint64_t v_a_120_, uint64_t v_b_121_){
_start:
{
lean_object* v___x_122_; lean_object* v___x_123_; lean_object* v_pa_124_; lean_object* v___x_125_; lean_object* v_pb_126_; lean_object* v___x_127_; lean_object* v___x_128_; lean_object* v_forward_129_; lean_object* v___x_130_; lean_object* v___x_131_; lean_object* v_backward_132_; uint8_t v___x_133_; 
v___x_122_ = lean_uint64_to_nat(v_a_120_);
v___x_123_ = lean_unsigned_to_nat(24u);
v_pa_124_ = lean_nat_mod(v___x_122_, v___x_123_);
lean_dec(v___x_122_);
v___x_125_ = lean_uint64_to_nat(v_b_121_);
v_pb_126_ = lean_nat_mod(v___x_125_, v___x_123_);
lean_dec(v___x_125_);
v___x_127_ = lean_nat_add(v_pa_124_, v___x_123_);
v___x_128_ = lean_nat_sub(v___x_127_, v_pb_126_);
lean_dec(v___x_127_);
v_forward_129_ = lean_nat_mod(v___x_128_, v___x_123_);
lean_dec(v___x_128_);
v___x_130_ = lean_nat_add(v_pb_126_, v___x_123_);
lean_dec(v_pb_126_);
v___x_131_ = lean_nat_sub(v___x_130_, v_pa_124_);
lean_dec(v_pa_124_);
lean_dec(v___x_130_);
v_backward_132_ = lean_nat_mod(v___x_131_, v___x_123_);
lean_dec(v___x_131_);
v___x_133_ = lean_nat_dec_le(v_forward_129_, v_backward_132_);
if (v___x_133_ == 0)
{
uint64_t v___x_134_; 
lean_dec(v_forward_129_);
v___x_134_ = lean_uint64_of_nat(v_backward_132_);
lean_dec(v_backward_132_);
return v___x_134_;
}
else
{
uint64_t v___x_135_; 
lean_dec(v_backward_132_);
v___x_135_ = lean_uint64_of_nat(v_forward_129_);
lean_dec(v_forward_129_);
return v___x_135_;
}
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_phaseDifferenceU64___boxed(lean_object* v_a_136_, lean_object* v_b_137_){
_start:
{
uint64_t v_a_boxed_138_; uint64_t v_b_boxed_139_; uint64_t v_res_140_; lean_object* v_r_141_; 
v_a_boxed_138_ = lean_unbox_uint64(v_a_136_);
lean_dec_ref(v_a_136_);
v_b_boxed_139_ = lean_unbox_uint64(v_b_137_);
lean_dec_ref(v_b_137_);
v_res_140_ = lean_get_phase_difference_u64(v_a_boxed_138_, v_b_boxed_139_);
v_r_141_ = lean_box_uint64(v_res_140_);
return v_r_141_;
}
}
LEAN_EXPORT uint64_t lean_estimate_period_u64(uint64_t v___n_142_){
_start:
{
uint64_t v___x_143_; 
v___x_143_ = 24ULL;
return v___x_143_;
}
}
LEAN_EXPORT lean_object* l_ILA_Primegenerator_FFI_estimatePeriodU64___boxed(lean_object* v___n_144_){
_start:
{
uint64_t v___n_boxed_145_; uint64_t v_res_146_; lean_object* v_r_147_; 
v___n_boxed_145_ = lean_unbox_uint64(v___n_144_);
lean_dec_ref(v___n_144_);
v_res_146_ = lean_estimate_period_u64(v___n_boxed_145_);
v_r_147_ = lean_box_uint64(v_res_146_);
return v_r_147_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_primegenerator_ILA_Primegenerator_InterferenceEnergyFast(uint8_t builtin);
lean_object* initialize_primegenerator_ILA_Primegenerator_Phase(uint8_t builtin);
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
res = initialize_primegenerator_ILA_Primegenerator_Phase(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
