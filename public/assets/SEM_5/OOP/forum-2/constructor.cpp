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
};

int main() {
    Kotak kotak1(3, 4); // Membuat objek kotak1
    return 0;
}

