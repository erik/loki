#ifndef _VALUE_H_
#define _VALUE_H_

#include "block.hpp"

#include <string>
#include <sstream>

enum ValueType {
  TYPE_NONE,
  TYPE_NUMERIC,
  TYPE_STRING,
  TYPE_BLOCK
  //...
};

class Value {
public:
  Value();
  virtual ~Value();

  // returns whether this is an instance of 'type'
  bool CheckType(ValueType type);

  // return the type of the object
  virtual ValueType Type();
 
  // return a string representation of the object
  virtual std::string ToString() const;

  // return a debug representation of object
  virtual std::string Inspect() const;

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
  std::string ToString() const;
  std::string Inspect() const;

  NumericValue operator+(NumericValue& other);
  NumericValue operator-(NumericValue& other);
  NumericValue operator*(NumericValue& other);
  NumericValue operator/(NumericValue& other); 

  double Value();
private:
  double m_value;
};

class StringValue : public Value {
public:
  StringValue();
  StringValue(const std::string& s);
  virtual ~StringValue();

  void Append(StringValue& other);
  void Append(std::string& other);

  StringValue operator+(StringValue& other);
  
  StringValue operator[](unsigned index);

  ValueType Type();
  std::string ToString() const;
  std::string Inspect() const;

private:
  std::string m_string;
};

class BlockValue : public Value {
public:
  BlockValue();
  BlockValue(Block b);
  virtual ~BlockValue();

  Block& GetBlock();

  ValueType Type();
  std::string ToString() const;
  std::string Inspect() const;

private:
  Block m_block;
};

#endif /* _VALUE_H_ */
