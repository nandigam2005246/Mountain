#include <iostream>
using namespace std;

class Vehicle
{
public:
	virtual void create() = 0;
};
class Car : public Vehicle
{
public:
	void create() override
	{
		cout << "Created Car" << endl;
	}

};

class Bike : public Vehicle
{
public:
	void create() override
	{
		cout << "Created Bike" << endl;
	}
};

class Lorry : public Vehicle
{
public:
	void create() override
	{
		cout << "Created Lorry" << endl;
	}
};

class VehicleFactory
{
public:
	static Vehicle* createVehicle(int vehicleType)
	{
		Vehicle* v = nullptr;
		switch (vehicleType)
		{
			case 1:
			{
				v = new Car();
				break;
			}
			case 2:
			{
				v = new Bike();
				break;
			}
			case 3:
			{
				v = new Lorry();
				break;
			}
			default:
				v = nullptr;
				break;
		}
		return v;
	}
};

int main()
{
	cout << "Choose the type of vehicle: " << endl;
	cout << "1. Car" << endl;
	cout << "2. Bike" << endl;
	cout << "3. Lorry" << endl;
	int vehicleType;
	cin >> vehicleType;
	Vehicle* v1 = VehicleFactory::createVehicle(vehicleType);
	if (v1 != nullptr)
	{
		v1->create();
	}
	else
	{
		cout << "Invalid Input" << endl;
	}
}
