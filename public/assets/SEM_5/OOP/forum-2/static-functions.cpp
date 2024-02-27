#include <iostream>

class Example {
public:
    static int count; // Static data member
    
    Example() {
        count++; // Setiap kali objek dibuat, nilai count akan bertambah
    }

    static void displayCount() { // Static member function
        std::cout << "Jumlah objek yang dibuat: " << count << std::endl;
    }
};

int Example::count = 0; // Inisialisasi static data member

int main() {
    Example obj1;
    Example obj2;
    Example obj3;

    Example::displayCount(); // Memanggil static member function

    return 0;
}
