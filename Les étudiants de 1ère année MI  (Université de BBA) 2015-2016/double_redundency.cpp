#include <iostream>
using namespace std;

int main(void) {
    const int n = 5;
    int arr1[n], arr2[n], arr[n*2];

    cout << "Enter vector 1: ";
    for (int i = 0; i < n; ++i) cin >> arr1[i];
    cout << "Enter vector 2: ";
    for (int i = 0; i < n; ++i) cin >> arr2[i];

    int size = 0;
    bool t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr1[i] == arr2[j]) {
                if (size == 0) {
                    arr[0] = arr1[i];
                    ++size;
                }
                else {
                    t = false;
                    for (int k = 0; k < size; ++k) {
                        if (arr1[i] == arr[k]) {
                            t = true;
                            break;
                        }
                    }
                    if (t == false) {
                        arr[size] = arr1[i];
                        ++size;
                    }
                }
            }
        }
    }

    cout << "Result: ";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
