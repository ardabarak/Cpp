// Arda Barak
// 300129340
// Exercise 2

#include <iostream>
using namespace std;

template <typename T, int N> //using the given template
class IterativeSquare {
public:
    static T apply(T value) {
        return applyOperation(value);
    }

private:
    static T applyOperation(T value) {
        if constexpr (N > 0) {
            return IterativeSquare<T, N - 1>::apply(value * value);
        } else {
            return value;
        }
    }
};

int main() {
    int result = IterativeSquare<int, 2>::apply(2);                     //computing (((2^2)^2)) from the example
    cout << "Result of computing (((2^2)^2)) is:    " << result << endl;   //output must be 16
    return 0;
}
