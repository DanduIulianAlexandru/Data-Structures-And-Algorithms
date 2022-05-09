#pragma once
#include "../vector.h"
typedef int TElem;
class IteratorLP;

class Lista {
private:
	friend class IteratorLP;
    int capacitate; // capacitatea vectorilor elemente, urm si prec
    int first; //primul nod al listei (daca este egal cu -1 inseamna ca lista e goala)
    int last; //ultimul nod al listei
    int primLiber; // primul i pentru care elemente[i] este gol
    vectorDinamic<TElem> elemente;
    vectorDinamic<int> urm;
    vectorDinamic<int> prec;

    void aloca(Lista lista, int i);  //alocam un loc din lista de spatii goale unui element nou in lista
    void dealoca(Lista lista, int i);
public:

		// constructor
		Lista ();

		// returnare dimensiune
		int dim() const;

		// verifica daca lista e vida
		bool vida() const;

		// prima pozitie din lista
		IteratorLP prim() const;

		// returnare element de pe pozitia curenta
		//arunca exceptie daca poz nu e valid
		TElem element(IteratorLP poz) const;

		// modifica element de pe pozitia poz si returneaza vechea valoare
		//arunca exceptie daca poz nu e valid
		TElem modifica(IteratorLP poz, TElem e);

		// adaugare element la inceput
		void adaugaInceput(TElem e);		

		// adaugare element la sfarsit
		void adaugaSfarsit(TElem e);

		// adaugare element dupa o pozitie poz
		//dupa adaugare poz este pozitionat pe elementul adaugat
		//arunca exceptie daca poz nu e valid
		void adauga(IteratorLP& poz, TElem e);

		// sterge element de pe o pozitie poz si returneaza elementul sters
		//dupa stergere poz este pozitionat pe elementul de dupa cel sters
		//arunca exceptia daca poz nu e valid
		TElem sterge(IteratorLP& poz);

		// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
		IteratorLP cauta(TElem e) const;

		//destructor

        void inverseazaIntre(IteratorLP, IteratorLP);

        void print();

		~Lista();
};
