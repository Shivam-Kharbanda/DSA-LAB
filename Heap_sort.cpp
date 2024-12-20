#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int left=(2*i) +1;
    int right=(2*i) +2;
    int large=i;
    if (left<n && arr[left]>arr[large])
    {
        large=left;
    }
    if (right<n && arr[right]>arr[large])
    {
        large=right;
    }
    if (large!=i)
    {
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void buildheap(int arr[], int n)
{
    for (int i=(n/2)-1;i>=0;i--)
    {
        heapify(arr, n, i);
    }
}

void heapsort(int arr[], int n)
{
    buildheap(arr, n);
    for (int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapsort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}