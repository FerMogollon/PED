#include <iostream>

using namespace std;

int main ()
{
    int x = 10;
    int *p = &x;
    int **pp = &p;
   // int ***pp = &p;
    //int ****pp = &p;

    cout << "x = " << x << endl;
    cout << "*p = " << p << endl;
    cout << "**pp = " << pp << endl;
    //cout << "**pp = " << **pp << endl;
    //cout << "***ppp = " << ***pp << endl;
    //cout << "****pppp = " << ****pp << endl;
}