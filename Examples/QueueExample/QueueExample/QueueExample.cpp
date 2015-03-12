// QueueExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Queue.h"

#include <iostream>

using std::cout;
using std::max;


int _tmain(int argc, _TCHAR* argv[])
{
	Queue<int> Q1;

	Q1.include(5);
	Q1.include(15);
	Q1.include(16);
	Q1.include(99);
	Q1.include(66);


	for(int i = 0; i < Q1.getSize(); i++)
	{
		cout<<"In the Queue: ";
		Q1.list();
		cout<<endl<<"Calling: "<<Q1.call()<<endl;
		cout<<"---------------------"<<endl;
	}

	system("pause");

	return 0;
}

