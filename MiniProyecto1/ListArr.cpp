#include <iostream>
#include "ListArr.h"
#include "SummaryNode.h"
#include "DataNode.h"
using namespace std;

// Cuando creamos el ListArr, creamos un primer SummaryNode raiz asociado a un DataNode vacío
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
	return true; // Sólo para que no tirara error
}