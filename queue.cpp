#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
public:
    Node *front, *rear;
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void push(int x) {
        Node *temp = new Node(x);
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if (!isEmpty()) {
            return front->data;
        } else {
            cout << "Queue is empty!" << endl;
            return -1; // Indicating empty queue
        }
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;

    q.pop();
    cout << "Front element after pop: " << q.peek() << endl;

    q.pop();
    q.pop();

    q.pop(); // Trying to pop from an empty queue

    return 0;
}
