#include "value.hpp"

BlockValue::BlockValue()
{
}

BlockValue::BlockValue(Block b)
  : m_block(b)
{
}

BlockValue::~BlockValue()
{
}

Block& BlockValue::GetBlock()
{
  return m_block;
}

ValueType BlockValue::Type()
{
  return TYPE_BLOCK;
}

std::string BlockValue::ToString() const
{
  // TODO: implement this
  return "A block!";
}
