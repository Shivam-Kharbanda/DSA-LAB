#include <iostream>
#include <limits.h>

using namespace std;

void solve(int *arr, int n) {
    int maxi = INT_MIN;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int area = ((j - i) * arr[i] + (0.5 * (j - i) * (arr[j] - arr[i])));
            maxi = max(area, maxi);
        }
    }

    cout << "Maximum area is: " << maxi << endl;
}

int main() {
    int arr[] = {1, 2, 4, 9, 10}; // Array must be sorted
    int n = sizeof(arr) / sizeof(arr[0]);

    solve(arr, n);

    return 0;
}