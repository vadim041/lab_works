#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct List
{
	T x;
	List* Next, * Head;
	void Add(T x, List*& MyList) {
		try {
			List* temp = new List;                             
			temp->x = x;                                       
			temp->Next = MyList->Head;                          
			MyList->Head = temp;
		}
		catch (bad_alloc & ba) {
			cerr << "bad_alloc caught: " << ba.what() << '\n';
		}
	};
	void Show(List* MyList) {
		try {
			if (MyList->Head == NULL)
				throw "Steck is empty!!\n";
			List* temp = MyList->Head;                          
			while (temp != NULL)                               
			{
				cout << temp->x << " ";                         
				temp = temp->Next;                           
			}
		}
		catch (const char* exception) 
		{
			cerr << "Error: " << exception << '\n';
		}
	};
	void ClearList(List* MyList) {
		try {
			if (MyList->Head == NULL)
				throw "Steck is empty!!\n";
			while (MyList->Head != NULL)                        
			{
				List* temp = MyList->Head->Next;                    
				delete MyList->Head;                               
				MyList->Head = temp;                               
			}
		}
		catch (const char* exception) 
		{
			cerr << "Error: " << exception << '\n';
		}
	};
};