/*
* ImagiNet Compiler 5.13.5501.65534+6ddbc592e16d83c41e7b0b9321278834ef733ad3
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 17:44:39 UTC. Any changes will be lost.
* 
* Model ID  6abb4123-4cb5-4c6c-8454-cad7f130a293
* 
* Memory    Size                      Efficiency
* Buffers   10256 bytes (RAM)         80 %
* State     25992 bytes (RAM)         100 %
* Readonly  41952 bytes (Flash)       100 %
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param data_out Output features. Output float[10].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_dequeue(float *data_out);
* 
*  @description: Try write data to model.
*  @param data_in Input features. Input float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_enqueue(const float *data_in);
* 
*  @description: Closes and flushes streams, free any heap allocated memory.
*  void IMAI_finalize(void);
* 
*  @description: Resets windows and neural networks(i.e. RNNs) to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_soft_reset(void);
* 
*  @description: Initializes buffers to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_init(void);
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
* 
* Notes:
* 	-> This code was generated with DEEPCRAFT Studio using:
* 		ml-coretools 3.2.0.9646.
* 		tensorflow 2.19.0.
* 		ethos-u-vela 4.5.0.
* 	-> This code requires the following Modus Toolbox libraries (add them to your
* 	project using the Library Manager):
* 		ml-middleware 3.2.0.
* 		ml-tflite-micro 3.2.0.
*/

// Global symbol checks
#ifndef COMPONENT_ML_TFLM
	#error Symbol COMPONENT_ML_TFLM is not defined. Visit the Infineon ML\
	deployment example to see how to define this symbol. Add 'COMPONENTS+=ML_TFLM'\
	to your Makefile to enable this symbol.
#endif

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "cy_retarget_io.h"
#include "cy_utils.h"
#include "mtb_ml_model.h"
#include "mtb_ml_utils.h"
#include "mtb_ml.h"

#include "model.h"

#ifdef __GNUC__
	#define ALIGNED(x) __attribute__((aligned(x)))
#else
	#define ALIGNED(x) __declspec(align(x))
#endif

#if defined(__GNUC__) || defined(__clang__)
	#define ATTRIB_WEAK  __attribute__((weak))
#else
	#define ATTRIB_WEAK 
#endif

#ifdef CY_ML_MODEL_MEM
 #define IM_ML_MODEL_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_MODEL_MEM))
#else
 #define IM_ML_MODEL_MEM
#endif

#ifdef CY_ML_ARENA_MEM
 #define IM_ML_ARENA_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_ARENA_MEM))
#else
 #define IM_ML_ARENA_MEM CY_SECTION(".cy_socmem_data")
#endif

#ifdef CY_ML_WORKING_MEM
 #define IM_ML_WORKING_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_WORKING_MEM))
#else
 #define IM_ML_WORKING_MEM CY_SECTION(".cy_socmem_data")
#endif

// Working memory
static IM_ML_WORKING_MEM ALIGNED(16) int8_t _buffer[10256];
static IM_ML_ARENA_MEM ALIGNED(16) int8_t _state[25992];

// Parameters
static IM_ML_MODEL_MEM ALIGNED(16) uint32_t _k7[] = {
    0x0000001c, 0x334c4654, 0x00200014, 0x0018001c, 0x00100014, 0x0000000c, 0x00040008, 0x00000014, 
    0x0000001c, 0x00000090, 0x000000e8, 0x000086bc, 0x000086cc, 0x00009afc, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000024, 0x00000004, 0x00000008, 0x6579616c, 0x30325f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffff790a, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x00000027, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x00000026, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x00000028, 0x000085d0, 0x000085c8, 0x00008538, 
    0x000084e8, 0x00008498, 0x00005488, 0x00004878, 0x00003ea8, 0x00003e64, 0x00003e48, 0x00003e28, 
    0x00003e08, 0x00003de8, 0x000025d8, 0x00002548, 0x00001938, 0x000018e8, 0x00000690, 0x00000180, 
    0x00000148, 0x00000134, 0x00000114, 0x0000010c, 0x00000104, 0x000000fc, 0x000000f4, 0x000000ec, 
    0x000000e4, 0x000000dc, 0x000000d4, 0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 
    0x000000a4, 0x0000009c, 0x00000094, 0x00000074, 0x00000004, 0xffff7a1e, 0x00000004, 0x00000060, 
    0x00000010, 0x00000000, 0x000e0008, 0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 
    0x00040008, 0x00000006, 0x00000004, 0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 
    0x45a742f2, 0x7403fb68, 0x00000003, 0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 
    0xffff7a8a, 0x00000004, 0x00000010, 0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffff6744, 
    0xffff6748, 0xffff674c, 0xffff6750, 0xffff6754, 0xffff6758, 0xffff675c, 0xffff6760, 0xffff6764, 
    0xffff6768, 0xffff676c, 0xffff6770, 0xffff6774, 0xffff6778, 0xffff677c, 0xffff6780, 0xffff7ae6, 
    0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xffff7b02, 0x00000004, 
    0x00000004, 0x00000001, 0xffff7b12, 0x00000004, 0x00000028, 0xbdb8e5d4, 0xbd657ae9, 0x3c6b49db, 
    0xbd94dfd7, 0x3d2542fe, 0xbc8e8140, 0x3dbdeb7e, 0x3d63b782, 0x3d9ea769, 0xbc52bcbb, 0xffff7b46, 
    0x00000004, 0x00000500, 0x3e2b7da9, 0x3e2fc588, 0xbdec8d14, 0x3d93107d, 0x3e4218e6, 0xbe3bea1c, 
    0x3ea82af0, 0x3e6420b2, 0x3e7524ac, 0xbe402e29, 0x3e715ebf, 0x3db0dd04, 0xbd8ce7da, 0x3e24191a, 
    0xbe0b66c3, 0xbd592c21, 0x3e2acdb4, 0x3e86129c, 0x3dd6cb19, 0x3e3bb742, 0xbe1369f1, 0x3e990ff1, 
    0xbe17c27f, 0xbe3256fd, 0xbf09ae8c, 0xbe3322d0, 0x3e28553d, 0xbe1b470d, 0xbeb31381, 0x3e6ce7c4, 
    0xbe791b35, 0xbd5b3093, 0x3e94863b, 0x3ed7d290, 0xbdb1ebb9, 0x3d3845c2, 0xbf2445ae, 0xbe59899e, 
    0x3e877156, 0xbf25aee6, 0x3e3a4412, 0x3ee4a51d, 0xbcaa1383, 0xbf366999, 0xbf43e51b, 0x3dd6ce68, 
    0x3e603e2a, 0x3e73980d, 0xbf1a8a4a, 0x3e6b1fd0, 0xbe899b0c, 0x3ee6df2c, 0x3f01e94e, 0xbee835fe, 
    0x3dd3b76d, 0xbeced71f, 0xbf2fe744, 0x3ec422d8, 0xbe5f9ca5, 0x3c18fb22, 0x3ec3b42c, 0xbf2405b6, 
    0x3e6db7d1, 0x3e2d0683, 0xbe422ff2, 0x3e992998, 0xbec48ddb, 0xbe961fbe, 0x3e921ae3, 0x3db3a338, 
    0xbf09fa3a, 0xbe732ab2, 0xbe8d7c4d, 0x3e24073d, 0xbe8576e8, 0x3eb31210, 0x3eb0785f, 0xbf022a15, 
    0xbf07328b, 0x3ebd9758, 0xbf143f13, 0xbea2be03, 0x3e207069, 0xbf3c61ce, 0x3e6dc770, 0x3f08e85c, 
    0xbe78bcfb, 0x3ea1f5d1, 0x3e22905f, 0xbefc4325, 0xbeea93d4, 0xbd6dc9bb, 0x3eeb7ffa, 0x3e3d79cd, 
    0x3eba4bd8, 0xbed8ab65, 0x3ee5e73b, 0xbe7abd81, 0xbf278d81, 0x3e348339, 0xbeccf3d9, 0x3eec820b, 
    0xbece3fe3, 0xbec70212, 0xbe71873f, 0x3e3cc516, 0x3d988bdf, 0x3eaedb5e, 0x3d185fb0, 0x3e8ca02e, 
    0xbe43eec6, 0xbf12205e, 0x3eb7be20, 0x3eecc683, 0xbf138ca9, 0xbea93b1a, 0x3e75c9fe, 0x3ddee4ac, 
    0xbe2d8538, 0x3ebdf291, 0x3e17f693, 0xbe4ff9c9, 0x3ebd0c89, 0xbf0af571, 0x3edafce4, 0x3eb275d4, 
    0xbed2495a, 0x3e367494, 0xbd1daffd, 0xbeae99e8, 0x3ef687cf, 0xbf26172b, 0xbdffe638, 0x3edfeab3, 
    0x3df1a348, 0xbefd3c9e, 0x3ef59657, 0xbd517624, 0xbf2729f6, 0xbeacf5b9, 0xbe22f9f0, 0x3e50aa65, 
    0x3e0cc821, 0x3eebdd48, 0x3f166619, 0xbec942c7, 0x3b2c2fd5, 0xbec844f9, 0xbe766026, 0xbd86a242, 
    0xbea7bfd3, 0xbdf5d1ce, 0xbf04da71, 0xbe8a909c, 0x3f003d02, 0x3de366f0, 0xbed09ef3, 0xbece7a27, 
    0x3eff584b, 0xbe82ef8a, 0xbdc142a5, 0x3e916245, 0x3ef8e50f, 0x3de9d814, 0x3da838d1, 0xbe9e125c, 
    0xbf330ab7, 0x3dcd1f0f, 0x3ea64d99, 0xbe06f3f5, 0xbf0b2172, 0x3e8ee658, 0xbebdb8e3, 0xbf002702, 
    0xbe03da7c, 0x3df283af, 0xbe084ba8, 0xbf16947f, 0x3e097a36, 0xbe9b76ce, 0x3e397821, 0xbceefa72, 
    0x3e9e0a77, 0x3e3c8e79, 0x3dcbb35b, 0x3d54de58, 0xbecff6ff, 0xbdb97474, 0xbd71d389, 0x3ecc2c84, 
    0xbed134b9, 0x3edcd10b, 0xbe9bd11b, 0xbeea8036, 0x3db88044, 0xbeb263db, 0xbc9e184a, 0x3d16704b, 
    0xbedaaba3, 0x3edfd32e, 0xbe0dd3dc, 0x3f0e3e1a, 0xbed29f45, 0xbeeb73e8, 0x3f08b944, 0x3ee06456, 
    0xbed81908, 0x3e296f64, 0xbe67dbc2, 0x3da64f3a, 0xbec44bf6, 0xbf0da053, 0x3d8a4240, 0xbe1c280b, 
    0x3db7c305, 0xbeb6db26, 0x3ea736cf, 0x3e840fbd, 0x3de4c227, 0xbe37498d, 0x3e8822cb, 0xbdc79047, 
    0xbed1b8c1, 0xbe930932, 0x3ed8d9e2, 0x3e70a72c, 0xbf0fa325, 0xbebb2979, 0xbe6a8d25, 0x3f0716b0, 
    0x3e92635c, 0xbf01b496, 0x3eac5899, 0xbf237e44, 0x3ec2bb98, 0xbebb3b99, 0x3ee4cc53, 0xbedce389, 
    0xbef8c9d7, 0xbdc178d9, 0xbe314831, 0xbd279115, 0x3ee9566d, 0x3e8325a6, 0xbe357e43, 0xbe8898ee, 
    0xbedf6fe7, 0xbf0eba44, 0xbf1bc3ad, 0xbe5fcd07, 0xbe9ea015, 0x3edd0173, 0xbdf0feda, 0x3e3f095c, 
    0xbea94507, 0xbe2337b3, 0xbf16ce59, 0xbe9115f3, 0x3d444b48, 0x3f1361b0, 0xbe03b4db, 0xbee89e89, 
    0xbd2d70ff, 0x3e9360ef, 0xbe64daa4, 0xbf3201a0, 0x3ead2d96, 0xbe911e02, 0xbf23a57d, 0x3d189d3a, 
    0x3eb7b8c1, 0xbf26eea9, 0x3e2580b4, 0x3d94323d, 0xbeb165f4, 0xbe7b6f2d, 0xbe4f46a4, 0x3db18321, 
    0xbf159f41, 0xbed3343b, 0x3ee02e5d, 0x3eacbb96, 0xbee72457, 0x3ebcca5a, 0xbe5a059e, 0xbf0e4a77, 
    0x3dbd1422, 0xbe271646, 0xbeaa8aa2, 0xbf031f29, 0x3b49244d, 0xbe0ed7f5, 0x3e988052, 0x3e37c713, 
    0xbf1b8422, 0xbf156c74, 0x3efa308e, 0x3d0885dd, 0x3e8b9bc7, 0xbe6d1332, 0x3e0df07b, 0x3edafc2b, 
    0x3ed9be9d, 0xbeb197c6, 0xbead1296, 0x3dcc37d3, 0x3ee0b3ac, 0x3e7504cd, 0xbf187735, 0xbe6a5ca1, 
    0x3ea229dc, 0xbf0f85c8, 0x3e7b0c06, 0xbeb21f8c, 0x3eedb7ad, 0xbed8a695, 0x3e7933b7, 0xbefc498e, 
    0xbccbc280, 0xbb8efb9d, 0xffff8052, 0x00000004, 0x00001248, 0xbe1dff16, 0x3d4bf5c7, 0x3d376ab7, 
    0xbd6a7162, 0x3e3d3cbd, 0xbdfd3811, 0x3e254013, 0x3e04e844, 0x3c578bc9, 0xbe440bf5, 0x3d4bed5a, 
    0xbdb621a4, 0x3bd996a0, 0x3e189ace, 0xbe02429c, 0x3d333634, 0xbe09024c, 0xbe0ae0e2, 0xbe21861f, 
    0xbdcfe73f, 0xbe1c794b, 0xbe492260, 0xbe191f1e, 0x3da8813f, 0x3dcc3c03, 0x3e0202ba, 0xbdaf5988, 
    0x3d99b2be, 0x3d7d24b1, 0x3b0ca5ee, 0x3cc3a3a9, 0xbe4bf40d, 0x3dee7a17, 0xbe095a68, 0x3e1fc418, 
    0xbd8bb30f, 0xbc979dea, 0xbdf73a85, 0xbdbd636f, 0x3e345907, 0x3e350ac4, 0xbe0ebff4, 0x3adbceb6, 
    0x3e172e47, 0xbda4e129, 0x3e2fc481, 0x3e1114db, 0x3dec342c, 0x3e7a0243, 0x3db1b20d, 0xbe0565fd, 
    0x3dd90f92, 0xbe9342fa, 0xbda52922, 0x3deacdb1, 0xbda9482d, 0xbcbd3454, 0xbd964143, 0x3dac3cbc, 
    0xbd539258, 0x3dea674b, 0x3e103a2a, 0xbcaba684, 0x3daf0c5b, 0xbcfd57a1, 0x3e16947e, 0x3af8f9e9, 
    0x3bbd4083, 0xbddde5a5, 0x3d874430, 0x3d8690c0, 0xbd886901, 0xbded99cb, 0xbc940887, 0xbdb3bd85, 
    0xbdeb9005, 0x3e8323d0, 0x3e43ae87, 0x3e332b5a, 0xbe0167e9, 0xbda4b410, 0xbe51c384, 0xbd9eee46, 
    0x3bed1a42, 0xbda26547, 0xbdc606ec, 0xbae0e5cf, 0x3e0cf247, 0x3e884a2a, 0xbe2cc055, 0xbd292044, 
    0x3c2bbc59, 0xbdde36a8, 0xbd8b6faf, 0x3c972823, 0x3dd1cec4, 0xbd7e1e5d, 0xbe231ac0, 0xbd5fd286, 
    0x3e2fa81c, 0xbda427a8, 0x3dc00ca2, 0x3db111f3, 0x3d3f62e4, 0x3de0539a, 0xbd6983fe, 0x38eb8496, 
    0x3c806913, 0x3e65282a, 0x3e532030, 0xbd396ed5, 0xbe0dc9d8, 0xbde21b15, 0xbdefa923, 0x3e3ec096, 
    0xbc86e665, 0xbe227f7a, 0xbd0c14bb, 0x3e1b94bb, 0x3ddd7709, 0x3d9d216f, 0xbdb4d306, 0xbe1f28a6, 
    0x3d532984, 0xbe29d447, 0xbe2a9981, 0xbdc643fd, 0xbd25ac27, 0x3e0ecc96, 0xbe26eb85, 0xbdda4f59, 
    0x3d8e03a5, 0xbe28dbbf, 0xbda81070, 0xbd6e5a2b, 0xbe50daa5, 0xbe54b88d, 0x3e2812a0, 0xbd8f1317, 
    0xbd90a814, 0x3de3a347, 0x3de7a6da, 0x3c22fd51, 0x3da31752, 0x3e0ce941, 0x3d1e6fec, 0xbde04576, 
    0x3b955d51, 0xbd7c3bd7, 0x3da00614, 0xbca246af, 0x3da33714, 0x3bfd7fe3, 0xbd02a502, 0xbd6fcc2f, 
    0xbe96f3be, 0xbdac6d11, 0x3e3c19b7, 0x3def1ec3, 0xbe13bdfb, 0x3d4297d0, 0xbdce4f71, 0xbe328b6e, 
    0xbd5b253d, 0xbe3709d6, 0xbe1cddf2, 0x3e2f8fd4, 0xbc87e91e, 0x3dba3b0b, 0x3d8858c5, 0x3e134424, 
    0x3e540cdc, 0x3d173bb7, 0xbdfc4b87, 0xbd83d1d9, 0xbe933b6f, 0x3beafb7c, 0x3dc75e09, 0x3e27634b, 
    0xbe10ee5a, 0xbe434e0a, 0x3dbc5315, 0xbda717e0, 0x3e4b1fbe, 0xbd35b27f, 0x3ce02a48, 0x3e12ca75, 
    0xbe278db5, 0x3d31ccd1, 0x3d9e7fa2, 0x3dd1e5a3, 0x3e0dafe0, 0x3e0d3bc8, 0xbe0961c5, 0xbda8b4c4, 
    0xbda51311, 0xbe5051ea, 0xbe371db3, 0x3d151391, 0x3d86a46c, 0xbe2b3a7a, 0x3e01330d, 0xbdd0db1b, 
    0xbdad1332, 0x3d6fa7b4, 0xbe0abda5, 0xbe058639, 0x3e2d1d03, 0xbcd711d7, 0x3d18105e, 0xbc1ace95, 
    0xbe4f5f4d, 0x3e0d3fd8, 0xbc4700a8, 0xbd99f6ad, 0xbd9718e1, 0xbd3cdcc1, 0x3e37fab2, 0xbdbcdaf4, 
    0xbdc64519, 0x3d742a41, 0xbe1b625b, 0x3e83cf9e, 0xbe1f25dc, 0x3dd9c193, 0x3ceaa716, 0x3aeb8bb2, 
    0x3d59836c, 0xbddca896, 0x3d8d039c, 0xbca6ad0e, 0xbdfdc0bf, 0x3e67a968, 0xbd919a00, 0x3d3b06ce, 
    0xbd882dc4, 0xbe2c8685, 0x3d942b07, 0xbdfbd990, 0xbdfafc85, 0xbd0cd018, 0x3d4af9d2, 0xbd00b6a7, 
    0x3e031eff, 0xbc83c558, 0x3d23ca9b, 0xbe115822, 0x3da67a99, 0xbd4ebfaa, 0xbe321344, 0xbdd9583b, 
    0x3dd2c4a6, 0x3dc97156, 0x3e4a9cdf, 0x39ac93ed, 0x3c61a47c, 0x3d445c44, 0xbe354f99, 0xbdf23e81, 
    0xbe1e59ea, 0xbe525091, 0x3e0c970c, 0x3bd01614, 0xbd8495e9, 0xbc6217af, 0x3ced454c, 0xbe4fd5e5, 
    0xbe0cdc50, 0xbda3d236, 0xbe86d6ca, 0xbe41a563, 0xbdf22846, 0x3e101c34, 0xbd0a64a5, 0xbd01a953, 
    0xbde8fad3, 0x3e11e6e3, 0xbd83d363, 0xbd262777, 0x3e005566, 0x3c70bf1e, 0xbda398b0, 0x3c857a9f, 
    0x3d999418, 0x3d2d7ff8, 0xbd764262, 0xbdb6ddf1, 0xbe0ac95d, 0x3e24b458, 0x3ccf989d, 0xbd5db022, 
    0xbcbe6da6, 0x3c14e9dc, 0x3e04df77, 0xbe6b76e1, 0x3dc6e431, 0x3d776ed2, 0xbc65a386, 0xbdf76a16, 
    0x3e88ae8a, 0xbdce658b, 0xbcc399ba, 0xbd9a915d, 0xbd212158, 0xbd5d4c86, 0x3b89c001, 0x3ddbc400, 
    0x3e156bb2, 0xbd7b8937, 0x3d463879, 0xbde37106, 0xbd8058d6, 0xbd665d42, 0xbdd0a5e6, 0x3dc9b755, 
    0x3c96360e, 0x3cae540e, 0xbe2b6b95, 0x3e0d9244, 0x3e1af537, 0x3e096b59, 0x3ce7e553, 0xbc9cfb1a, 
    0x3dd00a74, 0xbe43c3f5, 0xbd6a88b7, 0xbdf65d10, 0x3e3db0d2, 0x3e0ac86d, 0x3e54a892, 0x3cf88a9c, 
    0x3e232559, 0xbe1eb608, 0x3dd2bb6e, 0xba12564e, 0xbe2ea9db, 0x3e2bd4df, 0x3e0e4589, 0xbdcbbc73, 
    0xbbc30a9a, 0x3d64fa5a, 0x3e38a142, 0xbbbb153a, 0xbe0a9ee4, 0xbe4f986d, 0xbe90695f, 0xbc892722, 
    0x3e0eda1c, 0x3e183ace, 0x3dfff1e0, 0x3d885dc5, 0x3c86cdce, 0xbd6261cf, 0xbe582115, 0x3e0039ad, 
    0x3db2cbf6, 0xbbe6dcee, 0xbd60ad41, 0xbd9c8288, 0x3e196560, 0xbdd9dc86, 0x3e0e4ca0, 0x3c029034, 
    0x3e226d09, 0xbdb04ee1, 0xbc008e16, 0x3daaaa8e, 0x3d2eecdf, 0x3cc8cb0c, 0x3e4b9e6d, 0xbdb440a1, 
    0x3d1a704f, 0xbe400232, 0xbe25a104, 0xbe52bc51, 0x3d2702a6, 0x3d843d69, 0xbe1e5412, 0x3d11d930, 
    0x3e298b0d, 0x3db03fec, 0xbe27dfcf, 0xbd06404b, 0xbdb5bd40, 0x3defc44a, 0x3d885698, 0xbd5bb9ab, 
    0x3d634a2f, 0x3e356d87, 0x3e8b8f8e, 0x3e084ae1, 0xbbb2b8ab, 0x3e3eba92, 0x3cd0f1da, 0xbdb5fba9, 
    0x3d1c9371, 0x3e21af2b, 0xbe076062, 0xbdebf0c7, 0x3e2b245f, 0x3ba6bc42, 0x3d34f959, 0xbe12f55c, 
    0xbdc05f91, 0xbd7beac7, 0xbddceddc, 0xbe47746f, 0xbd567940, 0xbd029edf, 0xbcbfb2b6, 0x3d3c64dc, 
    0xbe514825, 0xbde9a91e, 0xbdcfdae2, 0xbe34aee2, 0xbe54d3b9, 0x3e20400b, 0x3e96c4a5, 0x3d462817, 
    0x3d0a18b6, 0xbd88a7b0, 0x3c892e42, 0x3db7fb3b, 0x3e38a433, 0x3e10660b, 0x3e072cde, 0x3d0c266b, 
    0xbd065e0a, 0xbe1eafdd, 0x3e2d1594, 0xbe24f839, 0x3e557a47, 0x3de69dd8, 0x3e3a1f42, 0x3dbe2ea9, 
    0xbc6b4248, 0xbd84c892, 0x3e188466, 0x3e735ee9, 0xbd8323c1, 0xbd12160a, 0xbded9934, 0x3ddab9a1, 
    0xbd9d5019, 0x3dd7165d, 0xbe099608, 0xbe631af7, 0xbd2ccfb4, 0x3e32b832, 0x3e5a8232, 0xbe048394, 
    0xbd2f6d10, 0xbc9c4324, 0x3d0fee81, 0xbe0aa852, 0xbc03e797, 0xbd48d232, 0xbe5ced2f, 0x3dbee8f9, 
    0xbe3b7d31, 0xbd367279, 0xbdbbed95, 0x3c147ee2, 0x3e15500e, 0xbd30ce47, 0x3e09077f, 0x3e7af7bb, 
    0x3de9a4d7, 0x3e492bae, 0x3e7013ef, 0x3e0fae30, 0x3d1434da, 0x3d9a15ef, 0x3e3e138a, 0xbe2b911e, 
    0xbe83fa7d, 0xbe01fb85, 0xbdab7283, 0x3dc1078c, 0x3d5de4e7, 0xbdb7334b, 0xbbe03edd, 0xbdc33f37, 
    0x3dfe53e6, 0xbe15beb0, 0x3e108a2a, 0xbd33037b, 0x3d56f818, 0xbe01f454, 0xbe354a1c, 0x3dad4840, 
    0xbe0ad843, 0xbc4888ed, 0x3df799a9, 0x3d2eff29, 0xbe2ae903, 0xbc7bebbc, 0x3cf40d58, 0xbd381ce8, 
    0xbcf90bd7, 0xbe17aaa2, 0x3e40270e, 0x3de39f3b, 0x3db12f8f, 0x3da2216d, 0xbe253daf, 0xbe2cc3ba, 
    0x3e03ea0b, 0x3e51e229, 0x3e90a1b0, 0x3d924950, 0xbe024676, 0x3e4e8c66, 0xbe1ed38b, 0x3e2c671a, 
    0x3af26af2, 0x3da5a38e, 0xbe86d284, 0x3c8bd677, 0x3d10fb89, 0x3df3be0a, 0xbd831660, 0x3d932278, 
    0x3e539f4e, 0x3d94114c, 0x3dcdea97, 0xbd97d49a, 0x3d3cb964, 0x3e87ec89, 0x3d36de20, 0xbc896b0c, 
    0xbde4bddc, 0xbdb388b4, 0x3e249b14, 0xbe2a3012, 0xbe0f91bb, 0xbdba48cf, 0x3b9a8252, 0x3e3ff3bf, 
    0xbcabf4cb, 0x3d9f9b9d, 0xbde4e5ad, 0x3dcc2aa4, 0xbd359ebf, 0xbe04ccf2, 0x3da89c8d, 0xbe62d710, 
    0xbd2f4f89, 0x3e1c045f, 0xbe244015, 0x3d09fa0f, 0xbe65ea8a, 0xbe6a14c2, 0xbd5444ff, 0x3e07ce0d, 
    0x3d3311eb, 0xbe2c0277, 0xbe54d380, 0x3cdae50e, 0x3dee973e, 0x3e2962d2, 0xbd03604d, 0x3d8ce4c1, 
    0x3e168441, 0x3db3f8cc, 0x389e0f19, 0xbdc1b55c, 0x3e4661ac, 0x3e8b4269, 0xbe2918bf, 0xbdaac9aa, 
    0x3ddb14f6, 0xbdf8ea7d, 0xbda87660, 0x3e64fce0, 0xbd75bdd1, 0x3e0e49ef, 0x3e023829, 0xbd384b11, 
    0x3d9460f1, 0xb97fa158, 0x3dc22ef5, 0xbe3ca6de, 0xbc134337, 0xbda8313f, 0xbe3f1a3d, 0xbe44440e, 
    0xbe563ab3, 0x3e16978d, 0xbcf2cc8b, 0xbe02c148, 0x3dec429a, 0x3ccfcff7, 0xbe553742, 0x3c360da7, 
    0x3cfc4c9c, 0x3e14f6ff, 0x3e3ea152, 0x3e93c915, 0x3df3cc43, 0x3e0c5ccf, 0xbc9d246d, 0xbcf743ac, 
    0x3b108c31, 0xbce4861a, 0x3de222ac, 0xbcd44d1c, 0x3d80a25a, 0xbdd98b41, 0x3cc149ff, 0xbe3e5d22, 
    0x3bea30d2, 0xbe09666b, 0xbd2ca383, 0x3e1dc2c7, 0xbdde83ff, 0xbe6582e9, 0xbb8ecd8a, 0x3e7c3bc8, 
    0xbe339ba3, 0x3c5050be, 0x3e48c84a, 0xbd3c1554, 0x3d265d45, 0x3d541f6c, 0xbc83fbf6, 0xbd753c10, 
    0x3e55a01b, 0x3e0c8af2, 0xbe0b2e75, 0x3d3df7d3, 0x3e16168d, 0x3e299d67, 0x3d57b6bf, 0xbd02d3df, 
    0x3d935c90, 0x3d802436, 0xbe2449f7, 0xbdbf1511, 0xbe281b73, 0x3dd86ea3, 0xbda3c512, 0xbe581d1b, 
    0x3c4061e6, 0xbd4ab55d, 0xbdcc48f2, 0x3dba8231, 0x3d9db746, 0x3d11ffe5, 0x3d58b9ed, 0xbe3803b4, 
    0xbe5aeb77, 0xbdef477b, 0xbc081150, 0xbdeea9ad, 0xbda06f1b, 0xbcd69fbc, 0x3d991d1f, 0x3ce81138, 
    0x3eb10760, 0xbdbdb29a, 0xbe4899d0, 0x3d93b0a5, 0xbdc3dc8d, 0xbb55463f, 0xbe30a5b4, 0x3d46413f, 
    0x3da938e0, 0x3d99bae5, 0xbc5cfcf5, 0xbe3ca737, 0xbd36aa1d, 0xbe670d0e, 0xbe6b37f9, 0x3d2a6ca0, 
    0x3e494df4, 0xbe18b763, 0xbe12b6e5, 0xbe247f4c, 0x3d52ec21, 0xbcedf2a6, 0xbe28701b, 0x3defee9c, 
    0xbd5d8898, 0xbe1f2d5e, 0xbd936a29, 0xbdd8100a, 0x3dc1d7e6, 0x3c6c88a8, 0x3e5b33ef, 0x3e1568c1, 
    0x3e289981, 0x3d138a63, 0xbdf5e950, 0x3db227b8, 0x3ba67428, 0xbc95c3aa, 0xbe44d417, 0x3e6c40ff, 
    0xbe374a1a, 0xbe0f503c, 0x3e12ec85, 0xbe3abf7e, 0xbd67fb0a, 0xbd10e6ea, 0x3c1781af, 0x3e0234b7, 
    0xbd4283bc, 0xba1ed0b5, 0xbda6c888, 0xbda845a4, 0x3e002990, 0x3cd4edbc, 0x3dc88797, 0xbe401904, 
    0x3e518c0a, 0xbe1a3653, 0xbdc2976d, 0x3d0a9a2f, 0x3e57a51f, 0x3e3a2e41, 0x3df7b496, 0x3cc53f4d, 
    0x3d70ce10, 0xbe18710b, 0x3e261c10, 0xbdb69b70, 0x3e0c9023, 0x3e031a09, 0x3ca23a12, 0x3dc77afd, 
    0x39a3ed7f, 0x3cb2be5d, 0xbdeb03d9, 0xbe541a2c, 0x3db15db3, 0x3cb10421, 0xbe016027, 0x3cd3b094, 
    0xbd22258b, 0xbd37781c, 0xbd4fd176, 0xbcb8822e, 0xbca1521d, 0xbcace1e7, 0x3e6c4ed3, 0x3d1ae6d0, 
    0x3e1f3ccf, 0x3d833653, 0x3d913ce9, 0xbd185d40, 0xbe2138a7, 0xbb04483a, 0x3dae966b, 0x3e3f7e8e, 
    0x3da7b4d0, 0xbc9e7bbd, 0x3e341856, 0xbce1c828, 0x3e18f6ec, 0xbe229a9a, 0x3da258db, 0x3d2e3859, 
    0x3db1062c, 0x3d2bd29b, 0x3e20e765, 0x3dbd6516, 0x3e074268, 0x3d950c75, 0x3c1d84ec, 0xbd23a5a7, 
    0xbe0adf5c, 0xbddab094, 0xbe246a9c, 0xbdc8c203, 0x3e12dcfb, 0x3d329be0, 0x3c8bbb6d, 0xbe538ac0, 
    0xbe4e8ff4, 0xbdbd8ae5, 0xbe13a46f, 0xbd414f3b, 0x3d349e70, 0x3d90f646, 0xbde380ed, 0x3e633d2c, 
    0x3e29fe62, 0x3d0545d9, 0xbe468c5e, 0xbded48d4, 0xbe020539, 0x3dc94a50, 0x3d22bdca, 0xbe2007d3, 
    0x3c9a0f68, 0x3e11c488, 0x3dae9af4, 0xbe27ba92, 0xbd95a528, 0x3d882baa, 0xbe1ad947, 0xbe65acfd, 
    0x3d50ea23, 0x3e5b503a, 0x3ddff636, 0xbd9497b4, 0xbe5bf633, 0x3e1c3a0d, 0x3cbfdef7, 0xbe301953, 
    0xbdf1250a, 0xbd8b0fe5, 0xbda3e561, 0x3ce4bf64, 0xbd4db359, 0x3dd6291b, 0xbd8a3f38, 0x3ba51adc, 
    0xbe1e5c7c, 0x3e235213, 0x3c8a947b, 0x3e491348, 0xbd1fda78, 0x3cc66d85, 0xbbc7a88c, 0x3d3fbc76, 
    0x3d3aff83, 0xbe492fd6, 0xbe117335, 0xbe50e312, 0xbd9cde07, 0xbdd47794, 0x3e08dbc6, 0x3d383710, 
    0x3e393583, 0x3e691e10, 0x3db106ed, 0x3bbe66d6, 0x3e296f0b, 0xbd676cb8, 0xbe37c57f, 0xbd277bf5, 
    0xbdfd4c37, 0x3d0a2085, 0xbd8740a7, 0x3e27a0bf, 0x3cb6dc51, 0x3e0e3d15, 0x3d811b15, 0x3d52228e, 
    0xbe15b21a, 0xbe29f64c, 0x3e261239, 0xbe090a34, 0x3ca03516, 0xbe1bb815, 0xbe421b93, 0xbe7cc379, 
    0x3d43b61c, 0x3b16beb2, 0xbd047a28, 0x3e4fa087, 0x3e368d17, 0x3e1814a5, 0x3e034b08, 0x3dbc5989, 
    0xbd4d6522, 0xbd6ab47a, 0x3d819ac5, 0xbc972f6e, 0x3b313694, 0xbc97fae2, 0xbd170606, 0xbde011aa, 
    0xbe192e4a, 0xbc5327d8, 0xbdaa1e7d, 0x3e3f2b5f, 0xbe432ff9, 0x3d644c03, 0x3d44ae13, 0xbd34a016, 
    0xbe17d9ff, 0xbc5b4bad, 0x3c3ede2b, 0xbd04e177, 0xbd8fbf5e, 0xbe8fd980, 0x3d1ec959, 0xbe6e774b, 
    0xbd43a66b, 0x3cfe7ef4, 0x3dad0eea, 0xbe18687e, 0x3cfe3da9, 0x3e48eea1, 0x3e83483b, 0x3df7c614, 
    0xbe292e2c, 0xbe3428c1, 0x3db04ed1, 0x3e0dbebc, 0x3e11e860, 0x3dae47ba, 0xbe75f33b, 0x3da42dec, 
    0xbc910395, 0xbd86a1f4, 0xbd8ffb50, 0x3d9a8cdd, 0xbe8786a8, 0xbe7b6895, 0x3d719ccc, 0x3dd8de4b, 
    0xbd0db188, 0x3c4c1959, 0xbda4ac38, 0x3e08e17e, 0x3dc7b494, 0xbd883f43, 0xbe08f902, 0xbd33b4ab, 
    0x3e5157c8, 0xbd40a244, 0x3ced016c, 0xbdb21da7, 0xbe233aa8, 0xbd5ec0bc, 0xbdb3f424, 0x3cea935a, 
    0x3c5faf4e, 0x3e0ba7b5, 0xbe443e2e, 0xbd4692e4, 0xbe67d034, 0x3c0a7702, 0x3e4c1e86, 0x3e17a6a4, 
    0x3d9f8db6, 0xbd85c4f4, 0xbe054630, 0xbd8aba04, 0xbe69d3c4, 0xbdb7931e, 0x3e0ae37e, 0xbdb89f93, 
    0xbe3bda0b, 0x3e43b5db, 0x3cf9a7a4, 0xbddbb0f6, 0x3da45be4, 0xbe875142, 0x3b9d0b58, 0x3ce75f33, 
    0xbd6a8a41, 0x3cda7182, 0x3d05ebe5, 0x3da4f2a7, 0xbe06a1a5, 0xbe0b7917, 0x3e22e9e3, 0x3de59a16, 
    0xbdc6ad36, 0x3db26db4, 0xbe13cf5d, 0xbe4fee87, 0x3d0b47ed, 0xbc4d5971, 0xbdb287a2, 0x3d93757b, 
    0xbe306f0c, 0x3c372dda, 0xbddc8c75, 0x3db79c7a, 0x3e1639d7, 0xbdcc369e, 0x3d77d611, 0xbd19a865, 
    0xbcfbda14, 0xbd791590, 0x3e07436b, 0xbe766ccf, 0x3e2fbf91, 0x3e018b18, 0x3e12f971, 0x3de9e78b, 
    0x3d2e5e04, 0xbe0a7ca8, 0xbe524176, 0x3d0a3eaa, 0x3e088e3d, 0x3e361cbe, 0xbe036ca7, 0xbc4eeb0e, 
    0x3deb2b37, 0x3d7d67ee, 0xbd8c09a9, 0xbdc7390d, 0xbd86bbaf, 0xbd7b8ff8, 0xbb90e57f, 0x3dc30ce4, 
    0x3d85ea12, 0xbe3dce3b, 0xbe2988cd, 0xbe42b786, 0xbbe95df9, 0xbe21aedb, 0x3dce3a3d, 0xbd4ae826, 
    0xbc8902f8, 0x3e22ed68, 0x3c4ca540, 0x3d742440, 0x3e9daa19, 0x3e09ede1, 0x3e2a9a3d, 0x3d87eba5, 
    0x3e346955, 0xbca1f1ca, 0x3d7956d7, 0xbd3fcdec, 0xbceb9893, 0xbc6d18cd, 0xbda23817, 0x3c2ebafc, 
    0xbe1c8665, 0xbe3f8b95, 0xbdcb7a50, 0x3e3ae507, 0x3e30a776, 0x3e7a5ece, 0x3d888b9c, 0x3e2a619a, 
    0xbe28e41a, 0xbe30d28d, 0xbe36051e, 0x3d83b3c5, 0xbe5b4dc1, 0xbdef70d9, 0xbe289e67, 0x3ddc3ac0, 
    0xbe336867, 0x3c2187fc, 0x3e80fc83, 0x3e321324, 0xbd9dc4e1, 0xbe305442, 0x3e0bb7dd, 0xbdbb938c, 
    0x3db186fb, 0x3e3bd6e6, 0x3e09b3a5, 0x3d3bc536, 0xbe2b1a69, 0xbd367946, 0xbc80a9e4, 0xbe158e25, 
    0x3e0c4b35, 0xbd230d84, 0xbe447c11, 0x3db532a7, 0x3e28b9ac, 0x3e384323, 0x3e00b36b, 0x3e087cf9, 
    0x3df75494, 0xbb8ff79f, 0x3d160da5, 0xbe06eafd, 0xbd4fa1b5, 0x3e156b15, 0x3df62dd5, 0xbdae7cb4, 
    0x3d96ba6e, 0x3e39888d, 0xbc58d2e1, 0x3e0435b7, 0x3cef8054, 0xbd61b88e, 0xbcee8f75, 0xbe0f69a3, 
    0x3e15c7bd, 0x3b44447c, 0x3cc7a13d, 0x3c0acd5b, 0xbd46ff37, 0xbdafc714, 0x3e451ed2, 0xbdb8c488, 
    0xbc58bb71, 0xbc1c1ea2, 0xbe0944a5, 0xbcc505b6, 0xbded5f5b, 0x3dec58fe, 0xbe1c5364, 0x3d87b348, 
    0x3e0ac51e, 0xbdd3ac04, 0xbd149e2b, 0xbdf5315a, 0xbcbcf90c, 0xbc973ba8, 0x3d675e78, 0x3dbb16fb, 
    0xbe8668da, 0x3e014326, 0x3e60e8a3, 0x3dcbb70c, 0x3c83493d, 0xbd8222b6, 0xbe1b2b22, 0x3d3003e1, 
    0x3dbdd378, 0xbe0e44dc, 0xbca06ee3, 0xbe191f36, 0xbe274105, 0x3d19014a, 0xbd216bbd, 0xbe48f604, 
    0x3cb177b1, 0xbe11e32c, 0xbe2f80a5, 0x3e8063ab, 0xbcaee032, 0x3e3b742a, 0xbe29f089, 0xbda19b4f, 
    0xbc5c3cb0, 0xbde1494b, 0x3dca36cb, 0xbd9098e3, 0xbd3e6c62, 0x3e55831c, 0xbe16b6a6, 0x3d7520cb, 
    0x3d6c25ee, 0xbe101122, 0x3c4b1487, 0xbce67d61, 0x3df82797, 0x3e06c716, 0xbcbf6dc8, 0x3d35d0d5, 
    0x3dfd43fd, 0x3d93a2b0, 0x3ce848d1, 0xbe1d0f78, 0xbc537171, 0xbe436eec, 0xbdb4ae8a, 0x3dc1b6a4, 
    0x3e01b4bc, 0x3d660bfd, 0x3cb021f7, 0x3e1192b1, 0xbe2f9b51, 0x3d407fcb, 0xbe8450a8, 0x3b3a210e, 
    0x3e40b261, 0x3ce1d79c, 0xbc3edbae, 0x3d06c856, 0xbe84bc66, 0xbe35abdc, 0x3c8425b8, 0xffff92a6, 
    0x00000004, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0xffff92f2, 0x00000004, 0x00000c00, 0xbccdca5d, 0xbdd1afb0, 0x3e0951a6, 
    0x3db18544, 0x3e1aa8db, 0xbdaac8fc, 0xbd3b1677, 0xbdccd0e9, 0xbd635288, 0x3cffeede, 0xbe0f1544, 
    0xbe1ad68f, 0x3d7d0caf, 0x3dde4b57, 0x3d61595e, 0x3da6e050, 0x3c88c9e0, 0x3e4a37b0, 0x3e1ea4ff, 
    0x3e085f47, 0x3d72b447, 0xbe703bd7, 0x3e3e7d54, 0x3e1f2a50, 0x3e421d27, 0x3e431868, 0x3d8ad129, 
    0x3e348a99, 0xbe76d19e, 0x3e330b23, 0xbda4e45e, 0x3e83e008, 0x3d8c221d, 0x3d1e06b1, 0xbe7e8bcb, 
    0x3c84b201, 0xbe613834, 0xbe1928a7, 0xbd9e3cbf, 0xbdaf214a, 0x3e5bf8b6, 0x3bcbfef8, 0x3da706f7, 
    0xbd8ab53b, 0xbe3ac07c, 0xbe52d659, 0x3e2bd85f, 0x3dc6f34e, 0x3b7bf39a, 0x3cba7080, 0xbe0ac772, 
    0xbe3186df, 0xbc28a6c0, 0x3d241da3, 0x3e48ba49, 0xbd37931c, 0xbd38be2f, 0xbdcd4534, 0xbdff31d2, 
    0x3e1e3a8f, 0x3d187bfa, 0x3d91cf4a, 0xbe597ebb, 0xbe8ac7a1, 0xbe2ed605, 0xbd9b8e9f, 0x3e9865b1, 
    0xbe41d568, 0x3e5f20e4, 0xbe603aa7, 0xbd82b31d, 0xbe8552d9, 0xbe5409ae, 0x3d04d4ad, 0x3de6ea37, 
    0xbe1ef3ad, 0x3de58e52, 0xbe5588b6, 0xbe10976c, 0xbdde3df4, 0xbe09bf49, 0xbd39e8cd, 0x3e399e78, 
    0x3e2bb60f, 0xbd474b2b, 0xbe65a516, 0xbe728f18, 0x3d8fab1e, 0x3d32e3a4, 0xbdfd26df, 0x3d9ee285, 
    0x3dce8a73, 0x3dc47f98, 0xbd8803fe, 0x3c046b7c, 0xbe55c13a, 0xbe361847, 0x3d4d6c9f, 0xba9f4987, 
    0xbe504088, 0x3e81dd19, 0xbdcccfd3, 0x3d0a0db9, 0xbde84b91, 0xbd7605a9, 0x3b1728cd, 0x3e456232, 
    0xbd9fe771, 0x3e8ed2b3, 0x3e13fb6a, 0xbe599c91, 0x3d8a5997, 0xbe530a3b, 0x3d049f65, 0x3e24be97, 
    0xbe3101c8, 0xbd825aca, 0xbe63e9b3, 0xbd934766, 0x3de5c694, 0x3d396703, 0x3df06d7c, 0x3dc73f89, 
    0xbe18fbd8, 0xbe09656a, 0xbd1079f9, 0xbeaa6da9, 0xbd1840e8, 0xbe070d2d, 0xbe213cf4, 0xbe4d851b, 
    0x3c01e24e, 0xbcdb6f03, 0xbcef0629, 0x3e3588ff, 0xbdf04555, 0x3e641503, 0xbacd1c5a, 0xbcc8ad51, 
    0xbd456d22, 0xbe37139c, 0xbca91f13, 0xbe970be9, 0xbd896d3f, 0x3e94ae03, 0x3e0e4198, 0x3de14499, 
    0x3e4fe525, 0xbd0df22e, 0xbd558318, 0xbbdf07af, 0x3d33f19e, 0x3dcabae8, 0x3d9cb050, 0xbdc994a5, 
    0xbcbdfbea, 0xbe69d78f, 0x3e80d89e, 0x3d955af1, 0xbd46d013, 0xbd9d2bee, 0xbe465a11, 0x3e460f84, 
    0xbddcc8ea, 0xbe2caf4a, 0x3e2fba4f, 0xbd931a9c, 0x3e40c3f3, 0xbe67ed8e, 0x3dedd508, 0xbc9f78ab, 
    0x3ca91054, 0xbdada136, 0x3e673967, 0x3e9d5296, 0x3e6d9a35, 0x3e93e9a8, 0xbe1ca822, 0xbd0325da, 
    0x3e2e6cf5, 0x3e2f46e9, 0x3bd9f658, 0xbdad0d60, 0xbe199def, 0x3da56c6e, 0xbc4bee60, 0xbcfbcfc4, 
    0xbdefe5dc, 0x3d234645, 0x3d26292e, 0x3d39b7ef, 0xbdf36572, 0xbcb130ef, 0x3dd05912, 0xbcff3a19, 
    0x3bc5ad66, 0xbcbcd6ae, 0xbcef8467, 0x3e6caf92, 0xbe250fa7, 0xbe033f21, 0xbe98f5c7, 0xbe4f4ada, 
    0x3da451f2, 0xbe6a042e, 0x3c05bc20, 0xbc714d28, 0xbe41f428, 0x3cef0e84, 0xbde8da6a, 0x3e136beb, 
    0xbb4764e6, 0x3dec6226, 0x3dc66e3d, 0xbe2a309d, 0x3d91abdd, 0xbe1a0e78, 0x3dac01cc, 0x3e2b4061, 
    0x3dbe2e39, 0xbdd3b244, 0xbe0aa4af, 0x3dbb7768, 0xbd4287a4, 0x3df53ddd, 0xbe85625c, 0xbe351cdf, 
    0xbe697d7e, 0xbe5ab335, 0x3e2ffb08, 0x3e7cdae3, 0x3b689a97, 0x3e3245ea, 0x3cf3a08e, 0x3cc651e2, 
    0xbd8e1a5b, 0x3d4c412a, 0xbab1f806, 0x3e83230d, 0xbea37652, 0xbdad96e9, 0xbe20f999, 0xbddc7718, 
    0x3e0ef9df, 0xbe97b8cd, 0x3dc5dd8c, 0xbc578943, 0xbe4a2c8a, 0xbd671e44, 0xbe8c4f81, 0xbe2c353d, 
    0xbbd3c597, 0x3e60c7ac, 0xbdd0852d, 0x3b46362c, 0xbe69cc4f, 0x3e2f3b24, 0xbde7ca75, 0xbe0ceafe, 
    0xbe7d1429, 0x3dccf197, 0x3e459ce5, 0x3ea6391c, 0xbdb8c87f, 0xbcd6a71c, 0x3e6e3b96, 0xbcf91795, 
    0xbe21bcaa, 0x3d8d9a9a, 0x3c748131, 0xbd1bb753, 0xbe279132, 0x3e17b384, 0xbd9b35fc, 0xbcf248a2, 
    0x3d933b15, 0xbe9bc0e1, 0xbdabb69c, 0xbca939e5, 0x3d3337cd, 0x3e122d96, 0x3db45bbb, 0xbd496eb6, 
    0xbc664b89, 0x3e4a2c8b, 0xbe4eb6bb, 0xbc63e44d, 0xbe8d4fe0, 0xbdcafe83, 0x3e3da529, 0x3d5bf433, 
    0xbd975c43, 0x3dfcca72, 0x3cebd451, 0xbe6653eb, 0xbe447fb3, 0xbd01f85c, 0x3e4a84ce, 0x3e0ad878, 
    0xbcceba8b, 0xbe247511, 0x3df1c434, 0xbe9c91a8, 0xbdebcecd, 0x3c430492, 0xbe0292e5, 0xbe81f3a6, 
    0xbcbfaec9, 0x3d6df164, 0x3e113bc4, 0xbe57f07c, 0x3e0c6d0f, 0x3e5317c9, 0x3e59f70b, 0xbe61bfc9, 
    0x3de882c1, 0xbe9f8366, 0xbe6a46dd, 0xbe536ca6, 0x3e175304, 0x3ce3feba, 0xbdf99ddc, 0xbc1f9797, 
    0x3b3be5da, 0x3d10d7be, 0x3ab632e0, 0xbc696ef7, 0x3e2d3e27, 0x3e3824ea, 0x3d1ca2ce, 0x3c3ff29e, 
    0x3d7a6307, 0x3e3bec8f, 0xbd8efee8, 0xbe62cf0f, 0x3d4793b3, 0xbe156e0c, 0x3e212986, 0xbe89d37a, 
    0x3dd4cfb4, 0xbe7c310a, 0x3e03c736, 0x3e0012b3, 0xbe66428b, 0xbe60f2e0, 0x3d94b026, 0xbd1cc912, 
    0xbe28d4b8, 0x3d9c7965, 0xbc3a7841, 0xbe0dfb66, 0xbdd1a86b, 0x3df76be9, 0x3e93aa06, 0x3e691d26, 
    0x3dba8db0, 0x3e2563b7, 0xbd227a8a, 0xbe1ace0a, 0x3d0f55bd, 0xbe4be25a, 0x3ccb9df6, 0xbe8a887f, 
    0x3d8c74f8, 0x3d4b1996, 0xbe463fd7, 0xbd0e735c, 0xbe963a6f, 0x3dae2bf7, 0x3e9ebf60, 0xbdd301db, 
    0xbd876e04, 0xbe5fd3c8, 0xbe22b56b, 0x3e130fa4, 0xbe2ea7e0, 0x3e24eeba, 0x3e156540, 0xbda3dd98, 
    0xbe3848d7, 0xbd89940a, 0xbd649ae5, 0xbdbf2ff0, 0xbcd7ce5d, 0xbe06f381, 0x3e2f6fad, 0x3e899b5f, 
    0xbd5cb36b, 0x3ddd6d09, 0x3dff387d, 0xbe2762a9, 0xbd45e6da, 0xbd468884, 0xbd25228c, 0x3daefe69, 
    0x3e0c5db4, 0x3e5d8778, 0xbe31840e, 0x3db67a64, 0x3d3712ec, 0xbe0164ab, 0x3b82cf8d, 0x3c00be00, 
    0xbc6a1df4, 0xbcbc3747, 0x3e3f9bb9, 0xbd4ba061, 0x3e4c5df3, 0xbd613708, 0x3e18ed15, 0xbe1453f9, 
    0x3ce34771, 0x3e84c8c6, 0x3dde01e8, 0xbe33d719, 0xbd51dfcd, 0x3cf0026b, 0x3e063ee9, 0x3c6cac2b, 
    0xbe4a963c, 0x3ceb1a92, 0xbe3eaeb9, 0x3df459d1, 0x3e08b6be, 0xbe12a80f, 0xbca8a1fc, 0xbd6dcd25, 
    0xbc830d3d, 0x3e35a8c0, 0x3e4a7c72, 0x3e3ddee8, 0x3e16cb32, 0x3e6664bc, 0x3e33eaff, 0xbe6e4f43, 
    0xbdd32c75, 0xbe2d9acd, 0xbe32bd83, 0xbe01885b, 0xbd9ffe68, 0xbe7245c8, 0xbce8563f, 0x3d1837f1, 
    0xbe7515ad, 0x3db02309, 0x3d29572d, 0xbde3f639, 0xbe11b61a, 0x3e41a027, 0xbcfe83fb, 0x3e63ff70, 
    0xbdd78f8c, 0x3dbf06fa, 0xbd909663, 0xbdc40b1f, 0x3e138061, 0x3e37721b, 0x3e2c596d, 0xbd572359, 
    0x3e685251, 0x3bcb5793, 0xbe1cb6ae, 0xbe0173ca, 0x3e6136eb, 0x3d111857, 0xbdd3e072, 0xbda7d7bd, 
    0x3e98438f, 0xbce5bc56, 0x3d8555c3, 0x3e570593, 0x3c950532, 0x3d07e20b, 0x3e7b0cc4, 0xbd3a27de, 
    0x3d42e161, 0xbd3de24f, 0xbe07dcd8, 0xbdb623a2, 0xbe7fbc46, 0xbf00e67d, 0xbdcdab4d, 0xbad804e7, 
    0x3e085e56, 0x3c379b86, 0xbe56c506, 0x3d73292d, 0xbe403d2a, 0xbde4709f, 0xbc999f50, 0x3e33c410, 
    0xbb1fef27, 0xbe0cf965, 0x3e8d1fbe, 0x3e86d98d, 0x3d96ecac, 0xbe528b72, 0x3e530645, 0x3d5802d4, 
    0x3e4caf43, 0x3d80a27a, 0xbe374ab8, 0xbe9cd11f, 0xbe1cd7bd, 0xbdd49390, 0xbdb89871, 0x3d193393, 
    0xbdc8c80f, 0x3e53717d, 0xbd0b7046, 0x3d271836, 0xbd8af94d, 0xbec75d24, 0x3d1d3868, 0xbe392bab, 
    0xbe34b016, 0xbd0f5d0c, 0xbcc6dcae, 0xbe428fc6, 0x3df633e7, 0x3cbb30da, 0x3dbb9946, 0x3e3300f4, 
    0x3e3d37f7, 0x3dc570fe, 0xbe3b06e4, 0xbe046b24, 0x3e3d6881, 0xbdd0c9c5, 0xbd8b866c, 0x3e67b990, 
    0x3dd03550, 0xbe3c2ab9, 0x3e79a4fb, 0xbdd5d68e, 0xbd486262, 0xbcc7e955, 0xbd968bcc, 0x3e1485ad, 
    0xbcab09dd, 0xbdd4e5ef, 0xbe4029a4, 0x3e7ac000, 0x3ddc758c, 0xbd4b8e1e, 0xbe3aa284, 0x3c916f98, 
    0x3db3a720, 0xbd999199, 0xbe1c578d, 0x3dc00e9e, 0x3dc0119f, 0x3d5e12f5, 0xbda9f2f1, 0xbe23143b, 
    0x3dada6b3, 0x3d9bedab, 0xbdbecea3, 0x3e17275f, 0xbd123d0a, 0xbe03ed1d, 0xbd1e9cc4, 0x3c9db2be, 
    0x3dbe41cd, 0xbe0ee220, 0x3dbec49f, 0x3dd382bf, 0x3ced263d, 0xbe252ab0, 0x3e0a5466, 0xbdae343c, 
    0xbd857c6a, 0x3e860ced, 0x3ced5ef8, 0x3e7f44c8, 0xbe2deb2b, 0x3e2643c6, 0xbe88d871, 0xbc01ae69, 
    0xbd826241, 0xbc811264, 0xbe20330d, 0x3e7b0063, 0x3e2f2156, 0x3e251e42, 0xbd1ed5bb, 0xbea4d4d3, 
    0xbdea1883, 0x3d02f6a6, 0x3dfd63fd, 0x3e2301e6, 0x3d9c132a, 0x3e00df00, 0xbe15f698, 0xbc165f78, 
    0x3e017526, 0xbe065142, 0xbe6bba9c, 0x3db0976c, 0xbdf878eb, 0x3e451e79, 0x3c896f71, 0x3dbd86fc, 
    0x3e05de49, 0x3de52a1f, 0xbc14b721, 0x3d4246f1, 0xbc82f911, 0x3dd22193, 0xbe0d2ebc, 0x3e1f393b, 
    0x3e06ff46, 0xbdd46d0e, 0xbb3776f3, 0x3e102764, 0x3e996694, 0x3dd8a792, 0x3df033d8, 0xbe9bc531, 
    0x3c553182, 0x3cc9977d, 0xbd835319, 0x3e512a36, 0xbe416233, 0x3d6e1ba3, 0xbcc2d599, 0xbab74228, 
    0x3d9fcf29, 0x3e661d1e, 0xbb40273e, 0x3cd944b1, 0x3db53813, 0x3d1f3f4b, 0xbc9b8f56, 0xbe08cf34, 
    0xbe9583b4, 0xbe01d4cf, 0x3d9104fc, 0xbe07de39, 0x3d1b6bfe, 0xbd88a8d4, 0xbd233477, 0xbdefc9fb, 
    0x3d0418f8, 0x3e49ab6b, 0xbd6a9917, 0xbe330f3e, 0x3d276391, 0xbe764f9a, 0x3de95c3a, 0x3e464e1f, 
    0xbdde0edb, 0x3e297e88, 0x3e72b144, 0x3e609a27, 0xbdd042ca, 0xbda9ffb6, 0xbe659acb, 0x3e216ece, 
    0xbd962b05, 0xbe1f9063, 0xbe201f27, 0xbe21a3e0, 0x3e192bfb, 0xbdd674f0, 0xbe081ff2, 0x3db1d4d4, 
    0xbe670175, 0x3e9739ca, 0xbe4129d3, 0x3e1c2eee, 0xbdbff579, 0x3da3f6f3, 0xbd094eeb, 0x3da0d548, 
    0xbe19bb6c, 0xbd75d47d, 0x3e0096a5, 0x3d22b625, 0xbca5b351, 0xbda79528, 0x3e1ef45e, 0x3dc38265, 
    0x3df3201c, 0x3dc52029, 0xbe30bffa, 0xbe57fc32, 0x3e0795ae, 0x3d2f7df6, 0x3daa0afb, 0x3c69379e, 
    0x3e188da9, 0x3e61ee56, 0x3dcb8991, 0x3e8163bc, 0xbc16636c, 0xbe1b2e11, 0xbbf9f176, 0xbe2fd5a0, 
    0x3e29bb22, 0x3d9257d3, 0xbda29e8c, 0x3e07a5e1, 0xbda41de4, 0xbd3507a5, 0xbddc0e3a, 0xbdc7d3d5, 
    0xbe374cad, 0x3df51c2c, 0x3d6a1083, 0x3e89c72a, 0xbe18b29b, 0xbe082428, 0xbd861276, 0x3d96c11c, 
    0xbcac67e1, 0xbda1a369, 0xbe6e076f, 0xbe1d22eb, 0xbe0d0334, 0x3e2e464a, 0x3da03690, 0xbe13b37f, 
    0xbe3878c3, 0x3e6a201c, 0x3e1de890, 0xbe26aeaf, 0x3e75cb91, 0xbc1163d9, 0xbd454fa5, 0x3dc5d10e, 
    0xbdfbb62a, 0x3ea24037, 0xbe50ee93, 0xbb00d8f6, 0x3af8c242, 0xbd22a258, 0xbe432ef4, 0xbd1a64e8, 
    0xbd83b8ad, 0xbe21a826, 0x3e5e6ec8, 0x3c8f5123, 0xbd89b9ed, 0xbe271640, 0xbc32a434, 0xbe578e32, 
    0xbdb6a301, 0xbe1400a7, 0x3e4010f3, 0xbd602eba, 0xbe081fc6, 0x3e120cee, 0xbe1607a5, 0x3c4c6789, 
    0x3e28fdf4, 0x3dfebc6a, 0xbb08bf2d, 0x3c045b1f, 0xbe2809c9, 0xbe4960ad, 0xbd01a1e7, 0xbe933951, 
    0x3cc565c0, 0x3e446725, 0xbdd56303, 0x3d8819e6, 0xbcd4d491, 0xffff9efe, 0x00000004, 0x00000080, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0xffff9f8a, 0x00000004, 0x00001800, 0x3e26e51f, 0x3d8f689d, 0xbdc62215, 0xbe111761, 0xbe0d1dcd, 
    0xbd556699, 0x3e340d76, 0xbc96e761, 0x3d9bee44, 0xbde6c6ea, 0x3deaf7c6, 0xbd0743fd, 0x3d82a6e1, 
    0xbe18eab8, 0xbe168598, 0xbdc86d54, 0xbd99f679, 0xbd2c7b50, 0x3ce28524, 0xbd762d79, 0x3de50f78, 
    0x3bdcff9b, 0x3bacbf36, 0xbd3a3b12, 0x3e3c6580, 0xbe8f170c, 0xbd9bbf25, 0xbd7a20a5, 0xbdf4fd49, 
    0x3dbb2564, 0xbbc8f674, 0x3d797380, 0x3e20b945, 0xbbaabeba, 0xbdfeb8a6, 0x3d6ca6fa, 0x3dea5e7c, 
    0xbe18fade, 0x3e7a9b21, 0x3dc31a04, 0xba5577b6, 0xbe19eea7, 0x3de7edfe, 0x3defe17c, 0x3dc55bac, 
    0x3dad93d4, 0x3e287802, 0xbda6557f, 0xbc033717, 0x3e0a592c, 0xbdb9087e, 0xbc12e00e, 0x3dd0bc0a, 
    0xbe025414, 0xbc0967fd, 0xbe042e63, 0x3db78162, 0x3dfa19fb, 0xbe84b4a2, 0xbe4cfe8b, 0x3dead7bd, 
    0x3c761769, 0xbdbc1873, 0xbdc3cb2c, 0x3e58fcfd, 0xbe5037e7, 0x3de73c74, 0x3e515bba, 0x3df87d9b, 
    0xbdacb0af, 0xbe1fe518, 0x3defb4de, 0x3de7a893, 0xbe1d06b2, 0xbe805108, 0x3e0c8a20, 0xbdaec0c1, 
    0x3e71759b, 0xbe116d48, 0x3dcb4ad4, 0x3de1b74f, 0xbe2ea58b, 0x3deb4bfe, 0x3dcc75de, 0x3d5f5d5b, 
    0x3dad655e, 0x3e0bb1b4, 0x3dda99fc, 0xbdea5c89, 0xbd79150b, 0xbc724f54, 0xbde02313, 0xbc36f598, 
    0xbd2096f1, 0xbd818120, 0xbbb1fda5, 0x3ddf8cb4, 0xbe1a8211, 0x3ce6eb6f, 0xbe2e8aa6, 0xbe59181e, 
    0x3e04ce3d, 0x3d6cb88e, 0x3d74bf85, 0x3e1fbe18, 0xbe2fed5e, 0xbdf26ecb, 0x3cf71c1c, 0xbd4c88e2, 
    0x3e67db9b, 0xbe29261d, 0xbdb98f14, 0x3c341f5a, 0xbe153ceb, 0x3d016a33, 0x3ddb8b7f, 0xbdb4cb8c, 
    0x3e12400c, 0xbd2c1bd1, 0x3a9d2cc9, 0x3e4f6a98, 0xbe2bea2d, 0x3ce60f6d, 0xbda9738b, 0x3d8ba3eb, 
    0x3e258790, 0x3d24ad71, 0x3d803d18, 0x3df281a1, 0xbd26e7b6, 0x3dcc0d9c, 0xbd8ad242, 0xbe3e4ed7, 
    0x3e033f91, 0x3d6a194b, 0x3e183940, 0x3e283af5, 0x3dac445d, 0x3deebc35, 0xbbae75ba, 0xbe06da73, 
    0x3d219177, 0x3dd64587, 0xbb0d5abe, 0x3c92a53d, 0x3d87084a, 0x3d9d1f34, 0xbc583926, 0xbe0e9977, 
    0xbdffd35a, 0x3ddb9815, 0x3dcfc064, 0x3e4bd6e3, 0x3e0a2b1a, 0x3c2678e8, 0x3de5b8b9, 0xbd3829d2, 
    0x3de470bf, 0x3e4ae95b, 0x3cd15290, 0xbd92a590, 0x3e18eb63, 0x3dce09b8, 0xbca4c3a0, 0xbcbed557, 
    0xbd879679, 0x3cdb7b8a, 0x3d98e4cf, 0xbde953a7, 0xbb854120, 0x3d3bf203, 0xbd261012, 0xbdf04347, 
    0xbd2f6d5b, 0x3bb65cae, 0x3e3e11b7, 0x3e41ef1b, 0xbda111d2, 0xbcec87c0, 0xbdf3c4c5, 0x3e035b30, 
    0xbc805a32, 0xbda5e6c5, 0xbe5b597b, 0xb9dc4e30, 0xbe0178f3, 0xbe07d514, 0x3dd7c9b6, 0xbe5cdddd, 
    0xbc7655f4, 0x3def6cd7, 0x3d9378de, 0xbe3f309d, 0x3d73e45a, 0xbdb928a6, 0xbd20bd4b, 0x3e1bd484, 
    0x3b9eace4, 0x3dfbf068, 0x3e49a118, 0x3d28a928, 0x3d0d99f3, 0x3d180b35, 0x3dfa66d2, 0xbd79eb3f, 
    0x3e2d8d4f, 0xbdec8726, 0xbe8632ff, 0xbe78bdca, 0x3dac2e24, 0xbcc5cc5b, 0x3e16db98, 0xbe38d46b, 
    0xbd29d9fb, 0x3d8b2a30, 0xbe03692a, 0xbd4db711, 0x3d3da9b6, 0x3e1fb939, 0x3e0434a1, 0x3d1bcbc0, 
    0xbe242215, 0xbe2b2dd7, 0x3948be77, 0xbd0067b6, 0x3c0464f1, 0x3d278a85, 0x3dba8dbb, 0x3e0778d8, 
    0xbe05269f, 0xbd2404e3, 0x3e4cd22f, 0x3da00249, 0xbe5783e5, 0xbd6e8949, 0x3df79761, 0xbcad12cb, 
    0xbbcd2391, 0x3d965148, 0xbe87708d, 0x3c1b280c, 0x3e1a0b20, 0xbda8e38e, 0x3e0da5ee, 0x3db39f0f, 
    0x3e1568ea, 0x3e21f449, 0x3dc5125c, 0xbc2479d1, 0xbd9a0f9a, 0xbe37d827, 0xbe36102a, 0x3d90ccfa, 
    0xbcbeb5d1, 0x3dfdb05c, 0xbce6d7dd, 0x3cd4b19a, 0xbe3589fe, 0xbe24eafc, 0x3e172ae5, 0x3d3e47ec, 
    0x3de3e0fb, 0xbc832da9, 0x3e37dea4, 0x3e0ecaf7, 0x3e2328e3, 0xbe4bb4df, 0xbcc3cc64, 0x3d563d3e, 
    0xbdf2825f, 0x3e09f0c8, 0xbe01a475, 0xbda99b03, 0xbd3b5bde, 0xbda6c947, 0x3d8c992a, 0xbc8f0fc0, 
    0xbdc5b470, 0x3e422c81, 0x3d198bab, 0xbe457c98, 0x3e2ad65a, 0x3dbf1859, 0x3b9e393d, 0x3dcb56bb, 
    0x3c3de022, 0xbdb0ce1a, 0x3defc6e1, 0x3e0805bb, 0xbd4c2a0c, 0x3d3c382e, 0xbdd4c88a, 0x3d5af7ce, 
    0xbde3efee, 0x3e499e07, 0xbdc1cfc3, 0x3da0d762, 0xbc575d5b, 0x3d9d89dd, 0x3d6f7035, 0xbd5a3863, 
    0x3d8d1945, 0x3e1c3bc9, 0x3e1d1720, 0xbe01cd85, 0x3d2171a5, 0xbc55e15d, 0xbda2736e, 0x3e2d1d7b, 
    0x3e489db3, 0x3c5440cf, 0xbbc3bd2c, 0x3e60b968, 0xbdb003ae, 0xbe32e42a, 0x3e2639ee, 0xbe0be884, 
    0x3968d3de, 0x3ddead4d, 0xbdb66ee0, 0x3d9fe106, 0xbdf9d255, 0xbdeb5fcd, 0x3d16c73c, 0x3cc39dcf, 
    0xbd6f13a3, 0xbc29e6a3, 0xbd3514d6, 0x3e257b15, 0x3df665e2, 0xbd301228, 0xbdf29f56, 0x3d18aeda, 
    0xbd26c098, 0x3db7339c, 0xbdc0788f, 0xbdefa342, 0xbdbd0912, 0x39dd933f, 0xbdf5c0a3, 0x3d59cbd3, 
    0xbc98b60f, 0x3d0727f8, 0x3e2852dd, 0x3dc37d4b, 0xbe129d92, 0x3b720671, 0xbd02c6b9, 0xbdac28ec, 
    0x3e6642d9, 0x3e4bb91a, 0xbe1d9ec5, 0xbdf9a0dc, 0x3d48086b, 0xbd7dc16d, 0x3d9a19c3, 0xbd86b042, 
    0x3c8990b1, 0x3e3cf716, 0x3d22c4fa, 0x3be3db11, 0x3daf9274, 0x3d7c281f, 0xbd34c074, 0xbdd725a7, 
    0x3d754374, 0xbdf44ae0, 0xbde92320, 0xbdc9333f, 0xbdba8bb1, 0x3cedd150, 0xbe472ed5, 0x3dc23caf, 
    0x3d854116, 0x3e3f7b08, 0xbe3c3657, 0x3e515eda, 0x3da1e736, 0x3b9d0080, 0x3e57659d, 0x3e11ca01, 
    0xbc2ccd90, 0x3e2d920a, 0x3e0388d9, 0x3c2221be, 0xbe0fc869, 0xbca09997, 0x3d224569, 0x3ce3d35a, 
    0xbce051c8, 0x3e301e78, 0xbd94d80e, 0x3d8beab1, 0xbd295066, 0x3a59c8b2, 0x3d1f4c70, 0x3dd164a7, 
    0xbdcdb8f2, 0x3d7dc240, 0x3db64ed4, 0x3e22eb01, 0xbcfe0c47, 0xbe29ed52, 0xbc7331e5, 0x3e164bd3, 
    0x3dcc7f2a, 0xbe21bc98, 0x3d1591a0, 0x3e0249f7, 0xbdd7b3f3, 0x3de49eab, 0xbd52afd2, 0xbd182dd0, 
    0x3e8860f0, 0xbe293e1a, 0xbe1d610b, 0xbe116e74, 0xbd90dabb, 0x3e1a4da7, 0x3dd96dab, 0x3e2a6f6f, 
    0xbe7a3b50, 0x3bcf7ebf, 0xbdbed322, 0x3d3dc5c0, 0xbe9e2dc7, 0xbdf2a608, 0xbe02998d, 0x3d7a2d20, 
    0x3e326917, 0xbe23098d, 0x3d989710, 0xbd7d2e9a, 0xbe8a7a30, 0xbc7dbaa2, 0xbd1ffbda, 0xbd8664ab, 
    0xbcb6b8b3, 0x3cc0d858, 0xbd694ae9, 0x3df79779, 0xbd9ab41d, 0x3c5bb344, 0xbdf03982, 0xbd984aa5, 
    0xbb82b8a8, 0x3d5fdea8, 0xbe6e084b, 0xbcca4d41, 0xbdaf3e72, 0x3e632be2, 0xbdc8644e, 0x3e30ec7b, 
    0x3cbd9e06, 0xbdae11e5, 0x3e0e7657, 0x3e219c0e, 0x3e017d9b, 0xbe2a24a6, 0xbd6e8f7f, 0xbdca2905, 
    0xbd87ef99, 0x3d3587c1, 0xbdd0c390, 0x3e1ba3e8, 0xbe973812, 0xbcf27efa, 0xbd696a9a, 0xbc16f824, 
    0x3d8c398a, 0xbe585ed2, 0x3e0142eb, 0x3e0d23d1, 0x3d64d9c2, 0xbe08c326, 0xbe4654f0, 0xbe17f8a8, 
    0xbd5ca1be, 0x3cf7ad38, 0xbb4f5b02, 0x3d9529a6, 0x3e6b9af3, 0xbdc26228, 0xbd85caa4, 0xbc328041, 
    0x3dd7cafc, 0xbd94d480, 0x3e1c13b5, 0xbe42e06b, 0xbde198db, 0xbdb9cca9, 0x3e37d100, 0xbcedd6b3, 
    0xbdee5f9f, 0x3e07ecbf, 0x3dd05ec8, 0xbddd6e3b, 0x3e67f801, 0x3e02d351, 0x3cafd295, 0x3d472a98, 
    0xbe0066c3, 0xbcc268e9, 0x3cd8321a, 0x3e107ccc, 0xbe0f03b3, 0x3ddc33aa, 0x3cb7c9dd, 0xbe7a3380, 
    0xbe67322a, 0x3e4ec5bd, 0xbe0e8575, 0xbde31999, 0x3e1620ef, 0xbd92af55, 0xbde72c32, 0x3e230ede, 
    0xbdc2b469, 0xbd07816c, 0x3d9008d6, 0xbce86c48, 0xbc0e9ffc, 0xbd65c3b3, 0x3e091a93, 0xbdf73a0d, 
    0xbe1ebc49, 0x3d3bed28, 0x3de06039, 0x3e382168, 0x3e53f3a0, 0xbbd2ce23, 0x3df79ea3, 0x3dd184eb, 
    0x3e94cea1, 0xbd5b7d92, 0xbd6b39e1, 0x3dcb82cb, 0x3de4e166, 0x3d996a5f, 0xbddbb2db, 0xbe1ab979, 
    0x3d966ec1, 0x3dcb94c1, 0xbca5c897, 0x3d965f1e, 0xbd78dcf9, 0xbb15789f, 0x3e0cbcf2, 0xbe44a755, 
    0x3da490b3, 0x3e4c7a13, 0xbe078e0d, 0x3d44e50b, 0x3d4dbb42, 0xbdd396ca, 0x3e251316, 0x3d9175a2, 
    0x3d333203, 0xbd5b0040, 0x3e274248, 0xbe3b11de, 0x3d55129e, 0xbd94ac01, 0xbd8f34c1, 0x3dfe08f3, 
    0x3d96eabf, 0xbcef79d5, 0x3e1f3706, 0x3d1de06d, 0x3d95a04a, 0x3e300061, 0xbdee3e06, 0xbd3a6dd8, 
    0x3d2235b6, 0x3d657937, 0x3d0b849e, 0x3d7c9a5a, 0xbd87028b, 0x3df714e2, 0x3d79eff6, 0x3e4c5177, 
    0x3ddb3387, 0xbe176d1b, 0xbe99759b, 0x3e28fc89, 0x3ce2d1d5, 0x3e2b7a9e, 0xbe716c31, 0x3e445703, 
    0x3c4e6c53, 0xbe0b794f, 0xbda3367c, 0xbe2c18a7, 0xbe848a92, 0xbdc0386a, 0x3e336c46, 0x3e005a72, 
    0x3e5199a7, 0xbc84afb5, 0x3c3786a6, 0xbc90ba2c, 0x3d5719b3, 0xbe06fcfb, 0x3d85b84f, 0x3a87fc4c, 
    0x3e019866, 0xbe0b2e26, 0xbdabe24f, 0xbe22348d, 0xbd39c146, 0xbe0e4bbd, 0x3ca2b18c, 0xbdd9cb72, 
    0xbdd9ba33, 0xbe111713, 0xbe3d7767, 0x3d592f9e, 0x3d6e6d65, 0x3d0c0b89, 0xbe840177, 0xbd386f90, 
    0xbe90bb55, 0xbd15a604, 0xbe5afcd9, 0xbe7f4e01, 0x3e207c57, 0xbe03d346, 0x3e5b67db, 0x3d7a9ef0, 
    0x3d195b2c, 0xbe064ebc, 0x3d90df02, 0x3cee2122, 0x3d3e4905, 0x3e0807ec, 0x3e29fa06, 0x3d94122f, 
    0xbe204f12, 0x3c0839df, 0xbd1ce1ee, 0xbe042382, 0x3e357714, 0xbdb20881, 0x3cd214f6, 0x3e2ed265, 
    0x3e6ef256, 0x3df19cef, 0xbd1aec82, 0x3db90f05, 0xbb886702, 0xbe0e07fe, 0x3e1264b3, 0xbde5021b, 
    0x3d8c8854, 0xbe64f110, 0xbd28fd48, 0xbe40c4ef, 0xbc529135, 0x3de7a205, 0x3e28dc46, 0xbdc4ab42, 
    0x3e452253, 0xbdbf0df5, 0x3e09542d, 0xbe520ead, 0x3c83e6a8, 0x3e0bd5ba, 0xbd66410d, 0x3ddea330, 
    0xbcbaeb28, 0xbddfee1e, 0xbe565766, 0x3e3ae8fe, 0x3dfe8f26, 0x3d5425e5, 0x3da0da22, 0x3c098621, 
    0x3cb49f78, 0x3ce06f1d, 0xbdd276a2, 0xbdf08dfa, 0xbd97b33f, 0xbdfdda5b, 0x3e80a438, 0x3d6c099f, 
    0x3e101d80, 0x3d134482, 0x3d8cda52, 0xbc63d291, 0x3d8de20e, 0x3dde4c20, 0x3dc0a30a, 0x3c8cece7, 
    0xbe539491, 0xbde634c6, 0xbd83f678, 0x3e2dfc27, 0xbe317c9e, 0x3dcb896a, 0xbd6b027f, 0xbb3fc86d, 
    0xbb99888d, 0x3e003422, 0x3c32fb8c, 0x3d6b8e19, 0xbd589dc8, 0xbe29260a, 0x3deed66b, 0x3e474bab, 
    0xbe1b6151, 0xbdca5da0, 0x3c41e099, 0x3c088a3f, 0xbcd4a56d, 0xbdbdf618, 0x3d862eda, 0xbe209bb0, 
    0xbd56eb58, 0x3db50bff, 0x3e0c7f3e, 0x3e99457d, 0x3cbcc720, 0x3e0d7395, 0xbe34d13f, 0x3e3555af, 
    0x3db3ca43, 0xbe1d6c68, 0xbcac24b6, 0x3dbb5030, 0x3d168928, 0x3c04b809, 0x3c93e534, 0xbe560625, 
    0x3c6c845a, 0x3e175d50, 0x3e092f45, 0xbd3c1f9a, 0x3d6c9566, 0x3e496c09, 0xbe3cdf01, 0x3dada854, 
    0xbddf5c95, 0xbdff5dfa, 0xbc8bc951, 0xbe6cc996, 0x3e003ae6, 0x3e0f7add, 0x3c4ff2e8, 0x3d40686a, 
    0x3e45f030, 0x3df7a7f8, 0x3d7a279e, 0x3ca3ff01, 0xbdbbdb92, 0x3e3618dc, 0xbdf8c0cb, 0xbd8d3d49, 
    0xbd1619cf, 0xbda27d16, 0xbd1bd113, 0xbe6f2277, 0xbdd7e7b4, 0x3d4cb8cd, 0x3e1c6050, 0xbda7c218, 
    0xbd67b29e, 0x3e51e7e6, 0x3e061aee, 0x3e1e63cd, 0x3cbda8a9, 0x3d84cd73, 0xbdcd832a, 0x3d637df9, 
    0x3e0f5f23, 0xbe16817f, 0x3b1becc5, 0xbd288deb, 0xbd81195f, 0xbd1aa33b, 0xbe476d30, 0x3d63d986, 
    0x3e0adc62, 0x3d8eefbf, 0x3b755c46, 0x3df3a3ec, 0xbdb7d481, 0x3e728548, 0x3e13bf3f, 0xbdf6c334, 
    0x3dcbcf96, 0x3cfc389d, 0x3d711a26, 0xbcb1728e, 0xbd988895, 0xbc466b07, 0xbdf89c31, 0x3d9cf665, 
    0xbcc840ab, 0xbd48bc96, 0xbe194ddb, 0x3e20afd3, 0xbe19504e, 0x3d977d2a, 0xbd8f6d3e, 0xbdb3b1d8, 
    0xbe31afc2, 0xbe11fb96, 0x3e05e69b, 0x3e6144aa, 0x3e467af0, 0xbd1d1411, 0x3cc56a97, 0x3e6d6ecf, 
    0x3d0a2b59, 0xbe0c8d9d, 0xbc777847, 0x3dae002d, 0x3e664faf, 0xbd4b5e1d, 0x3d9d4d5a, 0x3c2387a8, 
    0xbd7476a5, 0x3e0d41e0, 0x3e2592ea, 0x3d6376e9, 0xbe014007, 0xbd67d89f, 0x3e36eed2, 0x3d90329e, 
    0x3df4cd13, 0x3e50c275, 0x3df1918f, 0x3e1cec7b, 0xbe0aabf5, 0x3e2a28d7, 0x3ddb50bf, 0x3d49c758, 
    0xbd838482, 0x3db41992, 0x3d9ab9f5, 0x3c66deeb, 0xbd6d0d11, 0x3d6e70a2, 0xbd79cd4e, 0xbd0793ec, 
    0x3db2142d, 0xbe11277b, 0xbe17b38a, 0xbe00fb23, 0xbe15816f, 0x3de07554, 0x3e00b1da, 0x3ccf63bb, 
    0xbe71b39c, 0x3e03f89e, 0x3e5a00da, 0xbd990250, 0x3e30acb3, 0xbd030f1f, 0xbda557e2, 0x3c649931, 
    0x3dc9deb7, 0x3dd7f4a1, 0xbcac5d7a, 0xbd7a93ce, 0x3dabc065, 0x3dd40825, 0xbd82635d, 0xbe156c64, 
    0x3c80a09e, 0x3e40c0f2, 0xbe42b6dd, 0x3e124680, 0xbe7f3807, 0xbe306fbb, 0xbc8edbb2, 0xbc8596fa, 
    0x3e5b3df4, 0xbe332814, 0x39929f0a, 0xbe1152ef, 0xbe095e25, 0x3db5229a, 0x3dc4f10d, 0x3d3fe268, 
    0xbe4dde1b, 0xbd31186c, 0x3c8dae8e, 0xbd958edd, 0xbd7714ee, 0xbe31684b, 0x3e5371e7, 0xbc2a5f7f, 
    0x3d929e4c, 0x3e26b51a, 0xbd073842, 0x3d6ed2af, 0x3cca0cf7, 0xbbb4a311, 0xbda34cd3, 0x3e0e3339, 
    0xbd7c2782, 0x3e02f226, 0x3da69302, 0x3d505ecd, 0xbcf80e69, 0x3b6a9ae0, 0xbcd98c2a, 0xbe2afffa, 
    0x3d49244b, 0x3e3524f6, 0x3e435a53, 0x3e24235a, 0xbe3e195e, 0xbe193cc2, 0xbd4ba068, 0xbd410666, 
    0x3d916445, 0xbe029179, 0xbd46af7c, 0xbd22c23b, 0x3ba5906a, 0x3e1ddcd4, 0xbe29a95f, 0x3e0be854, 
    0xbe310ceb, 0x3e223730, 0xbd806828, 0x3e2feba3, 0x3d3b9f9e, 0xbe2151ab, 0xbcfe2155, 0x3e0a9f90, 
    0x3dac705e, 0xbe2187da, 0x3d766b67, 0x3db00437, 0x3d127fac, 0x3e287d68, 0x3dabcc50, 0x3cfca4ef, 
    0x3d47f0a0, 0x3d6e8782, 0x3c8de9b1, 0x3c311aaf, 0xbdfa329f, 0xbd8994cb, 0x3cca1c23, 0x3c7823a5, 
    0xbd694d9d, 0x3dba9495, 0xbe16e013, 0xbda2564f, 0xbc048de5, 0x3cf0e790, 0x3e36b0c2, 0x3da5a6d0, 
    0x3d74b294, 0x3d0dc4bc, 0x3dea0a23, 0x3dff2ef0, 0xbe0966dd, 0xbdd264b7, 0xbd93abfc, 0xbe2d3841, 
    0x3c8fa822, 0xbda4a902, 0xbd2b9f21, 0x3dd391aa, 0xbe107615, 0xbe5feb09, 0x3c8590a7, 0x3decb9fa, 
    0x3cf9b30a, 0x3db9e603, 0x3d984c8d, 0x3d6db102, 0x3e26c6ee, 0xbd2e1a9c, 0xbd1e8920, 0x3d834857, 
    0x3e43ee26, 0x3d8989fc, 0xbd945461, 0x3df43b77, 0x3df630b7, 0x3d49cdaa, 0x3d86f871, 0x3e3b6285, 
    0x3d990df5, 0x3e2e5f06, 0x3e166e6e, 0xbd8dcfd6, 0xbd98b150, 0x3c005d6c, 0x3d9e6377, 0x3d928045, 
    0x3c981c51, 0x3dc219b1, 0xbe3415b5, 0x3e2b1781, 0x3e27bd20, 0x3b8fc6b0, 0x3d86c823, 0xbe1a0bd0, 
    0xbd54dd02, 0x3dc5c63f, 0x3dfb010c, 0x3e29fa7f, 0xbe25254e, 0x3db3825f, 0x3d11d3ac, 0xbe0ae5a9, 
    0xbde1b556, 0x3c13e9aa, 0x3d9ce61e, 0x3e0efa8a, 0xbe9ca1ca, 0xbdc4ce14, 0x3e007b1e, 0xbe0c2880, 
    0x3ca9d10d, 0xbe32fb7c, 0xbdb7e068, 0x3e4531ff, 0xbe1b2042, 0x3e1c09c2, 0xbe6f793b, 0x3e23c9b4, 
    0xbda0b614, 0xbd1c66e0, 0x3c075f05, 0xbd1bee20, 0xbe3274f4, 0x3e42e19c, 0x3d83ccac, 0xbda3a7cf, 
    0x3e64a69d, 0xbe67de2d, 0xbe244e9e, 0x3db08a41, 0xbca05714, 0x3d03936e, 0xbd82985f, 0xbd7ff8a2, 
    0xbe332ee7, 0xbd8d1317, 0x3da559b0, 0x3d77bd18, 0xbdeb53c2, 0x3dca48d4, 0x3e473824, 0xbe377e84, 
    0xbd1c327e, 0xbdb33c45, 0xbde3422e, 0x3e52f8ca, 0xbc22010f, 0x3d8c05ea, 0xbdab18b3, 0xbe002169, 
    0xbc7cdf3a, 0x3c9912dd, 0x3c9f6d08, 0xbe64be53, 0xbd85ebf8, 0xbdf402c4, 0x3e1d0ec1, 0x3d74209b, 
    0x3e1e5ffa, 0x3d73bc1f, 0xbd4f8b84, 0x3ddf6cc4, 0x3de76c58, 0xbe1d8c4b, 0xbe7fbfbe, 0x3d1ec200, 
    0x3e1b565b, 0x3dad0210, 0x3d0afecf, 0x3caf31ef, 0xbb15bc7e, 0xbd8b7e23, 0xbdccce70, 0xba7437d1, 
    0xbd8a72fd, 0x3de4ed4c, 0x3dc8c5ab, 0x3e0b7121, 0x3cf51ee0, 0xbd09da59, 0xbe382822, 0xbe288fc9, 
    0x3e638267, 0x3c2f0d96, 0x3e28743f, 0xbd311fea, 0xbd784f84, 0x3de026b1, 0x3cb2d1aa, 0xbe2344e6, 
    0x3db73671, 0xbd38279e, 0x3e4b2094, 0x3e06a3df, 0x3e2f2e4d, 0xbd809670, 0x3d98b95e, 0xbe4797f2, 
    0x3d6dd47d, 0xbd0e0a4e, 0x3e08f429, 0xbe1ce954, 0x3e265f98, 0xbd53fe8a, 0xbdc79333, 0xbe2d680b, 
    0x3e25ff13, 0xbda8cfaf, 0x3d4b4d9e, 0x3e00a473, 0xbc477ab1, 0x3e0b7001, 0xbdc6e39a, 0xbd215fe9, 
    0xbe1bcf0a, 0xbdce03cd, 0xbdaec807, 0x3bdd4cfa, 0x3e1a14c2, 0x39eaab93, 0x3e144ed5, 0x3d21dd63, 
    0xbd91e836, 0xbc7db7e9, 0x3e1f672c, 0xbb44fa06, 0x3e1d6a0a, 0xbd0ebe8b, 0x3ded2d81, 0x3db66544, 
    0xbdc9a093, 0x3dbca8a9, 0x3e05bcd7, 0xbddf13dd, 0x3db40167, 0x3dca179d, 0x3b536c31, 0x3ca2a18f, 
    0xbd12c2b2, 0xbe3ae6c0, 0x3cf00e80, 0xbe0dcc86, 0xbba02e62, 0xbc8730bd, 0x3ca96d8f, 0x3d907f4a, 
    0xbd7d5076, 0x3c58feb5, 0xbe2a5da6, 0x3e4fbb99, 0x3c5b929d, 0xbd144d7e, 0x3dd8685a, 0x3dbeaecf, 
    0xbddcccdd, 0x3dce96b6, 0xbd4c9a69, 0xbe4908fd, 0xbde0de50, 0x3e98e3ef, 0x3b94a1ba, 0x3e37cf0c, 
    0x3cf3590d, 0x3c91183c, 0xbd8b458d, 0x3e0e1861, 0x3deca1cd, 0xbe1684f6, 0x3e0afa53, 0x3cec68f8, 
    0x3e4baeca, 0xbd3925db, 0x3cbe0c58, 0xbe6d94f3, 0x3e1d4508, 0x3e18302b, 0xbde1921c, 0xbd31bcca, 
    0xbdfb1a7d, 0x3c447ca4, 0xbc797bd1, 0x3e613c74, 0xbd16aa87, 0xbe1642fc, 0x3dc19d39, 0xbd926de6, 
    0x3d990cc1, 0xbbaeff2e, 0xbd8379e9, 0x3d6dcc87, 0xbcf583cb, 0xbddff38a, 0x3e1c4e54, 0xbdfef0bf, 
    0xbe0b48c6, 0x3df65f67, 0xbd9c44df, 0xbd0c71e4, 0xbd26d24b, 0xbc885f02, 0x3d90d73e, 0xbe0e358b, 
    0x3d823231, 0x3e451dce, 0xbe22c3dc, 0x3e109321, 0xbdfd203c, 0x3dc474c3, 0xbde2140a, 0x3d8b9730, 
    0x3cf5b503, 0xbe2ba003, 0xbdb95734, 0x3cfac9e2, 0x3dc4cd38, 0x3e31a093, 0xbe1c4f4f, 0xbd9abb0a, 
    0x3dd443cb, 0xbc62651f, 0x3e624b65, 0x3e06c64b, 0x3c1a4ef0, 0x3e3c3bbd, 0x3e5688d4, 0xbde0420b, 
    0x3d957c3f, 0x3e04fc68, 0x3d198fca, 0x3e13ac92, 0xbe1277e5, 0xbd63406f, 0xbd835d33, 0xbe14995d, 
    0xbccdf7df, 0xbd441ea9, 0x3d056c12, 0x3d3e699a, 0x3e497395, 0x3dfb6514, 0xbe7bbdc1, 0xbe0bca97, 
    0x3d246be7, 0x3c757ea5, 0xbce208f0, 0xbc901493, 0x3d6c7d8d, 0xbe6e8859, 0x3de1fd64, 0xbe2be90f, 
    0x3e27a1cf, 0x3d51ae70, 0xbd8bf5b0, 0xbdb00863, 0xbe20f4a5, 0xbd56c06c, 0x3d7347ba, 0x3dd86c75, 
    0x3d20f52f, 0x3e08900e, 0x3d4a9fee, 0x3e50f3f6, 0xbe34db97, 0xbe83053f, 0x3d6c9a48, 0x3e07d423, 
    0x3d7ca0dd, 0x3e17ba2b, 0xbdf6f24a, 0xbdfca444, 0x3e49da64, 0x3cd1be11, 0x3dcf141a, 0xbd979c84, 
    0x3cddbed4, 0x3e50a0f3, 0xbd3b35f3, 0x3d5eacf5, 0xbdd0367e, 0xbd3309d7, 0xbd445ba8, 0x3c411ae7, 
    0x3c2fd785, 0xbdea8955, 0xbe3a7b45, 0xbdd3c398, 0x3d5af5b5, 0x3d7bca79, 0x3d2b648f, 0xbd8d0847, 
    0x3cef01e0, 0xbe0606b2, 0x3ddc19d3, 0xbe577edb, 0xbe66cd92, 0x3d146609, 0x3d995cca, 0x3c8a6ab7, 
    0x3e1baf0e, 0x3d91a23c, 0xbd825f47, 0xbe19dd31, 0x3e279c34, 0xba03d5fc, 0xbdcbecae, 0xbe26f690, 
    0x3dee52ca, 0x3d1776c1, 0x3c9d26df, 0xbd6ee3c4, 0x3e073eed, 0x3d19037c, 0x3e05390f, 0xbac866eb, 
    0xbc5a35bd, 0xbe2a47cd, 0xbe414819, 0xbd8ec6c7, 0xbdb597cf, 0x3e0b1f14, 0xbe62abe3, 0xbc543d23, 
    0x3e9a056a, 0x3e4af9a3, 0xbd0c08b5, 0x3da50c2e, 0xbd8bd053, 0x3c7ec124, 0xbd8c764c, 0xbcb534bc, 
    0xba243a80, 0xbc675684, 0x3c9e35c2, 0x3e38562c, 0xbd963da9, 0x3dc05794, 0xbd6c7349, 0xbb924b37, 
    0xbe6d9516, 0xbdc4739c, 0x3ced161a, 0xbe18fe84, 0xbe0a7fe7, 0xbd01053b, 0x3d23ce13, 0x3e217dc8, 
    0xbd20cc0c, 0xbd3d0ddf, 0x3e073156, 0xbd4bcc85, 0xbcbdb9ab, 0xbd2735d3, 0xbe27b925, 0x3de19b3d, 
    0xbe03d0fa, 0xbe0346b4, 0x3d8cb15c, 0x3e80f0b3, 0xbe07548b, 0xbdfbd154, 0xbe1dc37e, 0xbe411d0c, 
    0xbd6cef9e, 0x3e169009, 0x3d96daf5, 0x3c8d5d9f, 0xbd7eaa6e, 0x3df0701d, 0xbce97493, 0xbdb51364, 
    0xbdd3ab1b, 0x3d1cd96f, 0xbe83d42d, 0x3e670f1c, 0xbe659157, 0x3e296825, 0xbe8f3010, 0x3e3ef1e3, 
    0x3d27b0c5, 0x3bc6440d, 0xbd7358a4, 0x3de5adc9, 0x3cc9aa7b, 0x3e17d9c3, 0xbd4d983d, 0x3d6ec0c2, 
    0x3b9ee2b8, 0x3e3b9095, 0x3dd1f238, 0xbc8a58e1, 0xbe0bf811, 0x3e772b03, 0x3e3bc374, 0xbe6c06fd, 
    0xbdd71bba, 0xbe13e808, 0xbcd75ce5, 0x3e308476, 0xbe538781, 0x3e57ec87, 0xbd09b5e7, 0xbe2c98fe, 
    0xbe225d1d, 0xbcbf14c0, 0x3d045655, 0x3ddf60e6, 0xbe78863e, 0xbb026eee, 0x3e5ae6d5, 0xbe4bc50b, 
    0x3da402af, 0xbd90e4cc, 0xbe1d1e15, 0xbe1ec5a1, 0xbd804506, 0xbcb5440a, 0xbe6a06f5, 0x3d5be48e, 
    0x3db26aec, 0x3dcc8152, 0x3dea6c63, 0xbdfce2f6, 0xbe56f2c1, 0x3c3dbda0, 0xbdd16aca, 0x3dd4cd3e, 
    0xbc7fc98b, 0xbdd6ce72, 0x3d599c08, 0xbdfba459, 0xbc503385, 0xbe5c6e2f, 0xbd85e1e8, 0x3deb2e94, 
    0xbe650114, 0x3d39b27b, 0xbe5a2f7b, 0x3dc2a45f, 0xbea79477, 0xbd9a6c0a, 0xbdc07d17, 0xbd4d813a, 
    0xbe77e533, 0xbe85f298, 0xbca1b0b2, 0xbc4d5fc8, 0xbe412f22, 0x3d9141ca, 0x3de18a5a, 0x3e583dea, 
    0xbe67e9d9, 0x3dedbcb4, 0xbe3d5b8c, 0xbdc5b435, 0xbd9b8d88, 0x3e8d0781, 0x3d8a05ba, 0xbd8e8b94, 
    0xbc8ca044, 0xbce1d050, 0x3e4fae48, 0xbcdbfc4a, 0xbc61e2e4, 0x3e081fe6, 0x3d704714, 0xbd93ead5, 
    0xbd93d192, 0x3dca6dca, 0x3bbdc3c4, 0x3d50477b, 0xbe355d45, 0x3e088cc8, 0xbdeb6877, 0x3e182a48, 
    0x3ca6905b, 0x3de44cf6, 0x3e3c895b, 0x3dad9a2d, 0xbcb75bf9, 0x3e6a674a, 0x3cb12700, 0xbe0a4fff, 
    0xbe3de19d, 0x3c1a5dcd, 0xbd513861, 0x3e21b76a, 0x3dcd2665, 0x3c8679b0, 0xbe2826da, 0x3e09c803, 
    0xbe2f31cd, 0xbe0d29b0, 0x3dc01efa, 0xbd8040a0, 0x3c4e4b59, 0x3c89099c, 0xbdeb61ab, 0x3de8bbdc, 
    0xbe6aaf89, 0x3e15b358, 0x3e00d1b7, 0xbcab6b53, 0x3d9fde73, 0x3dbda26c, 0xbe2b982a, 0x3da00941, 
    0xbd21858f, 0xbe158f32, 0x3e1a8c44, 0x3e070875, 0x3e3fa8e3, 0xbdc96257, 0x3dac77be, 0x3e217215, 
    0xbc8f7694, 0xbd9505e2, 0x3d1d7d17, 0xbd3f6501, 0x3df0043b, 0xbd04e511, 0x3c5cb24f, 0x3e12a4b4, 
    0x3df949e9, 0x3d9ea51e, 0xbdf23149, 0xffffb796, 0x00000004, 0x00000010, 0x00000001, 0x0000000c, 
    0x00000001, 0x00000010, 0xffffb7b2, 0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000006, 
    0x00000010, 0xffffb7ce, 0x00000004, 0x00000010, 0x00000001, 0x00000006, 0x00000001, 0x00000020, 
    0xffffb7ea, 0x00000004, 0x0000000c, 0x00000001, 0x00000003, 0x00000020, 0xffffb802, 0x00000004, 
    0x00000034, 0xbd96ccd8, 0xbe121720, 0x3c7f48ae, 0xbd843fe1, 0x3a476435, 0x3bafe1aa, 0x3d25df6b, 
    0x3c5563f8, 0x3dbea2c0, 0x3e3c1a83, 0xbcb7b37a, 0x3bf67b78, 0xbc705793, 0xffffb842, 0x00000004, 
    0x000009c0, 0x3e7dea24, 0xbe8d92e2, 0xbd7bbc03, 0xbe17ee18, 0xbea83598, 0x3d94ef83, 0xbdfc00f0, 
    0xbe2d668c, 0x3ec33bea, 0x3e6f43c7, 0x3ea3f1d4, 0x3eaa0034, 0x3e73ca00, 0x3e46d1de, 0xbdd97907, 
    0xbd133754, 0xbe86bf9e, 0x3d949484, 0xbe0c3c3c, 0xbee97a58, 0x3eacab21, 0x3eace20a, 0xbe0ddd3f, 
    0xbe110631, 0xbe08d97f, 0x3ee0e5e4, 0xbe92baed, 0xbc0cca4c, 0xbea75252, 0x3e877b9a, 0x3d82c505, 
    0xbdd9c0be, 0xbef474ab, 0x3e6f07ae, 0xbda3a8ff, 0x3b0876d9, 0xbeaf5290, 0x3e52eed4, 0x3eb2257f, 
    0xbac75722, 0x3db659d9, 0x3dbb837c, 0x3de62e90, 0xbe2e9b7f, 0x3da87a84, 0x3d8e1c9e, 0x3d0c8200, 
    0xbe8e08e4, 0x3df70f50, 0xbd9691e9, 0x3e2694ac, 0x3e54527a, 0x3dc26add, 0x3deac83c, 0x3d041890, 
    0xbe104e60, 0x3e278009, 0xbcc0988d, 0x3e09b287, 0xbc6b8cac, 0xbd927ac5, 0x3d2da82e, 0x3d8adc6d, 
    0x3dde7975, 0x3d8f51e9, 0x3d08f9a5, 0x3dc35f3c, 0xbdff8644, 0xbcba8aa1, 0xbd66b1f5, 0x3d851482, 
    0xbdaa09ec, 0x3e12417b, 0xbe090bb6, 0xbdf95d9b, 0xbd057438, 0x3e07d84a, 0x3e1705de, 0xbd1fe86a, 
    0x3a4a44d3, 0xbd9acbf0, 0x3c198138, 0x3e40540f, 0x3d601981, 0xbd11c326, 0x3cd9020e, 0xbe2367fa, 
    0xbd725db3, 0x3e71581b, 0xbd847911, 0x3d75e61e, 0x3e32441c, 0xbd53eee2, 0x3d95b1f9, 0x3e217ec2, 
    0x3c3cf0aa, 0xbdcee7fb, 0x3db03645, 0xbe0044aa, 0x3e60c727, 0xbdf9b53b, 0xbe08b50c, 0xbe1dcdcc, 
    0x3bd22481, 0x3cb98232, 0xbbaa5253, 0xbe6c5ce1, 0x3d97bab3, 0x3df02c16, 0x3dc9b23c, 0xbdaa997a, 
    0xbe4e3ab4, 0x3d01a9bb, 0x3c956506, 0x3e4766d6, 0xbdf1ad93, 0xbd9c2ca7, 0xbe1f2474, 0x3d04fadb, 
    0x3d72ba67, 0x3defed89, 0x3da74ed7, 0xbe03c6c1, 0x3e192ea8, 0x3cae8516, 0xbe262a3b, 0x3e5ec085, 
    0x3deb6aad, 0x3e410567, 0xbd7be892, 0xbdc51c4f, 0xbd531e33, 0xbe54b837, 0xbbf6d1fb, 0xbe39fb2d, 
    0x3e54e8ca, 0xbe3561e4, 0x3e456512, 0xbd98055b, 0xbe4f5be6, 0x3dfd8ae4, 0x3e1335c3, 0x3df9d2ba, 
    0xbcdda356, 0xbdc9dbdf, 0xbe2b8409, 0xbda6aa21, 0x3e158683, 0xbe16e9f3, 0xbad36e46, 0x3e45b37a, 
    0xbe17533d, 0xbe053141, 0xbc715c6f, 0x3d0150ab, 0x3d4eaf1f, 0xbbe9f3af, 0x3dc20dc6, 0x3d6f7f4b, 
    0xbe166253, 0x3e112280, 0xbc492b35, 0x3e7208f4, 0x3dd3e78c, 0x3dd07717, 0x3d19e5a4, 0x3c56694b, 
    0x3df1f4eb, 0x3c7de5b2, 0xbdc2bf6b, 0x3d698ace, 0xbe309695, 0xbe2abe93, 0x3d0f518c, 0x3dba6368, 
    0x3d968cc1, 0xbe23c322, 0x3e04c816, 0xbcf40027, 0x3ce7886c, 0x3df2b12e, 0xbcf88c6c, 0xbd56c28d, 
    0x3d710515, 0x3db28a6d, 0x3cbfc0e9, 0x3dccd04c, 0x3d64a191, 0x3e135e44, 0x3daba7d7, 0x3dfc2dde, 
    0x3e149f06, 0xbdf06c61, 0xbd1fef90, 0x3deadbaa, 0xbcd3148c, 0x3e56a4b8, 0x3debdcb3, 0x3de65a42, 
    0x3d151a3d, 0x3d89f9e2, 0x3dcafffb, 0x3d123d69, 0xbd8f3b25, 0x3c008ff1, 0xbdd66ab7, 0x3db4388a, 
    0x3e04a1a9, 0x3e7bfb1f, 0x3cca8e1d, 0x3e1b25ad, 0xbd202900, 0xbe0c824a, 0xbcf402db, 0x3c14c130, 
    0xbe32a777, 0x3da21403, 0xbe0af490, 0x3e55148f, 0x3d9bbe49, 0x3e0504bc, 0xbc2087d4, 0x3d515d37, 
    0x3e2c1243, 0xbd2dc109, 0x3cdc7797, 0x3d69253d, 0xbe529f5e, 0xbddc3b6a, 0xbdfd6a0f, 0xbdd6bf6b, 
    0x3d4ba155, 0x3d9a532c, 0xbd03e8d4, 0xbe8e4c01, 0xbd202600, 0xbdb38be7, 0x3e23444e, 0xbdb920df, 
    0x3d5394af, 0xbe1e1590, 0x3d82c379, 0xbe1dff62, 0xbe2fcae2, 0xbdcd8b2c, 0xbc945127, 0x3da97781, 
    0xbe66f339, 0xbd990e7f, 0xbd4feb7a, 0xbe43bfe3, 0xbe1fee61, 0x3e208f04, 0xbe3bc1f0, 0xbcd681f8, 
    0x3dec5568, 0x3dbfce86, 0xbd89c12e, 0xbdee82e1, 0x3d87707a, 0xbddfc30b, 0xbe16ab6a, 0x3cdc2317, 
    0xbcdd873c, 0xbe5fc875, 0xbe44e2ed, 0xbe36a4b8, 0xbccd9bb5, 0xbe1e8742, 0xbe288397, 0xbb2db3e2, 
    0xbce9a362, 0x3dffe861, 0x3db55b66, 0xbdb99df0, 0xbe6e083d, 0x3d7871d5, 0xbcf525e8, 0x3e207b02, 
    0x3de73ebe, 0x3d367a4c, 0x3e1c8703, 0x3d6a3a1e, 0x3d912460, 0x3db2efe1, 0x3d433e03, 0x3e5421cb, 
    0xbe301546, 0xbe4e2aae, 0xbe019e18, 0xbd40b534, 0xbd047728, 0x3d32c262, 0x3d0cfa73, 0xbe2a587b, 
    0x3d65ecf5, 0x3d909266, 0x3ddc0e7f, 0x3e237641, 0xbc8be2a5, 0x3d271c82, 0xbdb87f10, 0xbe1d89be, 
    0x3d740906, 0x3d608e49, 0xbd9579bf, 0xbe0c7051, 0x3e33ec82, 0x3cad015c, 0xbd9047a3, 0xbe530fa2, 
    0x3e7368a4, 0x3d1afd97, 0xbd9a4507, 0x3dbe59b0, 0xbd922aae, 0xbe0b990e, 0x3ddada59, 0x3baab049, 
    0x3dd515fe, 0xbdb3bd89, 0x3de44b66, 0xbe3be9f7, 0xbd6a07da, 0x3d01a9e4, 0xbe3056da, 0xbe179649, 
    0x3dc2bfa9, 0xbdd1b6f2, 0x3dd6965d, 0xbdf153e1, 0x3e0067dc, 0xbe2a6e23, 0xbd8e4f0a, 0x3e2a615c, 
    0xbbe7c523, 0x3d523bb7, 0xbd86170d, 0x3e0702f1, 0xbe3230fe, 0x3c98522c, 0xbe048a72, 0x3da8abd4, 
    0xbe1f7058, 0x3e2e6a72, 0x3df478d7, 0x3df65852, 0x3e0c77e9, 0x3cf05da5, 0xbe1de791, 0xbd6de90e, 
    0x3dee7819, 0x3cdabbe7, 0x3d4cea25, 0xbe4bb1cf, 0xbdca146b, 0xbe00037e, 0x3e7ea4c5, 0xbe102851, 
    0xbd0abcf5, 0xbdbea929, 0xbdc2d39b, 0xbd6a93eb, 0x3e181386, 0x3e155237, 0xbda0c6d2, 0x3dd80482, 
    0xbe10464c, 0xbe15e1af, 0xbc417506, 0x3e52f512, 0x3e0e8663, 0x3ddcff97, 0xbd70dd7e, 0x3e0e83b3, 
    0x3e01cb61, 0xbe634927, 0xbebd7762, 0xbe006de1, 0xbe734ddf, 0x3e05ba3f, 0xbd8390da, 0xbd522eab, 
    0xbcbb2d5e, 0xbe370239, 0xbc74a3ab, 0x3e7da2cb, 0x3e956895, 0x3e80d954, 0xbdae5ee3, 0xbd6422c1, 
    0x3ded2976, 0xbe6c8ad5, 0x3e4c38de, 0x3be1ccd6, 0x3dc2670e, 0xbe1d305d, 0xbbe60bdd, 0xbdfdc59d, 
    0x3e222264, 0xbdc00d4c, 0x3dc9086d, 0xbdd9b5a7, 0x3b9f2a0c, 0x3e683245, 0x3e6c0ebc, 0x3dc1fe83, 
    0x3e535915, 0xbe36e4de, 0x3ebdf792, 0x3d4ada99, 0x3d9fe9f1, 0xbe5d55f8, 0x3d09c39e, 0xbeae2189, 
    0x3d6c7a14, 0xbc6fbf14, 0x3da4c8d8, 0xbe4180da, 0x3e1e6db6, 0x3e93a3fe, 0x3d176bee, 0x3e72819f, 
    0xbe68241b, 0x3dba13f8, 0xbe4269ae, 0xbda9359b, 0xbe5f402d, 0x3e76932c, 0xbe1bfb0e, 0xbdd2d8c0, 
    0x3ca32b10, 0x3d82eb74, 0x3c672166, 0xbe35872f, 0xbdbcbcad, 0xbe5db281, 0x3e55daf0, 0xbda197db, 
    0xbe55f910, 0xbd513964, 0xbe370ce6, 0xbd6b7f1c, 0x3d569e71, 0x3e492fe3, 0xbdbba110, 0x3c9f992a, 
    0x3d8105cc, 0x3d8ce1e1, 0xbd7b3940, 0x3dfffe1f, 0x3c1a7cfb, 0x3d9af3e7, 0x3df7d444, 0xbd654510, 
    0x3c9edd42, 0xbdb080de, 0x3e3c441f, 0xbe5ae167, 0x3dc526c0, 0x3dbf49bc, 0x3da9f7dd, 0xbe669981, 
    0xbdec2d9f, 0x3e1d76a5, 0x3db2b2b6, 0x3d54e010, 0xbdac3093, 0x3e03b2f2, 0xbe0223cf, 0xbde55555, 
    0x3d6bb365, 0xbe736350, 0x3e1a70ce, 0x3df05571, 0xbc3105b3, 0x3e20cf8e, 0xbe97174e, 0x3e634fb2, 
    0xbe6887d5, 0x3e429acb, 0x3d12cb03, 0x3db675d2, 0xbe56bd9f, 0x3dab5112, 0x3da37cfd, 0x3d839211, 
    0x3db8acdc, 0xbe33d355, 0xbd7c0c05, 0xbe3b4988, 0x3e5304c1, 0xbe9f4ef5, 0x3e276cad, 0x3eb070e1, 
    0x3dba9a5d, 0xbcd63af6, 0xbdf1d3d9, 0x3d60db25, 0x3d4ccb77, 0xbd78a0f9, 0x3a2867b4, 0xbde926db, 
    0xbd44e6ad, 0xbdf996a6, 0xbd325a51, 0xbc581be1, 0xbe969ac4, 0xbe20dcfe, 0xbe1bd86e, 0xbe73ac42, 
    0x3e1460a6, 0x3e81be14, 0xbe363a1f, 0x3e739a09, 0x3e07676a, 0x3e47a7c1, 0x3ddfa8ac, 0xbe462614, 
    0x3d681984, 0xbe72be1f, 0xbe2a48c0, 0xbe8f0c64, 0xbdf68d27, 0x3e8dacd5, 0x3c02d6c3, 0xbda334cf, 
    0x3e850c8f, 0x3cd8d84a, 0x3e977673, 0xbd8f9210, 0xbe6cd7fb, 0x3ea6e42a, 0x3e04f6c0, 0xbd98cb20, 
    0xbe5f8095, 0x3c2def77, 0x3e2acc4a, 0x3e13789e, 0x3e4f7693, 0x3e8e6b7a, 0x3db19864, 0x3d8e0c10, 
    0xbe62c220, 0xbe0e391a, 0xbd828aef, 0xbd7bc7e9, 0xbe57bffc, 0x3e81cc09, 0x3e84fed0, 0xbe2e9a31, 
    0x3e5e0d8c, 0x3d8519a6, 0x3e875fc1, 0xbe84c885, 0xbde060e8, 0xbebb3fbe, 0xbe61bd40, 0xbe15296d, 
    0x3e36ecf7, 0x3ea3287a, 0xbe056593, 0xbd5ca648, 0x3e20754b, 0x3ec1f308, 0xbd381433, 0xbd40fd7b, 
    0x3ddde284, 0x3d636519, 0x3e4039d0, 0xbeb837c8, 0xbe2a116a, 0xbe12a61e, 0x3e7e7d0f, 0xbe4c6dc8, 
    0x3e904495, 0x3e7654cc, 0xbd69a747, 0xbd5ea0b2, 0x3e09b3d1, 0xbdded797, 0xbead64f4, 0x3d0e544b, 
    0xbda0fd9f, 0x3e4a2fdc, 0x3ca1c806, 0xbe1b8f74, 0x3d1c0b1a, 0x3e45c8f4, 0xbca10586, 0xbe8c7016, 
    0xbdbd0f17, 0xbd35a0fe, 0x3e02a7f8, 0x3e07ef5b, 0x3da22997, 0x3e1eca62, 0x3e25ab3f, 0xbdac79c9, 
    0xbd118984, 0xbdbb19a4, 0x3e09ba83, 0x3e5505ca, 0xbd8259a7, 0x3e869787, 0x3e7078b0, 0xbdbec2b9, 
    0xbddf551d, 0xbd84b6ba, 0xbcc78504, 0x3d9f0e7d, 0x3d7fa3e9, 0x3e345c20, 0xbcda3168, 0x3d74397f, 
    0x3d33779c, 0x3d4ddf52, 0x3b989317, 0x3d16c895, 0xbe6073f6, 0x3e17f7a2, 0xbdb42771, 0x3e38e381, 
    0x3cab56f3, 0xffffc20e, 0x00000004, 0x00000c00, 0x3f232a61, 0xbdc40f90, 0x3e90ecfd, 0xbeaf7121, 
    0x3f366123, 0x3f2780da, 0xbe88769b, 0xbf1c1493, 0xbf175fd0, 0xbe81e263, 0xbd0a760b, 0x3f3e5b15, 
    0x3ea78e69, 0xbf071ae6, 0x3ed717a1, 0xbf1317a2, 0x3f4a9455, 0x3f4077bc, 0xbeffa722, 0xbce46014, 
    0x3f095e10, 0x3d93e655, 0xbf436558, 0x3f47a5d9, 0xbf2efd40, 0x3e51b360, 0xbd2bf646, 0x3e55f37a, 
    0xbeef967f, 0x3ecbf05d, 0xbf4d4880, 0xbf6e4d8b, 0xbed76c25, 0x3f065903, 0x3f13d8c0, 0x3ebab2f0, 
    0x3f604cfc, 0xbdbaf553, 0x3d468107, 0x3f293189, 0x3f1f6a9f, 0x3f35287c, 0xbed44409, 0x3e1ebf69, 
    0xbf3d0e8d, 0x3f16bf3b, 0xbf5baf24, 0xbc4b1c32, 0x3c725ac4, 0x3dca5807, 0x3e0aae3d, 0xbe04b8d0, 
    0x3d571540, 0x3ee99a59, 0xbe0a9231, 0xbe92db4f, 0x3e611287, 0xbe57ca52, 0xbe9dd070, 0x3eca3b28, 
    0x3c7acd9f, 0xbd5ad117, 0x3eb0086e, 0x3c9bbcc8, 0x3e92d15a, 0xbeb6731c, 0xbe222350, 0x3eb15635, 
    0x3ecaf650, 0x3ea66975, 0x3eb485ee, 0x3efc54dc, 0x3e5c7786, 0xbed5212f, 0x3dee4413, 0x3ecf4b10, 
    0x3eb76f77, 0xbe943ccf, 0x3eb57028, 0x3e310179, 0xbea79d6a, 0x3dae324e, 0x3d02dfb2, 0x3e8966f1, 
    0xbe84ed1d, 0x3e7d51bf, 0xbe28f656, 0x3e41dd4e, 0x3e4b7070, 0x3cfe7de8, 0xbe80afe9, 0xbe647849, 
    0x3ee8fa22, 0x3d5bfb2b, 0xbe0d4620, 0x3ee2609f, 0xbedc5634, 0xbe3fd462, 0x3ea6bdb2, 0x3e65a267, 
    0xbe390093, 0x3f254955, 0xbf31722e, 0xbee754df, 0x3d776cc1, 0x3d0d0abf, 0xbf1d56a9, 0xbea67725, 
    0xbed6d596, 0x3ee3fa8f, 0xbdd6c60e, 0x3e95ea00, 0xbef3b3b6, 0x3dfc1905, 0xbf305652, 0xbd2b74ae, 
    0xbe64faa0, 0xbeafc2b2, 0xbf5eda91, 0x3e7015ed, 0x3c1f9f2b, 0xbe42a273, 0xbf1d4232, 0xbf48eac8, 
    0xbec7b6b1, 0x3b78d61a, 0x3ebbcdb9, 0xbf32efbc, 0x3d9ee30f, 0x3ec784fb, 0xbeb614ec, 0x3f1df3df, 
    0x3ed9240c, 0x3e238df7, 0xbecb38d9, 0x3e0592f3, 0xbf05f173, 0x3e00c0c3, 0x3ec71d5b, 0x3e90fc0d, 
    0x3e970e8c, 0xbee1724d, 0x3efa9fb5, 0xbd837df7, 0x3ee63eaa, 0x3c009caf, 0x3b16f553, 0x3ea6e922, 
    0x3f0fc826, 0x3d7ee9db, 0xbce4ca95, 0xbaa423c8, 0x3e97c182, 0x3d063611, 0x3ec7f903, 0xbec7d678, 
    0xbeeb9ee1, 0xbeb0706e, 0xbdb2b788, 0xbde4b459, 0x3e2effa5, 0x3eb40d4d, 0x3ddff180, 0xbde4b05b, 
    0xbe56b1d8, 0xbed5324b, 0x3e4108fb, 0xbdb175b2, 0x3eb8b43c, 0xbea0ecca, 0x3dc5744d, 0xbea45d31, 
    0x3ebedf65, 0xbdb53841, 0xbe489546, 0xbeb414e4, 0x3efe1677, 0x3e908549, 0x3ea5f8f6, 0x3ea463af, 
    0xbdf81226, 0xbe28e477, 0xbede77b1, 0x3ea4a020, 0xbe816fba, 0xbee5145c, 0x3e942ecb, 0x3f014c67, 
    0xbdfcbbe4, 0xbf0939d2, 0x3cec4440, 0x3f0939b3, 0xbe901ba8, 0x3e503214, 0xbe1ee2f8, 0x3e9bf2b5, 
    0x3f08d1e6, 0x3eab4102, 0x3ec6ff70, 0xbeea1806, 0xbf39cc41, 0x3e54c89a, 0xbeba9e13, 0x3e6dec02, 
    0x3dff7bfe, 0xbeb29ba8, 0x3ebd5f9c, 0x3e59b914, 0x3e6302b4, 0xbd83d789, 0xbeb3cd68, 0x3dbad835, 
    0x3efb53be, 0x3d9759c5, 0x3dabf7d7, 0xbdb8b203, 0xbe519215, 0x3d8a2632, 0x3eb5c53c, 0xbee8d49e, 
    0xbee7a0d9, 0xbee80801, 0x3e0d70e7, 0xbe881ce1, 0x3dfc6492, 0xbd3c728e, 0x3f035683, 0x3da3b321, 
    0x3ec7038a, 0xbef86bb6, 0x3e8bcb31, 0x3ee68c38, 0xbe3b4749, 0x3f3e358a, 0xbe911a3c, 0xbea79698, 
    0x3ef9a7a1, 0xbeba4615, 0xbead41c4, 0x3ef4a436, 0x3ea6e81d, 0xbeebd138, 0x3f179d2b, 0x3f33002f, 
    0xbf4e267d, 0x3c1ad125, 0x3e51f17a, 0x3f25cda0, 0x3f3659ef, 0x3edd1a2f, 0xbf890d6c, 0x3b8f5702, 
    0xbeec3239, 0x3f2eba78, 0x3f426920, 0x3e0e2b2b, 0x3e9d3a57, 0xbebcee97, 0x3eeb2526, 0xbd9c195d, 
    0x3f1f0675, 0xbeda781f, 0x3f1c85a1, 0x3e62590b, 0x3ee55b0f, 0x3eb34dcb, 0xbf91a9c6, 0x3e593723, 
    0x3f343f6d, 0x3f2bb446, 0xbf41b005, 0x3f659fe5, 0xbe02a77a, 0x3eb68eea, 0x3e525b46, 0x3dd8791d, 
    0xbed9aef5, 0xbed3f8c2, 0xbefda814, 0xbf0cfa89, 0x3f471e1d, 0x3ecb683b, 0xbe196f49, 0x3e0ecba5, 
    0xbf2641dd, 0x3f2774e6, 0x3ebd8c32, 0x3e914108, 0xbeb878a1, 0x3e3dfea5, 0xbd20db45, 0xbeefd739, 
    0xbe852a62, 0xbe138605, 0x3db2d651, 0xbf10af2e, 0xbe721193, 0xbed86d48, 0x3e0a487a, 0x3f0cc48a, 
    0x3e884734, 0x3ea40f7c, 0xbf1aad41, 0x3eaa6e38, 0xbf28d567, 0x3de51a7e, 0x3e703fb4, 0xbd9c2082, 
    0x3ee9f434, 0x3e5d0c90, 0x3f16b6ee, 0xbeee6de7, 0xbdf6adbb, 0x3d711522, 0x3ea5b14e, 0xbc87fcb1, 
    0x3dcd119f, 0x3e010928, 0xbe20823a, 0xbec70a19, 0xbd44e597, 0x3e8b1b5e, 0xbe9d3b51, 0xbf030c2a, 
    0x3eceed42, 0x3e627d5a, 0x3e5711ff, 0xbf2d9229, 0x3e08d6f3, 0xbef7156f, 0x3da4ef81, 0x3f1357f2, 
    0xbe0e5544, 0x3e9547e3, 0xbf0d0cb2, 0xbdb10738, 0x3ea78e60, 0x3f3322d2, 0x3eb9723e, 0x3cfcdaf5, 
    0xbd1492bc, 0x3cf2e788, 0xbeb5a65d, 0xbec51932, 0x3f38a362, 0xbf1b915f, 0x3eb5aeca, 0x3e9b42d4, 
    0xbeb5356b, 0xbe76fda9, 0x3e101016, 0xbe9175ab, 0x3e199909, 0x3f0787e8, 0x3d0344fc, 0x3c5e9939, 
    0xbe2bd3d0, 0x3dd9c58e, 0xbf43279c, 0x3df3e56f, 0x3eca0d5a, 0xbdf881d3, 0x3ed3fad2, 0xbe9fa01b, 
    0x3f32eb4b, 0x3f1581bd, 0xbf1a0537, 0xbee5f223, 0x3b9e1d59, 0xbece70a8, 0x3e0f61dd, 0x3e4a9cfa, 
    0xbe74ef3e, 0xbe66ad21, 0xbe77713f, 0x3d1c1a78, 0x3e8705d9, 0x3ef0f951, 0xbec69b21, 0x3f389c72, 
    0xbe8425f4, 0xbe68d04b, 0x3f15fb12, 0xbe5cf524, 0x3ef61dbc, 0xbe5c8e93, 0x3f4c478a, 0x3ec88b30, 
    0xbe659480, 0xbf04ee1f, 0x3da4ebab, 0xbe9a08cb, 0xbe8e7c80, 0x3ec0f85b, 0xbf2fef9a, 0xbcd36739, 
    0xbf315b1c, 0xbdbceaf4, 0xbf2fd4d8, 0x3c1925f8, 0xbf1117cf, 0x3ef9657d, 0x3f0484e0, 0xbee8a7da, 
    0xbe138259, 0xbe963149, 0xbe983274, 0xbf331892, 0xbd0f7791, 0x3ec8a405, 0x3e88ada5, 0x3e1eb85e, 
    0xbdd7fcb5, 0xbe837335, 0x3ddf41a3, 0xbedd8d85, 0x3e0a1a1c, 0x3d6006c0, 0xbe102de1, 0xbe114f83, 
    0x3b73ed44, 0x3d843d71, 0x3dfffe98, 0xbf4fb2f9, 0xbe2fbca3, 0x3e8fe07b, 0xbf01bbf0, 0xbe774449, 
    0xbd1e97e0, 0xbe5a6d06, 0xbe99f051, 0xbee259cd, 0x3e273fde, 0x3dc637c9, 0xbdc99ac4, 0x3f151433, 
    0xbdb4fbc5, 0xbda2a67b, 0x3d6f6b53, 0x3e6db603, 0x3ec66a23, 0xbe670d48, 0xbe2f711c, 0xbf02712e, 
    0x3e5eb84d, 0x3f19a845, 0x3e81037f, 0x3f0e8542, 0x3cfd744f, 0xbd86a44f, 0xbed170f2, 0x3f35e624, 
    0xbd99f43a, 0xbdf80ff4, 0x3d076c49, 0x3ea2a947, 0x3ec7f844, 0x3d304b6b, 0xbcea2caa, 0xbdbf4f89, 
    0xbf169a50, 0x3e8ce636, 0x3efd486b, 0x3e9bb61f, 0xbca3fb3b, 0xbd82c888, 0xbe534eca, 0x3eb0dd05, 
    0x3db5029b, 0xbf1b22d7, 0xbdc78f7b, 0xbe2fca79, 0x3f018f4b, 0x3e46fc78, 0x3e5391a6, 0xbebb3990, 
    0x3ec96dad, 0x3e23e48b, 0xbf19cdaf, 0x3f0829a6, 0x3e94e222, 0x3fc5bada, 0x3f438a3e, 0xbed6bd41, 
    0xbce047d1, 0x3e6b46f0, 0x3f2d9aee, 0x3f6c3da4, 0x3f159077, 0xbf0fddce, 0x3bbb3379, 0x3f39c42c, 
    0x3db96cc7, 0x3e659a09, 0xbf44b1da, 0x3ec21053, 0xbf0e406a, 0xbe0d8795, 0xbf2ba18e, 0xbf44b110, 
    0x3f0d0b06, 0xbf4f07b3, 0xbe9df61d, 0x3e3cade3, 0x3ca66c5e, 0x3dc47876, 0x3e0c8b43, 0xbe1edf02, 
    0xbf179057, 0x3c16d778, 0xbeeb0661, 0x3e619f09, 0x3efb474a, 0x3f10997e, 0x3da9edc8, 0xbf3e08f8, 
    0x3f5dae60, 0xbe20fe3e, 0x3e90b9f7, 0xbe9a9282, 0xbf3b89a0, 0xbf5c3ed2, 0x3e7ed4f3, 0x3e2d5b41, 
    0xbe16a3a9, 0x3e8220ef, 0x3f000b87, 0xbba1b4e8, 0xbe1b64bc, 0x3d27e8e8, 0xbf0654c7, 0xbec41f93, 
    0x3e43f166, 0x3f1d7407, 0xbe4722dd, 0xbe794e64, 0xbe3762fb, 0xbecd9a1f, 0xbf0345bb, 0x3c224b5f, 
    0x3deda17b, 0xbc2dd3a8, 0x3e14d456, 0xbe60c1bf, 0xbe4af61b, 0xbe95fe10, 0xbe243357, 0xbf0a1109, 
    0x3de415e9, 0xbd67c1c9, 0x3e6ca3c0, 0xbe098959, 0x3db84c35, 0x3dbbdd2b, 0xbe0ecbc5, 0x3e5e2032, 
    0x3e587e81, 0x3d17f5d1, 0xbe40a27a, 0x3e5d8c0f, 0xbe3f5586, 0x3d33c384, 0xbdbdb541, 0xbdec0990, 
    0x3e7d8490, 0x3e9f78e8, 0xbc0c9829, 0x3e711484, 0x3e6b1025, 0x3d98c799, 0x3e693a7d, 0x3ea76190, 
    0xbea913df, 0xbee79e9d, 0xbd3c756f, 0xbea2be7f, 0x3ee62b5c, 0x3e7fc5c6, 0x3e379481, 0xbef63b8b, 
    0xbebed8f4, 0xbece7c08, 0x3eefa054, 0xbd45bc53, 0xbe9636eb, 0x3e065c33, 0x3e41cfc0, 0xbe5d62b1, 
    0xbe57f4f5, 0x3d28bb05, 0xbd5ae75b, 0xbe5849d5, 0x3e4fcc94, 0x3ec1bc93, 0x3e087c53, 0x3d9d1f34, 
    0xbe7b49d6, 0xbdd81540, 0x3ec759df, 0xbeaca752, 0x3ecae39b, 0xbec3a5db, 0x3ede0d9a, 0x3e84c887, 
    0x3e96ac2e, 0xbe0ec762, 0xbe02ae93, 0xbe4671c3, 0x3eb43c4c, 0xbe1a66fa, 0x3de0f866, 0xbed584ab, 
    0x3e3aec07, 0xbe5b45c2, 0xbe9b6888, 0xbeea8219, 0x3c935eb8, 0xbde1b9ad, 0x376aa5bb, 0xbcb0b0a3, 
    0xbd409996, 0x3c4dfaf7, 0x3e755393, 0xbe6fb5fe, 0xbf11e4c2, 0xbe65e5ac, 0xbead9dfc, 0xbea9ed4f, 
    0xbe85ac33, 0xbd4e8019, 0x3ea9a73e, 0xbe109479, 0xbeb62395, 0xbd9d2308, 0xbeadafda, 0xbe7c940b, 
    0xbd91a29a, 0x3d8b1aa9, 0xbc96c533, 0xbddcb780, 0xbeed35a0, 0xbce83caf, 0x3f070c37, 0x3e823fd3, 
    0x3ef9ac9a, 0xbe5a8d8a, 0xbed4f9e0, 0xbe1af643, 0x3d3109dc, 0xbd3a412a, 0xbde49959, 0x3ed0ff62, 
    0x3e81fdcf, 0x3f0a37ed, 0x3e669e6e, 0xbf204789, 0xbe9d4f6c, 0x3e840576, 0xbecef71f, 0xbea8c302, 
    0x3ec3dd57, 0xbcaf8da4, 0xbe408026, 0xbe897b6f, 0xbeb75903, 0xbdce487f, 0xbebf63ce, 0x3e080af0, 
    0xbe9ef762, 0x3bb8bc50, 0xbecf566b, 0x3ea1a9ec, 0xbe70b66e, 0xbdb62162, 0xbedae660, 0x3f07830c, 
    0x3f34daa0, 0xbece4234, 0xbebec6cc, 0xbed1d389, 0xbecfae5f, 0x3c7d410b, 0xbe15cd04, 0xbf02eebd, 
    0x3eb34a86, 0x3f40604d, 0x3e375c29, 0xbf157144, 0x3ed1e080, 0x3ec97af6, 0xbdea8b78, 0x3e95aa5d, 
    0x3e06575b, 0x3eb6c9c2, 0x3eaacff3, 0x3e59de38, 0xbe1fccbc, 0x3edc6fef, 0xbe803d93, 0x3eb6199e, 
    0x3ef8f8bf, 0x3f0fa5f4, 0xbe20debb, 0x3f088207, 0x3edff82b, 0x3de6c83e, 0xbd07c574, 0x3b8bc65b, 
    0xbec4cce5, 0x3d44ac94, 0x3ea2766f, 0xbeceb5bc, 0x3e971bbc, 0xbdf4ec3a, 0xbdd15209, 0x3cf56d97, 
    0x3e03e30b, 0x3eb8aca1, 0xbe88bb99, 0x3ed8b10c, 0x3ef8dde9, 0xbfacb4a0, 0x3f3b09f9, 0xbf32ff0f, 
    0x3f57388c, 0xbe948437, 0x3eff12c1, 0x3f3daee7, 0xbe6df2bf, 0xbf17255f, 0xbdf791f2, 0x3e5d9edc, 
    0x3e37f8db, 0xbdcb1685, 0xbf20dc08, 0xba3e0fa4, 0x3db72ae9, 0xbf0ec981, 0xbdc966cd, 0x3f2db1be, 
    0x3f55aa3d, 0x3f594d96, 0x3f29ae61, 0x3ea21f25, 0xbe4cb745, 0xbe07dfd2, 0x3e68345d, 0xbe93c813, 
    0x3e980f56, 0x3d399dd9, 0xbf420647, 0x3ef5e9a7, 0xbdb84d4d, 0xbda2a16f, 0x3e853922, 0x3e124b7d, 
    0x3ea6c125, 0xbf57f012, 0x3d2df540, 0xbf01bc1e, 0xbef22a29, 0x3ec3a155, 0x3ea72a32, 0x3f6bca96, 
    0xbdb2f677, 0x3f34303c, 0x3f05604c, 0xbf2e92d0, 0xffffce1a, 0x00000004, 0x00003000, 0x3ea329b1, 
    0x3e99d5d8, 0x3ee421ca, 0x3de93cec, 0x3ebfb16e, 0xbdb78a37, 0x3e40ce61, 0xbe5fdb07, 0x3dbce083, 
    0xbef0a3ae, 0xbeb90b11, 0xbe93083c, 0x3e8b1ee9, 0xbe3d81e0, 0x3f1ec4fe, 0xbeabec8c, 0xbdd164fd, 
    0xbed6830a, 0x3e4a0318, 0xbf1e5f27, 0x3da6175d, 0xbf1810aa, 0x3e9ffeed, 0x3f06d125, 0xbe84e61e, 
    0xbe5bd01b, 0xbeb6bdd5, 0x3c86edb3, 0xbe1ef5df, 0x3e83320b, 0x3eca2517, 0x3efe7c20, 0x3e71ace7, 
    0x3ceb7bf7, 0xbe328038, 0xbe395a57, 0xbd4697fe, 0x3f2dad30, 0xbea62030, 0x3d300326, 0xbee648b5, 
    0xbf29bb62, 0xbea99baa, 0x3f0794f4, 0x3f1eeb1f, 0xbd8debcb, 0x3ed90b6c, 0x3e612e06, 0xbe14ae41, 
    0x3e205f6c, 0x3eecdefc, 0xbe00b5de, 0x3e709143, 0xbf3ef3e7, 0xbe847eaa, 0xbdfd5e09, 0x3e0a9470, 
    0x3ed637bf, 0xbf0387e3, 0x3e9e0863, 0x3ec02cb1, 0xbc11d1a1, 0xbe8cf1c3, 0x3e717ea0, 0xbed36ed7, 
    0x3f3b5d20, 0x3ed9b7b2, 0x3eb966f9, 0xbdbbfd7b, 0xbe4e9b07, 0x3e8401f5, 0x3ee5ec8e, 0x3eee0f55, 
    0xbf136326, 0x3f27abfe, 0x3e1a74de, 0xbe21bc04, 0x3ed7bd30, 0x3cdbb76f, 0xbdcfee9e, 0xbf17f6e6, 
    0xbdfd75f3, 0xbee587cd, 0x3d19755d, 0xbea425a8, 0x3cbc10e4, 0xbee5715a, 0x3f0c0fb6, 0xbee23d0a, 
    0x3ef4c343, 0xbd4da2a5, 0xbebf8f83, 0xbe5e7957, 0x3d0d517f, 0xbf3cc1f5, 0x3d2bd0ae, 0x3e4e9ea2, 
    0x3e825af2, 0xbe90f007, 0xbf0919f7, 0x3ef8da20, 0xbdd824bb, 0xbe881813, 0x3f183ce2, 0x3e1ac7e0, 
    0xbe41fe27, 0x3eeefb1f, 0xbe233138, 0x3ea996de, 0xbe4194ce, 0xbe444b53, 0xbe2910e8, 0xbb8db5a7, 
    0xbf063c79, 0xbf04b442, 0x3e496e99, 0x3c60dcfe, 0x3e61d9a8, 0x3e7227c9, 0xbd58500b, 0x3ed3c9e3, 
    0xbd444669, 0x3e12cea5, 0xbe866524, 0xbe034d3c, 0xbba20376, 0xbf3144c9, 0x3ec1429d, 0x3d686dd1, 
    0xbdaf2235, 0xbec287ed, 0x3ec31cf3, 0x3eecae9b, 0xbe26433e, 0xbebb4820, 0x3d05f2af, 0xbea93908, 
    0x3eaea3b7, 0xbd7ee3b6, 0xbedbd53b, 0xbed4fedc, 0x3eca4faa, 0x3e2e2ee6, 0xbe4441bc, 0xbeae2888, 
    0x3d221fde, 0x3f008807, 0x3e26ca0a, 0x3ea60c55, 0xbed59de4, 0xbdc3dc55, 0x3ebcb582, 0x3dc644e5, 
    0xbc4dd703, 0x3f0fd219, 0xbe8687d3, 0xbf081e0e, 0xbea95172, 0xbe47bf74, 0xbd218b61, 0xbec44772, 
    0x3e9dbabd, 0x3d298309, 0xbe3c4df7, 0x3ee060e4, 0x3f105e08, 0xbcff2ea0, 0xbec812a2, 0x3e5f1b0b, 
    0xbeb3e817, 0x3efd81c7, 0x3e526b1b, 0xbe4d15fe, 0x3e97eed9, 0x3eac4319, 0x3e0ccc64, 0xbd4bd901, 
    0xbe6f80aa, 0xbe934661, 0xbe9589a3, 0x3d780d2d, 0xbdc85e36, 0xbe858443, 0xbf00f3dd, 0xbe69ecd2, 
    0x3e82a5d3, 0xbea66599, 0x3de5552e, 0xbe2eb9c6, 0xbec4bda8, 0xbd71d301, 0x3e86199d, 0x3d5e7d8c, 
    0x3eadd041, 0x3e889890, 0x3eb12b90, 0xbe468e6a, 0xbed269e9, 0x3dcc227c, 0xbe95b408, 0x3f1677f1, 
    0xbf03550c, 0xbe82cc24, 0xbe6ea6f8, 0x3ed1284a, 0x3ea7e158, 0x3f051d1b, 0x3e0fa68d, 0xbda224aa, 
    0xbe87d0fb, 0x3e97f765, 0xbe70b391, 0x3d7edf85, 0x3dfeda1e, 0xbea6828a, 0x3e78dfb6, 0xbe6804aa, 
    0xbe555f47, 0x3f0dcd99, 0xbe23119c, 0xbd67c4b5, 0x3ee5eaeb, 0x3f07ac45, 0xbea66d3c, 0x3f6796da, 
    0xbd11321f, 0xbeeda45e, 0xbe436382, 0xbcd74872, 0x3ebf9cc4, 0x3c6dccd5, 0x3e68ab8d, 0x3e7ac408, 
    0xbdd60efa, 0x3d606c7b, 0x3c84215a, 0xbef30fef, 0xbeedc367, 0xbed3cee8, 0xbc8933fd, 0x3e808fe3, 
    0xbe9f86be, 0xbde5bf4f, 0xbe99b34f, 0xbeb79810, 0xbe1bc6ad, 0xbe0f7ecb, 0x3dbd5d3a, 0xbe01cc37, 
    0xbe80e24e, 0xbe85e5b4, 0xbddd4b08, 0x3f1491e7, 0xbee53efc, 0xbc824e73, 0x3dab2a11, 0x3e68a500, 
    0x3e060766, 0xbee02c5a, 0xbe53c1c6, 0xbdba32f8, 0xbdd45d2c, 0x3de839ae, 0x3e8616ad, 0x3ee13a83, 
    0xbda4db43, 0xbeb76476, 0xbeb3bc4e, 0x3d9dc186, 0x3ea6f591, 0x3e1c0919, 0x3f5ae658, 0xbee22576, 
    0x3dbc2cb9, 0x3eb0fb6f, 0x3e834085, 0xbe293d65, 0xbe03fdc4, 0xbebb2f0f, 0x3e517e07, 0x3f17ccf4, 
    0xbe0f096b, 0x3edc8f41, 0xbeef8a11, 0x3f0070ea, 0xbe441a0a, 0xbdc911e8, 0xbe7a13d4, 0xbe097433, 
    0xbba3219c, 0xbeab1c75, 0x3ee21708, 0xbdb5ff3e, 0x3ec5ea54, 0xbd380339, 0xbe6a7a34, 0xbda9709f, 
    0x3d85c306, 0x3ece9a9d, 0xbe4d2759, 0x3e414fee, 0x3e29085b, 0x3e4cbfa5, 0x3eb5f05d, 0x3e0cbeb0, 
    0xbe9432d1, 0x3d21d5bb, 0xbe2c5910, 0xbe5885d7, 0x3e275547, 0xbe4bb09d, 0x3e50053d, 0xbe91653d, 
    0x3e2477e9, 0x3d33563e, 0xbab19bc8, 0x3eb107b6, 0x3d72e1cf, 0x3eb671ea, 0x3daa1820, 0x3e9f7ac1, 
    0xbed7dc56, 0x3d8996a3, 0x3e9c05fe, 0xbdc49339, 0x3b303da9, 0x3ead600d, 0xbea98c3e, 0xbe7d052f, 
    0x3da5b20c, 0x3eab4b55, 0xbe97625a, 0x3e7cac15, 0xbdf66020, 0x3ea1ae4f, 0x3f0dc0de, 0xbe5968c9, 
    0xbe850570, 0xbe82ba3d, 0x3e4dad6f, 0x3ee1011c, 0x3e24f2c7, 0x3d7b7373, 0xbd40c80e, 0xbefb3a51, 
    0x3cbcd7cd, 0xbdf0861a, 0x3e37e2fc, 0xbc7e5375, 0x3e58391a, 0xbec00b48, 0xbdc32bdf, 0x3d99e977, 
    0xbceeeca0, 0x3e55074f, 0x3e62ac73, 0xbe305924, 0x3e864de4, 0xbe008754, 0xbe6be027, 0x3d937261, 
    0xbe401b5e, 0x3e2a8674, 0x3d31d577, 0x3ebd31e5, 0xbe9c0f7c, 0x3dbae1db, 0x3cf57524, 0xbc604ee9, 
    0xbdc6dc9f, 0xbec80839, 0xbd6d51cf, 0x3efb0d12, 0x3e499e2d, 0x3f052cce, 0x3ed59e21, 0xbc78aa70, 
    0x3ea9b6af, 0xbe4414f0, 0x3e4385fc, 0xbe2ffd71, 0x3eb1e9a2, 0x3decf822, 0xbed20efd, 0xbe7fd595, 
    0x3e8aa19b, 0x3e530448, 0x3e2faad1, 0xbec4e4ee, 0xbea526e4, 0xbeafc0aa, 0x3c930c89, 0xbe8cdc9c, 
    0x3ec2b039, 0xbea2e0de, 0xbe70c0fa, 0x3eaf6e08, 0x3ed3a5de, 0xbe52b665, 0x3e7c12c2, 0x3f0441d8, 
    0xbe8a758a, 0x3e9b1af7, 0xbdf32bd0, 0x3d503212, 0xbe1a0a4b, 0xbe995f6c, 0xbe9dd3c1, 0x3f2ad9fa, 
    0xbeaa33eb, 0x3f147e11, 0x3f35ff87, 0x3f41ce25, 0xbd80f116, 0xbdb6d674, 0x3db50f91, 0xbeab68b5, 
    0xbefa0654, 0x3eb657dd, 0xbe61c04b, 0x3dfffb8d, 0xbbc214c8, 0xbe9c3daa, 0xbd3a6f02, 0x3e8bc27c, 
    0x3ec653f6, 0x3e8221cc, 0x3eef5eea, 0xbe9b22a4, 0x3f0cf4c8, 0xbf03b04c, 0x3ef4c4b2, 0x3ed8cbf1, 
    0xbe6bd675, 0x3e6b4289, 0xbca77604, 0xbf19e6eb, 0x3e005850, 0xbeb8565b, 0x3ee6e7c5, 0xbd094515, 
    0xbee3fb27, 0x3f0e7b2b, 0xbede5daa, 0x3b1426f0, 0x3e182800, 0x3ea8bdbe, 0x3d4e7832, 0xbc439137, 
    0xbe66e440, 0xbe691510, 0xbefaa28b, 0x3b5ec197, 0x3e8c3124, 0xbd1c5734, 0xbe869a25, 0x3e32735c, 
    0x3f16229c, 0x3dc25554, 0x3e990de5, 0xbe0e2e91, 0x3e698c9a, 0xbee21533, 0xbdc5c2df, 0x3e4eb293, 
    0x3d066806, 0x3e32d1db, 0xbd9cd5f4, 0xbe970afa, 0xbe002bf2, 0xbd2bb065, 0xbe3b17c0, 0x3f0cb605, 
    0x3e0e2437, 0xbeb5eeca, 0xbd5f2740, 0x3f116187, 0x3e4d36f3, 0x3e333980, 0xbec031d5, 0x3ea715c3, 
    0xbe86a4f5, 0x3f2bfc13, 0x3eb3d13f, 0xbe12480d, 0xbe8b3bd5, 0xbe525c74, 0x3eb05367, 0x3e3c0ee2, 
    0xbe202e2e, 0xbd9f0eb0, 0x3de42130, 0x3db4d655, 0xbe88ebfd, 0xbe3eac63, 0x3e6df119, 0x3eff20c5, 
    0x3f02afba, 0xbec5b2e2, 0xbf048e84, 0x3d3156d9, 0xbd742f98, 0xbea5dde9, 0xbe0723c2, 0xbf2522e2, 
    0xbb761fab, 0xbdcf9bd6, 0x3e2054f2, 0xbca7217a, 0xbe56d17a, 0x3f2b90a3, 0x3ef9d412, 0x3b535fb4, 
    0x3dbfb618, 0x3ec935bf, 0xbdb2882b, 0xbe5849a6, 0xbd832121, 0x3e76544d, 0x3e8d47be, 0x3dfb6043, 
    0x3e3b3bba, 0x3e9a7572, 0x3e31a1c9, 0xbdd38954, 0xbe181165, 0x3ef8a439, 0xbe288390, 0x3dc6f92d, 
    0xbd6a2c24, 0xbea6c8a6, 0xbeab8a16, 0x3e9bc45c, 0xbefddfd5, 0x3decfe0c, 0xbd4d0050, 0x3df6ffc1, 
    0x3ebf9523, 0x3ed1a498, 0x3d8ec9e2, 0x3d489f28, 0xbf267fed, 0xbe18b030, 0x3ef24ce7, 0x3b4c42fa, 
    0x3d959f34, 0xbebf03fa, 0x3f221798, 0x3ea45812, 0xbf1f4d2a, 0xbe7e4a5c, 0xbeeb181a, 0xbe5d3ffd, 
    0x3e0be046, 0x3e5de64e, 0x3dcc9b69, 0xbde79175, 0xbea58909, 0xbec8c566, 0xbe3b2423, 0x3d8c397d, 
    0x3ec25b01, 0xbf255642, 0x3dc623b4, 0xbeb83eea, 0xbe3c1660, 0xbe4467be, 0x3d32c4ec, 0xbdf78366, 
    0x3e44aa05, 0x3df19e8a, 0x3ef7630b, 0x3f31fc88, 0x3ec8daf0, 0x3ee816f0, 0x3ee9d84d, 0x3e43130b, 
    0x3ed6aa05, 0x3e829dcc, 0xbd8c541e, 0x3ecc39f0, 0x3e50977a, 0xbf3579d1, 0xbed89eb9, 0x3ec79c72, 
    0xbd90e513, 0x3e97bf36, 0x3f0ad43e, 0xbdfc0b46, 0xbe19dc2f, 0x3f05369d, 0xbecf1f53, 0x3ed9c659, 
    0xbd442013, 0x3e11e345, 0xbe44e752, 0x3f46b05f, 0xbe638a6c, 0x3d730991, 0x3d3011a6, 0xbeafe144, 
    0x3d25d253, 0xbdedfba8, 0x3e57b61b, 0x3d8733dd, 0xbe627a6f, 0x3f126582, 0xbe1d07ba, 0xbda704c2, 
    0xbe5eb143, 0x3e30acf7, 0xbeb93924, 0x3ebeed4f, 0xbe800763, 0xbea76246, 0x3e40a09c, 0xbea31d02, 
    0xbe285572, 0xbe3e80a1, 0x3ecc6ba1, 0xbf26c693, 0x3dcb012f, 0x3ef9a771, 0x3e05a5c7, 0x3e2e4159, 
    0x3db490b1, 0x3e1c35cf, 0xbe00e4f2, 0xbe8e7c66, 0xbe50edeb, 0x3dd7da18, 0x3d84962a, 0x3e9f43ca, 
    0xbde2508e, 0xbef3bcb9, 0xbf117f0d, 0x3f06ed75, 0xbe05064d, 0x3dd698be, 0x3e39d2d6, 0x3e872664, 
    0x3eb0975d, 0x3d815401, 0x3e181147, 0x3e312563, 0x3ebf100d, 0xbf1debe3, 0x3e5250e7, 0x3ec422a7, 
    0xbec42d47, 0xbe1cbfe8, 0xbd274870, 0x3f0900c8, 0x3f0b7552, 0x3e4d0b4a, 0xbe3e0f8e, 0xbe9cbc62, 
    0x3eb80c5a, 0x3e454c84, 0x3ee34cb3, 0x3ed70209, 0x3da19e24, 0xbec1936f, 0xbe5c1526, 0x3bebf712, 
    0xbecafca3, 0xbe0c48a4, 0xbe636304, 0xbed7a396, 0x3e219618, 0xbe82eb7a, 0xbdbfd70c, 0x3e8c1010, 
    0xbe8e9657, 0xbed867e9, 0xbdc4319d, 0x3e66d8a6, 0xbdb234ad, 0xbe590a54, 0x3e2f2711, 0xbe532b5a, 
    0xbe6da51a, 0xbead0d06, 0xbedb7337, 0xbea9643f, 0x3da681d9, 0x3e3812bd, 0x3e792950, 0xbcb59114, 
    0x3e0f6ef7, 0xbe0aa968, 0x3ed807b6, 0x3d53959a, 0x3e760f14, 0xbf0db679, 0x3dd69e22, 0x3f20f281, 
    0x3e1de0d5, 0x3e8ce373, 0xbe302ebf, 0xbe4e9b12, 0x3e0e319b, 0x3d65b437, 0xbd1707d3, 0x3c28b98b, 
    0xbf0502ac, 0x3e07807c, 0x3dd96ea0, 0x3e9bea7e, 0x3eaf213d, 0x3e763da4, 0x3d6704c9, 0xbdf4ffc0, 
    0xbd94f380, 0x3e22603a, 0xbd492d09, 0x3eeeea9a, 0xbe480d75, 0x3e714a48, 0xbe59146e, 0xbeeb6b3d, 
    0x3e0fa553, 0x3d8d52fa, 0xbe318115, 0xbe65ad3b, 0x3ee63d29, 0x3e5480ca, 0x3d87cc54, 0x3dd6a883, 
    0x3d7d051d, 0xbef35cf6, 0xbf0489cf, 0x3d8fc7ff, 0x3ddd6fa8, 0x3d298990, 0xbddd9298, 0xbd7bbe98, 
    0xbcc4f631, 0xbeb2926d, 0x3d86ba29, 0x3e917ed9, 0xbe814bde, 0x3e3f89cc, 0x3dd62f02, 0xbeceee2d, 
    0x3d581bcd, 0xbe705efd, 0x3d03de24, 0x3e16f63a, 0x3e0f8260, 0x3ea6a061, 0x3e18802d, 0x3ddefa94, 
    0x3e9ccf2f, 0x3ee10bbc, 0x3eb8d5fd, 0xbd825c1b, 0x3edf348d, 0xbe156ea7, 0x3e9df6ab, 0xbe054bbd, 
    0xbe84ccec, 0x3eacb0ea, 0xbe369080, 0x3e032fe2, 0x3f222d6a, 0x3e22cde6, 0xbee43b26, 0xbeafedc6, 
    0x3d49ae1d, 0xbce3e50d, 0xbec20db4, 0x3edcf472, 0xbed1e031, 0xbea41bf9, 0xbe337732, 0xbeba5cdd, 
    0x3eacf087, 0x3f01d10e, 0xbe92e838, 0x3e072e21, 0xbecc1cac, 0xbe7a6ccc, 0x3dd254c4, 0x3f2dd144, 
    0x3d744d2f, 0x3e88e92d, 0xbecde148, 0x3eaf1a2d, 0xbe90c694, 0xbeaeb4c3, 0x3eca90f5, 0x3f111880, 
    0xbe287f48, 0xbe6c609b, 0xbe2edd23, 0x3f1f3fff, 0xbe681cd9, 0x3f025029, 0x3f0d3949, 0xbe8e7a4a, 
    0xbea8775d, 0x3e797177, 0x3ee13223, 0xbe4fecca, 0x3d0ff498, 0x3e177611, 0xbde13d85, 0x3efef2cb, 
    0xbebecfee, 0xbdcb6602, 0x3e3364a2, 0xbf116e57, 0xbe4a6827, 0x3e3ab1ad, 0xbda1cb2a, 0x3e9d5f13, 
    0x3e1adce8, 0xbe9b87b0, 0xbdf68b9b, 0xbec98092, 0xbd9c12ab, 0x3dde17fd, 0xbd4dceed, 0x3d47e402, 
    0xbebc34dd, 0xbf0575bf, 0x3e84777c, 0xbe6be133, 0xbf1fc8aa, 0x3e0c53b9, 0xbdd113a8, 0xbf079985, 
    0x3f204fbd, 0xbd9aaa4f, 0x3e151533, 0x3a9f09fe, 0x3db44417, 0x3e44da06, 0xbe22d7c4, 0x3ea162e6, 
    0xbe555b8a, 0x3e9f4521, 0xbe3b5bef, 0x3eb5cbac, 0xbd352254, 0x3d91f76e, 0x3ea877f7, 0x3cff0999, 
    0xbe1b2ac5, 0x3eb1481e, 0x3ddc4ba8, 0xbec093ee, 0xbe8f4bc3, 0x3e7a0d09, 0xbe9b8736, 0x3ef41776, 
    0x3d4d54d6, 0x3ec921bc, 0xbea4081d, 0x3f0300cc, 0xbe32b6a6, 0x3e48f2a0, 0x3eb604ec, 0x3ee300de, 
    0xbe611af8, 0x3eab3300, 0x3e4bd2eb, 0xbed405ca, 0x3d70e57a, 0x3f430812, 0x3e3dcff2, 0xbe2cc080, 
    0x3cbb8962, 0xbd8e878e, 0x3e3e281b, 0x3e2691b1, 0xbda0a9f6, 0xbd5b9d01, 0xbf03fb19, 0xbed31d60, 
    0xbf157af7, 0x3eb36873, 0x3ea8fe7b, 0x3cd121ed, 0xbe825a28, 0xbf003df6, 0xbbcbbadf, 0x3e515f5e, 
    0x3ea1c1e2, 0xbdd5be4d, 0x3e56dbe8, 0x3dc6a97c, 0x3e9d37e4, 0x3e830bb3, 0xbe78cfbc, 0xbee94007, 
    0xbec7a9df, 0xbc96bb35, 0x3e62a2a5, 0x3e949a7b, 0x3eaf545e, 0x3e9023c6, 0x3ee2e3c2, 0x3e4710f7, 
    0xbf24fdce, 0xbe94fe6f, 0xbe2a8873, 0x3ed7a8a4, 0x3e20167f, 0xbeb0990a, 0xbf0250df, 0x3eabdfa8, 
    0x3e0772e3, 0x3ed2adfd, 0xbbddcf7e, 0x3ecbac90, 0x3ee93583, 0x3ece5ed1, 0x3caf7c33, 0xbe97225e, 
    0xbe0edc2d, 0x3ee60bfc, 0x3e5765fb, 0x3e8464d2, 0x3eb596c9, 0xbe8fff2e, 0xbdccad8d, 0x3e4d29a3, 
    0x3f313570, 0xbdb6e138, 0xbc14287d, 0xbf10bf87, 0xbd649233, 0x3f1d4c2b, 0x3d55df17, 0xbf169077, 
    0xbc60a736, 0xbf20e228, 0x3ea9dc8f, 0xbf1b85ed, 0xbddb9ff0, 0x3eac3689, 0xbd58cc74, 0xbf07d228, 
    0x3b5bd096, 0xbd8251cc, 0xbe6a5724, 0xbeb9c36e, 0x3eb55653, 0xbeb8d58e, 0xbe969d59, 0x3ea387a9, 
    0xbd39a46d, 0x3ddf59ce, 0x3ee7f78f, 0xbdc733a4, 0x3eeb76d3, 0xbe171e58, 0x3e7c7590, 0xbe0480e6, 
    0x3f1aaf6b, 0x3f25687d, 0xbe5f3321, 0xbed3d88a, 0xbf05e9d1, 0xbf1648ff, 0xbd4bf775, 0xbea5a446, 
    0x3f3380a9, 0xbe076f2e, 0x3e022658, 0x3cb22ece, 0x3f1d981a, 0xbe20b9d9, 0x3ef054f7, 0x3f105395, 
    0x3daea15a, 0xbd261021, 0x3c7a46ca, 0x3eca717b, 0x3d773507, 0xbf244773, 0x3f2effab, 0xbef269fa, 
    0x3ebabd9a, 0xbec2ed09, 0x3e6a8147, 0x3e4d695f, 0x3d172c0e, 0xbe533f11, 0xbe49ac0a, 0xbede6148, 
    0xbf028e54, 0x3ed8749c, 0xbe59b81c, 0x3ee1fe47, 0x3e822790, 0xbe344c0c, 0xbe5ce020, 0x3d77436a, 
    0x3ee1bdf5, 0x3f08f294, 0x3dcf8f98, 0xbe56f7cb, 0x3d5df2de, 0x3e37d4d9, 0x3dcd8174, 0x3ea432b5, 
    0x3df2154c, 0xbe3ef4a8, 0xbe08b77c, 0xbe0aa059, 0xbe4cafab, 0x3e76b387, 0x3eb7e414, 0x3d80448b, 
    0x3ef3b632, 0x3e683237, 0xbc842a3d, 0x3e405580, 0xbe2ff648, 0xbf1d47c1, 0x3e57bb61, 0xbe4c15f6, 
    0x3ca5e413, 0x3e8ee7cd, 0x3e144626, 0x3e30c59a, 0x3e8364be, 0x3e88090c, 0xbefad626, 0x3eb575f5, 
    0x3db0a72e, 0x3e944ea8, 0x3e3836ee, 0xbe21f6f2, 0xbe5192e5, 0xbdd2b18d, 0x3e9275fd, 0x3e881f6b, 
    0xbeb844e8, 0xbea0928a, 0xbe689090, 0xbdbadd2d, 0x3e65711a, 0x3e798b44, 0xbdfd3dd8, 0xbbc9817d, 
    0x3e6a60c5, 0xbe9ba8d1, 0xbe8d8bdf, 0xbdd77396, 0x3e6e856f, 0xbe1bebba, 0x3e1f6445, 0x3efffa0a, 
    0x3e1eb556, 0xbebcb87e, 0x3e46769e, 0xbeadbfa4, 0xbe98e1ce, 0x3eae8de9, 0xbe795bac, 0x3eb99187, 
    0xbd849f2b, 0x3edd9724, 0x3d06fc51, 0x3e8a3a34, 0x3e8a641e, 0xbef45e64, 0xbed80ea3, 0xbe501226, 
    0xbe878742, 0x3ebbd056, 0x3ea27cd8, 0x3dd03f70, 0xbf020c15, 0x3dfe2c70, 0x3f1448d2, 0xbe309396, 
    0x3e8a7bc4, 0x3f2ac4bb, 0x3e9bfc05, 0xbeb4df2a, 0xbef4986b, 0xbedaf4df, 0xbe21354b, 0xbedd4825, 
    0xbead54b0, 0x3e4fb025, 0x3e9c1335, 0x3d3be266, 0x3ca7d346, 0x3dd49702, 0x3ee8dc29, 0xbe30946b, 
    0xbd0f3f2d, 0xbe7ab3ce, 0x3cd74967, 0x3bb72078, 0x3db2a6b4, 0x3dd231d7, 0xbde876ed, 0xbeb7c364, 
    0x3dfacb8d, 0x3eb9d195, 0x3e8b5c65, 0xbed01131, 0xbe4859f2, 0x3e06e7f4, 0xbe9ab743, 0x3e4f44c0, 
    0xbc80deb2, 0xbef8d3ae, 0x3eb82a25, 0x3eb5d7b9, 0xbeb2f1b7, 0x3c0108ec, 0xbe7025f2, 0xbe63c5b4, 
    0xbd9ebadc, 0xbee51261, 0x3eb26880, 0xbe6bcae9, 0xbe752036, 0xbd38ea54, 0xbe8acbdd, 0xbd0917df, 
    0xbace7d76, 0x3ebfc35c, 0x3da139b9, 0x3d38576c, 0x3e30f599, 0xbe97321a, 0xbe60191b, 0x3ea57a97, 
    0x3e330684, 0x3ea8545a, 0x3e96b02c, 0xbde569a9, 0xbe8876ee, 0x3e7f7983, 0x3e9c72fc, 0xbcadd5f6, 
    0xbc6d3014, 0x3f0fd75a, 0xbefbc9fd, 0x3e18ab89, 0x3e79dd29, 0xbd10eecc, 0x3e66a78e, 0xbebb4d56, 
    0xbdb55990, 0x3e350aaa, 0xbe31ea64, 0x3f00204c, 0xbe2f5dbc, 0xbe596999, 0x3e584c79, 0x3e8f238d, 
    0x3ee9a16d, 0xbf00c663, 0x3e5b190e, 0xbd31d9c5, 0x3ea813b9, 0x3df9507e, 0xbf001458, 0x3ee33f98, 
    0x3e8ad9ee, 0x3e5ac083, 0xbd684b9f, 0xbd5d9bd1, 0x3eebdc89, 0x3e10b83e, 0x3eb5b510, 0x3e8351bb, 
    0x3e9fc918, 0x3e04d823, 0x3d26c9c7, 0x3ce61ed7, 0x3dad2601, 0x3e11fd15, 0x3d53411d, 0xbeab33e9, 
    0xbe9a318f, 0x3f00cfab, 0x3e6b2a71, 0xbe478a1c, 0xbe0b4338, 0x3ebe6324, 0x3cc82a50, 0xbdbd48e6, 
    0x3e875d9c, 0xbe335e2c, 0xbec8db6e, 0xbe906504, 0xbe3da5e8, 0xbe218833, 0xbf1ff0dd, 0xbe709d93, 
    0x3f18f40d, 0xbd595a96, 0xbeb8c453, 0x3d013c28, 0x3eb3c84e, 0xbed37d1c, 0x3d2ab8d5, 0x3ebab894, 
    0xbe110ce1, 0x3d9d48f8, 0x3e71422b, 0x3d03e334, 0x3e2ae29a, 0xbe05e3fd, 0x3da7a0d6, 0x3e862158, 
    0xbeb9ef2f, 0xbe212de6, 0xbe8a2e87, 0x3e67f291, 0x3ea28c16, 0xbf09eef3, 0x3e933a5b, 0x3dbae482, 
    0x3ed5f356, 0x3d1a242e, 0x3da141b3, 0xbdf5362d, 0xbe38464f, 0xbeeb3757, 0xbe90e3e0, 0xbdcdf895, 
    0x3e9729b5, 0xbf047219, 0xbec993d4, 0x3e912270, 0x3e42f5e5, 0x3da24c4f, 0x3ea4d893, 0xbd929e37, 
    0x3d372855, 0x3e37538b, 0xbd71b4c5, 0x3e759326, 0x3e38f73a, 0x3cf706c6, 0xbe125111, 0x3e8396fd, 
    0x3ea19265, 0x3eb2c05d, 0x3ea53177, 0xbdfa3f2e, 0x3e4114d6, 0x3e28bf16, 0x3ec06d7a, 0x3e9d57ae, 
    0x3d6a1979, 0x3d90b863, 0xbd2b4e54, 0x3e9f844d, 0xbe5e3b96, 0x3e865e72, 0xbc2544ec, 0x3de039d6, 
    0x3e4a542c, 0xbe888a9a, 0xbe9d1c9e, 0x3e536a12, 0x3de5c152, 0x3e97e9c0, 0x3ea4de2c, 0xbb1ecf84, 
    0x3ec6e6f7, 0xbe5a0a3b, 0xbe0a4117, 0x3f0fa6aa, 0x3e018e92, 0xbdcacdc2, 0xbe8fbb05, 0x3df30ca1, 
    0xbeaac2b4, 0x3ebcf55a, 0xbcf8f8c5, 0x3e737409, 0xbec171b1, 0x3dfaf9f5, 0x3ea9dc77, 0x3e722c6d, 
    0xbe1815df, 0x3c5e0863, 0xbe61d505, 0x3ddbed4c, 0xbe9ce9b7, 0xbe70ad82, 0xbdba9286, 0xbd9a58eb, 
    0x3e5daa9b, 0x3e1d67b2, 0xbed2eff0, 0x3e8e2a28, 0x3d31cf0e, 0xbe226494, 0xbdb4b621, 0x3e7ad1b1, 
    0xbd85331d, 0xbd861185, 0xbe84dbff, 0xbd2dc603, 0x3e1e64f5, 0xbe88873c, 0x3c620511, 0xbd1c4f59, 
    0x3ec3231b, 0x3f221453, 0xbe4ce0b7, 0xbddfb4a9, 0x3b94c22d, 0x3ec4a10b, 0xbc511a89, 0x3e87d7c1, 
    0x3ecac021, 0xbde3d939, 0x3d2aad30, 0x3df3d060, 0xbead5d5b, 0x3d91d0bf, 0x3d95192d, 0x3b4334c6, 
    0x3d9e8005, 0x3ea590cc, 0x3e9487bd, 0x3ea9a543, 0xbd013a1b, 0xbe9b62d1, 0x3e315700, 0xbe844070, 
    0x3e3e17f6, 0x3e8a20af, 0x3ea74cfe, 0x3e302e8c, 0x3e4da026, 0x3ed88907, 0xbea4c749, 0xbf019804, 
    0x3e02a097, 0x3c75264b, 0xbeace4d1, 0xbe3185f6, 0xbe8dda12, 0xbe133313, 0xbe2ef60a, 0xbd279a5c, 
    0x3ef9f556, 0x3cbb3edf, 0xbdb648f0, 0x3e8a7e5d, 0x3d955831, 0x3e182753, 0x3d394dc6, 0xbe1df6e3, 
    0x3e02a0bf, 0xbe94dd43, 0xbcab52eb, 0x3deb596d, 0x3edb605c, 0xbe98aa33, 0x3e0ac51e, 0xbe62fecd, 
    0x3cc660c3, 0xbd4a85d4, 0xbbdc89d2, 0x3ec69181, 0xbe00f472, 0x3c3f9031, 0x3ec10bbc, 0xbeb12d2b, 
    0xbe5a1ae6, 0x3cc46374, 0x3ed88f4d, 0xbde41b6c, 0xbf042fb1, 0x3dd151d1, 0xbe5f16d5, 0xbebae283, 
    0x3ea14478, 0x3e87618d, 0x3e967899, 0xbf09b23a, 0xbe15f687, 0x3e934a9e, 0x3eca1869, 0x3e32ce49, 
    0xbf0a8ef4, 0xbe70691c, 0x3e00e395, 0x3e51ea7c, 0x3e0e7215, 0x3f0ad1e0, 0xbe3512f8, 0x3ec821de, 
    0xbe1e05b3, 0x3d8cfd38, 0x3ef20b43, 0x3eca2d05, 0x3e81bea1, 0x3ec8d66f, 0xbe8d8c6e, 0xbf080780, 
    0x3ec0dffa, 0xbdc5367d, 0xbe6bf8cd, 0x3e03d454, 0x3e848426, 0x3e0788b8, 0xbefe28ab, 0x3e83609e, 
    0x3f0a3b89, 0x3ea16869, 0x3db70b1f, 0x3efbe288, 0xbe9baee6, 0xbe6cb5d2, 0x3df66465, 0xbd508120, 
    0xbf07ea03, 0xbec603d3, 0x3f12bd7a, 0x3d8420e9, 0x3e73453c, 0x3db7189d, 0x3ee8191b, 0x3edaa73a, 
    0x3eed8aae, 0xbd3acb4e, 0xbe213167, 0x3ef19ce9, 0xbe901043, 0xbdd993fd, 0xbea45b55, 0x3f0ca214, 
    0x3e1b434f, 0x3ca3ecbe, 0xbee6d7e0, 0x3f01e9f8, 0x3e3cca6d, 0xbf1e2dad, 0x3ed805c6, 0x3e4595e8, 
    0xbe2440c9, 0xbe8662ae, 0xbd7390a2, 0xbec9069b, 0xbd288eb7, 0x3e42f5c0, 0xbe7b6f14, 0xbecd86be, 
    0x3ea3727c, 0xbe90489a, 0x3e4027c9, 0x3e8f822b, 0x3e063af0, 0x3e1828e6, 0xbf0f6ede, 0x3f32c499, 
    0xbf19be9e, 0x3ec39825, 0x3e0d26c8, 0xbe6ee2f8, 0x3dd1ae14, 0x3ea02533, 0xbe7394f2, 0xbe6afe49, 
    0xbe7c3457, 0x3e4350a1, 0x3e0e821b, 0x3e0d996c, 0xbeb0b8dd, 0x3e29a5da, 0xbec3820b, 0xbeb9f249, 
    0x3d430cb9, 0xbe5f4692, 0xbe174a9f, 0xbec7ca5d, 0x3e2a4255, 0xbde65057, 0xbef9ee9f, 0xbedb6d92, 
    0x3e6cc1b2, 0x3d7ea6e3, 0x3ea224b3, 0xbd907165, 0xbc2482f4, 0xbea68dc4, 0xbea1a1b9, 0xbbbe7d51, 
    0xbe4ceeb9, 0xbea26cdb, 0xbe1b7eaa, 0xbe31d144, 0xbb5c0d86, 0xbce32e05, 0x3d4c47f6, 0xbcf19d05, 
    0x3ce65197, 0xbef76e66, 0x3df1f54a, 0x3f1438ed, 0xbe6440de, 0xbe33f588, 0xbecc375a, 0x3f023421, 
    0xbe953be9, 0xbcb357e4, 0xbd04eefa, 0x3f25d129, 0x3e489fa2, 0xbec45f66, 0xbf0daee9, 0xbeb0ee14, 
    0x3eaef31d, 0x3dce5f11, 0x3e9fcc6d, 0x3ebb3629, 0x3ec7a0e0, 0xbeae7662, 0x3ddc4643, 0x3ef2c0e5, 
    0xbec70cc6, 0x3e231c77, 0x3eb87c70, 0x3dfcbeed, 0x3ead3fb1, 0x3eb96182, 0x3e1af2c8, 0x3e7f1803, 
    0x3d9a61ed, 0xbc9ad3cd, 0xbdf14be9, 0xbec81d5d, 0xbe188b1b, 0x3e66d7fa, 0xbe82c2f0, 0xbdfb8495, 
    0xbe9ccfe6, 0xbdca49ed, 0xbe300845, 0x3ec686bf, 0xbe96c15c, 0x3ce2058b, 0x3d83cbd7, 0x3d003329, 
    0x3e9fcf26, 0xbe1df3fe, 0x3eaecf9d, 0x3e633bd4, 0xbea4694d, 0x3edfcd6d, 0x3e98bdc8, 0xbddc2fcd, 
    0xbe1ca32a, 0x3e49619b, 0x3def4c74, 0x3eaaf0a7, 0xbddcc738, 0x3f08548d, 0xbd9fd3f0, 0x3e9f788e, 
    0xbeb2fd03, 0xbe09f15f, 0xbd50242d, 0xbda9266b, 0xbe26ba90, 0xbe2c0b05, 0x3e6d3af6, 0x3eb7ae1f, 
    0xbe954204, 0x3ec6e716, 0xbd241a5f, 0xbf02a805, 0x3dc925b0, 0xbe1bf744, 0x3ec3679d, 0x3e473d3c, 
    0x3e68e19a, 0x3d306ad5, 0x3ed37367, 0xbea85f99, 0x3e17fabb, 0x3e8e5557, 0x3d4bef69, 0xbea08943, 
    0x3efde270, 0xbe5b0c7b, 0x3da1e1c5, 0xbd9fc0ef, 0x3d5ce670, 0x3ed48ebe, 0x3e78b8ab, 0x3ec62543, 
    0xbcec81ad, 0xbe34c6eb, 0xbd8c5699, 0xbf0a094f, 0xbe2b0bc9, 0xbcadbb66, 0x3dd54105, 0x3ed73624, 
    0xbe5fce86, 0xbebeb21c, 0x3e6375c5, 0x3d1e06cd, 0x3e8ebeb9, 0x3e09fb8b, 0x3e0289b6, 0xbddad588, 
    0x3e3512c7, 0x3e13670c, 0xbe2eabcd, 0xbe22368c, 0xbe9185f7, 0x3ed043a0, 0xbe0f565c, 0xbda29434, 
    0x3e379338, 0xbe8a1287, 0xbe5314bb, 0x3e5ba70e, 0xbe36e9f4, 0x3e698421, 0x3e610ff8, 0xbe7094fe, 
    0x3eabd218, 0x3ea35e2d, 0xbee7f24f, 0xbec74df2, 0x3cd2fb25, 0x3ea79d71, 0x3e85ddf8, 0x3e137054, 
    0x3e56ba80, 0xbea31c5d, 0xbdcba7bc, 0xbe9c8fcc, 0xbeb90580, 0x3e588e8a, 0x3decf632, 0xbe72ffff, 
    0xbde5e6fe, 0x3ea7b3b8, 0xbe71d36a, 0xbe07f934, 0x3ef0f835, 0x3e988c77, 0xbcb53037, 0x3d1bafaa, 
    0xbd33fd67, 0xbea7d3c0, 0x3e267eca, 0x3e319b98, 0x3e865710, 0x3e8875ca, 0x3e853019, 0xbe8f55c5, 
    0x3e2b8010, 0x3ee66aa5, 0x3ed537a7, 0xbe9a1786, 0x3e2510a5, 0x3f0a5efd, 0xbe9b8cc2, 0x3df6171a, 
    0xbde4a05e, 0xbe069e25, 0x3e121a5a, 0xbdb3e14c, 0x3dd4332a, 0x3eaa90ba, 0xbe6b9754, 0x3e96f197, 
    0x3dfd1125, 0x3e329038, 0x3e7d05b5, 0x3ed0bd14, 0xbd7f5bed, 0x3eba0cdf, 0x3e6bd75a, 0x3dc4ade4, 
    0x3f0186a6, 0x3e68192a, 0x3acf45d4, 0xbe6e1db5, 0x3c87d37b, 0xbf0fda1a, 0xbe5622eb, 0x3e0f5ca2, 
    0x3e27b263, 0xbc12252c, 0x3ee599a6, 0x3eb99c1d, 0xbe179a20, 0x3d09cfaa, 0xbdacd8b2, 0xbe16e549, 
    0x3e438eb9, 0x3b0b34d0, 0x3d0b9ec0, 0x3e0aba16, 0xbe6ca376, 0x3e6fbf41, 0xbdf95ff8, 0xbde9aa94, 
    0x3d3a1b7f, 0xbe1a3fd4, 0xbd1494b2, 0x3e16c699, 0xbceea9e3, 0xbe4dce53, 0x3e5f5858, 0x3df5d486, 
    0x3f007e0b, 0x3ceaa2b7, 0x3df9a1e9, 0xbe02a992, 0x3e9242f9, 0x3d896374, 0xbde9346e, 0xbe0f398a, 
    0x3eedc709, 0x3ea1ad37, 0xbf221fdd, 0x3ed9d23d, 0x3db24d68, 0xbd48274f, 0xbf0151b6, 0xbea17134, 
    0x3eefafdb, 0x3e03db09, 0x3d188021, 0xbe456eb0, 0x3e492a01, 0x3e26947b, 0xbea32c85, 0x3f2a87aa, 
    0x3ee46527, 0x3ea6563a, 0xbe4ec26b, 0xbc3f7f3a, 0x3dbf3a24, 0xbf26f2ee, 0x3ea1a82f, 0x3c79dcc8, 
    0x3eaced75, 0x3ea0e587, 0x3ea3123c, 0xbe7edba0, 0xbebe9d12, 0xbd7d4700, 0xbd984de1, 0xbde881d8, 
    0xbeff1291, 0xbe860420, 0xbe986415, 0xbe46b917, 0xbf0a94f2, 0x3ea60b21, 0xbe17e38a, 0xbd0813d6, 
    0x3ef197ce, 0x3ea6989a, 0xbe89254e, 0x3e442cd7, 0x3d27a6a3, 0xbe36a715, 0x3ecf9e4c, 0x3eed3ec7, 
    0xbef6b249, 0x3eafd1f0, 0xbe859cf0, 0xbe3bcb12, 0xbd91a9fd, 0xbee2fc9c, 0x3e52a227, 0xbd7cd5d9, 
    0x3e62e418, 0x3dfce964, 0x3e8b6e83, 0xbea39d22, 0xbef7a4b6, 0x3d6f9458, 0x3e8afa26, 0xbe776aef, 
    0xbeae4a7b, 0x3e89622a, 0x3d919f80, 0xbdd16645, 0xbbdb1ec4, 0xbe00a24a, 0xbec3ac8d, 0x3e262928, 
    0x3e135e2e, 0x3e12e426, 0x3e484109, 0xbee5c925, 0x3f0eeea8, 0xbd946116, 0x3cf1ce06, 0x3e89c00d, 
    0x3e6f105b, 0x3e0066a5, 0x3e82c421, 0xbedd38a0, 0xbeb3a185, 0xbe7cc2f1, 0x3e47df42, 0x3db70dd2, 
    0xbea5f0c6, 0x3f021a38, 0x3e2c6590, 0x3e39369f, 0xbf1629f2, 0xbea509fe, 0xbd9a0806, 0xbeb3f070, 
    0x3db64f23, 0x3e9717bb, 0x3da63726, 0x3e0a4323, 0x3e9574b8, 0xbea634c3, 0xbe933006, 0xbe79605a, 
    0x3ed5ed46, 0xbcff796e, 0xbe7cb13d, 0xbea61673, 0x3ecac7d7, 0xbe005d56, 0xbe6d097d, 0x3ead06b8, 
    0x3e8b7d57, 0x3ed9ed52, 0xbe43a840, 0x3ee8b83e, 0xbea12aa2, 0x39bc8892, 0x3e3fad9c, 0x3d9d9938, 
    0x3ec6f524, 0x3e085700, 0x3dd38499, 0x3f095548, 0xbe8d6c1f, 0x3e990b93, 0x3d5e18da, 0xbe83a3f8, 
    0x3e754351, 0xbdc858d0, 0x3d7565b9, 0x3e16bfb4, 0x3e326451, 0x3dfc486f, 0x3b1944f4, 0x3dff6f33, 
    0x3e9a11c7, 0x3d0c3b3d, 0x3eeb45da, 0xbef8d54a, 0xbeba3e77, 0xbe225b47, 0xbd8ee565, 0x3e434d2c, 
    0xbeb5dced, 0x3eaa0aa4, 0x3cda2d59, 0x3e74a7f6, 0x3e8666df, 0x3e039a61, 0xbc281d56, 0xbe81123a, 
    0x3ec6527e, 0xbdaea2ef, 0x3ea65406, 0xbd52219b, 0xbe7f449b, 0xbf1dfe34, 0x3e35542c, 0xbe83312c, 
    0xbc400ed2, 0x3f13d811, 0x3de85198, 0x3e68fbc1, 0x3e9bb732, 0xbea6a499, 0x3cab12f0, 0x3dee8690, 
    0x3e8de6a3, 0xbe682c70, 0xbe3b4755, 0xbc2b0ad7, 0x3c787e61, 0x3db7db69, 0x3e25958f, 0x3f31fd97, 
    0xbeb37a36, 0x3e23ecd3, 0x3eeded4d, 0x3e4bbf88, 0xbd0ccdd0, 0xbc960a75, 0xbcb078e3, 0x3e822527, 
    0xbeb558a7, 0xbdfde995, 0xbe8529b7, 0xbd27cbe4, 0x3e13d606, 0xbef889da, 0xbe256d74, 0x3f07d65d, 
    0x3dd85789, 0xbef0fbc2, 0x3e831208, 0x3ecc7527, 0xbd358090, 0xbc33c4ae, 0x3e8cf268, 0xbeda892a, 
    0xbeefa5b6, 0x3f0a1729, 0xbdb2a8b7, 0x3e1bb6d3, 0xbe8b30fb, 0x3ee4bd76, 0x3da12677, 0xbf1440ac, 
    0xbc03503d, 0x3e515d40, 0xbebb9ed3, 0x3f215630, 0x3e7459c4, 0x3e94a832, 0x3e84691b, 0x3e8c3f44, 
    0xbf11d844, 0x3ee52d1f, 0xbe03a4e3, 0xbe603252, 0xbd8bac81, 0x3ef0390e, 0xbed97a7d, 0xbee0addf, 
    0x3e37c427, 0x3ea0c4f5, 0xbcd3fa5f, 0x3e0e43f2, 0x3f02d570, 0xbe35b0c3, 0x3d742c90, 0xbf13ca61, 
    0xbf00ebd6, 0xbeaf5dd5, 0xbd35b26b, 0xbec0b710, 0xbeb772b1, 0xbe53f717, 0xbf358409, 0xbe5d5061, 
    0xbdcba4dd, 0x3ed0dd97, 0xbee9d514, 0x3ec0211c, 0x3ea37302, 0x3c79ee5e, 0xbf1f66d7, 0x3e840b4c, 
    0x3f08b359, 0xbddf2c8c, 0xbf136c8a, 0xbe5288d2, 0x3f14ca76, 0x3c0dae40, 0x39ff54b9, 0x3e79b22b, 
    0x3da2803b, 0x3e2fde57, 0xbdff5965, 0xbf04a7b1, 0x3edc2ba8, 0xbf13f0ef, 0xbdca7873, 0x3f0e7211, 
    0xbf30c5ce, 0x3eba0226, 0x3b034ed9, 0xbe972181, 0x3e7cbe13, 0x3cab4929, 0xbedc37d8, 0xbe50d977, 
    0xbf362642, 0x3f05a9c8, 0x3e937433, 0x3ea37777, 0xbef06dff, 0x3ec6a034, 0x3e78c21d, 0x3d8a691a, 
    0xbe2c6bf9, 0x3d87c0c9, 0xbee9ed7d, 0x3d7fd5ea, 0xbded8b10, 0xbf32e2ad, 0xbf2fcaed, 0x3e865130, 
    0xbe101ede, 0xbd8ce9f8, 0xbeab1b09, 0xbe5801a7, 0x3e62f62e, 0xbcb6a4b9, 0x3ce77e45, 0x3dc8184f, 
    0xbe321462, 0x3ed1c053, 0xbd247276, 0x3e9c2572, 0x3ea42ead, 0xbdece755, 0xbeaf10d1, 0x3e5238d2, 
    0xbe225188, 0xbd39eb7c, 0xbccb635a, 0xbe29e91d, 0xbe48e1e1, 0x3e06ae3a, 0xbebfe069, 0x3e5c2215, 
    0x3e9862ae, 0x3e457810, 0x3f1e8789, 0x3e32d37c, 0x3ea23279, 0xbdbb4734, 0x3e490ec3, 0xbd909b60, 
    0x3e1fc2f9, 0xbe357e74, 0xbe8cb47c, 0x3c987865, 0x3e6f8831, 0x3e2ee014, 0x3ec90557, 0xbe4d2d00, 
    0x3ea41292, 0xbe1550c8, 0x3d12cb3b, 0x3e116628, 0x3e62520d, 0xbd808076, 0xbe8f677b, 0xbe0e7c95, 
    0x3d8bad1a, 0xbd3c61d8, 0xbd11ba5a, 0xbe4c8ef3, 0x3e2489aa, 0x3f036c11, 0xbdd5cafd, 0xbdef2234, 
    0x3ea52481, 0xbe4c6d06, 0x3eb24c90, 0x3e945d40, 0xbe0d516e, 0x3ed33f4e, 0xbe671ece, 0x3d966bfa, 
    0xbe9aeab1, 0xbe7fd189, 0xbdd2b5e5, 0x3dbea1cb, 0xbe2a3633, 0x3ea1bdee, 0xbe80e756, 0x3ece42db, 
    0x3e1ae0e5, 0x3edcabc5, 0x3e90e512, 0x3dd4d2be, 0x3eb31b9b, 0x3e3849dc, 0xbcbb4b1e, 0x3e256de2, 
    0xbe217c26, 0xbec1e536, 0xbe6ea8f3, 0xbd0dd4c3, 0xbd11d30b, 0x3edb2c75, 0x3d8dd331, 0xbe5f2ced, 
    0xbcc760c0, 0xbe842d2b, 0x3e4c4b8c, 0xbe32f940, 0x3e28aaa4, 0x3ec98253, 0x3d2b1b65, 0xbe059d19, 
    0x3e0a8d75, 0xbe858246, 0x3dcc303e, 0xbecc4ff6, 0xbe677633, 0x3e7352f1, 0x3ed571a1, 0x3d4a7b58, 
    0x3e5e79ba, 0x3e882744, 0x3b938e13, 0xbe6f685c, 0xbcf38b6f, 0x3e195799, 0x3e5d55f9, 0xbdd518a5, 
    0x3d383181, 0x3ecb4988, 0xbc7aaea3, 0x3c9867ff, 0x3e22a262, 0xbebbbe73, 0x3da30b09, 0x3f08bcaa, 
    0x3e9ba85d, 0x3d171a5f, 0xbe7c9aa4, 0xbe045f9f, 0xbe893ca7, 0x3dcdbfe7, 0x3debf5be, 0xbddfdb5b, 
    0x3e44bccd, 0xbca9665e, 0x3e9e5975, 0xbe47364f, 0x3e342cd9, 0x3e90d4d0, 0x3d8fce4d, 0xbeac7d3f, 
    0xbe67b581, 0x3e890ba7, 0xbeb1f92d, 0xbea67f89, 0xbeb38547, 0x3d635453, 0xbe0b69cd, 0x3df41011, 
    0xbea6e712, 0x3eae1d2c, 0xbeb3ed50, 0xbe64d08d, 0xbcc5aa53, 0x3de48512, 0xbe707f8e, 0x3e6a4fbb, 
    0xbdc077f4, 0xbc52d36e, 0xbe04e86f, 0xbddeaa14, 0xbc15875f, 0xbee7f9ff, 0x3e69d517, 0xbe054a7a, 
    0xbdfbbd2a, 0xbe454cd1, 0x3e52b073, 0xbe94eef2, 0x3e7adfc6, 0x3ea75ce5, 0x3c806c75, 0x3e87f2a2, 
    0xbe126616, 0x3e8783a7, 0x3e89a24c, 0x3e5e3129, 0xbec915f7, 0xbe591fe3, 0x3e16de86, 0x3e1d33e7, 
    0x3dc3ef85, 0x3e462a30, 0x3df4c015, 0xbe426d86, 0x3e889b20, 0xbe862edb, 0xbe8ca101, 0x3eaa47e6, 
    0x3c003323, 0x3e0b8f33, 0x3e6949f2, 0xbde81115, 0xbd3dbc37, 0x3dabb543, 0xbd503400, 0xbe354787, 
    0xbec0fa9d, 0xbe98edfb, 0x3ded84f8, 0x3ec476b3, 0x3e07eb03, 0x3c07fa73, 0xbe9f3856, 0x3ef0004a, 
    0x3e142781, 0xbe5a0f68, 0xbd1fda6d, 0x3f075894, 0x3d0e975b, 0xbe969bb7, 0xbee31dc2, 0xbe174425, 
    0x3e367f59, 0x3c17d87f, 0xbde3978e, 0x3dc328b4, 0xbe9d8e3f, 0x3f1eaaab, 0x3ec36af0, 0x3e93bd36, 
    0x3e4ab398, 0x3f254408, 0xbcf738da, 0x3e5bb09a, 0xbe908c37, 0x3e278d74, 0xbd917d42, 0x3eaa7b38, 
    0xbf04b9cf, 0xbe33334b, 0x3d843e99, 0x3def756f, 0xbe353013, 0x3e585ebc, 0xbeb557ca, 0x3ca28b9c, 
    0xbe8e58c8, 0xbea6ed6a, 0xbe487ca9, 0xbe78d3e6, 0xbd90fab4, 0x3d4fa27c, 0x3e88bc9a, 0xbeaa38ae, 
    0xbf143253, 0x3e9cc3f7, 0xbd8c4b48, 0x3e85d975, 0x3d76e77b, 0xbe5588af, 0xbe25f297, 0x3dd113f9, 
    0x3d44e857, 0xbdccd216, 0x3ee1695c, 0xbe75d377, 0xbf2b9196, 0x3d866f44, 0x3e6781e5, 0xbdb5d83b, 
    0xbd54e337, 0x3cfb1dbb, 0x3f048679, 0x3db7c0e3, 0x3e2cceac, 0xbe686857, 0x3db0e330, 0xbe0390cc, 
    0xbd6360cf, 0x3e92055f, 0x3eae36cc, 0x3d8525bf, 0xbf04cee2, 0x3e7986e4, 0xbecf915d, 0xbf077b28, 
    0x3ef65335, 0xbd8a481e, 0xbec1c462, 0xbc5e5e5a, 0xbc80c364, 0x3ed33786, 0x3f1f0fbd, 0xbea0570f, 
    0xbe50625a, 0x3eec4e19, 0xbddabb8f, 0x3d62923b, 0xbe8ced0e, 0x3db2c3cf, 0xbe432bb8, 0xbd08e7c8, 
    0xbccc3427, 0x3f00b38d, 0xbe9509e6, 0xbdb4dcbc, 0x3ebf4ca2, 0x3e5b5adc, 0x3eafbda5, 0x3e8f8b3d, 
    0x3a8a3ce9, 0x3c2d5d10, 0xbe0f5795, 0x3eb9748d, 0xbd038352, 0x3b0b15c4, 0x3f231f70, 0xbc243067, 
    0xbf043686, 0xbd478782, 0x3e085f02, 0xbea5e20b, 0xbe47d9b0, 0x3cb80262, 0x3e890071, 0xbe82bc0e, 
    0xbd8009c2, 0x3ecb3ffd, 0x3e67c3f5, 0x3ec4130d, 0x3ecbf192, 0xbdb77aa9, 0x3e09674a, 0xbeb4e8f2, 
    0x3eab6a60, 0xbceee7a6, 0x3cfbfd8c, 0xbf05205a, 0xbebf1f8a, 0x3d078ae5, 0x3e85c787, 0xbebb2fe6, 
    0xbdb9fc73, 0xbed48c6a, 0xbe35e87a, 0xbe8d3153, 0x3e2f1766, 0xbf0ab139, 0xbd2f79e1, 0x3eb394ce, 
    0xbe8e2784, 0x3e8b1296, 0xbebe2bb9, 0xbdb2caf1, 0x3e849ac2, 0xbe4063e1, 0xbe415ed7, 0xbd87cf9a, 
    0xbedd5cf4, 0xbe6f75ed, 0xbe6585dd, 0xbe96e970, 0x3ef88f84, 0x3e6c31a1, 0x3da1d847, 0xbdd40a27, 
    0xbe10bf89, 0x3e7826a1, 0x3eec576c, 0x3cb3d4b9, 0xbd9bce9e, 0x3e35ec9e, 0xbeb6af83, 0xbe846222, 
    0x3ef93377, 0xbef59f9c, 0x3d233d1a, 0xbc1a4e1d, 0x3e8a3a71, 0x3ec78059, 0x3ef0112e, 0x3e7c74e6, 
    0xbdd42964, 0x3e806488, 0xbde553be, 0xbe802103, 0x3f5a250f, 0x3e9dee94, 0x3e7feb14, 0x3d216d97, 
    0x3e81c665, 0xbdb0a647, 0xbea03b88, 0x3e8e3ebb, 0x3ee8c0dc, 0xbe3254fb, 0xbebd3310, 0xbef3c66d, 
    0xbe19f9e0, 0x3db61221, 0xbeabe9b1, 0x3e80e84d, 0xbd395aba, 0x3ecafdc6, 0x3e790fcb, 0xbdae86ed, 
    0xbedc4189, 0xbed33fc5, 0xbe544054, 0xbe38b038, 0xbf0d89c3, 0x3ec0f754, 0x3e50708a, 0xbecd5928, 
    0x3e950362, 0x3ead31a5, 0x3f14438f, 0xbe5db75d, 0x3d73b0ac, 0x3ed4ebcf, 0x3e4ae08b, 0x3e8f645a, 
    0xbd9e694f, 0xbe25ea00, 0x3b2ee396, 0xbddaf091, 0xbe30b1b1, 0xbf07e132, 0x3db1b3c6, 0x3d3a02a0, 
    0x3d95b80e, 0xbdf9311b, 0xbeadceaa, 0xbe4c2d24, 0xbd054e28, 0x3e7a35ec, 0x3e4051b5, 0xbebd5b00, 
    0x3e33465f, 0x3efb6cb1, 0xbe8e1c1d, 0xbd7de2cf, 0xbf092ad2, 0x3d487ab3, 0xbe881f21, 0xbf203b68, 
    0xbe6189c3, 0x3e80219d, 0x3f0054cd, 0xbed6bc47, 0x3f17f312, 0xbeaafe80, 0xbeafe105, 0xbdfd52d1, 
    0xbecf5765, 0x3d4b2127, 0xbee51b83, 0xbeb4c91c, 0xbd999357, 0x3e8b7018, 0xbe9ac16a, 0x3d9b7d35, 
    0xbdddf451, 0xbef77f5a, 0x3e0df294, 0x3e69e933, 0x3f07291e, 0x3eb2b25a, 0xbefa1d5f, 0x3e5797db, 
    0xbd99193e, 0xbedfc6b3, 0xbe47edc8, 0xbc9911d6, 0x3b1b427f, 0x3f0a7786, 0x3ea33be8, 0xbe7beb05, 
    0x3ec932b0, 0x3f150f01, 0x3f18dfc5, 0x3d8d280b, 0x3f149558, 0x3d9863a6, 0x3b78618a, 0xbc834f16, 
    0x3e7dbd54, 0xbeb240b4, 0x3e494c85, 0xbe7f7a21, 0x3e1106e2, 0xbe510246, 0xbed8cde2, 0x3e228786, 
    0xbddcf7d1, 0x3f4b8f91, 0xbe9fe446, 0xbe4dc372, 0x3ea30b39, 0x3f30033f, 0xbe57180a, 0xbce56c22, 
    0xbc786834, 0xbec986aa, 0x3e44d68c, 0x3e042c24, 0x3ea198e2, 0x3dc39d8a, 0x3ebbab46, 0xbe9de629, 
    0xbdf5b711, 0x3e8b5c3f, 0x3e0dbd82, 0xbea43f39, 0xbf05a89b, 0xbda79b00, 0x3eb1f109, 0x3a842575, 
    0x3d309615, 0x3e56a8b8, 0xbe95b010, 0x3f4bfe76, 0xbc82de86, 0x3f047fbb, 0xbeccae21, 0x3ef2bd46, 
    0x3e63db5c, 0x3efe7457, 0x3e830fd5, 0xbeb6b4fa, 0xbf1bd487, 0x3e52b01d, 0x3e9e0422, 0x3f11d1a6, 
    0x3ddf49bd, 0x3e9c5fdf, 0x3ef51212, 0x3e950cf9, 0xbe9d6ea4, 0x3e5882ee, 0x3c43149e, 0xbe97c045, 
    0x3e9be78f, 0xbe57e8ba, 0x3e1c6c49, 0xbebb6db4, 0xbf400d67, 0xbea0e1a7, 0x3e947ebe, 0xbf03b64f, 
    0xbe679f36, 0x3ece5b20, 0x3d3645a3, 0x3e4dcb89, 0xbcc4c245, 0x3e0b0bf7, 0x3efdf20b, 0x3c854b5d, 
    0xbd001ef1, 0x3f33c21a, 0xbcb84f34, 0xbe3f57b5, 0xbf28a6e8, 0xbe5db92d, 0x3d881f36, 0xbcb81a00, 
    0x3ee488db, 0x3de73cf4, 0x3e061be9, 0x3f0f870f, 0x3e8da8f5, 0xbce02f21, 0x3e94e987, 0x3e9f5f80, 
    0x3eae631b, 0x3e1768a2, 0x3eb0729d, 0x3d89415c, 0xbc8cf305, 0xbe255cde, 0x3e4fd910, 0x3ececdcf, 
    0xbd1f8877, 0xbf1ef120, 0x3cb39c50, 0x3f55bdef, 0x3c89eb8f, 0xbc84cae8, 0xbe9549cc, 0x3e6f6a6d, 
    0x3f6c72c2, 0x3df7b0ac, 0xbf3a6feb, 0xbec009c6, 0xbd9190ec, 0x3ea8a414, 0x3ec38e65, 0xbebbb891, 
    0xbe4f31dd, 0x3eb37342, 0xbecaf756, 0xbd425e7f, 0x3f4410d1, 0x3e89fab0, 0xbe341e3e, 0x3eead42c, 
    0xbcb422a6, 0xbb82c262, 0xbe00416a, 0xbe2f6dd0, 0x3ebbbfaf, 0xbe989f6a, 0x3ee56a8b, 0xbdb2871c, 
    0x3ea997b8, 0xbee94173, 0xbe61b994, 0xbe17c609, 0x3e96b9d7, 0xbec2a739, 0xbe13d74b, 0x3efeec6f, 
    0xbee2fc65, 0xbce460ba, 0xbf573b51, 0x3f2041e0, 0x3ec900a6, 0xbe8f7d34, 0xbe8d6609, 0xbd835b72, 
    0x3e6655b0, 0xbd0c2aeb, 0xbf30b64a, 0xbe8514a7, 0xbe2594df, 0x3eb630cc, 0x3e21c94f, 0x3dc59ed8, 
    0xbe04437e, 0xbf5bd57e, 0xbec6c7ab, 0xbeba2c22, 0xbf0faeb2, 0x3ef6ee1b, 0xbe3385cd, 0xbec9f962, 
    0x3e41e910, 0xbe7e546f, 0xbe9d585b, 0xbf201468, 0x3eb91bdc, 0xbf04c312, 0x3e9534ef, 0x3ee75579, 
    0x3eec323b, 0xbea1d991, 0xbec55b57, 0x3f3b4ce8, 0x3e0c75fd, 0x3c7e6d76, 0xbe3b8e01, 0x3ef344c7, 
    0xbe8b5d28, 0xbc0bf51e, 0xbe8a1521, 0x3ebd36bb, 0x3d982837, 0x3e9ca674, 0x3ea90881, 0xbed45040, 
    0x3ddd15ea, 0x3e27be4f, 0x3ee81e85, 0x3e80c9f6, 0xbe84efb8, 0xbf0995cb, 0xbe49c023, 0xbf14bd88, 
    0x3ed96cdc, 0x3e6c93b6, 0x3e0debc5, 0x3d5695c9, 0x3f0f587b, 0xbf455da2, 0x3e6adb97, 0xbd68282e, 
    0x3e6ac0c2, 0x3c8f774a, 0xbe43e67a, 0xbdfbaa46, 0xbe9037fb, 0x3e6553ff, 0x3f47ec40, 0xbe8baa91, 
    0xbe789e19, 0xbef859aa, 0xbe0e2c23, 0x3ebad608, 0x3ec647ba, 0xbe185757, 0xbecf2ec3, 0x3d453dd5, 
    0x3d708489, 0xbeb633b3, 0xbc99c705, 0x3f08ff6a, 0x3be20594, 0x3ea4eec0, 0xbeb6ada9, 0x3ead9d5b, 
    0xbe923633, 0x3eba4314, 0x3ef74e55, 0xbe235c60, 0x3c7ccdd4, 0x3e3bc059, 0xbec4e51d, 0xbeecd874, 
    0x3ecfdaa7, 0xbe64ed72, 0xbd56be18, 0xbe1df61c, 0x3eaf3451, 0x3e065e21, 0x3f03ac94, 0xbe817410, 
    0x3cb1a6e3, 0x3e21a969, 0x3e091456, 0xbe9f0d9d, 0xbee6f85b, 0x3e1a6b5c, 0xbf33ee0f, 0x3da7ac17, 
    0xbeb55ce9, 0x3e279739, 0x3d9b09c9, 0xbe7ed077, 0x3e496832, 0x3ea4e427, 0x3c3129b1, 0xbed5b8e9, 
    0x3ebb5462, 0xbe07cab0, 0xbddcceb4, 0x3e4ddec3, 0xbe085316, 0xbeed26aa, 0x3eb9a436, 0xbf64777c, 
    0xbd17d59c, 0x3dc90c48, 0xbc8b3c7a, 0xbef478bf, 0xbe8f161c, 0x3e93a0da, 0x3e8ba093, 0xbee1e7d1, 
    0x3ed6763c, 0x3e3ee806, 0xbeacd043, 0x3d756d39, 0x3d04c8bc, 0xbed8a557, 0xbe7919b7, 0x3de08959, 
    0x3e8e897c, 0xbf08664c, 0xbee399c6, 0x3ee8eb0d, 0xbe46e6d6, 0xbd6bc776, 0xbc806ee4, 0x3eebd74d, 
    0x3ec5290c, 0x3e74d106, 0x3eebf368, 0xbee5fa4f, 0x3f034258, 0x3ec65694, 0xbedaef25, 0xbe763068, 
    0x3c29956d, 0xbf2d9737, 0x3e367ea8, 0x3e613905, 0xbd2e74ad, 0xbf03e14c, 0xbe22f567, 0x3d9eae45, 
    0x3e6ef2a0, 0x3ec34867, 0x3dbe410e, 0x3ee4a268, 0xbedd1c6c, 0xbe54dc45, 0xbeb1f75b, 0x3ecc1890, 
    0xbea7ce03, 0xbe798798, 0xbedfb815, 0x3f15b33f, 0xbde6ad69, 0x3c187311, 0x3f2c23fe, 0x3db3dd9a, 
    0x3e47a137, 0x3ec754a3, 0x3e89edb1, 0xbd6878f7, 0xbe6e8c57, 0x3e9337bc, 0x3e1068a5, 0x3e793554, 
    0xbefe2e81, 0x3c8e3852, 0x3f2df1f9, 0x3f177f03, 0xbe523fd9, 0xbe80f0fa, 0x3b11f37e, 0xbbaa5ace, 
    0xbe65dc06, 0x3da194dd, 0x3e9f3787, 0x3ef878a6, 0xbedeb1af, 0xbec839ee, 0xbe6835ba, 0xbcfd5fcd, 
    0x3f003722, 0x3f412de6, 0xbe993243, 0xbe019125, 0x3ddfb7e3, 0xbcc4d087, 0x3e44e328, 0xbee9105c, 
    0xbe3327f8, 0x3cbe46fb, 0x3d1d6e12, 0x3cb7ce5d, 0xbe8f8b2c, 0xbd089d64, 0x3e140b58, 0x3e73c816, 
    0xbec98c1a, 0xbe5ca19a, 0x3def2078, 0xbf02ff7f, 0xbe9b958a, 0x3eca251a, 0xbed88311, 0xbea3620d, 
    0xbf1b83c2, 0xbdbf7c32, 0x3eef8e9f, 0x3e5aeb6c, 0x3cf28802, 0xbcfe64e8, 0xbdc9c990, 0x3e1e8a27, 
    0x3f247596, 0x3d19514c, 0xbd1e28d3, 0xbd71755b, 0xbebe3a5f, 0xbdc9ca31, 0xbdc82c10, 0x3cf5ebe0, 
    0xbcd735d5, 0xbe3198dd, 0xbe837648, 0xbc823a06, 0x3eec2266, 0xbeaa75d8, 0xbe833afe, 0x3e36a4e7, 
    0x3ef15a8c, 0xbe5a80b3, 0xbe807e95, 0x3ec13420, 0x3db9fe4a, 0xbdd7aa41, 0x3e4e5cd8, 0x3f05e33a, 
    0x3e453ec4, 0x3d7698d2, 0x3e9eaa84, 0xbd04dab7, 0x3efae2bb, 0xbe8beaca, 0xbea9a46f, 0xbe807e3c, 
    0xbe80ee72, 0xbe9f2d7d, 0x3c488a0d, 0xbe90bc1e, 0xbeefcf56, 0x3dcbee54, 0x3dfb70ea, 0xbef5cb99, 
    0xbd0397ff, 0x3e128b84, 0xbb9e98fd, 0x3f15f935, 0x3eb5c5e4, 0x3f309f4d, 0x3e29136e, 0xbe6daed2, 
    0xbde76252, 0x3c962d29, 0x3d41ba5d, 0x3de9afeb, 0xbe91ec46, 0x3b052f5d, 0x3e8a2482, 0xbe31e3d7, 
    0x3efe1217, 0xbdcad0ec, 0xbe73509a, 0x3d65c2ec, 0x3e603ecc, 0x3e1d0933, 0x3e14e4f6, 0xbe6d2167, 
    0xbefa7cd8, 0x3deb2579, 0xbda47aca, 0xbe1383d6, 0xbe95e431, 0xbd19ff57, 0xbe0ac912, 0xbe11bf49, 
    0xbe8a1ad5, 0x3b8593e5, 0x3d399f4a, 0x3e45d5d0, 0x3e7bea5f, 0x3e4f0c37, 0xbeb7d74c, 0xbdc881a1, 
    0x3eaf4712, 0xbd9eb767, 0xbe8681af, 0x3eb375eb, 0x3d468d9a, 0xbcb681cd, 0xbccacd79, 0x3d60017e, 
    0xbe2fbeb6, 0xbe14575b, 0x3f0a36b4, 0x3f048ad5, 0x3f110933, 0x3e2d0266, 0xbe9ce957, 0x3ec3370c, 
    0xbecb4c59, 0xbeeca37f, 0x3f10f5c5, 0x3dc60064, 0xbd148b4b, 0xbd98247d, 0xbe854875, 0x3ecfd371, 
    0xbe5aebf3, 0xbd8820bd, 0x3da885b8, 0xbe854383, 0xbdcc8982, 0x3db182c1, 0xbe97ed40, 0xbd4e9887, 
    0xbdd26b73, 0xbd964879, 0x3cc63be6, 0xbe99ad19, 0x3e8f8eda, 0x3ee1eaa3, 0xbd2b7565, 0xbe3f380b, 
    0xbec02e78, 0x3ee3c90e, 0xbe9c7171, 0xbe23a8d5, 0xbedad3b7, 0xbe9e7358, 0xbda874a1, 0xbd54b3be, 
    0xbe2ba3a0, 0xbe1c6729, 0x3e9fd8c7, 0x3dd17189, 0xbeac008e, 0x3e67f5a6, 0x3e1d239a, 0x3edfe96f, 
    0xbbabb9c5, 0xbc95a0c8, 0xbef26ef9, 0x3dea92e1, 0xbe4d7eac, 0x3e0953a2, 0xbe1cd315, 0x3df691c8, 
    0xbebc48b0, 0xbef3ef32, 0x3f05d45c, 0x3db4754f, 0x3ea3da50, 0x3e0b52b8, 0x3e010b4e, 0x3d8fcfb8, 
    0x3eabc35e, 0xbecb1ae0, 0xbe9e5afe, 0xbe8512e9, 0xbdd668a9, 0x3f08dcc5, 0x3ebff43e, 0xbef8e2d1, 
    0x3e1b982c, 0xbe173e6d, 0xbd9c6f7a, 0xbd6ef8ba, 0xbf05588a, 0xbe3fa774, 0x3e4368cb, 0xbeb09d4a, 
    0xbdc1b920, 0x3db16f2b, 0x3e1faa5f, 0xbe05e218, 0xbedbd8ec, 0xbd9f0939, 0xbd81de97, 0xbdde686c, 
    0x3eb5f0c0, 0xbe413cb4, 0x3db8b75c, 0xbd97b581, 0xbe57fdd2, 0x3ebc0669, 0x3eb73772, 0x3d2a3433, 
    0x3c122c8c, 0x3e6acbaf, 0x3995657c, 0x3d2b30b7, 0xbda4edbc, 0x3eb8d8ec, 0x3e4fe19d, 0x3e9dd43b, 
    0xbd7db257, 0x3ec2882e, 0xbc85c5f6, 0xbd72ae53, 0xbe272f57, 0x3ed59640, 0xbdb3a900, 0x3e83adfe, 
    0x3dade8ac, 0xbe209868, 0xbee80cf0, 0xbe8a17df, 0x3d8b9346, 0xbdfcc097, 0xbe1f9a2f, 0xfffffe26, 
    0x00000004, 0x00000040, 0xc025477e, 0xbf6c11fd, 0x3f9dfad8, 0x3f1d50ac, 0x3e8c4550, 0xbf89a7d6, 
    0x3fdac3c0, 0x3f9333a8, 0xc02450a0, 0x3fca6042, 0x3e844ff0, 0x400a419c, 0x3f0eb381, 0xc043436b, 
    0xbea750e0, 0xbfe69396, 0xfffffe72, 0x00000004, 0x00000040, 0xbe09cb3b, 0xbfb21c35, 0x3f8a7574, 
    0xbf138fa1, 0x3b861cac, 0xbfd921f2, 0x3f67db94, 0xbf7e4ade, 0x3fd0c892, 0xbfb9e0a3, 0x3f70d40c, 
    0x3f2add86, 0xbd830456, 0x3fa8d068, 0xbfa89fb8, 0xbf3a0526, 0xfffffebe, 0x00000004, 0x00000080, 
    0xbf448c6e, 0x3f19d38c, 0x3f866586, 0xbf2a3aa4, 0xbe00d242, 0xbf5b9282, 0xbfa14761, 0xbe915e7c, 
    0x3e205a99, 0xbf44c51c, 0xbf90cbb4, 0xbd81a43f, 0xbeefe7fc, 0xbfd69896, 0xbe3de613, 0x3f1d7be1, 
    0xbf54035b, 0xc003f8a3, 0x3f124520, 0xbfaa9055, 0x3f0682fa, 0xbf2bcc25, 0xbe054c1a, 0x3e1a332a, 
    0x3eb44d2a, 0x3f42d614, 0xbfef168a, 0x3fbb73ae, 0x3e881dc1, 0xbe1702b4, 0x3f299332, 0x3e6efd70, 
    0xffffebe8, 0xffffebec, 0x0000000f, 0x52494c4d, 0x6e6f4320, 0x74726576, 0x002e6465, 0x00000001, 
    0x00000014, 0x000e0000, 0x00140018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000014, 0x0000001c, 
    0x000003dc, 0x000003e0, 0x000003e4, 0x00000004, 0x6e69616d, 0x00000000, 0x00000010, 0x000003a0, 
    0x00000344, 0x000002e4, 0x000002a0, 0x0000025c, 0x00000238, 0x000001e4, 0x000001c0, 0x0000017c, 
    0x00000138, 0x00000114, 0x000000d0, 0x000000ac, 0x00000078, 0x00000040, 0x00000004, 0xfffffd06, 
    0x0000001c, 0x09000000, 0x0000001c, 0x00000020, 0x00000005, 0x00060000, 0x00040008, 0x00000006, 
    0x3f800000, 0x00000001, 0x00000024, 0x00000001, 0x00000023, 0xfffffd3e, 0x00000014, 0x08000000, 
    0x00000010, 0x00000014, 0x00000004, 0xffffecd4, 0x00000001, 0x00000023, 0x00000003, 0x00000022, 
    0x00000011, 0x00000012, 0xfffffd72, 0x00000014, 0x1b000000, 0x00000010, 0x00000014, 0x00000003, 
    0xffffed08, 0x00000001, 0x00000022, 0x00000002, 0x00000021, 0x00000013, 0xfffffd46, 0x00000008, 
    0x0000000c, 0x00000001, 0x00000021, 0x00000002, 0x00000020, 0x00000008, 0xfffffdc2, 0x00000014, 
    0x05000000, 0x00000024, 0x00000028, 0x00000002, 0xfffffefe, 0x00000002, 0x00000001, 0x00000002, 
    0x00000001, 0x01000000, 0x00000001, 0x00000020, 0x00000001, 0x0000001f, 0xfffffda6, 0x00000008, 
    0x0000000c, 0x00000001, 0x0000001f, 0x00000002, 0x0000001e, 0x00000009, 0xfffffe22, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xfffffe70, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x0000001e, 0x00000003, 0x0000001d, 0x00000004, 0x00000001, 0xfffffe62, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xfffffeb0, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x0000001d, 0x00000003, 0x0000001c, 0x0000000c, 0x0000000d, 0xfffffe46, 0x00000008, 
    0x0000000c, 0x00000001, 0x0000001c, 0x00000002, 0x0000001b, 0x0000000a, 0xfffffec2, 0x00000024, 
    0x05000000, 0x00000034, 0x00000038, 0x00000002, 0x000e0000, 0x00170018, 0x000c0010, 0x00040008, 
    0x0000000e, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x01000000, 0x00000001, 0x0000001b, 
    0x00000001, 0x0000001a, 0xfffffeb6, 0x00000008, 0x0000000c, 0x00000001, 0x0000001a, 0x00000002, 
    0x00000019, 0x0000000b, 0xffffff32, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xffffff80, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x00000019, 0x00000003, 0x00000018, 
    0x00000005, 0x00000002, 0xffffff72, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xffffffc0, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x00000018, 0x00000003, 0x00000017, 
    0x0000000e, 0x0000000f, 0xffffffb2, 0x00000020, 0x01000000, 0x00000028, 0x0000002c, 0x00000001, 
    0x0010000c, 0x000c0000, 0x00070008, 0x0000000c, 0x01000000, 0x00000001, 0x00000002, 0x00000001, 
    0x00000017, 0x00000003, 0x00000016, 0x00000006, 0x00000003, 0x000e0000, 0x0014001a, 0x000c0010, 
    0x0004000b, 0x0000000e, 0x00000020, 0x01000000, 0x00000028, 0x0000002c, 0x00000001, 0x000a0000, 
    0x000f0010, 0x00040008, 0x0000000a, 0x00000001, 0x00000002, 0x01000000, 0x00000001, 0x00000016, 
    0x00000003, 0x00000015, 0x00000010, 0x00000007, 0x000a0000, 0x0000000c, 0x00040008, 0x0000000a, 
    0x00000008, 0x0000000c, 0x00000001, 0x00000015, 0x00000002, 0x00000000, 0x00000014, 0x00000001, 
    0x00000024, 0x00000001, 0x00000000, 0x00000025, 0x00000fd0, 0x00000f7c, 0x00000f40, 0x00000f04, 
    0x00000ebc, 0x00000e74, 0x00000e2c, 0x00000df0, 0x00000db0, 0x00000d58, 0x00000d18, 0x00000cd4, 
    0x00000c88, 0x00000c48, 0x00000bfc, 0x00000bbc, 0x00000b70, 0x00000b2c, 0x00000aec, 0x00000aac, 
    0x00000a40, 0x000009cc, 0x00000900, 0x000007c8, 0x00000700, 0x000005c8, 0x0000055c, 0x000004f4, 
    0x00000480, 0x000003b4, 0x00000278, 0x0000020c, 0x000001a4, 0x00000140, 0x000000e0, 0x00000050, 
    0x00000004, 0xfffff0da, 0x01000000, 0x00000010, 0x00000010, 0x00000025, 0x00000028, 0xfffff0c4, 
    0x00000019, 0x74617453, 0x6c756665, 0x74726150, 0x6f697469, 0x4364656e, 0x3a6c6c61, 0x00000030, 
    0x00000002, 0x00000001, 0x0000000a, 0xfffff122, 0x01000000, 0x00000010, 0x00000010, 0x00000024, 
    0x0000006c, 0xfffff10c, 0x0000005e, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f39315f, 0x4d74614d, 0x6d3b6c75, 0x6c65646f, 
    0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 
    0x422f3931, 0x41736169, 0x00006464, 0x00000002, 0x00000001, 0x0000000a, 0xfffff1ae, 0x01000000, 
    0x00000010, 0x00000010, 0x00000023, 0x0000003c, 0xfffff198, 0x0000002c, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f38315f, 
    0x6e61654d, 0x00000000, 0x00000002, 0x00000001, 0x00000020, 0xfffff20a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000022, 0x0000003c, 0xfffff1f4, 0x0000002f, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f36315f, 0x65757153, 
    0x00657a65, 0x00000003, 0x00000001, 0x00000003, 0x00000020, 0xfffff26a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000021, 0x0000003c, 0xfffff254, 0x0000002f, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f36315f, 0x5078614d, 
    0x006c6f6f, 0x00000004, 0x00000001, 0x00000003, 0x00000001, 0x00000020, 0xfffff2ce, 0x01000000, 
    0x00000010, 0x00000010, 0x00000020, 0x00000040, 0xfffff2b8, 0x00000032, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f36315f, 
    0x61707845, 0x6944646e, 0x0000736d, 0x00000004, 0x00000001, 0x00000006, 0x00000001, 0x00000020, 
    0xfffff336, 0x01000000, 0x00000010, 0x00000010, 0x0000001f, 0x00000110, 0xfffff320, 0x00000103, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x2f35315f, 0x756c6552, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 
    0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x34315f72, 0x7461622f, 0x6f6e6863, 0x612f6d72, 
    0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 
    0x2f312d64, 0x6579616c, 0x33315f72, 0x6e6f432f, 0x2f443176, 0x65757153, 0x3b657a65, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x2f34315f, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x33315f72, 0x6e6f432f, 
    0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x00000006, 0x00000020, 0xfffff46e, 0x01000000, 
    0x00000010, 0x00000010, 0x0000001e, 0x000000a0, 0xfffff458, 0x00000092, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f32315f, 
    0x756c6552, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 
    0x2f312d64, 0x6579616c, 0x31315f72, 0x6e6f432f, 0x2f443176, 0x65757153, 0x3b657a65, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x2f31315f, 0x766e6f43, 0x00004431, 0x00000004, 0x00000001, 0x00000001, 0x00000006, 0x00000020, 
    0xfffff536, 0x01000000, 0x00000010, 0x00000010, 0x0000001d, 0x00000048, 0xfffff520, 0x00000039, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x2f31315f, 0x766e6f43, 0x452f4431, 0x6e617078, 0x6d694464, 0x00000073, 0x00000004, 
    0x00000001, 0x00000001, 0x00000006, 0x00000010, 0xfffff5a6, 0x01000000, 0x00000010, 0x00000010, 
    0x0000001c, 0x0000003c, 0xfffff590, 0x0000002e, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x4d2f395f, 0x6f507861, 0x00006c6f, 
    0x00000004, 0x00000001, 0x00000006, 0x00000001, 0x00000010, 0xfffff60a, 0x01000000, 0x00000010, 
    0x00000010, 0x0000001b, 0x00000040, 0xfffff5f4, 0x00000031, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x452f395f, 0x6e617078, 
    0x6d694464, 0x00000073, 0x00000004, 0x00000001, 0x0000000c, 0x00000001, 0x00000010, 0xfffff672, 
    0x01000000, 0x00000010, 0x00000010, 0x0000001a, 0x0000010c, 0xfffff65c, 0x000000fe, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x522f385f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x622f375f, 0x68637461, 0x6d726f6e, 0x6464612f, 0x6d3b315f, 
    0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 0x616c2f31, 
    0x5f726579, 0x6f432f36, 0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f375f72, 0x63746162, 
    0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 
    0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f365f72, 0x766e6f43, 0x00004431, 0x00000004, 
    0x00000001, 0x00000001, 0x0000000c, 0x00000010, 0xfffff7a6, 0x01000000, 0x00000010, 0x00000010, 
    0x00000019, 0x0000009c, 0xfffff790, 0x0000008f, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x522f355f, 0x3b756c65, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x432f345f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 0x6d2d6431, 
    0x75696465, 0x61622d6d, 0x636e616c, 0x312d6465, 0x79616c2f, 0x345f7265, 0x6e6f432f, 0x00443176, 
    0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000010, 0xfffff86a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000018, 0x0000010c, 0xfffff854, 0x000000fe, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x522f335f, 0x3b756c65, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x622f325f, 0x68637461, 0x6d726f6e, 0x6464612f, 0x6d3b315f, 0x6c65646f, 0x6e6f632f, 
    0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f31, 
    0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 
    0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f325f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 
    0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 
    0x2f312d64, 0x6579616c, 0x2f315f72, 0x766e6f43, 0x00004431, 0x00000004, 0x00000001, 0x00000001, 
    0x0000000c, 0x00000010, 0xfffff99e, 0x01000000, 0x00000010, 0x00000010, 0x00000017, 0x000000a0, 
    0xfffff988, 0x00000093, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x422f305f, 0x41736169, 0x6d3b6464, 0x6c65646f, 0x6e6f632f, 
    0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f30, 
    0x4431766e, 0x7571532f, 0x657a6565, 0x6f6d3b3b, 0x2f6c6564, 0x766e6f63, 0x6d2d6431, 0x75696465, 
    0x61622d6d, 0x636e616c, 0x312d6465, 0x79616c2f, 0x305f7265, 0x6e6f432f, 0x00443176, 0x00000004, 
    0x00000001, 0x00000001, 0x00000018, 0x0000000d, 0xfffffa66, 0x01000000, 0x00000010, 0x00000010, 
    0x00000016, 0x00000048, 0xfffffa50, 0x00000039, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x432f305f, 0x31766e6f, 0x78452f44, 
    0x646e6170, 0x736d6944, 0x00000031, 0x00000004, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 
    0xfffffcd6, 0x01000000, 0x00000014, 0x00000014, 0x00000015, 0x02000000, 0x00000048, 0xfffffac4, 
    0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x432f305f, 0x31766e6f, 0x78452f44, 0x646e6170, 0x736d6944, 0x00000000, 
    0x00000001, 0x00000004, 0xfffffd3e, 0x01000000, 0x00000014, 0x00000014, 0x00000014, 0x02000000, 
    0x00000020, 0xfffffb2c, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3831746e, 0x00000000, 
    0x00000000, 0xfffffb7a, 0x01000000, 0x00000010, 0x00000010, 0x00000013, 0x00000020, 0xfffffb64, 
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3731746e, 0x00000000, 0x00000001, 0x0000000a, 
    0xfffffbb6, 0x01000000, 0x00000010, 0x00000010, 0x00000012, 0x00000020, 0xfffffba0, 0x00000010, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x3631746e, 0x00000000, 0x00000002, 0x0000000a, 0x00000020, 
    0xfffffbf6, 0x01000000, 0x00000010, 0x00000010, 0x00000011, 0x00000020, 0xfffffbe0, 0x00000010, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x3531746e, 0x00000000, 0x00000004, 0x0000000d, 0x00000001, 
    0x00000003, 0x0000001e, 0xfffffc3e, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 0x00000020, 
    0xfffffc28, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3431746e, 0x00000000, 0x00000001, 
    0x00000010, 0xfffffc7a, 0x01000000, 0x00000010, 0x00000010, 0x0000000f, 0x00000020, 0xfffffc64, 
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3331746e, 0x00000000, 0x00000004, 0x00000010, 
    0x00000001, 0x00000003, 0x00000010, 0xfffffcc2, 0x01000000, 0x00000010, 0x00000010, 0x0000000e, 
    0x00000020, 0xfffffcac, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3231746e, 0x00000000, 
    0x00000001, 0x00000020, 0xfffffcfe, 0x01000000, 0x00000010, 0x00000010, 0x0000000d, 0x00000020, 
    0xfffffce8, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3131746e, 0x00000000, 0x00000004, 
    0x00000020, 0x00000001, 0x00000003, 0x00000010, 0xffffff46, 0x01000000, 0x00000014, 0x00000014, 
    0x0000000c, 0x02000000, 0x00000020, 0xfffffd34, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x3031746e, 0x00000000, 0x00000001, 0x00000004, 0xffffff86, 0x01000000, 0x00000014, 0x00000014, 
    0x0000000b, 0x02000000, 0x0000001c, 0xfffffd74, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0039746e, 0x00000001, 0x00000004, 0xffffffc2, 0x01000000, 0x00000014, 0x00000014, 0x0000000a, 
    0x02000000, 0x0000001c, 0xfffffdb0, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0038746e, 
    0x00000001, 0x00000004, 0x00160000, 0x0018001c, 0x00100017, 0x0008000c, 0x00000000, 0x00070000, 
    0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000009, 0x02000000, 0x0000001c, 0xfffffe04, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0037746e, 0x00000001, 0x00000003, 0xfffffe52, 
    0x01000000, 0x00000010, 0x00000010, 0x00000008, 0x0000001c, 0xfffffe3c, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 0x0000000d, 0xfffffe8a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000007, 0x0000001c, 0xfffffe74, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0035746e, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 0x0000000d, 0xfffffece, 0x01000000, 
    0x00000010, 0x00000010, 0x00000006, 0x0000001c, 0xfffffeb8, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0034746e, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 0x00000010, 0xffffff12, 
    0x01000000, 0x00000010, 0x00000010, 0x00000005, 0x0000001c, 0xfffffefc, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0033746e, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 0x00000020, 
    0xffffff56, 0x01000000, 0x00000010, 0x00000010, 0x00000004, 0x0000001c, 0xffffff40, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0032746e, 0x00000001, 0x00000010, 0xffffff8e, 0x01000000, 
    0x00000010, 0x00000010, 0x00000003, 0x0000001c, 0xffffff78, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0031746e, 0x00000001, 0x00000010, 0xffffffc6, 0x01000000, 0x00000010, 0x00000010, 
    0x00000002, 0x0000001c, 0xffffffb0, 0x0000000e, 0x74697261, 0x6f632e68, 0x6174736e, 0x0000746e, 
    0x00000001, 0x00000020, 0x00160000, 0x00140018, 0x00100000, 0x0008000c, 0x00000000, 0x00070000, 
    0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000001, 0x0000002c, 0x00040004, 0x00000004, 
    0x00000019, 0x76726573, 0x5f676e69, 0x61666564, 0x5f746c75, 0x6579616c, 0x3a305f72, 0x00000030, 
    0x00000003, 0x00000001, 0x00000032, 0x0000001e, 0x00000006, 0x00000060, 0x00000044, 0x00000034, 
    0x00000024, 0x00000014, 0x00000004, 0xffffffc4, 0x00000019, 0x19000000, 0xffffffd0, 0x00000009, 
    0x09000000, 0xffffffdc, 0x00000028, 0x28000000, 0xffffffe8, 0x00000011, 0x11000000, 0xfffffff4, 
    0x00000003, 0x03000000, 0x000c000c, 0x0000000b, 0x00040000, 0x0000000c, 0x00000016, 0x16000000
};

static const uint32_t _k11[] = {
    0x00000000, 0x381e87c4, 0x391e863b, 0x39b25423, 0x3a1e8019, 0x3a77a0f6, 0x3ab2449b, 0x3af29a52, 
    0x3b1e6790, 0x3b487014, 0x3b776514, 0x3b95a260, 0x3bb2068a, 0x3bd0ddef, 0x3bf2275e, 0x3c0af0c6, 
    0x3c1e058c, 0x3c325144, 0x3c47d325, 0x3c5e8a59, 0x3c767600, 0x3c87ca96, 0x3c94f373, 0x3ca2b513, 
    0x3cb10eef, 0x3cc00079, 0x3ccf891c, 0x3cdfa83e, 0x3cf05d41, 0x3d00d3bf, 0x3d09c324, 0x3d12fc79, 
    0x3d1c7f61, 0x3d264b7e, 0x3d306070, 0x3d3abdd2, 0x3d45633d, 0x3d505049, 0x3d5b8488, 0x3d66ff8d, 
    0x3d72c0e4, 0x3d7ec81a, 0x3d858a5c, 0x3d8bd322, 0x3d923e20, 0x3d98cb17, 0x3d9f79c6, 0x3da649eb, 
    0x3dad3b42, 0x3db44d87, 0x3dbb8073, 0x3dc2d3c0, 0x3dca4724, 0x3dd1da56, 0x3dd98d0a, 0x3de15ef5, 
    0x3de94fc9, 0x3df15f37, 0x3df98cef, 0x3e00ec51, 0x3e0520fd, 0x3e096453, 0x3e0db62a, 0x3e121654, 
    0x3e1684a9, 0x3e1b00fb, 0x3e1f8b1e, 0x3e2422e6, 0x3e28c824, 0x3e2d7aab, 0x3e323a4b, 0x3e3706d7, 
    0x3e3be01f, 0x3e40c5f2, 0x3e45b820, 0x3e4ab678, 0x3e4fc0c8, 0x3e54d6df, 0x3e59f88a, 0x3e5f2596, 
    0x3e645dd0, 0x3e69a105, 0x3e6eeeff, 0x3e74478b, 0x3e79aa74, 0x3e7f1784, 0x3e824743, 0x3e8507a1, 
    0x3e87ccc2, 0x3e8a968a, 0x3e8d64dd, 0x3e9037a0, 0x3e930eb6, 0x3e95ea04, 0x3e98c96d, 0x3e9bacd4, 
    0x3e9e941e, 0x3ea17f2c, 0x3ea46de3, 0x3ea76026, 0x3eaa55d6, 0x3ead4ed8, 0x3eb04b0c, 0x3eb34a56, 
    0x3eb64c99, 0x3eb951b5, 0x3ebc598e, 0x3ebf6406, 0x3ec270fd, 0x3ec58056, 0x3ec891f3, 0x3ecba5b5, 
    0x3ecebb7e, 0x3ed1d32f, 0x3ed4ecaa, 0x3ed807cf, 0x3edb2480, 0x3ede429f, 0x3ee1620c, 0x3ee482a8, 
    0x3ee7a455, 0x3eeac6f2, 0x3eedea63, 0x3ef10e86, 0x3ef4333d, 0x3ef7586a, 0x3efa7dec, 0x3efda3a4, 
    0x3f0064ba, 0x3f01f79e, 0x3f038a6f, 0x3f051d1d, 0x3f06af97, 0x3f0841d0, 0x3f09d3b7, 0x3f0b653c, 
    0x3f0cf651, 0x3f0e86e5, 0x3f1016e9, 0x3f11a64e, 0x3f133504, 0x3f14c2fc, 0x3f165025, 0x3f17dc72, 
    0x3f1967d3, 0x3f1af237, 0x3f1c7b91, 0x3f1e03d0, 0x3f1f8ae6, 0x3f2110c4, 0x3f22955a, 0x3f241899, 
    0x3f259a73, 0x3f271ad8, 0x3f2899b9, 0x3f2a1709, 0x3f2b92b7, 0x3f2d0cb6, 0x3f2e84f6, 0x3f2ffb69, 
    0x3f317001, 0x3f32e2af, 0x3f345365, 0x3f35c214, 0x3f372eaf, 0x3f389927, 0x3f3a016e, 0x3f3b6776, 
    0x3f3ccb32, 0x3f3e2c94, 0x3f3f8b8d, 0x3f40e811, 0x3f424212, 0x3f439982, 0x3f44ee55, 0x3f46407c, 
    0x3f478fec, 0x3f48dc96, 0x3f4a266f, 0x3f4b6d69, 0x3f4cb177, 0x3f4df28e, 0x3f4f30a0, 0x3f506ba2, 
    0x3f51a386, 0x3f52d842, 0x3f5409c9, 0x3f553810, 0x3f56630a, 0x3f578aac, 0x3f58aeeb, 0x3f59cfbb, 
    0x3f5aed11, 0x3f5c06e2, 0x3f5d1d24, 0x3f5e2fcb, 0x3f5f3ecc, 0x3f604a1e, 0x3f6151b6, 0x3f62558a, 
    0x3f63558f, 0x3f6451bc, 0x3f654a07, 0x3f663e67, 0x3f672ed2, 0x3f681b3e, 0x3f6903a2, 0x3f69e7f7, 
    0x3f6ac831, 0x3f6ba44a, 0x3f6c7c39, 0x3f6d4ff4, 0x3f6e1f74, 0x3f6eeab2, 0x3f6fb1a4, 0x3f707443, 
    0x3f713289, 0x3f71ec6c, 0x3f72a1e7, 0x3f7352f3, 0x3f73ff87, 0x3f74a79e, 0x3f754b32, 0x3f75ea3b, 
    0x3f7684b4, 0x3f771a97, 0x3f77abdd, 0x3f783882, 0x3f78c080, 0x3f7943d1, 0x3f79c270, 0x3f7a3c5a, 
    0x3f7ab188, 0x3f7b21f6, 0x3f7b8da1, 0x3f7bf483, 0x3f7c5699, 0x3f7cb3df, 0x3f7d0c52, 0x3f7d5fee, 
    0x3f7daeaf, 0x3f7df893, 0x3f7e3d97, 0x3f7e7db8, 0x3f7eb8f4, 0x3f7eef48, 0x3f7f20b3, 0x3f7f4d32, 
    0x3f7f74c3, 0x3f7f9766, 0x3f7fb519, 0x3f7fcdda, 0x3f7fe1a9, 0x3f7ff085, 0x3f7ffa6d, 0x3f7fff61, 
    0x3f7fff61, 0x3f7ffa6d, 0x3f7ff085, 0x3f7fe1a9, 0x3f7fcdda, 0x3f7fb519, 0x3f7f9766, 0x3f7f74c3, 
    0x3f7f4d32, 0x3f7f20b3, 0x3f7eef48, 0x3f7eb8f4, 0x3f7e7db8, 0x3f7e3d97, 0x3f7df893, 0x3f7daeaf, 
    0x3f7d5fee, 0x3f7d0c52, 0x3f7cb3df, 0x3f7c5699, 0x3f7bf483, 0x3f7b8da1, 0x3f7b21f6, 0x3f7ab188, 
    0x3f7a3c5a, 0x3f79c270, 0x3f7943d1, 0x3f78c080, 0x3f783882, 0x3f77abdd, 0x3f771a97, 0x3f7684b4, 
    0x3f75ea3b, 0x3f754b32, 0x3f74a79e, 0x3f73ff87, 0x3f7352f3, 0x3f72a1e7, 0x3f71ec6c, 0x3f713289, 
    0x3f707443, 0x3f6fb1a4, 0x3f6eeab2, 0x3f6e1f74, 0x3f6d4ff4, 0x3f6c7c39, 0x3f6ba44a, 0x3f6ac831, 
    0x3f69e7f7, 0x3f6903a2, 0x3f681b3e, 0x3f672ed2, 0x3f663e67, 0x3f654a07, 0x3f6451bc, 0x3f63558f, 
    0x3f62558a, 0x3f6151b6, 0x3f604a1e, 0x3f5f3ecc, 0x3f5e2fcb, 0x3f5d1d24, 0x3f5c06e2, 0x3f5aed11, 
    0x3f59cfbb, 0x3f58aeeb, 0x3f578aac, 0x3f56630a, 0x3f553810, 0x3f5409c9, 0x3f52d842, 0x3f51a386, 
    0x3f506ba2, 0x3f4f30a0, 0x3f4df28e, 0x3f4cb177, 0x3f4b6d69, 0x3f4a266f, 0x3f48dc96, 0x3f478fec, 
    0x3f46407c, 0x3f44ee55, 0x3f439982, 0x3f424212, 0x3f40e811, 0x3f3f8b8d, 0x3f3e2c94, 0x3f3ccb32, 
    0x3f3b6776, 0x3f3a016e, 0x3f389927, 0x3f372eaf, 0x3f35c214, 0x3f345365, 0x3f32e2af, 0x3f317001, 
    0x3f2ffb69, 0x3f2e84f6, 0x3f2d0cb6, 0x3f2b92b7, 0x3f2a1709, 0x3f2899b9, 0x3f271ad8, 0x3f259a73, 
    0x3f241899, 0x3f22955a, 0x3f2110c4, 0x3f1f8ae6, 0x3f1e03d0, 0x3f1c7b91, 0x3f1af237, 0x3f1967d3, 
    0x3f17dc72, 0x3f165025, 0x3f14c2fc, 0x3f133504, 0x3f11a64e, 0x3f1016e9, 0x3f0e86e5, 0x3f0cf651, 
    0x3f0b653c, 0x3f09d3b7, 0x3f0841d0, 0x3f06af97, 0x3f051d1d, 0x3f038a6f, 0x3f01f79e, 0x3f0064ba, 
    0x3efda3a4, 0x3efa7dec, 0x3ef7586a, 0x3ef4333d, 0x3ef10e86, 0x3eedea63, 0x3eeac6f2, 0x3ee7a455, 
    0x3ee482a8, 0x3ee1620c, 0x3ede429f, 0x3edb2480, 0x3ed807cf, 0x3ed4ecaa, 0x3ed1d32f, 0x3ecebb7e, 
    0x3ecba5b5, 0x3ec891f3, 0x3ec58056, 0x3ec270fd, 0x3ebf6406, 0x3ebc598e, 0x3eb951b5, 0x3eb64c99, 
    0x3eb34a56, 0x3eb04b0c, 0x3ead4ed8, 0x3eaa55d6, 0x3ea76026, 0x3ea46de3, 0x3ea17f2c, 0x3e9e941e, 
    0x3e9bacd4, 0x3e98c96d, 0x3e95ea04, 0x3e930eb6, 0x3e9037a0, 0x3e8d64dd, 0x3e8a968a, 0x3e87ccc2, 
    0x3e8507a1, 0x3e824743, 0x3e7f1784, 0x3e79aa74, 0x3e74478b, 0x3e6eeeff, 0x3e69a105, 0x3e645dd0, 
    0x3e5f2596, 0x3e59f88a, 0x3e54d6df, 0x3e4fc0c8, 0x3e4ab678, 0x3e45b820, 0x3e40c5f2, 0x3e3be01f, 
    0x3e3706d7, 0x3e323a4b, 0x3e2d7aab, 0x3e28c824, 0x3e2422e6, 0x3e1f8b1e, 0x3e1b00fb, 0x3e1684a9, 
    0x3e121654, 0x3e0db62a, 0x3e096453, 0x3e0520fd, 0x3e00ec51, 0x3df98cef, 0x3df15f37, 0x3de94fc9, 
    0x3de15ef5, 0x3dd98d0a, 0x3dd1da56, 0x3dca4724, 0x3dc2d3c0, 0x3dbb8073, 0x3db44d87, 0x3dad3b42, 
    0x3da649eb, 0x3d9f79c6, 0x3d98cb17, 0x3d923e20, 0x3d8bd322, 0x3d858a5c, 0x3d7ec81a, 0x3d72c0e4, 
    0x3d66ff8d, 0x3d5b8488, 0x3d505049, 0x3d45633d, 0x3d3abdd2, 0x3d306070, 0x3d264b7e, 0x3d1c7f61, 
    0x3d12fc79, 0x3d09c324, 0x3d00d3bf, 0x3cf05d41, 0x3cdfa83e, 0x3ccf891c, 0x3cc00079, 0x3cb10eef, 
    0x3ca2b513, 0x3c94f373, 0x3c87ca96, 0x3c767600, 0x3c5e8a59, 0x3c47d325, 0x3c325144, 0x3c1e058c, 
    0x3c0af0c6, 0x3bf2275e, 0x3bd0ddef, 0x3bb2068a, 0x3b95a260, 0x3b776514, 0x3b487014, 0x3b1e6790, 
    0x3af29a52, 0x3ab2449b, 0x3a77a0f6, 0x3a1e8019, 0x39b25423, 0x391e863b, 0x381e87c4, 0x00000000
};

static const uint32_t _k23[] = {
    0x00080006, 0x000d000a, 0x0012000f, 0x00180015, 0x001f001b, 0x00270023, 0x0030002b, 0x003b0035, 
    0x00470040, 0x0055004d, 0x0065005c, 0x0077006d, 0x008c0081, 0x00a40098, 0x00c000b2, 0x00e000cf
};

// Memory mapped buffers
#define _K11             ((float *)_k11)                     // f32[512] (2048 bytes)
#define _K23             ((int16_t *)_k23)                   // s16[32] (64 bytes)
#define _K7              ((uint8_t *)_k7)                    // u8[39840] (39840 bytes)
#define _K10             ((int8_t *)(_state + 0x00002110))   // s8[8] (8 bytes)
#define _K18             ((int32_t *)(_state + 0x00006120))  // s32[24] (96 bytes)
#define _K19             ((float *)(_state + 0x00006180))    // f32[258] (1032 bytes)
#define _K2              ((int8_t *)(_state + 0x00000000))   // s8[2256] (2256 bytes)
#define _K5              ((int8_t *)(_state + 0x000008d0))   // s8[6208] (6208 bytes)
#define _K6              ((uint8_t *)(_state + 0x00002120))  // u8[16384] (16384 bytes)
#define _K1              ((float *)(_buffer + 0x00000000))   // f32[512] (2048 bytes)
#define _K15             ((float *)(_buffer + 0x00000800))   // f32[512] (2048 bytes)
#define _K16             ((float *)(_buffer + 0x00001000))   // f32[257,2] (2056 bytes)
#define _K20             ((float *)(_buffer + 0x00001808))   // f32[1026] (4104 bytes)
#define _K22             ((float *)(_buffer + 0x00000000))   // f32[257] (1028 bytes)
#define _K27             ((float *)(_buffer + 0x00000404))   // f32[30] (120 bytes)
#define _K28             ((float *)(_buffer + 0x00000000))   // f32[30] (120 bytes)
#define _K3              ((float *)(_buffer + 0x00000078))   // f32[30] (120 bytes)
#define _K4              ((float *)(_buffer + 0x00000000))   // f32[50,30] (6000 bytes)

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

#ifdef IMAI_PROFILING
	static uint32_t region_profile_visits[IMAI_REGIONS_COUNT];
	static uint64_t region_start[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_sum[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_max[IMAI_REGIONS_COUNT];
	static char* region_names[] = IMAI_REGIONS_NAMES;
	static const char* region_notes[] = IMAI_REGIONS_NOTES;

	#define __HOOK_REGION(entered, region_id) hook_region(entered, region_id)
	#define __CLOSE_HOOKS() close_regions()

	int IMAI_get_ticks(uint64_t *val) { return 0; }
    int (*IMAI_get_ticks_ptr)(uint64_t* val) = &IMAI_get_ticks;

	ATTRIB_WEAK void IMAI_hook_region(bool entered, int32_t region_id) {
		uint64_t ticks = 0;
		// assign the current tick count with a BSP or custom function
		IMAI_get_ticks_ptr(&ticks);
		 if (entered) {
			 region_start[region_id] = ticks;
		}
		else {
			ticks = ticks - region_start[region_id];
			region_profile_visits[region_id]++;
			if (ticks > region_profile_max[region_id])
				region_profile_max[region_id] = ticks;
			region_profile_sum[region_id] += ticks;
		}
	}
	
	static bool region_entered[IMAI_REGIONS_COUNT];
	
	static inline void hook_region(bool entered, int32_t region_id) {
		region_entered[region_id] = entered;
		IMAI_hook_region(entered, region_id);
	}
	
	static inline void close_regions() {
		uint32_t i = 0;
		for (i = 0; i < IMAI_REGIONS_COUNT; i++)
			if (region_entered[i])
				hook_region(false, i);
	}

	void IMAI_print_region_profiling(void) {
		uint32_t i = 0;
		printf("Region profiling results:\r\n");
		for (i = 0; i < IMAI_REGIONS_COUNT; i++) {
			if (region_notes[i] != NULL && region_notes[i][0] != '\0') {
				printf("Region \"%s\"; %s\r\n",
					region_names[i],
					region_notes[i]);
			}
			else {
				printf("Region \"%s\"; visits: %lu, max cycles: %-10.2f, avg cycles: %-10.2f\r\n",
					region_names[i],
					(unsigned long)region_profile_visits[i],
					(float)region_profile_max[i],
					(float)region_profile_sum[i] / region_profile_visits[i]);
			}
		}
		printf("\r\n");
	}
#else
	#define __HOOK_REGION(entered, region_id) do { } while(0)
	#define __CLOSE_HOOKS() do { } while(0)

	void IMAI_print_region_profiling(void) {
		(void)0;
	}
#endif

// Represents a Circular Buffer
// https://en.wikipedia.org/wiki/Circular_buffer
typedef struct
{
	char *buf;
	int size;		// total bytes allocated in *buf
	int used;		// current bytes used in buffer.
	int read;
	int write;
} cbuffer_t;

#define CBUFFER_SUCCESS 0
#define CBUFFER_NOMEM -1

// Reset instance (clear buffer)
static inline void cbuffer_reset(cbuffer_t* buf) {
	buf->read = 0;
	buf->write = 0;
	buf->used = 0;
}

// Initializes a cbuffer handle with given memory and size.
static inline void cbuffer_init(cbuffer_t *dest, void *mem, int size) {
	dest->buf = mem;
	dest->size = size;
	cbuffer_reset(dest);
}

// Returns the number of free bytes in buffer.
static inline int cbuffer_get_free(cbuffer_t *buf) {
	return buf->size - buf->used;
}

// Returns the number of used bytes in buffer.
static inline int cbuffer_get_used(cbuffer_t *buf) {
	return buf->used;
}

// Writes given data to buffer.
// Returns CBUFFER_SUCCESS or CBUFFER_NOMEM if out of memory.
static inline int cbuffer_enqueue(cbuffer_t *buf, const void *data, int data_size) {
	int free = cbuffer_get_free(buf);

	// Out of memory?
	if (free < data_size)
		return CBUFFER_NOMEM;

	// Is the data split in the end?
	if (buf->write + data_size > buf->size) {
		int first_size = buf->size - buf->write;
		memcpy(buf->buf + buf->write, data, first_size);
		memcpy(buf->buf, ((char *)data) + first_size, data_size - first_size);
	}
	else {
		memcpy(buf->buf + buf->write, data, data_size);
	}
	buf->write += data_size;
	if (buf->write >= buf->size)
		buf->write -= buf->size;

	buf->used += data_size;
	return CBUFFER_SUCCESS;
}

// Advances the read pointer by given count.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data
static inline int cbuffer_advance(cbuffer_t *buf, int count) {
	int used = cbuffer_get_used(buf);

	if (count > used)
		return CBUFFER_NOMEM;

	buf->read += count;
	if (buf->read >= buf->size)
		buf->read -= buf->size;

	// Reset pointers to 0 if buffer is empty in order to avoid unwanted wrapps.
	if (buf->read == buf->write) {
		buf->read = 0;
		buf->write = 0;
	}

	buf->used -= count;
	return CBUFFER_SUCCESS;
}

// Returns a read pointer at given offset and  
// updates *can_read_bytes (if not NULL) with the number of bytes that can be read.
// 
// Note! Byte count written to can_read_bytes can be less than what cbuffer_get_used() returns.
// This happens when the read has to be split in two since it's a circular buffer.
static inline void* cbuffer_readptr(cbuffer_t* buf, int offset, int* can_read_bytes)
{
	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;
	if (can_read_bytes != NULL)
	{
		int c0 = buf->used;
		if (a0 + c0 > buf->size)
			c0 = buf->size - a0;

		*can_read_bytes = c0;
	}
	return buf->buf + a0;
}

// Copies given "count" bytes to the "dst" buffer without advancing the buffer read offset.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data.
static inline int cbuffer_copyto(cbuffer_t *buf, void *dst, int count, int offset) {
	
	if (count > cbuffer_get_used(buf))
		return CBUFFER_NOMEM;

	int can_read_bytes;
	void* src_ptr = cbuffer_readptr(buf, offset, &can_read_bytes);

	int c0 = (count < can_read_bytes) ? count : can_read_bytes;
	memcpy(dst, src_ptr, c0);
	
	int c1 = count - c0;

	if (c1 > 0)
		memcpy(((char *)dst) + c0, buf->buf, c1);

	return CBUFFER_SUCCESS;
}

typedef struct {
	cbuffer_t data_buffer;			// Circular Buffer for features
	int input_size;					// Number of bytes in each input chunk
} fixwin_t;

#ifdef _MSC_VER
static_assert(sizeof(fixwin_t) <= 64, "Data structure 'fixwin_t' is too big");
#endif

/*
* Try to dequeue a window.
*
* @param handle Pointer to an initialized handle.
* @param dst Pointer where to write window.
* @param stride_count Number of items (of size handle->input_size) to stride window.
* @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1) is no data is available.
*/
static inline int fixwin_dequeue(void* restrict handle, void* restrict dst, int count, int stride_count)
{
	fixwin_t* fep = (fixwin_t*)handle;

	const int stride_bytes = stride_count * fep->input_size;
	const int size = count * fep->input_size;
	if (cbuffer_get_used(&fep->data_buffer) >= size) {
		if (cbuffer_copyto(&fep->data_buffer, dst, size, 0) != 0)
			return IPWIN_RET_ERROR;

		if (cbuffer_advance(&fep->data_buffer, stride_bytes) != 0)
			return IPWIN_RET_ERROR;

		return IPWIN_RET_SUCCESS;
	}
	return IPWIN_RET_NODATA;
}

// input array (any shape >= 1D)
// output array (same shape as input array)
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void hannmul_f32(const float* restrict input, const float* restrict w, int d0, int d1, int d2, float* restrict output)
{
	const int d3 = d0 * d1;

	const float* ip = input;
	float* op = output;

	for (int j = 0; j < d2; j++) {
		for (int i = 0; i < d0; i++) {
			for (int k = 0; k < d1; k++) {
				op[k * d0 + i] = ip[k * d0 + i] * w[k];
			}
		}

		ip += d3;
		op += d3;
	}
}

static void makeipt(int nw, int *ip)
{
    int j, l, m, m2, p, q;
    
    ip[2] = 0;
    ip[3] = 16;
    m = 2;
    for (l = nw; l > 32; l >>= 2) {
        m2 = m << 1;
        q = m2 << 3;
        for (j = m; j < m2; j++) {
            p = ip[j] << 2;
            ip[m + j] = p;
            ip[m2 + j] = p + q;
        }
        m = m2;
    }
}

static void makewt(int nw, int *ip, float *w)
{
    void makeipt(int nw, int *ip);
    int j, nwh, nw0, nw1;
    float delta, wn4r, wk1r, wk1i, wk3r, wk3i;
    
    ip[0] = nw;
    ip[1] = 1;
    if (nw > 2) {
        nwh = nw >> 1;
        delta = atan(1.0) / nwh;
        wn4r = cos(delta * nwh);
        w[0] = 1;
        w[1] = wn4r;
        if (nwh == 4) {
            w[2] = cos(delta * 2);
            w[3] = sin(delta * 2);
        } else if (nwh > 4) {
            makeipt(nw, ip);
            w[2] = 0.5 / cos(delta * 2);
            w[3] = 0.5 / cos(delta * 6);
            for (j = 4; j < nwh; j += 4) {
                w[j] = cos(delta * j);
                w[j + 1] = sin(delta * j);
                w[j + 2] = cos(3 * delta * j);
                w[j + 3] = -sin(3 * delta * j);
            }
        }
        nw0 = 0;
        while (nwh > 2) {
            nw1 = nw0 + nwh;
            nwh >>= 1;
            w[nw1] = 1;
            w[nw1 + 1] = wn4r;
            if (nwh == 4) {
                wk1r = w[nw0 + 4];
                wk1i = w[nw0 + 5];
                w[nw1 + 2] = wk1r;
                w[nw1 + 3] = wk1i;
            } else if (nwh > 4) {
                wk1r = w[nw0 + 4];
                wk3r = w[nw0 + 6];
                w[nw1 + 2] = 0.5 / wk1r;
                w[nw1 + 3] = 0.5 / wk3r;
                for (j = 4; j < nwh; j += 4) {
                    wk1r = w[nw0 + 2 * j];
                    wk1i = w[nw0 + 2 * j + 1];
                    wk3r = w[nw0 + 2 * j + 2];
                    wk3i = w[nw0 + 2 * j + 3];
                    w[nw1 + j] = wk1r;
                    w[nw1 + j + 1] = wk1i;
                    w[nw1 + j + 2] = wk3r;
                    w[nw1 + j + 3] = wk3i;
                }
            }
            nw0 = nw1;
        }
    }
}

static void makect(int nc, int *ip, float *c)
{
    int j, nch;
    float delta;
    
    ip[1] = nc;
    if (nc > 1) {
        nch = nc >> 1;
        delta = atan(1.0) / nch;
        c[0] = cos(delta * nch);
        c[nch] = 0.5 * c[0];
        for (j = 1; j < nch; j++) {
            c[j] = 0.5 * cos(delta * j);
            c[nc - j] = 0.5 * sin(delta * j);
        }
    }
}

static void bitrv2(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    }
}

static void bitrv216(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x7r, x7i, x8r, x8i, x10r, x10i, 
        x11r, x11i, x12r, x12i, x13r, x13i, x14r, x14i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    a[2] = x8r;
    a[3] = x8i;
    a[4] = x4r;
    a[5] = x4i;
    a[6] = x12r;
    a[7] = x12i;
    a[8] = x2r;
    a[9] = x2i;
    a[10] = x10r;
    a[11] = x10i;
    a[14] = x14r;
    a[15] = x14i;
    a[16] = x1r;
    a[17] = x1i;
    a[20] = x5r;
    a[21] = x5i;
    a[22] = x13r;
    a[23] = x13i;
    a[24] = x3r;
    a[25] = x3i;
    a[26] = x11r;
    a[27] = x11i;
    a[28] = x7r;
    a[29] = x7i;
}

static void bitrv208(float *a)
{
    float x1r, x1i, x3r, x3i, x4r, x4i, x6r, x6i;
    
    x1r = a[2];
    x1i = a[3];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x6r = a[12];
    x6i = a[13];
    a[2] = x4r;
    a[3] = x4i;
    a[6] = x6r;
    a[7] = x6i;
    a[8] = x1r;
    a[9] = x1i;
    a[12] = x3r;
    a[13] = x3i;
}

static void cftf1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = a[j + 3] + a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = a[j + 3] - a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = a[j0 - 1] + a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = a[j0 - 1] - a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = a[j0 - 1] + a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = a[j0 - 1] - a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i + x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = a[j0 + 3] + a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = a[j0 + 3] - a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i + x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftmdl1(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    k = 0;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
    }
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
}

static void cftmdl2(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, kr, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i, wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, y0r, y0i, y2r, y2i;
    
    mh = n >> 3;
    m = 2 * mh;
    wn4r = w[1];
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] - a[j2 + 1];
    x0i = a[1] + a[j2];
    x1r = a[0] + a[j2 + 1];
    x1i = a[1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wn4r * (x2r - x2i);
    y0i = wn4r * (x2i + x2r);
    a[0] = x0r + y0r;
    a[1] = x0i + y0i;
    a[j1] = x0r - y0r;
    a[j1 + 1] = x0i - y0i;
    y0r = wn4r * (x3r - x3i);
    y0i = wn4r * (x3i + x3r);
    a[j2] = x1r - y0i;
    a[j2 + 1] = x1i + y0r;
    a[j3] = x1r + y0i;
    a[j3 + 1] = x1i - y0r;
    k = 0;
    kr = 2 * m;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        kr -= 4;
        wd1i = w[kr];
        wd1r = w[kr + 1];
        wd3i = w[kr + 2];
        wd3r = w[kr + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] - a[j2 + 1];
        x0i = a[j + 1] + a[j2];
        x1r = a[j] + a[j2 + 1];
        x1i = a[j + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wk1r * x0r - wk1i * x0i;
        y0i = wk1r * x0i + wk1i * x0r;
        y2r = wd1r * x2r - wd1i * x2i;
        y2i = wd1r * x2i + wd1i * x2r;
        a[j] = y0r + y2r;
        a[j + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wk3r * x1r + wk3i * x1i;
        y0i = wk3r * x1i - wk3i * x1r;
        y2r = wd3r * x3r + wd3i * x3i;
        y2i = wd3r * x3i - wd3i * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] - a[j2 + 1];
        x0i = a[j0 + 1] + a[j2];
        x1r = a[j0] + a[j2 + 1];
        x1i = a[j0 + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wd1i * x0r - wd1r * x0i;
        y0i = wd1i * x0i + wd1r * x0r;
        y2r = wk1i * x2r - wk1r * x2i;
        y2i = wk1i * x2i + wk1r * x2r;
        a[j0] = y0r + y2r;
        a[j0 + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wd3i * x1r + wd3r * x1i;
        y0i = wd3i * x1i - wd3r * x1r;
        y2r = wk3i * x3r + wk3r * x3i;
        y2i = wk3i * x3i - wk3r * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
    }
    wk1r = w[m];
    wk1i = w[m + 1];
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] - a[j2 + 1];
    x0i = a[j0 + 1] + a[j2];
    x1r = a[j0] + a[j2 + 1];
    x1i = a[j0 + 1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wk1r * x0r - wk1i * x0i;
    y0i = wk1r * x0i + wk1i * x0r;
    y2r = wk1i * x2r - wk1r * x2i;
    y2i = wk1i * x2i + wk1r * x2r;
    a[j0] = y0r + y2r;
    a[j0 + 1] = y0i + y2i;
    a[j1] = y0r - y2r;
    a[j1 + 1] = y0i - y2i;
    y0r = wk1i * x1r - wk1r * x1i;
    y0i = wk1i * x1i + wk1r * x1r;
    y2r = wk1r * x3r - wk1i * x3i;
    y2i = wk1r * x3i + wk1i * x3r;
    a[j2] = y0r - y2r;
    a[j2 + 1] = y0i - y2i;
    a[j3] = y0r + y2r;
    a[j3 + 1] = y0i + y2i;
}

static int cfttree(int n, int j, int k, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    int i, isplt, m;
    
    if ((k & 3) != 0) {
        isplt = k & 1;
        if (isplt != 0) {
            cftmdl1(n, &a[j - n], &w[nw - (n >> 1)]);
        } else {
            cftmdl2(n, &a[j - n], &w[nw - n]);
        }
    } else {
        m = n;
        for (i = k; (i & 3) == 0; i >>= 2) {
            m <<= 2;
        }
        isplt = i & 1;
        if (isplt != 0) {
            while (m > 128) {
                cftmdl1(m, &a[j - m], &w[nw - (m >> 1)]);
                m >>= 2;
            }
        } else {
            while (m > 128) {
                cftmdl2(m, &a[j - m], &w[nw - m]);
                m >>= 2;
            }
        }
    }
    return isplt;
}

static void cftf161(float *a, float *w)
{
    float wn4r, wk1r, wk1i, 
        x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    x0r = a[0] + a[16];
    x0i = a[1] + a[17];
    x1r = a[0] - a[16];
    x1i = a[1] - a[17];
    x2r = a[8] + a[24];
    x2i = a[9] + a[25];
    x3r = a[8] - a[24];
    x3i = a[9] - a[25];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y4r = x0r - x2r;
    y4i = x0i - x2i;
    y8r = x1r - x3i;
    y8i = x1i + x3r;
    y12r = x1r + x3i;
    y12i = x1i - x3r;
    x0r = a[2] + a[18];
    x0i = a[3] + a[19];
    x1r = a[2] - a[18];
    x1i = a[3] - a[19];
    x2r = a[10] + a[26];
    x2i = a[11] + a[27];
    x3r = a[10] - a[26];
    x3i = a[11] - a[27];
    y1r = x0r + x2r;
    y1i = x0i + x2i;
    y5r = x0r - x2r;
    y5i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y9r = wk1r * x0r - wk1i * x0i;
    y9i = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y13r = wk1i * x0r - wk1r * x0i;
    y13i = wk1i * x0i + wk1r * x0r;
    x0r = a[4] + a[20];
    x0i = a[5] + a[21];
    x1r = a[4] - a[20];
    x1i = a[5] - a[21];
    x2r = a[12] + a[28];
    x2i = a[13] + a[29];
    x3r = a[12] - a[28];
    x3i = a[13] - a[29];
    y2r = x0r + x2r;
    y2i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y10r = wn4r * (x0r - x0i);
    y10i = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y14r = wn4r * (x0r + x0i);
    y14i = wn4r * (x0i - x0r);
    x0r = a[6] + a[22];
    x0i = a[7] + a[23];
    x1r = a[6] - a[22];
    x1i = a[7] - a[23];
    x2r = a[14] + a[30];
    x2i = a[15] + a[31];
    x3r = a[14] - a[30];
    x3i = a[15] - a[31];
    y3r = x0r + x2r;
    y3i = x0i + x2i;
    y7r = x0r - x2r;
    y7i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y11r = wk1i * x0r - wk1r * x0i;
    y11i = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y15r = wk1r * x0r - wk1i * x0i;
    y15i = wk1r * x0i + wk1i * x0r;
    x0r = y12r - y14r;
    x0i = y12i - y14i;
    x1r = y12r + y14r;
    x1i = y12i + y14i;
    x2r = y13r - y15r;
    x2i = y13i - y15i;
    x3r = y13r + y15r;
    x3i = y13i + y15i;
    a[24] = x0r + x2r;
    a[25] = x0i + x2i;
    a[26] = x0r - x2r;
    a[27] = x0i - x2i;
    a[28] = x1r - x3i;
    a[29] = x1i + x3r;
    a[30] = x1r + x3i;
    a[31] = x1i - x3r;
    x0r = y8r + y10r;
    x0i = y8i + y10i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    x3r = y9r - y11r;
    x3i = y9i - y11i;
    a[16] = x0r + x2r;
    a[17] = x0i + x2i;
    a[18] = x0r - x2r;
    a[19] = x0i - x2i;
    a[20] = x1r - x3i;
    a[21] = x1i + x3r;
    a[22] = x1r + x3i;
    a[23] = x1i - x3r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x3r = wn4r * (x0r - x0i);
    x3i = wn4r * (x0i + x0r);
    x0r = y4r - y6i;
    x0i = y4i + y6r;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    a[8] = x0r + x2r;
    a[9] = x0i + x2i;
    a[10] = x0r - x2r;
    a[11] = x0i - x2i;
    a[12] = x1r - x3i;
    a[13] = x1i + x3r;
    a[14] = x1r + x3i;
    a[15] = x1i - x3r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    x3r = y1r - y3r;
    x3i = y1i - y3i;
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x0r - x2r;
    a[3] = x0i - x2i;
    a[4] = x1r - x3i;
    a[5] = x1i + x3r;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftf162(float *a, float *w)
{
    float wn4r, wk1r, wk1i, wk2r, wk2i, wk3r, wk3i, 
        x0r, x0i, x1r, x1i, x2r, x2i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[4];
    wk1i = w[5];
    wk3r = w[6];
    wk3i = -w[7];
    wk2r = w[8];
    wk2i = w[9];
    x1r = a[0] - a[17];
    x1i = a[1] + a[16];
    x0r = a[8] - a[25];
    x0i = a[9] + a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y0r = x1r + x2r;
    y0i = x1i + x2i;
    y4r = x1r - x2r;
    y4i = x1i - x2i;
    x1r = a[0] + a[17];
    x1i = a[1] - a[16];
    x0r = a[8] + a[25];
    x0i = a[9] - a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y8r = x1r - x2i;
    y8i = x1i + x2r;
    y12r = x1r + x2i;
    y12i = x1i - x2r;
    x0r = a[2] - a[19];
    x0i = a[3] + a[18];
    x1r = wk1r * x0r - wk1i * x0i;
    x1i = wk1r * x0i + wk1i * x0r;
    x0r = a[10] - a[27];
    x0i = a[11] + a[26];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y1r = x1r + x2r;
    y1i = x1i + x2i;
    y5r = x1r - x2r;
    y5i = x1i - x2i;
    x0r = a[2] + a[19];
    x0i = a[3] - a[18];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[10] + a[27];
    x0i = a[11] - a[26];
    x2r = wk1r * x0r + wk1i * x0i;
    x2i = wk1r * x0i - wk1i * x0r;
    y9r = x1r - x2r;
    y9i = x1i - x2i;
    y13r = x1r + x2r;
    y13i = x1i + x2i;
    x0r = a[4] - a[21];
    x0i = a[5] + a[20];
    x1r = wk2r * x0r - wk2i * x0i;
    x1i = wk2r * x0i + wk2i * x0r;
    x0r = a[12] - a[29];
    x0i = a[13] + a[28];
    x2r = wk2i * x0r - wk2r * x0i;
    x2i = wk2i * x0i + wk2r * x0r;
    y2r = x1r + x2r;
    y2i = x1i + x2i;
    y6r = x1r - x2r;
    y6i = x1i - x2i;
    x0r = a[4] + a[21];
    x0i = a[5] - a[20];
    x1r = wk2i * x0r - wk2r * x0i;
    x1i = wk2i * x0i + wk2r * x0r;
    x0r = a[12] + a[29];
    x0i = a[13] - a[28];
    x2r = wk2r * x0r - wk2i * x0i;
    x2i = wk2r * x0i + wk2i * x0r;
    y10r = x1r - x2r;
    y10i = x1i - x2i;
    y14r = x1r + x2r;
    y14i = x1i + x2i;
    x0r = a[6] - a[23];
    x0i = a[7] + a[22];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[14] - a[31];
    x0i = a[15] + a[30];
    x2r = wk1i * x0r - wk1r * x0i;
    x2i = wk1i * x0i + wk1r * x0r;
    y3r = x1r + x2r;
    y3i = x1i + x2i;
    y7r = x1r - x2r;
    y7i = x1i - x2i;
    x0r = a[6] + a[23];
    x0i = a[7] - a[22];
    x1r = wk1i * x0r + wk1r * x0i;
    x1i = wk1i * x0i - wk1r * x0r;
    x0r = a[14] + a[31];
    x0i = a[15] - a[30];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y11r = x1r + x2r;
    y11i = x1i + x2i;
    y15r = x1r - x2r;
    y15i = x1i - x2i;
    x1r = y0r + y2r;
    x1i = y0i + y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    a[0] = x1r + x2r;
    a[1] = x1i + x2i;
    a[2] = x1r - x2r;
    a[3] = x1i - x2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r - y3r;
    x2i = y1i - y3i;
    a[4] = x1r - x2i;
    a[5] = x1i + x2r;
    a[6] = x1r + x2i;
    a[7] = x1i - x2r;
    x1r = y4r - y6i;
    x1i = y4i + y6r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[8] = x1r + x2r;
    a[9] = x1i + x2i;
    a[10] = x1r - x2r;
    a[11] = x1i - x2i;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[12] = x1r - x2i;
    a[13] = x1i + x2r;
    a[14] = x1r + x2i;
    a[15] = x1i - x2r;
    x1r = y8r + y10r;
    x1i = y8i + y10i;
    x2r = y9r - y11r;
    x2i = y9i - y11i;
    a[16] = x1r + x2r;
    a[17] = x1i + x2i;
    a[18] = x1r - x2r;
    a[19] = x1i - x2i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    a[20] = x1r - x2i;
    a[21] = x1i + x2r;
    a[22] = x1r + x2i;
    a[23] = x1i - x2r;
    x1r = y12r - y14i;
    x1i = y12i + y14r;
    x0r = y13r + y15i;
    x0i = y13i - y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[24] = x1r + x2r;
    a[25] = x1i + x2i;
    a[26] = x1r - x2r;
    a[27] = x1i - x2i;
    x1r = y12r + y14i;
    x1i = y12i - y14r;
    x0r = y13r - y15i;
    x0i = y13i + y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[28] = x1r - x2i;
    a[29] = x1i + x2r;
    a[30] = x1r + x2i;
    a[31] = x1i - x2r;
}

static void cftf081(float *a, float *w)
{
    float wn4r, x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    x0r = a[0] + a[8];
    x0i = a[1] + a[9];
    x1r = a[0] - a[8];
    x1i = a[1] - a[9];
    x2r = a[4] + a[12];
    x2i = a[5] + a[13];
    x3r = a[4] - a[12];
    x3i = a[5] - a[13];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y2r = x0r - x2r;
    y2i = x0i - x2i;
    y1r = x1r - x3i;
    y1i = x1i + x3r;
    y3r = x1r + x3i;
    y3i = x1i - x3r;
    x0r = a[2] + a[10];
    x0i = a[3] + a[11];
    x1r = a[2] - a[10];
    x1i = a[3] - a[11];
    x2r = a[6] + a[14];
    x2i = a[7] + a[15];
    x3r = a[6] - a[14];
    x3i = a[7] - a[15];
    y4r = x0r + x2r;
    y4i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    x2r = x1r + x3i;
    x2i = x1i - x3r;
    y5r = wn4r * (x0r - x0i);
    y5i = wn4r * (x0r + x0i);
    y7r = wn4r * (x2r - x2i);
    y7i = wn4r * (x2r + x2i);
    a[8] = y1r + y5r;
    a[9] = y1i + y5i;
    a[10] = y1r - y5r;
    a[11] = y1i - y5i;
    a[12] = y3r - y7i;
    a[13] = y3i + y7r;
    a[14] = y3r + y7i;
    a[15] = y3i - y7r;
    a[0] = y0r + y4r;
    a[1] = y0i + y4i;
    a[2] = y0r - y4r;
    a[3] = y0i - y4i;
    a[4] = y2r - y6i;
    a[5] = y2i + y6r;
    a[6] = y2r + y6i;
    a[7] = y2i - y6r;
}

static void cftf082(float *a, float *w)
{
    float wn4r, wk1r, wk1i, x0r, x0i, x1r, x1i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    y0r = a[0] - a[9];
    y0i = a[1] + a[8];
    y1r = a[0] + a[9];
    y1i = a[1] - a[8];
    x0r = a[4] - a[13];
    x0i = a[5] + a[12];
    y2r = wn4r * (x0r - x0i);
    y2i = wn4r * (x0i + x0r);
    x0r = a[4] + a[13];
    x0i = a[5] - a[12];
    y3r = wn4r * (x0r - x0i);
    y3i = wn4r * (x0i + x0r);
    x0r = a[2] - a[11];
    x0i = a[3] + a[10];
    y4r = wk1r * x0r - wk1i * x0i;
    y4i = wk1r * x0i + wk1i * x0r;
    x0r = a[2] + a[11];
    x0i = a[3] - a[10];
    y5r = wk1i * x0r - wk1r * x0i;
    y5i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] - a[15];
    x0i = a[7] + a[14];
    y6r = wk1i * x0r - wk1r * x0i;
    y6i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] + a[15];
    x0i = a[7] - a[14];
    y7r = wk1r * x0r - wk1i * x0i;
    y7i = wk1r * x0i + wk1i * x0r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y4r + y6r;
    x1i = y4i + y6i;
    a[0] = x0r + x1r;
    a[1] = x0i + x1i;
    a[2] = x0r - x1r;
    a[3] = x0i - x1i;
    x0r = y0r - y2r;
    x0i = y0i - y2i;
    x1r = y4r - y6r;
    x1i = y4i - y6i;
    a[4] = x0r - x1i;
    a[5] = x0i + x1r;
    a[6] = x0r + x1i;
    a[7] = x0i - x1r;
    x0r = y1r - y3i;
    x0i = y1i + y3r;
    x1r = y5r - y7r;
    x1i = y5i - y7i;
    a[8] = x0r + x1r;
    a[9] = x0i + x1i;
    a[10] = x0r - x1r;
    a[11] = x0i - x1i;
    x0r = y1r + y3i;
    x0i = y1i - y3r;
    x1r = y5r + y7r;
    x1i = y5i + y7i;
    a[12] = x0r - x1i;
    a[13] = x0i + x1r;
    a[14] = x0r + x1i;
    a[15] = x0i - x1r;
}

static void cftleaf(int n, int isplt, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 512) {
        cftmdl1(128, a, &w[nw - 64]);
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
        cftmdl2(128, &a[128], &w[nw - 128]);
        cftf161(&a[128], &w[nw - 8]);
        cftf162(&a[160], &w[nw - 32]);
        cftf161(&a[192], &w[nw - 8]);
        cftf162(&a[224], &w[nw - 32]);
        cftmdl1(128, &a[256], &w[nw - 64]);
        cftf161(&a[256], &w[nw - 8]);
        cftf162(&a[288], &w[nw - 32]);
        cftf161(&a[320], &w[nw - 8]);
        cftf161(&a[352], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(128, &a[384], &w[nw - 64]);
            cftf161(&a[480], &w[nw - 8]);
        } else {
            cftmdl2(128, &a[384], &w[nw - 128]);
            cftf162(&a[480], &w[nw - 32]);
        }
        cftf161(&a[384], &w[nw - 8]);
        cftf162(&a[416], &w[nw - 32]);
        cftf161(&a[448], &w[nw - 8]);
    } else {
        cftmdl1(64, a, &w[nw - 32]);
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
        cftmdl2(64, &a[64], &w[nw - 64]);
        cftf081(&a[64], &w[nw - 8]);
        cftf082(&a[80], &w[nw - 8]);
        cftf081(&a[96], &w[nw - 8]);
        cftf082(&a[112], &w[nw - 8]);
        cftmdl1(64, &a[128], &w[nw - 32]);
        cftf081(&a[128], &w[nw - 8]);
        cftf082(&a[144], &w[nw - 8]);
        cftf081(&a[160], &w[nw - 8]);
        cftf081(&a[176], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(64, &a[192], &w[nw - 32]);
            cftf081(&a[240], &w[nw - 8]);
        } else {
            cftmdl2(64, &a[192], &w[nw - 64]);
            cftf082(&a[240], &w[nw - 8]);
        }
        cftf081(&a[192], &w[nw - 8]);
        cftf082(&a[208], &w[nw - 8]);
        cftf081(&a[224], &w[nw - 8]);
    }
}

static void cftrec4(int n, float *a, int nw, float *w)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m;
    
    m = n;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
}

static void cftfx41(int n, float *a, int nw, float *w)
{
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 128) {
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
    } else {
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
    }
}

static void cftf040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r - x3i;
    a[3] = x1i + x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftx020(float *a)
{
    float x0r, x0i;
    
    x0r = a[0] - a[2];
    x0i = a[1] - a[3];
    a[0] += a[2];
    a[1] += a[3];
    a[2] = x0r;
    a[3] = x0i;
}

#ifdef USE_CDFT_THREADS
struct cdft_arg_st {
    int n0;
    int n;
    float *a;
    int nw;
    float *w;
};
typedef struct cdft_arg_st cdft_arg_t;


static void cftrec4_th(int n, float *a, int nw, float *w)
{
    void *cftrec1_th(void *p);
    void *cftrec2_th(void *p);
    int i, idiv4, m, nthread;
    cdft_thread_t th[4];
    cdft_arg_t ag[4];
    
    nthread = 2;
    idiv4 = 0;
    m = n >> 1;
    if (n > CDFT_4THREADS_BEGIN_N) {
        nthread = 4;
        idiv4 = 1;
        m >>= 1;
    }
    for (i = 0; i < nthread; i++) {
        ag[i].n0 = n;
        ag[i].n = m;
        ag[i].a = &a[i * m];
        ag[i].nw = nw;
        ag[i].w = w;
        if (i != idiv4) {
            cdft_thread_create(&th[i], cftrec1_th, &ag[i]);
        } else {
            cdft_thread_create(&th[i], cftrec2_th, &ag[i]);
        }
    }
    for (i = 0; i < nthread; i++) {
        cdft_thread_wait(th[i]);
    }
}


static void *cftrec1_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    m = n0;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}


static void *cftrec2_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl2(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    k = 1;
    m = n0;
    while (m > 512) {
        m >>= 2;
        k <<= 2;
        cftmdl2(m, &a[n - m], &w[nw - m]);
    }
    cftleaf(m, 0, &a[n - m], nw, w);
    k >>= 1;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}
#endif /* USE_CDFT_THREADS */

static void cftfsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2(int n, int *ip, float *a);
    void bitrv216(float *a);
    void bitrv208(float *a);
    void cftf1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftf1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216(a);
        } else {
            cftf081(a, w);
            bitrv208(a);
        }
    } else if (n == 8) {
        cftf040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void bitrv2conj(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += nm;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    }
}

static void bitrv216neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i, x8r, x8i, 
        x9r, x9i, x10r, x10i, x11r, x11i, x12r, x12i, 
        x13r, x13i, x14r, x14i, x15r, x15i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x9r = a[18];
    x9i = a[19];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    x15r = a[30];
    x15i = a[31];
    a[2] = x15r;
    a[3] = x15i;
    a[4] = x7r;
    a[5] = x7i;
    a[6] = x11r;
    a[7] = x11i;
    a[8] = x3r;
    a[9] = x3i;
    a[10] = x13r;
    a[11] = x13i;
    a[12] = x5r;
    a[13] = x5i;
    a[14] = x9r;
    a[15] = x9i;
    a[16] = x1r;
    a[17] = x1i;
    a[18] = x14r;
    a[19] = x14i;
    a[20] = x6r;
    a[21] = x6i;
    a[22] = x10r;
    a[23] = x10i;
    a[24] = x2r;
    a[25] = x2i;
    a[26] = x12r;
    a[27] = x12i;
    a[28] = x4r;
    a[29] = x4i;
    a[30] = x8r;
    a[31] = x8i;
}

static void bitrv208neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    a[2] = x7r;
    a[3] = x7i;
    a[4] = x3r;
    a[5] = x3i;
    a[6] = x5r;
    a[7] = x5i;
    a[8] = x1r;
    a[9] = x1i;
    a[10] = x6r;
    a[11] = x6i;
    a[12] = x2r;
    a[13] = x2i;
    a[14] = x4r;
    a[15] = x4i;
}

static void cftb1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = -a[1] - a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = -a[1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    a[j2] = x1r + x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r - x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = -a[j + 1] - a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = -a[j + 1] + a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = -a[j + 3] - a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = -a[j + 3] + a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i - x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = -a[j0 + 1] - a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = -a[j0 + 1] + a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = -a[j0 - 1] - a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = -a[j0 - 1] + a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i - x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = -a[j0 - 1] - a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = -a[j0 - 1] + a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i - x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = -a[j0 + 1] - a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = -a[j0 + 1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = -a[j0 + 3] - a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = -a[j0 + 3] + a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i - x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftb040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r + x3i;
    a[3] = x1i - x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r - x3i;
    a[7] = x1i + x3r;
}

static void cftbsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2conj(int n, int *ip, float *a);
    void bitrv216neg(float *a);
    void bitrv208neg(float *a);
    void cftb1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftb040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftb1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2conj(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216neg(a);
        } else {
            cftf081(a, w);
            bitrv208neg(a);
        }
    } else if (n == 8) {
        cftb040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void rftfsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr - wki * xi;
        yi = wkr * xi + wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rftbsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr + wki * xi;
        yi = wkr * xi - wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rdft(int n, int isgn, float *a, int *ip, float *w)
{
    void makewt(int nw, int *ip, float *w);
    void makect(int nc, int *ip, float *c);
    void cftfsub(int n, float *a, int *ip, int nw, float *w);
    void cftbsub(int n, float *a, int *ip, int nw, float *w);
    void rftfsub(int n, float *a, int nc, float *c);
    void rftbsub(int n, float *a, int nc, float *c);
    int nw, nc;
    float xi;
    
    nw = ip[0];
    if (n > (nw << 2)) {
        nw = n >> 2;
        makewt(nw, ip, w);
    }
    nc = ip[1];
    if (n > (nc << 2)) {
        nc = n >> 2;
        makect(nc, ip, w + nw);
    }
    if (isgn >= 0) {
        if (n > 4) {
            cftfsub(n, a, ip, nw, w);
            rftfsub(n, a, nc, w + nw);
        } else if (n == 4) {
            cftfsub(n, a, ip, nw, w);
        }
        xi = a[0] - a[1];
        a[0] += a[1];
        a[1] = xi;
    } else {
        a[1] = 0.5 * (a[0] - a[1]);
        a[0] -= a[1];
        if (n > 4) {
            rftbsub(n, a, nc, w + nw);
            cftbsub(n, a, ip, nw, w);
        } else if (n == 4) {
            cftbsub(n, a, ip, nw, w);
        }
    }
}

// input array (any shape >= 1D)
// output array (shape = input.shape.replace(axis, n).insert(0,2))
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void rfft_libfft_f32(
    const float* restrict input, 
    float* restrict output, 
    int d0, int d1, int d2,
    int32_t* restrict temp_ip, float* restrict temp_w, float* restrict temp_a)
{
    void rdft(int n, int isgn, float* a, int* ip, float* w);

    int d3 = d0 * d1;
    int d_out = (d1 >> 1) + 1;

    for (int k = 0; k < d2; k++)
    {
        int dk = k * d3;
        int dm = k * 2 * d_out * d0;
        for (int i = 0; i < d0; i++)
        {                	           
            for (int j = 0; j < d1; j++)
            {
                temp_a[j] = input[dk + j * d0 + i];
            }
            rdft(d1, 1, temp_a, (int *)temp_ip, temp_w);

            for (int m = 2; m < d1; m+=2)
            {
                int index = (m * d0) + 2 * i + dm;
                output[index] = temp_a[m];
                output[index + 1] = -temp_a[m + 1];
            }
            int beta = dm + 2 * i;
            output[beta] = temp_a[0];
            output[beta + 1] = 0;
            output[beta + d3] = temp_a[1];
            output[beta + d3 + 1] = 0;
        }
    }
}

static inline float __norm_sqrt_sum_f32(const float* restrict input, int count)
{
	float sum = 0;
	for (int j = 0; j < count; j++) {
		float item = *input++;
		sum += item * item;
	}
	return sqrtf(sum);
}

static inline void norm_f32(const float* restrict input, int d1, int d2, float* restrict output)
{
	for (int k = 0; k < d2; k++) {
		*output++ = __norm_sqrt_sum_f32(input, d1);
		input += d1;
	}
}

static inline float __mel_f32(const float* restrict input, const short* restrict filter_points, int filter)
{
	short n0 = filter_points[filter];
	short n1 = filter_points[filter+1];
	short n2 = filter_points[filter+2];
	short c0 = n1 - n0;
	short c1 = n2 - n1;
	float sum = 0;
	
	for (int i = 0; i <= c0; i++) {
		float rate = i / (float)c0;
		float value = input[i + n0];
		sum += value * rate;
	}

	for (int i = 1; i <= c1; i++) {
		float rate = i / (float)c1;
		float value = input[i + n1];
		sum += value * (1.0 - rate);
	}

	return sum;
}

// input array (any shape >= 1D)
// output array (same shape as input array except with 0 replaced with num_filter)
// size = input.shape.size(0)
// slot = input.shape.slot(0)
static inline void mel_f32(const float* restrict input, const short* restrict filter_points, int size, int slot, int num_filter, float* restrict output)
{	
	for (int k = 0; k < slot; k++) {
		const float *ip = input + k * size;
		for (int i = 0; i < num_filter; i++) {
			*output++ = __mel_f32(ip, filter_points, i);
		}
	}
}

static inline void clip_f32(const float* restrict input, int count, float min, float max, float* restrict output)
{	
	for (int i = 0; i < count; i++) {
		float value = input[i];
		if (value > max)
			value = max;
		if (value < min)
			value = min;

		output[i] = value;
	}
}

static inline void ln_f32(const float* restrict x, int count, float* restrict result)
{
	for (int i = 0; i < count; i++) {
		*result++ = logf(*x++);
	}
}

/**
 * Enqueue handle->input_size values from given *data pointer to internal window buffer.
 *
 * @param handle Pointer to an initialized handle.
 * @param data Data to enqueue.
 * @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_ERROR (-2) if internal buffer is out of memory.
 */
static inline int fixwin_enqueue(void* restrict handle, const void* restrict data)
{
	fixwin_t* fep = (fixwin_t*)handle;

	if (cbuffer_enqueue(&fep->data_buffer, data, fep->input_size) != 0)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

static inline int mtb_model_raw(const void* handle,
	const void* restrict src, int src_count,
	void* restrict dst, int dst_byte_count)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_run(model, (MTB_ML_DATA_T*)src);
	
	int ret_status = model->lib_error;
	if (ret_status != 0) {printf("ERROR: TensorFlow Lite model inference failed with error code: %d.\r\n", ret_status);}
	CY_ASSERT(ret_status == 0);

	memcpy(dst, model->output, dst_byte_count);

	return IPWIN_RET_SUCCESS;
}

static inline void mtb_model_free(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_deinit(model);

#ifndef IMAI_NO_NPU
	mtb_ml_deinit();
#endif

	if (IMAI_mtb_models_count > 0)
		IMAI_mtb_models_count--;
}

/**
* Initializes a fixwin sampler handle.
*
* @param handle Pointer to a preallocated memory area of fixwin_handle_size() bytes to initialize.
*
* @param input_size Number of bytes to enqueue.
* @param count Number of items (of size input_size) in each window
*/
static inline void fixwin_init(void* restrict handle, int input_size, int count)
{
	fixwin_t* fep = (fixwin_t*)handle;
	fep->input_size = input_size;

	char* mem = ((char*)handle) + sizeof(fixwin_t);

	int data_buffer = input_size * count;
	
	cbuffer_init(&fep->data_buffer, mem, data_buffer);
}

static inline int mtb_model_soft_reset(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;

	cy_rslt_t result = mtb_ml_model_rnn_reset_all_parameters(model);

	if (result != MTB_ML_RESULT_SUCCESS)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

#if defined(IMAI_PROFILING_LOG)
#define MODEL_PROFILING MTB_ML_LOG_ENABLE_MODEL_LOG
#elif defined(IMAI_PROFILING)
#define MODEL_PROFILING MTB_ML_PROFILE_ENABLE_MODEL
#endif

#define IMAI_MAX_MTB_MODELS 4
uint8_t IMAI_mtb_models_count = 0;
mtb_ml_model_t* IMAI_mtb_models[IMAI_MAX_MTB_MODELS];

void IMAI_mtb_models_print_info() {
	if (IMAI_mtb_models_count < 1)
		return;

	printf("Loaded %ld models:\r\n", (long int)IMAI_mtb_models_count);
	for (uint32_t index = 0; index < IMAI_mtb_models_count; index++) {
		printf("Model %ld:\r\n", (long int)index);
		mtb_ml_utils_print_model_info(IMAI_mtb_models[index]);
		printf("\r\n");
	}
	printf("\r\n");
}

void IMAI_mtb_models_profile_log() {
	if (IMAI_mtb_models_count < 1)
		return;

	printf("Profiling %ld models:\r\n", (long int)IMAI_mtb_models_count);
	for (uint32_t index = 0; index < IMAI_mtb_models_count; index++) {
		printf("Model %ld: %s:\r\n", (long int)index, IMAI_mtb_models[index]->name);
		mtb_ml_model_profile_log(IMAI_mtb_models[index]);
		printf("\r\n");
	}
	printf("\r\n");
}

static int mtb_init(const void* handle, uint8_t* model_bin, unsigned int model_size, uint8_t* arena_buffer, int arena_size, int npu_priority, char model_name[]) {
	mtb_ml_model_t** model_obj = (mtb_ml_model_t**)handle;

	mtb_ml_model_bin_t model = {
		.model_bin = model_bin,
		.model_size = model_size,
		.arena_size = arena_size
	};

	strncpy(model.name, model_name, MTB_ML_MODEL_NAME_LEN - 1);
	model.name[MTB_ML_MODEL_NAME_LEN - 1] = '\0';

	mtb_ml_model_buffer_t buffer = {
		.tensor_arena = arena_buffer,
		.tensor_arena_size = arena_size
	};

	if (mtb_ml_model_init(&model, &buffer, model_obj) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

#ifndef IMAI_NO_NPU
	if (mtb_ml_init(npu_priority) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;
#endif

#if defined(IMAI_PROFILING) || defined(IMAI_PROFILING_LOG)
	if (mtb_ml_model_profile_config(*model_obj, MODEL_PROFILING) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

	IMAI_mtb_models[IMAI_mtb_models_count++] = *model_obj;
#endif

	return IPWIN_RET_SUCCESS;
}

#ifndef __CLOSE_HOOKS
	#define __CLOSE_HOOKS() do { } while(0)
#endif
#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } } while(0)
#define __RETURN_ALWAYS(_exp) __CLOSE_HOOKS(); return (_exp)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_BREAK_EMPTY_END(_exp) {  int __ret = (_exp); if(__ret == -1 || __ret == -3) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_CANCEL_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) { __CLOSE_HOOKS(); return 0; } if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __BREAK_ERROR(_exp) {  int __ret = (_exp); if(__ret < 0) break; }
#define __CONTINUE_ON_EMPTY(_exp) {  int __ret = (_exp); if(__ret < -1) { __CLOSE_HOOKS(); return __ret; } }

/*
* Try read data from model.
* 
*  @param data_out Output features. Output float[10].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_dequeue(float *restrict data_out) {    
    __HOOK_REGION(true, 0);
    while(1) {
        __RETURN_ERROR_BREAK_EMPTY(fixwin_dequeue(_K2, _K1, 256, 160));
        hannmul_f32(_K1, _K11, 1, 512, 1, _K15);
        rfft_libfft_f32(_K15, _K16, 1, 512, 1, _K18, _K19, _K20);
        norm_f32(_K16, 2, 257, _K22);
        mel_f32(_K22, _K23, 257, 1, 30, _K27);
        clip_f32(_K27, 30, 0.000316227766016, 3.40282347E+38, _K28);
        ln_f32(_K28, 30, _K3);
        __RETURN_ERROR_BREAK_EMPTY(fixwin_enqueue(_K5, _K3));
    }
    __RETURN_ERROR(fixwin_dequeue(_K5, _K4, 50, 6));
    __HOOK_REGION(false, 0);
    __HOOK_REGION(true, 1);
    __RETURN_ERROR(mtb_model_raw(_K10, _K4, 1500, data_out, 40));
    __HOOK_REGION(false, 1);
    return 0;
}

/*
* Try write data to model.
* 
*  @param data_in Input features. Input float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_enqueue(const float *restrict data_in) {    
    __HOOK_REGION(true, 0);
    __RETURN_ERROR(fixwin_enqueue(_K2, data_in));
    __HOOK_REGION(false, 0);
    return 0;
}

/*
* Closes and flushes streams, free any heap allocated memory.
* 
*/
void IMAI_finalize(void) {    
    mtb_model_free(_K10);
}

/*
* Resets windows and neural networks(i.e. RNNs) to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_soft_reset(void) {    
    fixwin_init(_K2, 8, 256);
    fixwin_init(_K5, 120, 50);
    __RETURN_ERROR(mtb_model_soft_reset(_K10));
    return 0;
}

/*
* Initializes buffers to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_init(void) {    
    fixwin_init(_K2, 8, 256);
    fixwin_init(_K5, 120, 50);
    __RETURN_ERROR(mtb_init(_K10, _K7, 39840, _K6, 16384, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0x23, 0x41, 0xbb, 0x6a, 0xb5, 0x4c, 0x6c, 0x4c, 0x84, 0x54, 0xca, 0xd7, 0xf1, 0x30, 0xa2, 0x93},
    .api_type = IMAI_API_TYPE_QUEUE,
    .prefix = "IMAI_",
    .buffer_mem = {
        .size = 10256,
        .peak_usage = 8208,
    },
    .static_mem = {
        .size = 25992,
        .peak_usage = 25984,
    },
    .readonly_mem = {
        .size = 41952,
        .peak_usage = 41952,
    },
    .func_count = 5,
    .func_list = (IMAI_func_def[]) {
        {
            .name = "IMAI_dequeue",
            .description = "Try read data from model.",
            .fn_ptr = IMAI_dequeue,
            .attrib = 3,
            .param_count = 1,
            .param_list = (IMAI_param_def[]) {
                {
                    .name = "data_out",
                    .attrib = IMAI_PARAM_OUTPUT,
                    .rank = 1,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "Labels",
                            .size = 10,
                            .labels = (label_text_t[]) { "unlabeled","Back_Left","Back","Back_Right","Front_Left","Front","Front_Right","Left","Noise","Right" },
                        },
                    },
                    .count = 10,
                    .bytes = 40,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 16.666666666666668,
                    .shift = 0,
                    .scale = 0,
                    .offset = 0,
                },
            },
        },
        {
            .name = "IMAI_enqueue",
            .description = "Try write data to model.",
            .fn_ptr = IMAI_enqueue,
            .attrib = 3,
            .param_count = 1,
            .param_list = (IMAI_param_def[]) {
                {
                    .name = "data_in",
                    .attrib = IMAI_PARAM_INPUT,
                    .rank = 1,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "",
                            .size = 2,
                        },
                    },
                    .count = 2,
                    .bytes = 8,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 16000,
                    .shift = 0,
                    .scale = 1,
                    .offset = 0,
                },
            },
        },
        {
            .name = "IMAI_finalize",
            .description = "Closes and flushes streams, free any heap allocated memory.",
            .fn_ptr = IMAI_finalize,
            .attrib = 10,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_soft_reset",
            .description = "Resets windows and neural networks(i.e. RNNs) to initial state.",
            .fn_ptr = IMAI_soft_reset,
            .attrib = 67,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_init",
            .description = "Initializes buffers to initial state.",
            .fn_ptr = IMAI_init,
            .attrib = 7,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
    },
};

IMAI_api_def *IMAI_api(void) {
    return &_IMAI_api_def;
}

