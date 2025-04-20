#include <iostream>

// Template function untuk menemukan nilai maksimum dari dua nilai
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Contoh penggunaan dengan integer
    std::cout << "Nilai maksimum dari 5 dan 10 adalah: " << max(5, 10) << std::endl;

    // Contoh penggunaan dengan double
    std::cout << "Nilai maksimum dari 5.5 dan 3.3 adalah: " << max(5.5, 3.3) << std::endl;

    return 0;
}
