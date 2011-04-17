#include "vm.hpp"
#include "block.hpp"
#include "value.hpp"

#include <iostream>

int main(int argc, char** argv) {
  VM vm;

  ValueStack& stack = vm.GetStack();
  stack.Push(NumericValue(42));
  stack.Push(StringValue("world!"));
  stack.Push(StringValue("hello, "));

  Block block_main("main", &vm);
  block_main.AddInstruction(OP_NOP);
  block_main.AddInstruction(OP_TOSTRING);
  block_main.AddInstruction(OP_POPSTACK);
  block_main.AddInstruction(OP_TOSTRING);

  vm.AddBlock(block_main);

  ValueStack args;

  vm.Call("main", args);

  stack.Clear();

  return 0;
}
