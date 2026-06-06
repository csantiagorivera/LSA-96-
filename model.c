/*
* ImagiNet Compiler 5.13.5501.65534+6ddbc592e16d83c41e7b0b9321278834ef733ad3
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 11:40:05 UTC. Any changes will be lost.
* 
* Model ID  f65f0929-7ba7-44a2-91e5-1c776160b0de
* 
* Memory    Size                      Efficiency
* Buffers   10256 bytes (RAM)         80 %
* State     25992 bytes (RAM)         100 %
* Readonly  41424 bytes (Flash)       100 %
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param data_out Output features. Output float[6].
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
    0x0000001c, 0x00000090, 0x000000e8, 0x000084ac, 0x000084bc, 0x000098ec, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000024, 0x00000004, 0x00000008, 0x6579616c, 0x30325f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffff7b1a, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x00000027, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x00000026, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x00000028, 0x000083c0, 0x000083b8, 0x00008328, 
    0x000082d8, 0x00008288, 0x00005278, 0x00004668, 0x00003c98, 0x00003c54, 0x00003c38, 0x00003c18, 
    0x00003bf8, 0x00003bd8, 0x000023c8, 0x00002338, 0x00001728, 0x000016d8, 0x00000480, 0x00000170, 
    0x00000148, 0x00000134, 0x00000114, 0x0000010c, 0x00000104, 0x000000fc, 0x000000f4, 0x000000ec, 
    0x000000e4, 0x000000dc, 0x000000d4, 0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 
    0x000000a4, 0x0000009c, 0x00000094, 0x00000074, 0x00000004, 0xffff7c2e, 0x00000004, 0x00000060, 
    0x00000010, 0x00000000, 0x000e0008, 0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 
    0x00040008, 0x00000006, 0x00000004, 0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 
    0xc23047ea, 0x5abdb88c, 0x00000003, 0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 
    0xffff7c9a, 0x00000004, 0x00000010, 0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffff6954, 
    0xffff6958, 0xffff695c, 0xffff6960, 0xffff6964, 0xffff6968, 0xffff696c, 0xffff6970, 0xffff6974, 
    0xffff6978, 0xffff697c, 0xffff6980, 0xffff6984, 0xffff6988, 0xffff698c, 0xffff6990, 0xffff7cf6, 
    0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xffff7d12, 0x00000004, 
    0x00000004, 0x00000001, 0xffff7d22, 0x00000004, 0x00000018, 0x3b9359a8, 0xbc866c55, 0x3d3ae232, 
    0x3c8fbc09, 0xbd7f2436, 0x3c01791f, 0xffff7d46, 0x00000004, 0x00000300, 0x3db636aa, 0x3df2cb1e, 
    0xbe3fb917, 0x3d9b2b06, 0x3eae2b60, 0x3ec92384, 0x3e50eb44, 0x3ce5f7c6, 0x3c3f952f, 0xbec468ee, 
    0x3dcff23c, 0x3e416e10, 0xbe68fbc2, 0xbd0f3bb6, 0x3dea562e, 0x3ddc220a, 0xbe908b19, 0x3e6f3e25, 
    0x3ebd35dd, 0x3e68437f, 0xbe60d563, 0x3dcaab9a, 0x3eac6d87, 0xbeb7fa94, 0xbde9e40d, 0x3e850b00, 
    0x3e6f2f2e, 0xbe52451b, 0xbe895e93, 0xbd571155, 0x3e31ccc6, 0xbeb82f3f, 0xbe91dcb5, 0xbf0b6897, 
    0x3d5c0d57, 0x3ea12a3f, 0x3eac1b91, 0x3d99fa92, 0xbf036712, 0x3ed10f7d, 0xbefeceee, 0xbdcc6dfc, 
    0x3e67f26a, 0xbe01a642, 0x3e938cd0, 0xbee0adb8, 0xbea622c6, 0x3e9bc91f, 0xbec4c3a8, 0xbe96773c, 
    0xbe9bbc7d, 0xbebd0092, 0x3cdae4e6, 0xbd857b85, 0xbeb9dc69, 0xbee815a2, 0x3ea4947c, 0x3eab237b, 
    0x3ecfca94, 0x3ec5b575, 0xbef0319b, 0xbef6b586, 0xbe0c8012, 0x3dd3cab1, 0xbe379a1b, 0x3e98952e, 
    0xbeebca81, 0xbeb85bc8, 0xbe9aeaf5, 0xbdbfb34e, 0xbe429ab9, 0xbe27bbf5, 0xbd3c8971, 0xbed3b103, 
    0x3ef2877a, 0x3e8f794e, 0xbddfce0d, 0xbed906e1, 0xbe7c72e8, 0xbeceaa39, 0x3cbeac7b, 0xbe8cecbd, 
    0x3ee3edcf, 0xbe98dd93, 0xbecaec4c, 0xbecb35bd, 0xbea47905, 0x3d1acdc2, 0xbd18fb10, 0xbe95f507, 
    0x3d44404b, 0x3c05ab10, 0x3ebe959d, 0xbeb96f82, 0xbe67f683, 0x3e9b58a0, 0xbee4796e, 0xbe3ccf1c, 
    0x3e603517, 0xbed4644c, 0x3eb73b54, 0xbe275058, 0xbe4388a0, 0xbe313e46, 0xbdfd1614, 0xbe3eaff3, 
    0xbef61eb6, 0xbf2288b6, 0xbee9e0f2, 0x3e7f7c35, 0x3e88b9dd, 0xbebbf4df, 0x3ed81ae9, 0xbeed762e, 
    0x3e94114a, 0x3c2c0798, 0xbeaa6e24, 0xb9d493e6, 0x3e6a81d9, 0xbd238c3f, 0x3d07ae6c, 0xbe241146, 
    0x3e58eaea, 0x3e933a79, 0x3e6b8f4a, 0xbddb0d00, 0xbec5d8cd, 0xbd1adbe8, 0x3d26fa58, 0x3e9b77ad, 
    0x3dbb0579, 0xbe26d5ba, 0xbed573fb, 0xbe1a4143, 0xbecf9268, 0x3ea0082c, 0x3e765636, 0xbcbc3b7b, 
    0xbe9c55e8, 0xbf0e90e5, 0x3dc4e564, 0xbeb934a3, 0xbeb45abc, 0x3e6a136a, 0xbe2ed250, 0x3dd54c03, 
    0xbeeb6f8d, 0x3e2c8ca5, 0xbdccfabd, 0x3e2ef4a8, 0x3ea4d19b, 0x3e4246da, 0x3e85b192, 0x3e9b317a, 
    0xbf06fd1f, 0xbd5fcd48, 0xbd639a82, 0xbd4684cd, 0x3e8a1d86, 0xbe91c922, 0xbe8c38c9, 0xbeb156be, 
    0xbe5ddb6f, 0x3d962430, 0xbefbb2b0, 0xbeb9a048, 0xbe3e6c29, 0xbf09deef, 0x3e55f98d, 0xbcacc1fd, 
    0xbcc7ad4b, 0x3e2029ac, 0x3dee0f31, 0x3e8154e1, 0x3e496f12, 0xbe26bedb, 0x3ee3d5bd, 0xbe8f637a, 
    0xbe1593fb, 0x3e3e8b52, 0xbec5f3bb, 0x3ef15046, 0xbf0b6a25, 0xbeda6b34, 0xbf10478e, 0x3ecb7320, 
    0xbd1209a9, 0x3ea58b1a, 0xbefe91d1, 0x3ece1e66, 0x3e934c30, 0x3eff3d9c, 0xffff8052, 0x00000004, 
    0x00001248, 0x3ce1ef93, 0x3dfd1607, 0x3ddd078f, 0xbd89377c, 0x3d100526, 0xbd01d5e0, 0x3e0f8f2c, 
    0x3e052ee5, 0xba3c4bb0, 0xbe1a6d66, 0x3e12db3d, 0x3e0406b8, 0x3d88b5cc, 0x3cc781d2, 0x3d9c8db1, 
    0x3e6d4617, 0xbd50230d, 0xbe24322a, 0xbd6383ee, 0x3da0be7d, 0xbe54ba2f, 0xbe29dadc, 0xbe1d8e67, 
    0x3d968ac7, 0x3deb5e00, 0x3da59ca7, 0x3e40e078, 0xbe35c795, 0xbe3abf57, 0x3d02fe4a, 0xbda72712, 
    0xbe0b1d81, 0x3d583333, 0x3de6a52c, 0xbdd37335, 0x3d91ca55, 0xbd39b968, 0x3e4a4446, 0x3dc2e60c, 
    0xbe681afd, 0x3e311987, 0x3c493e62, 0x3d536618, 0x3d3601ef, 0xbe433de7, 0xbd6a7661, 0x3d45fa9b, 
    0xbe209397, 0x3c9a4dc6, 0xbc921879, 0xbe317dd2, 0x3a2b7084, 0x3c6e4874, 0x3e58ed60, 0x3d99c6c2, 
    0xbd07d612, 0xbe64571c, 0x3e09813b, 0xbd4e2056, 0xbe36cd17, 0x3d01bfbb, 0xbde3e62c, 0x3e1d60d4, 
    0x3d7a3ade, 0x3e0f09d0, 0xbd814d46, 0x3d6abf42, 0x3e3f4726, 0x3d96ceff, 0xbd57f123, 0xbd785fe2, 
    0xbdd304ca, 0x3e63a128, 0x3e1a0265, 0x3dea6f18, 0x3e730bbf, 0xbe057455, 0x3d081b61, 0xbc2b4f1a, 
    0x3e124df1, 0xbd3af8d0, 0x3e0bff13, 0xbdf8b916, 0xbd5e5ab0, 0x3da9afeb, 0xbc028da8, 0xbdf122f2, 
    0x3e2baf40, 0x3e0f880b, 0xbe3e57c9, 0xbe267125, 0xbdd41ca9, 0xbd8a6b40, 0xb881e11c, 0x3cb2d74a, 
    0x3e6cb4d4, 0xbd51e434, 0x3d75a1c7, 0x3e2e88be, 0x3e4b53a8, 0x3e4f9614, 0x3e620236, 0x3e6d8f60, 
    0x3c39d828, 0xbe0f7b20, 0x3db1206d, 0xbd3f390a, 0x3e3d3116, 0xbd8b8f19, 0xbe1c0446, 0x3e05a18c, 
    0x3e4203b4, 0xbdeb0835, 0xbc9ef5ee, 0xbe068a0a, 0xbe2fe323, 0xbde6fd5c, 0xbb9fc482, 0x3e2eece6, 
    0x3bff62fc, 0xbc1b7c7d, 0xbe0960df, 0xbdd91492, 0x3da7e191, 0xbd123d2a, 0xbcc0d554, 0x3e0f55ba, 
    0xbdb7799f, 0xbd4d139e, 0xbdab5220, 0xbc245e85, 0xbdc18339, 0x3e66d19f, 0x3e108be5, 0xbd00ca91, 
    0x3e27fc07, 0xbdf2a9dd, 0x3e0c7ed8, 0xbd457309, 0xbe0b0fa0, 0xbde6fe71, 0xbe276f71, 0xbe856b97, 
    0xbdb68fd9, 0x3e1352a6, 0xbe1baca3, 0x3dfa7482, 0xbe222bf5, 0x3e07d88b, 0x3dac2b01, 0x3dbd350e, 
    0x3e5cac98, 0xbe252ba2, 0x3e3c6d8e, 0x3cee131a, 0x3bea70df, 0x3dca8693, 0x3d884baf, 0x3e0a3438, 
    0xbd8ccf1f, 0xbc7ff3b8, 0x3df314d7, 0x3e2906fa, 0x3db3348e, 0xbe008697, 0xbd90e2c9, 0xbdf4d04b, 
    0xbb1f2ceb, 0xbd040b6e, 0xbe195994, 0xbe261798, 0x3e2f2888, 0xbe1cb930, 0xbde839f8, 0x3db40d32, 
    0xbd96f3b3, 0xbe304044, 0xbda9f1b8, 0xbdee62d2, 0xbd81147e, 0x3dfc80e1, 0x3dcd05e7, 0x3de1ac7c, 
    0xbd989863, 0xbdcbada9, 0xbe33d10c, 0xbdcc4733, 0xbe4cd769, 0xbe218247, 0xbe368575, 0xbe17b82a, 
    0xbe390040, 0xbe1ced11, 0x3e561e7f, 0xbca7bf72, 0xbe1e7e13, 0xbd982331, 0xbe20cb82, 0x3d920423, 
    0x3ac214a3, 0xbe3f67f0, 0x3c8f6c24, 0xbe1171ce, 0xbe2f87ad, 0xbce656c9, 0x3d2ae1a1, 0x3d072618, 
    0x3daf38e1, 0xbd31a66d, 0x3dc0ddca, 0xbdd8bf8d, 0xbce95e9f, 0xbe13cf10, 0xbe000054, 0x3d61dcda, 
    0xbd848a6b, 0x3e02e565, 0x3dc63b62, 0x3de08460, 0xbe15b18d, 0xbe346f8f, 0xbdecb0d3, 0x3e4dac3c, 
    0x3dca96e7, 0x3e0604ed, 0xbd5ac07b, 0xbe3e5cbf, 0xbcda803a, 0xbd92d4d6, 0xbe1d3ac7, 0x3d44d809, 
    0xbcc01462, 0xbe842717, 0x3dc11a54, 0x3e501a55, 0x3e058b51, 0x3d165673, 0x3e48313e, 0xbd93dc4e, 
    0x3e366e65, 0xbd76c248, 0xbe21d980, 0xbe45e4d0, 0xbe195a73, 0xbe464576, 0x3e1b0367, 0xbe1d21e8, 
    0xbcc40ac6, 0x3d87c875, 0xbe2d5433, 0x3dccd05b, 0x3d52d2fb, 0xbdf6692f, 0x3cd92da9, 0x3d255518, 
    0x3e1e7b5f, 0xbda91a7b, 0xbded7606, 0xbd37f514, 0xbcb9431a, 0x3c8f4994, 0xbdc96905, 0xbe09cffe, 
    0xbdffe7d8, 0x3e0b7ab4, 0xbe29eccb, 0x3e1492f4, 0x3e26f747, 0x3dc8f205, 0xbe0a1d78, 0x3e38691b, 
    0xbd806062, 0xbe0409ea, 0x3e2e19dd, 0x3e77082d, 0xbe17df00, 0x3e0a44ce, 0xbdee02ce, 0x3e06fe49, 
    0x3e2e500b, 0x3d1d44a9, 0xbd940ead, 0x3e22ef7f, 0xbdc32707, 0xbd7824ff, 0x3e5af78b, 0x3dd38de3, 
    0x3d7aa111, 0x3d87d1f5, 0x3d8ce8e8, 0xbe5dbfb6, 0x3e027ee1, 0xbe032812, 0x3ddb4008, 0x3e51c944, 
    0x3d3964f1, 0x3d814464, 0xbda92215, 0x3e4268ac, 0xbdbc0edf, 0xbe199093, 0x3c9c1a8f, 0xbd43ff17, 
    0x3e4569ff, 0xbd1569b7, 0x3daf9cd4, 0xbe2108b6, 0x3e2d60ca, 0xbc29afe4, 0xbd9d81b3, 0xbdd9cbcd, 
    0x3e1544cb, 0x3dce2dc8, 0xbda1df8f, 0x3c7935a5, 0xbe0df57f, 0x3e345812, 0xbd6aef61, 0xbe4dff4d, 
    0x3d929f93, 0xbe02be29, 0x3e174a38, 0xbe4fb9f6, 0x3e515b7d, 0x3ce47f04, 0xbe0d7719, 0xbe35c9e6, 
    0x3e33d7bc, 0xbcc26487, 0x3dd3a9e6, 0xbe0a9c8c, 0x3dd3ef40, 0x3c4c74f3, 0x3dbc082a, 0xbd3d791d, 
    0x3cd29f93, 0x3e076fb5, 0xbda72a76, 0xbc58e970, 0x3ded1c3d, 0xbd03a800, 0xbdc2da66, 0x3d67c636, 
    0x3de51b46, 0xbe0cbfcc, 0x3d61dedc, 0xbda7df03, 0xbc501cc1, 0xbe04c6e3, 0x3dce6bae, 0xbe65e902, 
    0x3e1a9a07, 0xbb994f51, 0x3dd380d9, 0x3e85f70d, 0xbe3d3fe2, 0xbe105f46, 0xbde246a6, 0x3d727721, 
    0xbe1fa11d, 0x3dcbf50a, 0x3e189968, 0xbc72ef3b, 0xbe4c19b2, 0xbde28e0f, 0x3d013957, 0x3e2cd9fb, 
    0x3d9ecad4, 0xbda77f2c, 0x3b006e66, 0xbd93e0ca, 0x3d21663d, 0xbe29577b, 0xbe4e1cac, 0xbcd46832, 
    0x3e59bf21, 0x3d633dfa, 0x3e344cf6, 0x3da53b41, 0x3da254a8, 0xbe6ddd03, 0xbc6d52ce, 0xbe059942, 
    0x3cb8e68c, 0xbe22c1e9, 0xbe2b6444, 0xbdffbc73, 0x3ddafd90, 0xbe00a641, 0xbc7dbe7f, 0x3e2af752, 
    0xbe5a61a0, 0x3ca26a26, 0x3d9947d8, 0x3bab01be, 0xbd4e7f21, 0xbe0a6417, 0xbe06ee57, 0xbdeaf87f, 
    0x3de84a8a, 0xbd927ca4, 0x3b975f64, 0x3e03b6b1, 0xbc984836, 0xbda107c6, 0x3dec0055, 0x3d80b76f, 
    0x3db173a8, 0x3e04d9de, 0xbd750439, 0x3d3bce9e, 0xbe05a70e, 0xbe405831, 0x3d3d9356, 0xbe0ec3f3, 
    0x3e176e04, 0x3e457d0b, 0xbe34737c, 0x3d668ac5, 0xbdaa9777, 0xbe1f0095, 0xbe067c43, 0x3e02698f, 
    0xbe500baa, 0x3cbaf065, 0x3c3b9b55, 0x3e11e0b9, 0xbe1a94b4, 0x3cd54948, 0x3c95474f, 0x3dfe7868, 
    0x3daed301, 0xbe2c1789, 0x3e16676d, 0xbcbac9dd, 0x3dae10c0, 0x3dc12731, 0x3dbc4aee, 0xbe4c5aa4, 
    0x3c1fa5e8, 0xbe2f3ccf, 0x3d4ea60c, 0xbdc20cbe, 0xbc7f8e49, 0x3dbbd914, 0x3cba20a3, 0x3e406946, 
    0x3d2dd61e, 0x3d040531, 0xbe31fad6, 0xbd27de88, 0x3e338847, 0x3dfc3fa8, 0x3e20e6c8, 0xbd966109, 
    0xbab9d30c, 0xbd9a4c44, 0xbe00ef6c, 0x3d661dea, 0x3d5e7f40, 0x3d271fae, 0x3cbaff9a, 0x3df3b2fa, 
    0x3dd0611d, 0x3e343ccc, 0x3d928bdb, 0x3e5f4f3e, 0xbd4332c9, 0xbe53b681, 0xbce41e6d, 0xbd83b5fc, 
    0x3b539b08, 0xbdc9cad1, 0x3e2e8262, 0xbc7e2a54, 0xbdbd6e49, 0xbe3a2ba6, 0xbe1749a2, 0x3e132d28, 
    0xbd2f0611, 0xbdfcdfad, 0x3dbd237b, 0x3b3fcf41, 0x3d074088, 0x3e1c85e6, 0x3e090a71, 0xbc95499c, 
    0xbe4dc144, 0xbd7365be, 0x3e4ee615, 0x3e3d7ba9, 0x3d882836, 0x3c8d3ad0, 0x3d58101d, 0x3e1d9c3f, 
    0xbe15441c, 0xbe0f1a42, 0x3e002927, 0xbe0d8f2e, 0xbe219941, 0xbb8834ad, 0xbdd444af, 0x3c8ef76a, 
    0x3bad8fb3, 0x3cf29b7b, 0x3de71a90, 0x3e5c0b4b, 0x3df18a3d, 0xbe48d7e6, 0x3d4ca318, 0xbdbb02be, 
    0x3cf00edf, 0xbcc718e2, 0x3dc7cf0a, 0xbe40f702, 0xbdd8e1ef, 0x3dd8fea0, 0xbd999c1a, 0xbe2dd840, 
    0x3d511c2e, 0x3d66e5e4, 0xbdfa3202, 0xbe1c1f8e, 0x3dc04bd0, 0xbe346cbf, 0x3e4939cd, 0x3d59e6bc, 
    0x3d98e3c8, 0x3e406d80, 0xbe3cabb5, 0x3e0ce7ec, 0xbda33e5d, 0xbccde254, 0x3e0f2447, 0xbe4e742d, 
    0x3e22a5c1, 0x3e1ff8d8, 0xbe722bf1, 0xbe4fa735, 0x3e0ecd02, 0x3e027203, 0x3c1c4c28, 0xbe31a010, 
    0xbd6ab882, 0xbe4088e1, 0x3bb69d78, 0x3e0d67db, 0x3e57cb60, 0xbb10caa7, 0x3c6e4df3, 0xbc84d81e, 
    0x3e41bdaa, 0xbe194be0, 0x3dd6cce1, 0x3e110fdc, 0x3e168ac5, 0xbd6539a8, 0xbca62cec, 0x3d88bc75, 
    0x3e49c550, 0x3d544784, 0xbd8af7a3, 0xbdfb079a, 0x3d4e0b93, 0xbe250343, 0xbe404f8b, 0xbe483a2b, 
    0x3e40bc5d, 0xbd297f24, 0x3d4b6669, 0x3d38d698, 0xbe19632e, 0xbd1a188c, 0xbdb7babf, 0xbd69d38f, 
    0x3e47a263, 0xbe5ac7ad, 0xbcf5cc77, 0xbbe64df3, 0xbabbbe2b, 0xbdd2a5bf, 0x3e3adf84, 0x3e145841, 
    0xbd9f03cd, 0xbde3d4de, 0xbe303862, 0xbdb591d4, 0xbc0a2050, 0x3e0b6fbb, 0xbcd2d42b, 0x3e698f45, 
    0x3df08319, 0xbe3bfe51, 0x3e033903, 0x3e2b33c7, 0xbe11f5cb, 0x3d93804e, 0xbca1c79d, 0x3e226486, 
    0xbdbc3533, 0xbd7dd47c, 0xbdb92089, 0x3e536672, 0x3d265938, 0xbe36f9c1, 0x3d36c26a, 0x3ce39eb2, 
    0xbc6835bf, 0xbdb47e3b, 0xbca6727b, 0xbdb9180b, 0xbe0bad72, 0x3dd1b839, 0x3e520438, 0x3db64561, 
    0x3e17bf9d, 0x3e61b409, 0x3e10fc10, 0x3d4e3c89, 0x3e343b36, 0xbc5c955e, 0xbd970fa0, 0x3e25cba3, 
    0x3a246a54, 0x3d0b8f79, 0xbe0ff7bb, 0xbe387f0f, 0xbddec1e1, 0x3d527092, 0xbe658ed8, 0x3e121b9b, 
    0x3b613f69, 0xbdf9240f, 0xbe1851a0, 0x3c995322, 0xbd268298, 0x3e273004, 0x3d4b21d7, 0x3cc92bd5, 
    0xbc72e4e1, 0x3e620fb4, 0xbe2c8e9e, 0xbe0b74c5, 0x3cce4f3f, 0xbd9a2236, 0x3e0f5e73, 0x3c3f112a, 
    0x3d8b49b4, 0x3be6dfc9, 0x3e143777, 0x3e2bd8f1, 0x3e3b9dd6, 0xbe7681eb, 0xbd0d4b31, 0x3d098785, 
    0xbe28ebe8, 0xbe0efcc9, 0x3e40746c, 0x3e720dfd, 0x3db03394, 0x3d970e75, 0x3e287a83, 0x3cb4a9c4, 
    0x3d179d11, 0x3e411b11, 0x3e4739f4, 0xbe450ba1, 0xbd867005, 0x3cb3486f, 0xba44a28c, 0x3de38c82, 
    0x3c9dd194, 0xbdf2f562, 0xbdf1de37, 0xbaefa547, 0xbd9674a4, 0xbc491fa5, 0xbe505ed5, 0x3d859834, 
    0x3e58fe49, 0x3cb867bb, 0xbddac0e1, 0xbe755e7d, 0xbd38ed92, 0x3c8ccd03, 0xbd8a240b, 0x3b6ef919, 
    0xbc89be35, 0x3e5dfdcf, 0x3e3b711b, 0x3e15cbb7, 0xbdf2f5d5, 0x3dda0278, 0x3e3655f6, 0xbddcdb81, 
    0xbdabf9d9, 0xbd69b4bd, 0x3df6cbeb, 0x3dc18950, 0xbd1ae6ac, 0x3e26bef9, 0xbda0514f, 0x3e04c44b, 
    0xbe2db78c, 0xbe0e7b33, 0xbdaad773, 0xbd74f1a6, 0xbe704975, 0x3dabd241, 0xbe2409b5, 0x3d871b45, 
    0x3d80a9db, 0xbe065909, 0xbc9db261, 0xb8d9fbfd, 0x3cef1e33, 0x3e0c6ecc, 0x3d49f17b, 0xbd57532c, 
    0x3e83af2a, 0x3db59eee, 0x3e254838, 0xbe4481c4, 0xbe42794c, 0x3e11916a, 0xbe523eb8, 0xbdad76d0, 
    0xbe1d1276, 0xbcf8f5c8, 0xbda52045, 0x3cb46693, 0x3d6aef3a, 0xbe5f48ad, 0x3d69029e, 0x3d7a43d7, 
    0x3dc70196, 0x3b428129, 0x3d463c8f, 0x3d57d71f, 0xbd943d0a, 0x3ce8d231, 0xbde864ac, 0xbdeab641, 
    0xbe104b6c, 0x3e0dc4b4, 0xbe510948, 0x3e1b7f3c, 0x3d0951be, 0xbdbea36e, 0xbe285a01, 0x3ca8e53e, 
    0x3e33740f, 0xbd85d3aa, 0x3de48da6, 0xbda701c2, 0xbdf475fb, 0x3dab0235, 0xbe579b0a, 0xbdee0a33, 
    0xbdb3f076, 0xbdd767b2, 0x3e31a5a2, 0xbe425db5, 0x3c900ad5, 0xbe048f84, 0xbe279019, 0x3dea4f08, 
    0x3dd75d34, 0x3d98fc16, 0x3dcb96cd, 0x3da97a18, 0xbd91d638, 0x3cab71b1, 0x3daadfa0, 0x3e3effa7, 
    0xbb91af6f, 0xbd8f2d83, 0xbda82402, 0xbd6da5be, 0xbe1311fb, 0x3dd5b304, 0xbe413752, 0xbd3b8bdf, 
    0x3e291157, 0xbe31e773, 0x3ab42efa, 0xbda2ae7d, 0x3dfeec53, 0x3d2e0722, 0xbe019e4a, 0x3e5df43c, 
    0xbd4fb0fc, 0x3e1db7f2, 0xbe28a429, 0xbcf72dad, 0x3df9f941, 0xbd04aa81, 0x3e3cc222, 0x3ddf11ca, 
    0xbe2a5a3d, 0x3dcd45dc, 0x3e23a9ea, 0xbe3a8885, 0x3e297e1c, 0x3e2b8332, 0x3cca3427, 0x38b7a572, 
    0xbded17b1, 0xbd97ebb4, 0x3e4e7559, 0xbdad9947, 0x3e1e3ac5, 0x3e4abd79, 0xbe1723d5, 0x3dac63f9, 
    0x3e2657a2, 0x3dc159b3, 0x3e22f66e, 0xbc932c18, 0xbd38a59d, 0x3c21aed8, 0x3c9471da, 0x3dd4eb2e, 
    0xbc4c825e, 0xbd0a2486, 0x3e2c5912, 0x3d05ae27, 0xbd9c3b42, 0x3d690fe0, 0x3dae98a6, 0x3db6b64f, 
    0xbe090a6f, 0xbea227e3, 0x3cf31b01, 0x3e64a2ed, 0xbe59c6c4, 0x3e4295f5, 0xbe287f9b, 0xbc91815b, 
    0x3db276f0, 0xbe220105, 0xbe26398e, 0xbdc0e0ae, 0xbdf953a0, 0xbe4f435b, 0x3e01c6c8, 0x3db8aa22, 
    0xbd47ab90, 0x3d349a83, 0x3e30f662, 0x3e3e8f97, 0x3d857daa, 0x3d44159f, 0x3dba401d, 0xbcb8526d, 
    0xbe213ff1, 0x3d7a2e7e, 0x3d5c53a4, 0xbd13d2e8, 0x3e45a303, 0xbe296e43, 0x3d988fe3, 0xbdf01811, 
    0xbe104765, 0x3dd4b5ae, 0x3cc0f5ae, 0xbe03a66f, 0xbd8fd95f, 0x3e72d984, 0xbc2c743d, 0x3d643173, 
    0x3e1eff2c, 0xbdaacd4e, 0x3ddeaceb, 0xbd8c2818, 0xbba2b129, 0xbe63c841, 0xbe5006cc, 0x3a9daa89, 
    0xbdbd64a5, 0xbd8c951e, 0xbd8ddc53, 0x3c90af01, 0x3e115d52, 0x3db464ca, 0x3db5e0e6, 0x3ca9ed2d, 
    0x3e26d99d, 0x3de298cc, 0x3e0ddabd, 0xbda74157, 0x3e20bac6, 0xbd95c8ef, 0xbe3d1b54, 0x3e30ad9b, 
    0xbd7a893b, 0xbcf8083e, 0x3e17323f, 0xbe16951a, 0x3da31018, 0x3dbd2146, 0x3da5db23, 0x3d5561e6, 
    0x3d76a397, 0x3d73ab0f, 0xbe2905ac, 0x3a0d98d1, 0x3ca7e00b, 0xbe53e5dc, 0xbdc5daaa, 0x3c11054c, 
    0x3e143739, 0x3e788720, 0xbdf54125, 0x3dc50e27, 0xbdba84d6, 0x3e1cb9ca, 0x3d251683, 0x3d59d59a, 
    0xbc67bb6b, 0xbe05fa2e, 0xbe294ad1, 0xbe520cb2, 0x3de3856c, 0x3c57904c, 0x3e56d4de, 0xbddf4b19, 
    0xbb49e131, 0xbe484d48, 0xbe3b070f, 0x3e4b13e7, 0xbd8e228f, 0xbc7701dc, 0xbe53c7c5, 0x3d4e2a0e, 
    0xbe2dca08, 0xbde6d0f4, 0xbd40d96b, 0xbde0d7e0, 0xbb4fc360, 0x3d5fbc87, 0xbceaa83a, 0x3c86db4e, 
    0xbd1ae07f, 0xbe41627f, 0xbc0e03b3, 0xbcee13b5, 0x3e3017c5, 0x3de677ce, 0x3c6b5d7e, 0x3d1d626a, 
    0xbe2db995, 0x3e12bebc, 0xbdc903e2, 0xbde50fe8, 0xbc577538, 0x3e459cd7, 0xbe05802c, 0x3c80efe3, 
    0x3e25edb1, 0xbd964d95, 0xbe1034da, 0xbe1877f4, 0xbdb60a3c, 0x3e4a0bcc, 0x3e453ce5, 0x3e5d3ed9, 
    0xbc9fd7a7, 0x3e029bb8, 0x3d055230, 0xbdd5e9da, 0xbdc23779, 0x3ab71e6a, 0x3d8454d3, 0xbccdf95f, 
    0xbcb69faf, 0xbd21970e, 0xbc9dcf9c, 0xbde15b30, 0xbdd1a15f, 0x3dea9230, 0xbcad0aa3, 0x3ce07a42, 
    0x3cc2a2a5, 0x3e5f1a9b, 0xbd7ad468, 0x3e3bacee, 0x3bf99c5d, 0x3e1de573, 0xbcbbefe2, 0x3da4b5a1, 
    0xbe15c06d, 0xbe4ac95e, 0x3e4afb1a, 0xbdcca7b0, 0x3dde6ecc, 0xbd07733a, 0xbe1fb3e0, 0x3e2b00e9, 
    0xbdc40e40, 0xbe3490d8, 0xbe40ef5a, 0x3d83287b, 0x3d54722e, 0x3e3d9301, 0xbd84249b, 0x3e088cc3, 
    0xbde1c848, 0xbceb753b, 0xbe3ac4cc, 0xbe3410de, 0xbd4d2db1, 0x3e71835e, 0xbb8166bf, 0xbe317739, 
    0x3e3b580b, 0x3e2e4cc4, 0x3ba3ae7d, 0xbe07bb5c, 0xbdca63ba, 0x3d4e6cf1, 0xbd9a494d, 0x3df30a6e, 
    0x3afc2c1c, 0xbcfd6d6b, 0x3d67307c, 0x3daa83dd, 0x3e598d17, 0x3e4070ca, 0x3dfd7142, 0xbd51587d, 
    0x3d4d5f82, 0xbd784564, 0xbd813a34, 0xbdb291fb, 0x3dba3da8, 0x3dacee8f, 0xbd367fca, 0x3d02cef4, 
    0x3e5520c2, 0xbcd3d783, 0x3d91cc01, 0x3e4f9176, 0x3e160d74, 0x3e0c0e55, 0x3cd6cdc5, 0x3e3a26e2, 
    0xbdf802ba, 0x3d802465, 0x3d83a76b, 0xbd38a90c, 0xbe15d81b, 0x3ba56f45, 0xbe1954b5, 0xbd844262, 
    0x3ddb5727, 0x3d178276, 0xbe1e75cf, 0x3e41e64b, 0xbe408198, 0xbe0c2426, 0x3dbe2e20, 0xbe5f81f6, 
    0xbdf63e92, 0x3e174c21, 0x3e5d3862, 0x3d94a15f, 0x3e3f04a1, 0x3c1653b3, 0xbcf71c0f, 0xbdbc0ea8, 
    0xbd9238f7, 0xbdacdedc, 0xbda66625, 0xbe14d8d4, 0xbdf23e5a, 0xbe262d5d, 0xbe404100, 0xbd6a2be3, 
    0x3d82f89f, 0x3db81740, 0x3c69ffa5, 0xbdfb0bdb, 0x3dc2212d, 0xbe28f908, 0x3e34e372, 0xbdebd8ed, 
    0xbd97abd6, 0x3e2ce87b, 0xbdccd207, 0xbe3fa381, 0xbd479aa7, 0x3dad5850, 0xbe1702b7, 0xbd855457, 
    0x3d6cefe6, 0x3de2e584, 0xbd4ada3c, 0x3d99afb2, 0x3dc7ab6c, 0x3dbf6458, 0xbc1e838b, 0xbe7f06f7, 
    0xbe41cad3, 0x3c50e051, 0x3da61c85, 0xbdcbc77e, 0x3cf544c5, 0x3dbe71f0, 0x3e36206e, 0xbe126c63, 
    0x3e2a1d22, 0x3de1af6d, 0x3d9f89db, 0x3e403d38, 0x3d9117e2, 0x3dec3c04, 0x3dbad37f, 0xbe2612f0, 
    0xbdc082b3, 0x3e50562e, 0xbdfc6239, 0x3e3a7ce0, 0xbd94bfb1, 0x3deaaab9, 0x3cdc1e06, 0x3e30bee3, 
    0x3e31f18f, 0x3df4555d, 0xbceca851, 0xbc214ac3, 0x3d57ad5d, 0x3cd51df0, 0xbdd06542, 0x3c33f4cf, 
    0xbe3cbb2d, 0xbcfd9054, 0x3e68283b, 0xbd949738, 0x3ce49e97, 0xbdce6b95, 0xbe0f80ab, 0x3906be1b, 
    0x3dfc7115, 0x3d407f2b, 0x3ddfbc8e, 0x3d96c61a, 0x3e330029, 0x3c59217a, 0x3d200456, 0xbe0009b2, 
    0xbe34f5fb, 0xbe3b7738, 0x3d7aae2d, 0xbe26671b, 0xbe30ccd5, 0x3e31a7cb, 0xbce02b17, 0xbe0abcc3, 
    0x3c90e730, 0xbe1034a4, 0x3d25d211, 0xbdaac758, 0xbd1b012c, 0xbe1c5e94, 0xbe568d67, 0xbd9eab0b, 
    0x3de9f500, 0x3e4bba19, 0xbdf56f0f, 0xffff92a6, 0x00000004, 0x00000040, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffff92f2, 0x00000004, 
    0x00000c00, 0x3e156998, 0xbe1bb7b5, 0xbd873d45, 0x3d091667, 0xba8405f4, 0x3c990ffc, 0xbc4efb7a, 
    0x3e7a1d92, 0x3e12be57, 0x3deddbcc, 0x3d50b2ce, 0x3db12eef, 0x3e0ef4c9, 0x3e6dd790, 0x3df9f5e0, 
    0x3e195453, 0x3e5fe323, 0x3c197741, 0xbe816f9a, 0xbe1e16ff, 0xbdd72a00, 0x3e474301, 0x3e5d79a7, 
    0xbe259618, 0x3cbc6194, 0xbe13b53e, 0xbddea4f5, 0x3e86bbd0, 0x3d8f5015, 0xbb38ae2d, 0x3e3acb80, 
    0x3e0c76b9, 0xbe80afe1, 0xbda08a56, 0x3e4d1a1d, 0xbe219831, 0x3dc3ceea, 0xbdabd60a, 0xbbfd0fb1, 
    0x3e3404ca, 0xbe1148c0, 0xbe11d46b, 0x3aa919c4, 0xbd0d104b, 0x3e06add2, 0x3d8c6ed3, 0x3cfde767, 
    0x3e2bc4bd, 0x3e44c63e, 0xbcdb041f, 0x3e6ffe5f, 0x3cff328f, 0xbd9f090f, 0x3d980357, 0xbe2be4b4, 
    0xbe095ff4, 0x3e263d3f, 0xbe233230, 0x3dfad676, 0x3e094275, 0xbd437109, 0x3e0c8c48, 0x3e615fe0, 
    0xbd99b9be, 0x3dcf9c8a, 0xbe5126fa, 0x3cf187d0, 0x3e6ca8ca, 0x3e39127d, 0xbdc54813, 0x3e57fd5f, 
    0xbe4fab56, 0x3c34f6d1, 0xbc646a50, 0x3e5b1b0e, 0x3da7d2c5, 0xbceed2b6, 0xbe4a4252, 0x3dfe274e, 
    0x3e3995bc, 0x3dab0a42, 0x3d9ae100, 0xbac14cb1, 0x3e5a44cd, 0xbe4c4055, 0xbac1ea2b, 0xbe59ed3e, 
    0x3e004fb6, 0x3dec81e7, 0x3e54a98a, 0x3e80fca5, 0x3ddfe2eb, 0xbe034b73, 0xbe2e6cc7, 0x3ba68367, 
    0xbe0f25cc, 0xbe3d5ec0, 0x3d42d506, 0x3cbfef70, 0x3e4c0979, 0x3e6408b7, 0xbd9481d2, 0x3d2314ae, 
    0xbc56ccb0, 0x3e10aa49, 0x3c8684fc, 0x3db008c0, 0x3e05fdc6, 0xbe3030b0, 0x3dd9d3ce, 0xbe46f94c, 
    0x3db02b92, 0xbe165d82, 0x3dc47c72, 0xbcde86b0, 0x3e352711, 0xbe3e7702, 0xbe8fa3c0, 0x3bafa300, 
    0x3e0be2b4, 0x3e56373c, 0x3e89f129, 0x3e05e303, 0xbe70aeb4, 0x3e11c690, 0x3e48f580, 0x3dad94f5, 
    0xbd1a10b4, 0xbe440a90, 0xbd300a14, 0xbddc795b, 0x3b2393af, 0x3ce3fc01, 0xbe4653f4, 0x3e8161ef, 
    0x3e90f2ba, 0xbc4f284b, 0x3e25dbd4, 0xbe8a3b3f, 0x3e3df3ff, 0xbe02940f, 0xbcdb981c, 0x3da916a9, 
    0xbd2b5244, 0x3e862d98, 0x3e25f8aa, 0x3cdea557, 0x3e573d7a, 0x3df017a9, 0x3e22cffa, 0x3e1bdf35, 
    0x3e07b607, 0x3df3dc35, 0x3dc8e4cd, 0x3d045d8f, 0x3d5dc643, 0x3e248fb3, 0x3e169bed, 0x3e4c80c0, 
    0xbe0868d5, 0x3e29168c, 0x3dd3d1df, 0xbe12d4ec, 0x3e4c9eb0, 0xba483404, 0xbd68ae56, 0xbd0ab08a, 
    0x3e3f2210, 0x3ce3dd44, 0xbdcc3435, 0x3bfeb0e4, 0x3e2ac6bf, 0xbd96c294, 0xbdd7f807, 0xba42843c, 
    0xbd0b119e, 0xbdfdaf8e, 0xbe1fd0c7, 0xbe453511, 0x3e58524b, 0x3c1e95a3, 0xbda68ea0, 0x3d13c4de, 
    0xbe0af3bb, 0xbe83e719, 0xbe711cad, 0xbe429ff3, 0xbe5a2a3e, 0x3db9e624, 0x3df93ba9, 0x3e1342e7, 
    0x3c96f9f1, 0xbe5d151f, 0x3e795d5f, 0xbc9c9b86, 0xbe4640e6, 0xbdf88161, 0xbe737b4b, 0xbdd9843b, 
    0x3e378ce7, 0x3d8a48f1, 0x3e8865f4, 0x3c78d559, 0xbe3cb6f6, 0xbd35f9a6, 0x3e29cbf3, 0x3c77dcad, 
    0x3e3e3e51, 0x3d6a25be, 0xbcbaa29c, 0xbe225fb0, 0xbe4154f7, 0x3df22f71, 0x3d2265ec, 0xbd9136f5, 
    0xbd6c9df6, 0xbdc01488, 0x3dc40612, 0x3baa7091, 0xbe1b791d, 0x3da0a21b, 0xbe2b95da, 0x3e6ef857, 
    0xbafa8dc7, 0xbe31d03f, 0xbdb7f278, 0x3e61cc40, 0xbe74047f, 0xbe15949b, 0xbdf63d25, 0xbe340e17, 
    0x3d201368, 0xbe63c805, 0x3e3f65e0, 0x3e1a5736, 0xbbacd669, 0xbe1f1081, 0x3c4d8def, 0xbdc514cc, 
    0xbd278a24, 0xbe5266ff, 0x3d36d801, 0xbc65e083, 0xbb8a3929, 0x3e72cdad, 0xbe469b02, 0x3e88aecb, 
    0xbe238c6d, 0x3e6caf8b, 0xbca0fa55, 0xbe2d3ec8, 0xbc79cf61, 0x3e6599e2, 0x3de933cd, 0xbe7639b8, 
    0x3e1c1f24, 0xbe4b2f45, 0x3e3cc9aa, 0x3dab4c43, 0x3d369cd9, 0x3e3acb98, 0xbca86f04, 0x3e31a360, 
    0xbbbcfd24, 0xbdff3b7d, 0xbc69e4a5, 0xbe4dca7b, 0xbe2c8f3d, 0x3e352c13, 0xbd22fa88, 0xbca5a0e1, 
    0x3d8c7792, 0xbe6407ed, 0xbe047945, 0x3d98ddcd, 0xbdb53ddd, 0xbc8adb44, 0x3e2f9108, 0xbe2058c3, 
    0xbe75c432, 0x3b3a364c, 0x3ddea1fd, 0xbcf11325, 0xbe34dd56, 0x3b111ce1, 0x3d707d38, 0xbe59b8a2, 
    0xbe4dfe76, 0xbe308790, 0x3d9ecef3, 0xbe1f92ff, 0xbc7f531e, 0x3da9df3c, 0xbe279a0e, 0xbc9b7bae, 
    0xbe685fc0, 0xbe469b32, 0x3e33d4dd, 0x3e18463b, 0x3e154333, 0x3b250673, 0xbd2f975d, 0xbe6fea46, 
    0xb9892402, 0x3e581778, 0xbe141dd9, 0xbdd28a19, 0xbdc636a3, 0xbe29d7fc, 0xbcf79af8, 0xbe65f2ce, 
    0x3e17f8a5, 0x3dbe1fc4, 0xbd596076, 0x3d449f43, 0x3e61cf6d, 0xb98e4fa6, 0x3d4af34c, 0x3e937ce1, 
    0x3cf6fa76, 0xbe0efcbe, 0x3dd47ed6, 0x3e0863aa, 0x3cc101cc, 0xbcc95e9e, 0xbe043c5d, 0xbe738cb4, 
    0x3e78b46a, 0xbde99194, 0x3e0ca5b6, 0xbdb6895b, 0x3cf70ad2, 0x3e142c71, 0xbdfcd88a, 0xbe2e169a, 
    0x3d3283ef, 0xbe1fdc08, 0xbe8c9e79, 0x3e807379, 0xbc4ce74a, 0x3d8e183a, 0xbdf1559d, 0xbe052425, 
    0xbca42a1a, 0xbe1bbebf, 0x3e340c5e, 0xbdad7e60, 0x3dda8ada, 0xbe2fb68e, 0x3dd56fd5, 0x3d3b6f10, 
    0x3dac9e22, 0x3e703c37, 0x3e88c809, 0xbdb4f2be, 0x3d0edd6e, 0xbd1978b9, 0x3e4c1f8e, 0xbdc6c56a, 
    0x3d756be8, 0x3df1e7be, 0x3df3806d, 0x3e10845c, 0xbd7d9327, 0xbd884b41, 0xbdc3cbf6, 0x3dcf80d0, 
    0xbda00d9b, 0xbe5eaffa, 0xbc2ed0c4, 0x3e274c63, 0xbe575ad4, 0xbe24055d, 0xbe5c0a9d, 0xbe822356, 
    0x3e2458c6, 0xbe2bdb9f, 0x3e750c4f, 0x3e429a69, 0x3e23839a, 0xbdfd3ce8, 0xbda021ef, 0x3cb5a715, 
    0xbdd978cb, 0x3e756d4a, 0xbdea5ef0, 0x3dbba919, 0x3d904dad, 0x3e7b5138, 0xbe1aac2e, 0xbe2b42db, 
    0xbe56bad4, 0xbe1514c5, 0x3e487d1f, 0xbdde9e3b, 0xbbd5950b, 0x3e38e0a7, 0x3dd4dc32, 0x3e415544, 
    0x3da9531b, 0xbd983167, 0x3e83b362, 0x3d7b9ed3, 0xbd814c4c, 0xbe48a1c3, 0x3e290a1f, 0xbe06d73d, 
    0xbe80fec6, 0x3d37dd2c, 0xbe5b01ea, 0x3d9f59da, 0xbe0d4392, 0x3d88358d, 0x3e5c4523, 0x3d5e39a7, 
    0x3e1384e2, 0x3e175f90, 0x3d2757c8, 0xbe498399, 0x3c8e0278, 0xbdd971c6, 0xbe31d5ff, 0x3e272b03, 
    0xbdb715da, 0xbe568fe3, 0x3e4f57c9, 0xbda624e8, 0x3e7a2949, 0xbe22013c, 0x3e0b122d, 0xbd485186, 
    0x3e166b52, 0xbe70c92e, 0x3e03c135, 0xbde02a26, 0x3d84b024, 0x3e7334f5, 0x3e33a312, 0x3dac30e0, 
    0xbe42b2a7, 0xbe3267c8, 0xbe33d10d, 0x3de83bf8, 0x3d1c6590, 0x3e564b48, 0xbe2c0829, 0xbdbb73e0, 
    0x3ce3acb0, 0xbe803569, 0xbc22e25a, 0xbe3b5206, 0x3dfcc4f0, 0x3e45d537, 0x3e53dd21, 0x3e448743, 
    0x3e00d467, 0xbd42f924, 0xbd9f1ad0, 0xbe35a2a3, 0x3e2de5b4, 0xbe4904b6, 0xbdf1e196, 0x3c442753, 
    0x3d0aaa45, 0xbccacb5a, 0xbda1bbb9, 0x3e508cfb, 0x3e226c9b, 0xbe6478bd, 0x3b3f7d3d, 0x3e3895be, 
    0x3e495057, 0xbd982139, 0xbe1c8c11, 0x3db6cb63, 0xbdb7ffa6, 0xbca67138, 0xbe07d48f, 0x3d78aac1, 
    0xbc03875a, 0x3c9242f2, 0x3df4d778, 0xbce05ced, 0x3dc42312, 0x3daeef5a, 0x3e64b593, 0x3df079e7, 
    0x3dcfed00, 0x3e4ed08d, 0x3d062597, 0x3e266a32, 0xbe2f773b, 0x3e6c0eef, 0x3c5d3654, 0x3e3997e0, 
    0x3e2066e5, 0xbddc0cf4, 0x3db5466a, 0x3d6c8e69, 0xbd07baa0, 0xbd804ef5, 0xbe0239a1, 0x3e89f331, 
    0x3db24383, 0x3de75efb, 0x3c47ebec, 0x3cad3dd7, 0x3b2c19ad, 0x3e107cee, 0x3e13b698, 0xbe0d6c14, 
    0xbe0e5c64, 0xbe0e861c, 0xbde4d324, 0xbd000b44, 0x3ddc46fe, 0x3d0a00c1, 0xbe0caa7a, 0x3df01734, 
    0x3e38aaac, 0x3e16b47e, 0xbe3357e2, 0x3e3c9822, 0x3e108c08, 0x3d44d2f5, 0xbd60239c, 0xbd2d575a, 
    0x3de1c4bc, 0x3e7d0703, 0x3e09341d, 0xbd066932, 0x3d8c7f6f, 0xbd171985, 0xbdd29fc7, 0x3dfecf7d, 
    0xbb1eb5fd, 0xbe16db53, 0x3e2acdb9, 0xbe4a57d8, 0x3de57dc8, 0x3cbf6e0f, 0xbd2a48e3, 0xbd859f31, 
    0xbe557cee, 0x3e283e40, 0x3dedb33a, 0xbdc8015a, 0x3c48ab29, 0x3e14677f, 0x3b4f1a70, 0xbd1b1a97, 
    0x3e468e90, 0xbe31455d, 0x3e70f1db, 0x3e40d906, 0xbdd9426c, 0xbe0e961a, 0x3e86b0be, 0x3bebed11, 
    0xbbc4d7de, 0xbe1d328a, 0xbdaa550a, 0x3cddea8c, 0x3e13d6c6, 0xbe2d6896, 0x3e0b0e72, 0x3e61e70a, 
    0x3dec2cca, 0xbd375ae4, 0xbbc590dc, 0x3ddbcc9c, 0x3df88c7d, 0xbd7fad52, 0x3e3b664a, 0xbc28f916, 
    0x3e118389, 0x3dcc9871, 0x3dabb177, 0xbe230b15, 0x3dfa9026, 0xbe94cd67, 0x3df2e56d, 0xbde52213, 
    0x3e209e3b, 0x3e717cc5, 0xbe766f93, 0xbe459caf, 0xbdd0851b, 0xbc1834ac, 0x3de836e2, 0x3cd0ebc8, 
    0xbcb710ff, 0x3e1d6170, 0x3db33d68, 0x3d9ee805, 0xbe4871bc, 0x3c9ee8ef, 0xbe6b1b67, 0x3db3ef7e, 
    0x3d4d5c6e, 0x3e3b8d56, 0x3b964927, 0xbe1863d9, 0xbe6b8fbe, 0xbe24d2c9, 0xbe47e214, 0xbd013aa0, 
    0x3e231355, 0x3c22dae7, 0x3e0071b5, 0x3e01eda8, 0x3d5dbf7e, 0xbe09c495, 0xbd0c695d, 0x3da468ef, 
    0xbb048699, 0xbdad942b, 0x3d10e915, 0x3ce0fec6, 0x3e42590a, 0xbe0db088, 0x3e119090, 0x3e2e0893, 
    0x3cb43f5e, 0xbd253331, 0xbe027c9d, 0xbe419240, 0xbcebc15e, 0xbdf38833, 0x3c2f65ae, 0xbe3c5647, 
    0xbd40f3b1, 0xbdb2b87e, 0xbe2c688a, 0xbe29c2c0, 0x3e2c376a, 0xbe38121d, 0x3e5a0118, 0xbda25194, 
    0xbe3b8436, 0xbd236018, 0x3e3b6599, 0xbdaebc1d, 0xbe3d77cc, 0xbd82e2c9, 0x3e0a525f, 0xbd136555, 
    0xbd860bf2, 0xbd14fa2d, 0xbe3144ca, 0x3e0b8e10, 0xbe12eccd, 0x3e6143fc, 0x3da91eb1, 0xbe5c48e0, 
    0xbe0a66f8, 0x3e5695a8, 0xbdb0bf32, 0xbe3bd3a8, 0x3e60cbcc, 0xbd6daf6d, 0x3e35bc3b, 0x3d801894, 
    0x3e0979f7, 0xbd29fb68, 0xbd01106d, 0x3e884e43, 0xbdcde0e5, 0x3decd184, 0xbe0505f1, 0xbe01fe7f, 
    0xbce02fae, 0xbe7ccbf5, 0xbe7cc440, 0x3d0a9f49, 0xbe2d1140, 0x3deed617, 0xbc9b9981, 0xbd9796b6, 
    0x3e35df38, 0xbdc3321b, 0xbd8a7c31, 0x3dceb740, 0x3dd44e93, 0xbe9b4e2d, 0x3dc882b0, 0xbdbefaf3, 
    0xbda42a12, 0x3e6cccec, 0xbd125ba2, 0x3d4d87dd, 0xbd9faa34, 0x3d6d65ee, 0x3d2eb62c, 0xbdfd063b, 
    0x3d00eed2, 0xbe3d44b8, 0x3d9c82ba, 0xbe841996, 0xbdd87b88, 0x3cd99dff, 0xbe4437fa, 0x3d8e88ed, 
    0xbe4ef59b, 0x3d10d549, 0x3e280a84, 0xbd2839ff, 0xbe47a736, 0xbe89c102, 0x3d986b84, 0x3e849b64, 
    0xbe50fdf3, 0x3e300828, 0x3e6152eb, 0xbe165026, 0xbe3fb038, 0x3db84fa6, 0x3e21e17e, 0x3dfd1780, 
    0x3e803125, 0x3cefedf6, 0x3e6a3b7b, 0x3dc8748b, 0xbe52d6ad, 0x3e0375ee, 0x3e409143, 0x3ca3af02, 
    0x3cc772d5, 0x3e49ea4e, 0xbdef8b49, 0xbe62f712, 0x3e0fc2be, 0xbe643366, 0x3d46fe15, 0x3e24e0b5, 
    0x3e4556c7, 0xbe31cd08, 0xbe112091, 0x3b2601e4, 0xbe581de5, 0xbe5d5bfc, 0xbda312ef, 0x3e070e2c, 
    0x3c80a6f7, 0xbd3e8881, 0xbd514cfb, 0xbb87b02b, 0xbbb198e7, 0xbd35f727, 0x3db1d916, 0x3e81a1ef, 
    0x3e51612e, 0x3e3178e1, 0xbd0ab7ae, 0xbe820cc7, 0xbe28b6fb, 0xbd7a0768, 0x3e3fbd60, 0x3e69c0cf, 
    0xbe259955, 0x3d171865, 0x3e420704, 0xbe75de31, 0x3e871d62, 0x3d3fd639, 0x3e30f58a, 0xbd9d99c1, 
    0xbe135f11, 0xffff9efe, 0x00000004, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffff9f8a, 0x00000004, 0x00001800, 0x3e2036f3, 
    0x3db144df, 0x3cee021e, 0x3df325b3, 0x3e4f889c, 0xbdb597af, 0x3e0f6782, 0xbd8a37f5, 0x3e27f18e, 
    0x3e68bb86, 0xbc57510a, 0xbd884baf, 0xbe276b26, 0xbd12b636, 0x3e1dbe08, 0xbc74a77d, 0x3d476253, 
    0xbcec9115, 0x3db8a01c, 0xbdaa06b2, 0x3e2f7a9d, 0x3e4ba9e1, 0xbd1649a5, 0x3caa3e35, 0xbd49fee8, 
    0x3e05d69d, 0xbdbf124a, 0x3e012fed, 0xbc8e86e0, 0xbdfb87f6, 0xbd89b5ef, 0x3d946b79, 0xbe370e1e, 
    0xbe1b229e, 0x3e39927c, 0x3e54a8a3, 0xbd76efbd, 0xbc72fc1c, 0xbca9197a, 0x3e102f69, 0xbcb9395d, 
    0x3dc2f783, 0x3e243bf9, 0xbd627e88, 0xbe2274a4, 0x3de24e05, 0x3d5b90b2, 0xbdbca201, 0xbe1c07d6, 
    0xbe3403bc, 0xbdb36433, 0xbdece309, 0xbe239d3d, 0x3d8e13f2, 0xbe3df320, 0xbdff77ac, 0x3d5912a2, 
    0xbe555158, 0xbde52854, 0x3c885c26, 0x3daaca6e, 0x3e1b3f36, 0x3ddb7686, 0x3c436c73, 0x3e0ed2ec, 
    0x3e04423b, 0x3d11b735, 0x3d9cf939, 0xbd41d450, 0x3e16cd06, 0xbdb05172, 0xbdf9d46a, 0x3e238cb3, 
    0x3df24d83, 0xbe472f8f, 0xbe3c0f90, 0xbe3358cd, 0xbdfea174, 0xbdedd26d, 0x3c88435e, 0x3e12233b, 
    0x3dfebf82, 0xbc2a2610, 0xbe263c74, 0x3daa5298, 0x3e2d0264, 0xbe4160ea, 0xbe2e414d, 0x3dca9b4a, 
    0x3dc5b7b8, 0xbe387f63, 0xbe228d7d, 0xbd4b7315, 0x3de68842, 0xbe26f8a9, 0xbe3af749, 0xbe24723e, 
    0xbd32c572, 0x3cae4135, 0x3d6f1b92, 0x3e36e31e, 0xbde6f5a5, 0x3e39cb78, 0x3e096a0b, 0x3da6f397, 
    0xbe0e5bab, 0x3df6057c, 0x3e20ed42, 0x3e32e318, 0xbe353db8, 0x3e3c923c, 0xbe18e195, 0xbcc5ae9a, 
    0xbc820cc1, 0x382c55f2, 0xbdecf8cc, 0xbdcf614e, 0x3da1dcfc, 0x3de2d0a8, 0xbcaf12d6, 0xbe10a74e, 
    0xbcabef92, 0xbd9711b0, 0x3e1e74b5, 0x3c3295ec, 0x3d55bd53, 0x3d84f16e, 0xbd9e8796, 0x3df59a2a, 
    0xbd196a71, 0x3e354a7f, 0xbd6b0938, 0x3df8e9be, 0x3dcb067d, 0xbd1ca77d, 0x3cb8c701, 0x3d753812, 
    0xbb6e9daa, 0x3dfdd26a, 0x3e1c914f, 0xbc1e9bc4, 0xbc977b47, 0xbe1ff716, 0xbe0fad62, 0x3dbef98a, 
    0xbe080e0f, 0x3dadedb3, 0xbe1d7ddc, 0xbe56f6f3, 0x3ce1b055, 0x3dd956fc, 0x3e25a62b, 0xbe3978ed, 
    0xbd990541, 0x3e0174bf, 0xbd957c95, 0x3e064fd0, 0x3e207d6c, 0xbabec2fd, 0xbcbe9685, 0xbe097893, 
    0xbde216a0, 0x3dbb14b2, 0xbdfbde6a, 0xbe626f99, 0xbe541cf2, 0xbe0bf812, 0x3d48c9cd, 0xbe281768, 
    0xbdd4498a, 0xbe06b38b, 0x3c0922a3, 0xbce5e33b, 0xbd5f683f, 0x3e63013c, 0xbdb5e2d2, 0x3d86941a, 
    0x3db309f4, 0x3e44a167, 0x3e32e22c, 0xbdaaab25, 0x3e01b4b3, 0xbe120995, 0xbe0312a8, 0xbe5b2b3c, 
    0x3d140872, 0x3b6bd937, 0x3d97cdf1, 0xbe07aef5, 0x3e5cdd46, 0x3def2192, 0x3ca0e457, 0x3e149fff, 
    0xbdbff59f, 0x3e263c38, 0x3dfe987a, 0xbdd1eb70, 0x3d6d6ffb, 0x3d5c7ef8, 0x3df8fa31, 0x3e3efb18, 
    0xbba346c2, 0xbd9f4f4b, 0x3dafa88b, 0xbd6846a3, 0x3e317c31, 0xbd9ccd05, 0xbdb5ca71, 0xbd6b0ff1, 
    0x3dd89a1b, 0xbdaf8bd3, 0x3d57106b, 0x3e319956, 0xbe28d398, 0x3db94e3e, 0xbe152bbc, 0xbc4cda33, 
    0xbd54023e, 0x3d17688a, 0x3df5e3b7, 0x3de09084, 0x3e776897, 0xbdc645c1, 0xbe029d1e, 0xbd1f2600, 
    0x3d64a11d, 0xbde1c049, 0x3e2f7b14, 0x3e2e78fc, 0x3e057ff6, 0xbdd76431, 0xbdeffb99, 0x3e3491bb, 
    0xbc43a3f4, 0x3d65bcc5, 0xbd9bb471, 0x3cf44492, 0xbd0ce86b, 0x3d58b088, 0x3e377097, 0x3e216241, 
    0x3e14b582, 0x3d707ca1, 0xbdd0a96c, 0x3d66a844, 0x3e2009d4, 0x3e0a9885, 0x3d9b937f, 0xbc9f3844, 
    0xbd44ead3, 0x3d002bcf, 0x3e0db966, 0xbe676b26, 0x3de380ec, 0x3712bbc4, 0xbe03d2f1, 0x3d1d6471, 
    0x3da49367, 0xbc8df1aa, 0xbe13b14e, 0x3e1af961, 0xbdbaa5ce, 0xbb71e483, 0x3e324d03, 0x3dc66a7c, 
    0xbdb7bba1, 0xbe23b452, 0x3dabe11f, 0x3e232142, 0x3d00bef1, 0x3d9e8f47, 0xbe1a8a72, 0x3d9e02b1, 
    0x3e214988, 0x3cb527cc, 0xbe08d803, 0xbe3f822d, 0xbcbca28f, 0x3dbc5e51, 0xbbfecf61, 0xbca7a283, 
    0xbad7e786, 0x3df61123, 0xbc58939d, 0xbe065aac, 0x3cc9a8cf, 0x3e06c660, 0xbe61c66c, 0xbdf60c60, 
    0xbc88ab38, 0x3df19c69, 0x3e07b570, 0x3d4aea9a, 0xbdcae74d, 0x3d9efb66, 0x3ca77a67, 0xbc073c9c, 
    0xbcb7e7b3, 0x3dbb0ef6, 0x3d9128c8, 0x3e32fa91, 0x3e31e86f, 0xbc1b66a3, 0xbde10a89, 0x3ca105a7, 
    0x3d94b3ef, 0xbd96ee30, 0x3e6022ce, 0xbd925681, 0x3e2b9b29, 0xbe3f45a9, 0xbdfef1e5, 0x3b04484f, 
    0xbc6e1275, 0x3d5ed500, 0xbe46d289, 0x3cda25be, 0x3e101adf, 0x3e4519a2, 0xbd8ac1f9, 0x3e31e985, 
    0x3e0ddb77, 0xbd740c66, 0x3dd32591, 0x3ced869a, 0xbd9fc643, 0xbdb1c596, 0x3e11a953, 0x3b9c2789, 
    0x3dea0797, 0xbdfdf2ea, 0x3dc7f096, 0xbca6f688, 0x3d4e1387, 0x3d642fd3, 0x3c73e4e4, 0x3bb669b6, 
    0x3c305c9b, 0x3d712a21, 0x3c85a821, 0x3d811912, 0xbd23ce76, 0x3e133aae, 0xbd74e556, 0x3d0c5b20, 
    0xbdbbc0e8, 0xbd598077, 0xbe426476, 0xbd7d7a1a, 0x3e0faff8, 0xbdcf8324, 0xbe2c6f03, 0x3c326035, 
    0x3d4106d2, 0xbdbe3eae, 0xbdaaf813, 0x3e03f2a6, 0xbe65dcd0, 0x3d8501c1, 0x3cf2bce0, 0xbdfa0e65, 
    0xbd630777, 0x3e65842e, 0xbdaeb379, 0x3b20b73a, 0xbd4e028d, 0xbe2e9687, 0xbddb2919, 0xbe5373ac, 
    0x3e05c88e, 0xbe1a5599, 0x3e3eecd4, 0xbce266c4, 0x3db0601c, 0x3dc86282, 0x3d4a3f92, 0xbe3fa1b3, 
    0xbdfaec13, 0xbe162c34, 0x3c8d0209, 0xbe42a88a, 0x3b56227d, 0x3dd3d313, 0x3d114f7c, 0x3dd3dd11, 
    0x3d03af33, 0x3d864ae8, 0x3bca80cc, 0x3dd47d71, 0x3da5bed7, 0x3e25c290, 0xbddcc1f6, 0x3db3ef57, 
    0xbd216bf4, 0x3dd103e5, 0xbe7b34cc, 0x3ac842dd, 0xbd3121e5, 0x3e0876ef, 0xbe49e24e, 0x3de0adaa, 
    0xbc49db97, 0x3dbb7a4c, 0x3cb0ec69, 0xbda0626c, 0xbe26cda2, 0xbe2c5ede, 0x3dd7385d, 0x3dc25a67, 
    0x3e1bb4da, 0x3e20dc64, 0xbe09faae, 0xbacc177e, 0x3ddcae8b, 0xbe34253c, 0xbe0a208b, 0xbdb377aa, 
    0x3e3b3c16, 0xbd975eff, 0x3dbf0ebe, 0xbe77ccc6, 0x3c6ea8f0, 0xbc860d5f, 0x3e05f9e2, 0x3d24b645, 
    0x3ac92c50, 0x3db1934a, 0x3e032196, 0x3e1337f1, 0x3e1584f8, 0x3dbef0f1, 0x3dff89f5, 0x3e1c9ece, 
    0xbde4654b, 0x3d4f92fd, 0x3da751d0, 0x3d9873b1, 0xbe0459c9, 0xbde9f6e6, 0x3dfc1041, 0xbe10cd37, 
    0x3dae83d4, 0xbd9b94c5, 0xbadce60b, 0x3dd07239, 0x3dc0dfaf, 0x3de9ef2a, 0x3dc17405, 0x3d93a5fb, 
    0xbe2f1baa, 0x3cbe40b5, 0xbdd0debc, 0xbe1f61d7, 0x3d2db7b8, 0x3e0dbc12, 0x3cb968c9, 0x3dc0414b, 
    0x3c4ec991, 0x3da7e56d, 0x3cd2c897, 0xbe00d2ee, 0x3d4a4306, 0x3e421c05, 0xbd9c4c10, 0xbe10e9fb, 
    0xbe2af92b, 0x3e3836f0, 0x3e4cfad7, 0x3e094192, 0xbdce9b6d, 0xbe25ddeb, 0xbe2172e6, 0x3dcb5d17, 
    0x3e0f6b1e, 0x3d9638b7, 0x3e225a51, 0x3e3cd3f1, 0xbdbee641, 0xbd2fef3e, 0x3e02ecf2, 0xbe22d39c, 
    0x3db00426, 0x3ddf1612, 0xbdbb8385, 0xbd472d48, 0x3e14a8ea, 0xbe09ff39, 0x3e26a305, 0x3e489256, 
    0x3d99dd05, 0xbdddb93c, 0xbdc2ff1c, 0xbdd19eee, 0xbe239c83, 0x3de1bb7f, 0x3df2c620, 0x3ddea590, 
    0x3e2c9e16, 0x3c8ad7ed, 0xb9e1c6a1, 0xbded15a7, 0xbe2c5a5b, 0x3e064ae7, 0x3e2f91b1, 0x3e4f2c3e, 
    0xbb9f207e, 0x3e399b9b, 0xbd3fa0ff, 0x3c9a9af6, 0xbd62cbf8, 0xbcc9d1b8, 0xbe2b1f1c, 0xbe449bd0, 
    0xbe078e2e, 0xbdbe6662, 0x3daf1b6e, 0x3df390a0, 0xbd22e1c8, 0x3dd0857d, 0x3d583c4f, 0xbc5d9419, 
    0x3dacb5d5, 0x3d9f7abf, 0x3dedb469, 0x3da16f03, 0x3beaa2f7, 0x3e1131ac, 0xbe245f1e, 0xbe53f76f, 
    0xbd66e390, 0x3caf803a, 0x3ddbb270, 0x3d45fc4b, 0xbd8925ec, 0xbd4e35ff, 0xbcf954dc, 0x3deffd74, 
    0xbd0dc5ce, 0xbd803542, 0x3c1fd7d5, 0x3cbba905, 0x3d7f85e6, 0xbcf8e7ce, 0xbd84acf7, 0xbe3d804e, 
    0x3e09a3a3, 0xbe012119, 0x3d884a4e, 0x3c25c1ca, 0xbdabbe00, 0x3d58d6cd, 0xbe3c6b17, 0xbd188071, 
    0x3da2c772, 0xbd8d2f2b, 0x3d7ef323, 0x3e1f5463, 0x3d4ef1eb, 0x3dd1bc30, 0xbe1eea54, 0xbe051054, 
    0x3c5ddd6a, 0xbe2b63fe, 0xbb799bbc, 0x3e023957, 0x3e16f868, 0xbd7f6c80, 0x3dab37cc, 0x3e148e07, 
    0x3e4cdb8a, 0xbd9bae94, 0xbdee1325, 0xbe039fe4, 0x3dc49223, 0xbd44e8ea, 0xbe18d43d, 0x3e1e81e0, 
    0x3b92fc30, 0xbdbec483, 0xbc50c5cf, 0xbe45457a, 0xbe15189c, 0xbba2feba, 0xbda88c92, 0xbde7c612, 
    0x3e30bcac, 0xbd11a16d, 0xbe46639d, 0x3cfb6fea, 0xbe062309, 0xbe16452f, 0xbcfde84b, 0x3d0b6303, 
    0xbd95787c, 0x3b81b369, 0xbdcc7bc4, 0x3e2b73b5, 0x3d9ae4bb, 0x3cf21a32, 0x3e348f9e, 0xbda8170b, 
    0x3d478be0, 0x3db83990, 0x3e07cdb8, 0x3d6a916b, 0xbe17bcf7, 0x3c86595b, 0x3e024168, 0xbe3f98f7, 
    0xbd830456, 0xbd650f76, 0x3dac1e02, 0x3da9b634, 0xbdfa6ddf, 0xbc955f2a, 0x3dfd7e6a, 0xbe4a0c2c, 
    0x3e1eb839, 0x3e22dcfa, 0xbc73402b, 0x3a86e48b, 0x3dbab1be, 0xbd4ba483, 0xbe41d7cf, 0xbdd5a752, 
    0x3df253ad, 0xbda59679, 0x3e12c691, 0xbb6550ce, 0x3d495693, 0xbdd7bb06, 0x3e34e03a, 0x3db38c2d, 
    0x3e00b76d, 0xbd4b7ae8, 0x3e161622, 0x3ce528ba, 0x3e03484e, 0x3e1a9f66, 0x3c8a30ee, 0x3c9705cc, 
    0xbdc24aba, 0xbddbc2da, 0xbbf1cad7, 0x3d8c709b, 0x3cada0ac, 0x3c662660, 0xbdf9cc36, 0xbd3315b0, 
    0x3e01e997, 0xbe1e178b, 0x3dee903c, 0xbdc954db, 0xbdc6b24d, 0xbd86f2ac, 0x3b49ab9e, 0x3da52240, 
    0x3da7993e, 0x3e4ed2da, 0x3dfbc4d3, 0xbbc8514e, 0x3e3f4705, 0x3e2f7e47, 0x3ce691fd, 0x3daa6cae, 
    0xbd8d4f84, 0xbb954063, 0x3d854af8, 0xbd91e24a, 0xbb39a5b7, 0xbdde8858, 0xbdd1dca2, 0xbdfd0599, 
    0x3e0327af, 0xbdbe3a9c, 0xbe2267ed, 0xbda1403b, 0xbce88516, 0xbe1e5f72, 0xbcd0f10b, 0x3dd2f4f1, 
    0x3e049712, 0xbe05fa66, 0x3dd54656, 0xbe44d69d, 0x3e14f54f, 0xbd73c185, 0x3e24c72e, 0x3d0626f9, 
    0x3d07db6e, 0xbe43e57d, 0x3d56dfa0, 0xbdca8f6a, 0x3e810e80, 0xbd610125, 0x3de26413, 0x3e536f41, 
    0x3e2d1508, 0xbe326010, 0xbb48e2cf, 0x3cd8c5a3, 0xbde1bd54, 0xbdaac72b, 0x3e2c1617, 0x3e3722e5, 
    0x3d5a32cb, 0x3d2f37bf, 0x3c6b2a36, 0xbd3535a1, 0xbd3f46fc, 0xbe0eb95d, 0x3ddcc48f, 0x3df6a3c5, 
    0xbdbf7926, 0x3c8815e7, 0xbda9b856, 0xbd5e8dbe, 0x3e148b22, 0xbd476736, 0xbd5a967d, 0xbe345a8e, 
    0x3d18ebac, 0xba85055c, 0xbdd52900, 0xbe1cc7dc, 0x3e0591c8, 0x3e3228b8, 0x3e1397ef, 0xbc9cc3a6, 
    0xbbbebf28, 0x3cd75f09, 0x3d26c4f6, 0x3e24e88a, 0x3da3c4aa, 0x3d1097bb, 0x3db0d3cc, 0x3e257682, 
    0xbd187b09, 0x3e19520f, 0x3de88d82, 0x3cac63ba, 0xba326206, 0x3dfa5e27, 0x3d23466e, 0x3e06b376, 
    0xbe09a994, 0x3b7fb937, 0xbe1c7360, 0x3d51be18, 0xbd820bf5, 0xbd6b4a20, 0xbd88c2c2, 0x3e23c634, 
    0x3d8a73d0, 0x3c93daad, 0x3d92693e, 0xbe34b3a8, 0xbdc8d41d, 0xbd8ac788, 0xbdb739df, 0xbcec5a9a, 
    0x3e3bdda6, 0x3e399cbc, 0xbe4041a3, 0x3e396968, 0xbe0e84a1, 0xbde99e11, 0x3e62e5c3, 0xbe12207b, 
    0xbde0b17a, 0x3e1c3f5e, 0x3e475c23, 0x3e416117, 0x3e0fc09f, 0x3e165bb3, 0xbe01d89c, 0xbcbfcdd9, 
    0x3daea787, 0x3bca3c5e, 0x3d000e41, 0xbddc3f13, 0xbe3b4d8b, 0xbd3aae3f, 0xbe1f5005, 0xbe0975e9, 
    0x3e4766be, 0x3e1dfdbb, 0xbd9ae10a, 0xbd8b03dc, 0xbdb31f43, 0x3e6c3fd0, 0x3e5fbd27, 0xbc4032a9, 
    0xbd067678, 0xbd5f34c2, 0x3e491db8, 0xbdb0da07, 0xbe08437c, 0x3e2da20a, 0x3e197c69, 0xbe2be38f, 
    0x3e0c5b81, 0x3de75d9e, 0xbcf66373, 0xbe263ff0, 0x3da45cd9, 0x3cb1d5f8, 0xbe144f19, 0x3b58a779, 
    0x3cdd2e85, 0xbd633d91, 0x3dec0513, 0x3d9849ea, 0x3dd6e56e, 0x3da5d4c8, 0x3d547785, 0x3d964c32, 
    0xbe4af6e4, 0xbceaa37d, 0xbd82d70a, 0xbddbc024, 0x3df0fd66, 0xbbcdf2a1, 0x3dd6ba97, 0x3dd74429, 
    0x3dcdcbf3, 0x3e2d0517, 0xbd70d4fb, 0x3e078370, 0x3dd26c58, 0x3d4160ca, 0x3e29ba9b, 0xbd997323, 
    0x3e61b81a, 0x3dab3915, 0xbdf67af2, 0xbd4fc116, 0xbe1fcb62, 0xbd94005a, 0xbe4169a5, 0x3d52fcae, 
    0x3e820ec1, 0x3dcf8429, 0x3e0b9206, 0xbdf6d4b2, 0xbe0014fd, 0x3d7efffe, 0xbe16b80b, 0xbe0d3f84, 
    0xbdbc4aa5, 0xbd55c904, 0xbe21d6d1, 0xbda0c693, 0x3dbe8510, 0xbca35076, 0x3c8a4b44, 0x3c80bd51, 
    0xbe79ae89, 0xbe23057f, 0x3daec24e, 0xbb4f7297, 0xbdb013a5, 0xbe5e7a85, 0xbe026d86, 0xbe25930f, 
    0xbcd17e66, 0x3e4c6f59, 0xbc99227d, 0xbd351216, 0xbdd4ce0d, 0xbd9fcc7c, 0x3d9fa3f0, 0xbd26406c, 
    0xbce4eb62, 0x3e2cfa28, 0xbd6b84c6, 0x3dcb4ad4, 0xbe2ddeb7, 0x3e045402, 0x3e49ba32, 0x3e03b2c3, 
    0x3ddbdf48, 0x3d87760c, 0x3e4245e0, 0xbdf24755, 0xba9e93e8, 0xbe0ce326, 0xbd8e6b45, 0x3e37160f, 
    0xbd952e52, 0xbda2624a, 0x3df6c878, 0xbcd3d7c9, 0x3e1ad4e1, 0xbe633551, 0x3df36b50, 0x3c18b220, 
    0xbb1e3cbb, 0x3c21fe88, 0x3e444a52, 0x3e3ca327, 0x3d76f6e1, 0xbe3170ed, 0x3c732b99, 0x3dd1db84, 
    0x3e2cfbb1, 0x3e5c3d62, 0x3d8356ef, 0x3cadd10e, 0x3d90a8fe, 0xbdcd1941, 0xbdfc3a07, 0x3e53c332, 
    0xbdd6742a, 0x3db3ecd2, 0xbda85bf7, 0x3e2a3c70, 0x3de0ab62, 0xbdbbec6b, 0x3e1ffe52, 0xbddfa793, 
    0xbd957ff4, 0xbe01d47f, 0xbe1c3278, 0xbd47fe6e, 0x3d4217b9, 0x3de635de, 0x3e04a1df, 0x3dfc9f20, 
    0xbd014711, 0x3e11fa95, 0xbddb04d3, 0xbd7626c9, 0xbdccc0ba, 0x3de7febb, 0x3c6f1f86, 0x3e38801a, 
    0x3d47440b, 0xbe390543, 0xbcd3bc82, 0x3da82824, 0x3d9bd77a, 0x3bef38cc, 0x3d8edad1, 0xbe065699, 
    0x3dc86781, 0xbe0a5e0d, 0x3dfcbc7b, 0xbc043039, 0x3e0aa299, 0x3cc6deda, 0xbe348006, 0x3e115a8a, 
    0xbd66313d, 0xbe5ce082, 0xbe260ba6, 0x3df77cb6, 0x3d4a7661, 0xbdaac6d0, 0x3d992593, 0x3dce89ce, 
    0xbe525a75, 0xbe456061, 0xbdaed4df, 0x3d89661c, 0x3dc7d6ad, 0x3db23e73, 0xbcc3fc19, 0xbe1ad424, 
    0x3d99e76a, 0x3d618059, 0x3e2d7b24, 0x3e68084f, 0xbc7695cc, 0x3b78eca5, 0x3ce27a9b, 0x3baa8783, 
    0xbc1624ed, 0x3e071e4a, 0x3d590d1a, 0x3e03a97e, 0xbc66d5b3, 0x3d070ba3, 0xbe3278ab, 0xbe63fcde, 
    0xbd8aef57, 0xbd93e63f, 0xbc9c3fe6, 0xbc05e246, 0x3e41dbab, 0x3d4cc84c, 0xbda40044, 0x3ddfed7e, 
    0xbced5f15, 0x3cedbe2c, 0xbd038320, 0xbd43eadb, 0x3dcea1d9, 0x3d0c7c64, 0x3df26b04, 0xbd97ce6b, 
    0x3b426625, 0xbd805ddd, 0x3dc5bef5, 0x3e022e82, 0x3e0a4cc2, 0x3dc63f93, 0x3e358187, 0x3c96cb17, 
    0xbd358b1a, 0x3e5a48d3, 0xbdb5ea7f, 0x3d88c0c6, 0x3e311cc6, 0xbdc2c64f, 0xbd455986, 0x3e558925, 
    0xbdfcd5f5, 0xbe100dd0, 0xbe878571, 0xbd166442, 0x3ddc546c, 0x3e65663b, 0x3c8f0c3b, 0x3e5ca4c1, 
    0xbdbab6d6, 0xbd7fb2dc, 0x3e4358bf, 0xbe12f7df, 0x3dcb274e, 0xbc4891c7, 0x3e08228b, 0xbe15fa9a, 
    0x3dbf801c, 0xbd67e852, 0x3c7af0cb, 0xbd953f34, 0xbd870708, 0xbd69e903, 0xbd34ae05, 0x3d87231b, 
    0xbcec3503, 0xbd251316, 0xbcbf89d1, 0xbe0fadc5, 0x3d734a15, 0xbcad3df5, 0x3e1b03ce, 0xbd153165, 
    0xbdb7cc9a, 0x3e318d44, 0xbe47824b, 0x3e355e71, 0x3dee5cd1, 0x3d942ddd, 0xbdca9da3, 0xbdd658de, 
    0x3e32287f, 0x3e9dcba0, 0xbd418e58, 0xbc2c397e, 0x3e3cc545, 0x3dbaa8da, 0xbe0e2903, 0x3cdfdb09, 
    0x3e26624c, 0xbd0a3b84, 0x3e63f497, 0xbd1f61a5, 0xbe50d5da, 0xbdb74a1c, 0x3cd228b8, 0xbdcb1d7d, 
    0xbd59947e, 0x3da73662, 0x3b6b9940, 0x3ca6cab1, 0xbdcedf5b, 0x3e095394, 0x3e191836, 0xb9b76412, 
    0xbd92ac06, 0x3d733bd8, 0xbe09e646, 0xbe146295, 0x3d8779f3, 0x3d9faa8f, 0x3d3a54cc, 0xbd2e073f, 
    0x3dabe5cf, 0x3d1dab7f, 0xbdd556aa, 0xbe45ac18, 0xbc67e9f6, 0x3d47defa, 0xbd8813ce, 0x3d49fe31, 
    0x3ddfee4e, 0xbcecc2e3, 0x3c8438f3, 0xbdd05148, 0xbe144d0c, 0x3e0fb2d5, 0xbdd35116, 0x3e383ea0, 
    0xbe1b97ab, 0xbe4245f0, 0xbdd3e7b2, 0xbe199a43, 0x3d16aca8, 0x3e22802e, 0xbc970954, 0x3db292e2, 
    0x3d252e4a, 0xbd8d348a, 0xbe11062e, 0xbccdbde3, 0x397b6065, 0x3d9dcd83, 0xbd00a974, 0xbd1867b6, 
    0x3d50d896, 0xbe039586, 0x3d966a1a, 0xbc947352, 0x3d5b0300, 0xbe1379ba, 0xbe270721, 0xbe1d0efd, 
    0x3e3c3920, 0x3dd1e2bf, 0xbd209cae, 0x3de913c5, 0x3de56e49, 0x3ccfa8a4, 0x3df498ee, 0xbd73c335, 
    0x3e3734e8, 0xbdd7b8c3, 0x3d9822bb, 0xbdc2a813, 0xbe3629f6, 0x3d938ea9, 0xbdae826c, 0xbd96ead0, 
    0xbe094a32, 0x3e4257de, 0xbe27de7a, 0x3d9473e0, 0xbe5a80f5, 0xbda290cc, 0x3ca1ac16, 0xbce27de4, 
    0x3d582846, 0x3e113ae3, 0xbd5ed468, 0x3e14746e, 0xbd10252b, 0x3dbab603, 0x3dcab5ca, 0x3e2bba96, 
    0xbe28152b, 0xbd98f2a5, 0x3e0ebea4, 0x3d5259f5, 0x3db2cc0d, 0x3de88f1a, 0xbe40a983, 0xbd8ca352, 
    0x3d956b8d, 0x3b950e4a, 0x3deb0280, 0xbdda406c, 0xbcf0ace7, 0xbe136188, 0xbd462453, 0x3e4ec100, 
    0xbd220026, 0x3da04ef2, 0xbdeeadb0, 0x3e025d2d, 0xbc8139b8, 0x3e5627d1, 0x3ccacd95, 0x3da70c6e, 
    0xbd3a2f20, 0xbc82650b, 0xbd02a51f, 0x3e03b291, 0x3d84a418, 0x3db0c758, 0x3d4c6263, 0xbe23b208, 
    0x3e1a646c, 0xbdc4c692, 0xbd80f960, 0x3e26a7ec, 0xbdc6caff, 0x3e11fb6d, 0xbdb99964, 0x3d5e0377, 
    0xbe10119e, 0x3c1fae85, 0x3d845e33, 0x3d4215cf, 0x3e0beba0, 0x3e350069, 0xbce8d757, 0xbe2d2694, 
    0xbd2d0cd7, 0x3dd8b213, 0xbe2288f3, 0xbd9d8340, 0xbdfa48a9, 0x3ddf5540, 0x3cc56f8b, 0xbd9f8653, 
    0xbe248442, 0xbca7be8d, 0xbe8c9df2, 0x3e12bce7, 0xbe547503, 0x3dd3f190, 0x3e4b3af5, 0xbcfd453f, 
    0xbdda1b87, 0xbe1916f5, 0xbc26aa41, 0xbd4e061d, 0x3e163759, 0x3db9b1f4, 0x3ce842ba, 0x3e27ab30, 
    0x3c3e0e80, 0xbe517bde, 0xbd0866f7, 0x3d96b254, 0xbdbd8321, 0x3cb14527, 0x3df1e348, 0x3d1e560d, 
    0xbe687e4e, 0x3c83225c, 0xbe31d68a, 0x3e20646e, 0xbe584c53, 0x3b6dac29, 0x3cffa5a9, 0xbe7a33bc, 
    0xbd9652fa, 0xbbd908d5, 0xbcd11daa, 0xbde75266, 0xbd7aae19, 0xbdf82eca, 0xbe1f3835, 0x3cd3004a, 
    0xbd4d16e7, 0xbdfb5e4d, 0x3e36fa38, 0xbc3abdbb, 0x3d055fb5, 0xbde47c65, 0x3e4fd5b5, 0xbdaa146f, 
    0xbe8678b3, 0x3d32288c, 0x3d0e66f3, 0x3dbb4a59, 0x3e228f06, 0xbdbe5057, 0xbdbdd76e, 0x3dc17959, 
    0xbe559dc3, 0xbd5eedb4, 0x3e017398, 0xbe1f5972, 0x3c13b044, 0x3e020f13, 0x3e52502c, 0xbe425daa, 
    0xbe5ce2a2, 0x3c8d7b7d, 0x3d1af47d, 0x3ca288de, 0x3d573b06, 0x3e29e1fb, 0xbe5b55b4, 0xbe287a6a, 
    0xbe4edde3, 0x3e3b50fb, 0x3dc6ab35, 0x3dc5507a, 0x3cee39a2, 0xbe2cb477, 0x3db75f8e, 0xbdd71d8f, 
    0xbdcecd52, 0xbdc73919, 0x3dad74a7, 0x3dd72c83, 0x3da50367, 0xbe2f9f24, 0xbd993470, 0x3e24a053, 
    0xbdc669ce, 0xbda9c68c, 0xbdace501, 0x3d9b99fc, 0x3e0514cb, 0x3d4be21a, 0x3e27ba41, 0xbde9a5c8, 
    0x3d196a7b, 0xbdf0a9c8, 0xbe31ae7a, 0x3e39626f, 0x3e3583ba, 0xbe19dae8, 0xbe10fa57, 0xbe0d9da3, 
    0xbe6481b9, 0x3df91c97, 0xba16b0a1, 0x3c718e1f, 0xbe0ce38c, 0x3e0f1fd7, 0xbd4638f3, 0x3cda3b07, 
    0x3d82dacd, 0x3d929b84, 0xbce60d03, 0xbc566eb4, 0xbdd494dd, 0xbd847e49, 0x3d98532b, 0x3e650ae5, 
    0xbd900d74, 0xbc8eb11d, 0x3e595b07, 0xbd94b88c, 0xbda6d115, 0xbdbcc8d7, 0x3e84c843, 0xbe1141ab, 
    0x3e088a81, 0xbc193898, 0x3db20ebd, 0xbe242a8a, 0x3d21f8e7, 0xbe611812, 0x3d3aac13, 0xbe52187c, 
    0x3bb1d4ca, 0x3c45c15a, 0xbe1187ce, 0xbe2697f4, 0xbdccc1b6, 0x3dfde7fc, 0xbdd42289, 0x3d917796, 
    0xbe457de7, 0x3db1649d, 0xbdc318fa, 0xbdb5e123, 0x3e55dfd0, 0x3e206807, 0x3db8e0fc, 0xbdf24f42, 
    0x3d9ca690, 0xbd02c699, 0xbda65c28, 0x3df8a701, 0xbdbcfd59, 0xbdac298d, 0xbc99e9bc, 0x3de22c3e, 
    0xbe245f9c, 0x3e0725e6, 0xbe1dab04, 0xbc77a22c, 0x3e0d32f2, 0x3dc0af7b, 0x3d797b80, 0xbe072663, 
    0xbe3b7336, 0x3c95a768, 0x3e6a5d11, 0xbe1cdfbd, 0xbccfcded, 0x3d9378e5, 0x3e5d7a4d, 0xbe149a00, 
    0x3e5e4175, 0xbda3d323, 0x3ca5b608, 0xbe4de52c, 0xbe767281, 0x3e10ddcc, 0xbce24c47, 0x3e3ea63e, 
    0x3ded8b2e, 0x3d444a09, 0x3dc2bee7, 0x3de635c2, 0x3e0f6109, 0x3d92e320, 0xbda8ada8, 0x3d53848f, 
    0x3d726d14, 0x3deaf63a, 0xbdc482cb, 0xbe49130f, 0xbc476d5e, 0xbde400ed, 0x3d2c0566, 0xbd9cc623, 
    0xbe6499ba, 0xbe36490d, 0xbcc2ad65, 0x3dd0da6b, 0x3d09b803, 0x3dd214b4, 0xbdb2dd03, 0x3e0d6153, 
    0xbda3a14c, 0x3dbb8f88, 0x3d72dca4, 0xbe623f53, 0xbd24f7ef, 0xbe23dded, 0xbd29585e, 0xbd1adcae, 
    0x3df37bee, 0xbe166bcb, 0xbe214461, 0x3d837372, 0xbdf9037d, 0x3c061955, 0xbc0d5dfa, 0x3e1974de, 
    0xbd97f7ea, 0xbc0817ef, 0xbe35fa4f, 0x3d44b9fc, 0xbe360fcc, 0xbe6057cb, 0xbe21d733, 0x3e1bfda1, 
    0x3e06a932, 0xbae2583d, 0x3dffe242, 0x3e29fc97, 0x3da5d22b, 0x3e0f99ee, 0x3c837481, 0xbe64edf9, 
    0x3bf13860, 0x3de3cbcd, 0xbd81d8f0, 0x3e211f27, 0x3d8a6e9a, 0xbe40e32c, 0x3d8af725, 0x3cffa813, 
    0x3c22e3e8, 0xbcfc6ac4, 0xbdbfb9eb, 0x3d02a003, 0x3de0ca5e, 0x3e1bf45c, 0x3e06a67a, 0xbdba9afd, 
    0xbd67fdac, 0xbe2959bb, 0x3dff1080, 0x3df72fb4, 0x3d47edbc, 0xbdc24d3d, 0x3d1496c9, 0x3e0b7417, 
    0x3d4da1e1, 0x3d967a38, 0xbb1cf0e2, 0x3c0ad327, 0x3e218194, 0xbd8a7381, 0xbd0bf307, 0x3d6422a6, 
    0x3d07c7c4, 0x3e3bc48a, 0xbe454820, 0xbafd9c36, 0x3e1e5121, 0xbe1cc51e, 0x3d711c15, 0x3ddeb5ef, 
    0xbe242182, 0x3deb7031, 0xbe00be0b, 0xbd936b99, 0xbcc287c9, 0x3bc244cd, 0xbdef4a0b, 0xbd85b96a, 
    0x3d99ec58, 0xbd78d3aa, 0x3e0daa7b, 0x3e496a95, 0x3d6a8cdb, 0xbda67abb, 0xbda7b36c, 0x3e100d68, 
    0x3dc6e7bb, 0xbe2222e3, 0xbcf3f2a5, 0x3e2e1d08, 0xbe2ed46b, 0x3e67c9aa, 0xbdf380a4, 0x3d80313d, 
    0x3cc2428f, 0xbded6d67, 0xbdc4913d, 0x3e04c6a9, 0xbcf73490, 0xbe157379, 0xbd86a085, 0x3e312b3c, 
    0x3db8f4c1, 0xbd186291, 0xbd11d831, 0xbde01b5a, 0xbd92386e, 0x3ca105e0, 0xbe08f542, 0xffffb796, 
    0x00000004, 0x00000010, 0x00000001, 0x0000000c, 0x00000001, 0x00000010, 0xffffb7b2, 0x00000004, 
    0x00000010, 0x00000001, 0x00000001, 0x00000006, 0x00000010, 0xffffb7ce, 0x00000004, 0x00000010, 
    0x00000001, 0x00000006, 0x00000001, 0x00000020, 0xffffb7ea, 0x00000004, 0x0000000c, 0x00000001, 
    0x00000003, 0x00000020, 0xffffb802, 0x00000004, 0x00000034, 0xbc6f593b, 0xbd381cf9, 0x3d02c2c4, 
    0xbd1dffd0, 0x3d7a4e63, 0x3c8c0c27, 0xbd069cbc, 0xbcf6276a, 0xbd2e7f43, 0xbd1ef30b, 0xbca65541, 
    0x3c0980fd, 0xbc2abaa0, 0xffffb842, 0x00000004, 0x000009c0, 0xbdcec530, 0x3e456fae, 0xbc5fafe4, 
    0x3ca68073, 0xbd3722d8, 0xbd753a16, 0x3c60e841, 0x3e4ed213, 0xbd38fb86, 0x3e15f4b1, 0xbdd26b0e, 
    0xbd7f86e5, 0x3e02fa00, 0x3dffa40d, 0x3d90f4fe, 0xbe023608, 0xbda4bcbe, 0xbdd3467e, 0xbdb38ced, 
    0x3e00e3ba, 0x3e1ca5df, 0x3dbb0242, 0x3b39db0b, 0x3d66b004, 0x3cbd1166, 0x3e4f06fb, 0xbd5ebb4b, 
    0xbd9417ce, 0x3e2f1061, 0x3e1ce9c6, 0xbce14e03, 0x3d8b2d4e, 0xbe14f114, 0xbbb84df6, 0x3dbafca3, 
    0x3e1b894c, 0xbd59b9ef, 0xbe2cccc6, 0x3c0e2ee2, 0x3c89d151, 0xbd6ffd74, 0xbe09b073, 0xbdf50fbd, 
    0xbe0dfa62, 0x3d037c08, 0xbc10e575, 0xbd7182f0, 0xbe101ec9, 0xbdfcd3e7, 0xbdc83fd4, 0xbd6d608b, 
    0xbd32d749, 0xbdcbe049, 0xbe148bac, 0xbdbf7bba, 0x3def7fdf, 0xbc5a6f8d, 0xbc96d06b, 0x3d3d19e4, 
    0xbdc573d1, 0x3d9cae0c, 0x3cb15d89, 0xbdc7eb27, 0xbda259ce, 0x3e08e22d, 0x3e48e7ac, 0x3df0d3bc, 
    0xbdf66bf3, 0x3dfd5b67, 0xbe21bc41, 0xbda3a3bf, 0x3dc90fbb, 0xbdaca8e8, 0x3e0adefb, 0x3d166a09, 
    0xbcc2fe36, 0xbbf8000c, 0xbbba1bcb, 0x3c9b6d71, 0xbd4e3ab1, 0xbe7b4684, 0xbe3eac7a, 0xbe257d99, 
    0x3d9fd2a1, 0x3de4b763, 0xbc960d52, 0x3e511890, 0x3e3e29eb, 0x3e808c44, 0xbb9c12d4, 0xbe30deb6, 
    0xbe8ab6dc, 0xbc1fdf57, 0x3e49b1c4, 0xbe81dc8c, 0x3e27d063, 0x3b1dfb99, 0x3e0993a7, 0xbe5a0d72, 
    0xbdf16dcb, 0x3e212d20, 0x3e3bd9a5, 0x3e65c00b, 0x3df3aca1, 0x3db82917, 0x3e560cd8, 0xbe5408b9, 
    0x3ca4ca4c, 0x3e42eed1, 0x3e3c9e7a, 0x3dc17b14, 0x3e62f3c1, 0x3e5a8c50, 0xbe3478fa, 0xbdaf1532, 
    0x3e88f9da, 0x3e835d3f, 0x3e0d6104, 0xbe707cf1, 0xbe80f56d, 0xbdb42b7b, 0xbdd50acb, 0x3d8808ea, 
    0x3e919af2, 0xbe8ed5bc, 0xbe710213, 0xbd0f8235, 0x3e122dee, 0x3e3b0892, 0xbdee1ed9, 0x3e684c9a, 
    0x3e02ee47, 0x3e0285f4, 0x3e3bd0eb, 0xbd2a4e49, 0xbe60d83d, 0xbd65f277, 0xbce9dd44, 0xbe331d3f, 
    0xbe82eebe, 0x3dd7e75e, 0x3d4bf0e1, 0x3d009062, 0xbe659e69, 0x3e221b40, 0x3dbaef9b, 0xbe51ddaf, 
    0xbdfc8e13, 0xbe6e7d3c, 0xbe7e038a, 0x3e61e0d4, 0xbe1945f8, 0xbdc93e43, 0xbc026054, 0xbd56103c, 
    0xbbc33733, 0x3db022fb, 0xbdd93258, 0x3e55debe, 0x3c9f5c58, 0xbb993a20, 0xbdfa9f47, 0xbe0a0396, 
    0x3c49d28e, 0xbd8baaa7, 0xbe188e2d, 0xbe0812f5, 0x3deb370b, 0xbe5057c7, 0x3d5ddb7f, 0xbdd11ca4, 
    0xbda227e3, 0x3c16db85, 0x3de655f8, 0xbe23b334, 0x3bde803d, 0x3c8b99cc, 0xbd84a80e, 0x3c4980db, 
    0xbe0b2b08, 0x3c9bf8d5, 0x3e406095, 0x3e04e4da, 0xbdff9803, 0x3e4ae9c7, 0xbe4b6787, 0x3c9f84df, 
    0xbdd684aa, 0x3e253bbe, 0x3e12f06a, 0xbe085d27, 0x3d1070f3, 0x3d5d8b6b, 0xbd5bbf90, 0x3cf5a970, 
    0xbde6a32c, 0xbd1ca35a, 0x3d95afd2, 0x3d32c960, 0xbce97c23, 0xbdbc969d, 0xbe155294, 0x3e45dc48, 
    0xbd1f2b5c, 0xbd2b1298, 0x3ce7dbec, 0xbce08128, 0xbde0d84c, 0x3d1ab2aa, 0x3e211f42, 0xbe0c0141, 
    0xbd9fcdff, 0x3db94b67, 0x3e095b20, 0xbe0d9475, 0x3d8ad580, 0x3ddeed3a, 0xbd1f2bec, 0x3dde76f7, 
    0x3d474f98, 0xbe095a5a, 0xbcb16965, 0xbd0392fe, 0x3dde4b1d, 0xbe040c6e, 0x3df55665, 0xbd81009c, 
    0x3cdd6aff, 0x3e1e4e74, 0x3de51b6b, 0x3e0c5deb, 0x3db603d6, 0xbdc323c0, 0xbe139a6f, 0x3eb0e8ff, 
    0x3e892be7, 0x3e97c7e0, 0x3e8c603b, 0x3da2aab1, 0x3d11e323, 0xbe909a6e, 0xbd12b292, 0xbdeb0029, 
    0xbd7829de, 0x3e9039a7, 0xbe8b08ac, 0xbe44f123, 0xbdefe8bd, 0xbe8b478e, 0x3e8fac7a, 0xbd9b7abc, 
    0x3da57a25, 0xbe2fbbd5, 0xbd9d4181, 0x3e736d3b, 0xbb1e3156, 0x3e120674, 0xbd037099, 0xbe8985c7, 
    0x3dac96e8, 0xbdab5df6, 0x3ccf1cb9, 0xbe35346e, 0x3d417c5a, 0x3e45bc60, 0x3e0f56a1, 0xbcbcc381, 
    0x3e6d8d2c, 0xbd7251d9, 0x3e80d3e9, 0x3e1cabe6, 0x3c11beed, 0x3d1ad33f, 0x3e72ce88, 0x3ccde6de, 
    0x3e90574b, 0x3e7c9b43, 0xbd44aa6c, 0xbe5e0ba4, 0x3e0848bc, 0x3de7cc7b, 0x3de79555, 0x3dc37fcf, 
    0xbd8eb422, 0xbd0126f1, 0x3d4b5485, 0x3d28071b, 0xbc8c43b3, 0x3defe553, 0x3e12799a, 0x3e7acb48, 
    0x3d95536c, 0x3e28a321, 0x3e80ae26, 0xbe298cd8, 0x3d899083, 0x3d6f1b9e, 0xbe98948f, 0xbcf7e67e, 
    0x3ddd84a0, 0x3e2f2bd1, 0x3e1e8392, 0x3daa9f4a, 0x3e6cf4d0, 0xbc85728f, 0xbe8317d4, 0xbd17fd9b, 
    0x3d1451d9, 0x3e223b7b, 0x3e1d203a, 0xbd98d792, 0x3c31e7d5, 0x3e1143d5, 0x3d4f3930, 0xbdcf229c, 
    0x3e18bcfa, 0x3d94d206, 0x3d2da825, 0xbe1ae091, 0xbddd55a3, 0xbd41d6f0, 0xbb8cb2af, 0x3e01d774, 
    0xbc2fe414, 0xbe19e0a1, 0xbd27a65e, 0x3e238394, 0xbde0560f, 0x3dfbe01b, 0xbda8189b, 0x3d36e5f8, 
    0x3d41b586, 0xbb516ff0, 0x3d41c835, 0x3d7cf9ee, 0x3e01cc8d, 0xbd8874cf, 0x3e0954c0, 0xbbb5bec2, 
    0xbd896560, 0x3d00a885, 0x3d21d30c, 0xbc96f407, 0x3dfc3cc3, 0x3dd0f42f, 0xbe37df24, 0x3d306ef8, 
    0xbcb2d483, 0x3e282284, 0xbe28bb1a, 0x3da0e7af, 0x3df7a954, 0xbd6792c2, 0xbe1cd9b3, 0xbd1b0455, 
    0x3e0268e6, 0x3c9a07d4, 0xbd3b6a81, 0x3d553034, 0x3d9ab6e2, 0xbd9233c7, 0x3e051af6, 0x3e044f7d, 
    0x3d8be138, 0xbca9b9f1, 0x3da49f0c, 0x3c2231c8, 0x3e0e61f3, 0x3c9ae0c9, 0x3cf331f0, 0x3db7d947, 
    0xbd2b4d02, 0xbc850cef, 0xbc8fa2da, 0xbd9afa15, 0x3dfeec2e, 0x3e0b03c2, 0x3c684692, 0xbdae4e6d, 
    0xbde45c2a, 0x3c451777, 0x3e1f4291, 0xbc98dab7, 0xbcfab428, 0xbd258e93, 0xbd44ee77, 0x3d94d899, 
    0xbdd71c3e, 0x3dc0f881, 0x3caa3469, 0xbde3a87f, 0x3e92068b, 0x3d9b3500, 0x3e1cd758, 0x3e089c74, 
    0x3e16eb92, 0x3e1f0004, 0x3e817518, 0x3e50bb79, 0x3d94ca64, 0x3d11fcc0, 0xbe24bb1a, 0xbe5741b3, 
    0xbda02b0c, 0x3e944282, 0x3cfe48c0, 0x3ded46ca, 0x3e7af8ab, 0x3d8e92ba, 0x3df721d8, 0x3e310e80, 
    0xbdd4ccbb, 0xbc5627f5, 0x3dba5843, 0xbe87b2fe, 0xbd960a43, 0x3deef81a, 0x3e89fde9, 0x3dee7a7d, 
    0xbe7a346a, 0xbe8e90b1, 0xbe09c365, 0xbd87c226, 0x3d4e2c6e, 0x3dd81578, 0x3e015d4a, 0x3dd366b5, 
    0xbe6cad41, 0x3dcc13a3, 0xbdecf451, 0xbe1b1cbb, 0xbe0311c0, 0xbde735a5, 0x3e439c94, 0xbe12c014, 
    0x3e5f1a12, 0xbe209baa, 0x3e158f97, 0x3e3cefb3, 0x3d8fc6ac, 0xbdc5b7f8, 0x3e802684, 0xbe3ff5b2, 
    0x3d5293b9, 0xbd4eb4ee, 0x3d0da703, 0x3df0bd64, 0x3e66d515, 0x3e563c1c, 0x3e947afd, 0xbe01c9ef, 
    0x3db3db20, 0x3e148fe0, 0xbe8ffedf, 0x3e5db376, 0xbd915a93, 0xbe50cfa4, 0x3d56cb8a, 0xbda16325, 
    0x3e4f93ff, 0x3e11c831, 0xbe86dfce, 0xbdcf7342, 0xbe3e894c, 0x3dce76fa, 0x3e6b7515, 0x3e3d9ed4, 
    0xbd64d3df, 0x3c8200b5, 0xbe4c6d35, 0xbc588713, 0x3d1b9830, 0x3d255912, 0xbe4dce34, 0xbc050978, 
    0x3dc31304, 0xbe85a1aa, 0xbc41510d, 0xbe16fe50, 0x3e24669d, 0xbe1ac503, 0x3b95c21d, 0x3e516928, 
    0x3e4327cc, 0x3bb2c9e9, 0xbe5aff62, 0xbbffa626, 0x3daed8f3, 0x3ddfabf9, 0xbcb59a76, 0x3e8906cc, 
    0x3da8825b, 0xbdf9ff45, 0x3e42d3b9, 0x3e3240dc, 0xbe0f302e, 0xbd3c4267, 0x3db7b9e4, 0x3dd68e49, 
    0x3e4e9b68, 0x3e69ee95, 0x3e81c9a5, 0x3e551e02, 0x3d7204e0, 0xbb22b3f6, 0x3e16f3a0, 0xbe04ac50, 
    0x3e4492f2, 0xbcef41d6, 0x3e2dacdd, 0x3c619187, 0xbdcadc3b, 0x3d048f37, 0x3d4092c0, 0x3e06b6d0, 
    0x3b8f6c8b, 0xbc4c361a, 0x3d3ab783, 0xbd977894, 0xbbcb100a, 0xbd538bd4, 0x3dccfb0a, 0x3d821e06, 
    0x3e80433e, 0x3d492877, 0xbd57a7c8, 0x3dc5b21d, 0x3dbaccea, 0xbe29ca8c, 0x3d9a1547, 0xbd44f7ce, 
    0xbd989059, 0x3d9b1ec9, 0x3dbf22d3, 0x3cf7243d, 0xbcd42d1d, 0x3e35fe51, 0xbd1d194c, 0x3d0ba8fd, 
    0x3dca0af6, 0x3e2d6767, 0x3e1589a1, 0xbdcb47d0, 0x3dfdb0a2, 0x3e1cfde3, 0x3dffaa46, 0xbe504d6d, 
    0x3cf320fc, 0xbd575c42, 0x3d4bd9b5, 0xbdea294d, 0xbddd880c, 0x3e3a3c38, 0xbdee61db, 0xbdefa88c, 
    0x3d583496, 0xbb86fea6, 0xbe31b4a4, 0x3e1a1df9, 0x3d83b1ca, 0xbd664773, 0xbc295222, 0x3e4597d4, 
    0xbe1a6ebd, 0xbe33ecf0, 0xbdd6e060, 0x3e6a2e10, 0x3da69288, 0x3ba9be4b, 0xbdde147f, 0x3cfa82c6, 
    0x3e4735ae, 0xbca6056b, 0x3e4cb94a, 0x3dda0cc2, 0xbe04e1ca, 0x3d6b3f04, 0xbe1f79d2, 0x3dcf82ca, 
    0x3dd9236f, 0xbd92c86a, 0x3d45dfe4, 0x3dce7f5c, 0x3e02846a, 0x3b443b85, 0x3e82a17c, 0x3e33759e, 
    0x3ce721c1, 0xbd4a274a, 0x3d6b6d9c, 0xbe1613ea, 0xbe3f0262, 0x3e04a4f7, 0x3c8de901, 0x3d4f489b, 
    0x3bfd6876, 0x3e5f10c9, 0x3e0a2344, 0xbe81c1c4, 0x3e4c5517, 0x3e95bea5, 0x3d9e450b, 0x3e681280, 
    0xbdc29a2c, 0xbdb5f66b, 0x3e5b6c11, 0x3e476c91, 0x3e01d4f3, 0x3c9cebcb, 0x3d490a48, 0x3e13c591, 
    0xbe158825, 0xbdcf997d, 0x3c54ce71, 0x3d335a46, 0x3dd310df, 0xbe339066, 0x3e03de7f, 0x3e217627, 
    0x3df8bac7, 0x3c45d8f3, 0xbe24437a, 0x3c8dcaef, 0xbd89958f, 0xffffc20e, 0x00000004, 0x00000c00, 
    0x3e774b4c, 0x3f074834, 0xbf4a72cd, 0xbec10098, 0xbf4084f3, 0x3e8386b4, 0xbe577658, 0xbe87cb6f, 
    0x3e117caf, 0xbe8548d0, 0xbec1a750, 0xbed95770, 0x3ee02133, 0xbeed3e92, 0x3e0a3de9, 0xbe34ada9, 
    0x3f04ee68, 0x3e779642, 0x3f148f06, 0x3f1e8c43, 0xbf63c312, 0xbe076830, 0xbef8a1c9, 0xbf11983f, 
    0xbe88dd55, 0xbeb758d2, 0x3efd0aac, 0x3f168bb6, 0xbee14c3f, 0x3edabee2, 0xbf0e5494, 0x3e23884f, 
    0xbf397087, 0x3eff6b79, 0xbf055dd9, 0xbf401fcd, 0xbeeff5b4, 0x3e28da15, 0x3f270e03, 0x3f36b562, 
    0x3cad93f0, 0xbeb8cb1f, 0x3f05e956, 0xbdeedf96, 0x3daeb80f, 0x3ef095b8, 0xbf4563fc, 0x3e855176, 
    0xbec2726f, 0xbe7daa28, 0x3e8ee72a, 0x3ee036fd, 0x3eb46dd0, 0x3e6d0a0e, 0x3e603795, 0x3d774a1f, 
    0x3f0da62e, 0x3e16a0d9, 0x3e43ecee, 0x3ead11da, 0x3ec2964c, 0x3e99e85f, 0x3e003c8e, 0x3e48b0bf, 
    0x3e4054e7, 0xbd747288, 0xbf17d555, 0x3f13a3d5, 0xbe5f61fb, 0xbd34a18d, 0xbe9c915c, 0x3e030bc5, 
    0xbd186f36, 0xbc9d4af1, 0xb98f04e9, 0x3e44449c, 0x3ea498df, 0x3d07e57b, 0x3ee01ca2, 0x3ee99059, 
    0x3dff4a4c, 0x3dee6a30, 0xbe6b460a, 0xbe0849ac, 0x3f065ed8, 0xbdc6148e, 0xbe9b3d17, 0x3d48c65d, 
    0x3e033d17, 0xbe7e2e0c, 0xbe26e48d, 0xbe965dc0, 0xbe37729f, 0xbf12f205, 0xbe99611c, 0x3ece89d9, 
    0xbed2fb03, 0xbef60497, 0x3dbb0976, 0xbec55e75, 0x3d2d808b, 0xbdde39d9, 0x3eefd46c, 0x3eaa939d, 
    0xbe47b70e, 0xbeb66058, 0xbec92485, 0xbeebd01d, 0xbd6b1029, 0x3d4f740d, 0xbddc005f, 0xbe7524e2, 
    0xbe83f84b, 0xbe64b77a, 0xbe8475b5, 0x3dfec103, 0xbeb9673b, 0x3d1e7279, 0x3d98ef6a, 0x3ec5862e, 
    0x3e9fcbc6, 0x3e5076fc, 0xbe185fd2, 0x3e7692bd, 0x3e81f98d, 0xbf068ab3, 0x3f03a84f, 0x3ed348fd, 
    0xbec656a7, 0xbebc5443, 0x3e9100db, 0x3ec1f33c, 0x3e154ca6, 0xbe286401, 0xbe3fac49, 0x3c602010, 
    0x3ef11381, 0x3e01461b, 0x3d9ddb95, 0x3e2235eb, 0x3e990566, 0x3ede320b, 0xbe945097, 0x3e8cf2d0, 
    0x3f0fe95e, 0xbf36694c, 0x3f1ecd48, 0x3dfdc03a, 0x3c4c42e4, 0x3f197f09, 0x3e5c45f1, 0xbec76d45, 
    0x3f018501, 0x3d9ed8c0, 0xbe867439, 0xbe0bdf49, 0x3ea1bde5, 0x3eab9dcd, 0x3ed2bf4a, 0xbe0a2815, 
    0x3ec2f4ab, 0xbe0f7072, 0xbe92fd79, 0x3e3fd7f4, 0xbefaa319, 0x3e3a3589, 0xbf15c614, 0xbecfbd4c, 
    0xbe2f4c9e, 0x3e47e08c, 0xbeb038fe, 0x3c5573bb, 0x3f0e624c, 0xbd6188d7, 0xbdad875c, 0x3ecef108, 
    0xbd71020a, 0xbf142f5b, 0x3f342fbd, 0x3ecae26c, 0x3ed02ae3, 0x3f30f98b, 0xbe28f6de, 0x3f0e32bb, 
    0xbf096655, 0xbf181207, 0x3c4237f8, 0x3f251053, 0xbf055955, 0x3e5e489a, 0x3ec6f683, 0xbf0037cb, 
    0xbd946b77, 0xbda61f11, 0xbe5e1dc7, 0x3e445bc2, 0xbeaab1ea, 0x3e8138f2, 0x3efadf34, 0xbd4ede33, 
    0xbe5fbd80, 0x3f12b206, 0xbebae434, 0x3ea2f341, 0x3d75e4cb, 0x3e057f9f, 0x3e2c08bc, 0xbefb552b, 
    0x3ed1f625, 0x3ece0f6f, 0x3eda721d, 0x3ef1db9e, 0xbea51177, 0x3f018da2, 0xbf0512a0, 0xbf0bb1e8, 
    0x3ebdbdba, 0x3ebcc752, 0xbe38d639, 0xbee778f3, 0xbede9e2a, 0x3e7b6c56, 0x3d997a41, 0x3e29b66a, 
    0x3ece31aa, 0x3e90efc5, 0xbe3def45, 0xbec30079, 0x3eccdc74, 0x3e9f0491, 0xbcced080, 0xbe975ea7, 
    0xbcf93533, 0x3e08439f, 0x3ed7efc7, 0xbd77b13a, 0x3d1e71c9, 0x3e8d2866, 0x3ee2f392, 0xbde5aa52, 
    0xbe0ea20c, 0xbd90a1c4, 0xbe166637, 0x3f16d684, 0x3ee2cddf, 0xbf212056, 0x3de51339, 0x3e3a893a, 
    0xbcedd4b7, 0xbdbf5369, 0xbe22856c, 0x3ecbce9c, 0xbe929d39, 0x3e47d531, 0x3f2d153d, 0xbeff0269, 
    0x3e744d9c, 0xbeb821c4, 0xbec13e69, 0xbea9e57f, 0xbe4019ba, 0xbd4f867e, 0xbf03abf9, 0x3d9553dd, 
    0xbeb07472, 0x3e976f9a, 0xbe561753, 0x3d17a47a, 0xbef255cd, 0x3e7ddbb4, 0xbf2d17f5, 0x3e4ffbe8, 
    0x3f2820d0, 0x3f08daf6, 0xbf240c7e, 0xbed19b13, 0xbef159b9, 0x3e8ef290, 0xbe9dd31d, 0xbea10b6c, 
    0xbd424835, 0x3e3630fc, 0x3e2c178b, 0x3f2a3ae3, 0xbeedda97, 0xbe34356a, 0x3d2ac453, 0xbec6a3cd, 
    0xbee01e05, 0x3d67392e, 0x3dc90804, 0xbe994bc4, 0xbec63a74, 0xbe86e6a1, 0x3e7a37b8, 0x3eb97101, 
    0x3e37bf45, 0xbe0777d1, 0x3ec8a0e2, 0x3e653af5, 0x3e340e04, 0xbe1e05f7, 0x3d88f171, 0x3f0fcd33, 
    0xbe828b39, 0x3ea28abe, 0xbe0b70c7, 0xbea84127, 0x3e003371, 0xbef591dc, 0x3e8b70bd, 0x3eb3698c, 
    0xbeab9189, 0x3e015368, 0xbe10ec5a, 0xbe6cc272, 0xbd0c86ca, 0x3eb5efee, 0xbe636cd7, 0x3e5b72f1, 
    0xbeb5c0c0, 0x3ed7de87, 0x3dc442ed, 0xbefa2b25, 0x3c14feb9, 0x3de3eaf6, 0x3e255c80, 0x3f0a8a76, 
    0x3ec07bb6, 0x3db5eb5b, 0xbe12a2b2, 0x3e763a06, 0x3dea722f, 0xbf1ea918, 0x3f0cd6f0, 0x3dc3598b, 
    0xbbd6aba7, 0x3e946091, 0x3e721f45, 0xbe38049b, 0x3f006b12, 0x3e86fc6b, 0x3e13b8d1, 0xbda5206d, 
    0xbda93f51, 0x3dfc4f5b, 0xbeb57d63, 0xbe5ceadf, 0x3e329456, 0xbcd4d99f, 0xbde216ec, 0x3ef2caa2, 
    0xbf0d5b0f, 0x3ea814c4, 0x3e3f219b, 0xbec1d3fc, 0x3f053a86, 0x3e5c3f0b, 0xbf26d567, 0x3f24579c, 
    0x3d9a250a, 0xbe4ea010, 0x3e47402a, 0x3d995d44, 0x3ee28df5, 0xbea20793, 0xbe7b3e38, 0xbe79fad4, 
    0xbd859079, 0xbef60888, 0x3ef12642, 0xbebf8dd2, 0x3ef3457f, 0x3c4ec949, 0x3b6463c8, 0x3e4e00de, 
    0xbe6cb7a1, 0xbdbc47ca, 0xbd6067d5, 0xbec6ed17, 0x3df42e8d, 0xbdc2b29f, 0xbe98348a, 0x3e4d8e72, 
    0x3eeed482, 0xbde87d41, 0xbf0042e2, 0x3e732081, 0x3ecb7ca8, 0xbe9daaf4, 0x3ebaa0cc, 0xbeddd6af, 
    0x3f2a9ff6, 0x3e71baca, 0xbe68cadb, 0x3f04ad50, 0x3e195dec, 0xbde11591, 0x3f063a8a, 0xbd97d917, 
    0xbe92893c, 0xbefb565c, 0x3e2d5598, 0x3ecb32c9, 0x3e37cf40, 0xbcfac9a0, 0xbe5efe6d, 0x3efbbda6, 
    0x3cca27d5, 0xbf06e47f, 0xbf052e28, 0xbe9bd2ed, 0xbec80430, 0x3e8f5568, 0x3f3427b8, 0xbf2565eb, 
    0x3e029315, 0x3e62fb79, 0xbeb69d91, 0x3f1cd0c4, 0x3e7e33e9, 0xbe50f3a5, 0x3e9b336e, 0xbe9a02a9, 
    0x3eb41469, 0x3d8e92cf, 0xbf174058, 0x3f41699f, 0x3df7215c, 0xbe9dd4de, 0x3e8fbad1, 0xbf3115f2, 
    0xbeaf0da3, 0xbf0a894f, 0x3ee2368b, 0xbef05082, 0x3ed1444a, 0xbe245161, 0xbdf11a35, 0xbea55502, 
    0xbeaf12d8, 0xbe244311, 0x3d7144c7, 0xbe767b20, 0x3ebe8e62, 0xbefb6ea0, 0x3c5900d1, 0xbeea9635, 
    0x3e143690, 0xbed39ad4, 0xbef9b9fe, 0x3e16b30e, 0x3e5e6d1e, 0x3ec5c6fb, 0x3f0168e5, 0xbe8da428, 
    0x3e621cc6, 0xbeeaa833, 0xbe197211, 0x3ee3f42b, 0xbed9fd52, 0xbf0e0f2c, 0x3e516718, 0x3f2af6d5, 
    0x3f02ccc7, 0x3d6ba89f, 0x3eda3fe3, 0x3e9d990a, 0x3edd2b35, 0x3eed6d5e, 0xbee93d14, 0x3d9e8048, 
    0xbdd8f46f, 0xbdac0358, 0x3ca29ae9, 0xbe0eb1dd, 0x3f121d2a, 0x3dca0f78, 0x3e1f162e, 0x3ee8f940, 
    0xbe389381, 0xbefe57c4, 0xbe74cfe2, 0xbf2454f9, 0x3e95785d, 0xbdeff8f5, 0xbebf9693, 0xbc7b3b1d, 
    0xbd7337c2, 0xbf052696, 0x3ece2869, 0x3e94154b, 0x3f1c53af, 0x3ea446a6, 0x3eb2b03a, 0x3e70fa5e, 
    0x3e7cbab7, 0xbeaf9ea8, 0x3dd8ac03, 0xbf0ce202, 0xbe66919a, 0x3b9b4104, 0x3ecac1e6, 0x3f2ebf5a, 
    0x3e099b52, 0x3e8708c5, 0xbe32a41f, 0x3f1e396e, 0xbe90cc83, 0xbead1626, 0x3d0e1054, 0x3ec80e7d, 
    0x3f011be1, 0x3e24b1a4, 0xbecb2b83, 0xbe5d1a30, 0x3ef6d1f4, 0xbd4b03ac, 0xbc55e8de, 0x3efa6f5e, 
    0xbf2f308c, 0xbecf7656, 0xbe20763e, 0x3d85ad8e, 0x3eda5bd7, 0x3f27e107, 0x3e97188e, 0x3e86d144, 
    0x3e5ccb23, 0x3d031dc1, 0xbda6c8e2, 0xbea2e116, 0x3e56dbaf, 0x3e8058f8, 0xbe255268, 0x3db4cc36, 
    0xbe8b84c8, 0x3e2eebe0, 0xbe3f6c62, 0xbe18095e, 0xbe6573aa, 0x3ebefa85, 0x3e3dbe64, 0xbca05e2b, 
    0xbe6a5b2f, 0xbe88daf8, 0xbe453f60, 0x3d9fcd2f, 0xbe613ad4, 0xbe4fbdc8, 0x3d471da3, 0x3ebd6874, 
    0xbe8ec881, 0x3e409c2b, 0xbe97bcd4, 0xbe5114b3, 0xbe821d73, 0xbce117ca, 0xbdde7df1, 0xbda64874, 
    0xbdbc6540, 0x3e2bdc7b, 0xbd242cb5, 0xbd264146, 0x3e676cc0, 0x3e83acb5, 0xbe9c0c57, 0xbd9699a8, 
    0xbc9769f3, 0x3e1256bb, 0xbe008558, 0x3caed761, 0xbce15996, 0x3e6b32ad, 0xbe564806, 0xbdc98e59, 
    0x3ebd5fa0, 0xbf16a1bd, 0x3d6cc9aa, 0xbdbd2177, 0x3dd06bb1, 0x3db4d442, 0x3ea9d55b, 0xbe552fcd, 
    0x3c1b3aa0, 0xbe1be90a, 0x3ec50ce9, 0x3e5efe30, 0xbea2a069, 0xbf041b3c, 0xbecc9f81, 0x3de25561, 
    0xbf4e5aa5, 0x3f2f4719, 0xbe1f6f91, 0xbe483024, 0xbf2fd2d8, 0xbe8047a9, 0xbf011c85, 0x3e50b2bc, 
    0xbf4f7b09, 0x3e767e2c, 0x3e8ff7ae, 0x3cca8774, 0x3e899779, 0x3f11d543, 0xbf776d1b, 0x3d66e926, 
    0xbd75589e, 0x3f0c2d70, 0x3ed2c044, 0x3d33f8a3, 0xbf457af9, 0xbe421aad, 0xbe9fdc71, 0x3e1a0778, 
    0xbf59f3a0, 0xbf0389ff, 0x3f16dcf8, 0xbef77f6b, 0xbec58a55, 0xbe3e5a49, 0xbed4ab26, 0xbf060e0e, 
    0x3e144252, 0xbed990c7, 0xbefbbdb5, 0x3e54845a, 0xbf560b1e, 0xbee83ecb, 0xbef402b9, 0x3edd45d1, 
    0x3d581998, 0x3dfaff12, 0xbe84b338, 0x3de7d060, 0xbe2f3aa5, 0x3f21456d, 0xbf2088a7, 0x3ed85382, 
    0x3ecfc84f, 0x3e8e90ce, 0x3f0ce55f, 0xbdeb4b08, 0xbe4f1056, 0x3e9e8d6f, 0x3eaf8dd0, 0xbf2ab2a8, 
    0xbf15ef7a, 0x3e4e11b8, 0x3ea26df6, 0x3ea155fd, 0x3e88d563, 0x3ee37bd4, 0xbd2e1a5c, 0xbf30fa01, 
    0x3e38b78c, 0x3c3dec4a, 0x3e148cbb, 0x3e003ece, 0x3e91d54e, 0xbe2a9c44, 0xbf3fa292, 0xbe0da00b, 
    0x3e4f6a10, 0xbf1fd994, 0x3f122940, 0x3e75069e, 0xbead10b6, 0x3f40b390, 0x3db1faac, 0xbf00b41b, 
    0xbf54fa46, 0xbe08b761, 0x3ee5a3b7, 0x3e940b83, 0x3f4e514f, 0x3efea4a7, 0xbf325972, 0xbf45110c, 
    0xbe55bdab, 0xbf26b058, 0x3d8ae88b, 0x3f23d149, 0xbf04eceb, 0x3edec627, 0xbf510328, 0xbe4059ca, 
    0xbeea52a9, 0xbe9b292a, 0x3e945013, 0xbe0a3b2d, 0xbf21ff7d, 0xbea971b7, 0xbe7df913, 0x3edc1085, 
    0x3d8cf734, 0xbd8a7ac5, 0x3f29d0d7, 0xbe760dc1, 0xbda1dac7, 0xbf71292b, 0xbf653dfc, 0x3e74db61, 
    0x3e667873, 0xbf6730ba, 0xbec97674, 0x3f3a0ec7, 0x3e13623f, 0xbe571d37, 0x3d3f8270, 0x3d00a7f6, 
    0x3f1bba96, 0x3e058d5e, 0xbf65aad3, 0xbcf848a2, 0x3edb4d96, 0xbef66edf, 0xbe73586b, 0xbe55dabb, 
    0xbeca9a6b, 0xbe8c3671, 0xbe1de4c4, 0xbee62462, 0xbe328b3f, 0x3a0e1170, 0x3d52dc32, 0xbeb890fc, 
    0x3dc013c4, 0xbeec0ece, 0x3f29f279, 0xbe8e89fa, 0x3e0a168a, 0x3f34e4dd, 0xbe5fd08e, 0xbf08a707, 
    0xbe21bc32, 0xbebcd4ae, 0xbefabbee, 0xbe96efd7, 0x3ed91005, 0xbeb317ac, 0xbedfc37a, 0xbe75cbd1, 
    0xbed6b34c, 0xbe04a96f, 0x3f071f86, 0xbe6d9ef3, 0x3f19d20f, 0x3eef06e0, 0xbe2bf899, 0xbeb36c14, 
    0x3f0e12f0, 0x3ebd4268, 0xbe5e062d, 0x3e90f461, 0xbf0ef79b, 0xbe99c1ac, 0x3e007646, 0x3ce5d739, 
    0xbe1fe971, 0x3eda2493, 0xbedeee53, 0xbd4ebfad, 0xbe473196, 0xbd27a443, 0x3ef4eee4, 0xbc371032, 
    0xffffce1a, 0x00000004, 0x00003000, 0x3ec368d5, 0xbe22ab4c, 0x3e93c3fe, 0xbe9e4e6c, 0xbea542c6, 
    0xbe1cbc09, 0x3e824fdc, 0xbe9ef8d6, 0x3ed080a9, 0x3dcf3bdb, 0x3ea9f0a6, 0x3e29eff5, 0x3d9a80cc, 
    0x3ebee9ff, 0x3e0fa5fd, 0x3d9941d3, 0xbe3989d2, 0xbdd3403b, 0x3e9c8d7c, 0xbe663595, 0xbdb65559, 
    0xbd8135f4, 0xbec38964, 0x3c97d456, 0x3e8da272, 0x3e4a1f09, 0xbe8795a3, 0xbe48eae0, 0x3e9371c1, 
    0x3ea4f67a, 0x3e905045, 0x3ee09417, 0x3c15d8aa, 0x3dcef713, 0x3e244a08, 0x3ef9238c, 0x3edcddc9, 
    0xbe952130, 0x3c7466c4, 0xbe863519, 0x3e122c09, 0x3e5149ec, 0xbe01bd30, 0x3e1c18e1, 0x3eb0e6aa, 
    0x3d9a7460, 0xbe374f31, 0xbea24109, 0x3e1e33c2, 0xbdbd1a7c, 0x3c89673a, 0x3d8ebdae, 0xbe07ca62, 
    0x3e2bfc41, 0xbe3424b6, 0x3c4de8fd, 0x3c950dbf, 0xbe2eaa64, 0x3ea538ff, 0x3d9b6ad5, 0x3edf136e, 
    0x3e616b8a, 0xbe1e75de, 0xbd7952ef, 0x3e050cc8, 0xbe25eb70, 0xbdafa9dc, 0x3eb99659, 0x3dddac9b, 
    0xbea42a3f, 0x3e32d449, 0xbe64421c, 0xbe4e57a8, 0x3d9cfbf8, 0xbc83b20f, 0x3e3430a1, 0x3dc9fa0e, 
    0x3da056cf, 0x3e67f8a6, 0x3e8e55c0, 0x3e8e96b6, 0x3e999616, 0xbe8f745f, 0xbe72547f, 0x3e217659, 
    0x3ee49768, 0xbd5bb80e, 0x3ebc4971, 0xbdb8d164, 0x3e640065, 0x3c8790e1, 0xbe157cbf, 0xbe6adf24, 
    0x3eb03caa, 0xbd38fb27, 0x3ee6e705, 0x3e4b1314, 0x3dd98e8d, 0xbe9e4bea, 0xbdcdbc08, 0x3df70302, 
    0x3d944164, 0x3c8b5dc6, 0x3e8874f0, 0x3e3e37e7, 0x3dc15b14, 0xbea272f3, 0xbd8e61d8, 0xbe2d8148, 
    0x3e42b740, 0x3e0c7eac, 0x3dc5f201, 0xbe483b9a, 0x3e8f390f, 0x3e138b1c, 0xbd2e62b0, 0x3ebbe086, 
    0xbdfd1d83, 0x3de9781e, 0x3d26b4b9, 0xbe7aa2c4, 0xbe0f7f8a, 0x3e32f700, 0xbeb144cd, 0xbe496a58, 
    0x3c6e2ddf, 0x3e6b7c98, 0xbd5ae7d1, 0x3dcaa7f1, 0x3e0a099c, 0x3e1aecd4, 0x3e4dd4fd, 0x3e1c124f, 
    0xbe38ae4d, 0x3e417237, 0xbe0eae95, 0x3be82327, 0x3e815ced, 0xbe5a6f6e, 0xbe4ae861, 0xbe888d00, 
    0x3d30c1ed, 0x3e775e0b, 0xbc0b0b7f, 0x3d91f649, 0xbe91d9c1, 0xb9ddb6f1, 0x3e94a9f0, 0xbde30e46, 
    0x3e2749f0, 0x3dd7cdb2, 0xbe075a46, 0x3e785f76, 0x3e038878, 0xbe999fbf, 0x3b066392, 0x3e81b503, 
    0x3e81a631, 0x3d448530, 0x3e23eb63, 0xbe53e12f, 0x3e890b26, 0xbe0b04a9, 0x3a29cb17, 0x3e6e470a, 
    0xbe334a7b, 0xbe013e10, 0x3d29e033, 0x3e6bb663, 0x3c655c5b, 0xbe6e0240, 0x3e71e18e, 0x3db8b9d9, 
    0x3e639d75, 0x3d84ce59, 0x3ae9992a, 0xbe00efb4, 0x3e5a0504, 0x3e58b6f3, 0xbdef4f67, 0x3e0bc94e, 
    0x3d910e41, 0x3e519175, 0x3e7ae608, 0x3e2dac90, 0x3d4c6dd2, 0xbe913f14, 0xbdb449a7, 0xbe4ffbdb, 
    0x3e425743, 0xbdfeabfd, 0x3dcb41e7, 0xbc9f4057, 0x3d1ad933, 0xbcea02d7, 0xbcb83b23, 0xbe889317, 
    0xbe47d822, 0xbe6e6e5e, 0x3e0a1322, 0x3ee0dfeb, 0xbebbd997, 0xbe3e6d15, 0xbe016fbe, 0xbe542da1, 
    0x3e790ce3, 0x3db06965, 0x3eef3280, 0xbe936b09, 0x3e37da5d, 0x3e50b583, 0xbea58121, 0x3ef92c4e, 
    0xbe6739e4, 0xbe929c37, 0x3e486b94, 0xbda7c70e, 0x3ed901d0, 0xbdb13b58, 0xbe0cdc36, 0x3db7bb09, 
    0x3e886c8f, 0x3c15c430, 0xbd072496, 0xbeffc3ff, 0x3d1fb257, 0x3b725c9b, 0xbebe8c40, 0xbdda0a82, 
    0xbe21b14a, 0xbdb70bee, 0xbe8698d7, 0xbe910504, 0xbb7beca0, 0xbd886a70, 0x3e38fde3, 0xbe96c489, 
    0x3da7352a, 0xbeba270b, 0x3e90ebb6, 0x3d10b4f9, 0xbbb3e3ec, 0xbe31cc72, 0x3d88e0b9, 0xbe1e6ddb, 
    0x3e874cad, 0xbe56fe06, 0xbd76c5dd, 0x3d2e0378, 0x3e50b867, 0x3e682079, 0xbdb7e9a9, 0xbe834af9, 
    0x3d2c401a, 0x3e2bd170, 0xbe8beecc, 0x3dcb4f31, 0xbe4a3096, 0x3d5bb26e, 0xbd40d503, 0xbe35ae7e, 
    0x3dfe7891, 0x3e964f39, 0xbe83e5bc, 0x3e1de312, 0xbe8dd875, 0x3e6387b9, 0x3dd1ffc2, 0xbde9b71e, 
    0x3db0b00b, 0xbe63cf56, 0x3ea01f7b, 0x3d4e0343, 0x3e60e2e6, 0xbe6d7de7, 0x3df830c9, 0xbdcda704, 
    0xbeac7052, 0xbdadb296, 0x3e8f0c00, 0xbe9b2f37, 0x3e3af268, 0xbd5f4c88, 0xbe0995ac, 0xbe2d6b0b, 
    0x3e453c93, 0xbe92a3bb, 0x3e61e928, 0x3eeb07bd, 0xbdb61e32, 0x3db6b62c, 0xbe882773, 0xbe772b5d, 
    0x3d837218, 0x39dc91ad, 0xbe58cb13, 0xbe95366b, 0x3e7a03ec, 0xbd1ed107, 0x3d8e8932, 0x3ec33b6e, 
    0x3e3af205, 0x3e753c80, 0xbd81c1ce, 0x3dc81357, 0xbe75fb0b, 0x3e8b551f, 0xbcf62c4e, 0x3d2a7aae, 
    0x3ea52ff0, 0x3ec55320, 0x3d6aaaad, 0xbeaf1985, 0xbe8474e3, 0x3e4cb572, 0xbe133a3b, 0x3ee845c9, 
    0x3ebf595e, 0xbea8a445, 0x3e56570f, 0xbcf9fb99, 0xbe788100, 0x3e7728d1, 0x3d8e12ad, 0xbdd76a80, 
    0x3ea85f5c, 0xbe2a41b2, 0x3ead0781, 0xbe8c7f41, 0x3e7758a8, 0x3ec09b8d, 0xbe8d3f07, 0xbdab38f5, 
    0x3e81d675, 0xbd1c8013, 0xbea3911a, 0xbd59adb9, 0x3eafdbf5, 0x3ebba707, 0xbea600f5, 0x3e405134, 
    0x3dd2defa, 0xbda67c59, 0x3e8f64f5, 0x3e959931, 0x3c9fa9ad, 0x3e95ef8d, 0x3cc07072, 0x3e99cf2a, 
    0x3eed9bc8, 0x3d4e55bc, 0xbd2b4114, 0x3e06cf92, 0x3e672114, 0x3e27e882, 0x3e92efaf, 0xbddacccf, 
    0x3e30a113, 0x3e439e4f, 0x3e8c39d2, 0x3d8ce720, 0xbec13ec6, 0xbb599d9b, 0x3e0eacd2, 0x3e78290e, 
    0xbd4f32e1, 0x3dfaab4d, 0xbe5c34e5, 0x3e32c263, 0x3e916487, 0xbc1f2cf7, 0x3d808bf0, 0xbdae73cd, 
    0xbad736d2, 0x3f0eee84, 0xbe898bc0, 0xbe111d54, 0x3e93344b, 0x3e93f396, 0xbe8bd2f3, 0xbe0036ff, 
    0x3c0d0249, 0x3e5c6224, 0xbe4a74d7, 0x3d54460f, 0x3eccab11, 0x3d3ff7f4, 0xbee06bc8, 0xbe9c7327, 
    0x3dd061e0, 0xbe8522fe, 0xbe294f51, 0x3e17717c, 0x3dd8dabc, 0x3de3e90a, 0xbbb4e379, 0xbe264606, 
    0xbe226829, 0xbe737dcb, 0x3ed8fa64, 0x3eca2c2d, 0xbe98b734, 0xbe771224, 0xbe5dd11b, 0x3e8b482b, 
    0x3e7ebf9c, 0xbe4f7ce7, 0xbdc95aad, 0x3ea2d791, 0xbdf0a848, 0xbe72a491, 0xbe79c701, 0x3d40f6be, 
    0x3e0dd203, 0x3d96be93, 0xbdde5b87, 0xbe3e59b2, 0x3e377c22, 0xbd3ef01d, 0xbde1cfcd, 0xbd0ad2fb, 
    0x3ee75b0b, 0x3e6befae, 0xbecb645a, 0x3e772fa9, 0xbd05f70a, 0x3dca1938, 0xbe87f0d7, 0xbde78c64, 
    0x3e84e1f2, 0x3e6d0ea7, 0x3ec4e59f, 0xbe8206f2, 0xbee86cc8, 0xbbcc224d, 0xbe9567e0, 0xbdaccaca, 
    0xbe4d3cc4, 0x3e144787, 0xbeba0e29, 0xbd7d89d5, 0x3e55e71b, 0x3d2609ab, 0xbe4af3d0, 0xbe878e94, 
    0xbd8ede51, 0xbdd4d516, 0xbe9c1c5e, 0x3df63d98, 0xbd67d429, 0x3ef333cd, 0xbd942975, 0xbedc68cc, 
    0xbe1ade36, 0xbecb732e, 0xbd51eea9, 0x3da3ef0b, 0xbc0f0753, 0xbd84c105, 0x3ed3a46a, 0x3eb13c20, 
    0xbe18ddf8, 0xbe410337, 0x3e3b1cb5, 0x3e1317d7, 0xbdd504db, 0xbbe98e55, 0x3e86234e, 0xbe89d272, 
    0xbe41bf2a, 0x3e33249a, 0xbde5fc85, 0x3dfe81ce, 0xbca7613b, 0xbcdcbb99, 0x3db6d448, 0xbe0b113d, 
    0x3edefc2e, 0x3e167118, 0x3ea8072a, 0x3d274844, 0x3e8687ff, 0xbdbc366e, 0xbe94f021, 0x3d8b2d95, 
    0xbe265b87, 0x3a9e4965, 0x3ea965f8, 0x3f0326a1, 0xbeb863ad, 0xbcf66d4f, 0x3dd856e6, 0xbdca8ae7, 
    0xbd25e490, 0xbdf77645, 0x3ea6720c, 0xbde7d2d6, 0xbe732cf3, 0x3e9df2ff, 0xbece93e6, 0xbcd79f81, 
    0xbd7a6160, 0x3eba7da1, 0x3cde3321, 0x3e8f31f4, 0x3f06bbdb, 0xbe90bc65, 0x3f024418, 0x3e60d28d, 
    0x3e881eb9, 0xbe974d5a, 0xbd0aedd9, 0xbe9e06e0, 0xbeb278cf, 0xbea24b2e, 0x3f0d356b, 0xbe8ad04e, 
    0x3e0738aa, 0xbe9cf8ec, 0xbe032846, 0xbe6c1e36, 0x3dfd9b25, 0x3f0ee881, 0x3e8e56bf, 0x3ea0869e, 
    0xbedbbbbb, 0xbe859571, 0xbdf8ebac, 0x3ebbdbba, 0xbe217665, 0x3e6e1ca7, 0xbee82f05, 0xbe95ab44, 
    0x3f355730, 0x3ebbc565, 0xbdccbaee, 0x3e528b24, 0xbd7c50a2, 0x3dd1e5e2, 0x3ed08832, 0x3e1ac386, 
    0xbdefc33f, 0x3e7b7529, 0x3e95e758, 0xbe9c7915, 0x3ebde35c, 0x3ef3e293, 0xbe2db21e, 0x3e920da0, 
    0x3ecc95da, 0x3ee5114f, 0xbeeae4ea, 0x3d198508, 0xbe9b1d22, 0x3e8224a7, 0xbba9c27b, 0x3e80ab32, 
    0x3ef91a4d, 0xbd73dbe1, 0xbe6135b3, 0xbe96ae1a, 0xbe42133b, 0xbec50b0a, 0xbe9b876d, 0xbe9bf5d5, 
    0x3ebd931f, 0x3e6ef3e5, 0xbe8808a5, 0x3e8659e0, 0xbe4d6c06, 0x3e7be634, 0xbea3a700, 0xbebecffe, 
    0xbe538e29, 0x3dd27f13, 0xbebb4e3a, 0x3e5a958c, 0xbc8f0190, 0xbce6771e, 0x3d21bd93, 0x3d5522e9, 
    0xbe7b1fe7, 0xbe398fbc, 0xbdc430c5, 0x3dfef904, 0xbde4ec2b, 0xbdcea56d, 0x3e83fa96, 0xbe8eae95, 
    0x3e945bc8, 0x3c76ca86, 0xbe877cc0, 0x3eb45c8f, 0xbd8b4115, 0x3e839792, 0x3e094522, 0xbe6cb194, 
    0xbe0dc834, 0xbd2f3a96, 0x3e425d07, 0x3d1fc9cb, 0xbe02854a, 0xbe4dfbff, 0xbd5b2f73, 0xbd8fd79b, 
    0xbe04935b, 0xbd8881ed, 0x3e435ea0, 0x3e9d00fd, 0x3c68d612, 0x3cb30327, 0x3dd5b786, 0x3e81b573, 
    0xbe465278, 0x3e976b2c, 0xbdbcf68f, 0x3e1cc831, 0x3e3dd104, 0xbe3f4701, 0xbd967bd4, 0x3ea5a118, 
    0x3d674086, 0x3dc03088, 0xbe476eec, 0x3e2379a7, 0xbe0d1b52, 0xbe098bf1, 0x3e600c42, 0xbdd25abf, 
    0xbeb9ee59, 0xbe1b45bc, 0xbe011285, 0x3db842b7, 0xb9bdf5c7, 0x3e814e48, 0xbe301c04, 0xbdee38ec, 
    0x3e2a3a14, 0x3e29bc27, 0xbe2a02f7, 0x3e783c6e, 0xbe5a8810, 0xbe645ad0, 0xbe695756, 0x3be522a8, 
    0xbe94cf49, 0x3ce56b21, 0xbe2637ef, 0x3e824bbe, 0xbd460704, 0x3cee12ad, 0xbd06bb7d, 0x3d45a487, 
    0x3e4ad357, 0x3e6cbbbd, 0xbea02b7d, 0x3e257e6d, 0xbe2d1e63, 0x3e1a26a1, 0xbe29247e, 0xbd16cf9c, 
    0x3e8858af, 0x3b40021f, 0x3d1ac1f7, 0x3c03940b, 0x3eaed22a, 0xbde5a786, 0x3d232001, 0x3e1acd69, 
    0xbdb9cad0, 0xbe1b4e41, 0xbd1f90b4, 0x3e7ddfaf, 0xbed70726, 0xbe5fb6e2, 0xbdcfaa29, 0xbe813d17, 
    0xbe58391a, 0x3f050af8, 0x3e8feb90, 0x3e8adac6, 0x3ec8ef12, 0xbdc19435, 0xbe4bfc08, 0xbe46117d, 
    0xbeb141eb, 0xbb4d1bdd, 0xbd41d9af, 0xbe2b9f9c, 0x3e2c3b3d, 0x3e9fde28, 0xbe9033f6, 0x3da9834a, 
    0xbeff0c34, 0x3e0b9390, 0x3d4d2754, 0xbed96b18, 0xbb469a32, 0xbde2143d, 0xba9d799f, 0x3db228e3, 
    0xbe98fa7e, 0x3deb8e51, 0xbc7041f0, 0x3ec3f9ed, 0x3e9d3e72, 0x3e88b09f, 0x3e1fe978, 0xbddb6b8a, 
    0x3cf84a92, 0xbe4d3744, 0x3dad1366, 0x3e8d8ba3, 0x3dee2058, 0xbd658cac, 0x3e789ba5, 0xbcac5c2f, 
    0x3e7c3b9c, 0x3eae5e38, 0x3e9b6e16, 0xbee90c38, 0xbebf0876, 0xbe5ada0e, 0xbeed59b3, 0xbea2ca77, 
    0x3ebbcbd8, 0x3ee6a222, 0xbe34f899, 0x3eaa2ad6, 0xbe350bda, 0xbea14e5e, 0xbdf28e34, 0xbe068d48, 
    0x3e19b019, 0xbe9c78f3, 0xbe632439, 0xbe74a632, 0x3e81d21b, 0x3cfd8161, 0x3e242071, 0xbe075ad4, 
    0x3dba7d67, 0x3d4f0c12, 0x3e11ff39, 0x3e2b033c, 0xbeac9397, 0xbd211743, 0x3da767e7, 0xbdc5ee6e, 
    0xbe1331f7, 0xbe9050a1, 0x3e4b7c67, 0x3d81bee1, 0x3ed08988, 0x3ed7e672, 0xbc19bef9, 0x3e77c85f, 
    0xbe828379, 0x3e260ce2, 0x3ef9957a, 0x3d32e5ca, 0xbe2bb544, 0x3e487023, 0x3ef7db5f, 0xbe262a37, 
    0x3e83ed54, 0xba59ee1c, 0x3d36e22b, 0xbdeb6761, 0x3e49863a, 0xbdc4d77b, 0x3c8dbf4e, 0xbe48ccf8, 
    0xbec68434, 0x3e8df3d7, 0x3ec43c17, 0xbe8a64a2, 0x3ee944ac, 0x3d187acf, 0xbebe5e05, 0x3e0f8a2b, 
    0x3e3df4e9, 0x3e20a086, 0x3ee1c283, 0xbe36900c, 0xbe3e1217, 0x3e09c224, 0xbe8c0886, 0x3ede82e4, 
    0x3e8b7451, 0xbe9656c3, 0x3e92c209, 0x3e82aa37, 0x3ec03af2, 0xbd25fbfb, 0x3e8ff5e1, 0xbe86a244, 
    0x3e5d2474, 0x3e91ee18, 0xbe06c5ba, 0xbe14db5b, 0xbc4ab6f2, 0x3e4e3c28, 0x3e0a0513, 0xbe5adb20, 
    0x3d920327, 0xbdbd78cf, 0xbda2b695, 0xbe0c8db0, 0x3ed2a520, 0xbec7ad3e, 0x3ea821cc, 0x3e1d4a7e, 
    0x3ec1f85c, 0xbe8a97f5, 0x3e6374ba, 0x3e81c455, 0x3ecc74f6, 0xbd7cfa6b, 0xbe91a385, 0xbc527128, 
    0xbea3ecff, 0x3e42aa25, 0x3ee20afb, 0x3e81fbe1, 0xbe80ab6b, 0x3e0cd9cb, 0x3c2799c2, 0x3e717685, 
    0x3e891385, 0x3ee550db, 0x3e0e4704, 0x3e1ca904, 0xbefc6324, 0xbebd620a, 0x3e852bfe, 0xbea3f13e, 
    0xbcbf7c72, 0x3e974c29, 0x3e8c79d3, 0xbe572e56, 0xbd04a971, 0xbe41d8e7, 0x3e52d3f0, 0x3daf492d, 
    0x3e01f532, 0x3d16297a, 0xbe970baf, 0x3eb8e89c, 0xbe8b1e5a, 0x3ee5bac6, 0xbdbe3683, 0xbe88fa26, 
    0x3ed6c4f2, 0x3e561d18, 0x3f0d20d3, 0xbbf4023c, 0x3e8c1a6e, 0x3eefcc71, 0xbee4076b, 0x3e28cddb, 
    0x3e3f0ca5, 0x3ee4afb7, 0x3e1c61b8, 0x3eab1904, 0xbed206f4, 0x3e3e5c3b, 0xbe9f2066, 0xbeaedf0b, 
    0xbec5b6ac, 0xbd606175, 0xbe2a412f, 0xbd9cfd07, 0xbe201e44, 0xbebc25dc, 0xbdde8b90, 0x3e13b8cb, 
    0xbe2d65ec, 0x3d3ae5de, 0x3d1574b5, 0xbdde4527, 0x3e153250, 0x3e84acd2, 0xbec5fb23, 0xbe2c5ad0, 
    0x3eaefadf, 0x3e3ffb6d, 0x3f0b368f, 0xbf22ef44, 0x3daa9377, 0x3d9ca295, 0xbec5a381, 0x3e2fcc8f, 
    0x3ee94282, 0xbde3a22e, 0x3df9462a, 0xbea3a33a, 0x3e4d0856, 0x3d1cd8f2, 0x3e31f55a, 0xbe7630c9, 
    0xbd38cefa, 0xbdb4d6d4, 0x3e87b3a9, 0x3eb6fbd9, 0x3e887c94, 0x3dc53acd, 0xbe5acaf3, 0xbe63cbf6, 
    0x3edb06ea, 0x3e97867f, 0xbe2e79b0, 0xbdf145b5, 0x3eaf3079, 0xbda7de89, 0x3df6923b, 0x3ba9fd82, 
    0x3e39485b, 0x3e9c8750, 0x3ea8540d, 0xbca9c4a3, 0x3e55922d, 0xbda4ca53, 0x3b24c098, 0x3e40b02f, 
    0x3ea5e7ed, 0x3e9985f2, 0x3e6f02db, 0xbe4e89fe, 0x3e11ab9f, 0xbe3a9533, 0x3d8e0808, 0xbe1c4158, 
    0xbd83dff9, 0x3e8b350f, 0xbe3a8a04, 0xbe90939e, 0x3e8c1fa6, 0xbe8700fa, 0x3e80b74e, 0xbea3d0b1, 
    0xbe60ff58, 0xbc928f4f, 0xbdca0be3, 0x3ed90322, 0x3e49b2b8, 0x3eb80dc9, 0xbf07c5f4, 0xbdaced00, 
    0x3e145d20, 0xbe2b092b, 0xbe2169ed, 0xbea94f90, 0xbcd4a202, 0x3aaa831d, 0xbe9eb4a0, 0x3cbfeea1, 
    0xbe8c831a, 0xbe800b73, 0xbec09d09, 0x3d49ddea, 0x3ea9c2f6, 0x3d84a1d6, 0x3e87e524, 0xbe27d127, 
    0x3e2db624, 0xbd8f8a2d, 0x3e94108e, 0xbe10dfc9, 0xbf0d01cf, 0xbe0b1233, 0xbeb21edc, 0x3e7c96d6, 
    0x3e151888, 0xbe7cc05b, 0x3ed5ee2a, 0xbdf83e54, 0xbed46f3e, 0x3d4247a9, 0x3e6b6c60, 0xbeaa3bb5, 
    0xbd35e756, 0x3eafaf5d, 0xbec78c7f, 0x3d9d50fc, 0xbea30683, 0xbebddf04, 0x3f073268, 0x3cdcebd3, 
    0xbe8347b2, 0x3ed65d92, 0x3edc410c, 0x3e8e7f85, 0xbdfcafed, 0xbbd54e3b, 0xbe05e06b, 0x3dde99a0, 
    0xbd075482, 0xbe128fb2, 0x3ede449a, 0x3e856d73, 0xbe8211b7, 0x3e39ea3f, 0x3e8c6c7e, 0xbe83d347, 
    0x3eb096e3, 0xbe3c39c0, 0xbe4ed94e, 0xbbe59c2d, 0xbf01702a, 0x3ebfa167, 0x3ed3c6df, 0xbea2e1f5, 
    0x3f191abf, 0x3e9c1b59, 0xbe42784d, 0xbe9415fc, 0xbcc7e807, 0xbd54127f, 0xbec5f96d, 0x3e4a6b3f, 
    0x3d7b228c, 0xbeb389c5, 0x3d33be67, 0xbdb92310, 0xbdbea1e5, 0x3f18d24e, 0xbe7456c9, 0x3e8401bc, 
    0xbdb012ab, 0x3d9475ef, 0xbe98d3f3, 0x3cf8c2bc, 0xbe26af17, 0x3d8311e1, 0xbddfbc3e, 0xbc94c499, 
    0xbe999de2, 0x3eec2a78, 0xbe8aedaf, 0x3e2646ef, 0xbc5a5939, 0xbee8b369, 0x3c803257, 0xbebfebe4, 
    0xbe97844b, 0xbdaee2ff, 0xbe4d5885, 0x3ea58cd0, 0xbe2e28bc, 0x3e68deaa, 0x3f0939bb, 0xbdbc6a8a, 
    0x3dac756b, 0xbccf3ce7, 0x3c18f4fd, 0x3ef5ef74, 0x3e8137ed, 0xbeb98cc3, 0x3e8ed735, 0x3ed15552, 
    0xbd260522, 0xbe371bd7, 0x3ebb2d6a, 0x3d55403b, 0x3e90d187, 0xbd147db5, 0xbdcaccf1, 0xbe30713d, 
    0xbe0bcc94, 0x3ec8d5e3, 0xbc96c021, 0x3d39c48b, 0xbe826618, 0x3e258ad6, 0x3cb43134, 0xbe5566db, 
    0xbe9b18f2, 0x3e2eecc3, 0xbf107255, 0xbe8118a8, 0x3dd9d924, 0x3e0a433b, 0x3ece671a, 0x3ebbf5d3, 
    0xbe281067, 0x3f200005, 0x3d3b9bbe, 0xbc068d53, 0xbd1ed0f3, 0x3ec48740, 0x3d8d0737, 0xbdeda5c0, 
    0xbc306f90, 0x3e7cb740, 0x3e765365, 0xbeb66161, 0xbe793d4a, 0x3e1b14f1, 0xbe16bf38, 0x3ee07f3b, 
    0xbcd81db0, 0x3d4b25bf, 0x3cf0b534, 0xbdea81b8, 0xbdc78c66, 0x3d0fc0aa, 0x3f0f0aa4, 0x3eb26853, 
    0x3e37a45e, 0x3f3523c9, 0xbec673da, 0x3d33895f, 0x3e149f83, 0xbead65fe, 0x3eb9fadf, 0x3d06dac8, 
    0xbf03ece7, 0xbe737c21, 0xbe3d57a9, 0x3e1fc892, 0xbe50f745, 0x3ec4a630, 0x3ddc3f77, 0x3e1bdffd, 
    0xbed9720d, 0xbe854d72, 0xbb8e07bd, 0xbe13d1d6, 0xbea5a484, 0x3c64a145, 0xbe33738a, 0x3e859b19, 
    0xbd5590aa, 0xbe67a789, 0xbee0c5e4, 0x3c4270f4, 0xbd595eaf, 0xbe3ff121, 0x3e8a5c78, 0x3dafc8ee, 
    0x3e4895dd, 0xbe42d1f2, 0xbea800a1, 0x3ed11d74, 0xbedd1a04, 0xbefbec7c, 0x3f177198, 0xbe9c4a0e, 
    0x3eea1fde, 0xbc859299, 0x3f1775ef, 0x3e8a0599, 0xbdd237ef, 0xbdef368e, 0xbe90873f, 0x3de1c5ce, 
    0x3e2f8a8d, 0xbde76961, 0x3d4ca3b0, 0xbe08f805, 0x3e0e417e, 0x3e9a1ea4, 0xbe887b63, 0x3e46171f, 
    0xbd6af6d6, 0xbeb076af, 0xbdf4951a, 0x3dc83d55, 0x3f178208, 0xbcdc0cf8, 0x3e058d67, 0x3d7b808e, 
    0xbe8b2e0b, 0xbe0c4ca2, 0xbeabe462, 0x3dbfbdcf, 0xbe7fdf97, 0x3ec340d7, 0x3d372f76, 0xbe4b931d, 
    0xbd23c268, 0xbd3dcce9, 0x3e2d8e42, 0x3e3d7637, 0xbe88e7a2, 0xbe2c1de8, 0xbd13cd04, 0x3d2ebeb7, 
    0x3e9f8d52, 0x3c50e63a, 0xbe048e7f, 0xbe62bcf7, 0xbe294c2a, 0xbe3f325c, 0x3d8595bf, 0xbe92f51f, 
    0x3ea4bda9, 0xbdb76c81, 0x3dd220ea, 0x3d8096a4, 0xbd4eadb0, 0x3e93016b, 0xbdaa4bb3, 0xbe307a24, 
    0xbe84f911, 0xbe1a0d2b, 0xbe54d130, 0x3d9a622e, 0x3e4d6df9, 0x3eb10c89, 0x3d918658, 0x3cd6b16c, 
    0xbd26c684, 0xbd84f0d4, 0xbeb1ed42, 0x3e569e9a, 0x3e577497, 0x3dc0d854, 0xbe95c5a2, 0x3e1f923d, 
    0x3e5fa14f, 0xbebadaa2, 0x3e62c6fb, 0x3cd3d950, 0x3e9c711e, 0xbc45f7c5, 0xbe865944, 0x3e09a0f9, 
    0x3e593fa8, 0xbe992422, 0x3da825a8, 0xbd3986ed, 0x3e505a05, 0x3e92c9bc, 0xbe192756, 0xbe7b084a, 
    0x3db6fcce, 0x3ead8d4c, 0xbe1954f3, 0xbeb0ba7a, 0x3bcb5686, 0xbd4b6f2d, 0xbe21da79, 0xbe5d49d0, 
    0x3e28aff7, 0xbdc747cb, 0x3dccfd02, 0xbe384c95, 0x3d8d6c26, 0x3ed04728, 0x3e8d6197, 0xbedd4409, 
    0x3e0c64ff, 0xbeab41be, 0x3dd4434c, 0x3d8f3cfe, 0x3ed57985, 0x3e8e146b, 0xbcb12b25, 0x3ebabc6c, 
    0x3e67659c, 0x3dac818d, 0xbe9ccb5c, 0x3e04aaa8, 0xbd9e96e7, 0xbe171dff, 0xbc573653, 0x3e48a166, 
    0x3d8196d7, 0xbe011613, 0xbe2c075c, 0xbe04dc40, 0xbd673b11, 0xbe2191ba, 0x3e901bb7, 0x3efa0f87, 
    0xbeb3fa28, 0x3e2627d0, 0x3e5cc813, 0x3e06f2f1, 0x3df2f52d, 0xbe56b324, 0x3eac177f, 0x3cfe0bb1, 
    0x3e28128d, 0x3e6fe663, 0x3e7fe009, 0xbec5c73e, 0x3dd7eb01, 0xbe474698, 0xbd44667b, 0x3e526468, 
    0xbe5f7b46, 0xbea2b1dd, 0x3d4ae6fa, 0xbdb88d14, 0xbd996aae, 0xbc821811, 0x3e319f95, 0x3ee09578, 
    0xbdcd1ce9, 0xbe6456f3, 0xbea42263, 0x3d2e1809, 0x3e3db1c4, 0x3eaaf3b6, 0x3e33353e, 0x3da30dd0, 
    0x3df2a8da, 0xbdf59e97, 0xbb623966, 0xbd96ae4b, 0xbe048589, 0xbe2be657, 0x3d9e391b, 0xbdf9342b, 
    0xbe24d31e, 0x3d2455b2, 0x3ce1fcb7, 0xbd3d63d9, 0x3e41745d, 0xbac30226, 0xbd49ba02, 0xbdaff47b, 
    0xbd6389ae, 0xbea98ef9, 0x3d0271a6, 0xbe762b18, 0xbd8c32e1, 0x3b7ee475, 0xbe8caf55, 0x3eeefbf1, 
    0xbe394030, 0xbe4d3ac5, 0xbd538403, 0x3e685af2, 0x3ebd293f, 0xbe25a533, 0x3de0116f, 0x3e3f4d09, 
    0x3e6cc3d5, 0xbe50bb3e, 0xbdb96eab, 0xbeac4b68, 0xbea3acdf, 0x3eb2ccd0, 0x3eba26a5, 0xbeef9bdf, 
    0x3e029888, 0xbaed78d0, 0xbeecc941, 0x3ea6ddc7, 0x3ec12e6e, 0x3c4637f6, 0xbe4cea53, 0xbe139eba, 
    0x3d096fe7, 0x3e81a571, 0x3e74a7d8, 0xbb3a3356, 0xbd000280, 0x3dbd1149, 0xbe838ca6, 0x3d227636, 
    0xbe3223c7, 0xbf0ba6b7, 0x3dc7314c, 0xbd94d57a, 0xbe442e13, 0x3ee7be05, 0x3e3afb66, 0xbe73ce01, 
    0xbedd4525, 0x3e9069c4, 0x3e660ffb, 0xbe2e9f3f, 0xbe0eae05, 0xbe4a280a, 0x3eba5bd3, 0x3d89f28d, 
    0x3e36b32f, 0xbe7166e4, 0xbecd6b47, 0xbefd8e05, 0x3db26f74, 0xbe8ba289, 0x3def237d, 0xbe7d71b8, 
    0x3e0350b6, 0xbdeec038, 0xbca2e5c8, 0x3df11d2a, 0xbe860e57, 0xbe59c33a, 0x3d79147d, 0x3e4c5a5f, 
    0xbe31e4d2, 0x3eadcdfe, 0x3ce2ec75, 0x3e2d4b40, 0x3dd234e4, 0x3e9b7980, 0xbe2a7c81, 0xbdf07bd1, 
    0xbe169e03, 0xbeb6b496, 0x3e82a100, 0xbec47d54, 0xbdff77ee, 0x3d8ae2f1, 0x3f2bdd93, 0x3e56b1c9, 
    0xbe3be353, 0xbe4ce3b5, 0xbd87f277, 0x3e9093ba, 0xbd71d1e9, 0x3d11827d, 0x3e46ae8d, 0xbf0218de, 
    0xbebdd206, 0x3c5dd232, 0x3ed49803, 0x3cb96fa4, 0xbbd6b7b5, 0xbe91d052, 0xbe08ddd0, 0x3de8a235, 
    0x3d9102b7, 0xbf002417, 0xbdee4040, 0x3ea7790c, 0x3f1d5ef4, 0x3e6bfc7c, 0x3e82d7c8, 0x3eff2c6b, 
    0x3e88611a, 0xbe9ad80c, 0x3e831c7e, 0x3e804c27, 0x3e67972c, 0xbe82f7da, 0x3d7cd91f, 0x3e8848bb, 
    0xbe854f9c, 0xbe7885a3, 0xbd9ebec2, 0x3e83007a, 0x3e56939e, 0xbe036b75, 0xbec3923e, 0xbe86d7b9, 
    0xbe3f1e91, 0x3d946c3c, 0x3ca04e75, 0x3d48306f, 0x3e5f8bf2, 0xbe448ccb, 0x3e949ae9, 0xbe4c858d, 
    0xbe0c29e6, 0xbc37e363, 0x3d4d1f0e, 0xbe86f26b, 0xbd9143a0, 0x3e2b55fc, 0x3d7c1188, 0xbe651754, 
    0x3e9be598, 0xbe8a932e, 0x3e3fe2a5, 0x3e945232, 0xbe7fa849, 0x3e4d2e55, 0xbe144aed, 0x3eb051c2, 
    0xbd0693b4, 0x3e42d8c5, 0xbec95768, 0xbded451e, 0x3e9d9b3a, 0x3e1ab618, 0xbd564d97, 0xbbb85283, 
    0xbe66dfc8, 0xbe83e4f0, 0x3e86eb5f, 0x3e4e6289, 0x3cac6b51, 0x3e950c56, 0xbe14dd81, 0xbe4d0d93, 
    0xbe350130, 0x3de85500, 0x3e29ccfb, 0xbda121ec, 0xbe6dada2, 0xbd6e7d91, 0xbe46cc73, 0x3e349dd4, 
    0x3e8dbe6d, 0xbd48929b, 0x3aabd500, 0xbd91d99a, 0xbea73bc8, 0x3e7a6ddd, 0xbe20cfc2, 0x3d3c869e, 
    0x3e31cbff, 0x3e8e37cf, 0xbc8679e3, 0x3eaa5598, 0xbe1d7104, 0xbdb28582, 0xbe50bfd8, 0x3eb7cbbc, 
    0xbe7e1740, 0xbdccaee5, 0x3e69b3b1, 0x3e88e122, 0xbe7fd96a, 0x3eab9ec1, 0x3d291749, 0xbe920fc4, 
    0x3e477b78, 0x3e1602cf, 0x3d62a67d, 0xbea009a2, 0xbe2d0212, 0xbbcf660c, 0x3d5a9761, 0x3e79ae07, 
    0x3e507e9a, 0xbe7c45d6, 0xbe963aa0, 0x3e249468, 0x3e26932d, 0x3e15ff5b, 0xbdca6747, 0xbced5d96, 
    0xbe8d7fab, 0xbebb0ff9, 0xbe96a30f, 0x3d7d3a0b, 0xbe61326b, 0x3cef79ce, 0x3df400c9, 0xbd481191, 
    0x3e7caaec, 0xbe30347b, 0x3e482351, 0xbeb756f9, 0x3e2bf188, 0x3e455eed, 0xbcd5ae9b, 0xbe238b28, 
    0x3d955494, 0x3d801edb, 0xbd3757a4, 0x3d8191ec, 0x3df23351, 0xbb1fec94, 0xbe8e4131, 0x3c1f1298, 
    0xbca4b63b, 0x3e4597bf, 0xbe2667dc, 0xbebeab99, 0xbe154be9, 0xbdc8dfa8, 0xbd109aaf, 0xbd45860b, 
    0xbdaf9880, 0xbe96bf8a, 0x3dbd8c61, 0xbea3b5fc, 0xbe6431cd, 0xbec6636a, 0xbec65db5, 0x3e8b0731, 
    0xbd599c86, 0xbda9d4d9, 0xbe84fbcc, 0x3e7392c5, 0x3e6a6995, 0x3e615b1c, 0x3e963d59, 0x3e69b1e4, 
    0xbd7246bc, 0xbe764540, 0x3e88f0f3, 0xbe841b4f, 0x3e72d11e, 0x3d5a6499, 0x3e99cad2, 0x3e94e332, 
    0x3e32dca3, 0xbe55bb20, 0xbe286d8a, 0xbeb084e5, 0xbe8169ea, 0xbe1fc92e, 0x3e4a878c, 0x3c87620d, 
    0xbe1c0211, 0x3bb7b8b3, 0xbcfe2c3f, 0xbd6f4d67, 0xbd944702, 0xbec71256, 0xbeae31aa, 0xbe89f71b, 
    0xbd624f3c, 0x3e29cb6e, 0x3e04d489, 0xbd8aede1, 0x3ce33690, 0xbed1160a, 0x3d9975aa, 0x3dc50d4d, 
    0x3ea87989, 0x3e08160d, 0x3e9dee02, 0xbe2d7a5b, 0xbd986f0b, 0x3e8e032a, 0x3e3c3e44, 0xbe0e1284, 
    0x3e3cea29, 0xbe4aebc6, 0x3e2c177b, 0x3ed16af1, 0xbe714f82, 0xbe84d926, 0x3dc6080f, 0x3e377f38, 
    0xbe98822d, 0x3ec6983e, 0xbe106922, 0x3e0c9ed8, 0x3e0f6be3, 0x3cad0e2e, 0xbea6c96c, 0xbe96b1fe, 
    0xbdec6f31, 0xbe65f64d, 0xbdea30aa, 0x3e7a6e5c, 0x3e803e72, 0x3e16d789, 0x3d3f8c92, 0x3ea23127, 
    0x3e683383, 0xbe4da506, 0x3eb6ac96, 0x3dff787f, 0x3db49d7a, 0xbc4effb2, 0xbece1033, 0x3e6b503a, 
    0x3ed958b7, 0x3e98c8cd, 0xbe45bdea, 0x3d3eed99, 0x3e2ba2f4, 0xbe9f0010, 0xbd6a50d1, 0xbe95fa6c, 
    0x3dbf70f8, 0xbe0a9952, 0xbe726143, 0xbdd05eff, 0xbde1d206, 0xbe5dbb79, 0x3d9b7c4b, 0xbe94330c, 
    0x3e09292a, 0xbecaf32a, 0xbe8b6bae, 0x3e3be164, 0x3e4ea662, 0x3eb9615c, 0x3e6a55ca, 0xbebe69b9, 
    0x3ea6506f, 0xbe0e7212, 0xbe3c8fd6, 0xbe1fd236, 0xbe93a4cb, 0xbeb6c2f2, 0xbe97b2a5, 0xbe801de2, 
    0xbea6dd2c, 0xbe58f558, 0x3d7afc33, 0x3cea2bc6, 0xbed7103d, 0x3d750d5d, 0x3c1ccf21, 0x3ea91aa2, 
    0x3e4162cb, 0x3e362347, 0xbea15d94, 0xbdacc10f, 0x3e3642ed, 0xbeaa5032, 0x3ea05d5b, 0xbdc2c91f, 
    0xbe003f55, 0xbdf39e0e, 0x3e612b43, 0x3eb57867, 0xbec7b7bb, 0x3edbb62a, 0xbdaa5967, 0x3e88ff30, 
    0xbea70b3b, 0x3ea1524b, 0x3e81d576, 0xbd196e00, 0x3e166acb, 0xbe889d3e, 0xbc99d84a, 0xbed16ebc, 
    0x3d915aec, 0x3e96679b, 0x3ebac421, 0x3e99f94d, 0xbcc80886, 0x3e534dde, 0x3f1e107b, 0xbc8848c6, 
    0x3ca04ce4, 0xbe425b00, 0xbe03daf6, 0xbe85f536, 0x3c691753, 0x3ea4c9c0, 0x3eeef435, 0x3e69bc02, 
    0xbefc3ffe, 0x3d8b6f8f, 0xbdad3e7b, 0x3ee3cee9, 0xbedba0ac, 0xbe14b6ee, 0x3cfef837, 0xbd272fa5, 
    0x3e8c8443, 0xbf11d58d, 0x3dd94adf, 0xbe20f3b5, 0x3ec75337, 0xbe3cd630, 0x3db2b918, 0xbe4bd708, 
    0x3eb2439d, 0x3eb79526, 0xbe92e6d9, 0xbf05ea87, 0x3dffa43d, 0xbe5dc3c1, 0xbe2c8bc9, 0xbe8c7f69, 
    0xbd57949d, 0xbec2e418, 0x3ec09eab, 0x3dd7a381, 0x3ef27207, 0x3d87af31, 0xbd96b095, 0x3c95bc70, 
    0x3eea72eb, 0xbed242ad, 0x3f0549db, 0xbe927b1c, 0x3c5e64d9, 0xbe2f70e0, 0x3e278e43, 0xbeacc693, 
    0x3da2307c, 0xbf161e36, 0xbef3cb45, 0xbe8589c3, 0x3f179863, 0xbea21923, 0x3ea43b87, 0xbe442879, 
    0x3e8a2080, 0xbd37cb0d, 0x3f0a69ec, 0xbdf17440, 0x3ecb553e, 0xbeaf8c72, 0x3eb85cce, 0x3e3859bf, 
    0x3f0eabbf, 0xbe0e056f, 0xbec28ee7, 0xbd98203f, 0x3e91e8f8, 0xbe701867, 0x3eeec4d4, 0x3cdbb564, 
    0xbe857f31, 0x3ec3f0e0, 0xbec59093, 0x3d2a95a7, 0xbdb04979, 0xbecea3fe, 0xbeb05bf5, 0x3c9cb6d7, 
    0x3ec1358c, 0x3ecc742a, 0x3ed0d4bf, 0x3f262486, 0xbddfe673, 0xbe485664, 0x3ed1e20e, 0xbca7cca9, 
    0x3ec6b920, 0x3e5b47b4, 0x3f00b08c, 0x3e88965f, 0xbeb3d65f, 0xbe122bee, 0x3f21e51f, 0x3df24762, 
    0xbd6fc4dc, 0x3e9331a6, 0x3e89b2fc, 0xbdeabedd, 0x3e661ec1, 0xbe8a51ab, 0x3cbc51d6, 0x3f0b5796, 
    0x3db031e6, 0xbd53427c, 0x3ebf4f98, 0xbe56ae84, 0x3de6c1f2, 0xbe32425b, 0xbea0313a, 0x3ece7f6e, 
    0xbe73946d, 0x3d0ffb12, 0xbc70a27f, 0xbd97a633, 0x3ea47005, 0x3ede4838, 0xbd2bb25f, 0x3ebf91f8, 
    0x3e4db2ad, 0xbe75c573, 0xbe436c56, 0x3e8c1476, 0xbba29d65, 0xbeb0b6ea, 0xbea47424, 0x3ed2b46a, 
    0x3de2b698, 0x3eaf3d1c, 0xbccce428, 0x3ce8f239, 0x3e89aa10, 0xbe7297f4, 0x3e0bc28d, 0x3edb610f, 
    0x3e75ba01, 0x3e15610f, 0x3e73a06e, 0xbed498cb, 0x3dddfbec, 0xbeabc155, 0x3e9f95f8, 0x3d40527d, 
    0x3dbc2a94, 0x3e0f5321, 0x3ea5ab12, 0xbeb2625a, 0x3e4a0ed5, 0x3edea7cf, 0x3c02043a, 0x3ddb3f75, 
    0xbeb407af, 0x3dcf9b01, 0xbdbc23d0, 0x3ea252b1, 0xbe1a9102, 0x3eadc63d, 0x3ec33c91, 0x3c947e8d, 
    0x3e2dea99, 0xbe487842, 0xbc038898, 0xbeec2d13, 0x3eaba054, 0x3ddb5d4e, 0x3ed21e84, 0x3e072320, 
    0x3e95e123, 0x3e5ce401, 0x3eb7d842, 0x3ebdb4bb, 0xbe5dabcb, 0xbec7d540, 0xbe4274be, 0x3d7d8736, 
    0xbee51e44, 0xbe658daa, 0x3e9cd560, 0xbd57dd4d, 0xbd11540c, 0x3c88e8c0, 0xbe8f5261, 0x3e8f7141, 
    0x3e149a0e, 0x3d68f3ed, 0xbeab3505, 0x3d9b51b0, 0xbeb4ce68, 0xbea59297, 0xbecc6794, 0xbe7dd0b4, 
    0xbeae85bf, 0x3e9af9b3, 0x3f0e90d6, 0x3d4182ae, 0x3a12a2aa, 0x3e939ed6, 0x3e9b305a, 0xbda5ab9e, 
    0xbe677f4b, 0xbe80215e, 0x3e3092ef, 0x3e1335cf, 0x3f39e4cc, 0xbe3dd5cf, 0xbe19c6cf, 0x3e9bd492, 
    0x3e465fe4, 0xbdb791f1, 0x3ebbeed5, 0xbe655695, 0xbeaf6826, 0x3e8d08f2, 0x3e141ac7, 0x3dcdb3b2, 
    0x3c57cc61, 0xbec234c2, 0x3e454435, 0xbe2abae6, 0xbe77b1b9, 0xbecd7322, 0xbe41f7b0, 0xbdaba999, 
    0xbe39b3a3, 0xbe7dc0b7, 0x3e6776a6, 0x3e11e060, 0x3e4de28c, 0x3e0ef04f, 0xbde5b166, 0xbe8655d4, 
    0xbeaaa832, 0x3eb0c5de, 0x3ed7cec5, 0x3da6203e, 0x3e046bf1, 0x3ec49481, 0x3cc267ed, 0xbcf576f7, 
    0x3eddc4d7, 0x3cddb454, 0xbdf3f1dc, 0xbe7f89e3, 0xbe0c6b83, 0x3e800070, 0xbdeeb013, 0xbe29b322, 
    0x3e5a6a8d, 0xbdf72ddf, 0x3e853a4a, 0x3e2b9292, 0xbd2a7ee4, 0x3d7ceeda, 0xbda714bd, 0x3ddb6114, 
    0xbea15ab0, 0xbd9b97f6, 0x3d477aeb, 0x3e9c70ff, 0x3c9ad7d7, 0x3e388979, 0xbdac4eef, 0xbd003dab, 
    0x3d412439, 0xbe42d229, 0x3ecb8558, 0x3e9a1394, 0x3e704faa, 0xbece9cce, 0xbf00ee67, 0xbec39910, 
    0x3d9510ea, 0xbeacfd0b, 0xbc3383d2, 0x3e61d766, 0xbeef1219, 0x3e324bbd, 0x3dde07b5, 0xbec06fdb, 
    0xbbe729e9, 0x3e60656b, 0xbde08969, 0x3d69e464, 0xbeaa8cd5, 0xbeb40d28, 0xbe4198dc, 0x3d40fb1c, 
    0x3b9a95cc, 0xbcc50406, 0xbe4b13de, 0xbe5108e5, 0x3eaefbc8, 0x3d7cea60, 0x3eb36f14, 0xbe8023a2, 
    0x3ea7a152, 0xbe984c13, 0x3dbe5dea, 0xbe00c7a7, 0x3e3020fd, 0x3ec0a649, 0x3dcbce3b, 0x3e089feb, 
    0x3d398351, 0x3e3741af, 0x3e9b9c76, 0xbd972215, 0xbd453d64, 0x3f0498cb, 0xbe19cba8, 0x3dc07db7, 
    0xbdc3ac8c, 0x3e9cf066, 0xbe8996c1, 0x3b51e80d, 0xbedfe5cd, 0x3e928895, 0x3e221c59, 0xbd3f514a, 
    0xbedf8b5c, 0x3e6d3d15, 0xbe1886d0, 0x3e3e14ee, 0x3dd4d9f0, 0xbe85e8ca, 0xbeb64f2e, 0x3ed6520d, 
    0x3d2025d8, 0x3e9cbfca, 0x3dc487b2, 0x3dcba1a5, 0xbe390a62, 0x3e6ecad2, 0xbe940cef, 0x3e60a53e, 
    0xbce8ac8e, 0x3e01ca38, 0xbbc05066, 0xbe289b31, 0x3e7150a9, 0x3ea7b363, 0xbe732a85, 0xbcf4dfdd, 
    0x3ca55ff5, 0x3e7a04b7, 0xbe43ff91, 0x3e5d037e, 0x3e41c8b7, 0xbe0e70ce, 0x3ea024d5, 0x3d9136ef, 
    0xbe83ad04, 0xbe9286ef, 0xbeb1acf1, 0xbe69c99a, 0x3df130ab, 0x3e8aeb0b, 0xbea0664f, 0xbe96668f, 
    0xbea44c8d, 0xbe3db5f6, 0x3e0bfc76, 0x3d3d7511, 0xbe5df1e2, 0xbdc0de06, 0x3e4cefe5, 0xbde59185, 
    0xbdc25385, 0x3d92ffed, 0x3dfbd521, 0xbd190bf4, 0xbe733c8a, 0x3eabf969, 0x3e5d039c, 0x3d69e2ed, 
    0x3e8156e2, 0x3e3c6b2c, 0xbe8eb083, 0xbecfbb72, 0xbde3c184, 0x3e9bfd57, 0x3e265c7e, 0x3e998bac, 
    0xbe839344, 0xbea302dd, 0x3e8e8b25, 0xbdcb68cd, 0x3dc6336b, 0x3ec25536, 0xbe675821, 0x3ea3ee8b, 
    0xbed1458a, 0x3e8b921f, 0x3debb967, 0xbe9f4cbd, 0x3cd9b203, 0xbe90f8dd, 0x3e0c54ea, 0x3e1f9c05, 
    0x3e9905ec, 0xbe9ceb7c, 0xbdcc839f, 0x3eb049c0, 0x3eb0b3b4, 0xbd56b0ab, 0x3b6772e1, 0x3ead534f, 
    0xbd9963be, 0xbdfea1bf, 0x3e3d99aa, 0xbe277fd1, 0xbde1b3a7, 0x3dd25ec7, 0x3ecc068e, 0x3ea92cbb, 
    0x3d157fb2, 0x3cc2395b, 0x3c523c94, 0x3d841a87, 0x3e10b05e, 0xbea1ecf8, 0x3e6cb1f1, 0x3ce1865f, 
    0xbe70cf4d, 0xbeb75475, 0x3d85b08e, 0xbe66f779, 0xbee661ee, 0xbd674b67, 0xbe858dec, 0xbde26397, 
    0x3de3f610, 0x3df5a4d0, 0x3cf504d3, 0xbdbcb444, 0x3e88750a, 0x3eab79a0, 0x3c4050f2, 0xbecae77a, 
    0xbd9b2afd, 0xbd9fd3c4, 0xbe18fa0c, 0x3ea34ff0, 0x3e506333, 0x3d86ed12, 0x3efb366a, 0x3d798e47, 
    0x3d309bb7, 0x3da5bbb1, 0x3e7c84cf, 0x3edae817, 0xbd8443cc, 0xbe9c9c9d, 0x3dab1e14, 0x3e387d2b, 
    0xbe314990, 0xbeb0b5a4, 0xbb7a1c57, 0xbeb4cee4, 0xbe6cc405, 0x3d85b17c, 0xbdce27eb, 0xbe734475, 
    0xbdef29cb, 0xbecb1d5a, 0x3da29444, 0xbd9cf9d3, 0xbdcc90f2, 0xbe24577d, 0x3c3b4791, 0x3eda0a00, 
    0x3d78424c, 0xbe8a9694, 0x3d13adb2, 0xbe73c43c, 0x3ea6750e, 0x3d45d199, 0x3da2bf04, 0xbd035cb4, 
    0xbe8c58f1, 0x3e9845c0, 0x3e172893, 0x3e7cb55c, 0xbe8db456, 0x3e2e9ad7, 0x3e341bed, 0x3c1bac01, 
    0x3e448e52, 0x3e8fffb1, 0xbb65701c, 0xbea06589, 0x3c6c5d94, 0xbe18326c, 0x3e1f71df, 0x3ebffa8a, 
    0x3e32a247, 0xbe0dd6fb, 0xbe1143cd, 0xbd2ca6af, 0x3e7002da, 0xbeaae455, 0x3e02682e, 0xbe0dd8af, 
    0xbe9f7bec, 0x3d8e2cb7, 0x3c8679b3, 0x3e709222, 0x3d215d88, 0xbd968e5b, 0x3b88966d, 0x3e9f4b11, 
    0x3da877a7, 0x3da85a40, 0x3df7d06a, 0xbda6068f, 0xbcdfcb48, 0xbe9a6b27, 0xbecd283a, 0xbe406dae, 
    0xbd9ff93a, 0x3e3450f7, 0x3e947449, 0xbddaae15, 0x3ebf46b4, 0x3e8351d4, 0xbdc9996e, 0x3de17983, 
    0x3db4271d, 0x3e33a57c, 0xbe11a0fd, 0xbe5174c8, 0x3d4c81cf, 0x3e83f969, 0x3dbcd042, 0xbe807660, 
    0x3e098e12, 0xbdc81a2c, 0xbe5a71f6, 0xbe920578, 0xbe89514a, 0xba22ab66, 0xbe461cbe, 0x3e2662af, 
    0xbe35437d, 0xbd975ecd, 0xbe610436, 0xbd902c32, 0x3eb21879, 0xbeb0c105, 0x3dafc028, 0xbda554c9, 
    0xbe962801, 0xbe935c3a, 0xbcd280f3, 0xbe01f4e3, 0x3d1b40cb, 0xbda8d0d7, 0x3eaf7513, 0x3e7d4bbd, 
    0x3ecfe88a, 0x3e5185be, 0x3ebfbb23, 0x3e197d6d, 0xbc4708c7, 0x3e3328e5, 0xbe8ad208, 0x3e8a062f, 
    0x3ea6a6ae, 0x3e3c97ee, 0x3b5c1cfd, 0xbef924a9, 0xbe9fd758, 0xbed9b7f3, 0x3d8388d3, 0xbdc12137, 
    0xbb3f8fb6, 0x3e33fa6a, 0x3e9c8af3, 0x3eb981c5, 0xbe090b54, 0xbe50523c, 0xbe139738, 0xbea8a06b, 
    0xbe400a93, 0x3e8cfd6a, 0xbd9e223a, 0x3eabb89e, 0x3ebdda61, 0x3e83d68f, 0xbe1bd269, 0xbcf6dce8, 
    0x3db19446, 0x3db17e67, 0x3e75a75f, 0xbe9e72a7, 0xbdeb3861, 0xbe03cbb8, 0xbe380d81, 0x3e9e71bf, 
    0x3ebb5361, 0xbcb26e27, 0x3e926679, 0x3e92292b, 0x3e58de3a, 0x3d876b34, 0xbedd56a2, 0x3eb52fa8, 
    0x3eae3929, 0x3e5b2a69, 0xbbf67a6d, 0x3e858496, 0xbd994cce, 0xbea9ffec, 0xbd979d14, 0x3e4ef488, 
    0xbe77a459, 0xbeb38396, 0x3ec98424, 0x3bdf7aaf, 0x3ea37d9a, 0x3e7e6166, 0xbeb289ff, 0xbe18387f, 
    0xbd8469d9, 0x3e131f70, 0xbec0cdd9, 0xbe9b0abe, 0xbda84527, 0xbdc9081d, 0x3d89d1c1, 0xbe5f5079, 
    0xbe08e8c3, 0xbeacdb7b, 0xbe6b9ab8, 0xbc0e673a, 0xbdbec97f, 0xbe4084a4, 0x3d8d3824, 0xbe141091, 
    0xbe6e645e, 0xbe81f608, 0x3e991770, 0x3ecd3300, 0xbe7bea15, 0xbeaae8b1, 0xbdc33c88, 0xbd416863, 
    0xbe123c01, 0x3ebc22d6, 0xbe8c38fa, 0x3ee96c35, 0x3ec7d46b, 0xbe38af97, 0x3ee05dd3, 0xbded1350, 
    0xbea5d948, 0xbdff24a4, 0xbd316442, 0xbe32ef40, 0x3e2b9641, 0xbb5dfb11, 0xbe215485, 0x3d15a8b4, 
    0x3f041afc, 0xbd0391a9, 0xbe261fd2, 0x3e8970a4, 0xbd9848eb, 0xbda47f3f, 0x3d79efc7, 0x3eac1e46, 
    0xbe91d043, 0x3c7ceb94, 0xbe4049fb, 0x3ea308c3, 0x3e838c7d, 0xbd3e5a21, 0x3e491519, 0xbdf1635c, 
    0x3e6ace80, 0x3da6ea24, 0xbed8fbe1, 0x3ec155ab, 0xbe024f2b, 0x3d838afd, 0x3e0a3bd9, 0x3e5dab4a, 
    0xbebe8567, 0x3e05a566, 0xbe2d8b72, 0xbe93617f, 0x3e51bad1, 0xbe46759c, 0xbea9645a, 0x3e7598ea, 
    0x3d2fb17f, 0x3d87ffcc, 0x3d7c3f93, 0xbe13c149, 0xbe46f605, 0xbe3cb8b3, 0x3e2c06b0, 0xbe850bc4, 
    0x3e16c031, 0xbe9be974, 0x3e2a8765, 0x3e1a7cb8, 0xbdd1d24c, 0xbe2f0f73, 0xbe257a8f, 0xbda85d1c, 
    0x3d19286a, 0xbe647f98, 0x3c72420d, 0x3dd97e28, 0xbecf8068, 0x3e70adab, 0xbeac4533, 0x3e00573e, 
    0xbe9f9c88, 0x3cab4b3d, 0x3e76235b, 0xbed56a5f, 0xbb8aa24b, 0x3de324df, 0x3ed72c9f, 0xbe9fc504, 
    0x3edb54d0, 0x3c9a32bd, 0xbec6fdc7, 0x3e923d56, 0xbe773d9a, 0x3e7bf053, 0xbe998243, 0xbddb83e9, 
    0xbea1d177, 0x3e9466bd, 0x3e3b1f74, 0x3e7268e1, 0xbe3f290b, 0xbea7819c, 0x3eae7f9a, 0x3e215f6b, 
    0x3e0e69a9, 0xbe762d8a, 0x3e441bac, 0x3e41ed56, 0x3eaaef39, 0xbe9040b1, 0xbdf60723, 0xbe2b465d, 
    0xbdc1e251, 0xbdbce8de, 0x3dc840c1, 0xbdc7c0c8, 0xbd989509, 0x3e60e43f, 0xbe45ea2f, 0x3e21a75d, 
    0xbcf8109e, 0xbd5842ab, 0xbcaaa3a3, 0xbe2d1afb, 0x3d5d70af, 0xbe2451f2, 0x3dd6aac5, 0xbd17c051, 
    0x3e3fa18e, 0xbe21e15b, 0xbe80340a, 0x3e23d225, 0xbdf6044e, 0x3ef81475, 0xbe44b50d, 0xbcec5246, 
    0xbce2540e, 0xbe1476c8, 0xbb491b67, 0x3e9d64eb, 0xbe4dc691, 0xbe6f2278, 0x3e0ea553, 0x3e6f41a4, 
    0x3e0a4d9c, 0x3e6019bd, 0xbe499b29, 0xbebf3735, 0x3ea149ab, 0xbe6cfbff, 0xbe2af2c2, 0xbd6f7130, 
    0x3eabeed8, 0xbdb9b416, 0x3d907880, 0x3d5a1f00, 0x3df6aa63, 0x3efb77a1, 0x3e39dd77, 0x3e6ca435, 
    0x3c1fb746, 0xbd09b11e, 0x3e1e0124, 0xbe54a356, 0xbe32d4c2, 0x3ec7bc1b, 0xbe3f0719, 0xbcd7cff9, 
    0xbd77a1da, 0xbd1e5cbf, 0x3bf64be5, 0x3e15703f, 0x3dc3ba02, 0x3daf88f3, 0x3e3dd7e7, 0xbd02d6b2, 
    0x3ad32363, 0x3c876878, 0xbe3f8321, 0xbdd9dade, 0xbe85b2a3, 0x3dc61192, 0xbdb921d7, 0x3c9a4eec, 
    0x3e774fb2, 0xbc2a20b3, 0x3d6bc74e, 0x3c5bb83d, 0xbcba39d4, 0x3e0f8d76, 0xbdbbd95e, 0xbeda481e, 
    0x3d949758, 0x3e1db9dd, 0xbc39091e, 0xbd53603b, 0xbe386356, 0x3ed819da, 0xbe2a92a8, 0x3ebbdf1c, 
    0xbe557499, 0xbe516388, 0x3e0079a0, 0x3e15b278, 0xbe13a4aa, 0xbe9da4d1, 0x3e74770b, 0xbd8934dc, 
    0x3eaba8e8, 0x3e841bec, 0x3e7b070c, 0xbead8813, 0xbe41f53d, 0x3e99c05d, 0xbe408758, 0xbe5898e8, 
    0x3e99aa9c, 0xbe1af0d2, 0x3edb7074, 0xbe3a7354, 0xbeb143e0, 0x3e0e38b9, 0x3e36ce38, 0xbeafa05f, 
    0xbdc28c47, 0xbe9132a2, 0x3e99ba5d, 0xbe349fdf, 0x3bdc274e, 0xbc870317, 0x3e8864f4, 0x3e24bc6b, 
    0x3e86b81a, 0xbe43e5e5, 0x3d175ee7, 0x3e5b9eec, 0xbe181982, 0x3e3b6681, 0x3cea3bdf, 0xbe81074b, 
    0x3cfce086, 0x3ca384ab, 0x3e6edc8d, 0xbe346b56, 0x3ea231af, 0xbe1b0580, 0x3e9b2af9, 0x3e0d7abe, 
    0x3d3c36dd, 0x3ba9657b, 0xbdcdeb36, 0x3e6275f9, 0xbe184f9b, 0x3ec9d409, 0xbec4ade3, 0x3e618020, 
    0x3e3d6cbe, 0xbb3911e7, 0xbf0288e8, 0x3d46f643, 0x3ea6b0f5, 0xbe977d30, 0xbe53befb, 0xbf07261e, 
    0x3e364b8a, 0x3ecb8088, 0xbbac865c, 0xbe1435ef, 0x3ec08d7b, 0xbeb78568, 0xbe54a895, 0x3e1e77a6, 
    0x3e222ccc, 0x3e0de184, 0x3d2d9309, 0xbdcfe390, 0xbec0f272, 0x3e4bc68a, 0x3e84622f, 0x3e5805b4, 
    0x3e8a2daf, 0xbcaf7596, 0xbecaa75b, 0xbd2918ca, 0xbd1295ff, 0xbdc89fbe, 0xbe58c743, 0xbe349365, 
    0x3e553af3, 0xbed2b922, 0xbe0f5e1a, 0x3e958f6c, 0x3dc9486d, 0xbd7aaa0a, 0xbe96bea6, 0x3e0be07b, 
    0xbd1afbad, 0x3eafd2cb, 0x3def859e, 0x3ea6ebd4, 0x3eb99603, 0x3d674b18, 0x3ebbaf9d, 0xbe6adddc, 
    0xbe64a1eb, 0xbe84a105, 0x3ed029ae, 0xbed706bd, 0x3e212f83, 0x3e4f167a, 0xbe0b54dc, 0xbe21a2ff, 
    0x3e431131, 0xbaf885c0, 0xbe0ccb47, 0xbe0cda4f, 0x3e2963fe, 0x3ede09c4, 0xbebcc54a, 0xbe21b300, 
    0x3da39bca, 0x3e53b914, 0x3d879691, 0x3e08c3b6, 0xbe4143c8, 0xbe4d064d, 0xbeb68f5f, 0xbed1f51b, 
    0xbe8c874b, 0x3e15cf30, 0x3ed3e39e, 0xbee40a3b, 0xbe50cacf, 0xbec6ee9d, 0x3e4603f6, 0x3ec6508f, 
    0x3ef700b9, 0x3deec098, 0x3d071efd, 0xbe525270, 0x3e29bb9c, 0xbcadb544, 0x3e9eecb8, 0xb9f3fecf, 
    0xbf0c2f0e, 0x3de7e413, 0x3ef09a2b, 0xbc4cab5c, 0x3ef392e0, 0xbd35de85, 0x3e2b6f61, 0xbe8dd288, 
    0x3e98c3de, 0xbc81e6b4, 0xbdf209e4, 0xbea00a66, 0xbe10f888, 0x3e23c9fd, 0x3aeea8d5, 0xbeb8a1b0, 
    0x3ed474b2, 0xbec02f38, 0xbe5b405c, 0xbe9e4eb2, 0xbea91ec9, 0x3e85647f, 0x3e68f667, 0xbcbd23b8, 
    0xbe95b608, 0xbdcbd5e7, 0x3e8143ab, 0x3e9bd818, 0xbc21cfc9, 0x3dfd1230, 0xbef7aaee, 0xbe239fc0, 
    0xbe4a816a, 0xbe466ce5, 0xbe870881, 0x3e3f760b, 0x3ec01a5f, 0x3f0e808d, 0x3ea1a539, 0xbe5908c7, 
    0x3d155055, 0x3ed8ccac, 0xbe974a5e, 0x3e501f0b, 0x3c87e152, 0xbf0c7ac7, 0xbecb4f87, 0xbee54354, 
    0xbea2def4, 0x3e9d822e, 0xbe8e82db, 0x3db91640, 0x3e671ad6, 0x3de5478b, 0x3f01a65e, 0xbd8ea0e3, 
    0x3efd443d, 0xbebf3abc, 0x3f08a200, 0xbda31059, 0x3d009126, 0xbeb70266, 0x3e901b90, 0xbd4196fa, 
    0xbeafdefd, 0xbe1cdbf4, 0xbe99318d, 0xbe013c2f, 0x3da358c6, 0x3e344650, 0x3e548a2b, 0x3e73f39c, 
    0xbe04add6, 0xbe802d25, 0xbd8f41f2, 0x3e63dd38, 0x3e698c03, 0x3e6bbffd, 0x3dc73ee4, 0x3e235a4c, 
    0xbd4cff5c, 0x3de75d49, 0xbc8b2dde, 0xbddf722d, 0xbedc44f0, 0x3e83918d, 0x3e1a8d64, 0xbd8c28e9, 
    0x3e712cea, 0x3d22468d, 0x3e97233d, 0xbe68a4b7, 0xbe81ec58, 0x3ebbf645, 0x3e3785d1, 0x3ecad69e, 
    0x3e4baa94, 0x3e675850, 0x3e783ca1, 0x3dc2bbc4, 0xbe926993, 0xbe46c14a, 0x3e7f7af6, 0xbe0e2211, 
    0xbe9023ea, 0xbe4a7b46, 0xbe7c1818, 0xbe44e1a1, 0x3ca7d51f, 0xbea7d390, 0x3e97ddf3, 0xbeade582, 
    0x3ea1f870, 0xbe96fadc, 0x3e78bb3e, 0x3e06a855, 0xbe17a2f9, 0x3e3c1500, 0xbe6f2192, 0x3e9bea38, 
    0xbeac037e, 0x3e2360df, 0xbcb70d98, 0xbe831ade, 0x3e852249, 0x3ed100aa, 0x3ebe8154, 0xbd52ef6c, 
    0xbe063a37, 0xbd393abf, 0x3d3f416d, 0xbe735bc7, 0xbd41d421, 0x3e906f4b, 0x3eb98bdf, 0x3c4d9c2e, 
    0xbe815a70, 0x3d93a80a, 0x3dbafe2b, 0x3df4a7d4, 0x3e5a81e2, 0xbe17c999, 0xbe9fc31a, 0xbe9b99b7, 
    0xbe0cc7b7, 0x3e6cf236, 0x3e8054e5, 0xbd2400e1, 0xbd0daab9, 0x3dc1af2b, 0xbe5270ab, 0xbcc70f96, 
    0xbe143870, 0x3ea5daef, 0x3dcfac42, 0x3ea2e274, 0xbe42fdf4, 0x3e99a85a, 0xbca4359d, 0x3df88176, 
    0xbd812f16, 0x3dfcbdab, 0xbe6ffdf3, 0x3ea66a2c, 0xbf1670a2, 0xbe43ce85, 0xbe7fb541, 0xbef91a2f, 
    0xbea61595, 0x3ed49ceb, 0x3e411546, 0xbeae634f, 0x3efec3c8, 0x3ea38382, 0xbe029d06, 0xbead2f2e, 
    0xbe8047c5, 0x3e4daffc, 0xbeb9a487, 0xbe37ebbd, 0xbe589d3b, 0x3ee5f4bf, 0xbec67d74, 0x3e5bfa98, 
    0x3eb0fc94, 0x3e461a2d, 0x3e083f70, 0xbd08e495, 0xbc450599, 0xbe33c941, 0x3e32993b, 0xbd895ff4, 
    0xbe864a61, 0x3ec99214, 0x3e26eaac, 0xbea0ae5e, 0xbe3970b1, 0x3da38936, 0xbd245f3d, 0xbe1282a4, 
    0x3d7d2614, 0x3e8863c3, 0x3e24b04f, 0xbe92cc78, 0x3ee0294f, 0x3ea060be, 0x3e086b84, 0x3d6ebe04, 
    0x3d5361c0, 0x3dddcd91, 0xbd879d54, 0xbe748040, 0x3dd2570a, 0x3d5a2775, 0xbe839a8c, 0x3eeb2a47, 
    0x3e0af7f2, 0x3e90756a, 0x3e81e371, 0x3e881483, 0xbe6e4ef6, 0xbe7bde27, 0xbe12f20c, 0xbe8127a1, 
    0x3e8b1a5f, 0x3ecc845f, 0xbf059a96, 0x3a88ca2c, 0xbecaece9, 0xbe5fcc22, 0xbc165c99, 0xbe8ecc04, 
    0xbf03366e, 0x3e8780db, 0xbee9b1af, 0x3e87f3f4, 0x3e96cb84, 0xbd85c17b, 0xbecb0664, 0xbc7183dc, 
    0x3eb38c88, 0xbef71b9a, 0x3e5f3cbd, 0x3da16868, 0xbf05bb03, 0x3e10b04c, 0x3c368517, 0xbe2cc0a3, 
    0xbedbc356, 0xbed74a74, 0x3dae1fda, 0x3de64a2a, 0xbe5913f0, 0x3dc4de04, 0x3ec87b3b, 0xbeb9ba12, 
    0xbd177757, 0x3d29073b, 0x3cf09314, 0xbf15b282, 0x3e14a0b6, 0xbeee17d5, 0xbdc08e3c, 0x3eab3890, 
    0x3ec2cf31, 0x3df8012c, 0x3df5298c, 0xbddda6f5, 0x3ed23eec, 0xbdc8347e, 0xbde30505, 0xbdf35767, 
    0xbe4c1cc7, 0xbe31d873, 0xbdd0d777, 0x3ec56ea8, 0x3bfbc801, 0x3eeb2edc, 0xbe402a2c, 0x3e7fa1cd, 
    0x3e8c5ab6, 0xbdd8b974, 0xbe9e1a3f, 0x3b6995ba, 0xbd1dc6fe, 0x3ed860f0, 0x3de07278, 0x3e7cd512, 
    0xbcedb065, 0x3ca2f0b1, 0xbc783e7c, 0xbe483b3b, 0xbe2f6031, 0x3e48208d, 0x3e14dcb3, 0x3c793663, 
    0x3d8927c1, 0xbed7f681, 0x3ee0068f, 0x3e6370c2, 0x3e9c9529, 0xbeb5d3c4, 0xbd03d9cb, 0xbdbd0ab5, 
    0x3f00b5bd, 0x3ed9abe4, 0xbe846fed, 0x3ea2106a, 0xbd9ee14b, 0x3e7c8280, 0x3e884405, 0xbe6f3a06, 
    0x3ec3fbd6, 0x3e205899, 0xbeb0fe52, 0xbedf0f15, 0xbe180134, 0xbd96ed7b, 0x3eb99a83, 0xbf092c6d, 
    0xbe40f280, 0xbe048a75, 0x3eac6a25, 0xbe6d3af6, 0xbdc8c3d8, 0x3eac5d13, 0xbead0625, 0x3e4f0749, 
    0xbd8561af, 0x3e8926ca, 0x3ea9a026, 0xbeb53df5, 0xbeea11be, 0x3e1237c7, 0xbf233c9f, 0x3d27e294, 
    0xbea5d947, 0xbeaf5ce8, 0x3e96ead6, 0x3ee29b50, 0x3e24e46b, 0xbeb7b3d4, 0x3e103670, 0x3e9a9001, 
    0x3d9477c1, 0x3e3177ed, 0xbdff3278, 0xbeab7e4e, 0xbeba0c56, 0x3eaadf76, 0x3d85391b, 0x3e06e329, 
    0xbea908de, 0x3e20cdd0, 0x3dd6ddd9, 0xfffffe26, 0x00000004, 0x00000040, 0xbe7ef9d4, 0x401ce70b, 
    0x3f8230ec, 0xbf42a381, 0xbfce68b3, 0xbed3c481, 0xc01c9c1f, 0xc0059d2e, 0x3f94167b, 0x3f7dbf08, 
    0xbfbf5b9e, 0xbe55b7af, 0x3fabdb76, 0xbd5d04d6, 0xbf60bef2, 0xc0441051, 0xfffffe72, 0x00000004, 
    0x00000040, 0xbedf7f9e, 0xbf3ffd1b, 0x3f80773a, 0xbe9ec28b, 0xbf8a7f54, 0x3e8796ce, 0xbe2c9b22, 
    0x3eb8e12d, 0x3f0c132c, 0x3e0ea890, 0xbe02a89c, 0x3f94c232, 0x3dd19aab, 0xbf78983d, 0x3faf3a13, 
    0x3f9680ce, 0xfffffebe, 0x00000004, 0x00000080, 0xbff84ba7, 0xbf96c91c, 0x3f5d9172, 0xbfb57afe, 
    0xbc9a1d14, 0xbf2adf51, 0xbf33f917, 0xbf07ed4f, 0xbfcd9757, 0x3f37023a, 0xbe1b08be, 0xbf448aec, 
    0xbec764c3, 0x3e516cb9, 0x3f0c6380, 0xbf5ff2f2, 0x3fc9a55f, 0xbf45e239, 0x3e5b826a, 0xbfb8a7d1, 
    0xbe64eaed, 0xbf461272, 0x3f30a6e8, 0xbf265da7, 0x3edb2f6a, 0x3e75a90f, 0xbe445b33, 0x3d266c11, 
    0x3e989838, 0xbf3c762f, 0xbeaf92a0, 0xbf0b99d2, 0xffffebe8, 0xffffebec, 0x0000000f, 0x52494c4d, 
    0x6e6f4320, 0x74726576, 0x002e6465, 0x00000001, 0x00000014, 0x000e0000, 0x00140018, 0x000c0010, 
    0x00040008, 0x0000000e, 0x00000014, 0x0000001c, 0x000003dc, 0x000003e0, 0x000003e4, 0x00000004, 
    0x6e69616d, 0x00000000, 0x00000010, 0x000003a0, 0x00000344, 0x000002e4, 0x000002a0, 0x0000025c, 
    0x00000238, 0x000001e4, 0x000001c0, 0x0000017c, 0x00000138, 0x00000114, 0x000000d0, 0x000000ac, 
    0x00000078, 0x00000040, 0x00000004, 0xfffffd06, 0x0000001c, 0x09000000, 0x0000001c, 0x00000020, 
    0x00000005, 0x00060000, 0x00040008, 0x00000006, 0x3f800000, 0x00000001, 0x00000024, 0x00000001, 
    0x00000023, 0xfffffd3e, 0x00000014, 0x08000000, 0x00000010, 0x00000014, 0x00000004, 0xffffecd4, 
    0x00000001, 0x00000023, 0x00000003, 0x00000022, 0x00000011, 0x00000012, 0xfffffd72, 0x00000014, 
    0x1b000000, 0x00000010, 0x00000014, 0x00000003, 0xffffed08, 0x00000001, 0x00000022, 0x00000002, 
    0x00000021, 0x00000013, 0xfffffd46, 0x00000008, 0x0000000c, 0x00000001, 0x00000021, 0x00000002, 
    0x00000020, 0x00000008, 0xfffffdc2, 0x00000014, 0x05000000, 0x00000024, 0x00000028, 0x00000002, 
    0xfffffefe, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x01000000, 0x00000001, 0x00000020, 
    0x00000001, 0x0000001f, 0xfffffda6, 0x00000008, 0x0000000c, 0x00000001, 0x0000001f, 0x00000002, 
    0x0000001e, 0x00000009, 0xfffffe22, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xfffffe70, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x0000001e, 0x00000003, 0x0000001d, 
    0x00000004, 0x00000001, 0xfffffe62, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 
    0xfffffeb0, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x0000001d, 0x00000003, 0x0000001c, 
    0x0000000c, 0x0000000d, 0xfffffe46, 0x00000008, 0x0000000c, 0x00000001, 0x0000001c, 0x00000002, 
    0x0000001b, 0x0000000a, 0xfffffec2, 0x00000024, 0x05000000, 0x00000034, 0x00000038, 0x00000002, 
    0x000e0000, 0x00170018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000002, 0x00000001, 0x00000002, 
    0x00000001, 0x01000000, 0x00000001, 0x0000001b, 0x00000001, 0x0000001a, 0xfffffeb6, 0x00000008, 
    0x0000000c, 0x00000001, 0x0000001a, 0x00000002, 0x00000019, 0x0000000b, 0xffffff32, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffff80, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x00000019, 0x00000003, 0x00000018, 0x00000005, 0x00000002, 0xffffff72, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffffc0, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x00000018, 0x00000003, 0x00000017, 0x0000000e, 0x0000000f, 0xffffffb2, 0x00000020, 
    0x01000000, 0x00000028, 0x0000002c, 0x00000001, 0x0010000c, 0x000c0000, 0x00070008, 0x0000000c, 
    0x01000000, 0x00000001, 0x00000002, 0x00000001, 0x00000017, 0x00000003, 0x00000016, 0x00000006, 
    0x00000003, 0x000e0000, 0x0014001a, 0x000c0010, 0x0004000b, 0x0000000e, 0x00000020, 0x01000000, 
    0x00000028, 0x0000002c, 0x00000001, 0x000a0000, 0x000f0010, 0x00040008, 0x0000000a, 0x00000001, 
    0x00000002, 0x01000000, 0x00000001, 0x00000016, 0x00000003, 0x00000015, 0x00000010, 0x00000007, 
    0x000a0000, 0x0000000c, 0x00040008, 0x0000000a, 0x00000008, 0x0000000c, 0x00000001, 0x00000015, 
    0x00000002, 0x00000000, 0x00000014, 0x00000001, 0x00000024, 0x00000001, 0x00000000, 0x00000025, 
    0x00000fd0, 0x00000f7c, 0x00000f40, 0x00000f04, 0x00000ebc, 0x00000e74, 0x00000e2c, 0x00000df0, 
    0x00000db0, 0x00000d58, 0x00000d18, 0x00000cd4, 0x00000c88, 0x00000c48, 0x00000bfc, 0x00000bbc, 
    0x00000b70, 0x00000b2c, 0x00000aec, 0x00000aac, 0x00000a40, 0x000009cc, 0x00000900, 0x000007c8, 
    0x00000700, 0x000005c8, 0x0000055c, 0x000004f4, 0x00000480, 0x000003b4, 0x00000278, 0x0000020c, 
    0x000001a4, 0x00000140, 0x000000e0, 0x00000050, 0x00000004, 0xfffff0da, 0x01000000, 0x00000010, 
    0x00000010, 0x00000025, 0x00000028, 0xfffff0c4, 0x00000019, 0x74617453, 0x6c756665, 0x74726150, 
    0x6f697469, 0x4364656e, 0x3a6c6c61, 0x00000030, 0x00000002, 0x00000001, 0x00000006, 0xfffff122, 
    0x01000000, 0x00000010, 0x00000010, 0x00000024, 0x0000006c, 0xfffff10c, 0x0000005e, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 
    0x2f39315f, 0x4d74614d, 0x6d3b6c75, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 
    0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x422f3931, 0x41736169, 0x00006464, 0x00000002, 
    0x00000001, 0x00000006, 0xfffff1ae, 0x01000000, 0x00000010, 0x00000010, 0x00000023, 0x0000003c, 
    0xfffff198, 0x0000002c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x2f38315f, 0x6e61654d, 0x00000000, 0x00000002, 0x00000001, 
    0x00000020, 0xfffff20a, 0x01000000, 0x00000010, 0x00000010, 0x00000022, 0x0000003c, 0xfffff1f4, 
    0x0000002f, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x2f36315f, 0x65757153, 0x00657a65, 0x00000003, 0x00000001, 0x00000003, 
    0x00000020, 0xfffff26a, 0x01000000, 0x00000010, 0x00000010, 0x00000021, 0x0000003c, 0xfffff254, 
    0x0000002f, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x2f36315f, 0x5078614d, 0x006c6f6f, 0x00000004, 0x00000001, 0x00000003, 
    0x00000001, 0x00000020, 0xfffff2ce, 0x01000000, 0x00000010, 0x00000010, 0x00000020, 0x00000040, 
    0xfffff2b8, 0x00000032, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x2f36315f, 0x61707845, 0x6944646e, 0x0000736d, 0x00000004, 
    0x00000001, 0x00000006, 0x00000001, 0x00000020, 0xfffff336, 0x01000000, 0x00000010, 0x00000010, 
    0x0000001f, 0x00000110, 0xfffff320, 0x00000103, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f35315f, 0x756c6552, 0x646f6d3b, 
    0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 
    0x34315f72, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x33315f72, 0x6e6f432f, 
    0x2f443176, 0x65757153, 0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f34315f, 0x63746162, 0x726f6e68, 0x756d2f6d, 
    0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 
    0x2f312d64, 0x6579616c, 0x33315f72, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 
    0x00000006, 0x00000020, 0xfffff46e, 0x01000000, 0x00000010, 0x00000010, 0x0000001e, 0x000000a0, 
    0xfffff458, 0x00000092, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f312d, 0x72657961, 0x2f32315f, 0x756c6552, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x31315f72, 0x6e6f432f, 
    0x2f443176, 0x65757153, 0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f31315f, 0x766e6f43, 0x00004431, 0x00000004, 
    0x00000001, 0x00000001, 0x00000006, 0x00000020, 0xfffff536, 0x01000000, 0x00000010, 0x00000010, 
    0x0000001d, 0x00000048, 0xfffff520, 0x00000039, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x2f31315f, 0x766e6f43, 0x452f4431, 
    0x6e617078, 0x6d694464, 0x00000073, 0x00000004, 0x00000001, 0x00000001, 0x00000006, 0x00000010, 
    0xfffff5a6, 0x01000000, 0x00000010, 0x00000010, 0x0000001c, 0x0000003c, 0xfffff590, 0x0000002e, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x4d2f395f, 0x6f507861, 0x00006c6f, 0x00000004, 0x00000001, 0x00000006, 0x00000001, 
    0x00000010, 0xfffff60a, 0x01000000, 0x00000010, 0x00000010, 0x0000001b, 0x00000040, 0xfffff5f4, 
    0x00000031, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x452f395f, 0x6e617078, 0x6d694464, 0x00000073, 0x00000004, 0x00000001, 
    0x0000000c, 0x00000001, 0x00000010, 0xfffff672, 0x01000000, 0x00000010, 0x00000010, 0x0000001a, 
    0x0000010c, 0xfffff65c, 0x000000fe, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x522f385f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x622f375f, 
    0x68637461, 0x6d726f6e, 0x6464612f, 0x6d3b315f, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 
    0x622d6d75, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f36, 0x4431766e, 0x7571532f, 
    0x657a6565, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 
    0x2f312d64, 0x6579616c, 0x2f375f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 
    0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 
    0x2f365f72, 0x766e6f43, 0x00004431, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000010, 
    0xfffff7a6, 0x01000000, 0x00000010, 0x00000010, 0x00000019, 0x0000009c, 0xfffff790, 0x0000008f, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x522f355f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x432f345f, 0x31766e6f, 0x71532f44, 0x7a656575, 
    0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 0x6d2d6431, 0x75696465, 0x61622d6d, 0x636e616c, 0x312d6465, 
    0x79616c2f, 0x345f7265, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 
    0x00000010, 0xfffff86a, 0x01000000, 0x00000010, 0x00000010, 0x00000018, 0x0000010c, 0xfffff854, 
    0x000000fe, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f312d, 0x72657961, 0x522f335f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x622f325f, 0x68637461, 0x6d726f6e, 
    0x6464612f, 0x6d3b315f, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 
    0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f31, 0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 
    0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 
    0x2f325f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f315f72, 0x766e6f43, 
    0x00004431, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000010, 0xfffff99e, 0x01000000, 
    0x00000010, 0x00000010, 0x00000017, 0x000000a0, 0xfffff988, 0x00000093, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x422f305f, 
    0x41736169, 0x6d3b6464, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 
    0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f30, 0x4431766e, 0x7571532f, 0x657a6565, 0x6f6d3b3b, 
    0x2f6c6564, 0x766e6f63, 0x6d2d6431, 0x75696465, 0x61622d6d, 0x636e616c, 0x312d6465, 0x79616c2f, 
    0x305f7265, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x00000018, 0x0000000d, 
    0xfffffa66, 0x01000000, 0x00000010, 0x00000010, 0x00000016, 0x00000048, 0xfffffa50, 0x00000039, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x432f305f, 0x31766e6f, 0x78452f44, 0x646e6170, 0x736d6944, 0x00000031, 0x00000004, 
    0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xfffffcd6, 0x01000000, 0x00000014, 0x00000014, 
    0x00000015, 0x02000000, 0x00000048, 0xfffffac4, 0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x432f305f, 0x31766e6f, 
    0x78452f44, 0x646e6170, 0x736d6944, 0x00000000, 0x00000001, 0x00000004, 0xfffffd3e, 0x01000000, 
    0x00000014, 0x00000014, 0x00000014, 0x02000000, 0x00000020, 0xfffffb2c, 0x00000010, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x3831746e, 0x00000000, 0x00000000, 0xfffffb7a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000013, 0x00000020, 0xfffffb64, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x3731746e, 0x00000000, 0x00000001, 0x00000006, 0xfffffbb6, 0x01000000, 0x00000010, 0x00000010, 
    0x00000012, 0x00000020, 0xfffffba0, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3631746e, 
    0x00000000, 0x00000002, 0x00000006, 0x00000020, 0xfffffbf6, 0x01000000, 0x00000010, 0x00000010, 
    0x00000011, 0x00000020, 0xfffffbe0, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3531746e, 
    0x00000000, 0x00000004, 0x0000000d, 0x00000001, 0x00000003, 0x0000001e, 0xfffffc3e, 0x01000000, 
    0x00000010, 0x00000010, 0x00000010, 0x00000020, 0xfffffc28, 0x00000010, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x3431746e, 0x00000000, 0x00000001, 0x00000010, 0xfffffc7a, 0x01000000, 0x00000010, 
    0x00000010, 0x0000000f, 0x00000020, 0xfffffc64, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x3331746e, 0x00000000, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 0x00000010, 0xfffffcc2, 
    0x01000000, 0x00000010, 0x00000010, 0x0000000e, 0x00000020, 0xfffffcac, 0x00000010, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x3231746e, 0x00000000, 0x00000001, 0x00000020, 0xfffffcfe, 0x01000000, 
    0x00000010, 0x00000010, 0x0000000d, 0x00000020, 0xfffffce8, 0x00000010, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x3131746e, 0x00000000, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 0x00000010, 
    0xffffff46, 0x01000000, 0x00000014, 0x00000014, 0x0000000c, 0x02000000, 0x00000020, 0xfffffd34, 
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3031746e, 0x00000000, 0x00000001, 0x00000004, 
    0xffffff86, 0x01000000, 0x00000014, 0x00000014, 0x0000000b, 0x02000000, 0x0000001c, 0xfffffd74, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0039746e, 0x00000001, 0x00000004, 0xffffffc2, 
    0x01000000, 0x00000014, 0x00000014, 0x0000000a, 0x02000000, 0x0000001c, 0xfffffdb0, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0038746e, 0x00000001, 0x00000004, 0x00160000, 0x0018001c, 
    0x00100017, 0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 
    0x00000009, 0x02000000, 0x0000001c, 0xfffffe04, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0037746e, 0x00000001, 0x00000003, 0xfffffe52, 0x01000000, 0x00000010, 0x00000010, 0x00000008, 
    0x0000001c, 0xfffffe3c, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 
    0x0000000d, 0xfffffe8a, 0x01000000, 0x00000010, 0x00000010, 0x00000007, 0x0000001c, 0xfffffe74, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0035746e, 0x00000004, 0x00000010, 0x00000001, 
    0x00000003, 0x0000000d, 0xfffffece, 0x01000000, 0x00000010, 0x00000010, 0x00000006, 0x0000001c, 
    0xfffffeb8, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0034746e, 0x00000004, 0x00000010, 
    0x00000001, 0x00000003, 0x00000010, 0xffffff12, 0x01000000, 0x00000010, 0x00000010, 0x00000005, 
    0x0000001c, 0xfffffefc, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0033746e, 0x00000004, 
    0x00000020, 0x00000001, 0x00000003, 0x00000020, 0xffffff56, 0x01000000, 0x00000010, 0x00000010, 
    0x00000004, 0x0000001c, 0xffffff40, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0032746e, 
    0x00000001, 0x00000010, 0xffffff8e, 0x01000000, 0x00000010, 0x00000010, 0x00000003, 0x0000001c, 
    0xffffff78, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0031746e, 0x00000001, 0x00000010, 
    0xffffffc6, 0x01000000, 0x00000010, 0x00000010, 0x00000002, 0x0000001c, 0xffffffb0, 0x0000000e, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0000746e, 0x00000001, 0x00000020, 0x00160000, 0x00140018, 
    0x00100000, 0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 
    0x00000001, 0x0000002c, 0x00040004, 0x00000004, 0x00000019, 0x76726573, 0x5f676e69, 0x61666564, 
    0x5f746c75, 0x6579616c, 0x3a305f72, 0x00000030, 0x00000003, 0x00000001, 0x00000032, 0x0000001e, 
    0x00000006, 0x00000060, 0x00000044, 0x00000034, 0x00000024, 0x00000014, 0x00000004, 0xffffffc4, 
    0x00000019, 0x19000000, 0xffffffd0, 0x00000009, 0x09000000, 0xffffffdc, 0x00000028, 0x28000000, 
    0xffffffe8, 0x00000011, 0x11000000, 0xfffffff4, 0x00000003, 0x03000000, 0x000c000c, 0x0000000b, 
    0x00040000, 0x0000000c, 0x00000016, 0x16000000
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
#define _K7              ((uint8_t *)_k7)                    // u8[39312] (39312 bytes)
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
*  @param data_out Output features. Output float[6].
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
    __RETURN_ERROR(mtb_model_raw(_K10, _K4, 1500, data_out, 24));
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
    __RETURN_ERROR(mtb_init(_K10, _K7, 39312, _K6, 16384, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0x29, 0x09, 0x5f, 0xf6, 0xa7, 0x7b, 0xa2, 0x44, 0x91, 0xe5, 0x1c, 0x77, 0x61, 0x60, 0xb0, 0xde},
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
        .size = 41424,
        .peak_usage = 41424,
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
                            .size = 6,
                            .labels = (label_text_t[]) { "unlabeled","back","left","front","right","noise" },
                        },
                    },
                    .count = 6,
                    .bytes = 24,
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

