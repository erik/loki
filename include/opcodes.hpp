#ifndef _OPCODES_H_
#define _OPCODES_H_

/**
 * Stack setup for OP_CALL
 * TOS[Block To Call], numargs, arg1, arg2, arg3, ...
 *
 * called as BlockToCall(arg1, arg2, arg3, ...)
 *
 * All args passed to the block are popped off the VM's stack, and passed as
 * a new stack to the block
 */

enum Opcode {
  OP_NOP        = 0,     // Nothing

  OP_POPSTACK      ,     // Pops the top value off the stack
  OP_CLEARSTACK    ,     // Clears the stack

  OP_LOADBLOCK     ,     // Pops string off stack naming Block, pushes corresponding block as lambda or nil 
  OP_CALL          ,     // Calls block

  OP_TOSTRING      ,     // Pops top of stack, pushes string representation

  OP_NUM_OPS             // Not an opcode, just the number of opcodes
};

#endif /* _OPCODES_H_ */
