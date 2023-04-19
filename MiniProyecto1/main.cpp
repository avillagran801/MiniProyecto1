#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
using namespace std;

int main() {
	ListArr listaPrueba = ListArr(4);
	cout << "---INGRESO DE DATOS POR LA IZQUIERDA---" << endl << endl;
	cout << "*** ANTES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	int numDatosPrueba = 5;

	for (int i = 0; i < numDatosPrueba; i++) {
		listaPrueba.insert_left(i+1);
	}

	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	cout << endl;

	cout << "--INGRESO DE DATOS POR LA DERECHA---" <<  endl;

	for (int i = 6; i < numDatosPrueba*2 + 1; ++i) {
		listaPrueba.insert_right(i);
	}


	cout << "***DESPUES DEL SEGUNDO INGRESO DE DATOS***" << endl << endl;
	listaPrueba.print();

	cout << endl;
	cout << "---INGRESO DE DATOS EN UNA POSICION NO EXTREMA---" << endl;

	for (int i = 1; i < numDatosPrueba; ++i) {
		listaPrueba.insert(10 * i, 4);
	}

	cout << "***DESPUES DEL TERCER INGRESO DE DATOS***" << endl << endl;
	listaPrueba.print();


	//cout << "HOLA: " << listaPrueba.getRoot()->getRightSummary()->getUsedCapacity() << endl;

	return 0;
}