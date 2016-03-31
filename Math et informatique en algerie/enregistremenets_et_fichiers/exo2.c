#include <stdio.h>
#include <stdlib.h>

typedef struct Point { double x, y; } Point;

Point* make_point(double x, double y) {
    Point* p = (Point*)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

void destroy_point(Point* point) { free(point); }

void print_point(Point* point) {
    printf("Point: x = %.2f, y = %.2f\n", point->x, point->y);
}

int main() {
    Point* A = make_point(-1, 0.9);
    Point* B = make_point(2.5, 6);

    print_point(A);
    print_point(B);

    destroy_point(A);
    destroy_point(B);

    return 0;
}