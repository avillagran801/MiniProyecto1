#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
using namespace std;

int main() {
	/*
	DataNode* nodePrueba = new DataNode(4);

	nodePrueba->addToTheLeft(8);
	nodePrueba->addToTheLeft(7);
	nodePrueba->addToTheLeft(6);
	nodePrueba->addToTheLeft(5);

	cout << "*** ANTES DE AGREGAR UN ELEMENTO AL NODO LLENO ***" << endl << endl;
	nodePrueba->printAllLinkedData();

	nodePrueba->addToTheLeft(4);

	cout << "*** DESPUES DE AGREGAR UN ELEMENTO AL NODO LLENO ***" << endl << endl;
	nodePrueba->printAllLinkedData();

	nodePrueba->addToTheLeft(3);
	nodePrueba->addToTheLeft(2);
	nodePrueba->addToTheLeft(1);
	nodePrueba->addToTheLeft(0);
	nodePrueba->addToTheLeft(-1);

	cout << "*** AGREGAMOS ELEMENTOS HASTA OBTENER UN TERCER NODO ***" << endl << endl;
	nodePrueba->printAllLinkedData();

	*/

	ListArr* listaPrueba = new ListArr(4);
	cout << listaPrueba->size() << endl;

	return 0;
}