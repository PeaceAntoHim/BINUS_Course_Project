#include <iostream>
using namespace std;

namespace MyNamespace {
    void fungsi() {
        cout << "Ini dari namespace saya" << endl;
    }
}

int main() {
    MyNamespace::fungsi(); // Memanggil fungsi dari namespace MyNamespace
    return 0;
}