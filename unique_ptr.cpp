#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> fPtr1;
    std::unique_ptr<int> fPtr2(new int(4));
    auto fPtr3 = std::make_unique<int>();
    
    std::cout << "fPtr2 release before:" << fPtr2.get() << std::endl;
    int *pF = fPtr2.release();
    std::cout << "fPtr2 release after:" << fPtr2.get() << " and pF value:" << *pF << std::endl;
    
    std::cout << "move before fPtr1 address:" << fPtr1.get() << " fPtr3 address:" << fPtr3.get() << std::endl;
    fPtr1 = std::move(fPtr3);
    std::cout << "move after  fPtr1 address:" << fPtr1.get() << " fPtr3 address:" << fPtr3.get() << std::endl;

    std::cout << "move before fPtr1 address:" << fPtr1.get() << std::endl;
    fPtr1.reset();
    std::cout << "move after  fPtr1 address:" << fPtr1.get() << std::endl;


    // double* p[4] = new double({1.0, 2.0, 3.0});
    double *p = new double();
    for(int i=1;i<10;i++) {
      *(p+i) = i*0.01;    	
      std::cout << *(p+i) << std::endl;
    }

    p = nullptr;
    std::cout << nullptr << std::endl;
    delete p;
	
    // std::cout << "p: " << *p << std::endl;

    return 0;
}
