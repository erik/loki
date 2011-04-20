#include "block.hpp"
#include "vm.hpp"

#include <iostream>

Block::Block()
  : m_vm(NULL), 
    m_localScope(NULL), 
    m_name("noname")

{
}

Block::Block(std::string name, VM* vm)
  : m_vm(vm),
    m_localScope(&vm->GetScope()), 
    m_name(name)
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
      if(!stack.CheckStack(1)) {
        std::cout << "Expected a name" << std::endl;
        break;
      }
      
      std::string name = stack.Pop()->ToString();

      Block* b = m_vm->GetBlock(name);
      if(!b) {
        std::cout << "Block " << name << " not found!" << std::endl;
        break;
      }

      stack.Push(BlockValue(*b));

      break;
    }
    case OP_CALL: {
      if(!stack.CheckStack(2)) {
        std::cout << "Expected block and number of args" << std::endl;
        break;
      }

      BlockValue* block     = static_cast<BlockValue*>(stack.Pop());
      NumericValue* numArgs = static_cast<NumericValue*>(stack.Pop());

      if(!numArgs->CheckType(TYPE_NUMERIC)) {
        std::cout << "Expected a numeric, got " << block->Inspect() << std::endl;
        break;
      }

      if(!block->CheckType(TYPE_BLOCK)) {
        std::cout << "Expected a block, got " << block->Inspect() << std::endl;
        break;
      }
      
      if(!stack.CheckStack((int)numArgs->Value())) {
        std::cout << "Not enough args on the stack! (needed " << (int)numArgs->Value() << ")"
                  << std::endl;
        break;
      }

      // TODO: copy over required args

      ValueStack args;
      
      block->GetBlock().Call(args);

      break;
    }
    case OP_PRINT: {
      if(!stack.CheckStack(1)) {
        std::cout << "Stack empty!" << std::endl;
        break;
      }
      Value* v = stack.Pop();
      std::cout << v->ToString();
      delete v;
      break;
    }
    case OP_TOSTRING: {
      Value* v = stack.Pop();
      stack.Push(StringValue(v->ToString()));
      delete v;
      break;
    }
    case OP_INSPECT: {
      Value* v = stack.Pop();
      stack.Push(StringValue(v->Inspect()));
      delete v;
      break;
    }
    case OP_SETBINDING: {
      if(!stack.CheckStack(3)) {
        std::cout << "Expected three arguments" << std::endl;
        break;
      }
      StringValue* bindingName = static_cast<StringValue*>(stack.Pop());
      NumericValue* scopeType = static_cast<NumericValue*>(stack.Pop());
      Value* value = stack.Pop();

      if(!bindingName->CheckType(TYPE_STRING)) {
        std::cout << "Expected a string, got " << bindingName->Inspect() << std::endl;
        break;
      } else if(!scopeType->CheckType(TYPE_NUMERIC)) {
        std::cout << "Expected a number, got " << scopeType->Inspect() << std::endl;
        break;
      }

      Scope* temp = NULL;
      switch((int)scopeType->Value()) {
      case 0:
        temp = &this->GetScope();
        break;
      case 1:
        temp = &m_vm->GetScope();
        break;
      }      

      Scope& scope = *temp;

      if(scope.HasBinding(bindingName->ToString(), false)) {
        delete scope.Get(bindingName->ToString(), false);
      }

      std::cout << "Setting " << bindingName->ToString() << " to " << value->ToString() << std::endl;
      scope.Set(bindingName->ToString(), value);

      delete scopeType;
      delete bindingName;

      break;
    }
    case OP_GETBINDING: {
      StringValue* bindingName = static_cast<StringValue*>(stack.Pop());
      NumericValue* scopeType  = static_cast<NumericValue*>(stack.Pop());
      Value* ret = NULL;

      if(!bindingName->CheckType(TYPE_STRING)) {
        std::cout << "Expected a string, got " << bindingName->Inspect() << std::endl;
        break;
      } else if(!scopeType->CheckType(TYPE_NUMERIC)) {
        std::cout << "Expected a number, got " << scopeType->Inspect() << std::endl;
        break;
      }

      std::string name = bindingName->ToString();

      Scope* temp = NULL;
      bool searchParent = false;

      switch((int)scopeType->Value()) {
      case -1:
        temp = &this->GetScope();
        searchParent = true;
        break;
      case 0:
        temp = &this->GetScope();
        break;
      case 1:
        temp = &m_vm->GetScope();
        break;
      }

      Scope& scope = *temp;

      delete bindingName;
      delete scopeType;
      
      ret = scope.Get(name, searchParent);

      if(ret == NULL) {
        std::cout << name << " not found in scope" << std::endl;  
        break;
      }

      switch(ret->Type()) {
      case TYPE_NONE:
        stack.Push(*ret);
        break;
      case TYPE_NUMERIC:
        stack.Push(*static_cast<NumericValue*>(ret));
        break;
      case TYPE_STRING:
        stack.Push(*static_cast<StringValue*>(ret));
        break;
      case TYPE_BLOCK:
        stack.Push(*static_cast<BlockValue*>(ret));
        break;
      }
      
      delete ret;

      break;
    }
    default:
      break;
    }
  }
  return;
}

void Block::SetVM(VM* vm)
{
  m_vm = vm;
  m_localScope.SetParent(&vm->GetScope());
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

Scope& Block::GetScope()
{
  return m_localScope;
}
