#include <iostream>
#include <string>

// Kelas abstrak Kendaraan
class Kendaraan
{
public:
  virtual ~Kendaraan() {}
  virtual std::string getNama() const = 0;
  virtual int getJumlahRoda() const = 0;
};

// Kelas turunan Mobil dari Kendaraan
class Mobil : public Kendaraan
{
public:
  std::string getNama() const override
  {
    return "Mobil";
  }

  int getJumlahRoda() const override
  {
    return 4;
  }
};

// Kelas turunan Motor dari Kendaraan
class Motor : public Kendaraan
{
public:
  std::string getNama() const override
  {
    return "Motor";
  }

  int getJumlahRoda() const override
  {
    return 2;
  }
};

// Kelas turunan Bajaj dari Kendaraan
class Bajaj : public Kendaraan
{
public:
  std::string getNama() const override
  {
    return "Bajaj";
  }

  int getJumlahRoda() const override
  {
    return 3;
  }
};

int main()
{
  // Polimorfisme: membuat array pointer Kendaraan yang menunjuk pada objek-objek turunan
  Kendaraan *kendaraan[] = {new Mobil(), new Motor(), new Bajaj()};

  // Output informasi kendaraan
  for (int i = 0; i < 3; ++i)
  {
    std::cout << "Informasi Kendaraan\n";
    std::cout << "Nama\t= " << kendaraan[i]->getNama() << std::endl;
    std::cout << "Jumlah Roda\t= " << kendaraan[i]->getJumlahRoda() << " Buah\n\n";
  }

  // Membersihkan memori
  for (int i = 0; i < 3; ++i)
  {
    delete kendaraan[i];
  }

  return 0;
}
