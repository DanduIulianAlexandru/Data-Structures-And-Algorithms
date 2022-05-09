#include "Iterator.h"
#include "LO.h"
#include <iostream>

Iterator::Iterator(const LO& lo) : lista(lo){//O(1)
    index = 0;
}

void Iterator::prim() {//O(1)
    index = 0;
}

void Iterator::urmator(){//O(1)
    if(!valid())
        throw std::runtime_error("");
	index ++;
}

bool Iterator::valid() const{//O(1)
	return index < lista.d;
}

TElement Iterator::element() const{//O(1)
    if(!valid())
        std::runtime_error("");
    return lista.element(index);
}


