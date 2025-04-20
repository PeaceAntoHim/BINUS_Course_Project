// Program C++ sederhana menggunakan pendekatan Object-Oriented Programming
#include <iostream>
using namespace std;

// Deklarasi class
class Bilangan {
private:
    int nilai;
public:
    // Konstruktor
    Bilangan(int n) {
        nilai = n;
    }

    // Metode untuk menampilkan nilai
    void tampilkanNilai() {
        cout << "Nilai: " << nilai << endl;
    }
};

int main() {
    // Membuat objek dari class Bilangan
    Bilangan bilangan1(10);
    Bilangan bilangan2(20);

    // Memanggil metode untuk menampilkan nilai
    bilangan1.tampilkanNilai();
    bilangan2.tampilkanNilai();

    return 0;
}
