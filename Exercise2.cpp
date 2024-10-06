// Arda Barak
// 300129340

#include <iostream>
using namespace std;

class SetInt {
private:
    int* elem;// dynamic array's pointer
    int size; // # of elems
    bool containsAux(int n, int &poz) { //helper
        for (int i = 0; i < size; i++) {
            if (elem[i] == n) {
                poz = i;
                return true;
            }
        }
        return false;
    }

public:

    SetInt() : elem(nullptr), size(0) {}//default constr, empty set

    SetInt(int array[], int arraySize) {//constr array &arraysize
        size = arraySize;
        elem = new int[size];
        for (int i = 0; i < size; i++) {
            elem[i] = array[i];
        }
    }

    ~SetInt() {delete[] elem;} //destrucor

    SetInt(const SetInt &other) { //copy constr
        size = other.size;
        elem = new int[size];
        for (int i = 0; i < size; i++) {
            elem[i] = other.elem[i];
        }
    }

    void add(int n) { //adding an int
        int poz;
        if (!containsAux(n, poz)) { //check if int is already existent
            int* newElem = new int[size + 1];
            for (int i = 0; i < size; i++) {
                newElem[i] = elem[i];
            }
            newElem[size] = n;  //add elem
            delete[] elem;      //delete old array
            elem = newElem;     //update pointer
            size++;
        }
    }

    void remove(int n) { //remove int
        int poz;
        if (containsAux(n, poz)) {
            int* newElem = new int[size - 1];
            for (int i = 0, j = 0; i < size; i++) {
                if (i != poz) {
                    newElem[j++] = elem[i];//copy everythign to remove(except elem)
                }
            }
            delete[] elem;
            elem = newElem;
            size--;
        }
    }

    bool contains(int n) { //check if a int is in the set
        int poz;
        return containsAux(n, poz);
    }

    int nbElem() {return size;} //return number of elems

    int* tabElem() { //return a dynamic array of elems
        if (size == 0) {
            return nullptr;
        }
        int* array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = elem[i];
        }
        return array;
    }
};

int main() {
    int array[] = {1, 2, 3, 4, 5};
    SetInt set1(array, 5);
    set1.add(6);//add elems
    set1.add(2);//duplicate 2 testing
    set1.remove(2);//remove 2
    cout << "# of elems:    " << set1.nbElem() << endl;
    int* elements = set1.tabElem();
    if (elements) {
        cout << "Elems list:    ";
        for (int i = 0; i < set1.nbElem(); i++) {
            cout << elements[i] << ", ";
        }
        delete[] elements;
    }
    return 0;
}