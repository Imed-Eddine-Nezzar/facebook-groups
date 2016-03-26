// Copyright (c) 2016. Imed Eddine Nezzar <imad.eddine.nezzar[at]gmail.com>
#include <iostream>
#include <algorithm>    // swap()
#include <vector>       // vector<double>
#define LIMIT 10
using namespace std;

vector<double> sum(const vector<double>& p, const vector<double>& pi) {
    /*
    Return the sum to two polynomial equations.
    Example:

        a x^n + b x^(n-1)...
    +   a'x^n + b'x^(n-1)...
    -----------------------------------
        (a + a')x^n + (b + b')x^(n-1)...
    */
    vector<double> r(LIMIT, 0);
    for (int power = 0; power < LIMIT; ++power)
        r[power] = p[power] + pi[power];
    return r;
}

vector<double> multiply (const  vector<double>& p, const vector<double>& pi) {
    /*
    Return the multipcation to two polynomial equations.
    Example:
        (a x^n + b x^(n-1)...) * (a' x^(n) + b' x^(n-1))
        (aa'x^(n+n) + ab'x^(n+n-1) + ... + ba'x(n+n-1) + bb'x(n-1+n-1) + ...
    */
    vector<double> r(LIMIT * 2, 0);
    for (int outer = 0; outer < LIMIT; ++outer) {
        for (int inner = 0; inner < LIMIT; ++inner) {
            r[outer + inner] += (p[outer] * pi[inner]);
        }
    }
    return r;
}

vector<double> derive(const vector<double>& pl) {
    /*
        * TODO: write documentation
        */
    vector<double> r(LIMIT, 0);
    for (int power = 1; power < LIMIT; ++power)
        r[power - 1] = pl[power] * power;
    return r;
}

vector<double> integral(const vector<double>& pl) {
    /*
        * TODO: write documentation
        * FIXME: correct this implementation
        */
    vector<double> r(LIMIT, 0);
    for (int power = 0; power <LIMIT; ++power)
        r[power + 1] = pl[power] / power + 1;
    return r;
}

int comp(const vector<double>& p, const vector<double>& pi) {
    /*
        * TODO: write documentation
        */
    for (int power = LIMIT; power >= 0; --power) {
        if (p[power] < pi[power])      return -1;
        else if (p[power] > pi[power]) return 1;
    }
    return 0;
}

int min(const vector<vector<double> >& stack) {
    /*
        * TODO: write documentation
        */
    int m = 0;
    for (int i = 1; i < LIMIT; ++i) {
        if (comp(stack[m], stack[i]) == 1)
            m = i;
    }
    return m;
}

int max(const vector<vector<double> >& stack) {
    /*
        * TODO: write documentation
        */
    int m = 0;
    for (int i = 1; i < LIMIT; ++i) {
        if (comp(stack[m], stack[i]) == -1)
            m = i;
    }
    return m;
}

void sort(vector<vector<double> >& stack) {
    /*
        * TODO: write documentation
        */
    bool swapped;
    int k = 0;
    do {
        swapped = false;
        for (int i = 1; i < LIMIT - k; ++i) {
            if (comp(stack[i], stack[i - 1]) == -1) {
                swap(stack[i], stack[i - 1]);
                swapped = true;
            }
        }
        ++k;
    } while (swapped);
}

void printPolynomial(const vector<double>& p) {
    /*
        * TODO: write documentation
        */
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << "(" << i << ") ";
    }
    cout << endl;
}

int main(void) {
    // FIXME: write tests
    int n;
    vector<double> p1(10, 0), p2(10, 0);
    cout << "poli 1: ";
    for (int i = 0; i < 10; ++i) cin >> p1[i];
    cout << "poli 2: ";
    for (int i = 0; i < 10; ++i) cin >> p2[i];

    cout << "sum: " << endl;
    printPolynomial(sum(p1, p2));

    cout << "multi: " << endl;
    printPolynomial(multiply(p1, p2));

    cout << "integral: "<< endl;
    printPolynomial(integral(p1));

    cout << "derive: " << endl;
    printPolynomial(derive(p1));

    return 0;
}
