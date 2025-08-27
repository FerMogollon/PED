#include <iostream>

using namespace std;

int main () 
{
    char actions[256];

    for (int i = 0; i < 256; i++)
    {
        actions[i] = 'P';
    };

    actions['W'] = 'U'; // Up
    actions['A'] = 'L'; // Left
    actions['S'] = 'D'; // Down
    actions['D'] = 'R'; // Right

    char Key;
    cout << "Press a key (W, A, S, D) to move:";
    cout << endl;
    cin >> Key;
    cout << "You pressed: " << actions[Key] << endl;
}