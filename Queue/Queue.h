#pragma once

/*
Author: Murilo Gabardo Kramar
Collaboration: Diego Vieira Feder
E-mail: murilogabardo@hotmail.com
CV: http://lattes.cnpq.br/8203093591818100

--->This is a Generic Template Queue based on a Generic Template Linked List

Acknowledgements:

 Professor Jean Marcelo Simao.

*/

#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

template<class QType>
class Queue
{
private:
	/*Agregated class where we are going to make our Queue*/
	List<QType> L1;

public:
	Queue(void);
	~Queue(void);

	/*Include a new elemente at the end of the Queue*/
	void include(QType pP);

	/*Call de first element on the Queue*/
	QType call();

	/*Get Queue Size*/
	int getSize() const;

#ifdef _IOSTREAM_
	void list() const;
#endif

};

template<class QType>
Queue<QType>::Queue(void)
{
}


template<class QType>
Queue<QType>::~Queue(void)
{
}

template<class QType>
int Queue<QType>::getSize() const
{
	return L1.getListSize();
}

template<class QType>
void Queue<QType>::include(QType pP)
{
	L1.includeBack(pP);
}

template<class QType>
QType Queue<QType>::call()
{
	return L1.remove(0);
}

template<class QType>
void Queue<QType>::list() const
{
	for(int i = 0; i < L1.getListSize(); i++)
	{
		cout<<L1[i]<<" - ";
	}
}
