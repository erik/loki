#include "value.hpp"

Value::Value() 
{
}

Value::~Value()
{
}

ValueType Value::Type()
{
  return TYPE_NONE;
}

std::string Value::ToString()
{
  return "(NONE)";
}

Value* Value::CloneToPtr()
{
  Value* v = NULL;
  
  switch(Type()){
  case TYPE_NONE:
    v = new Value;
    break;
  case TYPE_NUMERIC:
    v = new NumericValue;
    break;
  }

  *v = *this;

  return v;
}
