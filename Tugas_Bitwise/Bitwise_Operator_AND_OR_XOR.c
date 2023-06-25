#include <stdio.h>

int main() {
    char A = 23, B = 56, Value;
    
    Value = A & B;
    printf("Hasil A & B = %d\n", Value);
    Value = A | B;
    printf("Hasil A | B = %d\n", Value);
    Value = A ^ B;
    printf("Hasil A ^ B = %d\n", Value);
    
    return 0;
}