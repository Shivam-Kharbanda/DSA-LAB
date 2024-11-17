#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

class DLL {
public:
    Node* head = nullptr;

    void push(int x, int i) {
        Node* temp = head, *newNode = new Node(x);
        if (i == 0) { newNode->next = head; if (head) head->prev = newNode; head = newNode; return; }
        while (--i && temp) temp = temp->next;
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode; newNode->prev = temp;
    }

    void pop(int i) {
        Node* temp = head;
        if (i == 0) { head = head->next; if (head) head->prev = nullptr; delete temp; return; }
        while (i-- && temp) temp = temp->next;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void print() { for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " "; cout << endl; }
};

int main() {
    DLL d;
    d.push(3, 0);
    d.push(5, 1);
    d.push(7, 2);
    d.push(1, 1);
    d.print();
    d.pop(1);
    d.print();
    d.pop(0);
    d.print();
    return 0;
}
