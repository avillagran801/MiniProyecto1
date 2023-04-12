#include "DataNode.h"
#include <iostream>
using namespace std;

DataNode::DataNode(int capacity) {
	fullCapacity = capacity;
	usedCapacity = 0;
	data = new int[fullCapacity];
	next = nullptr;
}

void DataNode::addToTheLeft(int number) {
	// Si est� vac�o, simplemente insertamos el n�mero en la posici�n 0
	if (usedCapacity == 0) {
		data[0] = number;
		usedCapacity++;
	}
	else {
		// Si a�n queda espacio disponible, se mueve todo 1 espacio a la derecha
		if (usedCapacity + 1 <= fullCapacity) {
			for (int i = 0; i < usedCapacity; i++) {
				data[usedCapacity - i] = data[usedCapacity - i - 1];
			}
			usedCapacity++;
		}
		// Si ya est� lleno el arreglo, enviamos el �ltimo n�mero a next y movemos todo 1 espacio a la derecha
		else {
			if (next == nullptr) {
				next = new DataNode(fullCapacity);
			}
			next->addToTheLeft(data[fullCapacity - 1]);
			for (int i = 0; i < fullCapacity; i++) {
				data[fullCapacity - i] = data[fullCapacity - i - 1];
			}
		}
		data[0] = number;
	}
}

void DataNode::setNext(DataNode* auxNext) {
	next = auxNext;
}

DataNode* DataNode::getNext() {
	return next;
}

int DataNode::getFullCapacity() {
	return fullCapacity;
}

int DataNode::getUsedCapacity() {
	return usedCapacity;
}

void DataNode::printAllLinkedData() {
	cout << "Numeros almacenados en el nodo: " << endl;

	for (int i = 0; i < usedCapacity; i++) {
		cout << data[i] << endl;
	}
	if (next != nullptr) {
		cout << endl;
		next->printAllLinkedData();
	}
	cout << endl;
}