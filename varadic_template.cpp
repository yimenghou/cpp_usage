#include <iostream>
#include <string>

void show() {}

template<typename T, typename ...Args>
void show(T val, Args... args) {
	std::cout << val << ",";
	show(args...);
}

int main() {
	int n = 12;
	double x = 3.14;
	std::string a = "yimeng";
	show(n,x);
	std::cout << std::endl;
	show(n,x,a);
	std::cout << std::endl;
	return 0;
}