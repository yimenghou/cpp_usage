#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) 
{
int a = 12;
const int& ref = a;
const int* ap = &a;
int* tmp = const_cast<int*>(ap);
*tmp = 11;
cout<<&a<<endl;
cout<<ap<<endl;
cout<<tmp<<endl;
cout<<ref<<endl;

}
