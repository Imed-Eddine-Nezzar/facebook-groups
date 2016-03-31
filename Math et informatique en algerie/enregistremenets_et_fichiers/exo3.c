#include <stdio.h>

// Point definition from "exo2.c"
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

Point* compute_mid(Point* a, Point* b) {
    double mid_x = (a->x + b->x) / 2,
           mid_y = (a->y + b->y) / 2;

    Point* mid = make_point(mid_x, mid_y);

    return mid;
}

int main() {
    double x, y;
    printf("Enter coordinates of point A: ");
    scanf("%lf %lf", &x, &y);
    Point* a = make_point(x, y);

    printf("Enter coordinates of point B: ");
    scanf("%lf %lf", &x, &y);
    Point* b = make_point(x, y);

    Point* c = compute_mid(a, b);

    print_point(c);

    return 0;
}