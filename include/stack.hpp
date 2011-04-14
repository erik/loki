#ifndef _STACK_H_
#define _STACK_H_

#include "value.hpp"

#include <stack>

// basically a wrapper around std::stack
class ValueStack {
public:
  ValueStack();
  virtual ~ValueStack();

  void Push(Value& v);

  Value& Pop();
  Value& Peek();

  unsigned int Size();

private:
  std::stack<Value> m_stack;
};

#endif /* _STACK_H_ */
