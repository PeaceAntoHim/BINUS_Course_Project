#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Base class for temperature scales
class TemperatureScale {
public:
    virtual double toCelsius(double value) const = 0;
    virtual double fromCelsius(double value) const = 0;
    virtual ~TemperatureScale() {}
};

// Concrete class for Celsius scale
class CelsiusScale : public TemperatureScale {
public:
    double toCelsius(double value) const override {
        return value;
    }

    double fromCelsius(double value) const override {
        return value;
    }
};

// Concrete class for Kelvin scale
class KelvinScale : public TemperatureScale {
public:
    double toCelsius(double value) const override {
        return value - 273.15;
    }

    double fromCelsius(double value) const override {
        return value + 273.15;
    }
};

// Concrete class for Fahrenheit scale
class FahrenheitScale : public TemperatureScale {
public:
    double toCelsius(double value) const override {
        return (value - 32) * 5 / 9;
    }

    double fromCelsius(double value) const override {
        return (value * 9 / 5) + 32;
    }
};

// Concrete class for Reamur scale
class ReamurScale : public TemperatureScale {
public:
    double toCelsius(double value) const override {
        return value * 5 / 4;
    }

    double fromCelsius(double value) const override {
        return value * 4 / 5;
    }
};

// Temperature converter class
class TemperatureConverter {
private:
    unique_ptr<TemperatureScale> scale;

public:
    TemperatureConverter(unique_ptr<TemperatureScale> s) : scale(std::move(s)) {}

    double convertToCelsius(double value) const {
        return scale->toCelsius(value);
    }

    double convertFromCelsius(double value) const {
        return scale->fromCelsius(value);
    }
};

int main() {
    double temperature;
    string scaleName;

    cout << "Please enter the temperature format as follows:" << endl;
    cout << "Example: 99 Celsius or 99 Kelvin or 99 Fahrenheit or 99 Reamur." << endl;
    cout << endl;

    while (true) {
        cout << "Enter temperature: ";
        cin >> temperature >> scaleName;

        unique_ptr<TemperatureScale> scale;
        if (scaleName == "Celsius") {
            scale = make_unique<CelsiusScale>();
             TemperatureConverter converter(std::move(scale));
        cout << "Temperature in Kelvin: " << converter.convertFromCelsius(temperature) << endl;
        cout << "Temperature in Fahrenheit: " << converter.convertFromCelsius(temperature) * 9 / 5 + 32 << endl;
        cout << "Temperature in Reamur: " << converter.convertToCelsius(temperature) * 4 / 5 << endl;
        cout << endl;
        } else if (scaleName == "Kelvin") {
            scale = make_unique<KelvinScale>();
                    cout << "Temperature in Celsius: " << converter.convertToCelsius(temperature) << endl;
        cout << "Temperature in Fahrenheit: " << converter.convertFromCelsius(temperature) * 9 / 5 + 32 << endl;
        cout << "Temperature in Reamur: " << converter.convertToCelsius(temperature) * 4 / 5 << endl;
        cout << endl;
        } else if (scaleName == "Fahrenheit") {
            scale = make_unique<FahrenheitScale>();
                    cout << "Temperature in Celsius: " << converter.convertToCelsius(temperature) << endl;
        cout << "Temperature in Kelvin: " << converter.convertFromCelsius(temperature) << endl;
        cout << "Temperature in Reamur: " << converter.convertToCelsius(temperature) * 4 / 5 << endl;
        cout << endl;
        } else if (scaleName == "Reamur") {
            scale = make_unique<ReamurScale>();
                    cout << "Temperature in Celsius: " << converter.convertToCelsius(temperature) << endl;
        cout << "Temperature in Kelvin: " << converter.convertFromCelsius(temperature) << endl;
        cout << "Temperature in Fahrenheit: " << converter.convertFromCelsius(temperature) * 9 / 5 + 32 << endl;
        cout << endl;
        } else {
            cout << "Invalid temperature scale. Please enter 'Celsius', 'Kelvin', 'Fahrenheit', or 'Reamur'." << endl;
            cout << "Example: 99 Celsius or 99 Kelvin or 99 Fahrenheit or 99 Reamur." << endl;
            cout << endl;
            continue;
        }
    }

    return 0;
}
