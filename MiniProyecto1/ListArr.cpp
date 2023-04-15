#include <iostream>
#include <cmath>
#include "ListArr.h"
#include "SummaryNode.h"
#include "DataNode.h"
using namespace std;

// Cuando creamos el ListArr, creamos un primer SummaryNode raiz asociado a un DataNode vacío
ListArr::ListArr(int arrayCapacity) {
	root = new SummaryNode();
	DataNode* aux = new DataNode(arrayCapacity);
	firstData = aux;
	root->setLeftData(aux);
	numDataNodes = 1;

	// usedCapacity = root->getUsedCapacity();
	// fullCapacity = root->getFullCapacity();
}

int ListArr::size() {
	return root->getUsedCapacity();
}

void ListArr::insert_left(int v) {
	root->addToTheLeft(v);
	root->updateUsedCapacity();
	root->updateUsedCapacity();
	// usedCapacity = root->getUsedCapacity();
	// fullCapacity = root->getFullCapacity();
}

void ListArr::insert_right(int v) {

}

void ListArr::insert(int v, int i) {

}

void ListArr::print() {
	root->printEntireArray();
}

bool ListArr::find(int v) {
	return true; // Sólo para que no tirara error
}

void ListArr::setNumDataNodes(int num) {
	numDataNodes = num;
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
	cout << endl << "NIVEL ACTUAL: " << level << endl;
	cout << "DATANODE ACTUAL: " << auxDataNode << endl;
	
	if (level == maxLevel) {
		summary->setLeftData(auxDataNode);
		auxDataNode = auxDataNode->getNext();
		cout << "DATANODE ACTUALIZADO: " << auxDataNode << endl;

		if (auxDataNode == nullptr) {
			cout << "ULTIMO A LA IZQUIERDA" << endl;
			return;
		}

		summary->setRightData(auxDataNode);
		auxDataNode = auxDataNode->getNext();

		cout << "DATANODE ACTUALIZADO: " << auxDataNode << endl;

		if (auxDataNode == nullptr) {
			cout << "ULTIMO A LA DERECHA!" << endl;
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

void ListArr::update() {
	maxLevel = findHeight();
	auxDataNode = firstData;
	SummaryNode* newRoot = new SummaryNode();
	generateTree(newRoot, 1);
	newRoot->updateFullCapacity();
	newRoot->updateUsedCapacity();
	root = newRoot;

	cout << root->getUsedCapacity() << " DE " << root->getFullCapacity() << " ESPACIOS" << endl;
}