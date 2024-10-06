//Arda Barak 300129340
//Exercise 1

#include <string>
#include <iostream>
using namespace std;

int main()
{
    int numbers[5];
    int inpnum;
    for (int i = 0; i < 5; i++)
    {
        cout << "enter a number: ";
        cin >> inpnum;
        numbers[i] = inpnum;
    }
    for (int i = 4; i >= 0; i--)
    {
        cout << "\nnumber is: " << numbers[i];
    }
    //cout << "Hello World!\n";
    return 0;
}
