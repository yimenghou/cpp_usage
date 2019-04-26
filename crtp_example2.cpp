
#include <iostream>
#include <vector>

struct Data1{
  bool flag;
  double output;
  int index;
};
struct Data2{
  float output;
  uint16_t index;  
};

template<typename D>
class SomeClassBase
{
public:
  //common methods go here
  template<typename T>
  void doSomething(T t)
  {
    std::cout << "base class" << std::endl;
    // static_cast<T*>(this)->doSomething(t);
  }
};

class SomeClass : public SomeClassBase< SomeClass >
{
public:
  template<typename T>
  void doSomething(T t) {
    std::cout << "some class" << std::endl;
  }
};

class SomeOtherClass : public SomeClassBase< SomeOtherClass >
{
public:
  template<typename T>
  void doSomething(T t) {
    std::cout << "some other class" << std::endl;
  }
};


int main(int argc, char const *argv[])
{
  SomeClass work0;
  SomeOtherClass work1;

  Data1 data1;
  Data2 data2;

  work0.doSomething<Data1>(std::move(data1));
  work1.doSomething<Data2>(std::move(data2));
  return 0;
}