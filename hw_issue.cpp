/**
 * hw_issue
 *
 * Author   Jonathan Lo < >
 */
#include "hw_issue.h"
Clearable pc_i ( "PC_I", REG_SIZE );
Clearable pc_ir ( "PC_IR", REG_SIZE );
Clearable npc_ir ( "NPC_IR", REG_SIZE );
Clearable ir_i ( "IR_I", REG_SIZE );
Clearable ir_ir ( "IR_IR", REG_SIZE );
Clearable aux_i ( "AUX_I", REG_SIZE );
Bus pcbus_i1 ( "PCBUS_I1", REG_SIZE );
Bus irbus_i1 ( "IRBUS_I1", REG_SIZE );
Bus irbus_i2 ( "IRBUS_I2", REG_SIZE );
Bus pcbus_i2 ( "PCBUS_I2", REG_SIZE );
BusALU destalu_i2 ( "LEFTSHIFT_ALU", REG_SIZE );
BusALU destalu_i1 ( "DESTALU_ISSUE", REG_SIZE );
// $(filename)
