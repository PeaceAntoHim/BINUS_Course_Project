#include <iostream>
using namespace std;

class Mobil {
  public:

  Mobil() {
    cout << "Objek Mobil telah dibuat" << endl;
  }

  ~Mobil() {
    cout << "Objek Mobil telah dihapus" << endl;
  }
};

int main() {
    Mobil mobilSaya; // Membuat objek dari class Mobil
    return 0;
}