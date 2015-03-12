// PQExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MultiPriorityQueue.h"


int _tmain(int argc, _TCHAR* argv[])
{
	MultiPriorityQueue<int> Q1(5);
	
	Q1.include(5,0);
	Q1.include(7,0);
	Q1.include(6,1);
	Q1.include(6,1);
	Q1.include(7,5);
	Q1.include(5,5);

	cout<<"Size of the MPQ: "<<Q1.getSize()<<endl<<endl;

	int size = Q1.getSize();

	for(int i = 0; i < size; i++)
	{
		Q1.list();
		cout<<"----------------------"<<endl;
		cout<<"Calling: "<<Q1.call()<<endl<<endl;
	}
	Q1.list();

	system("pause");

	return 0;
}

