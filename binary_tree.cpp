#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

Node* AlmostInsertionBinaryTree(Node* root, int val) {
    Node* newNode = new Node(val);
    if (root == nullptr) {
        return newNode;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == nullptr) {
            temp->left = newNode;
            return root;
        } else {
            q.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = newNode;
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

void printLevelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = nullptr;
    root = AlmostInsertionBinaryTree(root, 3);
    root = AlmostInsertionBinaryTree(root, 9);
    root = AlmostInsertionBinaryTree(root, 4);
    root = AlmostInsertionBinaryTree(root, 7);
    root = AlmostInsertionBinaryTree(root, 6);

    cout << "Level Order Traversal of Binary Tree:" << endl;
    printLevelOrder(root);
    return 0;
}
