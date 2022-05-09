#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {//O(1)
	curent = 0;
}

TElem IteratorColectie::element() const{//O(1)
	return col.e[curent];
}

bool IteratorColectie::valid() const {//O(1)
	if(curent < col.dim())
        return true;
	return false;
}

void IteratorColectie::urmator() {//O(1)
	curent ++;
}

void IteratorColectie::prim() {//O(1)
	curent = 0;
}
