/**
 * hardware.h
 *
 * Author   Nathan Castle < >
 *          Jonathan Lo <jcl5201>
 * global hardware instantiations
 */
#ifndef _HARDWARE_H
#define _HARDWARE_H

#include "includes.h"

/**
 * GLOBAL SIZES
 */
extern unsigned int ADDR_SIZE;   //
extern unsigned int OPC_SIZE;    // OP SIZE
extern unsigned int REG_SIZE;    // REGISTER SIZE
extern unsigned int DATA_SIZE;   // DATA SIZE

/**
 * INSTRUCTION OPCODE CONSTANTS
 */
enum INSTRS {
    OPC_NOOP = 0, OPC_LDA = 8,
    OPC_LDAH = 9, OPC_LDBU = 10,
    OPC_LDL	 = 40, OPC_LDWU = 12,
    OPC_STL	 = 44, OPC_STW = 13,
    OPC_JMP	 = 26, OPC_RPCC = 24,
    OPC_ADDL = 16,
    OPC_AND	 = 17,
    OPC_BGE	 = 62, OPC_JSR = 260,
    OPC_RET	 = 2600, OPC_JSRC = 26000,
    OPC_BGT	 = 63, OPC_BEQ = 57,
    OPC_BLBS = 60, OPC_BLE = 58,
    OPC_BLBC = 56, OPC_BLT = 59,

    OPC_BNE	 = 61, OPC_BR = 48,
    OPC_BSR	 = 52
};
//Note: because these instructions all share opcodes, decisions should not be made based on their values
//eg. reading an opcode of 16 could mean many things. Once you decode the true function, store it separately
#define OPC_ADDL 16
#define OPC_S4ADDL 16
#define OPC_S8ADDL 16
#define OPC_S4SUBL 16
#define OPC_S8SUBL 16
#define OPC_BIC 17
#define OPC_BIS 17
#define OPC_EQV 17
#define OPC_ORNOT 17
#define OPC_XOR 17
#define OPC_CMOVEQ 17
#define OPC_CMOVGE 17
#define OPC_CMOVGT 17
#define OPC_CMOVBLC 17
#define OPC_CMOVBLS 17
#define OPC_CMOVLE 17
#define OPC_CMOVLT 17
#define OPC_CMOVNE 17
#define OPC_SLL 17
#define OPC_SRL 17
/**
 * SPECIAL RESERVED REGISTERS
 */
extern Clearable not3_g;
extern Clearable mult4_g;
extern Clearable shift11_g;

/**
 * SPECIAL RESERVED BUSES FOR SRR
 */
extern Bus mm_controlbus;

extern Counter mm_internal_arith;
extern Counter mm_internal_type;
/**
 * PIPELINE REGISTERS
 */
extern Counter pc_ir;        // pc issue read
extern Counter npc_ir;       // npc issue read
extern Counter pc_r;
extern Counter pc_re;        // pc read execute
extern Counter pc_em;        // pc execute memory
extern Clearable ir_ir;      // ir issue read
extern Clearable ir_re;      // ir read execute
extern Counter aux_r;        // aux read
extern Clearable dispmask_g; //2097151
extern Clearable shift11_g;
extern Clearable lock_ir;  // lock issue read
extern Clearable lock_re;  // lock read execute
extern Clearable disp_r;   // disp read
extern Clearable disp_re;  // disp read execute
extern Clearable li_r;     // literal read
extern Counter li_re;      // literal read execute
extern Clearable func_r;   // func read
extern Clearable func_re;  // func read execute
extern Counter ra_re;      // ra read execute
extern Counter rb_re;      // rb read execute
extern Counter rc_re;      // rc read execute
extern Counter aux_re;     // aux read execute
extern Counter ex_internal_arith;
extern Counter ex_internal_shift;
extern Counter ex_internal_addr;
extern Counter ex_internal_ir;
extern Counter ex_out_addr;
extern Counter ex_out_arith;
extern Counter out_em;     // out execute memory
extern Counter pc_em;      // pc execute memory
extern Clearable ir_em;    // reg_addr execute memory
// extern Clearable  out_m; // out memory
extern Counter addr_em;   // addr execute memory
extern Clearable data_m;  // data memory
extern Counter literal_re;
extern StorageObject exec_const_2;
extern StorageObject exec_const_3;
extern StorageObject exec_const_not_3;
extern StorageObject exec_const_16;

extern Constant no_mem;
extern Constant read_mem;
extern Constant write_mem;
extern Constant writeback;
/**
 * BUSES
 */
extern Bus outbus_em;     // out bus execute memory
extern Bus addrbus_em;    // addr bus execute memory
extern Bus addrbus_m;     // addr bus memory
extern Bus dbus_m;        // dbus memory

/**
 * ALU
 */
extern BusALU destalu_i;      // mask alue
extern BusALU leftShift_alu;  // left shift alu
extern BusALU rightShift_alu; // right shift alu
extern BusALU dest_alu;       // pc alu
extern BusALU arith_alu;      // arith alu
extern BusALU shift_alu;      // shift alu
extern BusALU addr_alu;       // addr alu

/**
 * Programmer-viewable registers
 */
extern Counter* regfile[];

extern Bus irbus_e;
/* cache */
extern Memory instr_cache;
extern Memory data_cache;

extern bool done;

#endif

// $(filename) END
