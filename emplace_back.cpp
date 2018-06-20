#include <iostream>
#include <list>

int main()
{
  std::list<double> d;
  d.emplace_back();
  std::cout << d.back() << std::endl;
  return 0;
}
