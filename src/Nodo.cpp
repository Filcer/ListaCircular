/*
Nombre: Gabriel Filtzer Gorbach
 */
#include "Nodo.h"

Nodo::Nodo(int Dato)
{
	this->Dato = Dato;
	this->Sig = NULL;
}

Nodo::Nodo(int Dato, Nodo *Sig)
{
	this->Dato = Dato;
	this->Sig = Sig;
}

int Nodo::getDato()
{
	return this->Dato;
}

Nodo *Nodo::getSig()
{
	return this->Sig;
}

void Nodo::setDato(int Dato)
{
	this->Dato = Dato;
}

void Nodo::setSig(Nodo *Sig)
{
	this->Sig = Sig;
}