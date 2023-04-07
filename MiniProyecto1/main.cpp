#include "ListArr.h"
#include "DataNode.h"
#include "SummaryNode.h"
using namespace std;

int main() {
	ListArr listaPrueba = ListArr(4);
	cout << "CANTIDAD TOTAL DE DATOS INGRESADOS: " << listaPrueba.size() << endl;

	// Agregamos 20 números de prueba
	for (int i = 0; i < 20; i++) {
		listaPrueba.insert_left(i+1);
	}
	cout << "CANTIDAD TOTAL DE DATOS INGRESADOS: "  << listaPrueba.size() << endl;

	listaPrueba.print();

	return 0;
}