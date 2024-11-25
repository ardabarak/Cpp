// Arda Barak
// 300129340
// Exercise 3

#include <iostream>
#include <vector>
#include <functional>

template <typename T>   //template
class Container {       //class Container
private:
    std::vector<T> elements;

public:
    void add(const T& element) {elements.push_back(element);} //adding elements

    class Iterator {   //iterator class
    private:
        typename std::vector<T>::iterator current;

    public:
        Iterator(typename std::vector<T>::iterator it) : current(it) {} //constructor

        T& operator*() {return *current;} //overload *

        Iterator& operator++() {    //overload ++
            ++current;
            return *this;
        }

        Iterator& operator--() {    //overload --
            --current;
            return *this;
        }

        bool operator!=(const Iterator& other) const {return current != other.current;} //overload !=
    };

    Iterator begin() {return Iterator(elements.begin());} //begin iterator

    Iterator end() {return Iterator(elements.end());} //end iterator

    void forEach(const std::function<void(T&)>& func) { //forEach to apply a function or lambda
        for (T& element : elements) {
            func(element);
        }
    }
};

int main() {
    Container<int> container; //creating a Container
    //adding elements
    container.add(1);
    container.add(2);
    container.add(3);
    container.add(4);
    //displaying with custom iterator
    std::cout << "Elements in container: ";
    for (auto it = container.begin(); it != container.end(); ++it) {std::cout << *it << " ";}
    std::cout << "\n";
    container.forEach([](int& value) { value *= 2; }); //modifying elements with forEach
    std::cout << "Elements after modification: "; //displaying modified elements
    for (auto it = container.begin(); it != container.end(); ++it) {std::cout << *it << " ";}
    std::cout << "\n";
    return 0;
}
