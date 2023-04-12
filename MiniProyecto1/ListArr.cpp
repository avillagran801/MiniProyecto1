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

// SOLUCIONAR PROBLEMA PARA ACTUALIZAR DATA CUANDO SE REALIZA RECURSIVIDAD
void ListArr::generateTree(SummaryNode* summary, int level, DataNode* data) {
	cout << endl << "NIVEL ACTUAL: " << level << endl;
	cout << "DATANODE ACTUAL: " << data << endl;
	
	if (level == maxLevel) {
		summary->setLeftData(data);
		data = data->getNext();
		cout << "DATANODE ACTUALIZADO: " << data << endl;

		if (data == nullptr) {
			cout << "ULTIMO A LA IZQUIERDA" << endl;
			return;
		}

		summary->setRightData(data);
		data = data->getNext();

		if (data == nullptr) {
			cout << "ULTIMO A LA DERECHA!" << endl;
			return;
		}
	}
	else {
		SummaryNode* sumAuxL = new SummaryNode();
		summary->setLeftSummary(sumAuxL);
		generateTree(summary->getLeftSummary(), level + 1, data);

		SummaryNode* sumAuxR = new SummaryNode();
		summary->setRightSummary(sumAuxR);
		generateTree(summary->getRightSummary(), level + 1, data);
	}
}

void ListArr::update() {
	maxLevel = findHeight();
	DataNode* currentDataNode = firstData;
	SummaryNode* newRoot = new SummaryNode();
	generateTree(newRoot, 1, currentDataNode);
	root = newRoot;
}