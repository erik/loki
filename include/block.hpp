#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "opcodes.hpp"
#include "scope.hpp"

#include <vector>
#include <string>

class VM;
class ValueStack;

typedef void(*block_func)(VM* vm, ValueStack& stack);

// A block of code, comparable to a function
class Block {
public:
  Block();
  Block(std::string name, VM* vm = NULL);
  Block(std::string name, block_func fcn, VM* vm = NULL);

  virtual ~Block();

  // add an instruction to the block
  void AddInstruction(Opcode op);

  // call the block. this is where the execution actually happens
  void Call(ValueStack& args);

  // is this block an internal function?
  bool IsInternal();

  // setters
  void SetVM(VM* vm);
  void SetName(std::string name);
  void SetFunction(block_func fcn);

  // getters
  std::string GetName() const;
  unsigned int GetSize();
  Scope& GetScope();

private:
  VM *m_vm;
  Scope m_localScope;
  std::string m_name;
  std::vector<Opcode> m_opcodes;
  block_func m_function;
  bool m_internal;
};

#endif /* _BLOCK_H_ */
