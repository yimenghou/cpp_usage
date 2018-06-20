#include <bitset>
#include <iostream>
#include <string>

std::string byte_to_binary(const uint8_t value) {
  return std::bitset<8 * sizeof(uint8_t)>(value).to_string();
}

int main()
{
uint8_t a = 12;
std::string b = byte_to_binary(a);
std::cout << "b: " << b << std::endl;
return 0;
}
