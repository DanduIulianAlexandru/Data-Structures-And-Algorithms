#include <assert.h>
#include "iostream"

#include "Iterator.h"
#include "LO.h"

using namespace std;

using std::cout;

bool relatie1(TElement cheie1, TElement cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

bool conditie(TElement t1){
    if(t1 % 2 != 0)
        return true;
    return false;
}

void test_filter(){
    LO lo = LO(relatie1);
    lo.adauga(1);
    lo.adauga(4);
    lo.adauga(2);
    lo.adauga(3);
    lo.adauga(5);
    lo.adauga(6);
    lo.filtreaza(conditie);
    assert(lo.dim() == 3);
    assert(lo.element(0) == 1);
    assert(lo.element(1) == 3);
    assert(lo.element(2) == 5);
}


void testAll(){
	LO lo = LO(relatie1);
	assert(lo.dim() == 0);
	assert(lo.vida());
    lo.adauga(1);
    assert(lo.dim() == 1);
    assert(!lo.vida());
    Iterator iterator = lo.iterator();
    assert(iterator.valid());
    iterator.prim();
    assert(iterator.element() == 1);
    iterator.urmator();
    assert(!iterator.valid());
    iterator.prim();
    assert(iterator.valid());
    assert(lo.cauta(1) == 0);
    assert(lo.sterge(0) == 1);
    assert(lo.dim() == 0);
    assert(lo.vida());

}

