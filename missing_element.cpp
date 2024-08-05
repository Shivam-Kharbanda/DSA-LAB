#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> elements(n);
    cout << "Input the consecutive elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    int first_element = elements[0];
    int last_element = first_element + n;
    
    int xor_all_elements = 0;
    int xor_input_elements = 0;
    
    
    for (int i = first_element; i <= last_element; ++i) {
        xor_all_elements ^= i;
    }
    
    for (int i = 0; i < n; ++i) {
        xor_input_elements ^= elements[i];
    }
    
   
    int missing_number = xor_all_elements ^ xor_input_elements;
    cout << "The missing number is: " << missing_number << endl;

    return 0;
}
