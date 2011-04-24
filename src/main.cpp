#include "vm.hpp"
#include "block.hpp"
#include "value.hpp"

#include "modules/math.hpp"

#include <iostream>

int main(int argc, char** argv) {
  VM vm;

  StringValue key1("asdfg");
  NumericValue key2(12345);

  NumericValue val(16);
  StringValue  val2("ASDFG");

  ArrayValue arr;
  arr.Set(key1, val);
  arr.Set(key2, val2);

  std::cout << "1 " << arr[key1]->ToString() << std::endl;
  std::cout << "2 " << arr[key2]->ToString() << std::endl;

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

  vm.CloseLibraries();

  stack.Clear();

  return 0;
}
