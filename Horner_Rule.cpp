#include <iostream>
#include <math.h>

using namespace std;

int solve(int *arr, int n, int m, int x) {
   
    if (m > n) {
        return 0;
    }

    
    int current_term = arr[n - m] * pow(x, n - m);

    
    return current_term + solve(arr, n, m + 1, x);
}

int main() {
    int arr[5] = {11, 13, 20, 25, 38};
    int x;

    cout << "Enter value of x: ";
    cin >> x;

    int res = solve(arr, 5, 1, x);
    cout << "Result is: " << res << endl;

    return 0;
}
