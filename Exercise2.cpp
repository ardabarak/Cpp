// Arda Barak
// 300129340

#include <iostream>
using namespace std;

struct Node {
    int place;
    Node* sonraki;
};

Node* yeniCircle(int N) { //circular linked list
    Node* head = new Node;
    head->place = 1;
    Node* prev = head;

    for (int i = 2; i <= N; i++) {  //rest of the nodes
        Node* yeniNode = new Node;
        yeniNode->place = i;
        prev->sonraki = yeniNode;
        prev = yeniNode;
    }
    //linking last nodes end back to the head
    prev->sonraki = head;
    return head;
}

int findLastChild(Node* head, int M) {
    Node* current = head;
    Node* prev = nullptr;

    while (current->sonraki != current) {
        for (int count = 1; count < M; count++) {
            prev = current;
            current = current->sonraki;
        }
        cout << "Removing kid number:   " << current->place << endl;
        prev->sonraki = current->sonraki; //update prev nodes next pointer
        delete current;         //delete the current node
        current = prev->sonraki;//goto next child
    }
    return current->place;//last one returned
}

int main() {
    int N, M;
    cout << "input the total number of children:    ";
    cin >> N;
    cout << "input the number for M:                ";
    cin >> M;
    Node* head = yeniCircle(N);
    int lastChild = findLastChild(head, M);
    cout << "The last remaining child is at place: " << lastChild << endl;
    delete head;
    return 0;
}