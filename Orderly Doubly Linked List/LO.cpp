#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

LO::LO(Relatie r) { //teta(1)
    first = nullptr;
    last = nullptr;
    d = 0;
    this->r = r;
}

// returnare dimensiune
int LO::dim() const {//teta(1)
	return d;
}

// verifica daca LO e vida
bool LO::vida() const {//teta(1)
	return d == 0;
}

// returnare element
//arunca exceptie daca i nu e valid
TElement LO::element(int i) const{ //O(n)
	if(i < (d / 2)){
        PNod p = first;
        int k = -1;
        while(p != nullptr){
            k ++;
            if (k == i)
                return p->elem;
            p = p->get_next();
        }
        throw runtime_error("");
    }
    else{
        PNod p = last;
        int k = d;
        while(p != nullptr){
            k --;
            if(k == i)
                return p->elem;
            p = p->get_back();
        }
        throw runtime_error("");
    }
}

// sterge element de pe o pozitie i si returneaza elementul sters
//arunca exceptie daca i nu e valid
TElement LO::sterge(int i) { //0(n)
    if(d==0)
        throw runtime_error("");
    if(i == 0){
        if(d == 1){
            TElement e = last->elem;
            delete last;
            first = nullptr;
            last = nullptr;
            d--;
            return e;
        }else{
            TElement e = first->elem;
            PNod p = first;
            first = first->next;
            first->back = nullptr;
            delete p;
            d--;
            return e;
        }
    }
    if(i == d-1){
        TElement e = last->elem;
        PNod p = last;
        last = last->back;
        last->next = nullptr;
        delete p;
        d--;
        return e;
    }
    if(i < (d / 2)){
        int k = -1;
        PNod p;
        p = first;
        while(p != nullptr) {
            k++;
            if (k == i) {
                TElement t1 = p->elem;
                p->back->next = p->next;
                p->next->back = p->back;
                delete p;
                d --;
                return t1;
            }
            p = p->next;
        }
        throw runtime_error("");
    }
    else{
        int k = d;
        PNod p = last;
        while(p != nullptr){
            k --;
            if(k == i){
                TElement t2 = p->elem;
                p->back->next = p->next;
                p->next->back = p->back;
                delete p;
                d --;
                return t2;
            }
            p = p->get_back();
        }
        throw runtime_error("");
    }
}

// cauta element si returneaza prima pozitie pe care apare (sau -1)
int LO::cauta(TElement e) const { //0(n)
    //folosesc relatia sa nu merg mai departe degeaba
    PNod p = first;
    int k = 0;
    while (p != nullptr){
        if(p->elem == e) return k;
        k ++;
        p = p->get_next();
    }
    return -1;
}

// adaugare element in LO
void LO::adauga(TElement e) { //O(n)
    if(d == 0){
        PNod p = new Nod(e, nullptr, nullptr);
        first = p;
        last = p;
        d ++;
        return;
    }
    if(d == 1){
        PNod p = new Nod(e, nullptr, nullptr);
        if(r(first->elem, e)){
            first->next = p;
            p->back = first;
            p->next = nullptr;
            d ++;
            last = p;
            return;
        }
        else{
            p->next = first;
            p->back = nullptr;
            first->back = p;
            first = p;
            d ++;
            return;
        }
    }
    PNod p = new Nod(e, nullptr, nullptr);
    PNod i = first;
    while(i != nullptr){
        if(!(r(i->elem, e))){
            if(i == first){
                i->back = p;
                p->next = i;
                p->back = nullptr;
                first = p;
                d++;
                return;
            }
            i->back->next = p;
            p->back = i->back;
            p->next = i;
            i->back = p;
            d ++;
            return;
        }
        i = i->get_next();
    }
    d ++;
    p->back = last;
    last->next = p;
    last = p;
}

// returnare iterator
Iterator LO::iterator(){//O(n)
	return Iterator(*this);
}


//destructor
LO::~LO() {//O(n)
    while(first != nullptr){
        PNod next = first->get_next();
        delete first;
        first = next;
    }
}

void LO::print() {
    while(first != nullptr){
        PNod next = first->get_next();
        std::cout << first->elem << " ";
        first = next;
    }
}

void LO::filtreaza(Conditie cond) {        ///O(n)
    if(first == nullptr)
        return;
    PNod p = first;
    while ( p != nullptr && p->next != nullptr) {
        if (!cond(p->next->elem)) {
            PNod aux = p->next;

            p->next = p->next->next;
            d--;
            if ( p->next != nullptr ){
                p->next->back = p;
            }else{
                last = p;
            }
            delete aux;
        }
        p = p->get_next();
    }
    if (!cond(first->elem)){
        PNod aux = first;
        first = first->next;
        d--;
        if ( p->next != nullptr ){
            p->next->back = p;
        }else{
            last = p;
        }
        delete aux;
    }
}