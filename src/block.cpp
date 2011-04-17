#include "block.hpp"
#include "vm.hpp"

#include <iostream>

Block::Block()
  : m_name("noname"), m_vm(NULL)
{
}

Block::Block(std::string name, VM* vm)
  : m_name(name), m_vm(vm)
{
}

Block::~Block()
{
}

void Block::AddInstruction(Opcode op)
{
  m_opcodes.push_back(op);
}

void Block::Call(ValueStack& args)
{
  unsigned size = this->GetSize();
  ValueStack& stack = m_vm->GetStack();

  Opcode op = OP_NOP;

  for(unsigned i = 0; i < size; ++i) {
    op = m_opcodes[i];

    switch(op) {
    case OP_NOP: {
      // welp, that was easy
      break;
    }
    case OP_POPSTACK: {
      Value* v = stack.Pop();
      std::cout << "Popped " << v->ToString() << std::endl;
      delete v;
      break;
    }
    case OP_CLEARSTACK: {
      stack.Clear();
      break;
    }
    case OP_LOADBLOCK: {
      break;
    }
    case OP_CALL: {
      if(!stack.CheckStack(1)) {
        std::cout << "Expected number of args" << std::endl;
      }
      break;
    }
    case OP_TOSTRING: {
      Value* v = stack.Pop();
      std::cout << "ToString -> " << v->ToString() << std::endl;
      stack.Push(StringValue(v->ToString()));
      delete v;
    }
    default:
      break;
    }
  }
}

void Block::SetVM(VM* vm)
{
  m_vm = vm;
}

void Block::SetName(std::string name)
{
  m_name = name;
}

std::string Block::GetName() const 
{
  return m_name;
}

unsigned int Block::GetSize()
{
  return m_opcodes.size();
}
