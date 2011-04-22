#include "value.hpp"

StringValue::StringValue()
  : m_string("")
{
}

StringValue::StringValue(const std::string s)
  : m_string(s)
{
}

StringValue::~StringValue()
{
}

void StringValue::Append(StringValue& other)
{
  m_string.append(other.m_string);
}

void StringValue::Append(std::string& other)
{
  m_string.append(other);
}

StringValue StringValue::operator+(StringValue& other)
{
  return StringValue(m_string + other.m_string);
}

StringValue StringValue::operator[](unsigned index)
{
  if(index > m_string.size()) {
    return StringValue("");
  }

  return StringValue("" + m_string[index]);
  }

ValueType StringValue::Type()
{
  return TYPE_STRING;
}

std::string StringValue::ToString() const
{
  return m_string;
}

std::string StringValue::Inspect() const
{
  return "(StringValue)\"" + m_string + "\"";
}
