#include <stdio.h>

#define Box(T) struct { \
    T value; \
}
#define box_set(box, val) (box).value = (val); 
#define box_get(box) ((box).value)

int main(void)
{
    Box(char) a;
    Box(double) b;

    box_set(b, 'A');
    box_set(b, 3.14);

    char x = box_get(a);
    double y = box_get(b);

    printf("char: %c\n", x);
    printf("double: %f\n", y);

    return 0;
}