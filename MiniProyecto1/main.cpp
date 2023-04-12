#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
using namespace std;

int main() {
	ListArr listaPrueba = ListArr(4);

	int numDatosPrueba = 9;

	for (int i = 0; i < numDatosPrueba; i++) {
		listaPrueba.insert_left(i+1);
	}

	if (numDatosPrueba % 4 == 0) {
		listaPrueba.setNumDataNodes(numDatosPrueba / 4);
	}
	else {
		listaPrueba.setNumDataNodes(numDatosPrueba / 4 + 1);
	}

	cout << "CANTIDAD TOTAL DE DATOS INGRESADOS: "  << listaPrueba.size() << endl;

	listaPrueba.print();

	listaPrueba.update();

	return 0;
}