__attribute__((weak)) extern int foo();
extern int baz();
int bar() { return foo() + baz(); }
