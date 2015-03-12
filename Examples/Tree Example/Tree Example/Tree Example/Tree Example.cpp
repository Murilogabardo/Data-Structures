// ThreeExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Tree<int> Test;

	Test.add(5);
	
	Test.add(15);
	Test.add(95);
	Test.add(35);
	Test.add(45);
	Test.add(75);
	Test.add(10);
	Test.add(9);
	Test.add(11);
	Test.add(11);
	Test.add(12);
	Test.add(7);
	Test.add(95);
	Test.add(15);
	Test.add(5);

	Test.print();

	system("pause");

	return 0;
}

