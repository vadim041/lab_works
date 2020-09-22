#include "Header.h"
/* Вариант 2
Abiturient: Фамилия, Имя, Отчество, Адрес, Оценки. Создать
массив объектов. Вывести:
а) список абитуриентов, имеющих неудовлетворительные оценки;
б) список абитуриентов, сумма баллов у которых не меньше
заданной;
в) выбрать N абитуриентов, имеющих самую высокую сумму
баллов, и список абитуриентов, имеющих полупроходной балл.
*/
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
void BadMarks(Abiturient spis[], int n) {
	bool k = false;
	cout << "Students, who has bad marks :\n";
	for (int i = 0; i < n; i++) {
		if (spis[i].BadMarksCheck()) {
			k = true;
			spis[i].show();
		}
	}
	if (!k) {
		cout << "Bad students not found!";
	}
	cout << "==============================" << endl;
}
void SumEnter(Abiturient spis[], int n) {
	cout << "Enter min sum of marks\n";
	int sum;
	cin >> sum;
	cout << "Students, who has sum of marks higher than min :\n";
	bool k = false;
	for (int i = 0; i < n; i++) {
		if (spis[i].sum() >= sum) {
			k = true;
			spis[i].show();
		}
	}
	if (!k) {
		cout << "Students not found!";
	}
	cout <<endl<< "==============================" << endl;
	cout << "Students, who has half-pass score :\n";
	k = false;
	for (int i = 0; i < n; i++) {
		if (spis[i].sum() == sum) {
			k = true;
			spis[i].show();
		}
	}
	if (!k) {
		cout << "Students not found!";
	}
	cout <<endl<< "==============================" << endl;
}
void HighestSum(Abiturient spis[], int n) {
	cout << "Enter amount of the best students you need\n";
	int N;
	cin >> N;
	int* mas = new int[n];
	for (int i = 0; i < n; i++) {
		mas[i] = spis[i].sum();
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (mas[j] < mas[j + 1]) {
				swap(mas[j], mas[j + 1]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < n; j++) {
			if (mas[i] == spis[j].sum())
			{
				spis[j].show();
				break;
			}
		}
	}
    
	
}
int main() {
	Abiturient* spis;
	int n;
	cout << "Enter number of abiturients :\n"; cin >> n;
	spis = new Abiturient[n];
	/*for (int i = 0; i < n; i++) {
		cout<<"=============================="<< endl;
		spis[i].show();
	}*/
	BadMarks(spis, n);
	SumEnter(spis, n);
	HighestSum(spis, n);
	delete[] spis;
	cout<<"press any key!";
	while (!_kbhit());
	return 0;
}