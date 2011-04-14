#include "stack.hpp"

ValueStack::ValueStack()
  : m_stack()
{
}

ValueStack::~ValueStack()
{
}

void ValueStack::Push(Value &v)
{
  m_stack.push(v);
}

Value& ValueStack::Pop()
{
  Value& v = m_stack.top();
  m_stack.pop();
  return v;
}

Value& ValueStack::Peek()
{
  return m_stack.top();
}

unsigned int ValueStack::Size()
{
  return m_stack.size();
}
