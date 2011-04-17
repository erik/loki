#ifndef _VALUE_H_
#define _VALUE_H_

#include <string>

enum ValueType {
  TYPE_NONE,
  TYPE_NUMERIC,
  //...
};

class Value {
public:
  Value();
  virtual ~Value();

  // return the type of the object
  virtual ValueType Type();
  // return a string representation of the object
  virtual std::string ToString();

  // return a pointer to the right type for value v
  // doinitwrong
  virtual Value* CloneToPtr();
};

class NumericValue : public Value {
public:
  NumericValue();
  NumericValue(double);
  virtual ~NumericValue();

  ValueType Type();
  std::string ToString();

  NumericValue operator+(NumericValue& other);
  NumericValue operator-(NumericValue& other);
  NumericValue operator*(NumericValue& other);
  NumericValue operator/(NumericValue& other); 

  double Value();
private:
  double m_value;
};

#endif /* _VALUE_H_ */
