#include <stdio.h>

int main() {
    char A = 25, B = 62, Value;
    
    Value = A & B;
    printf("Hasil A & B = %d\n", Value);
    Value = A | B;
    printf("Hasil A | B = %d\n", Value);
    
    return 0;
}