// #include "ListArr.h"
#include "DataNode.h"
using namespace std;

int main() {
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

	return 0;
}