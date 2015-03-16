#pragma once

#include "stdafx.h"
#include "Stack.h"

class Menux
{
private:
	string datum;
	double numericDatum;
	Stack<double> P1;
	Stack<double> P2;
	double Num1;
	double Num2;
	double Num3;

public:
	Menux(void);
	~Menux(void);

	void execute();
	bool isNumber(string number);
	void list();
};

