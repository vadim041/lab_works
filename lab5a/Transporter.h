//Грузоперевозчик : Самолет, поезд, автомобиль. Время и стоимость перевозки для указанных городов и расстояний
class Transporter {
	int speed;
	int PricePerKm;
public:
	int GetSpeed() { return speed; };
	int GetPriceKm() { return PricePerKm; };
	void SetSpeed(int speed) { this->speed = speed; }
	void SetPriceKm(int price) { PricePerKm = price; }
	Transporter(int speed, int PricePerKm) {
		this->speed = speed;
		this->PricePerKm = PricePerKm;
	};
};
class Plane:public Transporter {
	int speed, price;
public:
	Plane() :Transporter(speed = 500, price = 100) {};
};
class Train :public Transporter {

	int speed, price;
public:
	Train() :Transporter(speed = 100, price = 50) {};
};
class Car :public Transporter {
	int speed,price;
public:
	Car() :Transporter(speed = 50, price = 10) {};
};