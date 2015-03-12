#pragma once

/*
Author: Murilo Gabardo Kramar
Collaboration: Diego Vieira Feder
E-mail: murilogabardo@hotmail.com
CV: http://lattes.cnpq.br/8203093591818100

--->This is a Generic Template Simply Linked List

Acknowledgements:

 Professor Jean Marcelo Simao.

*/

#include "Queue.h"

template <class PQType>
class MultiPriorityQueue
{
private:
	List<Queue<PQType>*> QueueList;
public:
	MultiPriorityQueue();
	MultiPriorityQueue(unsigned int priorities);

	~MultiPriorityQueue(void);

	void include(PQType pQ, unsigned int priority);

	int getSize() const;
	int getNumberPriorities() const;
	int getNumberInPriority(unsigned int priority);

	PQType call();

#ifdef _IOSTREAM_
	void list();
#endif
};

template <class PQType>
MultiPriorityQueue<PQType>::MultiPriorityQueue()
{
	QueueList.includeBack(new Queue<PQType>);
	QueueList.includeBack(new Queue<PQType>);
}

template <class PQType>
MultiPriorityQueue<PQType>::MultiPriorityQueue(unsigned int priorities)
{
	for(int i = 0; i < priorities; i++)
	{
		QueueList.includeBack(new Queue<PQType>);
	}
}

template <class PQType>
MultiPriorityQueue<PQType>::~MultiPriorityQueue(void)
{
}


template <class PQType>
void MultiPriorityQueue<PQType>::include(PQType pQ, unsigned int priority)
{
	if(priority < QueueList.getListSize())
	{
		(QueueList[priority])->include(pQ);
	}
	else
	{
		(QueueList[QueueList.getListSize()-1])->include(pQ);
	}
	
}

#ifdef _IOSTREAM_
template <class PQType>
void MultiPriorityQueue<PQType>::list()
{
	for(int i = QueueList.getListSize() - 1; i >= 0; i--)
	{
		if(QueueList[i]->getSize()>0)
		{
			cout<<"Priority "<<i<<": ";
			QueueList[i]->list();
			cout<<endl<<endl;
		}
	}
}
#endif

template <class PQType>
PQType MultiPriorityQueue<PQType>::call()
{
	for(int i = QueueList.getListSize()-1; i>=0; i--)
	{
		if(QueueList[i]->getSize() > 0)
		{
			return QueueList[i]->call();
		}
	}
	return NULL;
}

template <class PQType>
int MultiPriorityQueue<PQType>::getNumberPriorities() const
{
	return QueueList.getListSize();
}

template <class PQType>
int MultiPriorityQueue<PQType>::getNumberInPriority(unsigned int priority)
{
	if(priority < QueueList.getListSize())
	{
		return QueueList[priority]->getSize();
	}
}

template <class PQType>
int MultiPriorityQueue<PQType>::getSize() const
{
	int size = 0;
	for(int i = 0; i<QueueList.getListSize();i++)
	{
		size += QueueList[i]->getSize();
	}
	return size;
}