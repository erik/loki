#include "vm.hpp"

#include <iostream>

VM::VM()
{
}

VM::~VM()
{
}

void VM::AddBlock(Block& b)
{
  m_blocks[b.GetName()] = b;
}

Block *VM::GetBlock(std::string name)
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
