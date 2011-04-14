#ifndef _OPCODES_H_
#define _OPCODES_H_

enum Opcodes {
  OP_NOP = 0,

  OP_PUSHSTACK,
  OP_POPSTACK,
  OP_CLEARSTACK,

  OP_NUM_OPS
};

#endif /* _OPCODES_H_ */
