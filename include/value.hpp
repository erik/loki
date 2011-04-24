#ifndef _VALUE_H_
#define _VALUE_H_

#include "block.hpp"

#include <string>
#include <sstream>
#include <iostream>
enum ValueType {
  TYPE_NONE,
  TYPE_NUMERIC,
  TYPE_STRING,
  TYPE_BLOCK,
  TYPE_ARRAY
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
  virtual std::string ToString();

  // return a debug representation of object
  virtual std::string Inspect();

  // return a pointer to the right type for value v
  // doinitwrong
  virtual Value* CloneToPtr();
};

class NumericValue : public Value {
public:
  NumericValue();
  NumericValue(double);
  virtual ~NumericValue();

  virtual ValueType Type();
  std::string ToString();
  std::string Inspect();

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
  StringValue(const std::string s);
  virtual ~StringValue();

  void Append(StringValue& other);
  void Append(std::string& other);

  StringValue operator+(StringValue& other);
  
  StringValue operator[](unsigned index);

  ValueType Type();
  std::string ToString();
  std::string Inspect();

private:
  std::string m_string;
};

class BlockValue : public Value {
public:
  BlockValue();
  BlockValue(Block& b);
  virtual ~BlockValue();

  Block& GetBlock();

  ValueType Type();
  std::string ToString();
  std::string Inspect();

private:
  Block* m_block;
};

class ArrayValue : public Value {
public:
  ArrayValue();
  virtual ~ArrayValue();

  // get a value specified by key, or NULL
  virtual Value* Get(Value& key);

  // ditto
  virtual Value* operator[](Value& key);

  // set key to value
  void Set(Value& key, Value& val);
  virtual void Set(Value* key, Value* val);

  ValueType Type();
  std::string ToString();
  std::string Inspect();

private:
  std::map<std::string, std::pair<Value*, Value*> > m_map;
};

#endif /* _VALUE_H_ */
