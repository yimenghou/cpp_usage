#include <algorithm>
#include <iostream>
using namespace std;

void fun1(int x) 
{
    cout << x << " ";
}

struct Class1 // object type function
{           
    void operator() (int x) 
    {
        cout << x << " ";
    }
} obj1;


int main() 
{
    int arr[] = {11, 21, 4, 13};
    for_each(arr, arr + 4, fun1);
    cout << endl;
  	for_each(arr, arr + 4, obj1);
    return 0;
}
