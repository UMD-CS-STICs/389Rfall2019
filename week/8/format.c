#include <stdio.h>

void foo(char *str, int *a_x) {
    /* print the location of x this execution, might help to ensure offset chosen correctly */
    printf("x location: %p\n", a_x);

    /* print the value of x */
    printf("before x value: %x\n", *a_x);

    /* print user-provided string */
    printf(str);

    /* print the value of x */
    printf("\nafter x value: %x\n", *a_x);
}

int main(int argc, char **argv) {
    /* x, a 4-byte sequence encoded as an integer, exists on the stack */
    int x = 0xdeadbeef;

    /* simple argc check */
    if (argc < 2) {
        fprintf(stderr, "Please provide a string to print.\n");
        return -1;
    }

    foo(argv[1], &x);

    return 0;
}