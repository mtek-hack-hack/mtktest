/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */































#ifndef _brs_siin_h
#define _brs_siin_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS
#include "msf_cmmn.h"

#include "brs_sisi.h"

typedef enum {JUMP_FW_S, JUMP_BW_S, TJUMP_FW_S, LOAD_VAR_S} brs_si_type1XXPPPPP;

typedef enum {STORE_VAR_S, LOAD_CONST_S} brs_si_type010XPPPP;

typedef enum {CALL_S, CALL_LIB_S, INCR_VAR_S} brs_si_type011XXPPP;

typedef enum {
  JUMP_FW = 0x01,     JUMP_FW_W,          JUMP_BW,
  JUMP_BW_W,          TJUMP_FW,           TJUMP_FW_W,
  TJUMP_BW,           TJUMP_BW_W,         CALL,
  CALL_LIB,           CALL_LIB_W,         CALL_URL,
  CALL_URL_W,         LOAD_VAR,           STORE_VAR,
  INCR_VAR,           DECR_VAR,           LOAD_CONST,
  LOAD_CONST_W,       CONST_0,            CONST_1,
  CONST_M1,           CONST_ES,           CONST_INVALID,
  CONST_TRUE,         CONST_FALSE,        INCR,
  DECR,               ADD_ASG,            SUB_ASG,
  UMINUS,             ADD,                SUB,
  MUL,                DIV,                IDIV,
  REM,                B_AND,              B_OR,
  B_XOR,              B_NOT,              B_LSHIFT,
  B_RSSHIFT,          B_RSZSHIFT,         EQ,
  LE,                 LT,                 GE,
  GT,                 NE,                 NOT,
  SCAND,              SCOR,               TOBOOL,
  POP,                TYPEOF,             ISVALID,
  RETURN,             RETURN_ES,          INSTR_DEBUG
} brs_si_type00XXXXXX;

int brs_si_ExecBytecodeInstr (MSF_UINT8 instr, brs_si_si_t *si);


int brs_si_Exec_JUMP_FW_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_JUMP_FW (brs_si_si_t *si);
int brs_si_Exec_JUMP_FW_W (brs_si_si_t *si);
int brs_si_Exec_JUMP_BW_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_JUMP_BW (brs_si_si_t *si);
int brs_si_Exec_JUMP_BW_W (brs_si_si_t *si);
int brs_si_Exec_TJUMP_FW_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_TJUMP_FW (brs_si_si_t *si);
int brs_si_Exec_TJUMP_FW_W (brs_si_si_t *si);
int brs_si_Exec_TJUMP_BW (brs_si_si_t *si);
int brs_si_Exec_TJUMP_BW_W (brs_si_si_t *si);


int brs_si_Exec_CALL_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_CALL (brs_si_si_t *si);
int brs_si_Exec_CALL_LIB_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_CALL_LIB (brs_si_si_t *si);
int brs_si_Exec_CALL_LIB_W (brs_si_si_t *si);
int brs_si_Exec_CALL_URL (brs_si_si_t *si);
int brs_si_Exec_CALL_URL_W (brs_si_si_t *si);


int brs_si_Exec_LOAD_VAR_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_LOAD_VAR (brs_si_si_t *si);
int brs_si_Exec_STORE_VAR_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_STORE_VAR (brs_si_si_t *si);
int brs_si_Exec_INCR_VAR_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_INCR_VAR (brs_si_si_t *si);
int brs_si_Exec_DECR_VAR (brs_si_si_t *si);


int brs_si_Exec_LOAD_CONST_S (MSF_UINT8 instr, brs_si_si_t * si);
int brs_si_Exec_LOAD_CONST (brs_si_si_t *si);
int brs_si_Exec_LOAD_CONST_W (brs_si_si_t *si);
int brs_si_Exec_CONST_0 (brs_si_si_t *si);
int brs_si_Exec_CONST_1 (brs_si_si_t *si);
int brs_si_Exec_CONST_M1 (brs_si_si_t *si);
int brs_si_Exec_CONST_ES (brs_si_si_t *si);
int brs_si_Exec_CONST_INVALID (brs_si_si_t *si);
int brs_si_Exec_CONST_TRUE (brs_si_si_t *si);
int brs_si_Exec_CONST_FALSE (brs_si_si_t *si);


int brs_si_Exec_INCR (brs_si_si_t *si);
int brs_si_Exec_DECR (brs_si_si_t *si);
int brs_si_Exec_ADD_ASG (brs_si_si_t *si);
int brs_si_Exec_SUB_ASG (brs_si_si_t *si);
int brs_si_Exec_UMINUS (brs_si_si_t *si);
int brs_si_Exec_ADD (brs_si_si_t *si);
int brs_si_Exec_SUB (brs_si_si_t *si);
int brs_si_Exec_MUL (brs_si_si_t *si);
int brs_si_Exec_DIV (brs_si_si_t *si);
int brs_si_Exec_IDIV (brs_si_si_t *si);
int brs_si_Exec_REM (brs_si_si_t *si);


int brs_si_Exec_B_AND (brs_si_si_t *si);
int brs_si_Exec_B_OR (brs_si_si_t *si);
int brs_si_Exec_B_XOR (brs_si_si_t *si);
int brs_si_Exec_B_NOT (brs_si_si_t *si);
int brs_si_Exec_B_LSHIFT (brs_si_si_t *si);
int brs_si_Exec_B_RSSHIFT (brs_si_si_t *si);
int brs_si_Exec_B_RSZSHIFT (brs_si_si_t *si);


int brs_si_Exec_EQ (brs_si_si_t *si);
int brs_si_Exec_LE (brs_si_si_t *si);
int brs_si_Exec_LT (brs_si_si_t *si);
int brs_si_Exec_GE (brs_si_si_t *si);
int brs_si_Exec_GT (brs_si_si_t *si);
int brs_si_Exec_NE (brs_si_si_t *si);


int brs_si_Exec_NOT (brs_si_si_t *si);
int brs_si_Exec_SCAND (brs_si_si_t *si);
int brs_si_Exec_SCOR (brs_si_si_t *si);
int brs_si_Exec_TOBOOL (brs_si_si_t *si);


int brs_si_Exec_POP (brs_si_si_t *si);


int brs_si_Exec_TYPEOF (brs_si_si_t *si);
int brs_si_Exec_ISVALID (brs_si_si_t *si);


int brs_si_Exec_RETURN (brs_si_si_t *si);
int brs_si_Exec_RETURN_ES (brs_si_si_t *si);


int brs_si_Exec_DEBUG (brs_si_si_t *si);

#endif
#endif
