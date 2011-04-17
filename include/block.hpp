#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "opcodes.hpp"

#include <vector>
#include <string>

class VM;
class ValueStack;

// A block of code, comparable to a function
class Block {
public:
  Block();
  Block(std::string name, VM* vm = NULL);

  virtual ~Block();

  // add an instruction to the block
  void AddInstruction(Opcode op);

  // call the block. this is where the execution actually happens
  void Call(ValueStack& args);

  // setters
  void SetVM(VM* vm);
  void SetName(std::string name);

  // getters
  std::string GetName() const;
  unsigned int GetSize();

private:
  std::string m_name;
  VM *m_vm;
  std::vector<Opcode> m_opcodes;
};

#endif /* _BLOCK_H_ */
