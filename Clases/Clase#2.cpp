    #include <iostream>

    using namespace std;


    void swap(int* x, int* y)
        {
            int temp = *x;
            *x = *y;
            *y = temp;
        }


    int main ()
    {

        int numeros [5] = {10 ,20 ,30 ,40 ,50};
        int* p = numeros;

        // p + 0 apunta al primer elemento del array
        // p + 1 apunta al segundo elemento del array
        // p + 2 apunta al tercer elemento del array
        // p + 3 apunta al cuarto elemento del array
        // p + 4 apunta al quinto elemento del array

    
        for(int i = 0; i < 5; i++)
        {
            cout << "Elemento # " << i << " : " << endl;
            cout <<  *(p + i) << endl;
        }


        cout << numeros[4] << endl;
        cout << *(p + 4) << endl;   


    
        int x = 5;
        int y = 10;

        cout << "Antes del swap: " << endl;
        cout << "a: " << x << endl;
        cout << "b: " << y << endl;

        swap(&x, &y);

        cout << "Despues del swap: " << endl;
        cout << "a: " << x << endl;
        cout << "b: " << y << endl;


    return 0;

    }