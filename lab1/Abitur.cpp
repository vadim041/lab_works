#include "Header.h"
#include <iostream>
using namespace std;
Abiturient::Abiturient() {
	cout << "Input name, surname and patronymic :"; cin >> n.name >> n.surname >> n.patronymic;
	cout << "Input street:"; cin >> adr.street;
	cout << "Input house number:"; cin >> adr.house_number;
	cout << "Input flat number:"; cin >> adr.flat_number;
	cout << "Input 5 marks:";
	for (int i = 0; i < 5; i++) {
		cin >> marks[i];
	}
}
int Abiturient::sum() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += marks[i];
	}
	return sum;
}
void Abiturient::show() {
	cout << "Name :" << n.name << ' ' << n.surname << ' ' << n.patronymic << endl;
	cout << "Adress :" << adr.street<< ' ' << adr.house_number << '-' << adr.flat_number << endl;
	cout << "Marks :";
	for (int i = 0; i < 5; i++) {
		cout << marks[i] << ' ';
	}
	cout <<endl<< "------------------------"<< endl;
}
bool Abiturient::BadMarksCheck() {
	for (int i = 0; i < 5; i++) {
		if (marks[i] <= 2)
			return true;
	}
	return false;
}