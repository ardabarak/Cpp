// Arda Barak
// 300129340

#include <iostream>
#include <vector>
using namespace std;

int uniqPathsNumber(int m, int n) { //grid of m*n
    vector<int> vector(n, 1);
    
    for (int i = 1; i < m; i++) { //looping at every m to the right
        for (int ix = 1; ix < n; ix++) {//loop again at n's to down
            vector[ix] = vector[ix] + vector[ix - 1];
        }
    }    
    return vector[n-1];
}

int main() {
    // int m = 3, n = 7; //28
    // int m = 10, n = 10; //48620
    int m = 4, n = 6; //56
    cout << "Unique paths number is:    " << uniqPathsNumber(m, n) << endl;
    return 0;
}