#pragma once

/*
Author: Murilo Gabardo Kramar
Collaboration: Diego Vieira Feder
E-mail: murilogabardo@hotmail.com
CV: http://lattes.cnpq.br/8203093591818100

--->This is a Generic Template Element

Acknowledgements:

 Professor Jean Marcelo Simao.

*/

template<class EType>
class Element {
protected:
    Element<EType>* pNextElement;
	Element<EType>* pPreviousElement;
    EType pAttached;

public:
    Element(){pNextElement = NULL;}

    ~Element() {}

    Element<EType>* getNextElement() const   {return pNextElement;}
	Element<EType>* getPreviousElement() const   {return pPreviousElement;}

    void setNextElement(Element<EType>* pElement) {pNextElement = pElement;}
	void setPreviousElement(Element<EType>* pElement) {pPreviousElement = pElement;}

    void setAttached(EType pAtt) {pAttached = pAtt;}
    EType getAttached() const {return pAttached;}

};