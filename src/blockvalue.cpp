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
  std::ostringstream stream;
  stream << m_block.GetName();
  stream << "@";
  stream << (void*)&m_block;
  return stream.str();
}

std::string BlockValue::Inspect() const
{
  std::ostringstream stream;
  stream << "(BlockValue)";
  stream << ToString();
  return stream.str();
}
