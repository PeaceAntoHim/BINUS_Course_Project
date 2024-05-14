#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <memory>
using namespace std;

// Interface for car properties and availability
class ICarProperties
{
public:
  virtual string getName() const = 0;
  virtual int getYear() const = 0;
  virtual double getDailyRate() const = 0;
  virtual bool getAvailability() const = 0;
  virtual void setAvailability(bool status) = 0;
  virtual ~ICarProperties() = default;
};

// Interface for calculating rental cost
class IRentalCost
{
public:
  virtual double calculateTotalCost(int days) const = 0;
  virtual ~IRentalCost() = default;
};

// Single Responsibility: Car class handles car properties and calculations
class Car : public ICarProperties, public IRentalCost
{
protected:
  string name;
  int year;
  double dailyRate;
  bool isAvailable;

public:
  Car(string n, int y, double d) : name(n), year(y), dailyRate(d), isAvailable(true) {}
  virtual double calculateTotalCost(int days) const = 0;
  string getName() const override { return name; }
  int getYear() const override { return year; }
  double getDailyRate() const override { return dailyRate; }
  bool getAvailability() const override { return isAvailable; }
  void setAvailability(bool status) override { isAvailable = status; }
  virtual ~Car() = default; // Open/Closed: Car class is open for extension but closed for modification
};

class Sedan : public Car
{
public:
  Sedan(string n, int y, double d) : Car(n, y, d) {}
  double calculateTotalCost(int days) const override
  {
    return dailyRate * days;
  }
};

class SUV : public Car
{
public:
  SUV(string n, int y, double d) : Car(n, y, d) {}
  double calculateTotalCost(int days) const override
  {
    return dailyRate * days * 1.2; // 20% extra for SUVs
  }
};

class Minivan : public Car
{
public:
  Minivan(string n, int y, double d) : Car(n, y, d) {}
  double calculateTotalCost(int days) const override
  {
    return dailyRate * days * 1.1; // 10% extra for Minivans
  }
};

class Transaction
{
public:
  string customerName;
  shared_ptr<Car> rentedCar;
  int rentalDuration;
  double totalCost;

  Transaction(const string &c, shared_ptr<Car> r, int d)
      : customerName(c), rentedCar(r), rentalDuration(d)
  {
    totalCost = rentedCar->calculateTotalCost(d);
    rentedCar->setAvailability(false);
  }
};

class ICarRepository
{
public:
  virtual void addCar(shared_ptr<Car> car) = 0;
  virtual shared_ptr<Car> findCarByName(const string &name) const = 0;
  virtual vector<shared_ptr<Car>> getCars() const = 0;
  virtual void saveCarsToFile(const string &filename) const = 0;
  virtual void loadCarsFromFile(const string &filename) = 0;
  virtual ~ICarRepository() = default;
};

class CarRepository : public ICarRepository
{
private:
  vector<shared_ptr<Car>> cars;

public:
  void addCar(shared_ptr<Car> car) override
  {
    cars.push_back(car);
  }

  shared_ptr<Car> findCarByName(const string &name) const override
  {
    for (const auto &car : cars)
    {
      if (car->getName() == name && car->getAvailability())
      {
        return car;
      }
    }
    return nullptr;
  }

  vector<shared_ptr<Car>> getCars() const override
  {
    return cars;
  }

  void saveCarsToFile(const string &filename) const override
  {
    ofstream file(filename);
    for (const auto &car : cars)
    {
      file << car->getName() << " " << car->getYear() << " "
           << car->getDailyRate() << " " << car->getAvailability() << endl;
    }
    file.close();
  }

  void loadCarsFromFile(const string &filename) override
  {
    ifstream file(filename);
    string name;
    int year;
    double rate;
    bool availability;
    while (file >> name >> year >> rate >> availability)
    {
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

class ITransactionManager
{
public:
  virtual void addTransaction(const string &customerName, shared_ptr<Car> car, int days) = 0;
  virtual void displayTransactions() const = 0;
  virtual ~ITransactionManager() = default;
};

class TransactionManager : public ITransactionManager
{
private:
  vector<Transaction> transactions;

public:
  void addTransaction(const string &customerName, shared_ptr<Car> car, int days) override
  {
    transactions.emplace_back(customerName, car, days);
  }

  void displayTransactions() const override
  {
    for (const auto &transaction : transactions)
    {
      cout << "********** Start Display Transactions **********" << endl;
      cout << "Customer: " << transaction.customerName
           << ", Car: " << transaction.rentedCar->getName()
           << ", Duration: " << transaction.rentalDuration
           << " days, Total Cost: $" << transaction.totalCost << endl;
      cout << "********** End Display Transactions **********" << endl;
    }
  }
};

class IRentalSystem
{
public:
  virtual void addCar(shared_ptr<Car> car) = 0;
  virtual void addTransaction(const string &customerName, const string &carName, int days) = 0;
  virtual void displayTransactions() const = 0;
  virtual void saveCarsToFile(const string &filename) const = 0;
  virtual void loadCarsFromFile(const string &filename) = 0;
  virtual void searchCarByName(const string &name) const = 0;
  virtual void sortCarsByName() = 0;
  virtual void sortCarsByYear() = 0;
  virtual void displayCars() const = 0;
  virtual ~IRentalSystem() = default;
};

class RentalSystem : public IRentalSystem
{
private:
  shared_ptr<ICarRepository> carRepository;
  shared_ptr<ITransactionManager> transactionManager;

public:
  RentalSystem(shared_ptr<ICarRepository> carRepo, shared_ptr<ITransactionManager> transMgr)
      : carRepository(carRepo), transactionManager(transMgr) {}

  void addCar(shared_ptr<Car> car) override
  {
    carRepository->addCar(car);
  }

  void addTransaction(const string &customerName, const string &carName, int days) override
  {
    auto car = carRepository->findCarByName(carName);
    if (car)
    {
      transactionManager->addTransaction(customerName, car, days);
    }
    else
    {
      cout << "Car not available or not found." << endl;
    }
  }

  void displayTransactions() const override
  {
    transactionManager->displayTransactions();
  }

  void saveCarsToFile(const string &filename) const override
  {
    carRepository->saveCarsToFile(filename);
  }

  void loadCarsFromFile(const string &filename) override
  {
    carRepository->loadCarsFromFile(filename);
  }

  void searchCarByName(const string &name) const override
  {
    auto car = carRepository->findCarByName(name);
    if (car)
    {
      cout << "********** Start Display Car **********" << endl;
      cout << "Car Found: " << car->getName() << ", Year: "
           << car->getYear() << ", Daily Rate: $" << car->getDailyRate()
           << ", Available: " << (car->getAvailability() ? "Yes" : "No") << endl;
      cout << "********** End Display Car **********" << endl;
    }
    else
    {
      cout << "Car not found." << endl;
    }
  }

  void sortCarsByName() override
  {
    auto cars = carRepository->getCars();
    sort(cars.begin(), cars.end(), [](shared_ptr<Car> a, shared_ptr<Car> b)
         { return a->getName() < b->getName(); });
    displayCars(cars);
  }

  void sortCarsByYear() override
  {
    auto cars = carRepository->getCars();
    sort(cars.begin(), cars.end(), [](shared_ptr<Car> a, shared_ptr<Car> b)
         { return a->getYear() > b->getYear(); });
    displayCars(cars);
  }

  void displayCars(const vector<shared_ptr<Car>> &cars) const
  {
    for (const auto &car : cars)
    {
      cout << "********** Start Display Cars **********" << endl;
      cout << "Car: " << car->getName() << ", Year: " << car->getYear()
           << ", Daily Rate: $" << car->getDailyRate()
           << ", Available: " << (car->getAvailability() ? "Yes" : "No") << endl;
      cout << "********** End Display Cars **********" << endl;
    }
  }

  void displayCars() const override
  {
    displayCars(carRepository->getCars());
  }
};

void displayMenu()
{
  cout << "\n"
       << endl;
  cout << "********** Start Display Menu **********" << endl;
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
  cout << "********** End Display Menu **********" << endl;
  cout << "\n"
       << endl;
}
int main()
{
  auto carRepository = make_shared<CarRepository>();
  auto transactionManager = make_shared<TransactionManager>();
  auto rentalSystem = make_shared<RentalSystem>(carRepository, transactionManager);
  int choice;

  while (true)
  {
    displayMenu();
    cout << "Enter your choice of number: ";
    cin >> choice;

    if (choice == 0)
      break;

    switch (choice)
    {
    case 1:
    {
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
      rentalSystem->addCar(car);
      break;
    }
    case 2:
    {
      string customerName, carName;
      int days;
      cout << "Enter customer name: ";
      cin >> customerName;
      cout << "Enter car name: ";
      cin >> carName;
      cout << "Enter rental duration (days): ";
      cin >> days;
      rentalSystem->addTransaction(customerName, carName, days);
      break;
    }
    case 3:
    {
      rentalSystem->displayTransactions();
      break;
    }
    case 4:
    {
      string name;
      cout << "Enter car name: ";
      cin >> name;
      rentalSystem->searchCarByName(name);
      break;
    }
    case 5:
    {
      rentalSystem->sortCarsByName();
      break;
    }
    case 6:
    {
      rentalSystem->sortCarsByYear();
      break;
    }
    case 7:
    {
      rentalSystem->displayCars();
      break;
    }
    case 8:
    {
      string filename = "mobil.txt";
      rentalSystem->saveCarsToFile(filename);
      break;
    }
    case 9:
    {
      string filename = "mobil.txt";
      rentalSystem->loadCarsFromFile(filename);
      break;
    }
    default:
    {
      cout << "Invalid choice, please try again." << endl;
      break;
    }
    }
  }
  return 0;
}
