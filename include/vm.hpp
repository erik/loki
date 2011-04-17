#ifndef _VM_H_
#define _VM_H_

#include "opcodes.hpp"
#include "value.hpp"
#include "stack.hpp"
#include "block.hpp"

#include <map>

class VM {
public:
  VM();
  virtual ~VM();
  
  // add a new block to the VM
  void AddBlock(Block& b);

  // fetch a block by name (for calling or whatever)
  Block *GetBlock(std::string name);

  // returns the stack
  ValueStack& GetStack();

  // call a named block
  void Call(std::string name, ValueStack& args);

  // call a passed block
  void Call(Block& block, ValueStack& args);

private:
  std::map<std::string, Block> m_blocks;
  ValueStack m_stack;
};

#endif /* _VM_H_ */
