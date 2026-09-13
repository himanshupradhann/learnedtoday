#include <stdio.h>

typedef enum {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_FLOAT,
    TYPE_LONG,
} Datatype;

// Core generic addition function remains untouched
void add_core(const void* a, const void* b, void* result, Datatype data) {
    switch(data) {
        case TYPE_INT:
            *(int*)result = *(const int*)a + *(const int*)b;
            break;
        case TYPE_DOUBLE:
            *(double*)result = *(const double*)a + *(const double*)b;
            break;
        case TYPE_FLOAT:
            *(float*)result = *(const float*)a + *(const float*)b;
            break;
        case TYPE_LONG:
            *(long*)result = *(const long*)a + *(const long*)b;
            break;
        default:
            printf("\n");
            break;
    }
}

// THE MACRO LAYER: Uses C11 _Generic to detect the type of 'x' automatically
// It grabs the addresses and the correct enum flag for you.
#define smart_add(x, y, res) add_core(&(x), &(y), &(res), _Generic((x), \
    int:    TYPE_INT,                                                   \
    double: TYPE_DOUBLE,                                                \
    float:  TYPE_FLOAT,                                                 \
    long:   TYPE_LONG                                                   \
))

int main(void) {
    // Scenario 1: Doubles
    double x = 10.5;
    double y = 20.3;
    double d_result = 0; // Fix: Allocate actual stack memory for the result
    
    // Clean call: No addresses or enums needed!
    smart_add(x, y, d_result);
    printf("Double Result: %f\n", d_result);

    // Scenario 2: Integers
    int a = 5;
    int b = 12;
    int i_result = 0;
    
    smart_add(a, b, i_result);
    printf("Integer Result: %d\n", i_result);

    return 0;
}
