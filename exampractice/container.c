#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define Container(T) struct { \
    void *data; \
    size_t size; \
    size_t element_size; \
    size_t capacity; \
    T typeholder; \
}

#define container_init(container) do { \
    (container).data = NULL; \
    (container).size = 0; \
    (container).capacity = 0; \
    (container).element_size = sizeof((container).typeholder); \
} while (0)

#define container_reserve(container, count) do { \
    (container).data = malloc((count) * (container).element_size); \
    (container).capacity = (count); \
} while (0)

#define container_push(container, value) do { \
    __typeof__(value) temp = (value); \
    char *destination = (char *)(container).data \
        + (container).size * (container).element_size; \
    if ((container).size < (container).capacity) { \
        memcpy(destination, &temp, (container).element_size); \
        (container).size++; \
    } \
} while (0)

#define container_get(container, index) \
    (*((__typeof__((container).typeholder) *) \
    ((char *)(container).data + \
    (index) * (container).element_size)))

int main(void)
{
    Container(int) a;

    container_init(a);
    container_reserve(a, 4);

    container_push(a, 10);
    container_push(a, 20);
    container_push(a, 30);
    int x=container_get(a,1);
    printf("%d ",x);
    return 0;
}