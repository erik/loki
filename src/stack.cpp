#include "stack.hpp"

ValueStack::ValueStack()
  : m_stack()
{
}

ValueStack::~ValueStack()
{
}

bool ValueStack::CheckStack(unsigned int size)
{
  return this->Size() >= size;
}

void ValueStack::Clear()
{
  while(!m_stack.empty()) {
    delete m_stack.top();
    m_stack.pop();
  }
}

void ValueStack::Push(Value v)
{
  Value* val = v.CloneToPtr();
  m_stack.push(val);
}

void ValueStack::Push(NumericValue v)
{
  Value* val = v.CloneToPtr();
  m_stack.push(val);
}

void ValueStack::Push(StringValue v)
{
  Value* val = v.CloneToPtr();
  m_stack.push(val);
}

Value* ValueStack::Pop()
{
  Value *v = m_stack.top();
  m_stack.pop();
  return v;
}

Value* ValueStack::Peek()
{
  return m_stack.top();
}

unsigned int ValueStack::Size()
{
  return m_stack.size();
}
