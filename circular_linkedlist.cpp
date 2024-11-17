#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool detectCircular(Node* head) {
    unordered_set<Node*> visited;
    while (head) {
        if (visited.find(head) != visited.end()) return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;  // Making it circular

    if (detectCircular(head))
        cout << "It's a circular linked list." << endl;
    else
        cout << "It's not a circular linked list." << endl;

    return 0;
}
