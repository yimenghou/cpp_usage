
#include <iostream>
#include <memory>

class example {
public:
	example() {
		std::cout << "i'm constructed .." << std::endl;
	}
	virtual ~example() = default;
};

static const std::shared_ptr<example>& newExample() {
	static auto instance = std::shared_ptr<example>(new example);
	return instance;
}


int main() {
	// std::cout << testFunc() << " " << testFunc2() << std::endl;
	for(int i=0;i<10;i++) {
		std::cout << "i: " << i << std::endl;
		newExample();
	}
	return 0;
}