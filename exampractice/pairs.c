#include <stdio.h>

#define Pair(T1, T2) struct{\
    T1 first;\
    T2 secound; \
} 

#define pair_set_first(pair, val) do { \
    _Static_assert( \
        __builtin_types_compatible_p( \
            __typeof__((pair).first), \
            __typeof__(val) \
        ), \
        "Type mismatch!" \
    ); \
    (pair).first = (val); \
} while (0)

#define pair_set_second(pair, val) do { \
    _Static_assert( \
        __builtin_types_compatible_p( \
            __typeof__((pair).secound), \
            __typeof__(val) \
        ), \
        "Type mismatch!" \
    ); \
    (pair).secound = (val); \
} while (0)


#define pair_get_first(pair) ((pair).first)

#define pair_get_second(pair) ((pair).secound)


int main(void)
{
    Pair(int, double) p;

    pair_set_first(p, 10);
    pair_set_second(p, 3.14);

    int a = pair_get_first(p);
    double b = pair_get_second(p);

    printf("%d\n", a);
    printf("%f\n", b);

    return 0;
}