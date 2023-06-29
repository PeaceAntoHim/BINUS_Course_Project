#include <stdio.h>

int main () {
    unsigned char Y, NIM = 56;
    
    Y = NIM >> 2;
    printf("Y = %d\n", Y);
    Y = NIM << 3;
    printf("Y = %d", Y);
    
}