#include <iostream>
using namespace std;

int main(void) {
    const int n = 10; int arr[n];
    int x;
    // getting vector values
    cout << "Enter vector values [" << n << "]" << endl;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // printing vector content
    cout << "Vector: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;

    // removing duplicates
    int k = 0;
    bool t;
    for (int i = 0; i < n; ++i) {
        t = false;
        for (int j = 0; j < k; ++j) {
            if (arr[i] == arr[j]) {
                t = true;
                break;
            }
        }
        if (t == false) {
            arr[k] = arr[i];
            ++k;
        }
    }

    cout << "Result: ";
    for (int i = 0; i < k; ++i) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
