#include <iostream>
using namespace std;
//Грузоперевозчик : Самолет, поезд, автомобиль. Время и стоимость перевозки для указанных городов и расстояний
class Transporter {
	int speed;
	int PricePerKm;
public:
	int GetSpeed() { return speed; };
	int GetPriceKm() { return PricePerKm; };
	void SetSpeed(int speed) { this->speed = speed; }
	void SetPriceKm(int price) { PricePerKm = price; }
	friend ostream& operator<<(ostream& mystream, const Transporter& ob);
	friend istream& operator>>(istream& mystream, Transporter &ob);
	Transporter(int speed, int PricePerKm);
	
};
class Plane:public Transporter {
	int speed_plane, price;
public:
	Plane() :Transporter(speed_plane = 1000, price = 80) {};
};
class Train :public Transporter {

	int speed_train, price;
public:
	Train() :Transporter(speed_train = 800, price = 50) {};
};
class Car :public Transporter {
	int speed_car,price;
public:
	Car() :Transporter(speed_car = 100, price = 30) {};
};