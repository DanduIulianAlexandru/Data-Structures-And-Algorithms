#include "IteratorLP.h"
#include "Lista.h"
#include <exception>

IteratorLP::IteratorLP(const Lista& l):lista(l) {//teta(1)
	this->curent = l.first;
}

void IteratorLP::prim(){//teta(1)
	this->curent = lista.first;
}

void IteratorLP::urmator(){//teta(1)
	if(curent == -1)
        throw std::exception();
    curent = lista.urm.at(curent);
}

bool IteratorLP::valid() const{//teta(1)
	return curent != -1;
}

TElem IteratorLP::element() const{//teta(1)
    if(!valid()) throw std::exception();
    else
	    return lista.elemente.at(curent);
}


