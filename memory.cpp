/**
 * memory.cpp
 *
 * Author   Jonathan Lo < >
 */
#include "includes.h"

char memflag1value_mem [16];
char out1value_mem [16];
char print_mem [256];

void memory1 ( );
void memory2 ( );

void read_data_cache(){ data_cache.READ(); }
/**
 * write_ra
 * was data_cache.READ()
 * ra: REG_SIZE-7, REG_SIZE - 11
 * rc: REG_SIZE-28, 0
 * func
 */
void write_reg (int upper, int lower, void (*f)(StorageObject& rx))
{
    long rx = ir_em ( upper, lower );
    ( *regfile[rx] ).latchFrom ( dbus_m.OUT ( ) );
    dbus_m.IN ( ).pullFrom ( out_em );
}

void memory1() { //TODO - handle no-ops
    int mem_type = mem_flag.value(); //keep this around
    mm_controlbus.IN().pullFrom(mem_flag);
    mm_internal_type.latchFrom(mm_controlbus.OUT());
    if (mem_type == 1 || mem_type == 2) {
        //data_cache.MAR().latchFrom(addr_bus.OUT()); - cheating in execute
        //addr_bus.IN().pullFrom(ex_out_addr);
        //store for next cycle - STL only
        dbus_m.IN().pullFrom(out_em);
        mm_internal_arith.latchFrom(dbus_m.OUT());
    } else if (mem_type == 3) {
        long rx = ir_em ( 25, 21 );
        ( *regfile[rx] ).latchFrom ( dbus_m.OUT ( ) );
        dbus_m.IN ( ).pullFrom ( out_em );
    }
    sprintf ( memflag1value_mem, "memflag=%02lx",
              mem_flag.value ( ) );
    sprintf ( out1value_mem, "out=%08lx",
              out_em.value ( ) );
}

void simple_mem(StorageObject& rx) { rx.latchFrom(data_cache.READ()); }
void memory2() {
    int mem_type = mem_flag.value();
    sprintf ( print_mem, "|M| %-10s %-12s | ",
              memflag1value_mem,
              out1value_mem );
    cout << print_mem ;

    if (mem_type == 0) { }
    
    if (mem_type == 2) {
        data_cache.WRITE().pullFrom(mm_internal_arith); 
        data_cache.write();
    }
    if (mem_type == 1) {
        write_reg(REG_SIZE - 7, REG_SIZE - 11, simple_mem);
        mm_external_load.latchFrom(data_cache.READ()); //pipeline reg; forward 
        data_cache.read();
   }
    //forward to execute just in case it needs it
    if (mem_type == 3) {
        mm_external_arith.latchFrom(mm_hazard_bus.OUT());
        mm_hazard_bus.IN().pullFrom(mm_internal_arith);
    }

    
}


// $(filename) end
