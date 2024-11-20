#include <iostream>

using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

int kthSmallest(int arr[], int start, int end, int k) {
    int p = partition(arr, start, end);

    if (k - 1 == p) {
        return arr[p];
    } else if (k - 1 < p) {
        return kthSmallest(arr, start, p - 1, k);
    } else {
        return kthSmallest(arr, p + 1, end, k);
    }

    return -1;
}

int main() {
    int arr[] = {11, 12, 13, 14, 15, 16, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int ans = kthSmallest(arr, 0, n - 1, k);

    if (ans != -1) {
        cout << "The " << k << " smallest element is: " << ans << endl;
    } else {
        cout << "Invalid k value." << endl;
    }

    return 0;
}