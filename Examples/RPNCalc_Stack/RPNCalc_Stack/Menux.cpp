#include "stdafx.h"
#include "Menux.h"

Menux::Menux(void)
{
}


Menux::~Menux(void)
{
}


bool Menux::isNumber(string number)
{
	int i;
	char c;

	for(i = 0; i < number.size(); i++)
	{	
		c = number[i];

		if(  !(((0x39 >= c) && (c >= 0x30)||c == 0x2E)  || (((c == 0x2D || c == 0x2B)&&(i==0)&&number.size() >= 2))) )
		{
			return false;
		}
	}

	return true;
}

void Menux::list()
{
	for(int size = P1.getSize() - 1; size >= 0; size--)
	{
		P2.include(P1.unstack());
	}

	for(int size = P2.getSize() - 1; size >= 0; size--)
	{
		cout<<P2.getFirst()<<endl;
		P1.include(P2.unstack());
	}
}

void Menux::execute(void)
{
	cout<<"Write the instructions or write exit: "<<endl;

	do
	{
		fflush(stdin);
	
		cin>>datum;

		if((datum == "+" || datum == "-" || datum == "*" || datum == "/")&&P1.getSize() >= 2)
		{
			Num1 = P1.unstack();
			Num2 = P1.unstack();

			if(datum == "+")
			{
				Num3 = Num2 + Num1;
			}
			else if (datum == "-")
			{
				Num3 = Num2 - Num1;
			}
			else if (datum == "*")
			{
				Num3 = Num2 * Num1;
			}
			else if (datum == "/")
			{
				if(!(-1*std::numeric_limits<double>::min()< Num1 && Num1 < std::numeric_limits<double>::min()))
				{
					Num3 = Num2 / Num1;
				}
				else
				{
					cout<<"Divison per zero is not allowed friend"<<endl<<endl;
					system("pause");
					Num3 = Num2;
				}
			}
			P1.include(Num3);
		}
		else if(isNumber(datum))
		{
			P1.include(std::stof(datum));
		}

		system("cls");
		cout<<"Write the instructions or write exit: "<<endl;
		list();
	}while(datum != "exit");

}
