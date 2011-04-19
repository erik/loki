#ifndef _STACK_H_
#define _STACK_H_

#include "value.hpp"

#include <stack>

// basically a wrapper around std::stack
class ValueStack {
public:
  ValueStack();
  virtual ~ValueStack();

  // returns true if the stack has at least 'size' elements false otherwise
  bool CheckStack(unsigned int size);

  // clear the stack completely
  void Clear();

  // push a value onto the stack
  void Push(Value v);
  void Push(NumericValue v);
  void Push(StringValue v);
  void Push(BlockValue v);

  // pop the top value off the stack, returning it
  Value* Pop();

  // return the top value on the stack without popping it off
  Value* Peek();

  // return the size of the stack
  unsigned int Size();

private:
  std::stack<Value*> m_stack;
};

#endif /* _STACK_H_ */
