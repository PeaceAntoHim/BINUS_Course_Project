#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

// Interface for temperature converter
class TemperatureConverter
{
public:
  virtual double convert(double input) const = 0;
};

// Concrete implementation for Celsius to Kelvin conversion
class CelsiusToKelvinConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return input + 273.15;
  }
};

// Concrete implementation for Celsius to Fahrenheit conversion
class CelsiusToFahrenheitConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return (input * 9 / 5) + 32;
  }
};

// Concrete implementation for Celsius to Reamur conversion
class CelsiusToReamurConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return input * 4 / 5;
  }
};

// Concrete implementation for Kelvin to Celsius conversion
class KelvinToCelsiusConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return input - 273.15;
  }
};

// Concrete implementation for Kelvin to Fahrenheit conversion
class KelvinToFahrenheitConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return (input - 273.15) * 9 / 5 + 32;
  }
};

// Concrete implementation for Kelvin to Reamur conversion
class KelvinToReamurConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return (input - 273.15) * 4 / 5;
  }
};

// Concrete implementation for Fahrenheit to Celsius conversion
class FahrenheitToCelsiusConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return (input - 32) * 5 / 9;
  }
};

// Concrete implementation for Fahrenheit to Kelvin conversion
class FahrenheitToKelvinConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return (input - 32) * 5 / 9 + 273.15;
  }
};

// Concrete implementation for Fahrenheit to Reamur conversion
class FahrenheitToReamurConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return (input - 32) * 4 / 9;
  }
};

// Concrete implementation for Reamur to Celsius conversion
class ReamurToCelsiusConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return input * 5 / 4;
  }
};

// Concrete implementation for Reamur to Kelvin conversion
class ReamurToKelvinConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return input * 5 / 4 + 273.15;
  }
};

// Concrete implementation for Reamur to Fahrenheit conversion
class ReamurToFahrenheitConverter : public TemperatureConverter
{
public:
  double convert(double input) const override
  {
    return input * 9 / 4 + 32;
  }
};

// Helper function to perform temperature conversion
double performConversion(const TemperatureConverter &converter, double input)
{
  return converter.convert(input);
}

// Function to validate user input
double validateInput(const std::string &prompt)
{
  double input;
  while (true)
  {
    std::cout << prompt;
    if (std::cin >> input)
    {
      break;
    }
    else
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid number.\n";
    }
  }
  return input;
}

int main()
{
  std::string unit;
  double temperature;

  std::cout << "Tolong masukan format suhu seperti contoh berikut.\n";
  std::cout << "Contoh : 30 celcius atau 30 kelvin atau 30 fahrenheit atau 30 reamur.\n\n";

  std::cout << "Masukkan suhu: ";
  std::cin >> temperature >> unit;

  double result;

  if (unit == "celcius" || unit == "celsius")
  {
    CelsiusToKelvinConverter celsiusToKelvinConverter;
    CelsiusToFahrenheitConverter celsiusToFahrenheitConverter;
    CelsiusToReamurConverter celsiusToReamurConverter;

    result = performConversion(celsiusToKelvinConverter, temperature);
    std::cout << "Hasil Celcius Ke Kelvin: " << result << std::endl;

    result = performConversion(celsiusToFahrenheitConverter, temperature);
    std::cout << "Hasil Celcius Ke Fahrenheit: " << result << std::endl;

    result = performConversion(celsiusToReamurConverter, temperature);
    std::cout << "Hasil Celcius Ke Reamur: " << result << std::endl;
  }
  else if (unit == "kelvin")
  {
    KelvinToCelsiusConverter kelvinToCelsiusConverter;
    KelvinToFahrenheitConverter kelvinToFahrenheitConverter;
    KelvinToReamurConverter kelvinToReamurConverter;

    result = performConversion(kelvinToCelsiusConverter, temperature);
    std::cout << "Hasil Kelvin Ke Celsius: " << result << std::endl;

    result = performConversion(kelvinToFahrenheitConverter, temperature);
    std::cout << "Hasil Kelvin Ke Fahrenheit: " << result << std::endl;

    result = performConversion(kelvinToReamurConverter, temperature);
    std::cout << "Hasil Kelvin Ke Reamur: " << result << std::endl;
  }
  else if (unit == "fahrenheit")
  {
    FahrenheitToCelsiusConverter fahrenheitToCelsiusConverter;
    FahrenheitToKelvinConverter fahrenheitToKelvinConverter;
    FahrenheitToReamurConverter fahrenheitToReamurConverter;

    result = performConversion(fahrenheitToCelsiusConverter, temperature);
    std::cout << "Hasil Fahrenheit Ke Celsius: " << result << std::endl;

    result = performConversion(fahrenheitToKelvinConverter, temperature);
    std::cout << "Hasil Fahrenheit Ke Kelvin: " << result << std::endl;

    result = performConversion(fahrenheitToReamurConverter, temperature);
    std::cout << "Hasil Fahrenheit Ke Reamur: " << result << std::endl;
  }
  else if (unit == "reamur")
  {
    ReamurToCelsiusConverter reamurToCelsiusConverter;
    ReamurToKelvinConverter reamurToKelvinConverter;
    ReamurToFahrenheitConverter reamurToFahrenheitConverter;

    result = performConversion(reamurToCelsiusConverter, temperature);
    std::cout << "Hasil Reamur Ke Celsius: " << result << std::endl;

    result = performConversion(reamurToKelvinConverter, temperature);
    std::cout << "Hasil Reamur Ke Kelvin: " << result << std::endl;

    result = performConversion(reamurToFahrenheitConverter, temperature);
    std::cout << "Hasil Reamur Ke Fahrenheit: " << result << std::endl;
  }
  else
  {
    std::cout << "Unit tidak valid. Silakan masukkan 'celcius', 'kelvin', 'fahrenheit', atau 'reamur'.\n";
    return 1;
  }

  return 0;
}
