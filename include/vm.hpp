#ifndef _VM_H_
#define _VM_H_

#include "opcodes.hpp"
#include "value.hpp"
#include "stack.hpp"

#include <vector>

class VM {
public:
  VM();
  virtual ~VM();
  
  Value Interpret(ValueStack& args);
  
private:
  std::vector<Opcodes> m_opcodes;
  unsigned int m_instructionPointer;
  ValueStack m_stack;
};

#endif /* _VM_H_ */
