#include "value.hpp"

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
  // TODO: write this
  return "42";
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
