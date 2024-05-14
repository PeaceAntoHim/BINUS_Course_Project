#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// Abstract base class
class Car
{
protected:
	string name;
	int year;
	double rentalPrice;
	bool isAvailable;

public:
	Car(string name, int year, double rentalPrice)
			: name(name), year(year), rentalPrice(rentalPrice), isAvailable(true) {}

	virtual double calculateRentalCost(int days) = 0;

	string getName() const { return name; }
	int getYear() const { return year; }
	double getRentalPrice() const { return rentalPrice; }
	bool getAvailability() const { return isAvailable; }

	void setAvailability(bool availability) { isAvailable = availability; }
};

class Sedan : public Car
{
public:
	Sedan(string name, int year, double rentalPrice) : Car(name, year, rentalPrice) {}

	double calculateRentalCost(int days) override
	{
		return days * rentalPrice;
	}
};

class SUV : public Car
{
public:
	SUV(string name, int year, double rentalPrice) : Car(name, year, rentalPrice) {}

	double calculateRentalCost(int days) override
	{
		return days * rentalPrice * 1.1; // Example additional cost factor for SUVs
	}
};

class Minivan : public Car
{
public:
	Minivan(string name, int year, double rentalPrice) : Car(name, year, rentalPrice) {}

	double calculateRentalCost(int days) override
	{
		return days * rentalPrice * 1.2; // Example additional cost factor for Minivans
	}
};

class Transaction
{
	string customerName;
	Car *rentedCar;
	int rentalDuration;
	double totalCost;

public:
	Transaction(string customerName, Car *rentedCar, int rentalDuration)
			: customerName(customerName), rentedCar(rentedCar), rentalDuration(rentalDuration)
	{
		totalCost = rentedCar->calculateRentalCost(rentalDuration);
		rentedCar->setAvailability(false);
	}

	void printTransaction() const
	{
		cout << "Customer: " << customerName << ", Car: " << rentedCar->getName() << ", Duration: " << rentalDuration
				 << " days, Total Cost: " << totalCost << endl;
	}
};

class TransactionManager
{
	vector<Transaction> transactions;

public:
	void addTransaction(const Transaction &transaction)
	{
		transactions.push_back(transaction);
	}

	void printAllTransactions() const
	{
		for (const auto &transaction : transactions)
		{
			transaction.printTransaction();
		}
	}
};

class CarManager
{
	vector<Car *> cars;

public:
	~CarManager()
	{
		for (auto car : cars)
		{
			delete car;
		}
	}

	void addCar(Car *car)
	{
		cars.push_back(car);
	}

	void listCars() const
	{
		for (const auto &car : cars)
		{
			cout << "Name: " << car->getName() << ", Year: " << car->getYear()
					 << ", Price per day: " << car->getRentalPrice() << ", Available: "
					 << (car->getAvailability() ? "Yes" : "No") << endl;
		}
	}

	Car *findCarByName(const string &name) const
	{
		for (const auto &car : cars)
		{
			if (car->getName() == name)
			{
				return car;
			}
		}
		return nullptr;
	}

	void sortCarsByName()
	{
		sort(cars.begin(), cars.end(), [](Car *a, Car *b)
				 { return a->getName() < b->getName(); });
	}

	void sortCarsByYear()
	{
		sort(cars.begin(), cars.end(), [](Car *a, Car *b)
				 { return a->getYear() > b->getYear(); });
	}

	void saveCarsToFile(const string &filename) const
	{
		ofstream file(filename);
		for (const auto &car : cars)
		{
			file << car->getName() << "," << car->getYear() << ","
					 << car->getRentalPrice() << "," << car->getAvailability() << endl;
		}
	}

	void loadCarsFromFile(const string &filename)
	{
		ifstream file(filename);
		string name;
		int year;
		double rentalPrice;
		bool isAvailable;

		while (file >> name >> year >> rentalPrice >> isAvailable)
		{
			Car *car;
			// Assume all cars are of type Sedan for simplicity
			car = new Sedan(name, year, rentalPrice);
			car->setAvailability(isAvailable);
			addCar(car);
		}
	}
};

int main()
{
	CarManager carManager;
	TransactionManager transactionManager;

	// Add cars to the system
	carManager.addCar(new Sedan("Sedan1", 2020, 100));
	carManager.addCar(new SUV("SUV1", 2019, 150));
	carManager.addCar(new Minivan("Minivan1", 2021, 200));

	// Create transactions
	Car *car = carManager.findCarByName("Sedan1");
	if (car && car->getAvailability())
	{
		Transaction transaction("John Doe", car, 5);
		transactionManager.addTransaction(transaction);
	}

	// Print all transactions
	transactionManager.printAllTransactions();

	// Save cars to file
	carManager.saveCarsToFile("cars.txt");

	return 0;
}
