#include "vm.hpp"
#include "block.hpp"
#include "value.hpp"

#include "modules/math.hpp"

#include <iostream>

int main(int argc, char** argv) {
  VM vm;
  
  vm.OpenLibraries();

  ValueStack& stack = vm.GetStack();

  // main
  Block block_main("main", &vm);

  stack.Push(NumericValue(0));
  stack.Push(StringValue("add"));
  
  block_main.AddInstruction(OP_LOADBLOCK);
  block_main.AddInstruction(OP_CALL);

  vm.AddBlock(block_main);

  ValueStack args;

  vm.Call("main", args);

  stack.Clear();

  return 0;
}
