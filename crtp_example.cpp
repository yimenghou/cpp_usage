
#include <iostream>

void expandFunc() {}

template<typename HEAD, typename... Args>
void expandFunc(HEAD head, Args... args) {
  std::cout << "head: " << head << std::endl;
  expandFunc(args...);
}

struct Data1{};
struct Data2{};

template< class T >
class SomeClassBase
{
public:
  //common methods go here
  template<typename... Args>
  void doSomething(Args && ... args)
  {
    static_cast<T*>(this)->doSomething(std::forward<Args>(args)...);
  }
};

class SomeClass : public SomeClassBase< SomeClass >
{
public:
  template<typename... Args>
  void doSomething(Args && ... args) {
    std::cout << "some class" << std::endl;
  }
};

class SomeOtherClass : public SomeClassBase< SomeOtherClass >
{
public:
  template<typename... Args>
  void doSomething(Args && ... args) {
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
  expandFunc(1,2,3,4);
  return 0;
}