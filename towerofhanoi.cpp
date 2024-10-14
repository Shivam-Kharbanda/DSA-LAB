// #include <iostream>
// using namespace std;

// void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
//     if (n == 0) {
//         return;
//     }
    
//     towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
//     cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;

//     towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
// }

// int main() {
//     int n;
//     cin>>n; 
//     towerOfHanoi(n, 'A', 'C', 'B');  
//     return 0;
// }

// #include <iostream>
// #include <cmath>  
// using namespace std;

// int main() {
//     int n;
    
   
//     cout << "Enter the number of discs: ";
//     cin >> n;
    
    
//     int moves = pow(2, n) - 1;
    
    
//     cout << "Number of moves required for " << n << " discs: " << moves << endl;

//     return 0;
// }

// -----> Queue <------

#include <iostream>
using namespace std;
class Queue {
private:
    int front, rear, capacity;
    int* queue;
public:
    Queue(int size)
    {
        front = rear = -1;
        capacity = size;
        queue = new int[capacity]; 
    }
    void enqueue(int value)
    {
        if (rear==(capacity-1)) {
            cout<<"Queue full "<<endl;
            return;
        }
        if (front == -1) front = 0;
        rear++; 
        queue[rear] = value;
        cout<<"Enqueued "<<value<< endl;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout<<"Empty"<<endl;
            return;
        }
        cout<<"Dequeued "<<queue[front]<< endl;
        front++;
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout<<"Empty"<<endl;
            return;
        }
        cout<<"Elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Queue q(5);
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();

    return 0;
}