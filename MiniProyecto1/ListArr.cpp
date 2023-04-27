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
	maxLevel = 1;
	auxDataNode = nullptr;
}

int ListArr::size() {
	return root->getUsedCapacity();
}

void ListArr::insert_left(int v) {
	root->addToTheLeft(v);

	// Si la cantidad de nodos al agregar un elemento a la izquierda se ve alterada, actualizamos el árbol
	if (numDataNodes != root->getNumDataNodes()) {
		updateTree();
	}
	root->updateFullCapacity();
	root->updateUsedCapacity();
}

void ListArr::insert_right(int v) {
	root->addToTheRight(v);
	if (numDataNodes != root->getNumDataNodes()) {
		updateTree();
	}
	root->updateFullCapacity();
	root->updateUsedCapacity();
}

void ListArr::insert(int v, int i) { //V = número, i = posición
	root->add(v, i);
	if (numDataNodes != root->getNumDataNodes()) {
		updateTree();
	}
	root->updateFullCapacity();
	root->updateUsedCapacity();
}

void ListArr::print() {
	cout << "NUMERO DE DATOS INGRESADOS: " << size() << endl;
	cout << "NUMERO DE DATA NODES: " << root->getNumDataNodes() << endl;
	cout << "NUMERO DE NIVELES EN EL ARBOL: " << maxLevel << endl << endl;

	root->printEntireArray();
	cout << endl;
}

bool ListArr::find(int v) {
	return firstData->findNumber(v);
}

int ListArr::findHeight() {
	int height = 1;
	
	while (pow(2, height) < numDataNodes) {
		height++;
	}
	return height;
}

void ListArr::generateTree(SummaryNode* summary, int level) {
	if (level == maxLevel) {
		summary->setLeftData(auxDataNode);
		if(auxDataNode != nullptr) auxDataNode = auxDataNode->getNext();

		if (auxDataNode == nullptr) {
			return;
		}

		summary->setRightData(auxDataNode);
		if(auxDataNode != nullptr) auxDataNode = auxDataNode->getNext();

		if (auxDataNode == nullptr) {
			return;
		}
	}
	else {
		SummaryNode* sumAuxL = new SummaryNode();
		summary->setLeftSummary(sumAuxL);
		generateTree(summary->getLeftSummary(), level + 1);

		if (auxDataNode != nullptr) {
			SummaryNode* sumAuxR = new SummaryNode();
			summary->setRightSummary(sumAuxR);
			generateTree(summary->getRightSummary(), level + 1);
		}
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

SummaryNode* ListArr::getRoot() {
	return root;
}