#include "value.hpp"

#include <sstream>
#include <iostream>
/* NumericValue */
NumericValue::NumericValue()
  : m_value(0)
{
}

NumericValue::NumericValue(double d)
  : m_value(d)
{
}

NumericValue::~NumericValue()
{
}

ValueType NumericValue::Type()
{
  return TYPE_NUMERIC;
}

std::string NumericValue::ToString() const
{
  std::ostringstream oss;
  oss << m_value;
  return oss.str();
}

std::string NumericValue::Inspect() const
{
  std::ostringstream oss;
  oss << "(NumericValue)";
  oss << m_value;
  return oss.str();
}

NumericValue NumericValue::operator+(NumericValue& other)
{
  return NumericValue(other.m_value + m_value);
}

NumericValue NumericValue::operator-(NumericValue& other)
{
  return NumericValue(other.m_value - m_value);
}

NumericValue NumericValue::operator*(NumericValue& other)
{
  return NumericValue(other.m_value * m_value);
}

NumericValue NumericValue::operator/(NumericValue& other)
{
  return NumericValue(other.m_value / m_value);
}

double NumericValue::Value()
{
  return m_value;
}
