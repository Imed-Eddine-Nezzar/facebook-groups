#include <stdio.h>

#define false 0
#define true 1

// prototypes
int is_prime_f(int);  // F1
void is_prime_p(int);  // p1
int is_perfect_f(int);  // F2
void is_perfect_p(int);  // P2
int counter(int, int [], int);  // F3

int main() {
	// getting n
	int n;
	do {
		printf("Enter n (n > 5): "); scanf("%d", &n);
	} while (n <= 5);
	// checking n
	int prime = is_prime_f(n);  // if n is prime (only)
	is_prime_p(n);  // print if n is prime

	int perfect = is_perfect_f(n);  // if n is perfect (only)
	is_perfect_p(n);  // print if n is perfect

	// getting V elements
	int V[n], i;
	for (i = 0; i < n; ++i) {
		printf("V[%d] = ", i);
		scanf("%d", &V[i]);
	}

	// counting Val
	int val;
	printf("Enter a value: "); scanf("%d", &val);
	printf("%d has accured %d times in V\n", val, counter(val, V, n));
	return 0;
}  // end of main
//  F1
int is_prime_f(int a) {
	int i;
	for (i = 2; i < a / 2; ++i) if (a % i == 0) return false;
	return true;
}
// P1
void is_prime_p(int a) {
	printf("%d is %s prime\n", a, (is_prime_f(a) ? "\b":"not"));
}
// F2
int is_perfect_f(int a){
	int sum = 0, i;
	for (i = 1; i < a / 2; ++i) { if (a % i == 0) sum += i; }
	if (a == sum) return true;
	else return false;
}
// P2
void is_perfect_p(int a) {
	printf("%d is %s a perfect number\n", a, (is_perfect_f(a)) ? "\b":"not");
}
// F3
int counter(int x, int arr[], int size) {
	int i, count = 0;
	for (i = 0; i < size; ++i) 
		if (arr[i] == x) ++count;
	return count;
}
