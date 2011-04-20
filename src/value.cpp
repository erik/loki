#include "value.hpp"

Value::Value() 
{
}

Value::~Value()
{
}

bool Value::CheckType(ValueType type)
{
  return this->Type() == type;
}

ValueType Value::Type()
{
  return TYPE_NONE;
}

std::string Value::ToString() const
{
  return "(NONE)";
}

std::string Value::Inspect() const
{
  std::ostringstream stream;
  stream << ToString();
  stream << "@";
  stream << (void*)this;
  return stream.str();
}

Value* Value::CloneToPtr()
{
  Value* v = NULL;
  
  switch(this->Type()) {

  case TYPE_NONE:
    v = new Value;
    *v = *this;
    break;

  case TYPE_NUMERIC:
    v = new NumericValue(static_cast<NumericValue*>(this)->Value());
    break;

  case TYPE_STRING: {
    std::string val = static_cast<StringValue*>(this)->ToString();
    v = new StringValue(val);
    break;
  }

  case TYPE_BLOCK: {
    Block& b = static_cast<BlockValue*>(this)->GetBlock();
    v = new BlockValue(b);
  }

  }

  return v;
}
