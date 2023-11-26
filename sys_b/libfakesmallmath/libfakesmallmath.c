#include <stdio.h>
#include <dlfcn.h>

// Include the header file with function declarations
#include "libfakesmallmath.h"

// Function definitions using the available functions from system_b's libsmallmath
float m_mult(float a, float b) {
    // Since pow is not available, implement multiplication using repeated addition
    float result = 0;
    for (int i = 0; i < b; ++i) {
        result = m_add(result, a);
    }
    return result;
}

float m_div(float a, float b) {
    // Since pow is not available, implement division using repeated subtraction
    float result = 0;
    while (a >= b) {
        result = m_add(result, 1);
        a = m_sub(a, b);
    }
    return result;
}

float m_pow(float a, float b) {
    // Implement power using multiplication
    float result = 1;
    for (int i = 0; i < b; ++i) {
        result = m_mult(result, a);
    }
    return result;
}

// Provide an implementation for the add and sub functions
float m_add(float a, float b) {
    // Use the corresponding function from system_b's libsmallmath
    void *libsmallmath_b_handle = dlopen("libsmallmath.so", RTLD_LAZY);
    if (!libsmallmath_b_handle) {
        fprintf(stderr, "Error opening libsmallmath.so: %s\n", dlerror());
        return 0.0;
    }

    float (*add_func)(float, float) = dlsym(libsmallmath_b_handle, "m_add");
    if (!add_func) {
        fprintf(stderr, "Error finding symbol add: %s\n", dlerror());
        dlclose(libsmallmath_b_handle);
        return 0.0;
    }

    float result = add_func(a, b);

    dlclose(libsmallmath_b_handle);

    return result;
}

float m_sub(float a, float b) {
    // Use the corresponding function from system_b's libsmallmath
    void *libsmallmath_b_handle = dlopen("libsmallmath.so", RTLD_LAZY);
    if (!libsmallmath_b_handle) {
        fprintf(stderr, "Error opening libsmallmath.so: %s\n", dlerror());
        return 0.0;
    }

    float (*sub_func)(float, float) = dlsym(libsmallmath_b_handle, "m_sub");
    if (!sub_func) {
        fprintf(stderr, "Error finding symbol sub: %s\n", dlerror());
        dlclose(libsmallmath_b_handle);
        return 0.0;
    }

    float result = sub_func(a, b);

    dlclose(libsmallmath_b_handle);

    return result;
}
