#ifndef _VM_H_
#define _VM_H_

#include <string>
#include <map>

#include "scope.hpp"
#include "stack.hpp"

class Scope;
class Value;
class ValueStack;
class Block;
class Module;

class VM {
public:
  VM();
  virtual ~VM();
  
  // add a new block to the VM
  void AddBlock(Block& b);

  // fetch a block by name (for calling or whatever)
  Block* GetBlock(std::string name);

  // returns the stack
  ValueStack& GetStack();

  // returns the global scope
  Scope& GetScope();

  // call a named block
  void Call(std::string name, ValueStack& args);

  // call a passed block
  void Call(Block& block, ValueStack& args);

  // set a global value
  void SetGlobal(std::string name, Value val);
  void SetGlobal(std::string name, StringValue val);
  void SetGlobal(std::string name, NumericValue val);
  void SetGlobal(std::string name, BlockValue val);

  // get a global value
  Value* GetGlobal(std::string name);

  // load a new module into the VM
  void LoadModule(Module* m);

  // open all the standard modules
  void OpenLibraries();

private:
  void SetGlobal(std::string name, Value* v);

  Scope m_globalScope;
  std::map<std::string, Block> m_blocks;
  ValueStack m_stack;
};

#endif /* _VM_H_ */
