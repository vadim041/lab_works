#include "Set.h"
#include <iostream>
#include <conio.h>
using namespace std;
Set Build_set(Set ob1, Set ob2) {
	int coef = ob2.GetCardinality() + ob1.GetCardinality();
	for (int i = 0; i < ob1.GetCardinality(); i++) {
		for (int j = 0; j < ob2.GetCardinality(); j++) {
			if (ob2.GetOneElem(i) == ob1.GetOneElem(j))
			{
				coef -= 2;
				break;
			}
		}
	}
	Set UnionSet;
	UnionSet.GiveMemory(coef);
	int k = 0;
	for (int i = 0; i < ob1.GetCardinality(); i++) {
		bool l = true;
		for (int j = 0; j < ob2.GetCardinality(); j++) {
			if (ob1.GetOneElem(i) == ob2.GetOneElem(j))
			{
				l = false;
				break;
			}
		}
		if (l) {
			UnionSet.elems[k] = ob1.GetOneElem(i);
			k++;
		}
	}
	for (int i = 0; i < ob2.GetCardinality(); i++) {
		bool l = true;
		for (int j = 0; j < ob1.GetCardinality(); j++) {
			if (ob1.GetOneElem(j) == ob2.GetOneElem(i))
			{
				l = false;
				break;
			}
		}
		if (l) {
			UnionSet.elems[k] = ob2.GetOneElem(i);
			k++;
		}
	}
	return UnionSet;
	}
	
int main() {
	const int size_int_arr = 4;
	const int size_set_arr = 3;
	int mas[size_int_arr] = { 1,2,4,165 };
	int mas_2[size_int_arr] =  { 1, 2, 14, 186 };
	int mas_3[size_int_arr] = { 1, 3, 4, 169 };
	Set Example_set_1(size_int_arr,mas), Example_set_2(size_int_arr,mas_2), Example_set_3(size_int_arr, mas_3);
	Set Union_result = Example_set_2 + Example_set_1;
	Set Difference_result = Example_set_2 - Example_set_1;
	Set intersection_result = Example_set_2 * Example_set_1;
	Set arr[size_set_arr] = { Example_set_1, Example_set_2, Example_set_3 };

	for (int i = 0; i < size_set_arr - 1; i++) {
		for (int k = i + 1; k < size_set_arr; k++) {
			Set function_set = Build_set(arr[i], arr[k]);
			cout << "Result of building " << i << " and " << k << " sets:\n";
			for (int j = 0; j < function_set.GetCardinality(); j++) {
				cout << function_set.GetOneElem(j) << ' ';
			}
			cout << endl;
		}
	}
	cout << "Result of union of sets:\n";
	for (int i = 0; i < Union_result.GetCardinality(); i++) {
		cout << Union_result.GetOneElem(i)<<' ';
	}
	cout << endl;
	cout << "Result of difference of sets:\n";
	for (int i = 0; i < Difference_result.GetCardinality(); i++) {
		cout << Difference_result.GetOneElem(i) << ' ';
	}
	cout << endl;
	cout << "Result of intersection of sets:\n";
	for (int i = 0; i < intersection_result.GetCardinality(); i++) {
		cout << intersection_result.GetOneElem(i) << ' ';
	}
}