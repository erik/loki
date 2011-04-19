#ifndef _SCOPE_H_
#define _SCOPE_H_

#include <map>
#include <string>

class Value;

class Scope {
public:
  Scope();
  Scope(Scope* parent);
  virtual ~Scope();

  // set key to value
  void Set(std::string key, Value* value);

  // set the parent scope
  void SetParent(Scope* parent);

  // fetch the Value associated with key, or NULL
  // searchParent does just that: if true, searches parent scope for value as well
  Value* Get(std::string key, bool searchParent = true);

  // Same as Get
  Value* operator[](std::string key);

  // return whether or not the scope (or parent) contains the key
  bool HasBinding(std::string, bool searchParent = true);

private:
  Scope* m_parent;
  std::map<std::string, Value*> m_bindings;
};

#endif /* _SCOPE_H_ */
