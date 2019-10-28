#include <stdio.h>
#include <stdint.h>

int main(void) {
    int x = 0;
    int *y;
    
    *((uint16_t*)(((char*)&x))) = 0xdead;
    *((uint16_t*)(((char*)&x)+2)) = 0xbeef;

    y = (int*) "\xef\xbe\xad\xde";

    printf("%x\n", x);
    printf("%x\n", *y);
}
