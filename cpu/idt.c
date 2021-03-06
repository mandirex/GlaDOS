#include "idt.h"
void set_idt_gate(int n, uint32 handler) {
    idt[n].low_offset = ((handler) & 0xFFFF);
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].high_offset = (((handler) >> 16) & 0xFFFF);
}

void set_idt() {
    idt_reg.base = (uint32) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    // dont load idt load idt_reg
    asm volatile("lidtl (%0)" : : "r" (&idt_reg));
}