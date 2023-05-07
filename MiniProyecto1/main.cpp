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
		listaPrueba.insert_right(10 + i);
	}

	cout << "*** DESPUES DE INGRESAR LOS DATOS ***" << endl << endl;
	listaPrueba.print();


	for (int i = 0; i < 10; i++) {
		listaPrueba.insert(-i-1, 4);
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
	//La idea es solo modificar las variables n y b para hacer los experimentos, junto con la función a probar
	//Función actual: Inserts


	/*
	Array* Larray1;
	LinkedList* Llist1;
	ListArr* LListArr1;
	int n = 1000000;
	int b = 1024;

	int* data = new int[n];
	for (int i = 0; i < n; ++i) data[i] = rand();

	long long ArrayTime = 0;
	long long ListTime = 0;
	long long ListArrTime = 0;

	for (int j = 0; j < 1; ++j) {



		/*
		Larray1 = new Array(n);
		auto start1 = chrono::high_resolution_clock::now();

		for (int i = 0; i < n; ++i) {
			Larray1->addToTheRight(data[i]);
		}


		auto stop1 = chrono::high_resolution_clock::now();
		auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
		Larray1->print();
		ArrayTime += duration1.count();
		delete Larray1;
		*/


		/*
		Llist1 = new LinkedList();
		auto start2 = chrono::high_resolution_clock::now();

		for (int i = 0; i < n; ++i) {
			Llist1->addToTheRight(data[i]);
		}

		auto stop2 = chrono::high_resolution_clock::now();
		auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);

		ListTime += duration2.count();
		delete Llist1;
		*/

		/*
		LListArr1 = new ListArr(b);
		auto start3 = chrono::high_resolution_clock::now();

		for (int i = 0; i < n; ++i) {
			LListArr1->insert_left(data[i]);
		}

		auto stop3 = chrono::high_resolution_clock::now();
		auto duration3 = chrono::duration_cast<chrono::milliseconds>(stop3 - start3);

		ListArrTime += duration3.count();
		delete LListArr1;
		*/



		//}

		/*
		std::cout << "INSERT RIGHT" << " b = " << b << " n = " << n << endl <<endl;

		/*
		std::cout << "Tiempo total Array: " << ArrayTime << " milisegundos" << endl;
		std::cout << "Tiempo promedio Array: " << ArrayTime / long long(20) << " milisegundos" << endl << endl;

		*/

		//cout << "Tiempo total LinkedList: " << ListTime << " milisegundos" << endl;
		//cout << "Tiempo promedio LinkedList: " << ListTime / long long (20) << " milisegundos" << endl<< endl;


		/*
		cout << "Tiempo total ListArr: " << ListArrTime << " milisegundos" << endl;
		cout << "Tiempo promedio ListArr: " << ListArrTime / long long(20) << " milisegundos" << endl << endl;
		*/






		//Testeo de función find

		// b = 1024	, n = 100000
	Array* Larray1;
	LinkedList* Llist1;
	ListArr* LListArr1;
	int n = 100000;
	int b = 64;
	int* data = new int[n]; // Arreglo con números a poner en Arreglo, LinkedList o ListArr
	for (int i = 0; i < n; ++i) {
		data[i] = rand(); // Números del 0 al RAND_MAX()
	}
	int searched = 0;

	long long ArrayTime, ListTime, ListArrTime;
	ArrayTime = 0;
	ListTime = 0;
	ListArrTime = 0;

		std::cout << "FIND" << " b = " << b << " n = " << n << endl << endl;


		/*
		Larray1 = new Array(n);
		for (int i = 0; i < n; ++i) {
			Larray1->addToTheRight(data[i]); //Método más rápido para Array
		}

		for (int i = 0; i < 20; ++i) {

			searched = 2 * rand();

			auto start1 = chrono::high_resolution_clock::now();

			Larray1->find(searched);

			auto stop1 = chrono::high_resolution_clock::now();
			auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);

			ArrayTime += duration1.count();
		}

		delete Larray1;

		std::cout << "Tiempo total Array: " << ArrayTime << " microsegundos" << endl;
		std::cout << "Tiempo promedio Array: " << ArrayTime / long long(20) << " microsegundos" << endl;
		*/

		
		/*
		Llist1 = new LinkedList();
		for (int i = 0; i < n; ++i) {

			Llist1->addToTheLeft(data[i]); //Método más rápdido para LinkedList
		}

		for (int i = 0; i < 20; ++i) {

			searched = 2 * rand();

			auto start2 = chrono::high_resolution_clock::now();

			Llist1->find(searched);

			auto stop2 = chrono::high_resolution_clock::now();
			auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);

			ListTime += duration2.count();
		}

		delete Llist1;
		
		std::cout << "Tiempo total LinkedList: " << ListTime << " milliseconds" << endl;
		std::cout << "Tiempo promedio: " << ListTime / long long(20) << " milliseconds" << endl;
		*/
		

		
		LListArr1 = new ListArr(b);
		for (int i = 0; i < n; ++i) {
			LListArr1->insert_left(data[i]); //Método más rápido para n grande en ListArr
		}

		for (int i = 0; i < 20; ++i) {

			searched = 2 * rand();

			auto start3 = chrono::high_resolution_clock::now();

			LListArr1->find(searched);

			auto stop3 = chrono::high_resolution_clock::now();
			auto duration3 = chrono::duration_cast<chrono::microseconds>(stop3 - start3);

			ListArrTime += duration3.count();
		}

		delete LListArr1;
		
		std::cout << "Tiempo total ListArr: " << ListArrTime << " microseconds" << endl;
		std::cout << "Tiempo promedio ListArr: " << ListArrTime / long long(20) << " microseconds" << endl << endl;
		





	
	//_CrtDumpMemoryLeaks();
	
	return 0;
} 