#include "value.hpp"

ArrayValue::ArrayValue()
{
}

ArrayValue::~ArrayValue()
{
  std::map<std::string, std::pair<Value*, Value*> >::iterator it;

  for(it = m_map.begin(); it != m_map.end(); it++) {
    delete it->second.first;
    delete it->second.second;
  }
}

Value* ArrayValue::Get(Value& key)
{
  std::string k = key.Inspect();

  std::map<std::string, std::pair<Value*, Value*> >::iterator it =
    m_map.find(k);

  if(it == m_map.end()) {
    return NULL;
  }

  Value* val = it->second.second;

  return val;
}

Value* ArrayValue::operator[](Value& key)
{
  return this->Get(key);
}


void ArrayValue::Set(Value& key, Value& val) { 
  this->Set(&key, &val); 
}

void ArrayValue::Set(Value* key, Value* val)
{
  std::string sk = key->Inspect();

  std::map<std::string, std::pair<Value*, Value*> >::iterator it =
    m_map.find(sk);

  if(it != m_map.end()) {
    delete it->second.first;
    delete it->second.second;
    m_map.erase(it);
  }

  std::pair <Value*, Value*> pair (key->CloneToPtr(), val->CloneToPtr());  

  m_map[sk] = pair;
}

std::string ArrayValue::ToString()
{
  return "TODO, array.ToString()";
}

std::string ArrayValue::Inspect()
{
  return "TODO, array.Inspect";
}

ValueType ArrayValue::Type()
{
  return TYPE_ARRAY;
}
