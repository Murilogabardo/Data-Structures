#pragma once

#include"List.h"

/*
Author: Murilo Gabardo Kramar
Collaboration: Diego Vieira Feder
E-mail: murilogabardo@hotmail.com
CV: http://lattes.cnpq.br/8203093591818100

--->This is a Generic Template Stack based on a Generic Template Simply Linked List

Acknowledgements:

 Professor Jean Marcelo Simao.

*/


template<class PType>
class Stack
{
private:
	/*Instance of a List which parameter is the generic type given on creation of the Stack*/
    List<PType> L1;

public:
	/*Allows include an object on top o the stack*/
    void includeTop(PType pIn)
    {
        L1.includeTop(pIn);
    }

	/*Allows include an object on bottom o the stack*/
    void includeBottom(PType pIn)
    {
        L1.includeBottom(pIn);
    }

	/*Removes the object on the Top of the Stack. Returns the object*/
    PType removeTop()
    {
        return L1.remove(0);
    }

	/*Removes the object on the Bottom of the Stack. Returns the object*/
    PType removeBottom()
    {
        return L1.remove(L1.getListSize()-1);
    }

	/*Returns the item stored on Top of the Stack*/
    PType getTop()
    {
        return L1[0];
    }

	/*Returns the item stored on Bottom of the Stack*/
    PType getBottom()
    {
        return L1[L1.getListSize()-1];
    }

	/*Returns the Stack number of items stored*/
    int getStackSize()
    {
        return L1.getListSize();
    }
};
