// *-*- c -*-******************************************************************
// *
// *  Copyright Freescale 2013, All rights reserved.
// *  Copyright NXP 2017, All rights reserved.
// * 
// *  SPDX-License-Identifier: BSD-3-Clause
// *
// ***************************************************************************/
// ** \addtogroup IPUV_Defines.h
// *  @{
// ***************************************************************************/
// ** 
// *  
// *  \file      IPUV_Defines.adl
// *  \author    Stephan Herrmann, M.Staudenmaier
// *
// *  \internal
// *   language  ADL
// ***************************************************************************/

#ifndef __IPUV_DEFINES_H__
#define __IPUV_DEFINES_H__

//#define IGNORE_UNKNOWN_REG
#ifndef MAKEDOC
//#define SYSC  set in environment
#define LOG_MORE
#endif

// module version selection
//#define ISP2 set in environment before compiling

#ifdef ISP2
#define ACC24
#define HASABSANGLE
#define SELAUTOINC
#define LOOPCNT_B
#endif

#ifdef HASABSANGLE
#define HASACC
#endif


// module configuration
#define INPUT_STREAMS  5   // always 5!!
#define OUTPUT_STREAMS 3   // 1 to 3
#define STREAM_IPS_IN_IPU  // the StreamDMA peripheral register space is part 

#define OUTPUT_STREAM1
#define OUTPUT_STREAM2

// Simulator Options
//#define COMBINATORIAL
//#define CL_LINE_DONE
#ifdef COMBINATORIAL
#define PRECYCLE
#endif
#ifdef CL_LINE_DONE
#define PRECYCLE
#endif

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


// Vector ALU Operation codes
typedef enum {
  VALU_OP_MOV    =  0,
  VALU_OP_ADD    =  1,
  VALU_OP_SUB    =  2,
  VALU_OP_ABSDIFF=  3,
  VALU_OP_MULH   =  4,
  VALU_OP_MULL   =  5,
  //VALU_OP_SQD    =  6,
  VALU_OP_AND    =  7,
  VALU_OP_OR     =  8,
  VALU_OP_XOR    =  9,
  VALU_OP_MIN    = 10,
  VALU_OP_MAX    = 11,
  VALU_OP_ASR    = 12,
  VALU_OP_LSR    = 13,
  VALU_OP_ASL    = 14,
  VALU_OP_CLZ    = 15,
} valu_op_t;


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

#endif  /* __IPUV_DEFINES_H__ */
