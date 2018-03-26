// *-*- c -*-******************************************************************
// *
// *  Copyright Freescale 2013, All rights reserved.
// *  Copyright NXP 2017, All rights reserved.
// * 
// *  SPDX-License-Identifier: BSD-3-Clause
// *
// ***************************************************************************/
// ** \addtogroup IPUS_Defines.h
// *  @{
// ***************************************************************************/
// ** 
// *  
// *  \file      IPUS_Defines.adl
// *  \author    Stephan Herrmann, M.Staudenmaier
// *
// *  \internal
// *   language  ADL
// ***************************************************************************/

#ifndef __IPUS_DEFINES_H__
#define __IPUS_DEFINES_H__

//#define IGNORE_UNKNOWN_REG
#ifndef MAKEDOC
//#define SYSC  set in environment
#define LOG_MORE
#endif

// module version selection
#define MATRIX_INSTR_EXPLICIT_W

//#define ISP2 set in environment before compiling

#ifdef ISP2
#define ACC24
#define POWERSAVE_TREE
#define SELAUTOINC
#define LOOPCNT_B
#endif

// module configuration
#define HASINB
#define HASINALPHA         // keep always on, disable only stream
#define HASINALPHASTREAM
#define HASHIST
#define HASLUT
#define LUT4K
#define HASSTAT
#define HASPRNG
#define HASBEST5OFN
#define INPUT_STREAMS  3   // 3 always!!
#define OUTPUT_STREAMS 4   // 1 to 4
#define STREAM_IPS_IN_IPU  // the StreamDMA peripheral register space is part of the IPU peripheral space
//#define ACC_UPDATED_ON_READ
#define ACC_READ_ONLY
// do recoimpuation of AdderTree and SorterTree at end of
// line and halt (for matching with RTL)
#define ACC_EOL_RECOMPUTE

//#ifeq (OUTPUT_STREAMS,4)
#define OUTPUT_STREAM1
#define OUTPUT_STREAM2
#define OUTPUT_STREAM3
//#endif

// Simulator Options
//#define COMBINATORIAL
//#define CL_LINE_DONE
#ifdef COMBINATORIAL
#define PRECYCLE
#endif
#ifdef CL_LINE_DONE
#define PRECYCLE
#endif
#ifndef ACC_UPDATED_ON_READ
#define PRECYCLE
#endif


// loaction of memories in simulation
#define INST_MEM         (0)  //  64x32bit   -   255
#define HIST_OFFSET    (256)  // 256x32bit   -  1279 (1,25K)
#define LUT_OFFSET    (2048)  //4096x16bit   - 10239 (10K)
#define STAT_OFFSET  (10240)  // 256x4x32bit - 14335 (14K)
#define IMG_OFFSET   (16384)  // Mapped to SRAM

#define SMAX16 (0x7FFF)
#define SMIN16 (-0x8000)
#define UMAX16 (0xFFFF)
#define UMIN16 (0x0000)

#ifdef ACC24
  #define SMAXACC (0x7FFFFF)
  #define SMINACC (-0x800000)
  #define UMAXACC (0xFFFFFF)
  #define UMINACC (0x000000)
#else
  #define SMAXACC SMAX16
  #define SMINACC SMIN16
  #define UMAXACC UMAX16
  #define UMINACC UMIN16
#endif


// Scalar ALU Operation Codes
typedef enum {
  SALU_OP_MOV    =  0,
  SALU_OP_ADD    =  1,
  SALU_OP_SUB    =  2,
  SALU_OP_ABSDIFF=  3,
  SALU_OP_MULH   =  4,
  SALU_OP_MULL   =  5,
  //SALU_OP_SQD    =  6,
  SALU_OP_AND    =  7,
  SALU_OP_OR     =  8,
  SALU_OP_XOR    =  9,
  SALU_OP_MIN    = 10,
  SALU_OP_MAX    = 11,
  SALU_OP_ASR    = 12,
  SALU_OP_LSR    = 13,
  SALU_OP_ASL    = 14,
  SALU_OP_CLZ    = 15,
} salu_op_t;


// Matrix ALU Operation codes
typedef enum {
  MALU_OP_MOV    =  0,
  MALU_OP_ADD    =  1,
  MALU_OP_SUB    =  2,
  MALU_OP_ABSDIFF=  3,
  //MALU_OP_MULH   =  4,
  MALU_OP_THF    =  4,  // threshold filter
  //MALU_OP_MULL   =  5,
  MALU_OP_THM    =  5,
  //MALU_OP_SQD    =  6,
  MALU_OP_SWP    =  6,
  MALU_OP_AND    =  7,
  MALU_OP_OR     =  8,
  MALU_OP_XOR    =  9,
  MALU_OP_MIN    = 10,
  MALU_OP_MAX    = 11,
  MALU_OP_ASR    = 12,
  MALU_OP_LSR    = 13,
  MALU_OP_ASL    = 14,
  MALU_OP_CLZ    = 15,
} malu_op_t;

// Mask ALU Operation codes
typedef enum {
  MASKALU_OP_SET    =  0,
  MASKALU_OP_SEL    =  1,
  MASKALU_OP_INV    =  2,
  //MASKALU_OP_XXX    =  3,
  MASKALU_OP_THR    =  4,
  MASKALU_OP_ITH    =  5,
  //MASKALU_OP_XXX    =  6,
  MASKALU_OP_AND    =  7,
} maskalu_op_t;


/* branch conditions */
#define COND_AL  0   //< always
#define COND_NV  1   //< never
#define COND_EQ  2   //< equal (Z==1)
#define COND_NE  3   //< not equal (Z==0)
#define COND_CC  4   //< carry set (C==1)
#define COND_CS  5   //< carry set (C==0)
#define COND_MI  6   //< negative (N==1)
#define COND_PL  7   //< positive (N==0)
#define COND_OS  8   //< overflow set (O==1)
#define COND_OC  9   //< overflow cleared (O==0)
#define COND_GE 10   //< greater equal (signed arithmetics)
#define COND_LT 11   //< less than (signed arithmetics)
#define COND_HI 12   //< higher (unsigned arithmetics)
#define COND_LS 13   //< lower or same (unsigned arithmetics)
#define COND_GT 14   //< greater than (signed arithmetics)


// Condition Code Flags
#define F_O(x) (x.O==1)
#define F_C(x) (x.C==1)
#define F_N(x) (x.N==1)
#define F_Z(x) (x.Z==1)

#define F_OQ(x) (x.O==0)
#define F_CQ(x) (x.C==0)
#define F_NQ(x) (x.N==0)
#define F_ZQ(x) (x.Z==0)


// Statistics Operation Codes
typedef enum {
  STAT_OP_MAX    =  0,
  STAT_OP_MIN    =  1,
  STAT_OP_UACC   =  2,
  STAT_OP_SACC   =  3,
} stat_op_t;

#endif  /* __IPUS_DEFINES_H__ */
