#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <memory>
using namespace std;

// Single Responsibility: Car class handles car properties and calculations
class Car {
protected:
    string name;
    int year;
    double dailyRate;
    bool isAvailable;

public:
    Car(string n, int y, double d) : name(n), year(y), dailyRate(d), isAvailable(true) {}
    virtual double calculateTotalCost(int days) const = 0;
    string getName() const { return name; }
    int getYear() const { return year; }
    double getDailyRate() const { return dailyRate; }
    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool status) { isAvailable = status; }
    virtual ~Car() = default; // Open/Closed: Car class is open for extension but closed for modification
};

class Sedan : public Car {
public:
    Sedan(string n, int y, double d) : Car(n, y, d) {}
    double calculateTotalCost(int days) const override {
        return dailyRate * days;
    }
};

class SUV : public Car {
public:
    SUV(string n, int y, double d) : Car(n, y, d) {}
    double calculateTotalCost(int days) const override {
        return dailyRate * days * 1.2; // 20% extra for SUVs
    }
};

class Minivan : public Car {
public:
    Minivan(string n, int y, double d) : Car(n, y, d) {}
    double calculateTotalCost(int days) const override {
        return dailyRate * days * 1.1; // 10% extra for Minivans
    }
};

class Transaction {
public:
    string customerName;
    shared_ptr<Car> rentedCar;
    int rentalDuration;
    double totalCost;

    Transaction(const string& c, shared_ptr<Car> r, int d)
        : customerName(c), rentedCar(r), rentalDuration(d) {
        totalCost = rentedCar->calculateTotalCost(d);
        rentedCar->setAvailability(false);
    }
};

class CarRepository {
private:
    vector<shared_ptr<Car>> cars;

public:
    void addCar(shared_ptr<Car> car) {
        cars.push_back(car);
    }

    shared_ptr<Car> findCarByName(const string& name) const {
        for (const auto& car : cars) {
            if (car->getName() == name && car->getAvailability()) {
                return car;
            }
        }
        return nullptr;
    }

    vector<shared_ptr<Car>> getCars() const {
        return cars;
    }

    void saveCarsToFile(const string& filename) const {
        ofstream file(filename);
        for (const auto& car : cars) {
            file << car->getName() << " " << car->getYear() << " " 
                 << car->getDailyRate() << " " << car->getAvailability() << endl;
        }
        file.close();
    }

    void loadCarsFromFile(const string& filename) {
        ifstream file(filename);
        string name;
        int year;
        double rate;
        bool availability;
        while (file >> name >> year >> rate >> availability) {
            shared_ptr<Car> car;
            if (name.find("Sedan") != string::npos)
                car = make_shared<Sedan>(name, year, rate);
            else if (name.find("SUV") != string::npos)
                car = make_shared<SUV>(name, year, rate);
            else
                car = make_shared<Minivan>(name, year, rate);
            car->setAvailability(availability);
            cars.push_back(car);
        }
        file.close();
    }
};

class TransactionManager {
private:
    vector<Transaction> transactions;

public:
    void addTransaction(const string& customerName, shared_ptr<Car> car, int days) {
        transactions.emplace_back(customerName, car, days);
    }

    void displayTransactions() const {
        for (const auto& transaction : transactions) {
            cout << "Customer: " << transaction.customerName 
                 << ", Car: " << transaction.rentedCar->getName() 
                 << ", Duration: " << transaction.rentalDuration 
                 << " days, Total Cost: $" << transaction.totalCost << endl;
        }
    }
};

class RentalSystem {
private:
    CarRepository carRepository;
    TransactionManager transactionManager;

public:
    void addCar(shared_ptr<Car> car) {
        carRepository.addCar(car);
    }

    void addTransaction(const string& customerName, const string& carName, int days) {
        auto car = carRepository.findCarByName(carName);
        if (car) {
            transactionManager.addTransaction(customerName, car, days);
        } else {
            cout << "Car not available or not found." << endl;
        }
    }

    void displayTransactions() const {
        transactionManager.displayTransactions();
    }

    void saveCarsToFile(const string& filename) const {
        carRepository.saveCarsToFile(filename);
    }

    void loadCarsFromFile(const string& filename) {
        carRepository.loadCarsFromFile(filename);
    }

    void searchCarByName(const string& name) const {
        auto car = carRepository.findCarByName(name);
        if (car) {
            cout << "Car Found: " << car->getName() << ", Year: " 
                 << car->getYear() << ", Daily Rate: $" << car->getDailyRate() 
                 << ", Available: " << (car->getAvailability() ? "Yes" : "No") << endl;
        } else {
            cout << "Car not found." << endl;
        }
    }

    void sortCarsByName() {
        auto cars = carRepository.getCars();
        sort(cars.begin(), cars.end(), [](shared_ptr<Car> a, shared_ptr<Car> b) {
            return a->getName() < b->getName();
        });
        displayCars(cars);
    }

    void sortCarsByYear() {
        auto cars = carRepository.getCars();
        sort(cars.begin(), cars.end(), [](shared_ptr<Car> a, shared_ptr<Car> b) {
            return a->getYear() > b->getYear();
        });
        displayCars(cars);
    }

    void displayCars(const vector<shared_ptr<Car>>& cars) const {
        for (const auto& car : cars) {
            cout << "Car: " << car->getName() << ", Year: " << car->getYear() 
                 << ", Daily Rate: $" << car->getDailyRate() 
                 << ", Available: " << (car->getAvailability() ? "Yes" : "No") << endl;
        }
    }

    void displayCars() const {
        displayCars(carRepository.getCars());
    }
};

void displayMenu() {
    cout << "Car Rental System" << endl;
    cout << "1. Add Car" << endl;
    cout << "2. Add Transaction" << endl;
    cout << "3. Display Transactions" << endl;
    cout << "4. Search Car by Name" << endl;
    cout << "5. Sort Cars by Name" << endl;
    cout << "6. Sort Cars by Year" << endl;
    cout << "7. Display Cars" << endl;
    cout << "8. Save Cars to File" << endl;
    cout << "9. Load Cars from File" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    RentalSystem rentalSystem;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                string type, name;
                int year;
                double rate;
                cout << "Enter car type (Sedan/SUV/Minivan): ";
                cin >> type;
                cout << "Enter car name: ";
                cin >> name;
                cout << "Enter car year: ";
                cin >> year;
                cout << "Enter daily rate: ";
                cin >> rate;
                shared_ptr<Car> car;
                if (type == "Sedan")
                    car = make_shared<Sedan>(name, year, rate);
                else if (type == "SUV")
                    car = make_shared<SUV>(name, year, rate);
                else
                    car = make_shared<Minivan>(name, year, rate);
                rentalSystem.addCar(car);
                break;
            }
            case 2: {
                string customerName, carName;
                int days;
                cout << "Enter customer name: ";
                cin >> customerName;
                cout << "Enter car name: ";
                cin >> carName;
                cout << "Enter rental duration (days): ";
                cin >> days;
                rentalSystem.addTransaction(customerName, carName, days);
                break;
            }
            case 3: {
                rentalSystem.displayTransactions();
                break;
            }
            case 4: {
                string name;
                cout << "Enter car name: ";
                cin >> name;
                rentalSystem.searchCarByName(name);
                break;
            }
            case 5: {
                rentalSystem.sortCarsByName();
                break;
            }
            case 6: {
                rentalSystem.sortCarsByYear();
                break;
            }
            case 7: {
                rentalSystem.displayCars();
                break;
            }
            case 8: {
                string filename = "cars.txt";
                rentalSystem.saveCarsToFile(filename);
                break;
            }
            case 9: {
                string filename = "cars.txt";
                rentalSystem.loadCarsFromFile(filename);
                break;
            }
            default: {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    }
    return 0;
}
