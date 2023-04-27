#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
using namespace std;

int main() {
	ListArr listaPrueba = ListArr(1e6);
	cout << "*** ANTES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	for (int i = 0; i <4; i++) {
		listaPrueba.insert_left(i + 1);
	}

	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	for (int i = 0; i < 4; i++) {
		listaPrueba.insert_right(5 + i);
	}
	
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	
	for (int i = 0; i < 5; i++) {
		listaPrueba.insert(9+i, 1e7);
	}

	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	int num = 10;
	cout << "*** BUSCAMOS EL NUMERO " << num << " ***" << endl;
	if (listaPrueba.find(num)) {
		cout << num << " encontrado" << endl << endl;
	}
	else {
		cout << num << " no encontrado" << endl << endl;
	}

	num = 8;
	cout << "*** BUSCAMOS EL NUMERO " << num << " ***" << endl;
	if (listaPrueba.find(num)) {
		cout << num << " encontrado" << endl << endl;
	}
	else {
		cout << num << " no encontrado" << endl << endl;
	}
	
	return 0;
}