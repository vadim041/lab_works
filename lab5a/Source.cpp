#include "Transporter.h"
#include <iostream>
using namespace std;
int FindTime(Transporter a, int distance) {
	return (distance / a.GetSpeed()) * 60;
};
int FindPrice(Transporter a, int distance) {
	return distance * a.GetPriceKm();
}
int main() {
	const int N = 3;
	int distance = 500;
	Plane plane;
	Car car;
	car.SetSpeed(60);
	Train train;
	Transporter arr[N] = { train, car,plane };
	for (int i = 0; i < N; i++) {
		cout <<"Price per kilometr "<< arr[i].GetPriceKm()<<' '<< "Speed "<<arr[i].GetSpeed()<<endl;
	}
	cout << "Price for car " << FindPrice(car, distance) << endl;
	cout << "Time for train " << FindTime(train, distance);
}