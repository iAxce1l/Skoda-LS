#include <stdio.h>
#include <stdlib.h>


struct complex {
    float real;
    float i;
};


void print_cplx(struct complex c) {
    printf("[ %.2f + %.2fi ]\n", c.real, c.i);
}


float cplx_real(struct complex c) {
    return c.real;
}

float cplx_imag(struct complex c) {
    return c.i;
}

struct complex cplx_conj(struct complex c) {
    struct complex result;
    result.real =  c.real;
    result.i    = -c.i;
    return result;
}


struct complex cplx_add(const struct complex cplx1, const struct complex cplx2) {
    struct complex result;
    result.real = cplx1.real + cplx2.real;
    result.i    = cplx1.i    + cplx2.i;
    return result;
}


struct complex cplx_sub(const struct complex cplx1, const struct complex cplx2) {
    struct complex result;
    result.real = cplx1.real - cplx2.real;
    result.i    = cplx1.i    - cplx2.i;
    return result;
}

struct complex cplx_mul(const struct complex cplx1, const struct complex cplx2) {
    struct complex result;
    result.real = cplx1.real * cplx2.real - cplx1.i * cplx2.i;
    result.i    = cplx1.real * cplx2.i    + cplx1.i * cplx2.real;
    return result;
}


struct complex* cplx_conj_ptr(struct complex c) {
    struct complex* result = malloc(sizeof(struct complex));
    result->real =  c.real;
    result->i    = -c.i;
    return result;
}

struct complex* cplx_add_ptr(const struct complex cplx1, const struct complex cplx2) {
    struct complex* result = malloc(sizeof(struct complex));
    result->real = cplx1.real + cplx2.real;
    result->i    = cplx1.i    + cplx2.i;
    return result;
}

struct complex* cplx_sub_ptr(const struct complex cplx1, const struct complex cplx2) {
    struct complex* result = malloc(sizeof(struct complex));
    result->real = cplx1.real - cplx2.real;
    result->i    = cplx1.i    - cplx2.i;
    return result;
}

struct complex* cplx_mul_ptr(const struct complex cplx1, const struct complex cplx2) {
    struct complex* result = malloc(sizeof(struct complex));
    result->real = cplx1.real * cplx2.real - cplx1.i * cplx2.i;
    result->i    = cplx1.real * cplx2.i    + cplx1.i * cplx2.real;
    return result;
}


int main() {
    struct complex a = {3.0, -2.0};
    struct complex b = {2.0, -6.0};

    printf("a = ");        print_cplx(a);
    printf("b = ");        print_cplx(b);
    printf("conj(a) = ");  print_cplx(cplx_conj(a));
    printf("a + b = ");    print_cplx(cplx_add(a, b));
    printf("a - b = ");    print_cplx(cplx_sub(a, b));
    printf("a * b = ");    print_cplx(cplx_mul(a, b));

    struct complex* sum = cplx_add_ptr(a, b);
    printf("a + b (ptr) = "); print_cplx(*sum);
    free(sum);

    return 0;
}
