#include <stdio.h>

void top_secret_function(void) {
    printf("----- ALERT: PLAN TO TAKE DOWN WATTSAMP WEBSITE IS NOW IN ACTION -----\n");
}

void greet(void) {
    char name[10];
    /* prompt user for name */
    printf("What is your name? ");
    /* read name from user via... gets? `man gets` */
    gets(name);
    /* greet the user! */
    printf("Nice to meet you, %s\n", name);
}

int main(void) {
    printf("Don't read our secret plans at %p\n", &top_secret_function);
    greet();
}