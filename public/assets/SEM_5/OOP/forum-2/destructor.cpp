#include <iostream>

class Kotak {
public:
    int panjang, lebar;
    
    // Constructor
    Kotak(int p, int l) {
        panjang = p;
        lebar = l;
        std::cout << "Objek Kotak telah dibuat!" << std::endl;
    }
    
    // Destructor
    ~Kotak() {
        std::cout << "Objek Kotak telah dihapus!" << std::endl;
    }
};

int main() {
    Kotak kotak1(3, 4); // Membuat objek kotak1
    // Objek kotak1 dihapus secara otomatis saat program selesai
    return 0;
}
