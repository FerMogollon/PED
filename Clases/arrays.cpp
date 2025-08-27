#include <iostream>

using namespace std;

int main()
{

    // Declare an array of 3 integers

    int arr[3] = {1, 2, 3};

    // print the elemenets of th array

    for (int i = 0; i < 3; i++)
    {
        cout << "Element " << i << ": " << arr[i] << endl;
    }

    int matrix[3][3] =
        {
            {1, 2, 3},
            {1, 2, 3},
            {1, 2, 3}};

    // print the elements of the matrix

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Element [" << i << "][" << j << "]: " << matrix[i][j] << endl;
        }
    }
    return 0;
}