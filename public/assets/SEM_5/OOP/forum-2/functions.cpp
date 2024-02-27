#include <iostream>

// Fungsi untuk menambahkan dua bilangan
int tambah(int a, int b) {
    return a + b;
}

int main() {
    int hasil = tambah(3, 4); // Memanggil fungsi tambah
    std::cout << "Hasil penambahan: " << hasil << std::endl;
    return 0;
}