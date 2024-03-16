#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

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
}

namespace GajiNamespace {
    class GajiKaryawan {
    public:
        virtual double hitungGaji() = 0;
        virtual void setGolongan(int golongan) = 0;
        virtual void setLemburan(int jam) = 0;
        virtual void printInfo() = 0;
    };

    class Karyawan : public GajiKaryawan {
    private:
        int golongan;
        int nilaiGaji;
        double pajak;
        int lemburan;
        int nilaiLemburan;

    public:
        Karyawan() {
            golongan = 0;
            nilaiGaji = 0;
            pajak = 0;
            lemburan = 0;
            nilaiLemburan = 0;
        }

        void setGolongan(int golongan) override {
            this->golongan = golongan;
            switch (golongan) {
                case 1:
                    nilaiGaji = 5000000;
                    pajak = 0.05;
                    break;
                case 2:
                    nilaiGaji = 4000000;
                    pajak = 0.04;
                    break;
                case 3:
                    nilaiGaji = 3000000;
                    pajak = 0.03;
                    break;
                case 4:
                    nilaiGaji = 2000000;
                    pajak = 0.02;
                    break;
                default:
                    cout << "Golongan tidak valid" << endl;
            }
        }

        void setLemburan(int jam) override {
            lemburan = jam;
            if (golongan == 3 || golongan == 4) {
                if (lemburan >= 1 && lemburan <= 3)
                    nilaiLemburan = 100000;
                else
                    nilaiLemburan = 100000 + (lemburan - 3) * 50000;
            } else {
                nilaiLemburan = 0;
            }
        }

        double hitungGaji() override {
            double gajiBersih = (nilaiGaji + nilaiLemburan) * (1 - pajak);
            return  gajiBersih;
        }

        void printInfo() override {
            using namespace Utils;
            double gaji = hitungGaji();
            string gajiStr = doubleToStringWithSeparator(gaji);
            cout << "\n\n***** Start Output *****" << endl;
            cout << "Golongan\t: " << golongan << endl;
            cout << "Lemburan\t: " << lemburan << " Jam" << endl;
            cout << "Gaji\t\t: " << fixed << setprecision(2) << gajiStr << endl;
            cout << "******* End Output *******" << endl;
        }
    };
}

int main() {
    // Menggunakan namespace kustom
    using namespace GajiNamespace;

    Karyawan karyawan;

    int golongan, lemburan;
    cout << "Masukkan golongan karyawan (1-4): ";
    cin >> golongan;
    karyawan.setGolongan(golongan);

    cout << "Masukkan jumlah jam lemburan: ";
    cin >> lemburan;
    karyawan.setLemburan(lemburan);

    cout << endl << "Informasi Gaji Karyawan" << endl;
    karyawan.printInfo();

    return 0;
}
