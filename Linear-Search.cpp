#include <iostream>

using namespace std;

bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (key == arr[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr[5] = {23, 5, 69, 40, 84};

    int ans = linearSearch(arr, 5, 23);

    if (ans) {
        cout << "Element is present" << endl;
    } else {
        cout << "Element is not present" << endl;
    }

    return 0;
}