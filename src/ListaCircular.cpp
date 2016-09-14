/*
Nombre: Gabriel Filtzer Gorbach
 */

#include "ListaCircular.h"
using namespace std;

ListaCircular::ListaCircular()
{
	this->h = NULL;
	this->t = NULL;
}

ListaCircular::ListaCircular(int Dato)
{
	Nodo *n = new Nodo(Dato, n);
	this->h = n;
	this->t = n;
}

bool ListaCircular::ListaVacia()
{
	return (this->h == NULL && this->t == NULL);
}

bool ListaCircular::vaciar()
{
	this->h = NULL;
	this->t = NULL;
}

void ListaCircular::show()
{
	if (this->ListaVacia())
	{
		cout << "La lista está vacía." << endl;
		return;
	}
	cout << "[ ";
	for (Nodo *aux = this->h ; aux != this->t ; aux = aux->getSig())
	{
		cout << aux->getDato() << " , ";
	}
	cout << this->t->getDato() << " ]" << endl;
}

void ListaCircular::addInicio(int Dato)
{
	Nodo *n = new Nodo(Dato, this->h);
	if (this->ListaVacia())
	{
		this->t = n;
	}
	this->h = n;
	this->t->setSig(this->h);
}

void ListaCircular::addFinal(int Dato)
{
	Nodo *n = new Nodo(Dato);
	if(this->ListaVacia())
	{
		this->h = n;
	}
	else
	{
		this->t->setSig(n);
	}
	this->t = n;
	this->t->setSig(h);
}

/**
 *	Agrega el Dato en la posición -ref-, recorriendo
 *	todos los posteriores.
 *
 *	El primer elemento es lista[0].
 *
 *	Si la lista contiene menos elementos que ref, el
 *	Dato se agrega al final.
 */
void ListaCircular::addAt(int Dato, int ref)
{
	if (ref <= 0)
	{
		if (ref < 0)
		{
			cout << "Referencia inválida, agregando al inicio..." << endl;
		}
		addInicio(Dato);
		return;
	}
	if (!this->ListaVacia())
	{
		Nodo *aux = this->h;
		for (int i = 0; i < (ref - 1) ; ++i)
		{
			if (aux->getSig() == this->t || aux->getSig() == this->h)
			{
				cout << "El tamaño de la lista es menor, se agregará al final..." << endl;
				this->addFinal(Dato);
				return;
			}
			aux = aux->getSig();
		}
		Nodo *n = new Nodo(Dato, aux->getSig());
		aux->setSig(n);
		return;
	}
	cout << "La lista está vacía, se agregará el Dato al inicio..." << endl;
	this->addInicio(Dato);
}

int ListaCircular::popInicio()
{
	if (this->ListaVacia())
	{
		cout << "La lista está vacía." << endl;
		return 0;
	}
	int Dato = this->h->getDato();
	if (this->h == this->t)
	{
		this->h == NULL;
		this->t == NULL;
	}
	else
	{
		this->h = this->h->getSig();
		this->t->setSig(this->h);
	}
	return Dato;
}

int ListaCircular::popFinal()
{
	if (this->ListaVacia())
	{
		cout << "La lista está vacía." << endl;
		return 0;
	}
	int Dato = this->t->getDato();
	if (this->h == this->t)
	{
		this->h == NULL;
		this->t == NULL;
		return Dato;
	}
	Nodo *n = this->h;
	while (n->getSig() != this->t)
	{
		n = n->getSig();
	}
	this->t = n;
	this->t->setSig(this->h);
	return Dato;
}

/**
 *	Regresa el Dato en la posición -ref- ,eliminandolo
 *	y recorriendo los posteriores hacia atrás.
 *
 *	El primer elemento es lista[0].
 *
 *	Si -ref- es mayor al tamaño de la lista, no se hace
 *	nada.
 */
int ListaCircular::popAt(int ref)
{
	if (ref <= 0)
	{
		if (ref < 0)
		{
			cout << "Referencia inválida, retirando al inicio..." << endl;
		}
		return popInicio();
	}
	if (this->ListaVacia())
	{
		cout << "La lista está vacía." << endl;
		return 0;
	}
	Nodo *n = this->h;
	for (int i = 0 ; i < (ref - 1) ; ++i)
	{
		if (n->getSig() == this->t || n->getSig() == this->h)
			{
				cout << "El tamaño de la lista es menor, se eliminará el último elemento..." << endl;
				return popFinal();
			}
		n = n->getSig();
	}
	int Dato = n->getSig()->getDato();
	if (n->getSig() == this->t)
	{
		this->t = n;
		this->t->setSig(this->h);
	}
	else
	{
		n->setSig(n->getSig()->getSig());
	}
	return Dato;
}

Nodo *ListaCircular::getElemento(int Dato)
{
	if (this->ListaVacia())
	{
		cout << "La lista está vacía." << endl;
		return NULL;
	}
	Nodo *n = this->h;
	while (n->getDato() != Dato && n->getSig() != this->h)
	{
		n = n->getSig();
	}
	if (n->getDato() == Dato)
	{
		return n;
	}
	//Si n.Dato != Dato y n == t, entonces no se encontró
	cout << "No existe el elemento." << endl;
	return NULL;
}

Nodo *ListaCircular::getH()
{
	return this->h;
}

Nodo *ListaCircular::getT()
{
	return this->t;
}