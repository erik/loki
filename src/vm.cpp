#include "vm.hpp"

#include "opcodes.hpp"
#include "value.hpp"
#include "block.hpp"
#include "module.hpp"

#include "modules/math.hpp"

#include <iostream>

VM::VM()
  : m_globalScope(NULL)
{
}

VM::~VM()
{
}

void VM::AddBlock(Block& b)
{
  m_blocks[b.GetName()] = b;
}

Block* VM::GetBlock(std::string name)
{
  std::map<std::string, Block>::iterator it = m_blocks.find(name);
  
  if(it == m_blocks.end()) {
    return NULL;
  }

  return &it->second;
}

ValueStack& VM::GetStack()
{
  return m_stack;
}

Scope& VM::GetScope()
{
  return m_globalScope;
}

void VM::Call(std::string name, ValueStack& args)
{
  std::map<std::string, Block>::iterator it = m_blocks.find(name);

  if(it == m_blocks.end()) {
    std::cout << "nada" << std::endl;
    // TODO: push an error
    return;
  }

  Block block = it->second;

  return this->Call(block, args);
}

void VM::Call(Block& b, ValueStack& args)
{
  return b.Call(args);
}

void VM::SetGlobal(std::string name, Value val)
{
  SetGlobal(name, &val);
}

void VM::SetGlobal(std::string name, StringValue val)
{
  SetGlobal(name, &val);
}

void VM::SetGlobal(std::string name, NumericValue val)
{
  SetGlobal(name, &val);
}

void VM::SetGlobal(std::string name, BlockValue val)
{
  SetGlobal(name, &val);
}

void VM::SetGlobal(std::string name, Value* val)
{
  Value *v = m_globalScope.Get(name);
  Value* temp = val->CloneToPtr();

  if(v != NULL) {
    delete v;
  }

  m_globalScope.Set(name, temp);
}

Value* VM::GetGlobal(std::string name)
{
  Value* v = m_globalScope.Get(name);
  
  return v;
}

void VM::LoadModule(Module* m)
{
  m->Install(this);
}

void VM::OpenLibraries()
{
  this->LoadModule(MathModule::Instance());
}
