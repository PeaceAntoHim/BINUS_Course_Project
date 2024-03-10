#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <climits>
using namespace std;

// Interface untuk menghitung jumlah dana yang akan diterima
class DanaPenerimaan {
public:
    virtual double hitungDana() = 0;
};

// Class untuk mengelola informasi penerima bantuan
class PenerimaBantuan {
private:
    string nama;
    int umur;
    DanaPenerimaan* dana;

public:
    PenerimaBantuan(string _nama, int _umur) : nama(_nama), umur(_umur), dana(nullptr) {}

    void setDanaPenerimaan(DanaPenerimaan* _dana) {
        dana = _dana;
    }

    void tampilkanInfo(string _dana, string nameAge) {
        cout << "\n\n***** Start Output *****" << endl;
        cout << "Nama: " << nama << endl;
        cout << nameAge <<" - Umur: " << umur << " tahun" << endl;
        cout << "Dana yang diterima: " << _dana << endl;
        cout << "***** End Output *****" << endl;
    }
};

// Implementasi kelas DanaPenerimaan untuk bayi, balita, anak-anak
class DanaAnak : public DanaPenerimaan {
public:
    double hitungDana() override {
        return 1000000;
    }
};

// Implementasi kelas DanaPenerimaan untuk remaja, pemuda, dewasa
class DanaDewasa : public DanaPenerimaan {
public:
    double hitungDana() override {
        return 1500000;
    }
};

// Implementasi kelas DanaPenerimaan untuk lansia
class DanaLansia : public DanaPenerimaan {
public:
    double hitungDana() override {
        return 2000000;
    }
};

// Namespace untuk fungsi konversi dan manipulasi string
namespace Utils {
    // Fungsi untuk mengubah nilai double menjadi string dengan tanda titik sebagai pemisah ribu
    string doubleToStringWithSeparator(double value) {
        stringstream ss;
        ss << fixed << setprecision(0) << value; // Mengatur presisi dan memastikan bilangan desimal tidak digunakan
        string str = ss.str();
        int pos = str.length() - 3;
        while (pos > 0) {
            str.insert(pos, ".");
            pos -= 3;
        }
        return str;
    }

    // Fungsi untuk mencari kelas DanaPenerimaan yang sesuai dengan umur
    DanaPenerimaan* cariDanaPenerimaan(int umur) {
        map<pair<int, int>, DanaPenerimaan*> batasDana = {
            {{0, 1}, new DanaAnak()},  // Bayi
            {{1, 3}, new DanaAnak()},  // Batita
            {{3, 5}, new DanaAnak()},  // Balita
            {{5, 12}, new DanaAnak()}, // Anak-anak
            {{12, 17}, new DanaDewasa()}, // Remaja
            {{17, 30}, new DanaDewasa()}, // Pemuda
            {{30, 60}, new DanaDewasa()}, // Dewasa
            {{60, INT_MAX}, new DanaLansia()} // Lansia
        };

        // Mencari kelas DanaPenerimaan yang sesuai dengan umur
        for (const auto& pair : batasDana) {
            if (umur >= pair.first.first && umur < pair.first.second) {
                return pair.second;
            }
        }

        return nullptr;
    }

    string MappingAge(int umur) {
        map<pair<int, int>, string> batasDana = {
            {{0, 1}, "Bayi"},  // Bayi
            {{1, 3}, "Batita"},  // Batita
            {{3, 5}, "Balita"},  // Balita
            {{5, 12}, "Anak-Anak"}, // Anak-anak
            {{12, 17}, "Remaja"}, // Remaja
            {{17, 30}, "Pemuda"}, // Pemuda
            {{30, 60}, "Dewasa"}, // Dewasa
            {{60, INT_MAX}, "Lansia"} // Lansia
        };

        // Mencari kelas DanaPenerimaan yang sesuai dengan umur
        for (const auto& pair : batasDana) {
            if (umur >= pair.first.first && umur < pair.first.second) {
                return pair.second;
            }
        }

        return "Bayi";
    }
}


int main() {
    using namespace Utils;
    string nama;
    int umur;
    cout << "Masukkan nama: ";
    cin >> nama;
    cout << "Masukkan umur: ";
    cin >> umur;

    PenerimaBantuan penerima(nama, umur);
    
    DanaPenerimaan* dana = cariDanaPenerimaan(umur);

    if (dana == nullptr) {
        cout << "Umur tidak valid" << endl;
        return 1;
    }

     // Menghitung dan menampilkan dana yang diterima
    double danaDiterima = dana->hitungDana();
    string danaDiterimaStr = doubleToStringWithSeparator(danaDiterima);

    // Mapping name age
    string nameAge = MappingAge(umur);

    // Function to show value of data
    penerima.tampilkanInfo(danaDiterimaStr, nameAge);

    delete dana; // Hindari kebocoran memori
    return 0;
}
