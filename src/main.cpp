/*
Nombre: Gabriel Filtzer Gorbach
 */

#include "ListaCircular.h"
using namespace std;

int main()
{
    int opc, a, b;
    ListaCircular l = ListaCircular();
    do
    {
        cout << "1. addInicio" << endl;
        cout << "2. addFinal" << endl;
        cout << "3. addAt" << endl;
        cout << "4. popInicio" << endl;
        cout << "5. popFinal" << endl;
        cout << "6. popAt" << endl;
        cout << "7. vaciar" << endl;
        cout << "8. getElemento" << endl;
        cout << "9. show" << endl << endl;
        cout << "0. Salir del Programa..." << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el Dato: ";
            cin >> a;
            l.addInicio(a);
            break;
        case 2:
            cout << "Ingrese el Dato: ";
            cin >> a;
            l.addFinal(a);
            break;
        case 3:
            cout << "Ingrese el Dato: ";
            cin >> a;
            cout << "Ingrese la referencia (comienza en 0): ";
            cin >> b;
            l.addAt(a, b);
            break;
        case 4:
            cout << l.popInicio() << endl;
            break;
        case 5:
            cout << l.popFinal() << endl;
            break;
        case 6:
            cout << "Ingrese la referencia (comienza en 0): ";
            cin >> a;
            l.popAt(a);
            break;
        case 7:
            l.vaciar();
            break;
        case 8:
            cout << "Ingrese el Dato del nodo a obtener: ";
            cin >> a;
            cout << "Nodo obtenido: " << l.getElemento(a) << endl;
            break;
        case 9:
            l.show();
            break;
        case 0:
            break;
        default:
            cout << "Opción inválida." << endl;
        }
    } while (opc != 0);
    return 0;
}
