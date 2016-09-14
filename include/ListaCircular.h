/*
Nombre: Gabriel Filtzer Gorbach
 */

#include "Nodo.h"

class ListaCircular
{
public:
	ListaCircular();
	ListaCircular(int Dato);
	bool ListaVacia();
	bool vaciar();
	void show();
	void addInicio(int Dato);
	void addFinal(int Dato);
	void addAt(int Dato, int ref);
	int popInicio();
	int popFinal();
	int popAt(int ref);
	Nodo *getElemento(int Dato);
	Nodo *getH();
	Nodo *getT();

private:
	Nodo *h;
	Nodo *t;
};