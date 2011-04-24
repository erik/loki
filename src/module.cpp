#include "module.hpp"

#include "vm.hpp"

Module* Module::m_instance = NULL;
std::vector<Block> Module::m_blocks;

Module::~Module()
{
  delete m_instance;
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
  std::map<std::string, Block> map = vm->GetBlocks();

  for(unsigned i = 0; i < m_blocks.size(); ++i) {
    std::map<std::string, Block>::iterator it = map.find(m_blocks[i].GetName());

    if(it != map.end()) {
      map.erase(m_blocks[i].GetName());
    }
  }
}

void Module::AddBlock(Block b)
{
  m_instance->m_blocks.push_back(b);
}
