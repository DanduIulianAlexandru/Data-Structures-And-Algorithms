#include "TestScurt.h"

#include <assert.h>
#include <exception>
#include <iostream>

#include "Lista.h"
#include "IteratorLP.h"



using namespace std;

void testAll(){
	Lista lista = Lista();
	assert(lista.dim() == 0);
	assert(lista.vida());

    lista.adaugaSfarsit(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

    IteratorLP it = lista.cauta(1);
    assert(it.valid());
    assert(it.element() == 1);
    it.urmator();
    assert(!it.valid());
    it.prim();
    assert(it.valid());
    assert(it.element() == 1);

    assert(lista.sterge(it) == 1);
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaInceput(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());
    lista.sterge(it);

    lista.adaugaSfarsit(1);
    lista.adaugaSfarsit(2);
    lista.adaugaSfarsit(3);
    lista.adaugaSfarsit(4);
    lista.adaugaSfarsit(5);

    IteratorLP it2 = lista.cauta(1);
    IteratorLP it3 = lista.cauta(4);
    lista.inverseazaIntre(it2, it3);
    lista.print();
}

