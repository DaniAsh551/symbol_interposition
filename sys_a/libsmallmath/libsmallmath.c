#include "libsmallmath.h"

float m_add(float a, float b) {
    return a + b;
}

float m_sub(float a, float b) {
    return a - b;
}

float m_mult(float a, float b) {
    return a * b;
}

float m_div(float a, float b) {
    return a / b;
}

float m_pow(float a, float b) {
    // Implement power using multiplication
    float result = 1;
    for (int i = 0; i < b; ++i) {
        result = m_mult(result, a);
    }
    return result;
}