#include "module.hpp"

#include "vm.hpp"

Module* Module::m_instance = NULL;

Module::~Module()
{
}

Module::Module()
{
}

Module::Module(const Module&)
{
}

void Module::Install(VM* vm)
{
  for(unsigned i = 0; i < m_blocks.size(); ++i) {
    vm->AddBlock(m_blocks[i]);
  }
}

void Module::Uninstall(VM* vm)
{
}

void Module::AddBlock(Block b)
{
  m_instance->m_blocks.push_back(b);
}
