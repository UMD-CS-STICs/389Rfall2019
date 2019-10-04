#include <string.h>
#include <stdio.h>

int my_strlen(const char *str) {
    int i = 0;

    while (str[i]) {
        i++;
    }

    return i;
}

int my_strcmp(char *x, char *y) {
    int i, a = strlen(x), b = strlen(y);

    if (a != b) {
        return a-b;
    }

    for (i = 0; i < a; i++) {
        if (x[i] != y[i]) {
            return x[i] - y[i];
        }
    }

    return 0;
}

unsigned char my_is_reverse(char *x, const char *y) {
    int i, a = strlen(x), b = strlen(y);

    if (a != b) {
        return 0;
    }

    for (i = 0; i < a; i++) {
        if (x[i] != y[b-i-1]) {
            return 0;
        }
    }

    return 1;
}



int main(int argc, char **argv) {
    if (argc < 2) {
        printf("provide some parameters!\n");
    }

    if (argc == 2) {
        printf("strlen: %d\n", my_strlen(argv[1]));
    }

    if (argc >= 3) {
        printf("strcmp: %d\n", my_strcmp(argv[1], argv[2]));
        printf("is_reverse %d\n", my_is_reverse(argv[1], argv[2]));
    }
}
