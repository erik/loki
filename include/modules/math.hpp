#ifndef _MATH_H_
#define _MATH_H_

#include "module.hpp"

#include <iostream>

class MathModule : public Module {
public:
  virtual ~MathModule();

  static Module* Instance();
};

namespace Math {
  void add(VM* vm, ValueStack& args);
}

#endif /* _MATH_H_ */
