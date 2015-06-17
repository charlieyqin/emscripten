// This file uses SSE2 by calling different functions with different interesting inputs and prints the results.
// Use a diff tool to compare the results between platforms.

#include <emmintrin.h>
#define ENABLE_SSE2
#include "test_sse_full.h"

//#define ENABLE_SCALAR_64BIT

int main()
{
	float *interesting_floats = get_interesting_floats();
	int numInterestingFloats = sizeof(interesting_floats_)/sizeof(interesting_floats_[0]);
	assert(numInterestingFloats % 4 == 0);

	uint32_t *interesting_ints = get_interesting_ints();
	int numInterestingInts = sizeof(interesting_ints_)/sizeof(interesting_ints_[0]);
	assert(numInterestingInts % 4 == 0);

	double *interesting_doubles = get_interesting_doubles();
	int numInterestingDoubles = sizeof(interesting_doubles_)/sizeof(interesting_doubles_[0]);
	assert(numInterestingDoubles % 4 == 0);

	// SSE2 Arithmetic instructions:
	M128i_M128i_M128i(_mm_add_epi16);
	M128i_M128i_M128i(_mm_add_epi32);
//	M128i_M128i_M128i(_mm_add_epi64); // FAILS
	M128i_M128i_M128i(_mm_add_epi8);
	Ret_M128d_M128d(__m128d, _mm_add_pd);
	Ret_M128d_M128d(__m128d, _mm_add_sd);
#if 0
	M128i_M128i_M128i(_mm_adds_epi16);
	M128i_M128i_M128i(_mm_adds_epi8);
	M128i_M128i_M128i(_mm_adds_epu16);
	M128i_M128i_M128i(_mm_adds_epu8);
#endif
	Ret_M128d_M128d(__m128d, _mm_div_pd);
	Ret_M128d_M128d(__m128d, _mm_div_sd);
#if 0
	M128i_M128i_M128i(_mm_madd_epi16);
	M128i_M128i_M128i(_mm_mul_epu32);
#endif

	Ret_M128d_M128d(__m128d, _mm_mul_pd);
	Ret_M128d_M128d(__m128d, _mm_mul_sd);
#if 0
	M128i_M128i_M128i(_mm_mulhi_epi16);
	M128i_M128i_M128i(_mm_mulhi_epu16);
#endif
	M128i_M128i_M128i(_mm_mullo_epi16);
#if 0
	M128i_M128i_M128i(_mm_sad_epu8);
#endif
	M128i_M128i_M128i(_mm_sub_epi16);
	M128i_M128i_M128i(_mm_sub_epi32);
	// M128i_M128i_M128i(_mm_sub_epi64); // FAILS
	M128i_M128i_M128i(_mm_sub_epi8);
	Ret_M128d_M128d(__m128d, _mm_sub_pd);
	Ret_M128d_M128d(__m128d, _mm_sub_sd);

#if 0
	M128i_M128i_M128i(_mm_subs_epi16);
	M128i_M128i_M128i(_mm_subs_epi8);
	M128i_M128i_M128i(_mm_subs_epu16);
	M128i_M128i_M128i(_mm_subs_epu8);
#endif
	// SSE2 Cast functions:
	Ret_M128d(__m128, _mm_castpd_ps);
	Ret_M128d(__m128i, _mm_castpd_si128);
	Ret_M128(__m128d, _mm_castps_pd);
	Ret_M128(__m128i, _mm_castps_si128);
	Ret_M128i(__m128d, _mm_castsi128_pd);
	Ret_M128i(__m128, _mm_castsi128_ps);

	// SSE2 Compare instructions:
#if 0
	M128i_M128i_M128i(_mm_cmpeq_epi16);
	M128i_M128i_M128i(_mm_cmpeq_epi32);
	M128i_M128i_M128i(_mm_cmpeq_epi8);
#if 0
	Ret_M128d_M128d(__m128d, _mm_cmpeq_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpeq_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpge_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpge_sd);
#endif
	M128i_M128i_M128i(_mm_cmpgt_epi16);
	M128i_M128i_M128i(_mm_cmpgt_epi32);
	M128i_M128i_M128i(_mm_cmpgt_epi8);
#if 0
	Ret_M128d_M128d(__m128d, _mm_cmpgt_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpgt_sd);
	Ret_M128d_M128d(__m128d, _mm_cmple_pd);
	Ret_M128d_M128d(__m128d, _mm_cmple_sd);
#endif
	M128i_M128i_M128i(_mm_cmplt_epi16);
	M128i_M128i_M128i(_mm_cmplt_epi32);
	M128i_M128i_M128i(_mm_cmplt_epi8);
#if 0
	Ret_M128d_M128d(__m128d, _mm_cmplt_pd);
	Ret_M128d_M128d(__m128d, _mm_cmplt_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpneq_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpneq_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpnge_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpnge_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpngt_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpngt_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpnle_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpnle_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpnlt_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpnlt_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpord_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpord_sd);
	Ret_M128d_M128d(__m128d, _mm_cmpunord_pd);
	Ret_M128d_M128d(__m128d, _mm_cmpunord_sd);
	Ret_M128d_M128d(int, _mm_comieq_sd);
	Ret_M128d_M128d(int, _mm_comige_sd);
	Ret_M128d_M128d(int, _mm_comigt_sd);
	Ret_M128d_M128d(int, _mm_comile_sd);
	Ret_M128d_M128d(int, _mm_comilt_sd);
	Ret_M128d_M128d(int, _mm_comineq_sd);
	Ret_M128d_M128d(int, _mm_ucomieq_sd);
	Ret_M128d_M128d(int, _mm_ucomige_sd);
	Ret_M128d_M128d(int, _mm_ucomigt_sd);
	Ret_M128d_M128d(int, _mm_ucomile_sd);
	Ret_M128d_M128d(int, _mm_ucomilt_sd);
	Ret_M128d_M128d(int, _mm_ucomineq_sd);
#endif
#endif

	// SSE2 Convert instructions:
#if 0
	Ret_M128i(__m128d, _mm_cvtepi32_pd);
#endif
	Ret_M128i(__m128, _mm_cvtepi32_ps);
#if 0
	Ret_M128d(__m128i, _mm_cvtpd_epi32);
	Ret_M128d(__m128, _mm_cvtpd_ps);
#endif
#if 0 // Emscripten: RangeError: SIMD conversion loses precision
	Ret_M128(__m128i, _mm_cvtps_epi32);
#endif
#if 0
	Ret_M128(__m128d,  _mm_cvtps_pd);
#endif
	Ret_M128(double, _mm_cvtsd_f64);
#if 0
	Ret_M128d(int, _mm_cvtsd_si32);
	Ret_M128d(int64_t, _mm_cvtsd_si64);
//	Ret_M128d(int64_t, _mm_cvtsd_si64x);
#endif
	Ret_M128i(int, _mm_cvtsi128_si32);
#ifdef ENABLE_SCALAR_64BIT
	Ret_M128i(int64_t, _mm_cvtsi128_si64);
#endif
//	Ret_M128i(int64_t, _mm_cvtsi128_si64x);
	Ret_M128d_int(__m128d, _mm_cvtsi32_sd);
	Ret_int(__m128i, _mm_cvtsi32_si128);
#ifdef ENABLE_SCALAR_64BIT
	Ret_M128d_int64(__m128d, _mm_cvtsi64_sd);
	Ret_int64(__m128i, _mm_cvtsi64_si128);
#endif
//	Ret_int64(__m128d, _mm_cvtsi64x_sd);
//	Ret_int64(__m128i, _mm_cvtsi64x_si128);
	Ret_M128d_M128d(__m128d, _mm_cvtss_sd);
#if 0
	Ret_M128d(__m128i, _mm_cvttpd_epi32);
	Ret_M128(__m128i, _mm_cvttps_epi32);
#endif
	Ret_M128d(int, _mm_cvttsd_si32);
#ifdef ENABLE_SCALAR_64BIT
	Ret_M128d(int64_t, _mm_cvttsd_si64);
#endif
//	Ret_M128d(int64_t, _mm_cvttsd_si64x);

	// SSE2 Elementary Math Functions instructions:
	Ret_M128d(__m128d, _mm_sqrt_pd);
	Ret_M128d_M128d(__m128d, _mm_sqrt_sd);

	// SSE2 General Support instructions:
	_mm_clflush(interesting_floats);
	_mm_lfence();
	_mm_mfence();
	_mm_pause();

	// SSE2 Load functions:
	Ret_DoublePtr(__m128d, _mm_load_pd, 2, 2);
	Ret_DoublePtr(__m128d, _mm_load_pd1, 1, 1);
	Ret_DoublePtr(__m128d, _mm_load_sd, 1, 1);
	Ret_IntPtr(__m128i, _mm_load_si128, __m128i*, 4, 4);
	Ret_DoublePtr(__m128d, _mm_load1_pd, 1, 1);
	Ret_M128d_DoublePtr(__m128d, _mm_loadh_pd, double*, 1, 1);
#ifdef ENABLE_SCALAR_64BIT
	Ret_IntPtr(__m128i, _mm_loadl_epi64, __m128i*, 2, 1);
#endif
	Ret_M128d_DoublePtr(__m128d, _mm_loadl_pd, double*, 1, 1);
	Ret_DoublePtr(__m128d, _mm_loadr_pd, 2, 2);
	Ret_DoublePtr(__m128d, _mm_loadu_pd, 2, 1);
	Ret_IntPtr(__m128i, _mm_loadu_si128, __m128i*, 4, 1);

	// SSE2 Logical instructions:
	Ret_M128d_M128d(__m128d, _mm_and_pd);
	M128i_M128i_M128i(_mm_and_si128);
	Ret_M128d_M128d(__m128d, _mm_andnot_pd);
	M128i_M128i_M128i(_mm_andnot_si128);
	Ret_M128d_M128d(__m128d, _mm_or_pd);
	M128i_M128i_M128i(_mm_or_si128);
	Ret_M128d_M128d(__m128d, _mm_xor_pd);
	M128i_M128i_M128i(_mm_xor_si128);

	// SSE2 Miscellaneous instructions:
#if 0
	Ret_M128i(int, _mm_movemask_epi8);
	Ret_M128d(int, _mm_movemask_pd);
	M128i_M128i_M128i(_mm_packs_epi16);
	M128i_M128i_M128i(_mm_packs_epi32);
	M128i_M128i_M128i(_mm_packus_epi16);
	M128i_M128i_M128i(_mm_sad_epu8);
#endif

	// SSE2 Move instructions:
	Ret_M128i(__m128i, _mm_move_epi64);
	Ret_M128d_M128d(__m128d, _mm_move_sd);

	// SSE2 Probability/Statistics instructions:
#if 0
	M128i_M128i_M128i(_mm_avg_epu16);
	M128i_M128i_M128i(_mm_avg_epu8);
#endif
/*
	// SSE2 Set functions:
	_mm_set_epi16
	_mm_set_epi32
	_mm_set_epi64
	_mm_set_epi64x
	_mm_set_epi8
	_mm_set_pd
	_mm_set_pd1
	_mm_set_sd
	_mm_set1_epi16
	_mm_set1_epi32
	_mm_set1_epi64
	_mm_set1_epi64x
	_mm_set1_epi8
	_mm_set1_pd
	_mm_setr_epi16
	_mm_setr_epi32
	_mm_setr_epi64
	_mm_setr_epi8
	_mm_setr_pd
	_mm_setzero_pd
	_mm_setzero_si128
*/

	// SSE2 Shift instructions:
#if 0
//	Ret_M128i_Tint(__m128i, _mm_bslli_si128);
//	Ret_M128i_Tint(__m128i, _mm_bsrli_si128);
	M128i_M128i_M128i(_mm_sll_epi16);
	M128i_M128i_M128i(_mm_sll_epi32);
	M128i_M128i_M128i(_mm_sll_epi64);
	Ret_M128i_Tint(__m128i, _mm_slli_epi16);
	Ret_M128i_Tint(__m128i, _mm_slli_epi32);
	Ret_M128i_Tint(__m128i, _mm_slli_epi64);
	Ret_M128i_Tint(__m128i, _mm_slli_si128);
	M128i_M128i_M128i(_mm_sra_epi16);
	M128i_M128i_M128i(_mm_sra_epi32);
	Ret_M128i_Tint(__m128i, _mm_srai_epi16);
	Ret_M128i_Tint(__m128i, _mm_srai_epi32);
	M128i_M128i_M128i(_mm_srl_epi16);
	M128i_M128i_M128i(_mm_srl_epi32);
	M128i_M128i_M128i(_mm_srl_epi64);
	Ret_M128i_Tint(__m128i, _mm_srli_epi16);
	Ret_M128i_Tint(__m128i, _mm_srli_epi32);
	Ret_M128i_Tint(__m128i, _mm_srli_epi64);
//	Ret_M128i_Tint(__m128i, _mm_srli_epi128);

	// SSE2 Special Math instructions:
	M128i_M128i_M128i(_mm_max_epi16);
	M128i_M128i_M128i(_mm_max_epu8);
	Ret_M128d_M128d(__m128d, _mm_max_pd);
	Ret_M128d_M128d(__m128d, _mm_max_sd);
	M128i_M128i_M128i(_mm_min_epi16);
	M128i_M128i_M128i(_mm_min_epu8);
	Ret_M128d_M128d(__m128d, _mm_min_pd);
	Ret_M128d_M128d(__m128d, _mm_min_sd);
#endif

	// SSE2 Store instructions:
#if 0
	void_M128i_M128i_OutIntPtr(_mm_maskmoveu_si128, char*, 16, 1);
#endif
	void_OutDoublePtr_M128d(_mm_store_pd, double*, 16, 16);
//	void_OutDoublePtr_M128d(_mm_store_pd1, double*, 16, 16);
	void_OutDoublePtr_M128d(_mm_store_sd, double*, 8, 1);
	void_OutIntPtr_M128(_mm_store_si128, __m128i*, 16, 16);
	void_OutDoublePtr_M128d(_mm_store1_pd, double*, 16, 16);
	void_OutDoublePtr_M128d(_mm_storeh_pd, double*, 8, 1);
#ifdef ENABLE_SCALAR_64BIT
	void_OutIntPtr_M128(_mm_storel_epi64, __m128i*, 8, 1);
#endif
	void_OutDoublePtr_M128d(_mm_storel_pd, double*, 8, 1);
	void_OutDoublePtr_M128d(_mm_storer_pd, double*, 16, 16);
	void_OutDoublePtr_M128d(_mm_storeu_pd, double*, 16, 1);
	void_OutIntPtr_M128(_mm_storeu_si128, __m128i*, 16, 1);
	void_OutDoublePtr_M128d(_mm_stream_pd, double*, 16, 16);
	void_OutIntPtr_M128(_mm_stream_si128, __m128i*, 16, 16);
	void_OutIntPtr_int(_mm_stream_si32, int*, 4, 1);
#ifdef ENABLE_SCALAR_64BIT
	void_OutIntPtr_int64(_mm_stream_si64, int64_t*, 8, 1);
#endif

	// SSE2 Swizzle instructions:
	Ret_M128i_Tint(int, _mm_extract_epi16);
#if 0
	Ret_M128i_int_Tint(__m128i, _mm_insert_epi16);
#endif
	Ret_M128i_Tint(__m128i, _mm_shuffle_epi32);
	Ret_M128d_M128d_Tint(__m128d, _mm_shuffle_pd);
	Ret_M128i_Tint(__m128i, _mm_shufflehi_epi16);
	Ret_M128i_Tint(__m128i, _mm_shufflelo_epi16);
	M128i_M128i_M128i(_mm_unpackhi_epi16);
	M128i_M128i_M128i(_mm_unpackhi_epi32);
	M128i_M128i_M128i(_mm_unpackhi_epi64);
	M128i_M128i_M128i(_mm_unpackhi_epi8);
	Ret_M128d_M128d(__m128d, _mm_unpackhi_pd);
	M128i_M128i_M128i(_mm_unpacklo_epi16);
	M128i_M128i_M128i(_mm_unpacklo_epi32);
	M128i_M128i_M128i(_mm_unpacklo_epi64);
	M128i_M128i_M128i(_mm_unpacklo_epi8);
	Ret_M128d_M128d(__m128d, _mm_unpacklo_pd);
}
