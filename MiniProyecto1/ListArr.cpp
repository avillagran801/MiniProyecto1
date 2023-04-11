#include <iostream>
#include "ListArr.h"
#include "SummaryNode.h"
#include "DataNode.h"
using namespace std;

// Cuando creamos el ListArr, creamos un primer SummaryNode raiz asociado a un DataNode vac�o
ListArr::ListArr(int arrayCapacity) {
	root = new SummaryNode();
	DataNode* aux = new DataNode(arrayCapacity);
	root->setLeftData(aux);

	usedCapacity = root->getUsedCapacity();
	fullCapacity = root->getFullCapacity();
}

int ListArr::size() {
	return root->getUsedCapacity();
}

void ListArr::insert_left(int v) {
	root->addToTheLeft(v);
	usedCapacity = root->getUsedCapacity();
	fullCapacity = root->getFullCapacity();
}

void ListArr::insert_right(int v) {

}

void ListArr::insert(int v, int i) {

}

void ListArr::print() {
	root->printEntireArray();
}

bool ListArr::find(int v) {
	return true; // S�lo para que no tirara error
}

void ListArr::createNewDataNode(int cap) {
	// OJO: ESTE M�TODO SE LLAMA A PARTIR DE ROOT
	// NO UNE A�N EL �LTIMO DATANODE CON EL QUE SE AGREGA AQU�

	DataNode* newDataNode = new DataNode(cap);
	SummaryNode* auxRoot = root;
	SummaryNode* currentNode = root;
	SummaryNode* lastAvailableRight = nullptr;
	int addDirectly = 0;
	int lastSaved = 0;

	while (currentNode != nullptr) {
		if (currentNode->isLevelOne()) {
			// Si estamos en el �ltimo nivel y est� disponible el espacio a la derecha, se activa la bandera de addDirectly
			if (currentNode->getRightData() == nullptr) {
				addDirectly = 1;
				break;
			}
			break;
			// Si no est� disponible el espacio a la derecha, debemos crear uno o m�s SummaryNodes
		}

		else {
			 // Si queda camino por la derecha, continuamos
			if (currentNode->getRightSummary() != nullptr) {
				currentNode = currentNode->getRightSummary();
			}
			// Si no queda camino por la derecha, lo marcamos como �ltimo nodo con espacio libre
			else {
				lastAvailableRight = currentNode;
				currentNode = currentNode->getLeftSummary();
			}
		}
	}

	if (addDirectly) {
		cout << "AGREGAMOS DIRECTAMENTE! \n";
		currentNode->setRightData(newDataNode);
	}
	else{
		cout << "HAY QUE AGREGAR NODOS! \n";
	}

}