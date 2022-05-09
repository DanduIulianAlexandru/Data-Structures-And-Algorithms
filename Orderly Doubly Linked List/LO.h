#pragma once

class Iterator;

typedef int TComparabil;
typedef TComparabil TElement;
typedef bool (*Conditie)(TElement);
typedef bool (*Relatie)(TElement, TElement);

#define NULL_TELEMENT -1

class Nod;
typedef Nod* PNod;

class Nod{
private:
    TElement elem;
    PNod back;
    PNod next;

public:
    friend class LO;

    Nod(TElement e, PNod back, PNod next){
        this->elem = e;
        this->back = back;
        this->next = next;
    }

    Nod* get_back(){
        return back;
    }
    Nod* get_next(){
        return next;
    }
};



class LO {
private:
	friend class Iterator;
private:
    PNod first;
    PNod last;
    int d; //dimensiune
    Relatie r;
public:


	// constructor
	LO(Relatie r);

	// returnare dimensiune
	int dim() const;

	// verifica daca LO e vida
	bool vida() const;

	// returnare element
	//arunca exceptie daca i nu e valid
	TElement element(int i) const;

	// adaugare element in LO a.i. sa se pastreze ordinea intre elemente
	void adauga(TElement e);

	// sterge element de pe o pozitie i si returneaza elementul sters
	//arunca exceptie daca i nu e valid
	TElement sterge(int i);

	// cauta element si returneaza prima pozitie pe care apare (sau -1)
	int cauta(TElement e) const;

	// returnare iterator
	Iterator iterator();

	//destructor
	~LO();

    void print();

    void filtreaza(Conditie cond);
};
