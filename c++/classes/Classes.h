/*
 * Classes.h
 * @author Dan Woolsey
 */

#ifndef CLASSES_H
#define CLASSES_H

class NameOfClass
{

private:
  // member variables/private helper functions
  int value;

public:
  // public functions
  NameOfClass();          // default constructor
  NameOfClass(int value); // overloaded constructor
  ~NameOfClass();         // destructor

  // member functions
  void setValue(int value);
  int getValue();
  void doSomething();
};

#endif
