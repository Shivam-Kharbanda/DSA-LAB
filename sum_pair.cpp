
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements in array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int answer[100][3]; 
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (arr[k] == arr[i] + arr[j]) {
                    bool found = false;
                    for (int l = 0; l < count; l++) {
                        if (answer[l][0] == arr[i] && answer[l][1] == arr[j] && answer[l][2] == arr[k]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        answer[count][0] = arr[i];
                        answer[count][1] = arr[j];
                        answer[count][2] = arr[k];
                        count++;
                    }
                }
            }
        }
    }

    cout << "Triplets are: " << endl;
    for (int i = 0; i < count; i++) {
        cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << endl;
    }

    return 0;
}
