#include <iostream>
using namespace std;

class UtilsConverter
{
public:
  // Celcius ke Kelvin
  static double celciusToKelvin(double celsius)
  {
    return celsius + 273.15;
  }

  // Celcius ke Fahrenheit
  static double celciusToFahrenheit(double celsius)
  {
    return (celsius * 9 / 5) + 32;
  }

  // Celcius ke Reamur
  static double celciusToReamur(double celsius)
  {
    return celsius * 4 / 5;
  }

  // Kelvin ke Celcius
  static double kelvinToCelsius(double kelvin)
  {
    return kelvin - 273.15;
  }

  // Kelvin ke Fahrenheit
  static double kelvinToFahrenheit(double kelvin)
  {
    return (kelvin - 273.15) * 9 / 5 + 32;
  }

  // Kelvin ke Reamur
  static double kelvinToReamur(double kelvin)
  {
    return (kelvin - 273.15) * 4 / 5;
  }

  // Fahrenheit ke Celcius
  static double fahrenheitToCelsius(double fahrenheit)
  {
    return (fahrenheit - 32) * 5 / 9;
  }

  // Fahrenheit ke Kelvin
  static double fahrenheitToKelvin(double fahrenheit)
  {
    return (fahrenheit - 32) * 5 / 9 + 273.15;
  }

  // Fahrenheit ke Reamur
  static double fahrenheitToReamur(double fahrenheit)
  {
    return (fahrenheit - 32) * 4 / 9;
  }

  // Reamur ke Celcius
  static double reamurToCelsius(double reamur)
  {
    return reamur * 5 / 4;
  }

  // Reamur ke Kelvin
  static double reamurToKelvin(double reamur)
  {
    return (reamur * 5 / 4) + 273.15;
  }

  // Reamur ke Fahrenheit
  static double reamurToFahrenheit(double reamur)
  {
    return (reamur * 9 / 4) + 32;
  }
};

int main()
{
  double suhu;
  string skala;

  cout << "Tolong masukan format suhu seperti contoh berikut." << endl;
  cout << "Contoh : 99 Celcius atau 99 Kelvin atau 99 Fahrenheit atau 99 Reamur." << endl;
  cout << "\n"
       << endl;
  while (true)
  {
    cout << "Masukkan suhu: ";
    cin >> suhu >> skala;

    if (skala == "Celcius")
    {
      cout << "Hasil Celcius Ke Kelvin: " << UtilsConverter::celciusToKelvin(suhu) << endl;
      cout << "Hasil Celcius Ke Fahrenheit: " << UtilsConverter::celciusToFahrenheit(suhu) << endl;
      cout << "Hasil Celcius Ke Reamur: " << UtilsConverter::celciusToReamur(suhu) << endl;
    }
    else if (skala == "Kelvin")
    {
      cout << "Hasil Kelvin Ke Celcius: " << UtilsConverter::kelvinToCelsius(suhu) << endl;
      cout << "Hasil Kelvin Ke Fahrenheit: " << UtilsConverter::kelvinToFahrenheit(suhu) << endl;
      cout << "Hasil Kelvin Ke Reamur: " << UtilsConverter::kelvinToReamur(suhu) << endl;
    }
    else if (skala == "Fahrenheit")
    {
      cout << "Hasil Fahrenheit Ke Celcius: " << UtilsConverter::fahrenheitToCelsius(suhu) << endl;
      cout << "Hasil Fahrenheit Ke Kelvin: " << UtilsConverter::fahrenheitToKelvin(suhu) << endl;
      cout << "Hasil Fahrenheit Ke Reamur: " << UtilsConverter::fahrenheitToReamur(suhu) << endl;
    }
    else if (skala == "Reamur")
    {
      cout << "Hasil Reamur Ke Celcius: " << UtilsConverter::reamurToCelsius(suhu) << endl;
      cout << "Hasil Reamur Ke Kelvin: " << UtilsConverter::reamurToKelvin(suhu) << endl;
      cout << "Hasil Reamur Ke Fahrenheit: " << UtilsConverter::reamurToFahrenheit(suhu) << endl;
    }
    else
    {
      cout << "Skala suhu yang dimasukkan tidak valid. Harap masukkan 'Celcius', 'Kelvin', 'Fahrenheit', atau 'Reamur'." << endl;
      cout << "Masukan seperti contoh dibawah ini" << endl;
      cout << "Contoh 99 Celcius atau 99 Kelvin atau 99 Fahrenheit atau 99 Reamur" << endl;
    }

    cout << endl;
  }

  return 0;
}
