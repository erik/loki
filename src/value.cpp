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
