#include "vm.hpp"
#include "block.hpp"
#include "value.hpp"

#include <iostream>

int main(int argc, char** argv) {
  VM vm;

  ValueStack& stack = vm.GetStack();

  // other
  stack.Push(StringValue("Hi, i'm some other block!\n"));

  Block block_other("other", &vm);
  block_other.AddInstruction(OP_PRINT);

  // main
  Block block_main("main", &vm);

  stack.Push(NumericValue(0));
  stack.Push(StringValue("other"));

  block_main.AddInstruction(OP_LOADBLOCK);
  block_main.AddInstruction(OP_CALL);


  vm.AddBlock(block_main);
  vm.AddBlock(block_other);

  ValueStack args;

  vm.Call("main", args);

  stack.Clear();

  return 0;
}
