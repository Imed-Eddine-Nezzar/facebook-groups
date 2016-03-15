#include <iostream>
#include <random>
#include <vector>
#include <utility>
using namespace std;

// helper function to print the vector
void print_vector(const vector<int> &v);
// bubble sort
void bubble_sort(vector<int> &v);
// insertion sort
void insertion_sort(vector<int> &v);
// selection sort
void selection_sort(vector<int> &v);
// quick sort
void quick_sort(vector<int> &v, int left, int right);

int main(void) {
    random_device rand;
    vector<int> numbers(20); // create a vector with 20 numbers

    cout << "Bubble Sort" << endl;
    // populate the vector with random numbers
    for (int i = 0; i < numbers.size(); ++i) { numbers[i] = rand() % 100; }
    cout << "Before sorting: " << endl;
    print_vector(numbers); // print the vector
    cout << "After sorting: " << endl;
    bubble_sort(numbers); // sorting the vector
    print_vector(numbers); // print the vector

    cout << "\nInsertion Sort" << endl;
    // populate the vector with random numbers
    for (int i = 0; i < numbers.size(); ++i) { numbers[i] = rand() % 100; }
    cout << "Before sorting: " << endl;
    print_vector(numbers); // print the vector
    cout << "After sorting: " << endl;
    insertion_sort(numbers); // sorting the vector
    print_vector(numbers); // print the vector

    cout << "\nSelection Sort" << endl;
    // populate the vector with random numbers
    for (int i = 0; i < numbers.size(); ++i) { numbers[i] = rand() % 100; }
    cout << "Before sorting: " << endl;
    print_vector(numbers); // print the vector
    cout << "After sorting: " << endl;
    selection_sort(numbers); // sorting the vector
    print_vector(numbers); // print the vector

    cout << "\nQuick Sort" << endl;
    // populate the vector with random numbers
    for (int i = 0; i < numbers.size(); ++i) { numbers[i] = rand() % 100; }
    cout << "Before sorting: " << endl;
    print_vector(numbers); // print the vector
    cout << "After sorting: " << endl;
    quick_sort(numbers, 0, numbers.size()); // sorting the vector
    print_vector(numbers); // print the vector
    return 0;
}

void print_vector(const vector<int> &v) {
    string sep(50, '-');
    cout << sep << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl << sep << endl;
}

void bubble_sort(vector<int> &v) {
    bool swaped;
    int k = 0;
    do {
        swaped = false;
        for (int i = 1; i < v.size() - k; ++i)
            if (v[i - 1] > v[i]) {
                swap(v[i - 1], v[i]);
                swaped = true;
            }
        ++k;
    } while (swaped);
}

void insertion_sort(vector<int> &v) {
    for (int i = 1,  j; i < v.size() ; ++i) {
        j = i;
        while (j > 0 and v[j - 1] > v[j]) {
            swap(v[j - 1], v[j]);
            --j;
        }
    }
}

void selection_sort(vector<int> &v) {
    for (int i = 0, min = v[i]; i < v.size(); ++i) {
        min = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min]) min = j;
        }
        swap(v[i], v[min]);
    }
}

void quick_sort(vector<int> &v, int left, int right) {
    // TODO: Correct this
    int i = left, j = right;
    int pivot = v[(left + right) / 2];

    while (i <= j) {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    };

    if (left < j) quick_sort(v, left, j);
    if (i < right) quick_sort(v, i, right);
}
