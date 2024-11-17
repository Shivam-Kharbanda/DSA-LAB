#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkList {
public:
    Node* head = nullptr;

    void push_at_start(int x) { head = new Node(x); }

    void push_at_head(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    void push_at_end(int x) {
        Node* temp = new Node(x);
        if (!head) {
            head = temp;
            return;
        }
        Node* tail = head;
        while (tail->next) tail = tail->next;
        tail->next = temp;
    }

    void push_at_index(int x, int ind) {
        if (ind == 0) {
            push_at_head(x);
            return;
        }
        Node* root = head;
        while (--ind && root->next) root = root->next;
        Node* temp = new Node(x);
        temp->next = root->next;
        root->next = temp;
    }

    void delete_at_start() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_at_end() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* prev = nullptr;
        Node* temp = head;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
    }

    void delete_at_index(int ind) {
        if (ind == 0) {
            delete_at_start();
            return;
        }
        Node* prev = nullptr;
        Node* temp = head;
        while (--ind && temp->next) {
            prev = temp;
            temp = temp->next;
        }
        if (temp && temp->next) {
            prev->next = temp->next;
            delete temp;
        }
    }

    void print() {
        Node* root = head;
        while (root) {
            cout << root->data << " ";
            root = root->next;
        }
        cout << endl;
    }
};

int main() {
    LinkList l;
    l.push_at_start(5);
    l.push_at_head(12);
    l.push_at_end(15);
    l.push_at_index(10, 2);
    l.print();
    l.delete_at_start();
    l.print();
    l.delete_at_end();
    l.print();
    return 0;
}
