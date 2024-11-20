#include <iostream>
#include <math.h>

using namespace std;

void solve(int *arr, int x, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i] * pow(x, i);
    }

    cout << "Sum of polynomial is: " << sum << endl;
}

int main() {
    int arr[] = {11, 13, 20, 25, 38};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x;
    cout << "Enter the value of x: ";
    cin >> x;

    solve(arr, x, n);

    return 0;
}