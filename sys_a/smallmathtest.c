#include <stdio.h>
#include "libsmallmath/libsmallmath.h"

int main() {
    float a = 5.0, b = 2.0;

    printf("Addition: %f\n", m_add(a, b));
    printf("Subtraction: %f\n", m_sub(a, b));
    printf("Multiplication: %f\n", m_mult(a, b));
    printf("Division: %f\n", m_div(a, b));
    printf("Power: %f\n", m_pow(a, b));

    return 0;
}