#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

struct node* top = NULL;

void push(int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void peek() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Top element is: " << top->data << endl;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    free(temp);

    cout << "Popped value is: " << poppedValue << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();

    display();

    return 0;
}