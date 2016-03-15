#include <iostream>

using namespace std;
int main(void) {
    const int n = 10;
    int T1[n], T2[n], T3[2*n];
    cout << "Enter vector 1: " << endl;
    for (int i = 0; i < n; ++i) cin >> T1[i];

    cout << "Enter vector 2: " << endl;
    for (int i = 0; i < n; ++i) cin >> T2[i];

    for (int i = 0; i < n; ++i) {
        T3[i] = T1[i];
        T3[i+n] = T2[i];
    }

    cout << "Result: " << endl;
    for (int i = 0; i < 2*n; ++i) cout << T3[i] << " ";
    cout << endl;
    return 0;
}
