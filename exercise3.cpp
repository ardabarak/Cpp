//Arda Barak 300129340
//Exercise 3
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
    //for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++)
    //{
    //    cout << i+1 << ". number is: " << numbers[i] << "\n";
    //}

    //int elevator;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < size -1 ; i++)
    {
        for (int ix = 0; ix < size - i -1; ix++)
        {
            if (numbers[ix] > numbers[ix+1])
            {
                swap(numbers[ix], numbers[ix+1]);
                //elevator = numbers[i];//numbers[i] = numbers[i+ 1];//numbers[i+1] = elevator;//i--;
            }
        }
    }
    //to test if the numbers are calculated correct
    //for (int i = 0; i < size; i++) {cout << numbers[i] << "\n";}

    cout << "Maximum number is:     " << numbers[4] << "\nMinimum number is:     " << numbers[0];

    return 0;
}