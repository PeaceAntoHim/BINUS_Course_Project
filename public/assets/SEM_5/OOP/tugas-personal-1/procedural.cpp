// Program C sederhana menggunakan pendekatan structured programming
#include <stdio.h>

// Deklarasi fungsi-fungsi
int tambah(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 3;
    int hasil = tambah(x, y);
    printf("Hasil penjumlahan: %d\n", hasil);
    return 0;
}
