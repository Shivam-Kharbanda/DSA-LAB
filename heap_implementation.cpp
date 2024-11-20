#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    MaxHeap() {
        heap.push_back(0); // Index 0 is not used
    }

    int parent(int i) {
        return i / 2;
    }

    int leftChild(int i) {
        return 2 * i;
    }

    int rightChild(int i) {
        return 2 * i + 1;
    }

    void heapifyUp(int i) {
        while (i > 1 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left <= heap.size() - 1 && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right <= heap.size() - 1 && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void insert(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.size() == 1) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int max = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(1);

        return max;
    }

    void printHeap() {
        for (int i = 1; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    h.printHeap();

    cout << "Extracted max: " << h.extractMax() << endl;

    h.printHeap();

    return 0;
}