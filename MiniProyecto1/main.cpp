#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
using namespace std;

int main() {
	ListArr listaPrueba = ListArr(8);
	cout << "*** ANTES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	for (int i = 0; i < 4; i++) {
		listaPrueba.insert_left(i + 1);
	}

	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	for (int i = 0; i < 4; i++) {
		listaPrueba.insert_right(5 + i);
	}

	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	for (int i = 0; i < 3; i++) {
		listaPrueba.insert(9+i, 4);
	}

	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	return 0;
}