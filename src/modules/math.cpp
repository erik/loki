#include "modules/math.hpp"

#include "stack.hpp"

Module* MathModule::Instance()
{
  if(m_instance) {
    return m_instance;
  } else {
    m_instance = new MathModule;
    AddBlock(Block("add", Math::add));
  }

  return m_instance;
}

MathModule::~MathModule()
{
  delete m_instance;
}

void Math::add(VM* vm, ValueStack& args)
{
  /*  if(!args.CheckStack(2)) {
    std::cout << "Expected two arguments!" << std::endl;
    }*/

  std::cout << "ohai, modules!" << std::endl;
}
