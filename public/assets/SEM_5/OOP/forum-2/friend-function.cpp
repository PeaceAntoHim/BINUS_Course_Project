#include <iostream>

class A {
private:
    int x;
public:
    A() : x(0) {}

    // Mendeklarasikan friend function di dalam kelas A
    friend void display(A obj);
};

// Mengimplementasikan friend function di luar kelas A
void display(A obj) {
    // Friend function dapat mengakses anggota private dari kelas A
    std::cout << "Nilai x dari objek A: " << obj.x << std::endl;
}

int main() {
    A obj;
    display(obj);
    return 0;
}
