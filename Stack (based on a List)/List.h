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


template<class LType>
class List{

public:

    /*************************************************************************/

    //This is a Nested Class called Element
    //that is used to allow multiple lists to handle the
    //same item attached

    template<class EType>
    class Element {
    protected:
        //Pointer to the next element of the list
        Element<EType>* pNextElement;

        //Item that is attached to this element
        EType pAttached;

    public:
        Element()
        {
            pNextElement = NULL;
        }

        ~Element() {}

        //Get Next Element
        Element<EType>* getNextElement() const   {return pNextElement;}

        //Set Next Element
        void setNextElement(Element<EType>* pElement) {pNextElement = pElement;}

        //Attaches an Item to this Element
        void setAttached(EType pAtt) {pAttached = pAtt;}

        //Returns the attached Item in this Element
        EType getAttached() const {return pAttached;}
    };
    /**********************************************************************/

protected:

    /*First and Last Elents in the list*/
	Element<LType>* pFirstElement;
	Element<LType>* pLastElement;

    /*Auxiliary pointers to Elements*/
    Element<LType>* pBefore;
    Element<LType>* pActual;

    /*Auxiliary Item*/
    LType pAux;

    /*How long is this list?*/
	int listSize;

public:
	List()
	{
        pFirstElement = NULL;
        pLastElement = NULL;
        listSize = 0;
	}
	~List()
	{

	}

    /*Returns the size of the list*/
	const int getListSize() const
	{
	    return listSize;
	}

    /*Stores an Item in an Element and puts this Element
    in the first position of the List*/
	void includeFront(LType pIn)
	{
        Element<LType>* pAux = new Element<LType>;
        pAux->setAttached(pIn);
        if(pFirstElement == NULL)
        {
            pFirstElement = pAux;
            pLastElement = pAux;
        }
        else
        {
            pAux->setNextElement(pFirstElement);
            pFirstElement = pAux;
        }
        listSize++;
	}

    /*Stores an Item in an Element and puts this Element
    in the last position of the List*/
    void includeBack(LType pIn)
	{
        Element<LType>* pAux = new Element<LType>;
        pAux->setAttached(pIn);
        if(pFirstElement == NULL)
        {
            pFirstElement = pAux;
            pLastElement = pAux;
        }
        else
        {
            pLastElement->setNextElement(pAux);
            pLastElement = pAux;
        }
        listSize++;
	}

    /*Removes an Element from the List and returns the Item
    stored within it*/
    LType remove(int position)
	{
	    if(position > listSize-1)

        {
            return NULL;
        }

        int index;

        pBefore = NULL;

        pActual = pFirstElement;


        for(index = 0; index < position; index++)
        {
            pBefore = pActual;
            pActual = pActual->getNextElement();
        }

        if(position == 0)
        {
            pFirstElement = pFirstElement->getNextElement();
        }
        else if(position == listSize-1)
        {
            pLastElement = pBefore;
        }

        if(listSize > 1 && position != 0)
        {
            pBefore->setNextElement(pActual->getNextElement());
        }



        pAux = pActual->getAttached();
        delete pActual;

        listSize--;
        return pAux;
	}

	Element<LType>* getFirst() const
	{
	        return pFirstElement;
	}

	Element<LType>* getLast()
	{
	        return pLastElement;
	}

    /*Operator overload, so if you want a Item that's in the middle
    of the list you can acess it.
    IMPORTANT: this overloading doens't create a new position, it is read-only*/
    LType operator[] (const int elementIndex)
    {
        int index;
        Element<LType>* pAux = pFirstElement;
        for(index = 0; index < elementIndex; index++)
        {
            pAux = pAux->getNextElement();
        }
        return (pAux->getAttached());
    }

    /*Same as remove() but you search by Item Adress and doens't return it*/
    void exclude(LType* pIn)
    {
        int index;

        pBefore = NULL;

        pActual = pFirstElement;


        for(index = 0; pActual->getAttached() != pIn && index < listSize-1; index++)
        {
            pBefore = pActual;
            pActual = pActual->getNextElement();
        }

        if(index == 0)
        {
            pFirstElement = pFirstElement->getNextElement();
        }
        else if(index == listSize-1)
        {
            pLastElement = pBefore;
        }

        if(listSize > 1 && index != 0)
        {
            pBefore->setNextElement(pActual->getNextElement());
        }

        delete pActual;

        listSize--;
    }
};



