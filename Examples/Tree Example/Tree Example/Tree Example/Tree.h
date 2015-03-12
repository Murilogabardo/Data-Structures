#pragma once
/*
Author: Murilo Gabardo Kramar
Collaboration: Diego Vieira Feder
E-mail: murilogabardo@hotmail.com
CV: http://lattes.cnpq.br/8203093591818100

--->This is a Generic Template Tree
--->Notice that the operators of comparison MUST be defined for the Class used as parameter of the template
--->By definition numeric types have already this implemented, so just use it!

Acknowledgements:

 Professor Jean Marcelo Simao.

*/

#include "Node.h"
#include "stdafx.h"

template <class TType>

class Tree
{
private:
	/*This is the root (Node without parents) of the tree*/
	Node<TType>* root;

	/*Auxiliar Pointers to Nodes*/
	Node<TType>* pAux;
	Node<TType>* pAux2;
	Node<TType>* pAux3;

/*-----These functions are used only by the Tree class and its inherited classes----*/
	
	/*Adds a new element to the Tree*/
	Node<TType>* add(TType cValue, Node<TType>* pNo);

	/*Calculates the height of the specific node*/
	int height(Node<TType>* pNo);

	/*Balance the Tree*/
	Node<TType>* balance(Node<TType>* pNo);

	/*Search for a specific node*/
	Node<TType>* search(const TType cValue, Node<TType>* pNo) const;
	Node<TType>* search(const TType cValue) const;

	/*Returns the root of the Tree*/
	Node<TType>* getRoot() const;

	/*Count the number of members above the sub-tree*/
	int countUntil(const TType cValue, Node<TType>* pNo) const;
	
	/*Count the number of members of the sub-tree*/
	int elementsCount(Node<TType>* pNo);

	/*Weighs the nodes and set the weigh to the corresponding variable*/
	int weigh(Node<TType>* pNo);

	/*Possible rotations*/
	Node<TType>* leftRotation(Node<TType>* pNo);
	Node<TType>* rightRotation(Node<TType>* pNo);
	Node<TType>* doubleRightRotation(Node<TType>* pNo);
	Node<TType>* doubleLeftRotation(Node<TType>* pNo);

#ifdef _IOSTREAM_
	/*If Iostream is defined print to the console the Tree structure*/
	void print(Node<TType>* pNo);
#endif


public:
	Tree(void);
	~Tree(void);
	
/*--------Functions public acessed. This is a mean to create a interface from external classes to the tree-------*/

	/*Adds a new element to the Tree*/
	void add(TType  cValue);

	/*Counts the number of members on the Tree*/
	int elementsCount();

	/*Count the number of elements to the left of a specific Value*/
	int countLeftElements(TType  cValue);

	/*Conunt the number of elements that are less than the cValue*/
	int countLessThan(TType  cValue);

	/*Weighs the Tree (sets the weight variable with its value in each node)*/
	void weigh();

#ifdef _IOSTREAM_
	void print();
#endif _IOSTREAM_

};

template <class TType> inline
Tree<TType>::Tree(void)
{
	root = NULL;
}

template <class TType> inline
Tree<TType>::~Tree(void)
{

}

template <class TType> inline
Node<TType>* Tree<TType>::getRoot() const
{
	return root;
}

template <class TType>
void Tree<TType>::add(const TType cValue)
{
	if(root == NULL)
	{
		root = new Node<TType>(cValue);
	}
	else
	{
		add(cValue, root);
	}
}

template <class TType>
Node<TType>* Tree<TType>::add(const TType cValue, Node<TType>* pNo)
{
	if(cValue < pNo->getValue())
	{
		if(pNo->getLeft())
		{
			pAux3 = add(cValue, pNo->getLeft());
			if(pAux3)
			{
				pNo->setEsquerda(pAux3);
			}
			height(pNo);
			pAux3 = balance(pNo);
		}
		else
		{
			pNo->setEsquerda(new Node<TType>(cValue));
			return NULL;
		}
	}
	else
	{
		if(pNo->getRight())
		{
			pAux3 = add(cValue, pNo->getRight());
			if(pAux3)
			{
				pNo->setDireita(pAux3);
			}
			height(pNo);
			pAux3 = balance(pNo);
		}
		else
		{
			pNo->setDireita(new Node<TType>(cValue));
			return NULL;
		}
	}

	return pAux3;
}

template <class TType>
void Tree<TType>::print()
{
	height(root);
	if(root)
	{
		print(root);
	}
	else
	{
		cout<<endl<<"There is no elements on this tree"<<endl;
	}
}

template <class TType>
void Tree<TType>::print(Node<TType>* pNo)
{
	if(pNo != NULL)
	{
		print(pNo->getLeft());
		cout<<pNo->getValue()<<" - ";
		cout<<height(pNo)<<" ";
		cout<<" - "<<pNo->getWeight()<<endl;
		print(pNo->getRight());
	}

}

template <class TType>
int Tree<TType>::height(Node<TType>* pNo)
{
	if(pNo)
	{
		int alturaesquerda = height(pNo->getLeft()) ;
		int alturadireita = height(pNo->getRight());
		pNo->setHeight(max(alturaesquerda,alturadireita)+ 1);
		pNo->setWeight(alturadireita - alturaesquerda);
		return pNo->getHeight();
	}
	else
	{
		return 0;
	}
}

template <class TType>
Node<TType>* Tree<TType>::balance(Node<TType>* pNo)
{
	if(pNo)
	{
		if(pNo->getWeight() == 2)
		{
			if(pNo->getRight()->getWeight()  == -1)
			{
				pNo->setDireita(rightRotation(pNo->getRight()));
				return leftRotation(pNo);
			}
			else
			{
				return leftRotation(pNo);
			}
		}
		else if(pNo->getWeight() == -2)
		{
			if(pNo->getLeft()->getWeight()  == 1)
			{
				pNo->setEsquerda(leftRotation(pNo->getLeft()));
				return rightRotation(pNo);
			}
			else
			{
				return rightRotation(pNo);
			}

		}
	}

	return pNo;
}

template <class TType>
Node<TType>* Tree<TType>::leftRotation(Node<TType>* pNo)
{

	pAux = pNo;  //Stores the old root
	pAux2 = pNo->getRight()->getLeft(); //Stores the left element of the new root

	pNo = pNo->getRight(); //The new root is now the right node of the old one
	pAux->setDireita(pAux2);
	pNo->setEsquerda(pAux); //The new root takes as its left node the old root

	if(pAux == root)
	{
		root = pNo;
	}
	else if(pAux == root->getLeft())
	{
		root->setEsquerda(pNo);
	}
	else if(pAux == root->getRight())
	{
		root->setDireita(pNo);
	}

	pNo->setWeight(0);
	pAux->setWeight(0);

	return pNo;
}

template <class TType>
Node<TType>* Tree<TType>::rightRotation(Node<TType>* pNo)
{
	pAux = pNo;  //Stores the old root
	pAux2 = pNo->getLeft()->getRight(); //Stores the left node of the old root

	//Verifies cases where there is a change on the root or its direct sons
	pNo = pNo->getLeft(); //The new root is now the left node of the old one
	pAux->setEsquerda(pAux2);
	pNo->setDireita(pAux); //The new root takes as its left node the old root

	if(pAux == root)
	{
		root = pNo;
	}
	else if(pAux == root->getLeft())
	{
		root->setEsquerda(pNo);
	}
	else if(pAux == root->getRight())
	{
		root->setDireita(pNo);
	}

	pNo->setWeight(0); //Regulates weights
	pAux->setWeight(0);

	return pNo;
}

template <class TType>
Node<TType>* Tree<TType>::doubleRightRotation(Node<TType>* pNo)
{
	pAux = pNo; //Stores the old root
	pAux2 = pNo->getLeft(); //Stores the element of the left of the old root
	pNo = pAux2->getRight(); //The new root is the son of the right node of left node of the old root
	pAux2->setDireita(pNo->getLeft());  //Takes the left son of the new root adota filho esquerdo do novo root
    pAux2->setEsquerda(pNo->getRight());   //Takes the right son of the new root
	pNo->setEsquerda(pAux2);
    (pNo)->setDireita(pAux);

	if(pAux == root)
	{
		root = pNo;
	}
	else if (pAux == root->getLeft())
	{
		root->setEsquerda(pNo);
	}
	else if (pAux == root->getRight())
	{
		root->setDireita(pNo);
	}


	if (pNo->getWeight() == -1)
	{
	  pAux2->setWeight(0);
	  pAux->setWeight(+1);
	}
	else if (pNo->getWeight() == 0)
	{
		pAux2->setWeight(0);
		pAux->setWeight(0);
	}
	else
	{
		pAux2->setWeight(-1);
		pAux->setWeight(0);
	}
	pNo->setWeight(0);

	return pNo;
}

template <class TType>

Node<TType>* Tree<TType>::doubleLeftRotation(Node<TType>* pNo)
{
	pAux = pNo; //Stores the old root
	pAux2 = pNo->getRight(); //Stores the Right Node of the old root

	if(pAux == root)
	{
		root = pNo;
	}
	else if (pAux == root->getLeft())
	{
		root->setEsquerda(pNo);
	}
	else if (pAux == root->getRight())
	{
		root->setDireita(pNo);
	}

	pNo = pAux2->getLeft(); //The new root is the left son of the left node
	pAux2->setEsquerda(pNo->getRight());  //Takes the left son of the new root
    pAux2->setDireita(pNo->getLeft());   //Takes the right son of the new root
	pNo->setDireita(pAux2);
    (pNo)->setEsquerda(pAux);


	if (pNo->getWeight() == -1)
	{
	  pAux2->setWeight(0);
	  pAux->setWeight(+1);
	}
	else if (pNo->getWeight() == 0)
	{
		pAux2->setWeight(0);
		pAux->setWeight(0);
	}
	else
	{
		pAux2->setWeight(-1);
		pAux->setWeight(0);
	}
	pNo->setWeight(0);

	return pNo;
}

template <class TType>
Node<TType>* Tree<TType>::search(const TType cValue) const
{
	if(root->getValue() == cValue)
	{
		return root;
	}
	else if(cValue < root->getValue())
	{
		return search(cValue, root->getLeft());
	}
	else if(cValue > root->getValue())
	{
		return search(cValue, root->getRight());
	}
}

template <class TType>
Node<TType>* Tree<TType>::search(const TType cValue, Node<TType>* pNo) const
{
	if(pNo)
	{
		if(pNo->getValue() == cValue)
		{
			return pNo;
		}
		else if(cValue < pNo->getValue())
		{
			return search(cValue, pNo->getLeft());
		}
		else if(cValue > pNo->getValue())
		{
			return search(cValue, pNo->getRight());
		}
	}
}

template <class TType>
int Tree<TType>::elementsCount()
{
	if(root)
	{
		return (elementsCount(root->getRight()) + elementsCount(root->getLeft()))+1;
	}
	else
	{
		return 0;
	}
}

template <class TType>
int Tree<TType>::elementsCount(Node<TType>* pNo)
{
	if(pNo)
	{
		return (elementsCount(pNo->getRight()) + elementsCount(pNo->getLeft())+1);
	}
	else
	{
		return 0;
	}
}

template <class TType>
int Tree<TType>::countLeftElements(const TType cValue)
{
	if(pAux = search(cValue))
	{
		return elementsCount(pAux->getLeft());
	}
	else
	{
		return 0;
	}
}

template <class TType>
int Tree<TType>::countUntil(const TType cValue, Node<TType>* pNo) const
{
	if(pNo)
	{
		if(pNo->getValue() != cValue)
		{
			return countUntil(cValue,pNo->getLeft()) + countUntil(cValue,pNo->getRight()) + 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

template <class TType>
int Tree<TType>::countLessThan(const TType cValue)
{
	return countUntil(cValue, root);
}

template <class TType>
void Tree<TType>::weigh()
{
	weigh(root);
}

template <class TType>
int Tree<TType>::weigh(Node<TType>* pNo)
{
	int esq, dir;
	if(pNo)
	{
		pNo->setLeftMembers(esq = weigh(pNo->getLeft()));
		pNo->setRightMembers(dir = weigh(pNo->getRight()));
		return esq + dir + 1;
	}
	else
	{
		return 0;
	}
}

