#include <exception>
#include "IteratorLP.h"
#include "Lista.h"

#include <iostream>

using  namespace std;
Lista::Lista() {//teta(1)
    //first = 0 deci lista goala, primLiber e indicile primului spatiu gol adica elemente[i]
    first = -1;
    primLiber = 0;
}



void Lista::aloca(Lista lista, int i)//teta(1)
{
    i = lista.primLiber;
    lista.primLiber = lista.urm.at(lista.primLiber);
}

void Lista::dealoca(Lista lista, int i)//teta(1)
{
    lista.urm.at(i) = lista.primLiber;
    lista.primLiber = i;
}

int Lista::dim() const {//teta(1)
    //dimensiunea listei de elemente
	return elemente.size();
}


bool Lista::vida() const {//teta(1)
	return first == -1;
}

IteratorLP Lista::prim() const {//teta(1)
    IteratorLP it = IteratorLP(*this);
    if(dim() == 0) it.curent = -1;
    it.curent = first;
    return it;
}

TElem Lista::element(IteratorLP poz) const {//teta(1)
    return poz.element();
}

TElem Lista::sterge(IteratorLP& poz) {//teta(n)
    if(dim() == 0) throw std::runtime_error("");
    if(dim() == 1 && (poz.element() == elemente.at(first))){
        TElem e = elemente.at(0);
        elemente.erase(0);
        primLiber = 0;
        first = -1;
        last = -1;
        return e;
    } else{
        TElem e = elemente.at(poz.curent);
        elemente.erase(poz.curent);
        int a = prec.at(poz.curent);
        int b = prec.at(poz.curent);
        prec.erase(poz.curent);
        urm.erase(poz.curent);
        if(a != -1)
            urm.at(a) = b;
        return e;
    }

}

IteratorLP Lista::cauta(TElem e) const{//teta(n)
	IteratorLP it = IteratorLP(*this);
    it.curent = -1; //daca nu gasim elementul iteratorul va fi -1
    if(dim() == 0) return it;
    int i = first;
    while((i != -1) && (elemente.at(i) != e)) i = urm.at(i); //cat timp i ul e valid si nu am gasit elementul trecem prin lista
    if((i != -1) && elemente.at(i) == e) // verificam ca am gasit elementul
        it.curent = i;
    return it;
}

TElem Lista::modifica(IteratorLP poz, TElem e) {//teta(1)
	if(dim() == 0 || (!poz.valid())) throw std::runtime_error("");
    TElem v = elemente.at(poz.curent);
    elemente.set(e, poz.curent);
    return v;
}

void Lista::adauga(IteratorLP& poz, TElem e) {//teta(n)
	if(!poz.valid()) throw std::exception("");
    int ok = 1;
    int i;
    for (i = 0; i < elemente.size(); i++)
        if (prec.at(i) == -1 && urm.at(i) == -1)
        {
            ok = 0;
            break;
        }
    if(ok == 0)
    {
        elemente.at(i) = elemente.at(poz.curent);
        prec.at(i) = poz.curent;
        elemente.at(poz.curent) = e;
        if (urm.at(poz.curent) == -1)
            urm.at(poz.curent)= i;
    }
    if(ok == 1)
    {
        elemente.push_back(elemente.at(poz.curent));
        prec.push_back(i);
        urm.push_back(-1);
        elemente.at(poz.curent) = e;
        if (urm.at(poz.curent) == -1)
            urm.at(poz.curent) = elemente.size()-1;
    }
}

void Lista::adaugaInceput(TElem e) {//teta(n)
    if (first == -1) {
        first = 0;
        last = 0;
        elemente.push_back(e);
        primLiber = 1;
    }
    else{
        for(int i = dim(); i >= 0; i ++)
            elemente.at(i) = elemente.at(i - 1);
        elemente.set(e, 0);
        last ++;
        primLiber++;
    }
}

void Lista::adaugaSfarsit(TElem e) {//teta(1)
    if (first== -1)
        first = 0;
    elemente.push_back(e);
    prec.push_back(elemente.size() - 2);
    urm.push_back(-1);
    if (elemente.size() > 1)
        urm.at(elemente.size() - 2) = elemente.size() - 1;
}

Lista::~Lista() {
	/* de adaugat */
}

void Lista::inverseazaIntre(IteratorLP i1, IteratorLP i2){ //O(n)
    if((!i1.valid()) || (!i2.valid())) throw std::exception("");
    while(i1.curent <= i2.curent){
        int aux = elemente.at(i1.curent);
        elemente.at(i1.curent) = elemente.at(i2.curent);
        elemente.at(i2.curent) = aux;
        i1.curent ++;
        i2.curent --;
    }
}

void Lista::print() {
    for(int i = 0; i < dim(); i ++)
        std::cout << elemente.at(i) << "  ";
}