// Copyright (c) 2016. Imed Eddine Nezzar <imad.eddine.nezzar[at]gmail.com>
#include <iostream>
#include <algorithm>    // swap()
#include <vector>       // vector<double>
#define MAX_SIZE 10
using namespace std;

vector<double> sum(const vector<double>& pli, const vector<double>& plii) {
    /*
    Return the sum to two polynomial equations.
    Example: 

         a x^n + b x^(n-1)...
     +   a'x^n + b'x^(n-1)...
     -----------------------------------
        (a + a')x^n + (b + b')x^(n-1)...
    */
    vector<double> r(MAX_SIZE);
    for (int power = 0; power < MAX_SIZE; ++power) {
        r[power] = pli[power] + plii[power];
    }
    return r;
}

vector<double> multiply (const  vector<double>& pli, const vector<double>& plii) {
    /*
    Return the multiplication to two polynomial equations.
    TODO: implement this correclly
    */
    vector<double> r(MAX_SIZE * 2);
    for (int power = 0; power < MAX_SIZE; ++ power) {
        r[power * 2] = pli[power] * plii[power];
    }
    return r;
}

vector<double> derive(const vector<double>& pl) {
    vector<double> r(MAX_SIZE);
    for (int power = 1; power < MAX_SIZE; ++power) {
        r[power - 1] = pl[power] * power;
    }
    return r;
}

vector<double> integral(const vector<double>& pl) {
    vector<double> r(MAX_SIZE);
    for (int power = MAX_SIZE - 1; power >= 0; --power) {
        r[power + 1] = pl[power] / power;
    }
    return r;
}

int comp(const vector<double>& pli, const vector<double>& plii) {
    for (int power = MAX_SIZE; power >= 0; --power) {
        if (pli[power] < plii[power])      return -1;
        else if (pli[power] > plii[power]) return 1;
    }
    return 0;
}

int min(const vector<vector<double> >& stack) {
    int m = 0;
    for (int i = 1; i < MAX_SIZE; ++i) {
        if (comp(stack[m], stack[i]) == 1)
            m = i;
    }
    return m;
}

int max(const vector<vector<double> >& stack) {
    int m = 0;
    for (int i = 1; i < MAX_SIZE; ++i) {
        if (comp(stack[m], stack[i]) == -1)
            m = i;
    }
    return m;
}

void sort(vector<vector<double> >& stack) {
    bool swapped;
    int k = 0;
    do {
        swapped = false;
        for (int i = 1; i < MAX_SIZE - k; ++i) {
            if (comp(stack[i], stack[i - 1]) == -1) {
                swap(stack[i], stack[i - 1]);
                swapped = true;
            }
        }
        ++k;
    } while (swapped);
}

int main(void) {
    // FIXME: complete this.
    return 0;
}
