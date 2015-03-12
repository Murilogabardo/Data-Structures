#pragma once

template<class EType>
class Element {
protected:
    Element<EType>* pNextElement;
    EType pAttached;

public:
    Element(){pNextElement = NULL;}

    ~Element() {}

    Element<EType>* getNextElement() const   {return pNextElement;}

    void setNextElement(Element<EType>* pElement) {pNextElement = pElement;}

    void setAttached(EType pAtt) {pAttached = pAtt;}
    EType getAttached() const {return pAttached;}

};