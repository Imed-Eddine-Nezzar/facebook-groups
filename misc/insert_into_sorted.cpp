#include <iostream>
#include <random>
#include <vector>

using namespace std;
// helper function to print the vector content
void printv(const vector<int> &v);

// insertion function
void insert(const int &n, vector<int> &v){
    /*
    Insert value n into sorted vector v.
    */
    for(int i = 0; i < v.size(); ++i) {
        if (n < v[i]) { // find the correct place
            // make a space for the new number
            v.resize(v.size() + 1);
            // shift the reset of the numbers to the right
            for (int j = v.size() + 1; j >= i; --j) { 
                v[j] = v[j - 1];
            }
            // insert the new value
            v[i] = n;
            return;
        } 
    }
    // if it's greater than all other numbers
    // insert it at the end
    v.push_back(n);
}

int main(void) {
    random_device rand; int rand_num; // random number
    // creating and populating the vector
    vector<int> v;
    for (int i = 1; i < 10; ++i) v.push_back(i);
    // inserting random values to test the function
    cout << "Original vector: " << endl;
    printv(v);
    for (int i = 0; i < 10; ++i) {
        rand_num = (rand() % 20) - 10;
        cout << "\nInsert a random number: " << rand_num << endl;
        insert(rand_num, v);
        printv(v);
    }
    return 0;
}

void printv(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}
