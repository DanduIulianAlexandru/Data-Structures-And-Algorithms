#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {//O(1)
    if(e1 <= e2)
        return true;
    else
        return false;
}

void Colectie::redim(){//O(n)
    TElem *eNou = new TElem[2 * cp];
    for(int i = 0; i < n; i ++)
        eNou[i] =e[i];
    cp = 2 * cp;
    delete[] e;
    e = eNou;
}

Colectie::Colectie() {//O(1)
	cp = 2;
    e = new TElem[cp];
    n = 0;
}

void Colectie::adauga(TElem elem) {//O(n ^ 2)
    int ok = 0;
    if(this->cp == this->n) {
        redim();
    }
    if(n == 0){
        this->e[0] = elem;
        n ++;
    }
    else{
        for(int i = 0; i < n; i ++){
            if(rel(elem, e[i])){
                ok = 1;
                n ++;
                for(int j = n - 1; j >= i; j --) {
                    e[j + 1] = e[j];
                }
                e[i] = elem;
                break;
            }
        }
        if(ok == 0)
            e[n ++] = elem;
    }
}

bool Colectie::sterge(TElem elem) {//O(n^2)
	for(int i = 0; i < n; i ++){
        if(e[i] == elem){
            for(int j = i; j < n; j ++)
                e[j] = e[j + 1];
            n --;
            return true;
        }
    }
    return false;
}


bool Colectie::cauta(TElem elem) const {//O(n)
	for(int i = 0; i < n; i ++)
        if(e[i] == elem)
            return true;
	return false;
}


int Colectie::nrAparitii(TElem elem) const {//O(n)
    int ok = 0;
	for(int i = 0; i < n; i ++)
        if(this->e[i] == elem)
            ok ++;
    return ok;
}

int Colectie::dim() const {//O(1)
	return n;
}

bool Colectie::vida() const {//O(1)
	return (n == 0);
}

IteratorColectie Colectie::iterator() const {//O(1)
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	delete[] e;
}

void Colectie::show() {
    for(int i = 0; i < this->n; i ++)
        printf("%d  ", e[i]);
}
