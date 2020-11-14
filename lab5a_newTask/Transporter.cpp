#include "Transporter.h"
#include <iostream>
using namespace std;
Transporter::Transporter(int speed, int PricePerKm) {
	this->speed = speed;
	this->PricePerKm = PricePerKm;
};
ostream& operator<<(ostream& mystream, const Transporter& ob) {
	mystream << "Speed is: "; mystream << ob.speed; mystream << endl;
	mystream << "Price is: "; mystream << ob.PricePerKm; mystream << endl;
	return mystream;
}
istream& operator>>(istream& mystream, Transporter& ob) {
	cout << "Enter speed : \n";
	int spd;
	mystream >> spd;
	ob.SetSpeed(spd);
	cout << "Enter price per kilometr: \n";
	int prc;
	mystream >> prc;
	ob.SetPriceKm(prc);
	return mystream;
}