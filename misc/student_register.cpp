#include <iostream>
#include <vector>
using namespace std;

/************************************************
* Prototypes
************************************************/
/************************************************
* Exo 4 
************************************************/
template <typename T>
void sort(vector<T>& list);

template <typename T>
int min(const vector<T>& list, int i = 0);

template <typename T>
void swap(T& a, T& b);

/************************************************
* Exo 5
************************************************/
template <typename T>
int isearch(const vector<T>& haystack, const T& needle);

template <typename T>
int rsearch(const vector<T>& haystack, const T& needle, int beg = 0, int end = -1);

int main(void) {
    // variables
    vector<string> names; // names container
    int n;                // number of names
    string name;          // temperary variable

    // getting names
    cout << "How many names will you enter? "; cin >> n;
    while (n-- and cin >> name) names.push_back(name);

    // sorting and printing names
    sort(names);
    for (string x : names) cout << x << endl;

    // searching for name using recursion
    cout << "Enter name you want to search for: "; cin >> name;
    int x = rsearch(names, name);
    if (x != -1) 
        cout << names[x] << endl;
    else 
        cout << "Name not found!" << endl;

    // searching for name using iteration
    cout << "Enter name you want to search for: "; cin >> name;
    x = isearch(names, name);
    if (x != -1) 
        cout << names[x] << endl;
    else 
        cout << "Name not found!" << endl;
    return 0;
}

/************************************************
* Implementation
************************************************/
/************************************************
* Exo 4
************************************************/
template <typename T>
int min(const vector<T>& list, int i) {
    /*
        Template function to find the smallest value
        and return it's index in list

        Complexity: O(n)
    */
    // error checking
    // i must be in the range [0, list_size - 1]
    if (i < 0 or i > list.size() - 1) return -1;
    int m = i;
    for (; i < list.size(); ++i)
        if (list[i] < list[m]) m = i;
    return m;
}

template <typename T>
void swap(T& a, T& b) {
    /*
        Template function to swap two values 

        Complexity: O(1)
    */
    T t = *a;
    *a = *b;
    *b = t;
}

template <typename T>
void sort(vector<T>& list) {
    /*
        Template function for sorting using
        selection sort to sort the list

        Complexity: O(n^2)
    */

    if (list.empty()) return;                           // if no element in list, do nothing
    for (int i = 0, m; i < list.size(); ++i) {          // traverse the list
        m = min(list, i);                               // find the index of the smallest value
        swap(list[m], list[i]);                         // swap the current value with the smaller one
    }                                                   // repeat until the list is sorted
}

/************************************************
* Exo 5
************************************************/
// binary search using iteration
template <typename T>
int isearch(const vector<T>& haystack, const T& needle) {
    /*
        Template function to search for value (needle)
        in a list (haystack)

        Complexity: O(log(n))
    */
    if (haystack.empty()) return -1;                    // if no element in list return -1
    // basic setup
    int beg = 0,                                        // start search at index 0
        end = haystack.size() - 1,                      // end search at endex (size of list)
        mid;

    while (beg < end) {
        mid = (beg + end) / 2;                          // compute the middle
        if (haystack[mid] == needle) return mid;        // if the value in the middle matches return the middle index
        else if (haystack[mid] > needle) beg = mid + 1; // if it's greater search the right half
        else end = mid - 1;                             // if it's smaller search the left half
    }
    return -1;                                          // if not found return -1
}

// binary search using recursion
template <typename T>
int rsearch(const vector<T>& haystack, const T& needle, int beg, int end) {
    /*
        Template function to search for value (needle)
        in a list (haystack)

        Complexity: O(log(n))
    */
    if (haystack.empty()) return -1;                    // if no element in list return -1
    if (end == -1) end = haystack.size() - 1;           // if no end is given, set end to (size of list)
    int mid = (beg + end) / 2;                          // compute the middle
    if (haystack[mid] == needle) return mid;            // if the value in the middle matches, return it's index
    else if (haystack[mid] > needle)                    // if it's greater search the right half
        return rsearch(haystack, needle, mid + 1, end);
    else                                                // if it's smaller search  the left half
        return rsearch(haystack, needle, beg, mid - 1); // if not found return -1
    return -1;
}