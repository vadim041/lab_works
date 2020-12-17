#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
	List<int>* MyList = new List<int>;


	MyList->Head = NULL; 

	for (int i = 0; i < 10; i++) MyList->Add(i, MyList); 
	MyList->Show(MyList); 
	MyList->ClearList(MyList); 
	delete MyList->Head;
	delete MyList;
}