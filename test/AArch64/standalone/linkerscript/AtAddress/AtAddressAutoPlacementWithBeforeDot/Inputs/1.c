__attribute__((section(".foo1"))) int foo1() { return 0; }
__attribute__((section(".foo2"))) int foo2() { return 0; }
__attribute__((section(".foo3"))) int foo3() { return 0; }
__attribute__((section(".bar"))) int bar() { return 0; }
__attribute__((section(".baz@0x310"))) int baz() { return 0; }
