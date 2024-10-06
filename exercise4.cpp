//Arda Barak 300129340
//Exercise 4
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int		intput;
	float	floput;

	cout << "enter an float:		";
	cin >> floput;
	cout << "enter an integer:	";
	cin >> intput;
	
	//Calculate and print the square root of the number<float?> and also raise the number to the power of the integer input.
	float output;
	output = sqrt(floput); //square root of the input float
	cout << "square root of the input float:	" << output << "\n";
	output = pow(output, intput);
	cout << "power to the int input:	" <<  output << "\n"; //power to the int input

	return 0;
}
