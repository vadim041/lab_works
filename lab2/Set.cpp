#include "Set.h"
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
int min(int n, int m) { return (n < m) ? n : m; }
int max(int n, int m) { return (n > m) ? n : m; }
Set::Set() { 
	srand(time(NULL));
	n = rand() % 7 + 1;
	elems = new int[n];
	if (!elems) {
		cout << "Error";
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		elems[i] = rand() % 200 - 100;
	}
}
Set::Set(int k) {
	n = k;
	srand(time(NULL));
	elems = new int[n];
	if (!elems) {
		cout << "Error";
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		elems[i] = rand() % 200 - 100;
	}
}
Set::Set(int k, int mas[]) {
	n = k;
	elems = new int[n];
	if (!elems) {
		cout << "Error";
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		elems[i] = mas[i];
	}
}
Set::Set(const Set& ob) {
	n = ob.n;
	elems = new int[n];
	if (!elems) {
		cout << "Error";
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		elems[i] = ob.elems[i];
	}
}
void Set::CheckElement(int k) {
	bool a = false;
	for (int i = n; i >= 0; i--) {
		if (k == elems[i]) {
			cout << "Element is here!\n";
			a = true;
			break;
		}
	}
	if (!a) {
		cout << "Element is not here!\n";
	}
}
void Set::GiveMemory(int k) {
	n = k;
	if (elems) {
		delete[]elems;
	}
	elems = new int[n];
}
Set Set::operator+(Set ob) {
	int coef = n + ob.GetCardinality();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ob.GetCardinality(); j++) {
			if (elems[i] == ob.GetOneElem(j))
				coef--;
		}
	}
	Set UnionSet;
	UnionSet.GiveMemory(coef);
	for (int i = 0; i < n; i++) {
		UnionSet.elems[i] = elems[i];
	}
	int AmountRepeat = 0;
	for (int i = 0; i < ob.GetCardinality(); i++) {
		bool k = true;
		for (int j = 0; j < n; j++) {
			if (ob.GetOneElem(i) == elems[j]) {
				k = false;
				AmountRepeat++;
				break;
			}

		}
		if (k)
			UnionSet.elems[i + n - AmountRepeat] = ob.GetOneElem(i);
	}
	return UnionSet;
}
Set Set::operator*(Set ob) {
	int coef = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ob.GetCardinality(); j++) {
			if (elems[i] == ob.GetOneElem(j))
			{
				coef++;
				break;
			}
		}
	}
	Set UnionSet;
	UnionSet.GiveMemory(coef);
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ob.GetCardinality(); j++) {
			if (elems[i] == ob.GetOneElem(j))
			{
				UnionSet.elems[k] = elems[i];
				k++;
			}
		}
	}
	return UnionSet;
}
Set Set::operator-(Set ob) {
	int coef = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < ob.GetCardinality(); j++) {
			if (elems[i] == ob.GetOneElem(j))
			{
				coef--;
				break;
			}
		}
	}
	Set UnionSet;
	UnionSet.GiveMemory(coef);
	int k = 0;
	for (int i = 0; i < n; i++) {
		bool l = true;
		for (int j = 0; j < ob.GetCardinality(); j++) {
			if (elems[i] == ob.GetOneElem(j))
			{
				l = false;
				break;
			}
		}
		if (l) {
				UnionSet.elems[k] = elems[i];
				k++;
			}
	}
	return UnionSet;
}
