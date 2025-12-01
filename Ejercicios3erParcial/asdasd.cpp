#include <iostream>

using namespace std;
int main ()
    {
        int n = 5;
        int &p = n;
        int *ptr = &n;
        cout << &n << " - " << p << " - " << *ptr << " - " << ptr;

        return 0;
    }
