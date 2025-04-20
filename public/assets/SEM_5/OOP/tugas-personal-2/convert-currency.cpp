#include <iostream>
#include <iomanip> // Untuk std::setprecision
#include <sstream> // Untuk std::ostringstream

// Interface untuk konversi mata uang
class CurrencyConverter
{
public:
  virtual std::string convert(double amount) = 0;
  virtual ~CurrencyConverter() {}
};

// Konversi mata uang ke US Dollar
class USDConverter : public CurrencyConverter
{
public:
  std::string convert(double amount) override
  {
    double convertedAmount = amount / 16000; // Kurs Rupiah ke Dollar saat ini
    return formatCurrency(convertedAmount);
  }

private:
  std::string formatCurrency(double amount)
  {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << std::setw(10) << std::right << std::setfill(' ')
        << std::put_money(amount, true) << " USD";
    return oss.str();
  }
};

// Konversi mata uang ke Ringgit Malaysia
class MYRConverter : public CurrencyConverter
{
public:
  std::string convert(double amount) override
  {
    double convertedAmount = amount / 3400; // Kurs Rupiah ke Ringgit Malaysia saat ini
    return formatCurrency(convertedAmount);
  }

private:
  std::string formatCurrency(double amount)
  {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << std::setw(10) << std::right << std::setfill(' ')
        << std::put_money(amount, true) << " MYR";
    return oss.str();
  }
};

// Factory untuk membuat objek konverter
class CurrencyConverterFactory
{
public:
  static CurrencyConverter *createConverter(char choice)
  {
    switch (choice)
    {
    case 'a':
      return new USDConverter();
    case 'b':
      return new MYRConverter();
    default:
      return nullptr;
    }
  }
};

int main()
{
  char choice;
  double amount;

  std::cout << "Program Konversi Mata Uang\n";
  std::cout << "Input:\n";
  std::cout << "Pilih konversi\n";
  std::cout << "a. US Dollar\n";
  std::cout << "b. Ringgit Malaysia\n";
  std::cout << "Masukkan pilihan Anda (a/b): ";
  std::cin >> choice;

  CurrencyConverter *converter = CurrencyConverterFactory::createConverter(choice);

  if (converter)
  {
    std::cout << "Masukkan jumlah uang dalam Rupiah: ";
    std::cin >> amount;

    std::string convertedAmount = converter->convert(amount);
    std::cout << "Hasil konversi: " << convertedAmount << std::endl;

    delete converter;
  }
  else
  {
    std::cout << "Pilihan tidak valid.\n";
  }

  return 0;
}
