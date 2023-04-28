#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
#include "Array.h"
#include "LinkedList.h"
#include <crtdbg.h>
using namespace std;

int main() {

	LinkedList lTest = LinkedList();

	cout << "*** ANTES DE INGRESAR LOS DATOS ***" << endl << endl;
	lTest.print();

	for (int i = 0; i < 5; ++i) {
		lTest.addToTheLeft(i + 1);
	}
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	lTest.print();

	for (int i = 5; i < 10; ++i) {
		lTest.addToTheRight(i + 1);
	}
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	lTest.print();

	for (int i = 10; i < 15; ++i) {
		lTest.add(i + 1, 5);
	}
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	lTest.print();

	cout << lTest.find(10) << endl;
	cout << lTest.find(-1) << endl;


	/*

	Array aTest = Array(20);
	cout << "*** ANTES DE INGRESAR LOS DATOS ***" << endl << endl;
	aTest.print();

	for(int i = 0; i < 5; ++i) {
		aTest.addToTheLeft(i + 1);
	}
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	aTest.print();

	for (int i = 5; i < 10; ++i) {
		aTest.addToTheRight(i + 1);
	}
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	aTest.print();

	for (int i = 10; i < 15; ++i) {
		aTest.add(i + 1 , 5);
	}
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	aTest.print();

	cout << aTest.find(10) << endl;
	cout << aTest.find(-1) << endl;

	*/


	/*
	ListArr listaPrueba = ListArr(6);
	cout << "*** ANTES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	for (int i = 0; i <10; i++) {
		listaPrueba.insert_left(i + 1);
	}

	
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	

	for (int i = 0; i < 10; i++) {
		listaPrueba.insert_right(5 + i);
	}
	
	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();

	
	for (int i = 0; i < 10; i++) {
		listaPrueba.insert(9+i, 4);
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

	num = 89;
	cout << "*** BUSCAMOS EL NUMERO " << num << " ***" << endl;
	if (listaPrueba.find(num)) {
		cout << num << " encontrado" << endl << endl;
	}
	else {
		cout << num << " no encontrado" << endl << endl;
	}
	*/



	_CrtDumpMemoryLeaks();
	
	return 0;
} 