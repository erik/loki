#include "scope.hpp"
#include "value.hpp"

Scope::Scope()
  : m_parent(NULL)
{
}

Scope::Scope(Scope* parent)
  : m_parent(parent)
{
}

Scope::~Scope()
{
}

void Scope::Set(std::string key, Value* v)
{
  m_bindings[key] = v;
}

void Scope::SetParent(Scope* parent)
{
  m_parent = parent;
}

Value* Scope::Get(std::string key, bool searchParent)
{
  std::map<std::string, Value*>::iterator it = m_bindings.find(key);

  if(it == m_bindings.end()) {
    if(searchParent == true && m_parent != NULL) {
      return m_parent->Get(key);
    }
    return NULL;
  }

  return it->second;
}

Value* Scope::operator[](std::string key)
{
  return this->Get(key);
}

bool Scope::HasBinding(std::string key, bool searchParent)
{
  return this->Get(key, searchParent) != NULL;
}
