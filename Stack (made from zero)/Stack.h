#pragma once

#include "Element.h"
#include "stdafx.h"

/*
Author: Murilo Gabardo Kramar
Collaboration: Diego Vieira Feder
E-mail: murilogabardo@hotmail.com
CV: http://lattes.cnpq.br/8203093591818100

--->This is a Generic Template Stack made from the grounds

Acknowledgements:

 Professor Jean Marcelo Simao.

*/

template <class SType>

class Stack
{
private:
	Element<SType>* pFirst;
	Element<SType>* pAux;
	int size;
public:
	Stack(void);
	~Stack(void);

	void include(SType pS);
	void exclude();
	SType unstack();

	int getSize() const;

	SType getFirst() const;
};

template <class SType>
Stack<SType>::Stack(void)
{
	pFirst = NULL;
	pAux = NULL;
	size = 0;
}

template <class SType>
Stack<SType>::~Stack(void)
{
	for(int i = size - 1 ; i >= 0; i--)
	{
		exclude();
	}
}

template <class SType>
void Stack<SType>::include(SType pS)
{

	if(!pFirst)
	{
		pFirst = new Element<SType>;
		pFirst->setAttached(pS);
	}
	else
	{
		pAux = pFirst;

		pFirst = new Element<SType>;
		pFirst->setAttached(pS);
		pFirst->setNextElement(pAux);
		pFirst->setPreviousElement(NULL);

		pAux->setPreviousElement(pFirst);
	}

	size++;
}

template <class SType>
void Stack<SType>::exclude()
{
	if(size > 0)
	{
		pAux = pFirst->getNextElement();
		if(pAux)
			pAux->setPreviousElement(NULL);
		delete pFirst;
		pFirst = pAux;
		size--;
	}
}


template <class SType>
int Stack<SType>::getSize() const
{
	return size;
}

template <class SType>
SType Stack<SType>::getFirst() const
{
	return pFirst->getAttached();
}


template <class SType>
SType Stack<SType>::unstack()
{
	if(size > 0)
	{
		SType pTemp = pFirst->getAttached();  
		exclude();
		return pTemp;
	}
	else
	{
		return NULL;
	}
}

