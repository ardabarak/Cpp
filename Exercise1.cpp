// Arda Barak
// 300129340

#include <iostream>
using namespace std;

const char* checkStr(const char* s1, const char* s2) {
    while (*s1 && *s2) // seeing both strings every character
    {    
        if (*s1 < *s2) 
        {
            return s1;
        } else if (*s1 > *s2) {
            return s2;
        }
        s1++;
        s2++;
    }

    //the first one to end is first
    if (*s1 == '\0') {
        return s1;
    } else {
        return s2;
    }
}

int main() {
    char str1[40], str2[40];
    //taking the 2 inputs
    cout << "\ninput your 1st string:     ";
    cin >> str1;
    cout << "\ninput your 2nd string:     ";
    cin >> str2;

    const char* firstWord = checkStr(str1, str2);
    if (firstWord == str1) {
        cout << "1st string is alphabetically first" << endl;
    } else {
        cout << "2nd string is alphabetically first" << endl;
    }
    return 0;
}