#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
using namespace std;

int main() {
	ListArr listaPrueba = ListArr(4);

	int numDatosPrueba = 13;

	for (int i = 0; i < numDatosPrueba; i++) {
		cout << "ITERACION " << i << ":" << endl << endl;
		listaPrueba.insert_left(i+1);
		cout << endl;
	}

	cout << "CANTIDAD DE DATOS GUARDADOS: " << listaPrueba.size() << endl;

	return 0;
}