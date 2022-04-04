#include <stdio.h>

//prototype fungsi
void tukar(int *px, int *py); 

void main() {
    int a= 88,b = 77;
    printf("Nilai sebelum pemanggilan fungsi\n");
    printf("a = %d b = %d\n", a, b);
    tukar(&a, &b); //alamat a dan alamat b
    printf("\nNilai setelah pemanggilan fungsi\n");
    printf("a = %d b = %d\n", a, b);
}

void tukar(int *px, int *py) {
    int z;
    z = *px;
    *px = *py;
    *py = z;
    printf("\nNilai di akhir fungsi tukar()\n");
    printf("x = %d y = %d\n", *px, *py);
}