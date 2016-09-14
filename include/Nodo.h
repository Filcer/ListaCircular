/*
Nombre: Gabriel Filtzer Gorbach
 */

#include <iostream>

class Nodo
{
public:
	Nodo(int Dato);
	Nodo(int Dato, Nodo *Sig);
	int getDato();
	Nodo *getSig();
	void setDato(int Dato);
	void setSig(Nodo *Sig);

private:
	int Dato;
	Nodo *Sig;
};