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
	virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory
{
public:
	Vehicle* createVehicle()
	{
		return new Car();
	}
};

class BikeFactory : public VehicleFactory
{
public:
	Vehicle* createVehicle()
	{
		return new Bike();
	}
};

class LorryFactory : public VehicleFactory
{
public:
	Vehicle* createVehicle()
	{
		return new Lorry();
	}
};

int main()
{
	//Abstract Factory which returns factory object
	VehicleFactory* factory = new LorryFactory();
	//vehiicle got created usign factory object
	Vehicle* vehicle = factory->createVehicle();
	vehicle->create();

	delete vehicle;
	delete factory;

	factory = new CarFactory();
	vehicle = factory->createVehicle();
	vehicle->create();

	delete vehicle;
	delete factory;

	//It is satisfying the "SOLID" principle 'O'-> Open for Extension and Closed for modification
}
