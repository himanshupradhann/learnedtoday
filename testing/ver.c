#include <stdio.h>

int main() {
    #ifdef __STDC_VERSION__
        long version = __STDC_VERSION__;
        if (version >= 201112L) {
            printf("Yes! You have C11 or newer (Version value: %ldL)\n", version);
        } else if (version == 199901L) {
            printf("You are using C99 (Version value: %ldL)\n", version);
        } else {
            printf("You are using an older C standard (Version value: %ldL)\n", version);
        }
    #else
        printf("You are using C90 or an older standard.\n");
    #endif
    return 0;
}
