/*
* ImagiNet Compiler 5.13.5501.65534+6ddbc592e16d83c41e7b0b9321278834ef733ad3
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 11:21:03 UTC. Any changes will be lost.
* 
* Model ID  c6b5453f-0184-4998-91e7-e952c830f4c5
* 
* Memory    Size                      Efficiency
* Buffers   10256 bytes (RAM)         80 %
* State     25992 bytes (RAM)         100 %
* Readonly  40896 bytes (Flash)       100 %
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param data_out Output features. Output float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_dequeue(float *data_out);
* 
*  @description: Try write data to model.
*  @param data_in Input features. Input float[1].
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
    0x0000001c, 0x00000090, 0x000000e8, 0x0000829c, 0x000082ac, 0x000096dc, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000024, 0x00000004, 0x00000008, 0x6579616c, 0x30325f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffff7d2a, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x00000027, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x00000026, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x00000028, 0x000081b0, 0x000081a8, 0x00008118, 
    0x000080c8, 0x00008078, 0x00005068, 0x00004458, 0x00003a88, 0x00003a44, 0x00003a28, 0x00003a08, 
    0x000039e8, 0x000039c8, 0x000021b8, 0x00002128, 0x00001518, 0x000014c8, 0x00000270, 0x00000160, 
    0x00000148, 0x00000134, 0x00000114, 0x0000010c, 0x00000104, 0x000000fc, 0x000000f4, 0x000000ec, 
    0x000000e4, 0x000000dc, 0x000000d4, 0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 
    0x000000a4, 0x0000009c, 0x00000094, 0x00000074, 0x00000004, 0xffff7e3e, 0x00000004, 0x00000060, 
    0x00000010, 0x00000000, 0x000e0008, 0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 
    0x00040008, 0x00000006, 0x00000004, 0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 
    0x8e4a3d7d, 0x46dea501, 0x00000003, 0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 
    0xffff7eaa, 0x00000004, 0x00000010, 0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffff6b64, 
    0xffff6b68, 0xffff6b6c, 0xffff6b70, 0xffff6b74, 0xffff6b78, 0xffff6b7c, 0xffff6b80, 0xffff6b84, 
    0xffff6b88, 0xffff6b8c, 0xffff6b90, 0xffff6b94, 0xffff6b98, 0xffff6b9c, 0xffff6ba0, 0xffff7f06, 
    0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xffff7f22, 0x00000004, 
    0x00000004, 0x00000001, 0xffff7f32, 0x00000004, 0x00000008, 0xbc29df44, 0x3c29df49, 0xffff7f46, 
    0x00000004, 0x00000100, 0x3e832ecc, 0x3e2bd1fb, 0xbecd639e, 0xbc44bac4, 0xbdf95f71, 0xbe16d5c5, 
    0x3e006853, 0x3ee57ed6, 0xbeb5d89a, 0x3e95b8be, 0x3d9a9af3, 0x3e72256d, 0xbebc9019, 0x3ee885f1, 
    0xbe8df1c9, 0xbddeef41, 0x3ed60dd4, 0xbe81792f, 0x3e953800, 0x3d27c090, 0x3ed40597, 0xbe68b698, 
    0x3e06d91e, 0x3dec09cb, 0x3e28c1bf, 0xbe97a8d3, 0x3e2a8e10, 0x3e4b38e1, 0xbd8c7015, 0x3e892cca, 
    0x3e48592b, 0xbe90e340, 0xbe435324, 0x3eaf457b, 0xbe832c78, 0x3da17f8e, 0x3cb81159, 0x3d7dc4c9, 
    0x3e7032e0, 0x3ea03b0b, 0x3ecb08ab, 0xbe6aca2c, 0xbdac01f9, 0x3e154161, 0xbe838003, 0xbbb8deef, 
    0xbe442755, 0x3e942b5c, 0x3eb5e446, 0xbed95351, 0xbea42b26, 0x3e43d8d6, 0xbe29d0ea, 0x3e8aa5fa, 
    0x3e623be2, 0xbeba79c6, 0xbe15f721, 0x3eb6874f, 0x3d9c10b5, 0xbdd1d483, 0xbc2142f0, 0x3ea0fc51, 
    0x3e856ebb, 0x3eb9b91d, 0xffff8052, 0x00000004, 0x00001248, 0xbe4f2778, 0xbe16cc75, 0xbe08fa66, 
    0xbdd51a08, 0x3c09189b, 0xbd430969, 0xbd9125a2, 0x3e8f0f30, 0x3e37bfbb, 0xbdd2f9aa, 0x3dd74805, 
    0x3e647940, 0xbd2b59f8, 0x3daa63de, 0xbd746ebd, 0x3d951ded, 0x3b4865c4, 0xbb8af223, 0x3e2f1b2e, 
    0x3dac4162, 0x3df1fbdb, 0xbe0d8a81, 0x3e263ea1, 0x3df91a5d, 0xbe67af08, 0x3d8bd934, 0xbe6490cb, 
    0xbcde24b4, 0xbe4c236b, 0x3df64030, 0x3da90d4a, 0x3dab58fb, 0x3dd6eaa0, 0x3e1dcb61, 0x3d1b5cbc, 
    0xbb49245f, 0xbd2bc157, 0xbd2d4f2c, 0x3da5f00a, 0xbd07a0d3, 0x3dd8453e, 0x3e234852, 0xbd829d4f, 
    0x3d20e43d, 0x3dbfd0b7, 0x3d2c31b1, 0xbd9230c1, 0xbc674e5e, 0xbe186322, 0x3e7fe300, 0xbd911004, 
    0xbde4dbea, 0xbe0989ee, 0xbdda21bd, 0x3defd0b3, 0x3d5dc506, 0x3e0a5d35, 0xbe46b2cb, 0x3c97b4e8, 
    0x3db595f1, 0x39f15061, 0x3d9100de, 0xbcdd566f, 0xbd06311d, 0xbda6f2a2, 0x3e551200, 0x3da9ae79, 
    0xbdb77f26, 0xbcdac4c5, 0x3d65abda, 0x3e29b004, 0x3d278b21, 0x3dd494c4, 0x3e0be62c, 0x3c9df767, 
    0x3d1ff5a1, 0xbdb865cb, 0xbe192a04, 0x3e3fa7ab, 0x3dade5bd, 0x3dfb0b1e, 0xbdf57e00, 0x3d8e82b0, 
    0x3c3d44db, 0xbe45a97e, 0xbe0159e1, 0x3e16171e, 0xbdf1219b, 0xbe040165, 0xbe5e6168, 0x3d199c35, 
    0x3dedbb71, 0x3e19e170, 0x3e704446, 0xbd97fdc0, 0x3dc8f91b, 0xbe09c36b, 0xbd330f8f, 0x3e3d559c, 
    0xbd99edef, 0xbe74b2cf, 0x3c3f02d7, 0x3d0727e2, 0x3e38177f, 0xbb91a5e9, 0x3d70bd79, 0xbdda6054, 
    0xbdc2682d, 0x3d4fa526, 0x3d6d2917, 0x3d213208, 0x3e32766c, 0xbd904158, 0x3e4f3bdd, 0x3e09ecb8, 
    0x3c958c52, 0x3e3d9db1, 0xbdfef5a0, 0xbd73fb50, 0xbd638c2d, 0xbde59582, 0xbd6b7816, 0x3e2e60d1, 
    0xbd57aace, 0x3d72ecfb, 0xbe2d49cb, 0xbe869f5e, 0xbdd6b475, 0x3e00e627, 0x3da139b8, 0x3d617737, 
    0x3e216917, 0xbdfa6946, 0xbded0a1d, 0x3e230c77, 0x3dee00bc, 0xbe2d8015, 0x3d1550bc, 0x3e253655, 
    0xbe5503a4, 0x3dd088ba, 0x3d8fff71, 0xbe131d2e, 0xbda30c42, 0x3e0d218d, 0x3e19ba32, 0x3e09596b, 
    0xbe0a6e0f, 0x3da98bf3, 0xbe100c91, 0x3d94eeeb, 0x3da98ff6, 0xbe26a111, 0x3debff0c, 0x3e499611, 
    0x3c9b9fc1, 0xbe48cd88, 0x3e0f6601, 0x3e23d341, 0xbe4919bb, 0xbd17c843, 0xbe5349d8, 0x3dfdfe03, 
    0x3ddfa6d8, 0x3e2f9b37, 0xbca9c863, 0x3e1d4611, 0xbe02d203, 0xbe717ecc, 0xbcf7920a, 0xbe7fb378, 
    0x3e325d1f, 0x3dac93c4, 0x3e3fffff, 0x3e1931f8, 0x3e1fe9fd, 0xbd5ccf6e, 0x3cff865e, 0x3c2d2793, 
    0x3dcebd72, 0x3ddc7c1f, 0xbe3cc9d1, 0x3d83e7ed, 0xbd5da9d8, 0xbd36eccc, 0xbdfb1127, 0x3e096e33, 
    0xbdeb6942, 0xbba7903d, 0x3e23fd0f, 0xbe259a5c, 0x3e0468a3, 0xbd943c04, 0x3e030f1a, 0x3df321da, 
    0xbda336ca, 0x3d45039f, 0xbd3b358c, 0xbe0b7edc, 0xbe026d65, 0x3d32ab31, 0xbd4f0a12, 0x3e4ba821, 
    0xbd36f1a1, 0x3e2d9ebe, 0x3e102bc6, 0xbe2eaff0, 0xbe18928d, 0xbe2beaf9, 0xbe299931, 0x3e0c16f3, 
    0xbd9d6c74, 0xbd14fa41, 0x3d7dd54f, 0x3d710c8b, 0xbc9aad84, 0x3da7da13, 0x3e2530f1, 0xbe0c6015, 
    0x3e8485f1, 0x3da31d92, 0xbdc152a9, 0x3de313a4, 0xbe0e7567, 0x3de62f9b, 0xbdf7cc6d, 0xbdba8990, 
    0xbd31d352, 0xbdcd65c4, 0x3e1d8052, 0xbe11250a, 0x3e3edc04, 0xbe1adf80, 0xbe2630b8, 0x3da9f97a, 
    0xbe3d42f9, 0xbe447bbb, 0xbd01cf0b, 0xbe2ad990, 0x3e071480, 0x3d04ad33, 0xbd015744, 0x3dd64200, 
    0x3e187832, 0x3dfe510f, 0xbe034b8c, 0xbd796451, 0x3e167fd2, 0xbd843692, 0xbce600da, 0xbe058e6e, 
    0xbe40fee8, 0x3cb84bb6, 0xbcea727f, 0xbe7ce0eb, 0x3e134747, 0x3b915456, 0xbe622495, 0x3befc45e, 
    0x3c1d2726, 0xbc1e3e86, 0xbd7b3733, 0xbd954620, 0xb6ca1108, 0xbcc332f8, 0xbe02533f, 0xbc657c3b, 
    0x3ca23035, 0xbd0f9d5f, 0x3e1fa059, 0x3e096eb5, 0x3be1ab3d, 0x3da202c4, 0xbcb02872, 0xbde7f164, 
    0xbd6f83f5, 0x3e3bf528, 0x3c48c2aa, 0x3e012758, 0x3e05f403, 0xbc235020, 0x3df1582d, 0xbe66432e, 
    0x3d9cdb69, 0x3e3795ad, 0x3d7adac6, 0xbde0bade, 0xbda017dd, 0x3d7bbcdd, 0x3e62b055, 0x3e723211, 
    0xbe3dcb63, 0xbe3e7111, 0x3e0c1054, 0x3cb1d800, 0xbe019a95, 0x3e3dc7db, 0xbd85f701, 0x3e1a8486, 
    0x3e231f61, 0x3d4e73da, 0x3e531f06, 0xbcb85757, 0xbc5d86b0, 0xbdca53b9, 0xbbc29578, 0x3e4b5d1f, 
    0x3c92f3c0, 0x3e46316a, 0xbaa96795, 0x3d3a9dba, 0x3e062265, 0xbdb16f8d, 0xbe374dec, 0x3c5b1970, 
    0x3e46e915, 0xbdc4b9eb, 0x3e40cbf5, 0xbdd3def0, 0x3d96c8eb, 0x3e65df73, 0xbd833ced, 0x3b388738, 
    0x3d529bb6, 0x3e37123e, 0x3e2efd41, 0x3dfa7b2f, 0x3ddd9d19, 0xbe630e55, 0xbe20c888, 0x3bfe84a7, 
    0x3dfaed1f, 0xbdab7699, 0xbe0aaae2, 0x3d001a41, 0x3e12752d, 0xbe0afebc, 0xbd101d45, 0x3c77067c, 
    0xbcc0ed6a, 0x3e8015ed, 0x3e199504, 0xbe4629c9, 0xbe144d04, 0xbd6e3912, 0x3b667f1f, 0x3e3c981c, 
    0x3e00a881, 0xbe05628a, 0x3d971358, 0xbe01da5c, 0xbdcbf507, 0xbcda4c33, 0xbe0bea95, 0x3e0270f9, 
    0x3c8adf44, 0x3e032068, 0xbdfbf830, 0xbbfcf33c, 0xbdfa6522, 0x3dff27d1, 0xbe04166a, 0xbe142e12, 
    0xbdb93877, 0xbc19fe85, 0x3d951672, 0x3e4f6001, 0xbd8e727b, 0x3d86285e, 0x3a8b87e9, 0xbd80a269, 
    0xbe289471, 0xbdf97339, 0xbd62718d, 0xbe3c3b49, 0x3ba3ba10, 0xbcef9136, 0xbe504fa6, 0x3dc9e59f, 
    0xbce94223, 0xbe2b778e, 0xbd282301, 0xbd1a5227, 0xbe43cbe3, 0xbe696b4b, 0x3cf3dc13, 0xbe390edf, 
    0xbabf67a3, 0x3d66c041, 0xbd173b1a, 0xbe2dafef, 0xbe02dd23, 0x3e32138a, 0x3e02fee1, 0xbd973153, 
    0x3e3c4acd, 0x3d2f57c1, 0xbd9df351, 0x3dd8c503, 0x3d4dffee, 0xbe769e89, 0xbd1e8394, 0xbe9d343b, 
    0xbdc438a1, 0xbc2d1bdd, 0xbe218ed4, 0x3e01e8e4, 0xbe60a3d6, 0x3cc450d7, 0x3d42b56e, 0xbe46e146, 
    0x3d174584, 0x3e217235, 0xbe0449cd, 0xbbe17595, 0xbd6f4058, 0xbc3615f8, 0xbd99cb56, 0x3e2e45c2, 
    0xbb2bde70, 0x3ceb9a63, 0xbd262577, 0xbe2b412e, 0xbde5d857, 0xbe048f46, 0x3d989db4, 0x3e0e11f5, 
    0x3d035635, 0xbe681075, 0x3cbd8661, 0xbe1f4e3b, 0x3e7501dd, 0xbe395b72, 0xbe81f989, 0x3cf2d0bf, 
    0xbdbfca19, 0xbdb76306, 0xbdb67cab, 0x3d9c1971, 0x3e219aba, 0xbe024a01, 0x3dbf1a64, 0x3dc7c20b, 
    0xbe00c518, 0x3dc0abea, 0xbe26086f, 0xbe0548e2, 0xbde53cf4, 0x3cf2b7bd, 0x3e4cca46, 0xbd01c692, 
    0xbdad64fc, 0xbdd9c0ad, 0xbe10db4f, 0x3cb6e16a, 0x3dac7e4f, 0xbc840904, 0xbe643851, 0xbe608435, 
    0x3e30a70c, 0x3e79815f, 0x3dd881f4, 0x3e4e4cad, 0xbe7ed621, 0xbe7decb2, 0x3d43f2be, 0x3ddde76a, 
    0x3de7d05e, 0xbe23c8bd, 0x3e473a50, 0x3be54225, 0x3e041276, 0x3d4fa97a, 0x3e308c93, 0x3e6b4527, 
    0x3dff43f2, 0x3c3468a0, 0x3c9648d7, 0xbe5f6ead, 0x3e19fc99, 0x3e48631e, 0xbde7aed7, 0x3c6ce998, 
    0xbe7530d7, 0x3dd7aabb, 0x3e37100b, 0x3d0cc447, 0xbd00c6fa, 0x3e147be9, 0xbe1c5cc5, 0x3d9ae9c5, 
    0x3d500c82, 0xbd89c075, 0x3bdbab48, 0x3b5a73da, 0xbe0577a7, 0x3e1b046c, 0xbc6449dd, 0x3d706467, 
    0xbd1727a8, 0x3ddc4b55, 0x3db4d867, 0xbe0d6e4b, 0xbdf85314, 0xbdf7be70, 0x3e00ab15, 0x3e2b9570, 
    0x3da93f50, 0x3e17c28d, 0x3de87652, 0x3b9d3a03, 0xbdf44f5a, 0x3ce51755, 0x3df654ec, 0x3e1e645c, 
    0x3e258eb2, 0x3d16ee08, 0xbdef91d8, 0xbcfc5335, 0xbe0297d6, 0x3ce38ca6, 0xbb9b72a1, 0x3e60da45, 
    0xbe157870, 0xbe332284, 0x3e0043da, 0xbdbec062, 0xbdabfea5, 0x3de45b2d, 0x3ddced25, 0x3c9fd675, 
    0x3e24ddae, 0xbb29f1b7, 0x3d2cd6a2, 0x3d439993, 0xbcaddd1f, 0xbd40fa29, 0x3df5a023, 0xbcdd1add, 
    0x3d0587fa, 0xbcaff81b, 0xbe5ac8db, 0xbcb997e9, 0x3d17d3ed, 0xbde01fd5, 0x3dcb59c7, 0x3d1c52cd, 
    0x3dcab640, 0x3e5be682, 0x3db08911, 0x3e2528a6, 0x3d59b847, 0x3d1a5fca, 0x3e26f568, 0x3df728bf, 
    0xbce9cccb, 0x3e5033ab, 0x3d00c5f5, 0xbe2d3317, 0xbe43aade, 0x3ddf95eb, 0xbdf89d02, 0x3e354263, 
    0x3d9ee984, 0xbe4d944b, 0x3d904230, 0xbe3cf7f5, 0x3dc67d93, 0xbe2cf221, 0xbdab6b73, 0xbdb88fc6, 
    0xbe5f2df2, 0x3ddd795b, 0xbd8cd2e7, 0xbd5d6bb6, 0x3e3d8e3d, 0x3d9e2e38, 0x3e00b67e, 0x3c349f8c, 
    0x3e1a2230, 0xbe0c4d29, 0x3a40b4f1, 0x3d9ab90b, 0x3da79172, 0x3de08cd5, 0xbe3344f1, 0xbc8ab954, 
    0x3e02e24f, 0xbe316854, 0x3e087e57, 0xbe370949, 0xbe528b60, 0x3e23d312, 0xbe0deeb2, 0xbd43b0df, 
    0xbe06fdb8, 0xbda03e2f, 0x3d9e76c6, 0x3e3c3d80, 0x3d221403, 0xbe39b433, 0xbd8b8e7a, 0x3e0bdaa9, 
    0x3df2ddef, 0xbe2ea82d, 0xbcde2bda, 0x3ce91921, 0x3db2c760, 0xbcda45c1, 0xbd65f265, 0x3e6e2bf8, 
    0x3deedb17, 0x3de16150, 0xbe0089b9, 0x3ce7ca29, 0xbe075182, 0xbe2af39d, 0xbe0364cf, 0xbcc05a90, 
    0x3d630fa7, 0xbd85a036, 0x3ddc90e0, 0xbd884891, 0x3ca8ed61, 0xbe3f097e, 0xbc260cd0, 0x3dba9c9c, 
    0xbd56bec9, 0x3b8f24eb, 0x3e28695b, 0x3cdcd35a, 0x3e8a1682, 0xbdfffd09, 0xbd5231f7, 0xbe893544, 
    0x3ddeab9f, 0x3c12f3ac, 0xbd1a499d, 0x3db2a88f, 0xbd602362, 0x3d8b2804, 0x3e4d112e, 0x3e2b79b9, 
    0xbd88e459, 0x3a810626, 0xbe16abb3, 0xbe262410, 0xbe018125, 0xbdc01f0b, 0x3df0e834, 0x3dbde293, 
    0x3e0a0233, 0x3ca6d57e, 0x3e20be30, 0x3dd03b47, 0xbd85acfa, 0x3dc54fab, 0xbd1ee70c, 0xbe405698, 
    0x3d9dc1f5, 0x3e316c40, 0x3e1fd728, 0x3e3f9645, 0x3ce95f8e, 0x3d1d31fc, 0x3d6b05b7, 0xbe07d22f, 
    0xbe1a5916, 0xbe282a8a, 0xbe4fbd67, 0x3bbd30b1, 0x3e2575eb, 0xbe26d60a, 0xbd308d86, 0xbda52059, 
    0xbdab8fee, 0x3e318d9c, 0x3d5b3176, 0xbe33d10d, 0x3ddaadac, 0xbe302121, 0xbd93c695, 0x3da80577, 
    0x3d771851, 0xbd4aac28, 0xbe329e6f, 0xbdc7db92, 0xbde16748, 0x3ba15b60, 0x3c5a07f5, 0x3cf6d10d, 
    0x3d71709f, 0xbdb629b9, 0x3dc97d4f, 0xbe8c1a92, 0x3d19cdc9, 0x3d983006, 0xbe43567b, 0xbe3da5b1, 
    0x3e4d2b8e, 0x3e3dd33c, 0xbe1ca52a, 0x3d739b21, 0xbe65d31f, 0x3d342b1d, 0xbc42cd51, 0xbe39caa3, 
    0x3e524b71, 0xbe4b1077, 0xbe592de9, 0x3bf19b3d, 0x3e4637ee, 0x3e3e1422, 0x3e01f9b6, 0xbdd019f9, 
    0xbd9a6038, 0x3a5df474, 0xbe0490b8, 0xbe5291e1, 0x3ca32b2e, 0xbe169e34, 0xbdfb6ec2, 0x3d28230a, 
    0xbdf15e32, 0xbdbef569, 0xbe27a073, 0x3df0abc3, 0x3e17b1a9, 0x3e903541, 0xbde829e4, 0xbdc6c194, 
    0xbcc24fbc, 0xbe7c8483, 0xbe4e935e, 0x3d4be7cf, 0x3d953ecc, 0x3e1dc6fb, 0x3c40e19f, 0x3d5223be, 
    0xbe1d0a96, 0x3d463fea, 0xbd27d5a2, 0x3c01255f, 0x3db33598, 0xbd025c6a, 0x3e238840, 0xbdafb96f, 
    0x3de545e6, 0xbdd27e22, 0x3e6afc6e, 0xbdc114cc, 0x3e20061e, 0xbbf94d22, 0xbe1cca4e, 0xbe446a65, 
    0xbdf187a6, 0xbbac7fe3, 0xbd79ad52, 0x3e83578f, 0x3e25f72d, 0x3e535035, 0xbdd0c440, 0xbdf50105, 
    0x3d86f741, 0xbdd72fad, 0x3de233e6, 0x3d8a7d4e, 0x3e1b32e2, 0xbdbdd8c0, 0x3db657cb, 0x3d3619c0, 
    0xbe1b03e6, 0x3e1a4070, 0x3d9fcefa, 0xbdcd7467, 0x3de99606, 0xbd89b319, 0xbe26b926, 0x3e09b794, 
    0xbdfa4d8b, 0xbdb805e2, 0x3d073863, 0xbe0bb6ab, 0x3e174825, 0x3e1e23bb, 0xbd8658ee, 0xbe665977, 
    0xbd8dcbfe, 0x3e5609f5, 0x3d974997, 0x3d18b1d8, 0xbde2dbc0, 0xbe1b27ee, 0xbdc12ced, 0xbcc38f4b, 
    0xbc2308ce, 0x3e163b22, 0x3d85ff6e, 0x3d3f98eb, 0x3e57902b, 0xbe368c85, 0xbce0a582, 0x3e637c65, 
    0x3e57467c, 0xbe70cdf6, 0x3dc2311f, 0x3e0ff1e4, 0x3e39a47c, 0xbe01bacd, 0x3d2fd2c7, 0x3d4c5a91, 
    0x3e38d6e8, 0xbd6b5484, 0x3e0b565f, 0x3c4a853f, 0x3c729629, 0x3d19a1a3, 0xbde24236, 0x3d74bcc5, 
    0xbe1fd6b0, 0x3da7376a, 0x3e0f36c3, 0xbdcf2587, 0x3d661fdb, 0x3d7183ae, 0xbdcfe0cb, 0x3e270c70, 
    0x3dc28f48, 0x3e1f593f, 0x3c527310, 0x3e0b6cfd, 0xbd98bd99, 0x3d83f30b, 0xbdc2b525, 0x3e4a5370, 
    0xbd0d533b, 0xbdf63801, 0x3d9598d2, 0xbe2768c2, 0xbdd484b0, 0xbc490c76, 0x3dcb1e70, 0x3b83c6c0, 
    0x3da4641e, 0x3e407592, 0xbe20a063, 0x3e16e94a, 0xbc4d2c91, 0x3e3c2fac, 0xbe5ddb27, 0x3d3127ab, 
    0x3d310a76, 0x3d6cf83e, 0xbd3f8562, 0x3e1e838c, 0x3e0ddeb1, 0xbd9107a3, 0x3dc9022e, 0xbe387d2d, 
    0xbe566321, 0x3e3207c7, 0x3db7a397, 0x3e02533d, 0xbde66215, 0xbcc1d24c, 0xbe0b2e5d, 0x3d3be1ba, 
    0x3c1f6fa4, 0x3d3ce9d3, 0x3e5e6621, 0x3db3df22, 0x3e22ade3, 0x3e2083ed, 0x3dff21f9, 0x3b1a187f, 
    0x3e21b5d4, 0x3dce9057, 0x3e50de7b, 0x3e0f535a, 0xbe839f6f, 0xbe461e35, 0x3cd8385e, 0xbe10f7fe, 
    0xbe295503, 0xbd868e98, 0xbe25bf3b, 0xbe27e3f3, 0xbb362874, 0xbe3533ce, 0xbc932af6, 0xbd1c241e, 
    0x3e2390fe, 0x3d7511d2, 0x3d523a7e, 0x3e3e9be6, 0x3d9a3cc8, 0x3d0499ad, 0xbd5db3e2, 0xbb04e328, 
    0x3e66bd5a, 0x3d24560d, 0x3d2cf041, 0x3d2ea065, 0x3d5f29d5, 0xbdcf47ec, 0x3e62b162, 0xbe3d3195, 
    0xbe478fb7, 0xbe2a8101, 0x3d01ebf2, 0xbdc69983, 0x3e538b98, 0x3db180dc, 0xbe074305, 0x3d6f7a1a, 
    0xbb0ec0f7, 0xbe29f52e, 0xbd9c5866, 0x3d43c4c0, 0xbd65879a, 0x3d66411d, 0xbd9a21d6, 0x3e34504c, 
    0xbdf17ac9, 0xbe32f1fe, 0x3e5b2eb5, 0x3d7e4dfa, 0xbdfa1285, 0x3e1f4961, 0x3c6dfce3, 0x3dc1844f, 
    0x3dbd78f9, 0xbdf16d70, 0xbe125325, 0x3e340cf9, 0x3e175593, 0x3d1c24b9, 0xbe0c0e78, 0xbd0e3f08, 
    0xbe8ab9a2, 0x3d368683, 0x3da6c13e, 0xbe2aa781, 0x3cad1745, 0x3e86cb1c, 0xbe5e529c, 0x3ce2aead, 
    0xbe009230, 0xbe0e7202, 0xbdf02855, 0x3d076fe5, 0xbe274303, 0x3e062ad4, 0x3c183a4a, 0x3e440f62, 
    0xbd6e3178, 0x3e411b66, 0xbe0ad742, 0xbe06df45, 0xbe1da446, 0xbd995d9b, 0xbbb088d0, 0xbe1841b7, 
    0x3e50d918, 0x3db37cf6, 0xbdd9bd2f, 0xbe5f1177, 0x3d444aa6, 0xbd3107b4, 0xbe77f519, 0x3e22625c, 
    0x3c37e098, 0x3bef3da9, 0xbc8b6bf8, 0xbc923d6b, 0x3e3d35f2, 0x3cd9444d, 0xbda78d66, 0xbb3430ac, 
    0x3e206655, 0x3e2f83c8, 0x3ce3b6ef, 0xbd74b7b7, 0xbddc9c8f, 0x3d89a627, 0x3e271ea6, 0xbd98d4ad, 
    0xbdf3774f, 0xbe1267ff, 0x3d8d78e9, 0xbe48791e, 0x3dea9682, 0x3dbc632a, 0xbde49212, 0x3e01dfcd, 
    0x3e3620d1, 0xbe402d4f, 0xbd3ae3dd, 0xbe08f3a6, 0xbe163a21, 0xbdf48922, 0x3e76f756, 0xbd8f1fdb, 
    0xbddf9b19, 0xbdfe12f8, 0xbe18e1f0, 0x3da2b47a, 0x3cdbae0c, 0x3d7debf3, 0xbe60fd14, 0xbd25e5fa, 
    0x3e0c94c7, 0xbe5091d8, 0xbe497eb1, 0xbe4e4fdd, 0xbda1feb2, 0x3e1e8412, 0xbd15a975, 0xbba110c3, 
    0xbdcf8022, 0xbd235630, 0xbe347b06, 0x3d9a59dd, 0x3e75ac06, 0xbbc994cf, 0x3e803fec, 0xbe4ec7cf, 
    0x3dacc4ae, 0x3df97143, 0xbe96d60b, 0xbda817ed, 0x3e5e93c3, 0x3d9c4b65, 0xbdfc6aa3, 0x3e4a1cbe, 
    0xbe403682, 0xbd478239, 0xbdb7bb80, 0x3d8d9488, 0xbd5da81f, 0x3bd685ef, 0x3e016bba, 0x3d3eeb71, 
    0xbd30b1ed, 0x3d90fdd8, 0xbe26fe00, 0x3de496bb, 0x3e0c0f02, 0xbd31227f, 0xbd7eb569, 0x3dc8875b, 
    0x3e1d7f2d, 0x3d1fefcc, 0x3dae40ab, 0xbd93b445, 0xbd9725e5, 0xbe320498, 0xbdad86dc, 0x3df6c1ea, 
    0xbdc0d753, 0xbcc0eb55, 0x3e0a6e7b, 0xbe9b00c2, 0xbdcd92b8, 0x3e09b8fa, 0xbe386200, 0x3e304e7a, 
    0xbe3574a8, 0x3c4594e8, 0x3b1bc94e, 0xbe4418e5, 0x3bbb276d, 0x3d68450f, 0xbe48b2e2, 0x3e044402, 
    0xbddf6b0d, 0xbdad4e24, 0x3d8403af, 0x3db1dc08, 0xbdffcfea, 0x3e19a0ae, 0x3da5b1fd, 0xbe458ea6, 
    0x3e674c70, 0x3e22a620, 0xbe31f381, 0x3df185c2, 0xbcf088c5, 0xbe428c86, 0xbe31eba9, 0xbd4dbe6e, 
    0x3c907059, 0xbe46a6cc, 0x3e762c7e, 0x3e2b7087, 0x3d1c6ab4, 0xbc2641f8, 0xbdf3c2a5, 0xbd198121, 
    0xbe0c97e1, 0x3e34602c, 0x3e575d10, 0x3e3df6f0, 0x3e5a279a, 0xbe1bdc91, 0x3dee7e85, 0xbe2718e3, 
    0xbe2bddad, 0x3e1d231d, 0x3e27d0b5, 0xbe2296c2, 0xbd90e71d, 0x3e060148, 0xbd6baf8f, 0x3d584ebb, 
    0x3e1810df, 0xbe5d0875, 0x3dba35d1, 0xbe321173, 0xbe271bef, 0x3d59dbfd, 0x3e1e2104, 0xbe45afb1, 
    0xbe05efe6, 0xbd27347d, 0x3dec53e6, 0x3dccea39, 0x3d84241c, 0x3e49cfc7, 0x3e1cc290, 0xbbbb6728, 
    0xbd730782, 0x3d8aae17, 0xbe0c00e4, 0x3dc2de4c, 0x3e5b7145, 0xbd8b02f6, 0xbd38ea59, 0xbe147d97, 
    0xbce496e8, 0xbe50b1bf, 0x3e39ec7a, 0x3e33c552, 0x3d8a1961, 0xbe069110, 0xbe2cba7c, 0xbe0cdcfc, 
    0xbc046444, 0x3d95984a, 0x3dc8934e, 0x3d2227aa, 0xbd8cc099, 0x3e1ea792, 0x3df8650a, 0x3e5afd56, 
    0xbd6c0732, 0x3d83355c, 0x3dcba0e2, 0x3e3898b1, 0x3df10df0, 0x3e0b4bf0, 0xbdf9a4c1, 0x3e4bc16e, 
    0x3d8d211a, 0x3e1d392a, 0xbd27f669, 0x3e466dc0, 0x3e19ee99, 0xbd864ddd, 0xbdb32b93, 0xffff92a6, 
    0x00000004, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0xffff92f2, 0x00000004, 0x00000c00, 0x3e26578d, 0xbe0640e9, 0xbc14c0d9, 
    0x3e5fef3e, 0x3d580fe0, 0x3e147ed0, 0xbb86db45, 0xbdf5ce7c, 0x3cb7c91f, 0xbe25a7bf, 0xbdb71d08, 
    0x3e638eac, 0x3e8c4de9, 0x3dea1c05, 0xbe636edc, 0x3d9231dd, 0xbe544b00, 0x3d8d5b7b, 0xbdb5e621, 
    0xbe29c844, 0xbda68c59, 0xbe2c4dab, 0xbe594b17, 0xbdbbcd58, 0xbd5eb586, 0x3cae3091, 0x3cda8930, 
    0x3e2a1e31, 0xbe060500, 0x3cd2655f, 0xbdd9505b, 0xbe23491b, 0x3ad792a2, 0x3e1f01b6, 0xbceca33e, 
    0x3e3c7d98, 0xbd11c985, 0x3d6dea5e, 0xbcbc40ef, 0x3e855e87, 0x3d4a6dd3, 0x3e205039, 0x3e51f4d0, 
    0xbe1a9b46, 0xbdb911b8, 0xbacfe6de, 0x3df3f42f, 0xbe69d42b, 0xbe1d050d, 0x3d12f220, 0x3e17e82e, 
    0xbe06557b, 0xbe4e46ff, 0xbccf3123, 0x3d4588cf, 0xbd463f31, 0x3d530689, 0xbcdf74ac, 0x3d860b58, 
    0xbe6faa64, 0x3e821cb9, 0x3ce0ee05, 0x3e245f10, 0x3ca475ec, 0x3d8bf6c0, 0xbd9d27ed, 0xbe2e32d3, 
    0x3c875b9c, 0x3e57a6e1, 0xbde5042d, 0x3c0c64e9, 0xbe57903e, 0x3d43a42a, 0xbd8003ae, 0xbdb0af65, 
    0xbd3be4da, 0x3e6c9553, 0xbcfb8689, 0x3db0645d, 0x3dd285b4, 0x3e0f4e5e, 0xbcec11c5, 0x3d53ba65, 
    0x3e5490cc, 0x3d032fba, 0xbe50876b, 0x3dd8edda, 0x3e2b136c, 0xbda36652, 0xbe2f55c1, 0x3d80d46b, 
    0xbe0f8b3e, 0xbd6780c9, 0xbc29e6ab, 0x3e70ca93, 0xbe02be09, 0xbdb73af8, 0xbe64bfbb, 0x3e48be18, 
    0x3b7d3454, 0xbcc8f512, 0xbe35fa4b, 0xbe183073, 0xbdba94cb, 0xbe2b82af, 0xbd7d8c06, 0x3d4bdd73, 
    0x3cf59e37, 0x3cb9630b, 0xbcb1d82f, 0x3e1d9b28, 0x3e7c91c8, 0xbd9003de, 0xbc00d686, 0xbe535ef8, 
    0x3e1368f4, 0x3e8573a1, 0x3e0052cb, 0x3e57f67b, 0xbe76de70, 0x3e57d9f0, 0xbe6107a5, 0x3d97ae7d, 
    0xbe7c9fb6, 0x3e6c8d53, 0xbe35b21b, 0xbd86760f, 0xbe46129a, 0xbe0e980c, 0x3e0afa1e, 0x3deb36ea, 
    0xbd338c5d, 0xbde2dbdc, 0x3e517d81, 0x3da9b8ae, 0x3e2ad113, 0xbdf84a01, 0xbe02c086, 0xbdb5ff26, 
    0xbdbb3a89, 0x3ce28817, 0x3d988d20, 0x3dce583b, 0xbca0ab8f, 0xbd8bb5eb, 0x3db539c2, 0xbda58381, 
    0x3d2ed098, 0xbe6c2b9d, 0xbd7fd89d, 0xbd59a42e, 0xbe0f8a14, 0x3dec17d4, 0x3e3af1c8, 0x3d49dd8f, 
    0x3e598fa1, 0x3e3f3012, 0xbd822f6e, 0x3e2a668e, 0xbe7c37f1, 0x3da7ad6e, 0x3e851fc2, 0xbe588714, 
    0xbe7456aa, 0x3da64b49, 0xbe610d53, 0x3e284776, 0xbbe54af7, 0x3ddb3028, 0xbd1c3ffc, 0x3e6725ea, 
    0x3dc622d6, 0xbc32e36d, 0xbcf177b0, 0x3e3bff15, 0x3e6097c8, 0x3e47a3f4, 0x3e0ae02f, 0xbcde733a, 
    0xbdecf966, 0x3e2d510b, 0xbe6c3742, 0xbe05da46, 0x3cbaf35d, 0xbce47b79, 0xbe683052, 0xbe1448f8, 
    0x3e31caee, 0x3e404717, 0x3c87d882, 0xbe560eb0, 0x3e147756, 0xbdc563ad, 0x3bbdd6ac, 0xbe384553, 
    0xbe534c9b, 0xbe218323, 0x3cfec43c, 0xbe456718, 0xbe006875, 0xbd3b1b83, 0xbb8763f4, 0x3d739fc2, 
    0x3e6843a9, 0x3e7a80a8, 0xbd0621da, 0xbdf47e3d, 0xbdcc69db, 0x3e7e59fc, 0x3d9d0a54, 0x3deba3ee, 
    0xbd49d0ce, 0x3db7cfb9, 0x3d5f9148, 0xbe22b2df, 0xbe1a52bf, 0x3c09f131, 0xbe02b62d, 0x3d8aa157, 
    0xbd289e73, 0xbd06d94b, 0xbe0e6b66, 0x3d730062, 0x3ded07b9, 0x3c9e6701, 0x3e76017b, 0x3de7c7c3, 
    0xbd2c8522, 0xbda2eeb0, 0x3d52fcf1, 0xbcb309ac, 0xbe044f1f, 0x3dd0e429, 0x3e32038d, 0x3de8b080, 
    0xbe40781c, 0x3e310ad6, 0xbdee17d6, 0xbc61b3f5, 0xbd26b98c, 0xbe129ba3, 0x3e2d8583, 0xbc740bea, 
    0x3e2ff1b5, 0x3df70850, 0x3e7f085b, 0xbc3611ff, 0x3e088c7c, 0x3ce4e8c9, 0xbd92ff7f, 0xbe33ac32, 
    0x3e0a94e0, 0x3e53d299, 0x3b9aa41c, 0xbdf6577c, 0xbdf5e6bc, 0xbbb1d775, 0xbe5bcaea, 0x3e7cd82a, 
    0xbe3804e1, 0x3dc1b497, 0x3e0c32e5, 0x3e54120f, 0xbe296eb3, 0x3d9d67fe, 0xbddccd1a, 0xbe839920, 
    0xbe2f40dc, 0x3e2c031f, 0x3db65438, 0xbcb4a6c7, 0x3d5c7a11, 0xbe53129a, 0xbdc79665, 0x3e04f33b, 
    0xbdf97a5e, 0xbe5a7e68, 0x3e51ced2, 0xbd3811d9, 0x3e2f5d30, 0xbdd948d3, 0x3e56dfd3, 0x3d66fb17, 
    0x3e41a131, 0xbe186c0b, 0x3e21a2b7, 0xbd3bfcfa, 0xbde53471, 0xbde6ef22, 0x3d2a1605, 0x3d1dad8a, 
    0x3da331e1, 0xbe35cca1, 0x3cf50558, 0xbe7b8ec7, 0xbe2a96a4, 0x3e5a104b, 0xbe38440d, 0xbe638958, 
    0x3e0cb1fa, 0x3dc3b6af, 0x3dc575c9, 0xbdd97a3f, 0xbe37d2c1, 0xbe8c6a38, 0x3d7f69bd, 0xbe872172, 
    0x3e43963a, 0x39e3fbb7, 0x3ca2d7be, 0xbe733554, 0x3bc862e2, 0x3dc08e08, 0x3db8719f, 0xbe90a84c, 
    0x3d6c57d5, 0xbe1c5847, 0xbe64840b, 0x3e137225, 0xbe997356, 0x3db5861f, 0x3e0d1d8c, 0xbe1d95b9, 
    0x3de71a13, 0x3e6b2f87, 0x3dbe9f5d, 0xbe89d6bd, 0x3d910cee, 0xbda349a0, 0xbcc4a76b, 0xbdc32f41, 
    0xbd9020b5, 0xbc96271d, 0xbd8b7792, 0xbd13355f, 0x3c5bdc0d, 0xbdde359b, 0x3dadd9f2, 0x3df728f9, 
    0xbe060045, 0xbe3d3e06, 0x3de7c302, 0x3da3eb83, 0x3d1cd48a, 0xbce46564, 0x3d976fe1, 0x3d515b68, 
    0xbe26b81a, 0xbe1d8ca4, 0x3e096ccb, 0xbd9a621a, 0xbc655027, 0x3db9fba2, 0x3df82375, 0xbe1215d9, 
    0xbc86913e, 0xbda541f1, 0x3d95e3a1, 0x3e110a8a, 0xbd9333ee, 0xbe607ac3, 0x3e643139, 0x3d783f54, 
    0xbe38ff29, 0xbe08041f, 0xbe1ab386, 0x3c99c4c6, 0xbbad7e55, 0x3e4f3de7, 0x3e0df47d, 0x3c83e827, 
    0xbc2c72ed, 0xbd6f84b9, 0xbe6e22e7, 0xbda7a25c, 0xbd1196c1, 0x3dc3e098, 0x3e1551c0, 0x3e07dad7, 
    0x3d0c9228, 0xbdc2797c, 0x3da69c31, 0xbd9b2cc9, 0x3e6f8436, 0xbe62ed41, 0xbcedfedd, 0xbe140b88, 
    0xbd77b80a, 0xbce33d90, 0xbe2d978b, 0x3dbf4628, 0x3c740239, 0x3d4acb71, 0x3cb8d380, 0x3d5b4998, 
    0xbdf92a8b, 0x3e65bf60, 0xbe18d148, 0x3e606adc, 0xbd6d1954, 0x3c86969b, 0x3e5cb7ee, 0xbe2a8b2f, 
    0x3d3db765, 0xbc955749, 0x3d0168b8, 0xbdbd0b31, 0xbe3d98ab, 0x3dbf8705, 0x3e08db3c, 0xbcb80831, 
    0xbe808edd, 0x3e0b1140, 0x3d58fbed, 0xbdb107ce, 0x3d7f84b9, 0x3da8e482, 0x3cdfbb44, 0x3d42636d, 
    0x3e39f584, 0x3d103de0, 0x3dc493d9, 0x3e2bc49d, 0xbe5db0fd, 0x3e11e4b6, 0x3dddb90b, 0xbdbe859a, 
    0xbd74680a, 0xbd0f22bf, 0xbe35ac09, 0xbe72a981, 0x3e5fd100, 0x3e31fd91, 0x3e073b05, 0x3e5896a2, 
    0x3dce2e65, 0x3e6bb427, 0x3e35121a, 0xbda3c583, 0x3e7707e4, 0xbe36c9f9, 0xbe66bdcb, 0xbe398e4e, 
    0xbdfa89e9, 0x3d86275a, 0x3e406f25, 0xbd8afd7b, 0x3e2c7151, 0x3e0b1e09, 0x3e47e06b, 0x3e1ac6b9, 
    0x3e451cb9, 0xbd7dd86c, 0x3e341b01, 0x3e22f14f, 0x3e803dae, 0xbe720dd4, 0x3db9afba, 0xbe86c4f7, 
    0x3d289d22, 0x3d19e89c, 0x3e6e7a80, 0xbe634c8c, 0x3d6b6132, 0x3ce9b616, 0x3d339552, 0x3b87435e, 
    0xbe1eb066, 0x3d3eb5e8, 0x3b3b8d0c, 0xbbdfd01f, 0xbe0f5b6f, 0x3d1a75e8, 0xbe6fae86, 0xbe143fa2, 
    0xbe469993, 0xbe34d8a9, 0x3e7368b0, 0x3e1cd618, 0x3e203897, 0x3e3d8ef6, 0x3e105c96, 0x3dad9d5c, 
    0x3d6f6bba, 0x3e5f29a2, 0x3e919078, 0x3e57d01c, 0xbd9f0cc9, 0x3deb787f, 0x3e1621f9, 0xbdf0ac8a, 
    0x3db91c69, 0x3e64195e, 0xbe0be3eb, 0x3e169a2b, 0xbde4fc83, 0x3d3ded37, 0xbc68de37, 0x3d908f29, 
    0x3e63f712, 0x3e2bfa15, 0xbe3a0a60, 0x3e3f0a26, 0x3dba8ad1, 0x3e7d0672, 0xbe2b8b7f, 0x3e3dae90, 
    0x3e4970ac, 0x3dc97359, 0xbe1be50d, 0x3e40dcc5, 0x3de74971, 0xbe2a3759, 0xbd44e8f1, 0xbe2ca583, 
    0xbcad786c, 0xbe07dc29, 0xbe1f1bfd, 0xbdbfc986, 0xbd73f4dc, 0x3e6fce2d, 0x3c9f8859, 0xbe5b3537, 
    0x3df3ca38, 0xbddd3545, 0xbe23b25f, 0x3db5526a, 0x3c8d18c9, 0xbde2c689, 0xbe536b41, 0x3dadc568, 
    0x3d2df602, 0xbe3ee147, 0x3e593475, 0xbd00ec2c, 0xbe626918, 0x3e2b9b82, 0xbdad3821, 0xbd80cc30, 
    0x3e1684da, 0xbb2154ed, 0x3da90edb, 0x3cf44475, 0x3e5a3549, 0x3d3df321, 0xbd34ba75, 0x3e4648fe, 
    0x3e60df63, 0x3d09953c, 0xbdd5ae9c, 0xbd716288, 0x3d165830, 0xbd844fff, 0xbd364b0e, 0x3e1f33bc, 
    0xbe2ce11c, 0x3d86cb65, 0x3e178b19, 0xbdde6974, 0x3d2b16ac, 0x3e408dc6, 0xbd83d272, 0x3df2b280, 
    0xbaa693fa, 0xbe0383fc, 0xbe713ccf, 0xbe73ecde, 0xbe36b199, 0xbd79f535, 0x3d4723c5, 0xbe2d026d, 
    0x3e4a9d4a, 0xbdcac82e, 0x3d62b22c, 0xbe341c45, 0x3e293679, 0x3dd8d2cd, 0xbdd1caf5, 0x3dec8c62, 
    0x3e1bd265, 0x3e3da281, 0x3deb5665, 0x3bbd5475, 0x3e6e19fe, 0xbd3c0e09, 0x3e045c3a, 0xbe537b33, 
    0x3e2619cb, 0xbe2f689f, 0x3e39b926, 0xbd4b1c6a, 0x3c8b0b23, 0xbde85f1a, 0x3e277d0d, 0x3e65af8b, 
    0xbca0ca80, 0xbe536626, 0x3dcbc698, 0x3d1c6ba1, 0xbdb70b37, 0xbe0f77a7, 0x3c82c24d, 0x3dadde28, 
    0xbe00ae9b, 0xbe60c249, 0xbcaaa079, 0x3be8769f, 0x3d9eb8a5, 0xbe8374d2, 0x3e6cc987, 0xbe0ceca7, 
    0xbe63f560, 0xbdf1ebb8, 0x3db6585e, 0xbd8c2d41, 0x3e3deeee, 0x3e894c09, 0xbe5dabae, 0x3d9a460f, 
    0xbe63a4c7, 0x3e249e3e, 0xbe264e07, 0xbd8ff6bc, 0xbe46742b, 0x3e445509, 0xbdaed374, 0xbdf17c7e, 
    0x3d01b915, 0xbe1d0bdf, 0x3cc7cf46, 0x3db525ec, 0xbdc2749a, 0x3e1d75f7, 0xbe1a8951, 0x3dbcf956, 
    0xbdfbec68, 0x3e8233a7, 0x3e5c5eef, 0xbdfb255b, 0xba473e2e, 0xbd9a8f44, 0xbdad5445, 0x3da6a4c2, 
    0x3e7a2af3, 0xbd441058, 0x3e2fac38, 0x3e4e865a, 0xbdc46d25, 0xbd9418b9, 0xbc50365b, 0xbe75dcde, 
    0x3e830bf1, 0xbe108b28, 0x3c0dc6d9, 0x3e7b0c07, 0x3e17974e, 0x3e7b33c9, 0xbe180dab, 0xbe6b7cc9, 
    0xbd546e6d, 0xbd9ece86, 0x3d9d3748, 0x3da020f8, 0xbe095928, 0xbe472a11, 0xbe0285c4, 0xbe507c89, 
    0xbe525cfc, 0xbd7be4eb, 0xbc56c6d3, 0xbbfc9164, 0x3e1d22e4, 0x3dc1bd9b, 0xbd9badc6, 0xbe29ba38, 
    0xbd5aba41, 0x3e710286, 0x3ccb9079, 0x3d27f25b, 0xbd3e6cb4, 0x3e4dc0f2, 0xbd2318f5, 0xbc9d131e, 
    0x3daa4fa0, 0x3e042a8f, 0x3e20a40d, 0xbde76675, 0x3c32222f, 0xbdba606d, 0xbb53a2e5, 0x3d480403, 
    0x3da30123, 0x3ce1c8bd, 0xbd9fd715, 0x3e26eb66, 0x3dd06929, 0x3e1b2a55, 0x3d6919d7, 0x3e25ff46, 
    0x3cc0bf2e, 0xbe220b24, 0x3e642508, 0xbe17fc50, 0xbe04aaee, 0xbd3933bc, 0x3bd86782, 0x3d7e264e, 
    0xbd123211, 0xbe6de4f3, 0xbe2879fe, 0xbda367a2, 0x3da84e20, 0xbe4c02dc, 0x3d26bd1a, 0x3d0e87a9, 
    0xbe3bf0bc, 0x3e2ea978, 0xbd4a423b, 0xbc772d9d, 0xbe4f15d5, 0x3db4e0f9, 0xbe53faf8, 0x3e98b656, 
    0x3e1552bc, 0xbcb4d0c7, 0xbe3d680f, 0x3e5148cb, 0x3d5427b2, 0x3d5a8ffb, 0xbe5387ea, 0xbe41a188, 
    0xbdc90413, 0x3d6d6625, 0xbe51c4ec, 0x3e27ef55, 0x3df3cfa7, 0xbd6608d2, 0xbcd51c30, 0xbd8d1b48, 
    0x3e2b0d07, 0x3e09189d, 0x3cadc2d7, 0x3e3b2ae6, 0x3e56dccc, 0xbe7a269e, 0x3e860150, 0xbca61a4e, 
    0x3d8b8aa9, 0x3d3a736e, 0x3dbf0682, 0xbd9b6327, 0xbdec0d00, 0x3de8d28a, 0xbd1c8619, 0x3e4d15c7, 
    0x3cf6f39c, 0x3d2536b1, 0xbe579820, 0xbe4f675c, 0x3de225ef, 0xbd86fdb8, 0x3e1cb0c9, 0x3e70eccd, 
    0x3e02a847, 0xbc4fe1aa, 0xbc357262, 0x3e3f87f4, 0xbbd1a5de, 0xffff9efe, 0x00000004, 0x00000080, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0xffff9f8a, 0x00000004, 0x00001800, 0xbe166bf9, 0x3dbef032, 0xbbfb6e5f, 0x3e1c0d8a, 0x3d51298b, 
    0xbd9cba22, 0x3db49342, 0xbc88024f, 0xbe2ffb63, 0xbcfdfb14, 0x3e57c616, 0x3df6ff46, 0xbddf9031, 
    0xbcc70159, 0x3e17e54f, 0xbdf2157b, 0xbdd82bd6, 0xbe445572, 0x3dca4a06, 0xbd5cf8e2, 0xbd72e6e6, 
    0xbd88f2a3, 0x3dea6f80, 0xbdfbe911, 0xbaf51b92, 0xbe2e7293, 0x3e22a968, 0x3e1ce1ae, 0xbcea7792, 
    0xbd1fc3b3, 0x3dfe91ee, 0x3db39538, 0xbc9e5d8c, 0xbbb70c3e, 0xbe1436fc, 0x3e34e249, 0xbe3ce3ed, 
    0x3d959668, 0xbcc970e3, 0x3d97742a, 0x3dbfa12e, 0xbcd8fc32, 0xbd022820, 0xbd63add1, 0xbd041e30, 
    0xbab8cdd4, 0x3db29678, 0xbe0412c7, 0xbe1d0afa, 0x3e04c716, 0xbe4720bb, 0xbd163c87, 0xbe1dc6b2, 
    0x3da4bf3b, 0x3dc3f0d8, 0x3d8142d5, 0x3e3068e8, 0xbe519c05, 0x3e351bd8, 0xbd5f4918, 0x3d068bd4, 
    0xbcc5ac78, 0xbca2fdf5, 0xbc43ecfc, 0x3dca04e2, 0x3e270e9c, 0x3e233630, 0x3e575861, 0xbe34cc16, 
    0xbd0ede14, 0xbe02b8a5, 0xbd516651, 0xbc970cc4, 0x3d9abfba, 0x3cc87801, 0x3e185833, 0x3d8d1543, 
    0x3e64b624, 0x3d72ab2d, 0xbde9adc0, 0x3d8b6715, 0x3e240c11, 0x3d604c50, 0x3da175c4, 0x3d89fa61, 
    0xbd0746e2, 0xbe36dbef, 0x3e4ec7f4, 0x3e0ac8dd, 0xbe234eff, 0xbdc87c17, 0xbe2eed24, 0x3db32793, 
    0x3df42861, 0x3e11cef3, 0x3e4d822c, 0xbd7259e0, 0xbd9d8801, 0xbd4a9b44, 0xbdf66b62, 0x3d471c90, 
    0x3d9e61a9, 0xbe432eb3, 0x3d94f767, 0xbe0d4495, 0x3c155af1, 0x3d819eba, 0x3dbbba0b, 0xbbc02b80, 
    0x3d01e11e, 0xbdcfde31, 0xbdfa5982, 0x3de85898, 0xbe0b6229, 0xbdc3939d, 0x3e14b835, 0xbe4a2d75, 
    0x3e161cd9, 0xbe4c6529, 0x3d9855f0, 0xbe24b405, 0xbe3761a7, 0xbc4e994d, 0xbda1c0d7, 0xbe53be2e, 
    0x3e1c68b5, 0x3c89614f, 0xbe52ecc1, 0xbad2c233, 0xbe8c5c01, 0x3c16d175, 0xbe1baac0, 0xb6f608fc, 
    0x3dce988c, 0x3dac2efe, 0xbde49677, 0x3e4a2bda, 0xbcfd5bda, 0xbc8644f4, 0x3dac3858, 0x3d5e1aeb, 
    0x3cd2f10d, 0x3e139bf7, 0xbd6392e1, 0x3e0267af, 0xbd740700, 0xbe1d235b, 0x3df67243, 0x3dc599a5, 
    0x3e037190, 0xbd94cdff, 0xbd75e95a, 0xbe26338c, 0x3a21fbc9, 0x3df66c41, 0x3cb472e7, 0x3de4860c, 
    0xbca7b29e, 0xbd8da3bd, 0xbdcf3c18, 0x3d4ddb25, 0x3ddaa2c0, 0x3d80dce1, 0x3d7241e5, 0xbe075d33, 
    0xbdbd8857, 0xbdb1c2c6, 0x3df4ec4d, 0xbdaca28d, 0xbcaca6ca, 0xbc7905a1, 0x3b70dde0, 0x3dc4a5a3, 
    0xbde5a3bf, 0x3d9b8a97, 0x3e3ab733, 0x3e559f3e, 0xbe30e5ed, 0x3de4f5c5, 0x3e6c5c09, 0xbdbc240c, 
    0x3e29cc82, 0xbd97dcc1, 0xbcab7495, 0xbc284e68, 0x3e3f8faf, 0x3d973a29, 0x3e39053e, 0x3e0fb967, 
    0x3dca073e, 0xbd5d7823, 0xbd6770ef, 0x3d477439, 0xbdcae7d7, 0x3d9a3108, 0x3cc5c191, 0x3d5fc9a4, 
    0xbe4b9964, 0x3d811825, 0x3d873f6c, 0x3dc5eed7, 0xbdcfc25f, 0xbe0e3ff7, 0x3e301c3a, 0x3d64ab39, 
    0x3e3eed56, 0xbce5ea81, 0x3dff7430, 0x3e03bad9, 0x3e1c30ff, 0x3e0dd9b8, 0x3e3cd88e, 0x3c6d22e7, 
    0x3ce9be6d, 0xbe2e6fd0, 0xbde1cce6, 0xbd758e0a, 0xbe1567ac, 0x3e0b82be, 0xbe135b53, 0x3e3fbae8, 
    0x3e2efc39, 0xbd9f6541, 0x3d4cd00a, 0xbe0157f7, 0xbc910c39, 0xbe2b7f58, 0x3c21d5c1, 0x3abd8894, 
    0x3d360b6d, 0xbe48d808, 0x3e116136, 0x3e1874c2, 0xbd3b0859, 0xbbb6b30c, 0x3e2c714d, 0x3dfbb009, 
    0x3db81f04, 0x3dafaa24, 0x3e57bf5d, 0x3e2ba4e1, 0xbc53db28, 0x3e40d5b7, 0x3dfa0a66, 0x3e220300, 
    0x3cdabdf5, 0xbd275199, 0xbd8d7b62, 0x3d09977f, 0x3ccd6fe3, 0xbce3c3c8, 0x3e36bf6d, 0x3cc42147, 
    0xbbc5368c, 0xbe1a68a6, 0xbe32c42a, 0x3c89d041, 0xbe208c62, 0x3e23e127, 0x3d8734c7, 0x3e006f25, 
    0xbdcdf42e, 0xbe64d814, 0xbc29c35b, 0x3e268cb6, 0xbd7eb08c, 0xbe15abf7, 0x3df13fda, 0x3dfdb92b, 
    0x3d9b5420, 0xbe6b9234, 0xbe28dfce, 0xbe03c984, 0x3d113ba8, 0x3e412223, 0xbd79c8ca, 0xbdeb0432, 
    0x3e69a5ad, 0xbd90f558, 0x3d25aacc, 0x3d58ea98, 0xbc9d6bba, 0xbdc0077f, 0x3de182bc, 0x3dec218c, 
    0xbd7fe74b, 0xbc00863b, 0xbdea4bfb, 0xbe3620bf, 0xbe4bea92, 0x3e227775, 0x3e1b76f3, 0x3e2809ba, 
    0x3e16972c, 0xbc8c73e7, 0x3e3de859, 0xbd4f1df0, 0x3dcbe496, 0x3e4fdb29, 0x3dc075a9, 0x3cfb3a3d, 
    0xbd63f5e7, 0x3e1ae4a9, 0xbcfd1ec9, 0xbe5d2201, 0xbdc0dce3, 0x3d5d94ab, 0xbdcfef1c, 0xbdda8e3c, 
    0xbe1869dd, 0x3daa05ab, 0x3df2c9f5, 0x3e2c69e0, 0xbc227597, 0xbd75751d, 0x3e321c1d, 0x3e2dbaf4, 
    0x3dd57b07, 0x3c9b8bc1, 0x3e00872b, 0x3dfce331, 0x3e2fb22e, 0x3dc405df, 0x3e084565, 0xbdfaf877, 
    0xbdcc3530, 0xbd2c3ff2, 0x3dccb462, 0xbd8382ad, 0x3e3564e3, 0xbd6af30d, 0xbd677e39, 0xbd168bb3, 
    0xbdda4b5b, 0xbd0da254, 0x3e51a732, 0xbe782927, 0xbd4e2ece, 0xbcf6746f, 0x3e30c937, 0x3e4f7d8b, 
    0x3dd940d3, 0x3d7062a1, 0xbd82be01, 0xbe56766a, 0xbc578e7c, 0x3e383745, 0xbd194531, 0x3d9679d1, 
    0xbda2f78a, 0x3d3626db, 0xbd8fe1f4, 0x3b436df9, 0x3e13d389, 0xbe090aef, 0xbc83c6b5, 0x3df71ad1, 
    0xbe4beecc, 0x3e1df3db, 0xbe17d97c, 0xbe76f7cd, 0xbe33997a, 0xbe1d4492, 0x3d801d87, 0x3e0f5618, 
    0xbd93b3aa, 0x3d86d482, 0xbcb8f5e5, 0x3bf71849, 0x3e2985be, 0x3e1bb2b4, 0xbe05422f, 0x3df21505, 
    0xbe1293ca, 0x3dda5572, 0xbe2ce0c7, 0xbe7843c6, 0xbdc481b0, 0xbd808411, 0xbdb7bd2a, 0xbd6944f7, 
    0xbd0e26d4, 0xbdf22279, 0xbea4b366, 0xbe02155b, 0x3dcac776, 0x3dd72d93, 0x3e52ecbe, 0x3d06c71c, 
    0xbdf05cf3, 0x3e3ca6a2, 0x3ddbbdc9, 0xbd9f7811, 0xbd3c0324, 0xbdcf99c4, 0xbd817a79, 0x3d967a8c, 
    0x3d3c6642, 0xbd20ff81, 0xbd1d2b84, 0xbd9e89df, 0x3dadea44, 0xbdf7c49e, 0xbcc0324a, 0x3d0b88ff, 
    0xbddc41a7, 0x3d3fd8b1, 0xbdf408f0, 0xbccee09c, 0x3db21c5f, 0xbe4fc16f, 0xbe06dbab, 0x3dd7ef94, 
    0x3dc95f0d, 0xbd5cbb0b, 0xbe387de1, 0x3deeab81, 0xbbd92d20, 0xbdc6a21e, 0x3df08186, 0xbd02d35b, 
    0x3d3c8a87, 0xbe2c6010, 0xbd5b1a2e, 0xbd1deded, 0x3de72e8d, 0x3d8e81d8, 0x3d36c17d, 0x3d9917ec, 
    0x3e4e1399, 0xbdab3ee8, 0x3cac5887, 0xbd364ba6, 0xbdd2cddd, 0xbe1b8296, 0x3d9d2861, 0xbcdeeae7, 
    0xbdf27970, 0xbcfc620b, 0x3e58b3b1, 0xbe4bcc1b, 0xbda39d00, 0xbd95c739, 0xbe3ac0eb, 0x3e187685, 
    0xbddaf1e7, 0xbccd4529, 0x3dce48ee, 0xbda60003, 0xbd9d927b, 0x3cb92783, 0xbd32d1bb, 0xbca342db, 
    0xbe424df0, 0x3e01c666, 0x3d621632, 0xbe365514, 0xbe0324da, 0x3e334947, 0xbe2aa8f9, 0xbd81e7dd, 
    0x3e1a01fa, 0x3c924c1b, 0xbe638e8c, 0x3cbd3a78, 0x3d388d14, 0x3de07669, 0x3e0af972, 0xbe48a910, 
    0xbd46efef, 0x3b85227d, 0x3e36febf, 0xbd94a33d, 0x3e0df42c, 0x3d75f6a6, 0x3dd3e874, 0x3e2454ee, 
    0xb9542864, 0xbdbb2786, 0xbda630e9, 0xbe190494, 0x3c4ae77d, 0x3e1a3831, 0xbe27383e, 0x3d80ce1d, 
    0x3c8bcd11, 0xbe54844d, 0xbe42a0e3, 0x3da9d690, 0x3e2467cd, 0x3cf42723, 0xbe66b1cd, 0x3e1e653a, 
    0x3dd1c38d, 0xbe0de0ff, 0x3dd82a98, 0xbd26169c, 0xbbb4422d, 0x3e01da5b, 0xbe27f63f, 0xbe55ca69, 
    0x3dab8594, 0x3d9fd8e2, 0x3be417fa, 0x3dd1ffe0, 0xbd8df0d1, 0x3d7652cd, 0xbe59f878, 0xbdd2187c, 
    0x3b57dacf, 0xbe156321, 0xbddd3c64, 0xbe08e1b5, 0x3e3cc2b6, 0xbba3394a, 0xbd55cd6c, 0x3c510f05, 
    0xbd52f78d, 0xbe0605fb, 0xbcdeaa0e, 0xbd6fbbdd, 0xbe175d3c, 0xb9dcd566, 0xbe7a71a9, 0x3e468c27, 
    0x3e4193bc, 0xbc83a56e, 0x3e0e007f, 0xbd5e6af7, 0xbaccb8f4, 0xbdae7e57, 0xbe1ed819, 0xbd9b8bdc, 
    0xbbec66dd, 0xbb437545, 0xbdff1e5b, 0xbd5aa003, 0x3cbc24ec, 0xbe54b0e4, 0x3e0e1f7e, 0x3dc68ff2, 
    0xbe2b69ec, 0xbddd905c, 0x3d5f4642, 0x3c44dc26, 0xbcd5c566, 0x3df6a26f, 0xbdb1139b, 0x3dc26241, 
    0x3e0f8fa9, 0xbdf4fb15, 0xbe0d6f3f, 0xbdee6765, 0xbe2a94b5, 0x3d33e368, 0x3da4943b, 0x3dda5a1e, 
    0xbe6fe493, 0x3d822260, 0x3e3184de, 0xbdf32bc6, 0xbd8630ca, 0xbd84db62, 0xbe36f3c4, 0x3dfc3457, 
    0x3d191b22, 0xbd8e27b9, 0xbe01f653, 0x3c3d2265, 0x3a226a28, 0xbe8d3b94, 0x3cf329b5, 0x3dcf3b78, 
    0xbe42b510, 0xbc7e66c0, 0x3deab50f, 0x3dc0f141, 0xbe398bca, 0xbe766e44, 0xbcb12325, 0xbd11ad97, 
    0xbe141dca, 0xbdf3ac2d, 0x3af2fef0, 0xbe362961, 0xbe140686, 0xbe81981e, 0xbe5da862, 0xbe340ebc, 
    0xbe26d4e6, 0x3e46b4bd, 0xbd9ec13f, 0xbde9b9e1, 0xbd680a61, 0x3e5bb09b, 0x3dd28b95, 0xbd118ccc, 
    0xbcf6e031, 0xbdda1155, 0x3dc9b26e, 0x3dea297b, 0x3d2e2a08, 0x3e50ffd0, 0x3ce4b434, 0x3cc9850d, 
    0xbe3f5f3c, 0x3cde6038, 0xbe421316, 0xbd51d363, 0x3da10648, 0x3df78269, 0xbdbc0487, 0xbd99d244, 
    0xbe26da02, 0x3e3ad6fc, 0x3e3a5608, 0xbe2eb828, 0xbd8c5af0, 0x3cc37ac4, 0x3d7362e5, 0xbe0b06c4, 
    0xbdf40241, 0x3dcd7d08, 0x3da71ed8, 0x3e53a34a, 0x3e178824, 0xbe39b45a, 0x3e433147, 0x3caebde1, 
    0xbc30fdb0, 0xbe3b996e, 0xbe2d9178, 0xbd3d8c0a, 0xbdd8bac4, 0x3dede670, 0x3de304bb, 0x3e1335ec, 
    0xbe14f603, 0x3dfbfa62, 0x3e41f2e4, 0x3da23247, 0x3d562072, 0xbe238b73, 0x3e3be893, 0x3e445834, 
    0xbde3e3d2, 0xbe215661, 0x3e126ac7, 0x3e1624be, 0x3dbbec27, 0x3d065609, 0xbd0b0b50, 0x3cfc3d75, 
    0x3bd366e0, 0xbe412fde, 0x3e4bd36e, 0xbd4c11c2, 0xbdf56dc4, 0xbe004118, 0xbe0c6d35, 0xbd3aa90f, 
    0x3dfe62b0, 0xbdeaa958, 0xbe1c2a03, 0x3dc7bbea, 0xbdc2c24c, 0xbdb002c5, 0x3d88cf1a, 0x3b19f571, 
    0xbdf20edf, 0x3c8b4f95, 0xbdd8843e, 0xbda6f8a6, 0xbc1490b4, 0xbda1b38b, 0xbe6587a2, 0x3cb61bae, 
    0xbdfd2e20, 0xbde4ce31, 0xba5e7452, 0x3dd8467f, 0xbe64c640, 0x3e35df2c, 0x3daeebae, 0xbd716f72, 
    0xbe154efe, 0xbdd241f5, 0xbaeea728, 0x3d8f7700, 0x3c05c757, 0x3df1f955, 0xbd9cab97, 0x3db680d5, 
    0xbe106b06, 0x3e0f7292, 0xbe6005b6, 0xbdfec1dc, 0xbde4cfea, 0xbd39cd09, 0xbe57c117, 0xbda0e96f, 
    0xbe2bd0df, 0xbd296965, 0xbdb64604, 0x3e2edbe2, 0xbda478a5, 0xbcb242e1, 0x3dc941db, 0xbe27c20b, 
    0x3c4bc6eb, 0x3dfd8803, 0x3d7c4961, 0xbdd33fdd, 0xbc6f568f, 0xbe54b783, 0xbdeda737, 0x3d1339f8, 
    0x3dfd2e71, 0x3de339db, 0x3e1ecdcd, 0xbd4c90f5, 0x3dd8e980, 0xbbcdcc4a, 0x3dc9a847, 0xbda3409c, 
    0xbdc0dc03, 0xbe1e030c, 0x3e03e654, 0xbdd58ba0, 0x3d490ddf, 0xbd2c6345, 0x3c9f5498, 0xbdbd9c57, 
    0x3d5f8711, 0x3bb8df93, 0xbd11611f, 0xbe12470f, 0x3deefec7, 0x3ca37bbe, 0xbe2ead75, 0xbce2b84b, 
    0xbdc5cf43, 0x3db121cb, 0xbd0628cc, 0xbdbe2e62, 0xbdb9995e, 0x3db0a78f, 0x3e4f3681, 0xbc2f9c94, 
    0x3e077c17, 0xbdb23725, 0x3c680dd1, 0xbe39be88, 0xbe20b8fd, 0x3db3b50a, 0x3e08d40b, 0xbd975555, 
    0xbd2811b9, 0xbdfeb9c1, 0x3d10f5e3, 0xbd96f36f, 0x3e38b928, 0x3d259fc5, 0x3e297d92, 0x3dff29b1, 
    0xbdce62ef, 0xbd8bff55, 0xbc25b8af, 0x3df2fcdc, 0xbe56558f, 0x3e5d0d3f, 0xbda558f4, 0xbdacf980, 
    0xbe1dca3d, 0x3e317d36, 0x3e2b7a29, 0x3dcd78be, 0x3d3abb47, 0x3cc62886, 0x3c47c67b, 0x3dd895c0, 
    0x3c921ff4, 0xbe6ed97b, 0xbd04a9be, 0x3de6b880, 0x3d9126f6, 0xbd6dd98c, 0xbd88e70e, 0x3cab6461, 
    0xbdf9e9cd, 0xbda2ef69, 0x3dcad940, 0x3da3593d, 0xbe219904, 0xbcbffba3, 0xbd79ea0d, 0xbdf7f3a5, 
    0xbde65680, 0xbe1388c6, 0x3d485477, 0xbd2db422, 0xbe53e4fd, 0xbe11a141, 0x3b91469d, 0xbe4b7215, 
    0xbc55f831, 0xbe129825, 0x3e547d28, 0x3e201e12, 0x3da52f2f, 0xbad2a8d8, 0xbe08e03b, 0xbe6c7845, 
    0xbe351ff1, 0xbe71db92, 0x3e28218a, 0xbda7e2a1, 0xbd11bbbb, 0xbdd4169a, 0x3e085a2f, 0xbe598639, 
    0xbcc1c0f7, 0x3e21ecf3, 0x3df955a8, 0xbcfe1cc2, 0xbd996165, 0x3d2901f3, 0xbe20e20b, 0xbe43b07f, 
    0xbd906cbd, 0xbd25a2fc, 0x3e235a5f, 0xbe01a9bc, 0xbdd51438, 0x3cf8e795, 0xbe171f3c, 0xbd916da6, 
    0xbe49a513, 0xbe0a4ac3, 0xbdfe0a1a, 0x3d2a14d2, 0xbe1b6b0b, 0x3d905183, 0x3dc0a3e3, 0xbe1be0d5, 
    0xbe11e910, 0x3e011b11, 0x3d9a6ef4, 0xbe1065a0, 0xbe5d6dc5, 0xbe215401, 0xbe215950, 0xbe3810af, 
    0xbe1a8a5a, 0x3e30108d, 0xbd82440e, 0x3e75df14, 0xbdf34d8d, 0xbdccc56c, 0x3dcdf755, 0x3d70a729, 
    0x3e52be77, 0x3e409086, 0xbe0764c8, 0xbe006aed, 0xbd51d7ca, 0x3d3bb81b, 0xbe42e20c, 0xbd0ad00a, 
    0x3e7376ec, 0x3da8c334, 0xbe17ecbe, 0x3e393c30, 0xbe22a1f4, 0x3dde7c35, 0x3e440b0d, 0xbc75cf73, 
    0xbdadc92b, 0x3e0398b7, 0xbe2070bd, 0x3dd50a4d, 0x3e1b71a3, 0x3e0c1a5d, 0x3d2770f4, 0x3e17ac43, 
    0x3e352676, 0xbe3910af, 0x3e1aa3ef, 0xbe400e37, 0xbe4b85db, 0x3da4ba89, 0xbd032af9, 0x3dc1e0d1, 
    0x3da2398c, 0xbe045b95, 0xbcb958a7, 0xbdb514f0, 0x3d62c840, 0xbd42dd12, 0xbdc6dc8b, 0xbd999a4d, 
    0x3e353cd9, 0xbe2f32f9, 0x3e1621fa, 0xbdc6bbc8, 0xbb95a44a, 0xbd9613a7, 0xbdef22d7, 0xbe2e155e, 
    0x3e4a5c96, 0x3e0b836b, 0xbe405f2c, 0xbd50d3ef, 0xbd0378c7, 0x3dbdf21c, 0xbaa80199, 0xbdf08047, 
    0x3dac4f89, 0xbe4681dd, 0x3d7cfb67, 0xbddabc7c, 0x3d8a7dfa, 0xbe181df2, 0x3d47f6c0, 0xbdc18fe5, 
    0xbd199381, 0x3d9f14fb, 0x3d2c6976, 0x3e1d950c, 0x3d5296ea, 0x3da29271, 0xbe1290b5, 0xbdceca43, 
    0xbd9b3579, 0xbd33a7fa, 0x3e00ec1b, 0x3c2a46a4, 0xbd444ebe, 0x3e25c8e4, 0xbddc7951, 0xbdf87d89, 
    0xbe363eff, 0xbe421031, 0x3d9e3c6f, 0xbdafa114, 0xbe06f266, 0x3dff7cc8, 0xbaff0c29, 0x3dbfa9f7, 
    0xbcf48737, 0x3e45afed, 0x3e195954, 0xbc78f884, 0x3dc9cd8e, 0x3cf38c15, 0xbcd02659, 0x3dc4a30c, 
    0x3dd7c90b, 0x3e0e1044, 0xbdf25eef, 0xbcf20562, 0x3dd563e8, 0xbdc6f13a, 0xbd29918a, 0x3e80d67f, 
    0xbdd71d1e, 0xbe09f9d7, 0xbe427280, 0x3e206f08, 0xbd884aa3, 0xbdaa217b, 0x3d32a601, 0xbd1ea8c0, 
    0x3de73d76, 0x3e2bf79f, 0xbd761ea1, 0xbe4fb0b4, 0xba6273f9, 0x3e23dab2, 0x3e06e94c, 0xbc7be1a8, 
    0xbd0cdaba, 0x3dcf7f70, 0x3cabc5ec, 0xbe1e72ab, 0x3e64da1d, 0x3d79e41f, 0xbd8533cc, 0xbe0ac211, 
    0x3e332355, 0x3e1727cc, 0xbe4e29ba, 0x3d1d5285, 0x3d959aa2, 0xbc73c90f, 0xbe338826, 0xbe0de894, 
    0xbe20c11c, 0x3d1b5bd9, 0xbd00a8d5, 0xbdc59b89, 0xbe20e62b, 0xbc21af2e, 0xbe2f4cf2, 0x3e04c9e8, 
    0xbe122a5b, 0xbe141f24, 0x3df9e60b, 0x3d9846b9, 0xbe087a55, 0xbe166450, 0x3d2a72ac, 0xbddd1e73, 
    0x3e57285d, 0x3d839619, 0xbcb8385a, 0xbdbea6d5, 0x3da1c182, 0x3e4afa23, 0x3e183e56, 0x3d4567bd, 
    0xbceff7b6, 0xbe2f6a19, 0x3e02926c, 0xbd692894, 0xbe023ed4, 0xbdd1c42a, 0x3e607171, 0x3e0d5a85, 
    0x3dbddb41, 0x3e0a7586, 0xbe4b2536, 0x3e18a58b, 0x3e22813f, 0x3d813d4b, 0xbe17b79d, 0x3d429a29, 
    0x3d94e7b9, 0x3d55b2e6, 0x3e18effd, 0x3c201ea3, 0x3dc5f2e7, 0x3c7a7366, 0x3dc5cd42, 0xbccf9e7b, 
    0x3ddc10a8, 0x3dd4680e, 0x3d8f2f64, 0x3e1fb6f0, 0xbe144b1b, 0x3d1d9263, 0xbda4efa8, 0x3e34da2a, 
    0x3e25ba6b, 0x3bf8ff8a, 0x3b6bef3e, 0x3e655946, 0xbe364894, 0xbe6a36e4, 0x3cfc7dfd, 0x3e6c8238, 
    0x3e1cbdcc, 0x3d0be2fe, 0x3dcdf87f, 0xbd1873d9, 0x3e152a2d, 0xbe16cb77, 0x3e4e9946, 0xbe36297f, 
    0x3d1ab73a, 0xbe0040ec, 0xbe252df5, 0xbc875dc3, 0x3cd03aaa, 0xbdaa5415, 0x3e2ea8cd, 0xbe116573, 
    0x3e050f0b, 0x3e14ddd6, 0xbdcabaf2, 0xbddd1743, 0xbdef9fd8, 0xbda1c670, 0x3e64f21a, 0x3e18180f, 
    0x3de0ce2e, 0xbdab18c7, 0xbe276e60, 0xbe12253e, 0xbe22c63e, 0x3e174bb6, 0xbd49603b, 0x3d81b4fa, 
    0xbc91e3a8, 0x3e05556e, 0x3cc658ea, 0xbe382775, 0x3e27287d, 0x3d7f2a68, 0xbdd3bde9, 0xbd9f0644, 
    0xbdff5505, 0x3d8d1862, 0x3c569e0d, 0x3e6b55b8, 0xbde94bad, 0xbd4df34b, 0xbda66021, 0x3da3aed0, 
    0xbd151901, 0xbd88749e, 0x3d8e626a, 0xbce51741, 0xbe37ee11, 0xbd949938, 0xbd17e9b2, 0xbe6c8e75, 
    0xbd27bab5, 0x3e442f14, 0xbdc8515c, 0xbd067862, 0x3c58a3f8, 0x3da97daf, 0x3d46b2c9, 0x3dd89856, 
    0xbe33ea5d, 0x3da6aa0e, 0xbe1521b9, 0x3e49c6f0, 0xbe4fcceb, 0x3df0fd05, 0xbdb2a862, 0xbd859961, 
    0x3dffc6d3, 0x3e12391b, 0x3d7f60ed, 0x3d98af24, 0x3e1152bb, 0x3dae5dc1, 0xbe00a7aa, 0xbdb57a6f, 
    0xbd6fd7d8, 0xbe4f95b0, 0x3e0cd770, 0xbe10da31, 0x3ddced25, 0xbe12f1ae, 0x3e3e5cac, 0x3e1063d3, 
    0x3d6496be, 0x3d1a5999, 0xbc5d6df3, 0xbdc8e296, 0x3c869487, 0x3d9df5c9, 0xbafc2724, 0xbc3f1fa1, 
    0xbd315107, 0xbd04b2a3, 0x3e1c9945, 0x3d5b62a5, 0x3ba71cc5, 0xbe5e705b, 0x3de2d7b6, 0xbe371036, 
    0xbdce71f9, 0x3e135f22, 0xbd9b47f0, 0x3da46e69, 0x3e3d031e, 0x3d94978b, 0xbda63052, 0xbe166daa, 
    0x3b8942af, 0xbd9b28f6, 0x3cf4e860, 0x3e306cd8, 0xbc25aa91, 0xbc3b4251, 0x3da4c988, 0xbd4dabba, 
    0x3ca2112b, 0xbe38ec96, 0xbd992919, 0xbdecc37f, 0x3cb47f89, 0xbe131de8, 0x3d17e4c4, 0xbe022122, 
    0xbdcb68a3, 0x3e0996d7, 0xbd8d873d, 0x3d6bd555, 0x3d24537e, 0x3e33db46, 0x3e05b5be, 0xbe063c80, 
    0xbdfe75f6, 0xbe2641de, 0xbe140b54, 0x3d87243f, 0x3cb539a2, 0x3e59dea3, 0x3ccb1dbb, 0xbda358fc, 
    0xbd85a905, 0xbdfb1f83, 0xbd2dd874, 0xbdbd29ee, 0x3ccdb123, 0xbc500e88, 0x3e5cf791, 0x3d6c4e2b, 
    0x3cb41247, 0xbc8e5767, 0xbce19393, 0xbdebb761, 0x3da45d07, 0x3d54039c, 0x3b845dc7, 0xbd962892, 
    0x3d15ccde, 0x3c3625c2, 0xbbb5026d, 0x3e1b0fff, 0xbe21b31a, 0xbdae35b8, 0xbdbafc10, 0xbdea2992, 
    0x3e23afd4, 0x3d6314a8, 0xbe4056c4, 0x3e74b219, 0x3e6ce1aa, 0xbccd8bec, 0xbe32f006, 0xbd93fbbc, 
    0x3dec6c07, 0xbe5ff2bd, 0x3da6451c, 0x3e37ddb7, 0xbcc3db50, 0xbe0bbc34, 0xbdd7d4f3, 0xbe107f42, 
    0x3dd3029a, 0xbda6a7d3, 0xbd955910, 0xbbefb798, 0xbe249801, 0xbe4e9edc, 0xbe236299, 0x3e5cf193, 
    0x3d1b0ae9, 0x3daa3301, 0xbdcc353f, 0xbe3e4149, 0x3d4dad14, 0x3e0d9fbd, 0x3d7817dc, 0x3da2ddc5, 
    0x3d9cf651, 0xbc47f00d, 0x3e109149, 0x3e7a5440, 0xbe258c00, 0xbd8cb857, 0x3dd14798, 0xbdb790a3, 
    0x3e7cad75, 0x3e496fcf, 0xbdd657cf, 0xbc38c490, 0xbde8c2ea, 0xbe046cea, 0xbd360cbc, 0x3dcd390e, 
    0x3de6e586, 0x3de69701, 0x3df8ef97, 0xbe1df2a4, 0x3d9ed143, 0xbd98298c, 0xbe157f66, 0x3e24dcb0, 
    0xbd61a783, 0x3d966a57, 0x3d4e43f9, 0x3d1e7e30, 0xbd8fec86, 0xbcea44a2, 0x3dedd6c2, 0xbe04f2e0, 
    0xbe2ecb3b, 0x3e1f11d9, 0x3bd6f882, 0xbe43b4cf, 0xbe069606, 0xbe5406f7, 0x3d14677b, 0x3e297dfa, 
    0xbdcb1f5b, 0x3e2de477, 0x3e154622, 0xbd3e9391, 0xbb3fac41, 0xbdac3e5e, 0xbe835d1f, 0xbd09e18e, 
    0xbe2bc8fd, 0x3e0dd694, 0x3d02de4f, 0x3e1bc742, 0xbe0a6e8f, 0xbdbbf042, 0xbdb62010, 0x3da7f7c1, 
    0xbe281a4f, 0xbcc5286e, 0x3ce06769, 0x3e3a51cc, 0x3c8a274b, 0x3dbe3455, 0xbe51bc56, 0x3cea6e6a, 
    0xbd4df15f, 0x3e1538f6, 0x3e4153e1, 0x3da94b79, 0xbd404d72, 0x3de1145c, 0xbdacb8d5, 0xbd891863, 
    0x3d9f1b51, 0x3e021594, 0xbe39684e, 0x3d136abb, 0xbde58d62, 0x3e46afcb, 0x3cc4d399, 0x3dd8e678, 
    0xbda55590, 0x3e2d936d, 0xbe55b1f4, 0xbdbe36ec, 0x3dbb5e04, 0xbd0433e5, 0xbe01d1f3, 0x3e276510, 
    0xbd645a3c, 0xbe1a795e, 0xbe244d4b, 0xbc3e8c37, 0x3d4b839a, 0x3dadb4f2, 0x3e47540d, 0xbcb54703, 
    0x3dd70383, 0xbcc2e0c2, 0xbe02cd8f, 0xbe024a02, 0xbdf315d7, 0xbd7dfaec, 0x3db946a3, 0xbddfc3e0, 
    0xbd1faba4, 0xbe0883eb, 0xbe29a7a9, 0x3e3489ed, 0xbd268d85, 0x3d90b6a4, 0x3dcf25e3, 0xbd3cd21a, 
    0xbdfedc39, 0xbdd81c30, 0xbdb885cc, 0xbda70d49, 0x3d938350, 0x3cc3dfc0, 0xbd1c7e94, 0x3daa8d41, 
    0xbe1950df, 0x3c3fcbf2, 0xbc454fdb, 0xbc2e286d, 0x3d4d1aaa, 0x3c112c7c, 0x3e72d0ad, 0xbdac8223, 
    0x3e02c4a1, 0x3e334f26, 0xbdaafdef, 0x3be8c271, 0x3e27fe9e, 0x3e294992, 0x3e28ca35, 0xbc792b45, 
    0x3db479cc, 0x3d8ea3f9, 0xbe224f8e, 0xbd92aaf7, 0xbd6e2feb, 0x3dd61e4f, 0x3e14911c, 0xbe524e0f, 
    0xbe4a417a, 0x3caf962a, 0x3e1efb25, 0xbcec80c7, 0x3e2f7bb9, 0xbd92ef8f, 0xbd349d11, 0x3cc01b52, 
    0x3d1d91dc, 0xbd638afa, 0xbdbb917f, 0x3e12b643, 0xbe0c1bdf, 0x3e321b40, 0x3cfa749c, 0xbddb1e50, 
    0x3d824a9c, 0xbdaca94a, 0x3db35aec, 0xbde66601, 0x3c41a987, 0xbd5896cf, 0xbe21baf1, 0x3c45bbf3, 
    0x3c579ce9, 0x3d95a8c2, 0x3cd92d65, 0x3d6872fc, 0x3dbf9b24, 0xbe2ef55e, 0xbe0ed335, 0x3dd93199, 
    0x3d69bfa7, 0x3db723b6, 0xbd87997d, 0xbe317c17, 0xbe195e86, 0x3c33a071, 0x3de5a214, 0xbe2488b1, 
    0xbe3023cb, 0xbb5c0f5e, 0x3d9ef861, 0x3deccfb4, 0x3df689ea, 0x3d91fbd6, 0xbe24ac92, 0xbd05f2ec, 
    0x3dc82265, 0xbdffb55e, 0xbda75740, 0xbda89b7b, 0xbd0ffea4, 0x3daca27a, 0xbdf95ed9, 0x3e0d8bd0, 
    0xbda94e53, 0xbe15df91, 0x3e0eac39, 0xbd127b9d, 0x3d910f2b, 0x3cc17737, 0x3e100b48, 0xbe2b2767, 
    0x3dcc0ad1, 0x3e372d3a, 0xbdfef08e, 0x3e1eade6, 0xbb6cb82f, 0xbd231810, 0xbd2ac6d7, 0x3e25b86c, 
    0xbdbb30d3, 0xbe061ba8, 0x3d90af85, 0xbdb80684, 0x3e2f9fc5, 0xbd3370f5, 0xbe58c5f9, 0x3e0795a9, 
    0xbcaf2c0a, 0x3d77f538, 0x3d62aaa4, 0x3e132790, 0x3d6449b8, 0x3d12c7ee, 0xbd8c5e0e, 0x3cda4e55, 
    0xbdf880eb, 0xbe15a36a, 0x3d26b7c4, 0x3daf96a4, 0xbdc60a29, 0x3e366a61, 0xbdd89a7d, 0x3d76be32, 
    0xbe0e8651, 0x3e18ac88, 0x3e3d15ed, 0xbe34e376, 0x3cab9d90, 0xbdbb1233, 0xbe1569dd, 0xbdd86879, 
    0xbc2b3737, 0x3d0ee04e, 0xbd99540e, 0x3e27bd0d, 0xbc089ec3, 0xbe3f0820, 0x3da702d8, 0x3e1b8291, 
    0xbdb7c081, 0xbde11f16, 0xbd8a86a5, 0xbe1a68fd, 0x3e00a597, 0x3e0e61a2, 0xbe0585a5, 0x3dd6508e, 
    0xbd5343c3, 0x3e1095e0, 0xbe1f8eb2, 0x3d8bdcc8, 0x3c92573f, 0x3e086200, 0xbd76ad4d, 0x3e1b2ee7, 
    0xbdf5a9f1, 0xbdd2702b, 0xbdcebc24, 0xffffb796, 0x00000004, 0x00000010, 0x00000001, 0x0000000c, 
    0x00000001, 0x00000010, 0xffffb7b2, 0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000006, 
    0x00000010, 0xffffb7ce, 0x00000004, 0x00000010, 0x00000001, 0x00000006, 0x00000001, 0x00000020, 
    0xffffb7ea, 0x00000004, 0x0000000c, 0x00000001, 0x00000003, 0x00000020, 0xffffb802, 0x00000004, 
    0x00000034, 0x3d4fef2c, 0x3db57e9c, 0xbc984073, 0x3c273663, 0x3de9b843, 0xbd87e112, 0xbaeef26c, 
    0xbc64bbcd, 0xbd489cf4, 0xbc5cc0e0, 0xbd518ae3, 0x3db0b353, 0xbc8adbf4, 0xffffb842, 0x00000004, 
    0x000009c0, 0xbd9af0f0, 0xbda389de, 0x3dcbab99, 0xbdaff3e7, 0x3c436e2d, 0xbd7e4369, 0xbdb39fea, 
    0xbd832100, 0x3c9285ae, 0x3d04272d, 0xbccd9438, 0xbcacfac7, 0x3d4f11ae, 0xbc94343c, 0xbc53ad28, 
    0x3d0eebc1, 0x3d10e666, 0x3cfeb3b9, 0xbcf2de4f, 0x3d746150, 0xbda07f1f, 0xbd8728cc, 0xbd8f97e7, 
    0xbd333578, 0x3d29505c, 0xbcefd388, 0x3d804681, 0x3d5806c4, 0x3d79792b, 0x3d5e9564, 0x3cf75edc, 
    0xbb8db234, 0x3db53676, 0xbd8be513, 0x3d326962, 0x3d3e2000, 0x3da6b5f4, 0xbcd8951c, 0xbd3da797, 
    0x3e0d9627, 0xbdd3642e, 0x3daef807, 0x3da2c6a5, 0xbe5f6220, 0x3e32db79, 0xbd8dc55f, 0x371d0c17, 
    0xbdc935d4, 0xbd91b427, 0xbd2189f0, 0x3e13fcc2, 0xbe437c20, 0xbd3ce4e6, 0xbdff8467, 0x3de7c41a, 
    0xbd73f834, 0x3c3558b3, 0x3e05a93e, 0x3deedbcf, 0x3dbff7e6, 0x3e22b971, 0x3df93902, 0x3e1d33e4, 
    0x3d84c1ba, 0xbdbd6016, 0xbdd94a3e, 0xbd4b623d, 0xbe139b87, 0x3d113af6, 0x3d5d8e13, 0x3d765375, 
    0xbdbd8683, 0xbde407bb, 0x3d9942e9, 0xbd57cb55, 0x3c24a76c, 0x3e367994, 0x3d5b57f6, 0xbcd66bc8, 
    0x3ddf83ee, 0x3daa1a1f, 0xbd0aec6f, 0xbddc6e3b, 0x3e1b5c21, 0xbe07181a, 0xbdfed65d, 0xbe42c884, 
    0xbe2eb498, 0xbe48dd77, 0x3cdbabf4, 0xbdf998b1, 0xbe2e9e11, 0xbe09a295, 0x3e0810b0, 0xbdfaba7c, 
    0xbd2c1c1d, 0x3da64711, 0xbd6766be, 0x3e5930bd, 0xbe2072e0, 0xba5f174c, 0x3e059c96, 0xbe0b4657, 
    0xbdc1c588, 0xbe0c6015, 0xbe1e285c, 0xbddeea2a, 0x3d873180, 0xbe2bb4a1, 0x3dca84e2, 0x3d8ba4bb, 
    0x3e48908f, 0xbca7221e, 0xbd86e0ad, 0xbda75ad5, 0xbe4521ef, 0xbd2fb359, 0xbe0e3d79, 0xbd1baed7, 
    0x3df2f6d8, 0xbdad0823, 0xbe133f01, 0xbe28d975, 0xbd9ee2be, 0xbded1b9e, 0x3d860c87, 0x3bf4810b, 
    0x3dc726dd, 0xbd0c8338, 0x3e191d8b, 0xbd87cce8, 0x3dd86910, 0xbd947d60, 0xbe22c85e, 0xbd0a7b1d, 
    0xbbcf97a3, 0x3dab6896, 0xbdd66e35, 0xbdc8b10f, 0xbe15c07b, 0xbe067aec, 0x3df7021b, 0xbd23c3a6, 
    0x3e01fbab, 0x3d913679, 0xbc8697aa, 0xbcc59bc3, 0xbdf2aa07, 0xbe3f67d1, 0x3cbd390d, 0xbe3996f1, 
    0x3e1ad0a4, 0xbdfdff06, 0x3dab95c3, 0xbd468986, 0xbd8c7c8f, 0xbda0668a, 0x3b3ebff0, 0xbd876406, 
    0x3cf93ceb, 0x3e1e4223, 0xbd0a3033, 0x3ce92fa5, 0xbe197854, 0x3d08460e, 0xbdbc4b31, 0x3e08063a, 
    0x3cf9d5dc, 0xbc9b6bf5, 0xbd3350a3, 0xbdb22eab, 0xbc32ad9a, 0x3be1f0ec, 0x3d7e352c, 0x3d9ca5f8, 
    0x3da53b37, 0x3e04c69d, 0x3d8fb2e5, 0xbde5a276, 0xbe1f37f5, 0xbdbeb753, 0xbdd6e728, 0x3e3297e8, 
    0xbcb29936, 0xbd878529, 0x3dc7fb83, 0xbdf0d228, 0x3e0707de, 0x3cb3449e, 0x3de10599, 0x3d155957, 
    0x3d2d827e, 0xbe264029, 0xbc15d8b0, 0xbd0350e7, 0xbda67721, 0x3d407e48, 0xbd77677b, 0xbc7825fc, 
    0x3d97d471, 0x3d7da485, 0xbd11318f, 0x3b290ecc, 0xbda76a17, 0xbd854d11, 0x3dac98fe, 0x3d418824, 
    0xbd68cc14, 0x3c27767c, 0xbdb560ed, 0xbd251f9e, 0x3d6dfbe5, 0x3d930d66, 0x3d2efafd, 0x3d4c7b75, 
    0xbd9db7e8, 0xbce02673, 0x3cc70d95, 0x3af9d00c, 0x3daf5983, 0x3d8b48d0, 0xbd5889b6, 0xbd8e0fb0, 
    0xbdad8c3e, 0x3db18319, 0x3d2999f3, 0xbd404a3f, 0xbd1536d8, 0xbdc8e8aa, 0x3ccb5612, 0xbc6d8822, 
    0x3d70c9f8, 0xbda8e1d4, 0xbda41c8f, 0x3e09ed00, 0xbe318980, 0x3c94f578, 0x3d916db1, 0x3c3d94d0, 
    0xbe130ddf, 0xbde8b345, 0x3bd071cc, 0xbd16a443, 0xbe153a50, 0x3e17e636, 0xb8a950a8, 0xbdc0ccda, 
    0xbdfec2fd, 0xbb359205, 0x3c65b349, 0x3e145de6, 0x3da3e636, 0xbd93dff7, 0xbe65cda7, 0xbd589a12, 
    0x3c3fdd79, 0x3d45d491, 0x3dca0ab1, 0xbe351628, 0xbc025b27, 0x3df19089, 0xbe107d8a, 0x3da4f044, 
    0x3d4b5863, 0xbe023c33, 0x3da07b0b, 0xbe2f243e, 0xbd443e3f, 0xbcbd1d7e, 0xbda7c605, 0xbd8a33f8, 
    0xbd7241a2, 0xbda27864, 0xbe2cf822, 0x3dfc871b, 0xbe5402e5, 0x3e544ef4, 0xbc8187e7, 0xbe62e5df, 
    0x3e13799a, 0xbd934702, 0x3d3ac52d, 0x3ca35466, 0x3e6c2697, 0x3e393d8f, 0x3b45187d, 0x3da0c989, 
    0xbd6f42f0, 0xbda3ae3f, 0x3dd6dc75, 0x3d2ce8f2, 0x3e5a4f45, 0x3e4aaee1, 0x3d67fd49, 0x3e042117, 
    0x3e108b96, 0x3e64db0b, 0x3dcaa800, 0x3c089ca6, 0x3bd2bd04, 0xbe47c88c, 0xbe32a0d8, 0xbe1fe65e, 
    0xbdea65cb, 0x3d989c77, 0x3e658e77, 0x3e710706, 0xbe3e27cd, 0x3dbcd04a, 0xbcb76205, 0x3d949e97, 
    0xbe0a9012, 0xbcb927e7, 0x3d49129a, 0x3da4dd2c, 0xbce58daf, 0x3e02bfa0, 0x3cc4bf8b, 0x3d954a6f, 
    0x3d3488f7, 0xbe164194, 0x3dae5b72, 0x3e0ef8ca, 0xbda47694, 0xbe3251b5, 0xbe31658e, 0xbd7f7f56, 
    0xbc15ac09, 0x3d812700, 0xbd515c65, 0x3e12e7bd, 0xbda92b1e, 0xbce34421, 0xbdaf8342, 0x3da9d023, 
    0x3da92369, 0xbd89c9ed, 0x3d18b516, 0xbe1fd637, 0xbd105d50, 0xbc97c6ae, 0x3b91ad8c, 0xbe0bdf63, 
    0x3df5322e, 0xbdddae7a, 0x3d55cdeb, 0x3bf5c417, 0x3da970c0, 0x3d95854e, 0x3c7362ee, 0xbe0b03cb, 
    0xbdc9d406, 0xbc678750, 0xbe30f7ab, 0xbe1a88b2, 0xbda2f5a1, 0xbddfd39d, 0x3cc293bb, 0x3d7bf9d2, 
    0x3d878fc4, 0x3e53dbbe, 0xbe18a4d0, 0xbd9807c7, 0xbe419255, 0xbbe7afaf, 0x3cf4ab8b, 0x3dea1040, 
    0x3e52b95a, 0x3d252d50, 0xbd904a34, 0x3de1aeb9, 0x3da95a4f, 0x3e5b87ac, 0xbd8f3775, 0x3d6bd478, 
    0x3d7a19f7, 0x3d0bbd19, 0xbe02701a, 0xbdeaf538, 0x3de82c8c, 0x3e5600d9, 0x3e18ee2a, 0x3d2473d3, 
    0x3cc35285, 0x3d11f23b, 0x3e0b8797, 0x3c48cf65, 0xbdcad60f, 0xbde0cb2e, 0xbbd50335, 0xbe43c3a2, 
    0x3c977f03, 0xbd81ae17, 0x3e158f84, 0xbcacfcea, 0x3dd9a797, 0x3ca3d457, 0xbe2dd9e6, 0x3bcc85f8, 
    0x3d890eb9, 0xbd8fa60d, 0x3b8bb4ee, 0x3de70ef8, 0x3cc829b9, 0x3dc5137f, 0x3d8f8cb0, 0xbdfb8db2, 
    0xbdf99426, 0xbe388a32, 0xbbbb598e, 0xbd924017, 0xbdbccf7a, 0xbde8a7ab, 0x3d0bef44, 0xbd875095, 
    0xbd8df29b, 0xbcb06f38, 0xbd4c9020, 0xbe01a67e, 0x3dab64cc, 0x3df827f8, 0xbdc15622, 0x3b6528d1, 
    0x3e2118e5, 0xbe0c95af, 0xbd579552, 0xbdbb1fa7, 0x3e4bcba5, 0xbe049100, 0x3b93c09c, 0xbd3fdb7e, 
    0x3df0832d, 0xbc6a6420, 0x3c9ad4df, 0x3dc738fb, 0x3c88d126, 0x3cd3ddc1, 0xbdaffb68, 0x3d9b8a4a, 
    0xbd7c7422, 0x3d8dda30, 0xbd7ae90e, 0xbd1139da, 0xbda61f4b, 0xbd8a4d49, 0xbd873b43, 0xbb4559f2, 
    0x3d9ee510, 0x3c799617, 0xbd48c737, 0x3c95421a, 0xbdb7379b, 0x3c92d011, 0x3c7152bd, 0xbd2b75fe, 
    0xbd221813, 0xbdae99c1, 0xbd3e2db2, 0x3d81309e, 0xbd0f79e5, 0x3d1798c6, 0x3ddddb65, 0x3d910cb8, 
    0xbd530e41, 0xbded13e6, 0xbdbcbcf1, 0x3d99a5e4, 0x3dd21940, 0xbda77350, 0x3c8599f5, 0xbd027cff, 
    0xbbd02e40, 0x3d1e8ce4, 0x3dd20ea8, 0xbd9a3105, 0x3e3d0cd3, 0x3da79acb, 0xbdc8448f, 0xbe01de5d, 
    0x3dbbd0ff, 0x3d149952, 0xbdb7e5b7, 0x3db597b6, 0xbddab023, 0xbd639227, 0x3de19f3f, 0xbe1c9327, 
    0x3d945c3e, 0x3d2bf10f, 0xbd01f327, 0x3cdb8f4b, 0x3d6c4d75, 0x3ccb3ef6, 0xbc452ff8, 0xbe0fd6cf, 
    0xbdacdcf4, 0x3d4e5670, 0x3da3e7ca, 0xbdc70d6b, 0x3d29d7f5, 0xbdb1dfbf, 0xbd1459c1, 0x3d8260a5, 
    0x3ddc8a41, 0x3dd6f721, 0xbce4bc0d, 0x3e243bf5, 0xbd831eda, 0xbd8599c6, 0xbc9fa5a6, 0xbd9dc697, 
    0x3b74b970, 0xbac0ab6e, 0xbd6e32eb, 0x3cf6f9a9, 0x3d91157c, 0xbd9107d2, 0xbd4bf27e, 0x3d1ddc64, 
    0x3d36ed3f, 0x3d2d154a, 0x3cd445c5, 0xbd074cab, 0x3d1276af, 0xbccd7cf7, 0x3c1355bb, 0x3c528085, 
    0xbcae57b1, 0x3dc6232c, 0x3b8e10bf, 0xbd27ba4d, 0xbd6c6695, 0x3d446dd6, 0xba21f7c8, 0xbd93ef0d, 
    0xbd2205cc, 0x3c6d5ff0, 0xbd5b8920, 0xbca97b89, 0xbd91bcfd, 0x3de7789b, 0xbce50f62, 0x3d9f0a05, 
    0xbcaf2d14, 0xbc8f6ee5, 0x3d46f7ff, 0x3d33ea3b, 0x3d285199, 0xbdb39156, 0x3ca4de7f, 0xbd488bac, 
    0x3cb200d0, 0xbd554ef8, 0x3d0b7269, 0xbd445446, 0xbdd5eee6, 0x3d62996e, 0xbd7d3dc8, 0x3daa7049, 
    0x3d5970e7, 0x3d1cfcf0, 0x3d835043, 0xbc6b1403, 0xbdac794b, 0xbd7d8bd9, 0x3d91905a, 0x3c402cc8, 
    0xbd6d0ced, 0x3d91d952, 0x3c08e894, 0x3d2e12ae, 0x3d16f6a2, 0xbd847550, 0x3c81ec48, 0x3d47af5a, 
    0xbcd3f31c, 0xbd297a18, 0xbccbd08e, 0xbda498fb, 0x3d25e4cc, 0xbbbd6c1a, 0xbb735a6c, 0x3d50bcf6, 
    0xbd1bd6d5, 0xbc016733, 0xbd72091b, 0x3d98248b, 0x3db03316, 0x3c8ab4ae, 0x3d91acb9, 0xbb580fa7, 
    0x3cb5f2ba, 0x3de63833, 0xbdbc5554, 0x3dd4f146, 0x3c53be3f, 0x3daa5b62, 0xbd46a460, 0xbd319d86, 
    0x3d79ab78, 0xbc9ec1fb, 0xbd60a19a, 0xbd062922, 0xbd873c54, 0xbbed2223, 0xbca33bc0, 0xbd19dcc2, 
    0xbd22ed9f, 0x3cc59e4e, 0x3cc794bd, 0xbd4d052a, 0x3d8d6ad1, 0x3d13fdcd, 0xbd7ee8c1, 0x3de272d9, 
    0x3c949bf2, 0x3d9aa259, 0xbd9f0fcd, 0xbb87c5f9, 0x3add6891, 0xbc4418a1, 0x3b974f39, 0x3d928682, 
    0xbc2c6c83, 0xffffc20e, 0x00000004, 0x00000c00, 0xbe92b041, 0xbe49e86c, 0x3ef7df86, 0xbe723c44, 
    0x3f17d6b3, 0x3e9d7580, 0xbc98270a, 0xbeef3946, 0x3f11bb47, 0xbea73593, 0x3daaede4, 0xbec4dafb, 
    0x3e08c6c1, 0x3ec1d2e6, 0xbe4c97dd, 0xbe120aee, 0xbead76d2, 0xbe07f21f, 0x3ebe8b8b, 0x3eca4725, 
    0xbeaaff54, 0xbdfcffd3, 0xbee1b81f, 0x3f0b3e20, 0x3c832faf, 0xbdffb160, 0xbeca7d03, 0xbe35b2e3, 
    0xbf068562, 0xbe2b4581, 0xbebf6c4a, 0xbf3005ee, 0x3f4c0821, 0x3ee9b3fc, 0x3f12590b, 0xbcd30601, 
    0xbe883dd8, 0xbdc8f963, 0xbd965b47, 0xbdeb8ecd, 0xbdf73696, 0x3ee94372, 0x3dc7157f, 0xbdc8036b, 
    0xbf0f8063, 0x3effd0a7, 0x3c864a18, 0xbf008203, 0x3ecb4776, 0x3e0d2217, 0x3eb8c019, 0xbe73832d, 
    0xbe4a2795, 0x3ce162e7, 0x3f6f23a8, 0x3e9c4797, 0xbf02c2cf, 0xbee49a37, 0x3f332092, 0xbd4bcf40, 
    0xbe7d3ebe, 0xbf2923ef, 0xbf50b83a, 0xbead615b, 0xbe6d2174, 0xbec552f5, 0x3f631666, 0x3f20bb6d, 
    0x3eb862e5, 0xbcbeae49, 0xbf0e05a2, 0xbe9d2433, 0xbf4e43bd, 0x3ef0aa3f, 0x3ef46d3e, 0xbf1b382a, 
    0x3eb90210, 0x3e52ec4c, 0xbf32e26b, 0x3e4acd23, 0x3eb89dcd, 0xbe1297ca, 0x3e0857ae, 0xbe3fa350, 
    0x3f061b64, 0x3ec6c932, 0xbf4b4300, 0x3f0e4531, 0xbde28caa, 0x3f187763, 0xbf586620, 0xbf2d0c81, 
    0xbee9c251, 0xbdfb6e01, 0x3d312bbd, 0xbf3fc74a, 0xbf2e5598, 0xbf03406b, 0xbf432f45, 0xbe263075, 
    0x3f4998cb, 0x3f4b4e9f, 0x3e4a637d, 0x3e46243f, 0x3f040ba3, 0xbe503b73, 0xbf1cd686, 0x3cb542f2, 
    0x3ed611ec, 0x3e8dc60e, 0x3e6605a7, 0x3f1421a9, 0xbe973f26, 0xbd41c8e0, 0x3ece7660, 0xbea942cd, 
    0xbeff9f4e, 0x3ee75960, 0x3e2a1304, 0x3df352c6, 0x3e698ff2, 0xbc82a63f, 0xbba60991, 0x3eaa85b7, 
    0x3e79fb56, 0xbed2853a, 0x3eb31995, 0xbeb5ebeb, 0xbe960a5f, 0xbf2b2529, 0xbe13d844, 0xbf124d64, 
    0x3e819a22, 0xbcad408d, 0x3f830ae4, 0x3f52f767, 0xbf270a84, 0x3e2de7f7, 0x3c4c8ee5, 0xbe9d3d8c, 
    0xbe8f95ef, 0xbf714568, 0xbef5a92c, 0x3ef97a7e, 0xbe34a78d, 0x3f01c2ca, 0xbec4e9ea, 0x3e6a07ff, 
    0x3e4e540d, 0xbdbf86f9, 0xbe3d8ea6, 0xbea9bbff, 0x3e5766f6, 0xbeae5dfd, 0xbf340170, 0x3d094784, 
    0xbf39c859, 0xbe46e4ca, 0x3edfc203, 0x3e0bf575, 0xbec4fb42, 0xbf0b4652, 0xbf0f593f, 0xbf1042d2, 
    0x3edfa8e3, 0x3eef2bc1, 0xbec37fe8, 0xbe845957, 0xbe7bd90f, 0xbd1af18e, 0x3e2234b8, 0x3e58db3d, 
    0xbea45a57, 0xbee3927b, 0x3e91dbbb, 0xbdea0bb6, 0xbe196707, 0xbeae69cd, 0xbf276040, 0x3e471fbb, 
    0xbed747ce, 0xbe054867, 0xbe89fb3d, 0x3ee53140, 0xbe060860, 0xbe24611f, 0xbeb98e45, 0x3f2e33de, 
    0x3e515c31, 0x3eb38d51, 0xbeb87c91, 0x3e394f3c, 0xbe1e15f7, 0xbec74503, 0x3c85d787, 0x3f1073c9, 
    0xbe6f1e01, 0xbe9f6fc9, 0xbf01e9ae, 0xbe1965c1, 0xbe829ffc, 0x3dbe5d4c, 0x3f02e750, 0x3dedfb36, 
    0x3ef9e423, 0x3f13130d, 0x3e9fdacc, 0x3ea4a704, 0xbe22e653, 0x3e4a19d0, 0x3f129c2a, 0xbe6bce10, 
    0xbdae4f04, 0xbf01b75e, 0xbeccb60e, 0x3ebc5808, 0xbec957a7, 0x3ecdd2aa, 0x3efca8ac, 0x3e0eb838, 
    0x3ecba84b, 0x3e79a9a3, 0x3f2716ea, 0xbe85ba32, 0x3eb5d253, 0x3e2e5c8d, 0xbe281c0c, 0x3f1c9f12, 
    0xbf0d6a3a, 0x3edc878f, 0x3eed0c02, 0xbe2d5c51, 0xbe95fc23, 0xbe8f7724, 0xbe73a681, 0x3f03b353, 
    0xbe8de24c, 0xbef07349, 0x3f4c3e26, 0xbe3fa739, 0x3ed73645, 0x3df03e70, 0x3e99df3e, 0xbec493ee, 
    0x3e520f41, 0xbf099a5f, 0xbe391c29, 0xbec0a14b, 0xbdf0ec37, 0x3da12a39, 0x3cebdd03, 0xbe750a69, 
    0x3edb6676, 0xbdbda6ba, 0x3e0018ff, 0xbea88330, 0x3ec519e6, 0x3e71389f, 0x3e6937a8, 0x3ddacc73, 
    0x3d901e4c, 0xbeb54dbb, 0x3eaeb628, 0x3ca50791, 0x3ead2111, 0xbdcb3786, 0xbef987c6, 0xbe6082fa, 
    0xbed528c3, 0xbe97ecbf, 0xbe48e0a3, 0xbef0f55c, 0xbd92c013, 0xbeb97079, 0x3e9b74ec, 0x3edad030, 
    0x3df9fa26, 0x3edfcf2a, 0x3e75b9c6, 0xbe95fe37, 0x3e7fc6c0, 0xbeb54c0d, 0x3ed59116, 0x3deebc31, 
    0xbe835d93, 0x3e8de035, 0xbebcf85c, 0xbea3eea2, 0xbe34ced8, 0x3c5e448a, 0xbe117d64, 0x3e621459, 
    0xbd749d7d, 0xbdc04e9a, 0xbe3051dd, 0xbd75e08f, 0x3e72340d, 0x3d8e2aae, 0xbecac748, 0x3ee2759c, 
    0xbe3225d2, 0x3d0caa9c, 0xbe6ae71c, 0x3e83aa16, 0xbe28aac0, 0x3e29f02e, 0xbe20958c, 0xbed19a21, 
    0xbebc9b9e, 0x3e5b56af, 0x3e997c8e, 0x3e755fd3, 0xbf0bcfc8, 0x3e2e055d, 0xbeb82061, 0xbdf9446c, 
    0x3bf49dbf, 0x3d29a58e, 0x3e9b8665, 0x3d28a668, 0x3e6ed296, 0xbeabd78c, 0x3ed3310b, 0xbe7325b3, 
    0xbece73ce, 0xbdbcb0ca, 0xbe3af95b, 0xbeb2d01e, 0xbeb66361, 0xbe134540, 0xbec13658, 0xbe0680ba, 
    0xbea00095, 0xbcabd82d, 0xbeba3c16, 0xbecdb833, 0xbf7ae3c0, 0xbd6fb041, 0x3d231169, 0x3ba4113b, 
    0xbe9cd0c4, 0xbd144c52, 0xbec7a2ba, 0xbca76363, 0xbe9b79be, 0xbebe5024, 0x3f484d0a, 0x3e9f12a9, 
    0x3e0af2ca, 0xbf003f16, 0x3eee70fe, 0xbe9d3a5a, 0xbf9b968d, 0xbf14e800, 0x3f392f32, 0xbf3b7413, 
    0x3f6491c1, 0xbea23551, 0xbe7dde52, 0x3f66fa6c, 0xbd9c60dd, 0xbc3f8427, 0x3ef90772, 0x3f592d64, 
    0xbf3a32da, 0x3f3e4562, 0xbeb9a22e, 0x3e204402, 0xbf0e536d, 0x3f2bd6c6, 0x3dede512, 0xbf65c55f, 
    0x3f618c2b, 0x3db06d1e, 0x3f439095, 0x3ed7dc50, 0x3f1789b6, 0x3e19e561, 0xbf160830, 0x3f7f4f53, 
    0x3ef25d60, 0xbdf959a6, 0xbf20baf5, 0xbd694587, 0x3c43e5ed, 0x3ed81718, 0x3f0db3d9, 0xbeafc5aa, 
    0xbd888e75, 0xbd645e41, 0xbeb8b963, 0xbe35f359, 0x3ed20f6a, 0x3dec9e4b, 0x3d813f75, 0xbe2220fe, 
    0xbe157a35, 0x3e1f7fdc, 0x3d7d1a35, 0x3e2932d3, 0x3eb8a15f, 0x3e735537, 0x3f0d3e55, 0xbe673df8, 
    0xbe198099, 0x3eba6e65, 0x3e243d77, 0xbea53246, 0xbe8d85fb, 0xbe742fe3, 0x3d56f506, 0x3eabb2e8, 
    0x3e9a9b15, 0xbee92494, 0x3eefdb5e, 0x3eba05a2, 0xbe9fb3c8, 0x3ce8d713, 0x3c9a3f19, 0xbe6a9f30, 
    0xbe65ce29, 0xbec1663c, 0xbe8148d4, 0x3e420123, 0xbdec007c, 0xbd745972, 0x3ecb8a82, 0xbe8e4419, 
    0xbe24ea3f, 0xbec095dd, 0x3ea5977c, 0x3e90e109, 0x3ddc080f, 0xbefa8561, 0x3f02b4f7, 0xbdf5d92a, 
    0x3e98978a, 0xbd31245d, 0x3f224c3e, 0x3e22f6d2, 0x3db789e2, 0xbd93f844, 0x3e90db36, 0xbed92bcf, 
    0x3d0dba62, 0xbd1593a1, 0x3d9c2ed2, 0xbd6e0f68, 0x3ef7cdd8, 0xbeb09edc, 0xbf0f9d5d, 0x3eebfefe, 
    0xbe367002, 0xbe96d25c, 0x3f188f59, 0xbdfd6302, 0x3f07d167, 0x3dc75448, 0x3eac4fae, 0x3e80ea44, 
    0x3ea5a302, 0xbee1c8bc, 0xbeb0653d, 0x3f0f004b, 0x3d646940, 0xbf0fdbbc, 0x3d63070d, 0x3e001e79, 
    0xbd6a263e, 0x3dc2ef29, 0xbc3bee26, 0xbe5ed1e0, 0xbea3edee, 0x3d6bbe7e, 0x3edfca61, 0xbdd36c1d, 
    0x3bb3c6d3, 0xbe879a22, 0x3ee8e260, 0xbccc8217, 0x3e073610, 0x3e26d306, 0xbded398a, 0x3efdffda, 
    0xbe27cb10, 0xbdc20539, 0xbe762c22, 0x3e971bc8, 0x3f07cf75, 0x3d6c92c7, 0x3eb3bdc8, 0xbddf9a20, 
    0xbebcc921, 0xbf0fa642, 0xbd87fdb0, 0x3ea2592a, 0x3e73fc39, 0xbe2fd3f0, 0xbe78eb84, 0x3e55bb4b, 
    0x3e86cd97, 0x3e3cd958, 0x3cb3d115, 0x3e500f03, 0x3e903da2, 0x3e944ec1, 0x3deb63e1, 0x3dc5a91b, 
    0x3dad6973, 0xbee8bf23, 0xbee503f7, 0x3e5979cf, 0xbe13927a, 0xbe4dc942, 0x3d974500, 0x3e796d20, 
    0xbd2c6ccb, 0xbe951edc, 0xbedbbf08, 0x3e44c63e, 0xbc687e7d, 0x3e999914, 0x3e57898e, 0x3e0832d9, 
    0xbeabda29, 0xbf07bede, 0xbec8e2bb, 0x3ebc637e, 0xbe024327, 0xbf2cf596, 0xbf18cea9, 0x3e4b8cc5, 
    0xbb3e65aa, 0xbf43def8, 0x3e11a979, 0x3dd42ede, 0x3d1d3766, 0x3ec4eb15, 0x3e5215f1, 0xbde40731, 
    0x3ddf18eb, 0xbdb87222, 0xbf1567cc, 0x3ec6a6f0, 0xbf0e4cf3, 0xbf21b25b, 0xbf1672eb, 0x3e671459, 
    0xbeb62ac5, 0x3e47daa7, 0xbdfcad4c, 0xbe6987f2, 0xbeb140f2, 0x3edd4536, 0xbd51758c, 0xbe523728, 
    0x3ef2187e, 0xbf64c265, 0x3e5b17e3, 0x3ef14c43, 0xbed12aca, 0x3eb47e1e, 0x3eee6e60, 0xbf39eab1, 
    0x3e64ff83, 0xbe73b7b6, 0x3ed39532, 0xbed8ace6, 0x3f466158, 0xbe9c292f, 0xbd2c11a7, 0xbe6a3fc6, 
    0x3d81ae0b, 0xbf07c020, 0xbf2686ed, 0xbebdede4, 0x3f5effb9, 0x3ec86953, 0xbe69275b, 0x3c91c505, 
    0xbeb3159b, 0x3f2749e5, 0x3eba160d, 0xbeb2c7fb, 0xbf257121, 0xbe233a99, 0x3e0a8d58, 0xbe27c8e2, 
    0xbf2ade7f, 0xbec96056, 0x3e9a6532, 0x3e582588, 0x3f542d5c, 0xbed68267, 0x3f39e0f7, 0x3ef04a5c, 
    0x3f437c5d, 0x3ee44bac, 0x3e93fe0b, 0x3f349600, 0x3e7af070, 0x3f290d9d, 0xbebc374d, 0x3db1b13e, 
    0x3f1af325, 0x3f5d816e, 0x3cb90d44, 0xbde62197, 0xbe923806, 0x3e617120, 0xbe95607a, 0xbf036445, 
    0x3f46f296, 0xbf081c96, 0xbe6b3c9d, 0x3ee015e0, 0x3f1b0f12, 0xbe8c8dd9, 0xbf198ad3, 0xbeac5f4f, 
    0x3e88c694, 0xbe136bb9, 0xbd8db8ae, 0xbeb8db34, 0x3ea9de8d, 0x3ec36e24, 0x3f71cb21, 0x3e28307e, 
    0x3e7701e2, 0xbed6e50e, 0xbf013290, 0x3e633319, 0xbf12a9bb, 0x3e9965ff, 0xbf167780, 0xbf50d663, 
    0x3f06167d, 0xbef7c20a, 0x3efc9d2c, 0xbef8e10d, 0xbde534fa, 0x3f1be292, 0x3edbebc2, 0x3f5f83dd, 
    0xbe510483, 0xbe096be3, 0x3e6ddd28, 0x3c944d26, 0xbf2293c9, 0xbf0dff0c, 0x3dce4421, 0xbe8548f5, 
    0x3e514bb0, 0x3f64dd15, 0x3ec9a9e2, 0x3e82ef2a, 0xbef9e1fc, 0xbebfb218, 0x3efd505b, 0xbeb6148e, 
    0x3f497d3e, 0xbd016e06, 0xbf05ee25, 0x3f14fd5b, 0x3ec42d80, 0xbe8cde40, 0xbf0df565, 0x3ea6bd7b, 
    0x3d0a412e, 0xbf0b1453, 0x3f15c48f, 0xbe5b7cc6, 0xbee3bfde, 0x3d230198, 0x3e64a093, 0x3f1e8e98, 
    0xbce29dad, 0xbbb9820e, 0x3ec267fe, 0x3e696eb7, 0x3cef43ec, 0x3ccb69c8, 0x3ecfb0b9, 0xbd9c2aaa, 
    0x3eea8f4e, 0xbea5ed9e, 0xbe132ffc, 0xbebc731e, 0x3e348390, 0x3e2de82e, 0xbe8c9c5f, 0x3e83b672, 
    0xbedfec3a, 0x3eb5458b, 0xbe12e9bb, 0xbf05d187, 0x3ee069d7, 0x3f257e79, 0xbedb255e, 0xbeaaa2e8, 
    0xbecdfe01, 0xbd5f29d6, 0x3e013a7d, 0xbf24b80f, 0x3eda5eb7, 0x3ee0001f, 0xbf07bc68, 0x3e9b83e2, 
    0xbe1d112d, 0x3ebca880, 0x3e0445f7, 0x3f0d7848, 0x3e377ffc, 0x3f104c98, 0xbf048aa8, 0x3ecfcc48, 
    0xbf0e55f1, 0x3ee26c34, 0xbe37b541, 0x3eced5df, 0x3ea458a3, 0xbd316640, 0x3e8552a0, 0x3d0b30b2, 
    0xbee2cab7, 0x3eadd333, 0xbee6149a, 0xbee1b7d0, 0xbeed8982, 0xbd9f54fe, 0x3ebfd57a, 0x3ba4ff99, 
    0xbecf60bd, 0x3d8d0e10, 0xbf0896ea, 0x3e9e1eae, 0xbe55f981, 0x3ec6f7cb, 0x3e8cc666, 0xbf0ddcfb, 
    0x3e76d431, 0x3f262d7c, 0xbe9fec05, 0xbf04d2a4, 0x3eefb179, 0x3f0540ce, 0x3e825e52, 0xbe874eb3, 
    0xbeb1d005, 0xbf0597bc, 0x3f225336, 0xbde608de, 0xbf175fef, 0xbe77b8ee, 0x3f032eeb, 0xbed3e213, 
    0xbea525c8, 0x3db3945c, 0x3e44a05d, 0xbe006ae9, 0xbe522dc4, 0xbd7cd23e, 0x3f08418e, 0xbea362b3, 
    0x3ee3cdec, 0x3eb5de4e, 0xbed66f24, 0xbe3982cd, 0xffffce1a, 0x00000004, 0x00003000, 0x3d46e9f3, 
    0xbdbe4872, 0x3f226fa6, 0x3ebf6e0f, 0xbeb5dbad, 0xbe6f3679, 0xbeba047d, 0xbc621eff, 0xbe7295ad, 
    0x3f09a345, 0x3ede4202, 0x3e8d5733, 0xbe007ef9, 0x3de73e0c, 0x3eae7ccc, 0x3f08f42d, 0x3e359706, 
    0x3ecaf042, 0xbe6ccc9f, 0xbdab4dbc, 0xbee83956, 0xbe21fda8, 0x3e2d4693, 0x3ec8dbd3, 0xbdf550ab, 
    0xbdc51168, 0x3eeb104d, 0xbdf7e1a2, 0xbe36b033, 0x3d87bb07, 0x3e59ac34, 0xbedaa72a, 0xbe8e6cfd, 
    0xbe98ce97, 0xbe5a6f77, 0x3e87c6fd, 0xbd6466a3, 0x3f0a942c, 0xbe88a2c7, 0xbe996fe4, 0xbeb0f0d0, 
    0xbed6c23b, 0xbea3093e, 0xbd704111, 0x3e580f76, 0x3eb4c377, 0xbeace5dc, 0xbe677396, 0xbede96fb, 
    0xbe3c2e0c, 0xbe83ecf8, 0x3ce5e89d, 0x3e661c51, 0x3ea8c4a9, 0x3ed11804, 0x3e9a8574, 0xbee309a1, 
    0x3d852ebb, 0xbe25d6ad, 0xbd3ae880, 0xbf1e68f1, 0xbf21fa07, 0x3e8e27e7, 0x3eeaa1d0, 0x3e1d815e, 
    0xbed1f297, 0x3e9430f6, 0xbe5d62b6, 0xbec74bfb, 0xbef20715, 0x3e657f9d, 0xbe1d95b0, 0xbe508e29, 
    0x3dfea014, 0x3e28dc98, 0xbeb97200, 0x3edb3cf7, 0xbe714754, 0xbe3f0866, 0xbf1253fe, 0xbe3b6640, 
    0xbbcf5fe2, 0xbddf9651, 0x3e6fc3b6, 0xbd5c61ed, 0x3db2b280, 0x3e453a2a, 0x3f14159f, 0x3e55d75f, 
    0xbea9ddf0, 0x3e912715, 0xbd530264, 0xbdd20c5c, 0xbe44ab84, 0xbee636b1, 0x3ea10630, 0xbcfb98ec, 
    0xbe655acb, 0x3ea2d307, 0x3d9b52a7, 0x3f1110bc, 0xbebcb126, 0x3ebe8afb, 0x3f0c14e7, 0xbf02c7ca, 
    0x3f52f4cf, 0x3f0f1a80, 0xbef4063f, 0x3b581b1f, 0xbf410cfe, 0x3eaaba57, 0xbed90ce1, 0x3ee06d21, 
    0x3df08cc3, 0xbef7b156, 0x3e590216, 0x3dd2a36f, 0xbd6b5926, 0x3f1660cf, 0x3eae4411, 0x3e0bb0e2, 
    0xbee88935, 0x3ebcdf60, 0x3ece71d1, 0x3f12aae4, 0x3e8648b5, 0xbf16206f, 0xbf5a16c0, 0xbd1e90bf, 
    0x3ecbf4b5, 0x3f01daca, 0x3e9b8188, 0x3ed3608a, 0xbf018429, 0xbf0dc69d, 0x3d78cadb, 0xbdea0f92, 
    0x3f5b06f0, 0x3f0bf34c, 0xbe370dac, 0x3d7e02d9, 0xbdee6333, 0xbe8f59de, 0xbf0ada4f, 0xbf075f9b, 
    0x3f4c4ef8, 0xbf05a252, 0xbabeb827, 0xbe319356, 0x3f1bc48d, 0xbec0793b, 0xbf016c04, 0x3f602d64, 
    0x3e9f619d, 0xbed31927, 0x3ef5716f, 0x3edb2ddb, 0xbd60a4e9, 0x3ee9eb62, 0xbf5006e9, 0xbf05df5e, 
    0xbde4cce0, 0xbecbe087, 0xbe72ec57, 0x3f10c442, 0x3f254449, 0x3f04a40f, 0x3d295714, 0xbe1aef6f, 
    0x3e72f99e, 0xbf3f0a54, 0xbeac623b, 0xbe41de3a, 0xbf0d0532, 0x3f25288c, 0x3aafeb17, 0xbf02f368, 
    0x3c846529, 0x3dd23c95, 0x3ebbc615, 0xbe9ccb58, 0xbc546b1c, 0xbf09d6b0, 0xbf3b439a, 0x3ef5833f, 
    0xbf29320d, 0xbed1a695, 0xbf3fec3e, 0x3f1e5928, 0xbf1139c5, 0x3e34544d, 0x3dc86431, 0x3e9a80ac, 
    0x39a605e1, 0xbf2b9aff, 0x3eb3c149, 0xbec505d2, 0xbe9e9a50, 0x3eb32a5d, 0x3f046c4c, 0xbd37a610, 
    0xbf006d94, 0xbeda0446, 0x3ef1bb3a, 0x3ea23fc4, 0xbe4a29db, 0x3e3e4897, 0x3f1c43cd, 0xbe5e7036, 
    0x3ea08fb5, 0x3ebf1b6c, 0xbd8fc679, 0xbe9f4f62, 0x3d140b9b, 0x3eac1a35, 0x3e277e93, 0x3d52582d, 
    0x3cac5655, 0x3d853045, 0xbdc42586, 0x3e13d9c9, 0xbee4b272, 0xbe008d77, 0xbef6cc2e, 0x3f00cb6b, 
    0xbed776e4, 0xbf24d86b, 0xbde6a73e, 0x3c8ae49c, 0x3e2b5ed3, 0xbe04d531, 0xbdcb69c0, 0xbe5253d7, 
    0x3e399454, 0xbeb3e052, 0xbeb5b81b, 0xbe4894fa, 0x3dd2cdd3, 0xbed48b42, 0x3f0faa43, 0xbeb42aae, 
    0x3d518195, 0x3e7ac72c, 0x3e6d97ea, 0xbf02bcce, 0xbe70da07, 0x3eb88d4f, 0x3dff2cbd, 0x3e803fbe, 
    0xbe47a6ea, 0x3e9f2c7f, 0xbeead8b1, 0x3ed7ee33, 0xbe7bb299, 0x3e495f02, 0x3e54a475, 0xbe04fc34, 
    0xbe9ac07c, 0xbdbfefc7, 0x3e5c5a69, 0x3e076434, 0x3efb0378, 0x3eef4680, 0xbd392d09, 0xbf0319f3, 
    0x3e80441c, 0xbd632697, 0x3e05c8ee, 0x3ef45f82, 0x3e9e20dc, 0x3e31863c, 0xbe4d407e, 0x3ebe66bc, 
    0xbee60313, 0x3f01f039, 0x3eeffd01, 0xbf005a89, 0xbf0b4208, 0x3e11f611, 0xbe4708d9, 0xbed7255c, 
    0x3e4e2ffd, 0xbd8158c9, 0x3e6a560c, 0xbebc4841, 0xbd8117c4, 0x3eb8ec9f, 0xbe43849b, 0xbf0ee1b6, 
    0xbe13a722, 0x3d4d6a64, 0xbeff9eee, 0xbe3033e0, 0x3e94311b, 0xbe1408e1, 0x3cac898f, 0x3c43bed4, 
    0xbf1bd9d5, 0x3e9f4bbb, 0xbd832f74, 0x3d2674c8, 0x3e24f653, 0x3e935b12, 0x3ea64c10, 0xbe612d93, 
    0xbd10910f, 0x3eb2b54b, 0xbd07b089, 0xbea8e0b8, 0x3c9cd9fa, 0xbdb8ec42, 0x3c054a40, 0x3da0f061, 
    0xbf034bdc, 0xbd3fd1da, 0xbedf0d15, 0x3e0344f8, 0x3ebbd237, 0xbda0d1e1, 0x3e8c474f, 0xbeca32e1, 
    0x3dfe2cea, 0xbeab1837, 0xbe79ed78, 0xbed37985, 0xbee9a2ec, 0xbdd8ab92, 0x3ecd96a9, 0xbe02e5c1, 
    0x3dbf5788, 0xbea41418, 0x3c22d43c, 0x3f1c9075, 0x3e0c1935, 0xbe16ba09, 0x3f16b8f6, 0xbe03a04c, 
    0xbde6bc9d, 0xbeeb1a28, 0x3cb25f1f, 0xbe88adab, 0xbf14e447, 0x3d6cb7ef, 0xbe36f11f, 0x3f14d3dd, 
    0xbee32ace, 0x3e52acf9, 0xbe55346b, 0xbe611830, 0x3ef71fea, 0xbe34bf4f, 0xbe45ef30, 0xbebaa0db, 
    0xbe92a6b9, 0xbda19f98, 0xbe6bb4a3, 0xbe190d81, 0x3e866f2d, 0x3e52c4ee, 0xbe85fefc, 0xbde1445f, 
    0x3ee0f674, 0x3e265c6c, 0x3f135002, 0x3e822ac9, 0xbe0399bc, 0xbf26f0f0, 0x3ec4306a, 0x3f477472, 
    0x3e1b432f, 0x3ed3196d, 0x3e5e4ec1, 0x3e646a23, 0x3e2ccdc8, 0xbec182a0, 0x3db6594d, 0xbe4c3104, 
    0x3e96489a, 0x3dff3035, 0xbef38796, 0xbe874792, 0xbda1d100, 0xbdb81772, 0x3ecdef61, 0x3da33702, 
    0xbc59feda, 0xbf87923c, 0x3ed0691d, 0xbe2622be, 0xbeb9595b, 0xbc68d62c, 0x3f1952b4, 0xbea9e49a, 
    0x3f2606a9, 0xbd877242, 0x3e853f7d, 0xbefc4921, 0xbe602512, 0xbf7ce265, 0x3e968b0b, 0x3ebeda0c, 
    0xbef17a7f, 0x3ecbc4b2, 0x3ee47123, 0x3f040fcf, 0x3dcd65e6, 0xbe2eafbc, 0x3e6cb5c1, 0xbd4f3a3d, 
    0x3f168004, 0xbedb993b, 0x3ee94a90, 0x3f1c6df2, 0xbe5b182a, 0xbf156bc1, 0x3ed5a52b, 0x3edbd72a, 
    0x3e962100, 0xbf0e7a8a, 0x3ee70533, 0xbf43eb37, 0xbf2d89c1, 0x3f24c0d0, 0xbf37938a, 0xbd851fe4, 
    0x3e6182f3, 0xbee679cc, 0xbdca5a09, 0x3f0cb215, 0x3da8dd1e, 0x3e236ebc, 0xbef673d5, 0xbe0129ab, 
    0x3ecd4e6e, 0x3f1645a4, 0xbe3fbfc7, 0xbf082e1f, 0x3f099e2c, 0xba886830, 0x3e3cde02, 0x3f32a772, 
    0xbf8250f3, 0x3e1c140b, 0xbde506b0, 0xbf54d34d, 0xbe7f70ab, 0x3f2e06a0, 0x3c369a3f, 0xbee9046d, 
    0xbe446d99, 0xbcd68f5f, 0x3d666146, 0x3e0ad2ed, 0x3d3ae41c, 0xbb8292ca, 0x3f55c3e0, 0xbe0150bb, 
    0x3ebf448d, 0xbd9ccc16, 0xbe8d12af, 0x3c07cc8a, 0x3e053bdb, 0xbe46728d, 0xbeb54e5d, 0x3ea9b8a8, 
    0x3f309479, 0xbf09a34b, 0xbf0145b9, 0x3eb992e7, 0x3e6cb4b3, 0x3d4430a8, 0xbdb59652, 0x3eb85581, 
    0xbea08391, 0xbf359e5a, 0xbe761790, 0x3ed4cffb, 0xbf1838a7, 0xbdb0f97e, 0xbe8ffd87, 0x3ecb1b52, 
    0x3d96d684, 0x3e983a12, 0xbec7a96b, 0x3d32199e, 0xbe768b1f, 0x3da58b8f, 0xbe822ef2, 0xbf01b691, 
    0x3ef95702, 0x3eb51ba9, 0xbe3b404a, 0xbd8964a8, 0xbe15ea35, 0xbe98a674, 0x3f02716e, 0xbe4fd8ea, 
    0x3d1aa415, 0xbdc7d46c, 0xbeae92a2, 0x3ee3af25, 0x3ec2ed7b, 0xbeff9aab, 0xbe147312, 0xbe4dbe2e, 
    0x3ea9e7a7, 0x3e2def7f, 0xbe5de630, 0xbeab6cb8, 0x3eaaa0f6, 0xbf1a7f3e, 0xbd7672eb, 0xbe3077b7, 
    0xbdf99b27, 0xbee9a016, 0xbeea38d1, 0x3e89b9a8, 0xbea76f45, 0x3e9da241, 0x3cb4db95, 0xbf1c67ea, 
    0xbeccb5d1, 0xbf28d5c8, 0x3f00b035, 0x3f1958f7, 0xbe9e2af6, 0xbf34476f, 0x3e41612f, 0x3ee97d5d, 
    0x3d61297b, 0x3e4f3abc, 0x3ea4ef49, 0xbef438db, 0xbedafd52, 0xbeebffc7, 0x3e2a8c94, 0xbe92f464, 
    0xbedd0931, 0xbeb96581, 0xbf301b93, 0xbd40ab5b, 0xbef7f07a, 0x3e98bb69, 0xbeb1570c, 0xbf1247c1, 
    0x3ec792e7, 0xbecc9441, 0x3ee081ee, 0xbdf92fff, 0xbf38a9b1, 0xbe8447f7, 0xbeb18e4a, 0xbdd2898c, 
    0x3e5a323d, 0xbf237626, 0xbf0687c9, 0xbe92c098, 0xbe158c30, 0xbf03101a, 0x3e39e9e7, 0xbebf8455, 
    0x3e2a26db, 0x3ea778dc, 0xbde3952d, 0x3eea9646, 0xbdb3d9a6, 0x3e461804, 0xbe30f324, 0x3e46cef7, 
    0xbe685632, 0xbf108819, 0xbdc584bc, 0xbe8a6e7d, 0x3ed4b428, 0x3de9c1c6, 0x3eb08bd0, 0x3d8cb905, 
    0x3ed5b4ff, 0xbeeab9a7, 0x3ee66043, 0xbee795e7, 0xbef01073, 0x3ecb51e6, 0xbe3fd57b, 0xbd1db467, 
    0x3effe608, 0x3e0e2661, 0x3ef3e073, 0x3ee640d1, 0x3ec08053, 0x3d1c5296, 0x3eea210f, 0x3e5fb6d4, 
    0xbe3c74f0, 0x3ed8bf0d, 0xbdf50bc8, 0x3e55e741, 0x3f0751ee, 0x3ec58167, 0x3c9bba87, 0x3ecb1851, 
    0xbe9f0902, 0xbdab95f9, 0xbcdaba51, 0xbc04021f, 0x3e9dd7dd, 0x3e5fbfcc, 0xbd8e96a8, 0xbeceecfe, 
    0xbe077b46, 0xbe6f47cd, 0xbdc6e62d, 0xbec81693, 0xbec15852, 0x3ca1f0d2, 0xbe4cfeb7, 0x3f09138e, 
    0xbe8603b3, 0xbe148623, 0x3e659f7c, 0xbe29cbc7, 0x3d8935d8, 0xbe9c88ce, 0xbd3a1906, 0xbdd0ccd7, 
    0xb8975dc8, 0xbecd9393, 0x3eb8e46f, 0xbde7c592, 0x3f157395, 0x3e372ef0, 0x3d8ec141, 0xbde79670, 
    0x3e82a652, 0xbe978cd2, 0x3e7839e0, 0xbde8e92c, 0xbd409dea, 0x3d5f4593, 0xbdc83db8, 0xbe3574f7, 
    0x3eba640f, 0x3b78ed4d, 0x3ebd8bb9, 0x3dde2857, 0x3e2ee654, 0xbeaa8894, 0x3e31da98, 0x3e44a7df, 
    0x3e489b21, 0xbc721634, 0x3e5746dc, 0x3e460762, 0x3ea69761, 0x3ea49f92, 0xbe695dfb, 0x3ddce09c, 
    0xbd709a38, 0xbed244b7, 0xbed7f6b3, 0x3e01e300, 0x3d350377, 0x3ea75364, 0xbedb4f1c, 0x3ebba129, 
    0x3cf97e3e, 0xbe37521a, 0x3e4397dd, 0x3d4ce586, 0xbe3e6bd7, 0x3edd76df, 0xbd084bf1, 0xbf00064b, 
    0x3e8eaa00, 0x3e8b60cd, 0x3ebd71e2, 0x3f0c776a, 0x3edb2f55, 0xbf180064, 0x3e925d3e, 0xbed78bf6, 
    0xbea4dad4, 0x3e67ce91, 0xbce35fb0, 0xbeafda48, 0x3decb9e7, 0xbe85a18f, 0xbecfb03e, 0x3e96547f, 
    0x3eacf275, 0xbe67c78b, 0xbe9f32aa, 0xbf67dba4, 0x3dee4220, 0xbe863e08, 0x3ea863f1, 0x3e52b438, 
    0x3f36b8db, 0xbe8533b5, 0x3e93d4dc, 0x3e1820f1, 0x3eb00e3d, 0xbe982ec1, 0x3e19bcb0, 0xbf6fd897, 
    0xbede4531, 0x3f4df026, 0x3ee2d1bc, 0xbeb65067, 0xbed3deaf, 0xbe4c7c10, 0x3ed0f93b, 0xbe9fb948, 
    0xbdf59106, 0x3e400202, 0xbe08409d, 0xbf367e47, 0xbe2511ea, 0x3e73b890, 0x3e903b6e, 0xbeee9e57, 
    0xbf1ddf72, 0xbeaa642b, 0xbe76787f, 0xbf198801, 0xbed4d2d6, 0xbe992ef9, 0xbed0e84d, 0x3daecbd3, 
    0x3dfa01a0, 0x3eb4b502, 0xbe4d3c56, 0xbf19ecc6, 0xbe80bcbd, 0x3e730414, 0xbee113d5, 0xbe930b49, 
    0x3f026682, 0x3eb6b4a1, 0xbe4c92fb, 0xbeabd36a, 0x3f30b934, 0xbe1c5ef2, 0xbcbc0667, 0x3e1f6861, 
    0xbf1d4f9d, 0xbdd4bccb, 0xbe56b4d2, 0xbe3b3021, 0x3ec0bc9b, 0xbf114941, 0x3eb9ebf8, 0xbdf568b4, 
    0x3ef44c4a, 0x3dbb7207, 0x3d8df60d, 0x3f28f95b, 0xbf003944, 0xbd09cf71, 0x3f193b4b, 0xbe290909, 
    0xbe93cc1e, 0xbe8d15d5, 0xbe8008d4, 0x3dbd8522, 0xbebddbca, 0x3e7b6ec8, 0x3ee8ccba, 0x3ec7e2ae, 
    0xbeb63851, 0x3d1e5f83, 0xbd8554a0, 0x3c8a2dc2, 0xbc9db383, 0x3e179992, 0x3e892039, 0x3eed5473, 
    0xbebd7e67, 0x3eb38cde, 0x3da82aac, 0xbe98bd47, 0xbecffd1b, 0xbb43f084, 0x3edc3eb1, 0xbe801f8e, 
    0x3ecaace8, 0x3eaa0257, 0xbea583f2, 0xbe8017d3, 0xbe8f623a, 0xbea890fe, 0x3edec78b, 0x3ed225b4, 
    0x3c0d0e43, 0x3d1852e4, 0xbe932687, 0x3edb207e, 0xbe8c1739, 0x3e1cad6a, 0xbc66faad, 0x3eee7c10, 
    0xbf00da30, 0xbe331bab, 0xbe897f23, 0x3ec7aa57, 0x3db6c01a, 0x3e957aaa, 0x3eb5d3b1, 0xbe9c3042, 
    0x3e99b1c3, 0xbdf99e0b, 0xbe00111f, 0xbed1a45c, 0xbd15f2b8, 0x3e63c456, 0x3e6798b1, 0x3e830f8e, 
    0xbd500051, 0x3ed1625f, 0x3d1ce42f, 0xbec0e863, 0xbeadf4e8, 0x3b1b5737, 0xbdcc236c, 0xbb35095d, 
    0xbf11ce78, 0xbef982f0, 0x3eca3cb9, 0x3c21e720, 0x3e217e84, 0xbe0f8c47, 0x3de7a4ad, 0xbecaa559, 
    0xbdda7a29, 0xbe043b45, 0xbe0c8760, 0x3e945940, 0xbe83e369, 0x3ddcf14c, 0x3eb6fb61, 0xbeb11597, 
    0xbe822897, 0xbe9be2ca, 0x3e4a63d4, 0x3e0c2828, 0xbed3f766, 0xbea4143d, 0x3e992232, 0x3f23485c, 
    0x3ef876a8, 0xbdc5a700, 0x3d5c388d, 0xbe5af1ac, 0xbdb00bfa, 0xbe9441e4, 0xbd8d3393, 0xbe63299a, 
    0xbaabbd92, 0xbe1b384a, 0xbe5ee2a1, 0xbdc09457, 0x3e0240f8, 0xbe531710, 0x3ec3c774, 0x3e5b811d, 
    0x3e1062f3, 0x3dbb12f2, 0x3ecab064, 0x3ed4978f, 0x3e9b8737, 0xbe2f80ed, 0x3d83e731, 0xbf0945fd, 
    0x3e03d459, 0xbe30c325, 0xbe258ab1, 0xbf0c4515, 0x3e04c2d1, 0x3d8eb44f, 0x3e371901, 0x3d678a71, 
    0x3e5671ea, 0xbd07e0a2, 0xbeb18aff, 0xbeb22381, 0x3e47fead, 0xbed31c89, 0xbec95231, 0xbee68e9b, 
    0x3f01dcb7, 0x3e88d8b3, 0xbd86c97c, 0x3ce28252, 0xbee8c5c8, 0x3ea72a7e, 0xbe53db27, 0xbf19b1ff, 
    0x3eec6f7e, 0x3cca4bab, 0xbccc0f54, 0xbebb87f5, 0xbe2a62b4, 0x3dde3815, 0xbc8b4961, 0x3e8cab57, 
    0xbeee6049, 0xbe242256, 0xbde63222, 0xbf2427ef, 0xbeb6993e, 0xbe721f28, 0x3e5a9eb1, 0xbec7d8ca, 
    0x3e1527e0, 0xbd08c96b, 0x3e2e57c8, 0x3e9be91e, 0xbed7f255, 0xbe372ddd, 0xbeb37e8d, 0xbe9a85a3, 
    0xbdb331a1, 0x3eb41c11, 0xbeddb7b6, 0xbec4409c, 0xbecb91a2, 0x3d3211d7, 0xbef1806f, 0xbe162264, 
    0x3db1edc4, 0x3eec74c1, 0x3f19a81e, 0x3e843c39, 0x3edd234f, 0x3e6f7860, 0xbf0a1fe6, 0x3e80fec5, 
    0xbed638be, 0x3e828024, 0xbeb93642, 0x3f007843, 0x3ec99aaa, 0xbe9ac9ca, 0xbec114da, 0xbda9bb8b, 
    0x3deff842, 0x3d464949, 0x3e943cb3, 0x3e88d00b, 0xbdd4b98d, 0x3ea92651, 0x3edfd0aa, 0x3d0e41ef, 
    0x3e7e9617, 0xbeb4b27f, 0x3ec0ce91, 0xbe81b8ad, 0xbe71eff2, 0xbebb47d1, 0xbca834c1, 0xbea0dd0b, 
    0xbe1a6572, 0x3e5dd7a0, 0xbe74cc28, 0x3e41d477, 0x3e906535, 0xbe0c39cf, 0xbcf39dcb, 0xbed95489, 
    0x3f01940b, 0xbe688022, 0xbf0128b7, 0xbea7828c, 0x3ecd7b96, 0xbd230381, 0xbda7b174, 0xbee897f6, 
    0xbf0cedbe, 0xbf1a02a2, 0x3d9ab39e, 0x3e9d415b, 0x3e295c74, 0x3e9ad527, 0xbe8ca3c0, 0xbe8c5b43, 
    0x3ee1f7be, 0xbdf6eb97, 0x3f27c78f, 0x3ebc357a, 0x3f2163c6, 0x3f2b20fc, 0xbee21c2b, 0xbe4d8d51, 
    0x3e705a62, 0x3e815fab, 0xbe04619e, 0x3d034087, 0xbd296aba, 0xbd8abde9, 0x3eb46068, 0x3ec21813, 
    0xbeb1ee96, 0xbef9e6c0, 0x3ef0b0b5, 0xbd8d0141, 0xbf1bb0c4, 0x3e804d74, 0xbed2877c, 0x3d318c53, 
    0xbe398b79, 0x3f1dc718, 0x3ebd02ec, 0x3f1aa651, 0x3e9ec401, 0x3e3ac660, 0xbe39abfd, 0xbee32bb3, 
    0x3e62bbb2, 0x3f01149a, 0xbf0f8e99, 0x3f1e5123, 0xbdd74aa9, 0x3eebc3b8, 0x3f0bbdfd, 0x3f0e57ec, 
    0xbeb0b70d, 0x3ed4b588, 0x3ec274a8, 0xbe2794fe, 0x3ecd0b61, 0x3e9e6efa, 0x3f3509c8, 0xbea9ac8c, 
    0x3eed854b, 0x3f0c5b88, 0x3eea09f7, 0x3db30155, 0x3f0a33c4, 0xbf00a3f2, 0xbe109799, 0x3ee9e45d, 
    0x3e9fba96, 0xbf12d538, 0xbd84023d, 0xbdef5e4a, 0xbf3081ee, 0xbee992a5, 0x3f51a110, 0xbef091c2, 
    0x3e7eca4c, 0xbee5cbd3, 0xbee95af8, 0xbcaa55dc, 0xbe190eba, 0x3e8fac3b, 0xbe9bf6db, 0x3eb5c721, 
    0xbebcd891, 0x3f215016, 0x3ec942d4, 0xbe9c3256, 0xbe57aad0, 0xbe396c6e, 0xbee3aff8, 0x3d2a53e8, 
    0x3e9c7f26, 0x3ee0477b, 0xbe85412d, 0xbea40911, 0xbe5e693c, 0xbea72325, 0xbdd4a161, 0x3d819a04, 
    0xbea14aa5, 0xbdd839d1, 0xbe2e5555, 0x3eb29de0, 0x3e96e740, 0x3e90658b, 0x3e41b9e9, 0x3dea700e, 
    0x3ef11933, 0x3e01a41e, 0xbe5c1cdc, 0x3dd701da, 0xbec137de, 0xbe715187, 0xbec3dec9, 0x3eac42cc, 
    0x3db772f6, 0x3b84d1ca, 0xbe8f50cd, 0xbee37765, 0x3edbde39, 0xbea39822, 0xbf0b6dac, 0xbebcd4d3, 
    0xbd1589b3, 0x3eaa3379, 0xbe0e5156, 0xbde9782f, 0xbe826039, 0xbdf9eafc, 0xbed1d192, 0x3dd6f18b, 
    0xbddfad6d, 0x3da1304b, 0x3eed462f, 0xbf0a1bb5, 0x3eb7df96, 0xbe71b799, 0xbd2aeab3, 0x3c3ae91b, 
    0x3ed6e9ae, 0x3ec8ab6b, 0xbd39874e, 0x3ea274fb, 0xbef75315, 0xbeb894d2, 0x3ebf6ff1, 0x3ea3ee47, 
    0x3edf7b9b, 0x3ea9e9df, 0xbe285f40, 0x3e617b00, 0x3cfc2a04, 0x3e3e6d42, 0xbe626446, 0x3ec66107, 
    0xbeca5044, 0x3e0ee06d, 0x3e2bc37e, 0x3e4b9708, 0x3e87df4d, 0x3eef634b, 0xbcb6424b, 0xbdb77f7a, 
    0x3d90c4d7, 0x3e63f67e, 0x3e8dc419, 0xbed2d71c, 0x3e80f8ef, 0x3e3e37d8, 0x3eb2734a, 0x3df0b99a, 
    0x3eed0313, 0x3e207bc2, 0xbe9d63f3, 0xbeb55159, 0x3e4e5f73, 0x3ea9f3f3, 0x3f05ab35, 0x3d476e73, 
    0x3ec887a8, 0x3e7ef77d, 0xbee95dc0, 0xbeea86fe, 0x3e3531fe, 0xbebc1859, 0x3ed52906, 0xbf4be740, 
    0xbe71810f, 0x3ef80ba3, 0xba14166e, 0xbe10ace1, 0xbdddd55e, 0x3d3aa3cf, 0xbc46b94d, 0x3eb2dd65, 
    0xbea1695f, 0xbde40a20, 0x3e78618c, 0xbe767b5b, 0xbe9732dd, 0x3e30e9f4, 0xbf124acb, 0x3f2887fc, 
    0x3ee71e16, 0xbf1e2d78, 0xbdaea99f, 0xbeae5ebe, 0x3edb8634, 0x3eac8dee, 0x3e70d77d, 0xbe8bf548, 
    0x3ed09694, 0xbe4a760c, 0x3efb3991, 0x3e2f8dc4, 0xbf0cd2f9, 0xbddae2d4, 0x3f0a4bc8, 0xbdc17db6, 
    0xbed4a4ef, 0xbd19ac04, 0x3dc9cd09, 0xbe54c38e, 0x3e1acf06, 0x3f1b3501, 0x3d862f6d, 0x3e2ade3f, 
    0x3ebdbca4, 0xbe590510, 0xbe20a04d, 0x3ed27b25, 0xbe8b6aa7, 0xbf1567b6, 0xbc8a723f, 0xbda64660, 
    0xbb3f813e, 0xbe18f292, 0xbcff2ec3, 0x3e889fb5, 0x3eb06554, 0xbeb7b2b6, 0x3d070584, 0x3eaa2ec3, 
    0xbf04a4de, 0x3e8416fd, 0xbf2399ce, 0x3e456bf5, 0xbe455c71, 0x3f16f698, 0xbeb07125, 0x3e057312, 
    0xbdae004e, 0x3ca86df7, 0xbe3c61f9, 0xbf30c932, 0xbf08f95d, 0xbe8b277d, 0x3f03bc94, 0x3f3d9c86, 
    0xbdeee995, 0xbe0be64c, 0xbed6f0f5, 0xbe8cf78e, 0xbd249040, 0xbeb3c7e7, 0x3d026669, 0xbef49ba8, 
    0x3bbf6589, 0xbef3a9f5, 0xbee7a2a5, 0x3ec48c1a, 0xbd90eb51, 0xbee65981, 0x3ca53030, 0x3debb5dd, 
    0xbdeb322e, 0x3f379e1d, 0xbe5bb941, 0x3df814b7, 0x3f4756db, 0x3c487638, 0xbe4766ea, 0xbe97d797, 
    0x3c8d86c7, 0xbdb902ef, 0xbf50bbe8, 0x3e2beb8f, 0x3e9684ed, 0xbe791115, 0xbd1357dd, 0x3d933f74, 
    0xbe40d062, 0x3df77fc7, 0xbde7e89d, 0x3eff43ea, 0xbd62498b, 0xbd8cad43, 0xbd117883, 0x3e4ce2ce, 
    0x3e6ff2b0, 0x3e3c964c, 0x3f0a2dbb, 0x3d6e4e4c, 0x3ea8c75a, 0xbf11a6d9, 0x3e980b91, 0xbeed12a7, 
    0x3dd6e642, 0x3f028212, 0x3c9c1fd8, 0x3e1e9dcd, 0x3f0100e6, 0xbeec83db, 0x3e5f7e79, 0x3ee63c03, 
    0xbe8316b9, 0xbf090906, 0x3db053f1, 0x3d83d1ea, 0x3e4235a1, 0xbaae0a5c, 0x3e132292, 0x3ef9bcdc, 
    0xbe259b85, 0x3e9eb2a5, 0xbe1c1f2c, 0xbe0e6824, 0x3dd50b7f, 0x3e971ec4, 0xbf071454, 0xbd6d84f8, 
    0xbe8f11d0, 0x3e94913f, 0x3eb68f06, 0x3eac23b4, 0x3e6c69ab, 0xbe994924, 0xbefca455, 0xbf0f1b93, 
    0x3e5accca, 0x3e36a833, 0x3e644e43, 0xbdfe76ba, 0x3f27df7c, 0xbe5e9962, 0x3ed8bbd0, 0xbe82b527, 
    0x3ee73b34, 0x3ea48be4, 0x3ea6ddcb, 0xbe94e8c0, 0x3f19d170, 0x3ddc25ce, 0x3ee3457f, 0xbe15dce5, 
    0x3e1838d9, 0x3eb5c4d5, 0x3e855faf, 0xbf4a5f70, 0x3e6f3277, 0xbed3bff5, 0x3f1f98b1, 0x3ec28fbb, 
    0x3adf622f, 0xbddfb27e, 0x3f0cc5af, 0xbf031b04, 0xbf05f814, 0xbeda9def, 0xbeee2cd3, 0xbe1b7be1, 
    0xbe474204, 0xbebfc639, 0xbea6ba4d, 0x3e3c7215, 0x3df677fa, 0x3e1981fc, 0xbd912212, 0xbe63ecac, 
    0xbe296a7c, 0x3e32162d, 0xbe9df4d8, 0xbcbdd9bb, 0xbe3d68e5, 0xbd97a0e8, 0xbda8dba7, 0xbd01557b, 
    0x3dca5391, 0xbdde4dc3, 0xbe846473, 0x3e7a31ce, 0xbe6ba9d8, 0xbd9d33a0, 0x3dc5fae8, 0xbdceddfe, 
    0xbeaf842d, 0xbef2f674, 0x3ddf3b99, 0x3eb2aab0, 0x3ce15cce, 0x3e55f56e, 0xbebb867b, 0x3eec4ee8, 
    0xbdac2b3d, 0x3d3b7106, 0xbea09301, 0xbe236c89, 0xbe251e15, 0xbddc85b2, 0x3e97feaa, 0x3e85b8c2, 
    0x3df6d753, 0xbe6c9e24, 0x3dc0fe0f, 0x3f0420b5, 0x3eb6487b, 0xbda00aaa, 0x3e91cbb9, 0xbdea1c00, 
    0xbeb1c864, 0xbeb1889d, 0xbe11bee5, 0x3da97c05, 0xbe72f720, 0x3e590ddc, 0xbf21416b, 0x3ee683bb, 
    0xbbbaa4ea, 0xbe8fbff1, 0xbe51cdf5, 0x3e78450d, 0xbeb7b346, 0x3df5dd43, 0x3e65cb7b, 0x3e3f4fd9, 
    0x3cfaeee9, 0xbdb7a072, 0xbe0d4f37, 0xbe105cd4, 0xbb9ab030, 0xbd8e75fe, 0xbecbcaf4, 0xbe751e3e, 
    0x3eb5dcfa, 0xbed6b091, 0xbe886a0d, 0xbed21fb9, 0xbead5351, 0xbf080662, 0xbe910598, 0x3f118edc, 
    0xbe4c4fa8, 0x3d725560, 0x3db479ca, 0xbe1ce3e5, 0x3d939803, 0xbeadacc9, 0xbe87b2e2, 0x3e60ee7f, 
    0x3e1c08be, 0xbe4af26c, 0x3eaa0d8e, 0xbeb89fc8, 0x3e1cb7ca, 0x3ebf475c, 0xbc3c8e15, 0x3edc8d52, 
    0x3e8d0cb6, 0xbc4ca774, 0x3e225a38, 0x3dee12d8, 0xbeaff9b7, 0x3ecf9445, 0x3d769527, 0xbe4196a4, 
    0x3ef9593e, 0xbed36d0c, 0xbe0b23f3, 0xbee65d61, 0x3dbd79e8, 0x3e8f3b2a, 0x3ebaf685, 0x3ea43bae, 
    0x3f03783d, 0xbe9506c7, 0xbe4c95f6, 0xbea855ef, 0xbf13324f, 0x3e85d38e, 0x3e509413, 0xbd248509, 
    0xbc8c56c8, 0x3e72da84, 0x3e41052e, 0xbe1176dd, 0xbd544384, 0xbec7ab34, 0xbe8f9cfd, 0x3f0061b2, 
    0x3db64273, 0xbe8a5705, 0x3f02972c, 0xbe9c22bf, 0x3c481a4f, 0xbdc52641, 0x3e7dd078, 0x3ef9e152, 
    0xbe90277e, 0xbe699756, 0x3d607e63, 0x3f14f194, 0xbecb555c, 0x3d8ab204, 0x3e322551, 0xbe96dd83, 
    0x3cba12a4, 0x3e4f0098, 0x3f18d880, 0xbeb9088e, 0x3df296be, 0xbe02b3fc, 0xbebf0306, 0xbd2bd526, 
    0x3d7eebed, 0x3d18a15f, 0xbeff66e2, 0x3d3ed15d, 0xbdad5e91, 0x3df5676e, 0xbc97e0cb, 0x3ea1284c, 
    0xbe9046a2, 0x3e30121d, 0x3e4d3056, 0xbdcbc8dd, 0xbd7d17c6, 0x3eed1331, 0x3ddfa507, 0x3e87f2f8, 
    0xbd22dbe0, 0xbf1a1845, 0x3e750c71, 0x3e1604ac, 0xbe8692e1, 0xbefc1c15, 0xbe4ace46, 0xbea17a92, 
    0xbe107d09, 0x3e9241f6, 0x3ed93373, 0xbe6fdad5, 0xbf09d6f7, 0xbf107bd4, 0x3de245fe, 0x3d925651, 
    0x3d909dbb, 0x3d0b2c52, 0xbee8438e, 0x3dba0258, 0xbe44c6f9, 0xbe10206e, 0xbecdcd67, 0xbe84dad0, 
    0x3c984477, 0x3f07309f, 0x3cbcc9f0, 0x3e0e10b1, 0xbd0a26fa, 0xbd36f403, 0x3ec8fcda, 0x3e00996a, 
    0x3ee08e43, 0x3e33aa09, 0x3e819ffb, 0x3e376c07, 0x3e2da050, 0xbd245106, 0x3ded4b3d, 0x3ea83cba, 
    0xbee6eb77, 0x3f132a08, 0x3c17a8be, 0xbb885276, 0x3c9c33c2, 0x3de158cf, 0x3e071163, 0xbe3c9c05, 
    0x3ec1ecec, 0xbec3fa5a, 0x3e8bc484, 0xbe234ed5, 0xbe3056cf, 0x3c7c3ffa, 0x3dd688cf, 0xbe0aa477, 
    0x3d105703, 0x3ed29a22, 0xbdefbfc2, 0x3ec25a1c, 0x3d17ddb9, 0x3e5330f5, 0xbd5a7f36, 0xbeff2848, 
    0xbf2cedcb, 0x3e160498, 0xbea4ef83, 0xbe89cfde, 0x3ec6cdb4, 0x3f1b3606, 0x3e60d83a, 0xbeee024e, 
    0xbdcad7c7, 0xbef470e0, 0xbe6e860c, 0xbe738dc3, 0xbdc862f2, 0xbe447db6, 0x3ead2005, 0xbe9d2297, 
    0x3f0fc3ec, 0x3f1e18bf, 0x3d58dc2b, 0x3e806559, 0x3eb26562, 0xbef1bb21, 0xbec2ec79, 0xbd2a9105, 
    0x3e018691, 0x3e693c61, 0x3eebcca4, 0xbc206ea8, 0x3e67bf28, 0x3ef255d6, 0xbf198b07, 0x3e98a437, 
    0x3e4698dc, 0xbf07067f, 0xbc2b5bf2, 0x3f0b768e, 0xbea85a15, 0xbe5c4145, 0xbe98bf21, 0xbda2d8a4, 
    0xbf1245a9, 0x3f4506d7, 0x3db8c68b, 0xbeaeac3f, 0x3edaf59f, 0x3ea2f058, 0xbc52b7ac, 0x3ed1fa9b, 
    0x3f28bb7d, 0xbe7145d5, 0xbf2cc533, 0xbf23a325, 0x3e21acc0, 0x3b65c089, 0xbf2941dc, 0x3df29353, 
    0x3ef19e10, 0x3ed8135f, 0x3eaa11eb, 0x3d8fc170, 0x3ecbc617, 0xbdf4a6aa, 0xbf136ff9, 0xbeca5df7, 
    0x3e7164fc, 0x3e016c88, 0xbf135c82, 0xbedc0223, 0x3ebba803, 0xbe04b70f, 0xbe4c6bbd, 0x3d9719b8, 
    0x3e307dc7, 0xbbfaaa3b, 0xbed9a8be, 0xbf2373f3, 0x3e973480, 0xbf0e13b2, 0x3f03085b, 0x3dd104b6, 
    0x3de6fd19, 0x3efbc188, 0xbde85ea9, 0xbeb4021d, 0xbe6862fe, 0xbdb94f4d, 0xbe8ea13e, 0xbdcfd2fb, 
    0xbec006e7, 0x3e0cac4b, 0x3f09a90d, 0x3eb476a7, 0x3d74d101, 0xbd5a8977, 0x3e9ce709, 0xbdda4a97, 
    0x3e466732, 0xbe292c81, 0x3ed105a2, 0xbeb3c674, 0xbed793c6, 0xbed74d05, 0x3e1f5b2b, 0x3e882be1, 
    0x3e10bddb, 0x3edbe4e2, 0xbe831816, 0xbf2f7ff3, 0xbede20ff, 0xbda42b62, 0x3e643b27, 0xbdd4854b, 
    0xbe56cc4f, 0x3eac9876, 0xbe999fbe, 0xbe92210d, 0xb9f37a20, 0x3e9ad027, 0xbe038ea1, 0xbf032842, 
    0x3e45fb50, 0x3dd36807, 0x3efa28ce, 0x3c1949ae, 0x3e8de089, 0x3caa6ba5, 0xbee3ea61, 0x3d068772, 
    0xbe445eb9, 0xbe0a232b, 0xbe7107a8, 0x3ec23f78, 0xbe9f283a, 0x3f183f27, 0x3e40f162, 0x3e52c444, 
    0x3ec9d2f3, 0xbdeb9be9, 0xbeb6024e, 0xbb217ac8, 0x3d851087, 0xbd7d41ef, 0x3eb71412, 0x3e095c49, 
    0x3f0a8e36, 0x3d49d0cc, 0x3d67be51, 0xbe3e0920, 0xbef5572d, 0x3da8fbb4, 0x3ef13c0e, 0xbe2d7b7b, 
    0xbea5180f, 0xbe50ec06, 0x3d27d252, 0xbe5fd9ab, 0x3e238f08, 0xbe9e8f99, 0xbeae072f, 0xbdebd9f9, 
    0xbe9c3cea, 0xbda15e46, 0x3ee892f3, 0xbe9e49cd, 0x3ecd42c9, 0x3e159ece, 0xbd266311, 0xbe254866, 
    0x3dabfe14, 0x39ef77d8, 0xbf034f37, 0xbf1e7153, 0x3e0dfae9, 0xbe5a1516, 0xbd584233, 0x3f05ba48, 
    0x3f137617, 0xbdda490e, 0x3e69b0bd, 0xbe596fb7, 0x3e422787, 0x3e75227a, 0x3f0c9d0a, 0xbe378b06, 
    0xbe95ac9a, 0xbd48aef9, 0x3d62eed5, 0xbe1a47ff, 0xbccd5e91, 0xbc648e2e, 0xbedf09ef, 0xbea02e46, 
    0x3eb54cd4, 0x3db2078a, 0x3e8e9bc7, 0xbe8cc9b5, 0xbe08dd8a, 0xbf232fd4, 0xbd49a3f3, 0x3b42ed1f, 
    0x3dc2150e, 0x3ee1cad2, 0xbe4f16e7, 0xbdf62503, 0xbddc40bd, 0xbe63092c, 0x3d4cea43, 0xbf02d24b, 
    0xbe7ff26b, 0xbe51404d, 0xbcc88e13, 0x3d4b823e, 0xbec54c85, 0xbe3ff0a9, 0xbed21641, 0xbd635caa, 
    0x3e447586, 0x3ead14e4, 0xbe79bdb1, 0x3e383bee, 0x3ca20204, 0xbed66b0c, 0xbeaf9705, 0x3e4d6fae, 
    0xbf350ffb, 0xbcc77f74, 0xbc848e60, 0xbee2d850, 0xbe6a92d7, 0x3e55e70c, 0xbec49bf6, 0xbea3795c, 
    0xbed4e9a6, 0x3e88f3a5, 0x3e14153f, 0xbeb14337, 0xbe83ae35, 0x3efc65c0, 0x3eb3247b, 0x3e1ca3bc, 
    0x3ebb7fd5, 0x3d85c0f4, 0x3f08ca1f, 0xbee9e893, 0xbd836178, 0x3e845ce4, 0xbea6f8d0, 0x3e2e1c02, 
    0x3ebf4b3a, 0x3e420add, 0xbe0e9fe6, 0xbeed420a, 0xbf0d7a54, 0x3eda9c80, 0x3ead9685, 0xbedb18ef, 
    0x3e30cfa2, 0x3e22f015, 0xbd93e87a, 0xbea229a2, 0xbf01fd86, 0x3f032cad, 0x3d92c6eb, 0x3e286681, 
    0xbd7bed5e, 0xbebf4403, 0xbe2d7cbb, 0xbf15a8e6, 0xbec434c9, 0xbeafc474, 0x3da0158b, 0x3f2c54bb, 
    0x3e815f5a, 0xbf0b92f6, 0xbe9aa8ae, 0x3d05f25a, 0xbd696f0d, 0x3e275adb, 0xbe8f7934, 0x3e375fb3, 
    0x3e2aac86, 0xbedafe60, 0x3e69a86c, 0xbe87d2a6, 0xbf289efe, 0x3c9bc0ee, 0x3eb8aae6, 0xbf0dc333, 
    0xbd4e663a, 0xbe684523, 0x3e56524e, 0xbe988036, 0x3f00398c, 0x3e0bf19d, 0x3e8fdfeb, 0x3f072147, 
    0xbe9d8a1c, 0xbdd9c0d2, 0x3e9ff509, 0xbd542916, 0x3f1a1743, 0xbebfd245, 0x3e59e5be, 0x3e7ecfbb, 
    0xbd197aec, 0x3d0eb333, 0x3e9ee41d, 0xbea6f0c9, 0x3ecf246f, 0xbed7bfee, 0xbd3f12ef, 0x3b9845a5, 
    0xbe279a9d, 0xbeb46a17, 0x3e468aa6, 0xbf1053df, 0x3dea9180, 0xbc334587, 0x3d6fa5da, 0xbea3fac2, 
    0xbd0650ca, 0x3dc7cb0b, 0x3e6e0327, 0xbe03fe36, 0xbeedbf70, 0xbf069d1c, 0xbecc5152, 0xbe96e1a7, 
    0x3dab3f10, 0x3ecd2592, 0x3dfc988f, 0x3ec8de1f, 0x3ecd4208, 0xbee5c8fb, 0xbedc95cc, 0x3e1fed4a, 
    0xbe6ac0df, 0x3ed0a9d7, 0x3ef6ce26, 0xbebe8cf7, 0x3ef22327, 0xbf1aafee, 0x3d890b88, 0xbe9ec9ae, 
    0x3f1aff9f, 0x3e233b1b, 0xbdcdb0fd, 0x3ea9016c, 0x3ee47edb, 0xbe0c341a, 0xbd988410, 0xbc55ffe1, 
    0x3e9fad56, 0x3e8b1e84, 0xbf370dad, 0xbdcd48be, 0x3dc83e92, 0xbe216d79, 0x3f1cf7a4, 0xbe10018b, 
    0xbe92c3d5, 0x3db6b8b1, 0xbf0b11d1, 0xbf160d59, 0xbece1282, 0xbe999a89, 0xbbc021e5, 0x3ebc2669, 
    0x3f04e2bb, 0x3dc237b9, 0xbdcaedcf, 0xbe69310e, 0xbd8c11c9, 0x3e1e2009, 0xbece11c2, 0xbeb87f75, 
    0xbc3a5709, 0xbca42508, 0xbea9cb71, 0x3d8627e8, 0xbe5bb7f6, 0xbeed963d, 0xbe9f7f73, 0xbe620203, 
    0xbef6431d, 0x3f09f850, 0xbe56de1a, 0xbdcf7110, 0x3ed744d7, 0x3d823b52, 0x3e79c501, 0x3eeec488, 
    0xbd86bf5b, 0x3e6815ca, 0x3e83e306, 0x3e961399, 0x3ed403ca, 0x3d836417, 0x3eb4888f, 0x3e6cf78a, 
    0x3da481dc, 0xbd624b99, 0x3edd1908, 0xbe31b095, 0xbe211baa, 0xbedadf91, 0xbef30367, 0xbe27ea44, 
    0x3d41ca4f, 0x3eadcd90, 0x3eae19e2, 0x3da9f84e, 0x3eebf907, 0x3ecbf840, 0xbf048d55, 0x3e3bfdec, 
    0x3d897889, 0x3eec0f60, 0x3e644856, 0x3d482eb4, 0x3eb36607, 0x3d8f207e, 0x3e0beae7, 0xbea04d4c, 
    0x3e2c8999, 0x3f06542d, 0x3e2793ff, 0xbece500c, 0x3e040c6d, 0x3eb2144d, 0xbe75778a, 0x3d11da9e, 
    0x3ca78fb7, 0xbea4cfbf, 0xbef97483, 0x3db8bcf1, 0xbef5c647, 0xbdcaeaaa, 0x3e699935, 0x3d71d008, 
    0xbe648194, 0xbf06870d, 0xbf0a0d38, 0x3d172820, 0x3e4cd30d, 0xbdc869d5, 0x3f378940, 0xbec47ce2, 
    0x3d95a01a, 0x3e8738f1, 0x3e981d06, 0x3ce69453, 0xbf34a685, 0x3e19588b, 0xbc90abbb, 0x3e4755f7, 
    0x3dbabb35, 0xbd88c611, 0x3ebf7caf, 0x3e1d5f56, 0x3ed2a88b, 0xbda571fe, 0x3ec75a22, 0xbe1b3ee6, 
    0x3f0cd414, 0x3e9e161f, 0x3eacbd59, 0xbe06f217, 0xbeeb2929, 0x3f0ecdf1, 0xbe7ec229, 0x3f0e2bf0, 
    0x3ee2649c, 0xbd51e379, 0x3e5a7d9c, 0x3e76450f, 0xbcd60d20, 0xbdfda9b3, 0x3d5c3bd1, 0x3c1cbce0, 
    0xbe29b6e6, 0xbe8d8454, 0x3f0f281c, 0x3f1d8c3b, 0x3e285a3e, 0xbe151e2f, 0xbd630909, 0x3f4e2c4e, 
    0x3e6688fa, 0xbeef0ea0, 0xbd384b51, 0xbe94e243, 0xbdd877d8, 0x3ee7d23c, 0xbf184490, 0x3f408fad, 
    0x3e8efd13, 0xbef37609, 0xbe02cedd, 0x3e2e733c, 0x3f291272, 0xbef5abcb, 0x3d83317e, 0xbda12b8a, 
    0xbf1324d4, 0xbf334e53, 0x3ed67090, 0xbe8fd56f, 0x3e8d7594, 0x3c43d716, 0x3e27dbb4, 0xbf286697, 
    0x3f255f47, 0xbe61cfbf, 0xbe0678f8, 0xbe4988f6, 0x3e433714, 0xbe528523, 0xbdeaf788, 0x3f61afe8, 
    0x3f0d85d3, 0x3e227af4, 0xbefa7be8, 0x3f205fd2, 0xbedcce34, 0x3d45ce62, 0xbed0c61a, 0x3e075f52, 
    0xbe733759, 0xbf030a9e, 0x3e405e59, 0x3e1b802c, 0x3f05c07f, 0xbf0e4eda, 0xbe648348, 0x3e6b6558, 
    0x3e7a1b2c, 0x3c81c290, 0xbde14c12, 0xbf0df8c8, 0x3e619419, 0xbbc1ad96, 0x3e4bb4d1, 0x3e91f74f, 
    0x3e9b5dc1, 0xbf0de026, 0xbf0c0766, 0xbdf57606, 0xbe7ae5b8, 0x3dce9f5b, 0x3ece885e, 0xbe01a189, 
    0x3e047877, 0x3eeaebda, 0xbe7c0e36, 0x3ec793ba, 0x3ea7a04e, 0xbd98e7ff, 0x3e496805, 0xbce4e01c, 
    0x3e0ef260, 0xbe09584d, 0xbd8a03b6, 0x3e071e9f, 0x3e5f7cb6, 0xbe6856b4, 0xbec87406, 0xbea18f9f, 
    0xbf043180, 0xbf0fa7e1, 0xbec513e8, 0xbe9cc474, 0x3f12d8fc, 0x3e73a00f, 0x3e432c66, 0x3ea441de, 
    0xbe638520, 0xbe71e464, 0x3e962cca, 0xbe8f75d1, 0x3e5c64a3, 0xbdde1a11, 0x3f10934c, 0xbf007673, 
    0x3efaf816, 0x3de93198, 0x3e837dd6, 0xbe8f00e7, 0x3c2d9f4a, 0x3c1e5015, 0xbefaa0a5, 0x3ecfafb8, 
    0xbec34c4d, 0x3c4ab3c5, 0xbe268593, 0x3d17cd85, 0xbecd9227, 0x3ebfb494, 0x3e968ba0, 0x3e987ed1, 
    0xbca63b07, 0xbe43287f, 0x3e8efd6c, 0xbe66380d, 0x3efc678f, 0x3e66ed52, 0x3edc6bf4, 0x3ed513e0, 
    0xbec7fd1f, 0x3ead2363, 0xbebc2d08, 0x3e8bbe2d, 0xbd80f4b3, 0x3d96b95a, 0x3d18d166, 0xbf19501d, 
    0x3d91b9b9, 0x3ed7656f, 0xbeda17bc, 0x3cdf48c3, 0xbe548ea2, 0xbe3cb7e8, 0x3e2743b6, 0x3e97f9da, 
    0xbf1303fb, 0xbe1ff9e0, 0x3e6369d3, 0x3ee8a5e6, 0x3ece53d9, 0x3ede0188, 0x3e1425cb, 0xbe7aeb95, 
    0xbe65797b, 0x3f092e46, 0xbee92616, 0xbccfa81d, 0x3e1b757a, 0xbeeda0e6, 0x3ca58284, 0xbe968bda, 
    0x3e59df33, 0x3e652b89, 0x3e99f5b2, 0x3dba80ae, 0x3ec42360, 0x3eaad6d3, 0x3ebca5da, 0xbdd3ee1c, 
    0x3e7ec803, 0x3e9a3894, 0xbf1591ff, 0xbf082b39, 0xbd23a1f4, 0xbe98352d, 0x3d1eb2da, 0xbef88688, 
    0x3dbfbced, 0xbed7f712, 0xbe451acd, 0xbea640eb, 0xbf16f023, 0xbb347557, 0x3ed6fc78, 0xbd2bcb15, 
    0xbeafddfa, 0x3f05e1eb, 0x3e982070, 0xbe0cefb6, 0x3f1a9ced, 0xbcd5bcfa, 0x3cf3b0d5, 0x3d9ea496, 
    0x3e4cc350, 0xbe6bb98a, 0xbdb9fd26, 0xbe2e9d58, 0x3ebaec28, 0x3eae3c8d, 0xbe51bc1b, 0x3e11d28b, 
    0xbec14ab3, 0x3e55f936, 0x3e42d31c, 0xbe256369, 0x3d8eece6, 0x3ebbca18, 0xbe8bbe5f, 0xbe303815, 
    0xbeea55c4, 0x3eaea3f8, 0x3ecc4097, 0x3e4fe0b7, 0xbebe184d, 0xbf0abd54, 0xbef5fe65, 0xbf10bd62, 
    0x3deb813f, 0x3f1de075, 0x3eac5219, 0x3ee61a3a, 0xbede9c74, 0xbed96b10, 0x3ef6e521, 0xbe65d925, 
    0xbe36aeec, 0x3c283249, 0xbf55395d, 0x3d920bfd, 0x3f0ae718, 0xbd917ae9, 0x3e971393, 0xbc86790b, 
    0x3e8b1006, 0xbe931eaf, 0xbf0fb0ef, 0x3eeb7e20, 0xbf116fc2, 0x3e18153d, 0xbe0c7ba4, 0xbd7ba3b7, 
    0x3e81471e, 0x3e320183, 0xbe214a51, 0x3e0b0132, 0xbec403ac, 0x3eb1fdb6, 0x3f054157, 0xbdc1a96f, 
    0x3d95ffaa, 0x3ef79ce7, 0x3e89c681, 0x3ec0581c, 0xbe06077e, 0x3dc3c92f, 0x3ea11bd8, 0x3e1891b9, 
    0xbd984581, 0x3e9b1347, 0xbeb3c5c9, 0xbd93fe4a, 0xbdc9a5a0, 0xbdb86288, 0x3e27ceac, 0x3d995749, 
    0x3e4b2e25, 0x3ddcdacf, 0xbe99e2aa, 0x3ebbd875, 0xbe21e1a6, 0xbd7f14a9, 0x3e81b66a, 0x3dd4ea0a, 
    0x3ea4d697, 0x3cb24c17, 0x3ebc7f7f, 0x3e7c0c4d, 0x3eca851d, 0xbe44804e, 0xbe32acf7, 0xbe994dd1, 
    0x3e0cceea, 0x3eb4cd30, 0xbe9415e0, 0x3ef83bf8, 0x3e8af08e, 0x3e6f40fe, 0x3d75bdab, 0x3e9efd95, 
    0xbe9d4cf2, 0x3d211deb, 0x3da9eb9e, 0xbe915d13, 0xbe44af5f, 0x3c769755, 0xbc8d6f73, 0x3e866218, 
    0xbecc7709, 0xbcae1299, 0x3e7c7bbb, 0xbe3ab205, 0x3e0577e8, 0x3e7f32fa, 0x3de6fc2d, 0xbe2c9399, 
    0x3eae03e8, 0x3caa74da, 0xbea456e7, 0x3e34abd9, 0xbe16cd44, 0x3e98f29c, 0xbe6b2eb5, 0xbe7354ce, 
    0xbba48fb3, 0x3e2b1d23, 0x3dbbed86, 0x3ecbd48f, 0x3eaefdc7, 0x3e6985f9, 0x3e6aacf2, 0x3d9c0aaa, 
    0x3e0e36c3, 0xbe36ff6a, 0x3e9689bd, 0x3e89a62d, 0x3e6df7e4, 0x3dccdfd7, 0x3ead425a, 0x3dad054a, 
    0x3d932797, 0x3ea87709, 0x3e73c797, 0xbe569d61, 0xbea7ad57, 0xbda542e0, 0x3b3de11e, 0xbe804563, 
    0xbe0a9447, 0xbe083ff7, 0x3e77ca09, 0xbecb242a, 0x3ed14c96, 0x3de5da8e, 0xbeb9e5fb, 0x3f1b02f3, 
    0xbec13702, 0x3e1e6b1d, 0x3e08a92c, 0x3e9e1295, 0xbe6295c3, 0xbdfe0c77, 0xbedd1ae0, 0x3edebd9a, 
    0x3d98e621, 0xbf02d5a2, 0x3f1cd345, 0xbe48c0c3, 0x3e52c130, 0x3f46a643, 0x3e42a9cd, 0x3f685117, 
    0xbebf314d, 0xbf0c3ec3, 0x3ed472cd, 0x3f084779, 0x3e03190e, 0x3edfde43, 0xbe31f2fd, 0xbed300fc, 
    0xbec9dc87, 0xbe4ae480, 0x3edaf583, 0x3efdb8f8, 0x3d385c9f, 0xbeac88db, 0xbee23d72, 0xbd8703cd, 
    0x3de0c313, 0x3e1e325f, 0xbd2fa9c8, 0xbe33b3d9, 0x3e583f2a, 0x3e8c32c4, 0x3ec6207f, 0x3f170720, 
    0x3e03b36e, 0xbe06be36, 0xbe790f06, 0xbe58f13e, 0xbf38e977, 0x3e383d97, 0x3ed64f99, 0x3e273fde, 
    0x3e9a5fb3, 0xbe4cff55, 0x3ebdf289, 0x3d75b018, 0xbe614e7f, 0xbf29a722, 0xbe9990d8, 0xbe7f61ab, 
    0x3e6ff18d, 0x3eb796ed, 0xbf32c654, 0xbc8179e8, 0xbe9b6b59, 0xbeb8f01f, 0x3eba5f25, 0x3ea1934c, 
    0x3de386a2, 0x3ee6f34c, 0xbf0ee1ca, 0x3e5b1a3c, 0x3ebb8ee3, 0x3e02729f, 0xbec713f3, 0xbe173008, 
    0x3f2f6fe9, 0xbf249cd6, 0xbd97af4a, 0xbeba128f, 0x3ef5be1e, 0x3dbe4cd0, 0x3e60055f, 0xbe7f3bea, 
    0x3f1d5875, 0xbeb0b424, 0x3f0136cf, 0xbe6cf7c8, 0xbdb4411f, 0x3d213cae, 0x3e2ccd40, 0x3e1e8276, 
    0x3df726f7, 0xbef1b95e, 0x3ef0374f, 0xbedbbbbc, 0x3ed4dd00, 0xbc77bec8, 0xbea86f2e, 0xbef46f09, 
    0x3d4254da, 0x3ef71b6c, 0x3f1da363, 0x3f2ad9cb, 0x3f0df869, 0xbeff72f4, 0x3ea594d5, 0x3c98363a, 
    0x3ec2091a, 0x3f0de7ee, 0xbea66be5, 0x3ead0481, 0x3bda5da1, 0xbf2cb7c7, 0x3d58551a, 0xbd6f1f99, 
    0xbf13942a, 0xbed3c342, 0x3cec8a83, 0xbed9c173, 0x3aea72c3, 0x3e413785, 0xbdd186de, 0x3f04c3fd, 
    0xbe83a104, 0xbe0681ba, 0xbe83984b, 0xbecec4a0, 0x3ef3ceee, 0x3e99a970, 0x3e3cc3fc, 0xbf0cff2c, 
    0x3ec002e6, 0x3f1f6e16, 0x3b009c3b, 0xbed5e60e, 0xbe84f04d, 0x3da60117, 0xbe80d8e0, 0xbec35933, 
    0xbf341c4a, 0x3f36d28c, 0xbeae07ad, 0x3ea89404, 0x3ec5d490, 0xbf0a9595, 0x3f079c48, 0xbe80d390, 
    0xbd84b5f6, 0xbeeb1760, 0x3eee15d8, 0xbf27a5f4, 0x3ebe255d, 0x3edcf4d6, 0xbf08d3b2, 0x3ddfc179, 
    0x3ef28513, 0xbe6befb1, 0x3e225cfd, 0xbf1b2d03, 0x3eab8758, 0xbd98e95d, 0x3e147734, 0x3f0b3f4e, 
    0x3e33f674, 0x3f282a29, 0x3e258019, 0x3e6549ee, 0x3e7a9e39, 0x3ef2c35b, 0x3e3dbf82, 0xbf366290, 
    0x3e533ebc, 0xbddcaa5a, 0x3e82db6d, 0x3ea0ad46, 0xbe5286fe, 0xbed5d5c9, 0xbeb20ada, 0xbe068c9d, 
    0xbe81dd45, 0xbd1fab12, 0xbe07e6fe, 0xbe1d6764, 0x3e640027, 0x3e2585ff, 0x3d176323, 0xbed33223, 
    0x3f30492a, 0xbcb1bf9f, 0xbefde5fc, 0xbeceb4b3, 0x3e8936ec, 0xbdef4b90, 0xbe38e909, 0xbe9e5841, 
    0xbed99ad8, 0xbeae61d6, 0x3e7b722d, 0x3e56f724, 0xbe9994cd, 0xbefa9ad6, 0xbe9759ad, 0xbe1413c9, 
    0x3e21dc64, 0xbe5becf9, 0x3d659de2, 0x3e5033be, 0x3cbe55bd, 0x3dc55545, 0x3e39a36d, 0xbda16d3e, 
    0xbee27c5f, 0x3eb59ff5, 0xbef89456, 0xbf061ca4, 0xbe599df1, 0xbcae4d61, 0xbd32a614, 0xbec4bec4, 
    0x3e95a50d, 0x3ecdfebd, 0x3eb137f7, 0xbeff4717, 0x3dd6387b, 0xbe904889, 0xbeda0048, 0xbf10ba91, 
    0xbe024f4a, 0x3eaf304c, 0x3d55d784, 0x3ebc6ee6, 0x3eaf298b, 0x3e6b57bd, 0x3d46178b, 0xbe5f000d, 
    0xbf11fd97, 0xbe97bbdb, 0xbe880b64, 0xbe95a817, 0x3df5ec70, 0xbea6d14b, 0x3eb044a1, 0xbe9bd118, 
    0x3ec1a865, 0xbdddb5a1, 0xbf0876ea, 0x3ed1a187, 0x3d12e338, 0x3e677b13, 0x3da43b05, 0x3e433b1c, 
    0xbda79a2a, 0xbd978f42, 0x3e3143c3, 0x3e54a907, 0xbf11ec42, 0x3e01cdd5, 0xbe252a92, 0xbe51d635, 
    0x3e587087, 0x3f171825, 0xbe93a670, 0x3ec215e2, 0xbe85fc90, 0xbf017dc6, 0x3ec51a52, 0xbe357392, 
    0x3d7c8c19, 0xbe9ccec5, 0xbe24f1ec, 0xbee8782f, 0xbdf53fff, 0xbeeb9857, 0x3e88de8f, 0xbd43685b, 
    0xbf2f4b28, 0xbd6a329b, 0xbdb7e438, 0xbe909f60, 0xbef177bb, 0xbeba775c, 0xbe5f2560, 0xbe81c3b1, 
    0x3efb2f88, 0xbe5d9a80, 0x3eda0c5c, 0xbe42ae85, 0xbeda745e, 0xbe15ba0a, 0xbcdc0361, 0xbdbff1ac, 
    0x3de337be, 0xbebf7257, 0xbec23e26, 0xbe21177a, 0xbd060f17, 0x3dcc404d, 0x3ec9142e, 0xbe8bafd4, 
    0x3e935c7d, 0xbef3c5f5, 0xbe966f0b, 0xbe20a8a6, 0xbef3ee47, 0xbec55df5, 0x3c29573e, 0xbdc5a346, 
    0xbd45a9bc, 0xbe084fc2, 0x3e7e6c03, 0xbea23a25, 0xbeabfedc, 0xbeec3341, 0xbeb61bcc, 0xbe6b6610, 
    0x3e4e0641, 0x3d02fd91, 0x3d615244, 0x3e520ffb, 0xbe35c4d2, 0x3dfdfe62, 0xbe274472, 0xbd1823bb, 
    0xbe91bd10, 0x3d1aff2a, 0xbee18e47, 0x3d26ce96, 0xbe1298d1, 0x3dafd657, 0xbe3ea475, 0x3e180602, 
    0xbd28ecf8, 0xbe13b2a0, 0xbe2edcbe, 0x3e96231e, 0xbc80e1b0, 0x3e291e5b, 0xbe069045, 0xbe923981, 
    0x3ea15aa0, 0xbc7b896c, 0x3e87c734, 0x3edf895a, 0xbc91df49, 0xbd9a891c, 0xbe8ad4d9, 0xbe58dca7, 
    0x3e13225b, 0xbe035e61, 0xbe903473, 0x3e9e8ec8, 0xbea00475, 0xbe0a9964, 0xbebfcc63, 0x3e8f4763, 
    0x3d8fbc9d, 0x3c996611, 0xbd7548fb, 0xbdffd352, 0x3e5f9375, 0x3e8133d7, 0x3e7006d0, 0x3d41fea0, 
    0xbc5385da, 0x3bfa511a, 0xbe344c97, 0xbe26ac24, 0x3ca8f75f, 0xbd2eeb45, 0x3ea8614c, 0x3edbcbd7, 
    0x3e93322d, 0x3db1fda4, 0x3ea6bf0c, 0x3e54f1f9, 0xbe5febb2, 0x3e86a07d, 0xbe3d4b94, 0xbe3011a6, 
    0xbc88c011, 0xbe90160b, 0x3e88309c, 0x3db1e388, 0x3eb76d1f, 0x3e813e8d, 0xbe2268d6, 0x3e1f6d0b, 
    0x3d4c7f07, 0xbeac591e, 0x3ecf778c, 0x3edea90d, 0x3e2ddcb6, 0x3cb15814, 0x3ef640c8, 0xbe744872, 
    0x3e89626b, 0xbe05feb5, 0xbe9f84d5, 0x3e5b4d63, 0xbeadae46, 0xbe5fb288, 0x3ce9ed7a, 0xbd4aade0, 
    0xbe90b5d4, 0x3ebace53, 0x3e95af54, 0xbee7c9c3, 0x3e4b9e07, 0x3ebd80a7, 0xbe8d0fc9, 0xbe91adc3, 
    0xbedbcf09, 0xbe3ed454, 0xbe0f5c81, 0xbc6107f7, 0xbd8b7a73, 0xbe20b8ba, 0x3e225b5b, 0x3ecff7c8, 
    0xbe0613f4, 0xbeb350d2, 0xbedcb18d, 0x3e7aa238, 0xbd83130b, 0x3d5aac36, 0x3e9ae33b, 0x3e78761a, 
    0xbda7b6cb, 0x3e937c51, 0xbd933347, 0x3f03808e, 0x3e10c49f, 0xbdf8ce26, 0x3ee06dbe, 0x3e84a192, 
    0xbe750c64, 0x3e88f358, 0x3e844e54, 0x3ebfe4df, 0x3e551f0a, 0x3e233ccd, 0xbe7d1397, 0x3e97997a, 
    0x3cf63bac, 0x3d86d1bc, 0xbd031432, 0x3d5c9ca5, 0xbe3bba1c, 0x3a7ef5a6, 0xbdb1f833, 0xbdbf37d8, 
    0xbe5643a8, 0xbe62e9af, 0x3e34ac4c, 0xbe9c1c2f, 0x3d10a94b, 0xbed87957, 0x3efce6b7, 0x3efb7988, 
    0xbe87ef26, 0xbeae9bca, 0xbdf33af9, 0x3e35a3a7, 0xbf321759, 0x3e7c74e1, 0xba3fcdf8, 0xbe52ccfe, 
    0xbda1e70e, 0x3e8f7642, 0xbea06eea, 0xbee3d1db, 0x3d188b7c, 0x3b6d7bd4, 0x3e0b73ba, 0xbe7925b9, 
    0xbd917103, 0xbece33a2, 0xbd221ab4, 0xbe09c607, 0xbe0bd6f6, 0xbd219cf6, 0x3ea3d726, 0xbf02cce6, 
    0x3ecd8772, 0x3d3cfc6b, 0xbe4f0fe4, 0xbed8d39e, 0xbe551f17, 0x3d1b8d76, 0x3dfc4297, 0x3df0081f, 
    0xbe945d0a, 0x3d597b92, 0x3ec20177, 0x3d68dc49, 0x3bb4ff03, 0xbe798d28, 0x3d71a8cd, 0x3e176eb6, 
    0xbe986208, 0xbdc3a87f, 0x3e8c3649, 0x3eac7cf7, 0x3f1679b6, 0x3ee02b76, 0xbee4dacd, 0x3f30c424, 
    0x3eba5e5f, 0xbe1f1f73, 0x3f0dfee0, 0x3edffc6b, 0xbe29ccb0, 0x3e0bcdc8, 0x3f02178f, 0x3cd0d2ec, 
    0xbeb96216, 0xbf362657, 0xbf170c12, 0x3e02d505, 0x3dab5647, 0x3ecea2a9, 0x3ef34604, 0x3d091cb7, 
    0x3f0449af, 0x3ddc751b, 0xbe25a0b4, 0xbf018265, 0x3ca463b6, 0x3d0a872e, 0x3f330ecd, 0x3f08f136, 
    0xbe27672f, 0xbea62f80, 0x3d77ee7e, 0x3df35d11, 0xbdf41044, 0xbe5a89c7, 0x3b714b13, 0x3e8e789d, 
    0xbe97f7a5, 0x3e997508, 0x3e8fccda, 0xbec447b5, 0x3f07585c, 0xbde6a213, 0xbe655cbb, 0xbecd0987, 
    0xbe03396e, 0xbedc9cda, 0x3ea261fb, 0x3e9f5f36, 0xbec28293, 0xbe468ae8, 0xbecbe863, 0x3deb3d91, 
    0xbefb1da1, 0x3e0679a7, 0xbc8c70ee, 0xbf24918d, 0x3d7aeac2, 0xbf23bcc9, 0xbecda3ec, 0xbe97a78a, 
    0xbc8539d9, 0xbf00cea6, 0xbea06d27, 0xbe9011df, 0x3eaebcd2, 0xbd2dc29f, 0x3e9e4b55, 0x3f424449, 
    0xbea4edd8, 0xbd8db3c9, 0xbe3e0339, 0xbe928d34, 0xbe0e48c5, 0xbf10a0ff, 0xbe239efe, 0x3cf07ef5, 
    0x3eaf05b0, 0xbf072a25, 0xbe6fa6a7, 0xbe6b3d14, 0xbdeab6db, 0x3e20d89d, 0x3c6cddd7, 0x3e769608, 
    0x3e964932, 0x3d767989, 0x3d8cff89, 0xbdb06348, 0xbe5c9a61, 0xbe72e51d, 0x3ee38040, 0x3cdf6294, 
    0x3e21c871, 0x3e6007f3, 0x3d31ae63, 0x3e9c53ec, 0x3e542ab0, 0xbefcf096, 0xbdaa9419, 0x3f0d68d7, 
    0x3cf397c2, 0xbd84cd31, 0xbee07535, 0x3ea75cd8, 0xbe252e8e, 0xbedcf9de, 0xbed16979, 0xbee9d26d, 
    0xbe1e2461, 0xbf0992f4, 0x3e839454, 0xbdb93b25, 0x3ecf3d88, 0xbd4121d1, 0x3d915003, 0xbed6f075, 
    0x3eb4c4d7, 0x3eb7e4f1, 0x3e939a22, 0x3ee8d826, 0xbe919150, 0x3dd32397, 0xbe03e11d, 0x3ee82111, 
    0xbd8bb926, 0x3cec25ee, 0xbdbd3a6c, 0x3e96978e, 0xbcba8949, 0x3cdb1eab, 0xbebac945, 0x3e19fa53, 
    0xbebe9c9c, 0xbe840acd, 0x3e9a9b09, 0x3f041e51, 0xbdda265c, 0x3e911d1e, 0xbda58554, 0x3e9da772, 
    0xbeaf2382, 0x3e0fc77a, 0xbdad70ee, 0xbeeafa12, 0x3eb232de, 0x3f06c5a7, 0x3e2c2757, 0x3ed4e85c, 
    0xbe09fd13, 0x3db6b2dd, 0x3ef2452d, 0x3d2418c5, 0xbe5138ad, 0xbdda19bb, 0x3d5c124b, 0x3df431cd, 
    0xbe265d3f, 0x3e643362, 0x3efc14b9, 0x3e8b3ec1, 0x3daa7cf5, 0xbeb865a1, 0xbdb23692, 0x3df63149, 
    0x3df83eca, 0xbdf9f266, 0xbdb48a52, 0xbecfb59b, 0x3eae16b3, 0x3cad0a8b, 0xbe1a3d0c, 0xfffffe26, 
    0x00000004, 0x00000040, 0xbf3d5c0a, 0xbec6d09f, 0xbc80edae, 0xbdaa58c0, 0xbe6b1e7e, 0xbe179703, 
    0xbf195db5, 0xbdabc6d3, 0x3f223e9a, 0xbe0a1bcc, 0xbe9259b6, 0xbf12cac4, 0x3f3f8718, 0x3f4477dc, 
    0x3f0b13fd, 0xbec326e8, 0xfffffe72, 0x00000004, 0x00000040, 0x3f097b84, 0x3c4052da, 0x3f0e3d52, 
    0x3f924254, 0xbf856e38, 0x3f36e736, 0x3fa85efe, 0xbde76420, 0xbeca504b, 0xbf4e4d04, 0xbf95d314, 
    0x3f4654e2, 0xbeb0788d, 0x3e9b9143, 0xbf408c0b, 0xbef52c26, 0xfffffebe, 0x00000004, 0x00000080, 
    0x3f23e442, 0xbeff1b9f, 0xbe021957, 0x3fb2e5aa, 0xbee0115a, 0x3f9c310f, 0xbf8829e9, 0x3f943297, 
    0x3f3d43b6, 0xbefeaf54, 0xbf0716e8, 0xbf2c4201, 0x3fa85f8b, 0xbf568c7c, 0x3fb32a34, 0x3d8f98e3, 
    0xbfb5772d, 0xbf5c97fd, 0x3f974eaf, 0x3e8665ad, 0xbf4edd23, 0x3e3eb966, 0xbddb7344, 0x3f6cf1e8, 
    0xbfc2d49b, 0x3bf1e2c2, 0xbfb39785, 0x3f90a125, 0x3f6cb3c2, 0xbe67eb30, 0xbd9d8cff, 0xbcaeef1a, 
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
    0x00000002, 0x00000001, 0x00000002, 0xfffff122, 0x01000000, 0x00000010, 0x00000010, 0x00000024, 
    0x0000006c, 0xfffff10c, 0x0000005e, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f39315f, 0x4d74614d, 0x6d3b6c75, 0x6c65646f, 
    0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 
    0x422f3931, 0x41736169, 0x00006464, 0x00000002, 0x00000001, 0x00000002, 0xfffff1ae, 0x01000000, 
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
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3731746e, 0x00000000, 0x00000001, 0x00000002, 
    0xfffffbb6, 0x01000000, 0x00000010, 0x00000010, 0x00000012, 0x00000020, 0xfffffba0, 0x00000010, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x3631746e, 0x00000000, 0x00000002, 0x00000002, 0x00000020, 
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
#define _K7              ((uint8_t *)_k7)                    // u8[38784] (38784 bytes)
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
*  @param data_out Output features. Output float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_dequeue(float *restrict data_out) {    
    __HOOK_REGION(true, 0);
    while(1) {
        __RETURN_ERROR_BREAK_EMPTY(fixwin_dequeue(_K2, _K1, 512, 320));
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
    __RETURN_ERROR(mtb_model_raw(_K10, _K4, 1500, data_out, 8));
    __HOOK_REGION(false, 1);
    return 0;
}

/*
* Try write data to model.
* 
*  @param data_in Input features. Input float[1].
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
    fixwin_init(_K2, 4, 512);
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
    fixwin_init(_K2, 4, 512);
    fixwin_init(_K5, 120, 50);
    __RETURN_ERROR(mtb_init(_K10, _K7, 38784, _K6, 16384, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0x3f, 0x45, 0xb5, 0xc6, 0x84, 0x01, 0x98, 0x49, 0x91, 0xe7, 0xe9, 0x52, 0xc8, 0x30, 0xf4, 0xc5},
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
        .size = 40896,
        .peak_usage = 40896,
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
                            .size = 2,
                            .labels = (label_text_t[]) { "unlabeled","sirens" },
                        },
                    },
                    .count = 2,
                    .bytes = 8,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 8.333333333333334,
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
                            .size = 1,
                        },
                    },
                    .count = 1,
                    .bytes = 4,
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

