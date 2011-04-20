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

/**
 * OP_{SET, GET}BINDING
 *
 * SETBINDING:
 * Expects TOS->NAME[string], TYPE[int], VALUE[any]
 * VALUE is the value to be set
 * TYPE is either 0 or 1.
 * 0 means set at local scope
 * 1 means set at global scope
 * NAME is the name of VALUE
 *
 * GETBINDING: 
 * expects TOS->NAME[string], TYPE[int]
 * TYPE is either -1, 0, or 1, and specifies how NAME will be looked up
 * -1 means search local scope first, going to global if not found
 * 0 means search only local scope
 * 1 means search global scope only, skipping possibly overwritten values in local scope
 */

enum Opcode {
  OP_NOP        = 0,     // Nothing

  OP_POPSTACK      ,     // Pops the top value off the stack
  OP_CLEARSTACK    ,     // Clears the stack

  OP_LOADBLOCK     ,     // Pops string off stack naming Block, pushes corresponding block as lambda or nil 
  OP_CALL          ,     // Calls block, see note

  OP_TOSTRING      ,     // Pops top of stack, pushes string representation
  OP_INSPECT       ,     // Pops top of stack, pushes a debug string representation

  OP_PRINT         ,     // Pops top of stack, converts to string, prints

  // See note above for next two
  OP_SETBINDING    ,     // Pops *, int, string
  OP_GETBINDING    ,     // Pops int, string, push Value

  OP_NUM_OPS             // Not an opcode, just the number of opcodes
};

#endif /* _OPCODES_H_ */
