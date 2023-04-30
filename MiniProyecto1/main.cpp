#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
#include "Array.h"
#include "LinkedList.h"
#include <crtdbg.h>
#include <chrono> 
using namespace std;

int main() {

	/*
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
	*/

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

	//---Experimentos oficiales--
	
	//----------------- INSERT_LEFT: --------------------
	
	// b = 1024	, n = 10000
	Array* Larray1;
	LinkedList* Llist1;
	ListArr* LListArr1;
	int n = 10000;
	int b = 1024;

	int* data = new int[n];
	for (int i = 0; i < n; ++i) data[i] = rand();

	long long ArrayTime = 0;
	long long ListTime = 0;
	long long ListArrTime = 0;

	for (int j = 0; j < 20; ++j) {

		Larray1 = new Array(n);
		Llist1 = new LinkedList();
		LListArr1 = new ListArr(b);

		auto start1 = chrono::high_resolution_clock::now();

		for (int i = 0; i < n; ++i) {
			Larray1->addToTheLeft(data[i]);
		}


		auto stop1 = chrono::high_resolution_clock::now();
		auto duration1 = chrono::duration_cast<chrono::nanoseconds>(stop1 - start1);

		auto start2 = chrono::high_resolution_clock::now();

		for (int i = 0; i < n; ++i) {
			Llist1->addToTheLeft(data[i]);
		}

		auto stop2 = chrono::high_resolution_clock::now();
		auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);

		auto start3 = chrono::high_resolution_clock::now();

		for (int i = 0; i < n; ++i) {
			LListArr1->insert_left(data[i]);
		}

		auto stop3 = chrono::high_resolution_clock::now();
		auto duration3 = chrono::duration_cast<chrono::nanoseconds>(stop3 - start3);

		
		ArrayTime += duration1.count();
		ListTime += duration2.count();
		ListArrTime += duration3.count();

		delete Larray1;
		delete Llist1;
		delete LListArr1;
	}

	cout << "INSERT LEFT" << " b = " << b << " n = " << n << endl;

	cout << "Tiempo total Array: " << ArrayTime << " nanosegundos" << endl;
	cout << "Tiempo promedio Array: " << ArrayTime / long long (n*20) << " nanosegundos" << endl;

	cout << "Tiempo total LinkedList: " << ListTime << " nanosegundos" << endl;
	cout << "Tiempo promedio: " << ListTime / long long (n*20) << " nanosegundos" << endl;

	cout << "Tiempo total ListArr: " << ListArrTime << " nanosegundos" << endl;
	cout << "Tiempo promedio ListArr: " << ListArrTime / long long(n*20) << " nanosegundos" << endl << endl;
	
	



	/*


	// b = 1024	, n = 100000
	Array* Larray2;
	LinkedList* Llist2;
	ListArr* LListArr2;

	int* data2 = new int[100000];
	for (int i = 0; i < 100000; ++i) data2[i] = rand();

	ArrayTime = 0;
	ListTime = 0;
	ListArrTime = 0;

	for (int j = 0; j < 20; ++j) {

		Larray2 = new Array(100000);
		Llist2 = new LinkedList();
		LListArr2 = new ListArr(1024);

		auto start1 = chrono::high_resolution_clock::now();

		for (int i = 0; i < 100000; ++i) {
			Larray2->addToTheLeft(data2[i]);
		}


		auto stop1 = chrono::high_resolution_clock::now();
		auto duration1 = chrono::duration_cast<chrono::nanoseconds>(stop1 - start1);

		auto start2 = chrono::high_resolution_clock::now();

		for (int i = 0; i < 100000; ++i) {
			Llist2->addToTheLeft(data2[i]);
		}

		auto stop2 = chrono::high_resolution_clock::now();
		auto duration2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);

		auto start3 = chrono::high_resolution_clock::now();

		for (int i = 0; i < 100000; ++i) {
			LListArr2->insert_left(data2[i]);
		}

		auto stop3 = chrono::high_resolution_clock::now();
		auto duration3 = chrono::duration_cast<chrono::nanoseconds>(stop3 - start3);


		ArrayTime += duration1.count();
		ListTime += duration2.count();
		ListArrTime += duration3.count();

		delete Larray2;
		delete Llist2;
		delete LListArr2;
	}

	cout << "INSERT LEFT, B = 1024, N=100000" << endl;

	cout << "Tiempo total Array: " << ArrayTime << " nanosegundos" << endl;
	cout << "Tiempo promedio Array: " << ArrayTime / long long(100000 * 20) << " nanosegundos" << endl;

	cout << "Tiempo total LinkedList: " << ListTime << " nanosegundos" << endl;
	cout << "Tiempo promedio: " << ListTime / long long(100000 * 20) << " nanosegundos" << endl;

	cout << "Tiempo total ListArr: " << ListArrTime << " nanosegundos" << endl;
	cout << "Tiempo promedio ListArr: " << ListArrTime / long long(100000 * 20) << " nanosegundos" << endl << endl;

	*/
	//_CrtDumpMemoryLeaks();
	
	return 0;
} 