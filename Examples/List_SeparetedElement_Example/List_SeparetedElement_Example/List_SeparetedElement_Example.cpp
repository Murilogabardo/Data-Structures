// List_SeparetedElement_Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> L1;
	//5
	L1.includeBack(5);
	//15 5
	L1.includeFront(15);
	//15 5 10
	L1.includeBack(10);
	//15 5 10 1
	L1.includeBack(1);
	//15 5 10 1 85
	L1.includeBack(85);
	//10 15 5 10 1 85
	L1.includeFront(10);

	cout<<"List Size: "<<L1.getListSize()<<endl<<endl;

	cout<<"Foward List: ";

	//Front to Back
	for(int i=0; i < L1.getListSize(); i++)
	{
		cout<<L1[i]<<" ";
	}

	cout<<endl;

	cout<<"Reverse List: ";

	//Back to Front
	for(int i=L1.getListSize()-1; i >= 0; i--)
	{
		cout<<L1[i]<<" ";
	}

	cout<<endl;


	system("pause");

	return 0;
}

