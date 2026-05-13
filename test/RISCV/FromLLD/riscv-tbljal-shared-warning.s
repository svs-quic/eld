## --relax-tbljal is incompatible with shared-library links.
#
# RUN: %llvm-mc -filetype=obj -mattr=+relax,+zcmt %s -o %t.o
# RUN: %link %linkopts -shared %t.o --relax-tbljal --defsym foo=0x150000 -o %t.so 2>&1 | %filecheck --check-prefix=WARN %s
# RUN: %objdump -d -M no-aliases --mattr=+zcmt --no-show-raw-insn %t.so | %filecheck --check-prefix=DISASM %s
#
# WARN: Option `-relax-tbljal' is disabled as it is incompatible with `-shared`
# DISASM-NOT: cm.jt
# DISASM-NOT: cm.jalt

.global _start
.p2align 2
_start:
  .rept 20
  call foo
  .endr
