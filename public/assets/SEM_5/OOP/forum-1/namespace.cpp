#include <iostream>
using namespace std;

namespace A {
  void fungsi() {
    cout << "Ini dari namespace A" << endl;
  }
}

namespace B {
  void fungsi() {
    cout << "Ini dari namespace B" << endl;
  }
}

int main() {
    A::fungsi(); // Memanggil fungsi dari namespace A
    B::fungsi(); // Memanggil fungsi dari namespace B
    return 0;
}