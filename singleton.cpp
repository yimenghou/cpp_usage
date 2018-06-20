#include <iostream>
#include <iomanip>
#include <iostream>

#define DISALLOW_COPY_AND_ASSIGN(classname) \
 private:                                   \
  classname(const classname &);             \
  classname &operator=(const classname &);

#define DISALLOW_IMPLICIT_CONSTRUCTORS(classname) \
 private:                                         \
  classname();                                    \
  DISALLOW_COPY_AND_ASSIGN(classname);

#define DECLARE_SINGLETON(classname)        \
 public:                                    \
  static classname *instance() {            \
    static classname instance;              \
    return &instance;                       \
  }                                         \
  DISALLOW_IMPLICIT_CONSTRUCTORS(classname) \
 private:


class Dog {
public:
	~Dog() = default;
	void getIncrement() const;
	void increment();

private:
	int life = 0;
	DECLARE_SINGLETON(Dog);
};


void Dog::getIncrement() const {
	std::cout << "life: " << life << std::endl; 
}

void Dog::increment() {
	life++;
}

Dog::Dog() {}

int main() {
	Dog::instance()->increment();
	Dog::instance()->getIncrement();
	Dog::instance()->increment();
	Dog::instance()->getIncrement();
	Dog::instance()->increment();
	Dog::instance()->getIncrement();
	return 0;
}