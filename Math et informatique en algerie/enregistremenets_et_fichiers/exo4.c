#include <stdlib.h>

typedef struct Complex {
    int real,
        imaginary;
};

Complex* make_complex(int real, int imaginary) {
    Complex* cmp = (Complex*) malloc(sizeof(Complex));

    cmp->real = real;
    cmp->imaginary = imaginary;

    return cmp;
}

void destroy_complex(Complex* cmp) { free(cmp); }

Complex* add(Complex* a, Complex* b) {
    int real = a->real + b->real,
        imaginary = a->imaginary + b->imaginary;

    Complex* result = make_complex(real, imaginary);

    return result;
}

Complex* product(Complex* a, Complex* b) {
    x  = a->real;    y  = a->imaginary;
    xi = b->real;    yi = b->imaginary;

    int real = (x * xi) - (y * yi),
        imaginary = (x * yi) - (y * xi);

    Complex* result = make_complex(real, imaginary);

    return result;
}

Complex* divide(Complex* a, Complex* b) {
    x  = a->real;    y  = a->imaginary;
    xi = b->real;    yi = b->imaginary;

    int real = (x * xi + y * yi) / (xi * xi + yi * yi),
        imaginary = (x * yi - y * xi) / (xi * xi + yi * yi);

    Complex* result = make_complex(real, imaginary);

    return result;
}
