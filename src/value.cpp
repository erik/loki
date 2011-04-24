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

std::string Value::ToString()
{
  return "(NONE)";
}

std::string Value::Inspect()
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
  
  switch(Type()) {

  case TYPE_NONE:
    v = new Value;
    *v = *this;
    break;

  case TYPE_NUMERIC:
    v = new NumericValue(static_cast<NumericValue*>(this)->Value());
    break;

  case TYPE_STRING: {
    v = new StringValue(this->ToString());
    break;
  }

  case TYPE_BLOCK: {
    Block& b = static_cast<BlockValue*>(this)->GetBlock();
    v = new BlockValue(b);
    break;
  }

  case TYPE_ARRAY: {
    ArrayValue* a = static_cast<ArrayValue*>(this);
    v = new ArrayValue(*a);
    break;
  }
  }

  return v;
}
