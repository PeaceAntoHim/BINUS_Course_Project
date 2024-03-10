// Deklarasi namespace
namespace Matematika {
    int tambah(int a, int b) {
        return a + b;
    }
}

namespace Fisika {
    int tambah(int a, int b) {
        return a - b;
    }
}

int main() {
    // Memanggil fungsi tambah() dari namespace Matematika
    Matematika::tambah(5, 3);

    // Memanggil fungsi tambah() dari namespace Fisika
    Fisika::tambah(5, 3);
    return 0;
}