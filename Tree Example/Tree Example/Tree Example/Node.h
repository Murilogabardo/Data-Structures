#pragma once

#include "stdafx.h"
#include "Element.h"

template <class NType>

class Node
{
private:
	Element<NType> value;
	int weight;
	int height;

	Node<NType>* right;
	Node<NType>* left;

	int leftMembers;
	int rightMembers;

public:
	Node(const NType cValue = 0.0, const int cPeso = 0);
	~Node(void);

	void setDireita(Node* pDir);
	void setEsquerda(Node* pEsq);

	Node<NType>* getRight() const;
	Node<NType>* getLeft() const;

	NType getValue() const;
	int getHeight() const;
	int getWeight() const;
	int getLeftMembers() const;
	int getRightMembers() const;

	void setValue(const NType N);
	void setHeight(const int N);
	

	void increaseWeight();
	void decreaseWeight();

	void setWeight(const int N);

	void setLeftMembers(const int N);
	void setRightMembers(const int N);



};


template <class NType>
Node<NType>::Node(const NType cValue, const int cPeso)
{
	value.setAttached(cValue);
	height = cPeso;
	weight = 0;
	right = NULL;
	left = NULL;
	rightMembers = 0;
	leftMembers = 0;
}

template <class NType>

Node<NType>::~Node(void)
{

}

template <class NType>

void Node<NType>::setDireita(Node<NType>* pDir)
{
	right = pDir;
}

template <class NType>
void Node<NType>::setEsquerda(Node<NType>* pEsq)
{
	left = pEsq;
}

template <class NType>

Node<NType>* Node<NType>::getRight() const
{
	return right;
}

template <class NType>
Node<NType>* Node<NType>::getLeft() const
{
	return left;
}

template <class NType>
NType Node<NType>::getValue() const
{
	return value.getAttached();
}

template <class NType>
int Node<NType>::getHeight() const
{
	return height;
}

template <class NType>
void Node<NType>::setValue(const NType N)
{
	value = N;
}

template <class NType>
void Node<NType>::setHeight(const int N)
{
	height = N;
}

template <class NType>
void Node<NType>::increaseWeight()
{
	weight++;
}

template <class NType>
void Node<NType>::decreaseWeight()
{
	weight--;
}

template <class NType>
int Node<NType>::getWeight() const
{
	return weight;
}

template <class NType>
void Node<NType>::setWeight(const int N)
{
	weight = N;
}

template <class NType>
void Node<NType>::setLeftMembers(const int N)
{
	leftMembers = N;
}

template <class NType>
void Node<NType>::setRightMembers(const int N)
{
	rightMembers = N;
}

template <class NType>
int Node<NType>::getLeftMembers() const
{
	return leftMembers;
}

template <class NType>
int Node<NType>::getRightMembers() const
{
	return rightMembers;
}

