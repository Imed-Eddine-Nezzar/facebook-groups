/*
Generate all possible permutations of length N.
Rules:
d1 < d2 < d3 < d4 < d5 ...
Eg:
input  >> 4
output >> 
    1234
    2345
    2456
...
*/
#include <stdio.h>
#include <math.h> // importing pow()

// Prototypes
void _generateOredered(int result, int digit, int power, int limit);
void generateOredered(int limit);

int main(void) {
    int n;
    do {
        printf("Enter number of digits [1-9]: "); scanf("%d", &n);
    } while (n < 1 || n > 9);
    generateOredered(n);
    return 0;
}

// Main function
void generateOredered(int limit) { _generateOredered(0, 9, 1, limit); }

// Helper function
void _generateOredered(int result, int digit, int power, int limit) {
    // Base Case
    if (power == pow(10, limit)) {
        printf("%d\n", result);
        return; // return to caller
    };
    int i;
    for (i = digit; i >= 1; --i) {
        _generateOredered(result + i * power, i - 1, power * 10, limit);
    }
}
