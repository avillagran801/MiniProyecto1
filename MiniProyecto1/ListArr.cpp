#include <iostream>
#include <cmath>
#include "ListArr.h"
#include "SummaryNode.h"
#include "DataNode.h"
using namespace std;

// Cuando creamos el ListArr, creamos un primer SummaryNode raiz asociado a un DataNode vac�o
ListArr::ListArr(int arrayCapacity) {
	root = new SummaryNode();
	DataNode* aux = new DataNode(arrayCapacity);
	firstData = aux;
	root->setLeftData(aux);
	numDataNodes = 1;
}

int ListArr::size() {
	return root->getUsedCapacity();
}

void ListArr::insert_left(int v) {
	root->addToTheLeft(v);

	// Si la cantidad de nodos al agregar un elemento a la izquierda se ve alterada, actualizamos el �rbol
	cout << "REVISA LA CANTIDAD DE DATANODES: " << endl;
	if (numDataNodes != root->getNumDataNodes()) {
		cout << "UPDATEA EL ARBOL: " << endl;
		updateTree();
	}
	root->updateFullCapacity();
	root->updateUsedCapacity();
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

int ListArr::findHeight() {
	int height = 1;
	
	while (pow(2, height) < numDataNodes) {
		height++;
	}
	cout << "CANTIDAD DE DATANODES: " << numDataNodes << endl;
	cout << "ALTURA DEL ARBOL: " << height << endl;
	return height;
}

void ListArr::generateTree(SummaryNode* summary, int level) {
	if (level == maxLevel) {
		summary->setLeftData(auxDataNode);
		auxDataNode = auxDataNode->getNext();

		if (auxDataNode == nullptr) {
			return;
		}

		summary->setRightData(auxDataNode);
		auxDataNode = auxDataNode->getNext();

		if (auxDataNode == nullptr) {
			return;
		}
	}
	else {
		SummaryNode* sumAuxL = new SummaryNode();
		summary->setLeftSummary(sumAuxL);
		generateTree(summary->getLeftSummary(), level + 1);

		SummaryNode* sumAuxR = new SummaryNode();
		summary->setRightSummary(sumAuxR);
		generateTree(summary->getRightSummary(), level + 1);
	}
}

void ListArr::updateTree() {
	numDataNodes = root->getNumDataNodes();
	maxLevel = findHeight();
	auxDataNode = firstData;
	SummaryNode* newRoot = new SummaryNode();
	generateTree(newRoot, 1);
	root = newRoot;
}