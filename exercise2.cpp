//Arda Barak 300129340
//Exercise 2
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string strinput;
	cout << "enter a word:	";
	cin >> strinput;
	string revword;
	revword = strinput;
	reverse(revword.begin(), revword.end());

	if (strinput == revword)
	{
		cout << "The word is palindrome";
	}
	else
	{
		cout << "The word is not palindrome\n";
		cout << "The inputted word is: " << strinput << "\n";
		cout << "The reversed word is: " << revword << "\n";
	}
	return 0;
}
