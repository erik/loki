#ifndef _MODULE_H_
#define _MODULE_H_

#include "block.hpp"
#include "value.hpp"

#include <map>
#include <vector>

class VM;

class Module {
protected:
  Module();
  Module(const Module&);

public:  
  virtual ~Module();
  static Module* Instance();

  void Install(VM* vm);
  void Uninstall(VM* vm);

protected:
  static void AddBlock(Block b);

  static Module* m_instance;
  std::vector<Block> m_blocks;
};

#endif /* _MODULE_H_ */
