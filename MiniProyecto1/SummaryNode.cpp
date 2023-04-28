#include "SummaryNode.h"
#include "DataNode.h"
using namespace std;

SummaryNode::SummaryNode() {
	usedCapacity = 0;
	fullCapacity = 0;
	leftData = nullptr;
	rightData = nullptr;
	leftSummary = nullptr;
	rightSummary = nullptr;
}



int SummaryNode::getUsedCapacity() {
	updateUsedCapacity();
	return usedCapacity;
}

int SummaryNode::getFullCapacity() {
	updateFullCapacity();
	return fullCapacity;
}

void SummaryNode::updateUsedCapacity() {
	int aux = 0;

	// Si está en el último nivel, obtiene la información directamente de los DataNodes
	if (isLastLevel()) {
		aux += leftData->getUsedCapacity();
		if (rightData != nullptr) {
			aux += rightData->getUsedCapacity();
		}
	}
	// Si está en otro nivel, significa que tiene punteros a SummaryNodes y llamará la función recursivamente
	else {
		if(leftSummary != nullptr) aux += leftSummary->getUsedCapacity();
		if (rightSummary != nullptr) {
			aux += rightSummary->getUsedCapacity();
		}
	}

	usedCapacity = aux;
}

void SummaryNode::updateFullCapacity() {
	int aux = 0;

	if (isLastLevel()) {
		aux += leftData->getFullCapacity();
		if (rightData != nullptr) {
			aux += rightData->getFullCapacity();
		}
	}
	else {
		if(leftSummary != nullptr) aux += leftSummary->getFullCapacity();
		if (rightSummary != nullptr) {
			aux += rightSummary->getFullCapacity();
		}
	}

	fullCapacity = aux;
}

int SummaryNode::getNumDataNodes() {
	int aux = 0;

	if (isLastLevel()) {
		DataNode* auxData = leftData;
		while (auxData != nullptr) {
			aux++;
			auxData = auxData->getNext();
		}
		return aux;
	}

	else {
		getLeftSummary()->getNumDataNodes();
	}
}

void SummaryNode::setLeftData(DataNode* dataAux) {
	leftData = dataAux;
}

void SummaryNode::setRightData(DataNode* dataAux) {
	rightData = dataAux;
}

void SummaryNode::setLeftSummary(SummaryNode* summaryAux) {
	leftSummary = summaryAux;
}

void SummaryNode::setRightSummary(SummaryNode* summaryAux) {
	rightSummary = summaryAux;
}

DataNode* SummaryNode::getLeftData() {
	return leftData;
}

DataNode* SummaryNode::getRightData() {
	return rightData;
}

SummaryNode* SummaryNode::getLeftSummary() {
	return leftSummary;
}

SummaryNode* SummaryNode::getRightSummary() {
	return rightSummary;
}

bool SummaryNode::isLastLevel() {
	// Si tiene un DataNode asociado a la izquierda, entonces estamos en el nivel 1 de los SummaryNodes
	return leftData != nullptr;
}

void SummaryNode::addToTheLeft(int number) {
	// Si está en nivel 1, pasa el número al DataNode de la izquierda para que lo maneje
	if (isLastLevel()) {
		leftData->addToTheLeft(number);
	}
	// Si está en otro nivel, continúa bajando por los SummaryNode de la izquierda hasta llegar al nivel 1
	else {
		leftSummary->addToTheLeft(number);
	}
}

void SummaryNode::addToTheRight(int number){
	this->add(number, usedCapacity + 1);
}

void SummaryNode::add(int number, int pos) {
	//Se considera que el primer elemento lleva la posición 1.
	if(isLastLevel()){
		if (leftData->getUsedCapacity() > pos - 1) {
			leftData->add(number, pos);
		}
		else {
			if (rightData == nullptr) {
				DataNode* aux = leftData->getNext();
				rightData = new DataNode(leftData->getFullCapacity());
				leftData->setNext(rightData);
				rightData->add(number, pos - leftData->getUsedCapacity());
				rightData->setNext(aux);
			}
			else {
				rightData->add(number, pos - leftData->getUsedCapacity());
			}
		}	
	
	}else { //No está en el último nivel, se revisan los SummaryNodes
		if (pos > usedCapacity+1|| pos < 1) {
			cout << "Error: Posición inexistente.";
			return;
		}
		//Se revisa si la posición existe a la izquierdaS
		if (leftSummary->getUsedCapacity() >= pos - 1) {
			//Si la posición existe, se hace recursión por ese lado
			leftSummary->add(number, pos);
		}
		else {
			//De cualquier otra forma se va por la derecha
			rightSummary->add(number, pos - leftSummary->getUsedCapacity());
		}
	}
}

bool SummaryNode::find(int number) {
	if (isLastLevel()) {
		return leftData->findNumber(number);
	}
	else {
		leftSummary->find(number);
	}
}

void SummaryNode::printEntireArray() {
	if (isLastLevel()) {
		leftData->printAllLinkedData();
	}
	else {
		leftSummary->printEntireArray();
	}
}