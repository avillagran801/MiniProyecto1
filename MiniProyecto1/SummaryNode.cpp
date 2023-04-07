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
	return usedCapacity;
}

int SummaryNode::getFullCapacity() {
	return fullCapacity;
}

void SummaryNode::updateUsedCapacity() {
	int aux = 0;

	// Si está en el nivel 1, obtiene la información directamente de los DataNodes
	if (isLevelOne()) {
		aux += leftData->getUsedCapacity();
		if (rightData != nullptr) {
			aux += rightData->getUsedCapacity();
		}
	}
	// Si está en otro nivel, significa que tiene punteros a SummaryNodes y llamará la función recursivamente
	else {
		aux += leftSummary->getUsedCapacity();
		if (rightSummary != nullptr) {
			aux += rightData->getUsedCapacity();
		}
	}

	usedCapacity = aux;
}

void SummaryNode::updateFullCapacity() {
	int aux = 0;

	if (isLevelOne()) {
		aux += leftData->getFullCapacity();
		if (rightData != nullptr) {
			aux += rightData->getFullCapacity();
		}
	}
	else {
		aux += leftSummary->getFullCapacity();
		if (rightSummary != nullptr) {
			aux += rightData->getFullCapacity();
		}
	}

	fullCapacity = aux;
}

void SummaryNode::setLeftData(DataNode* dataAux) {
	leftData = dataAux;
	updateFullCapacity();
}

void SummaryNode::setRightData(DataNode* dataAux) {
	rightData = dataAux;
	updateFullCapacity();
}

void SummaryNode::setLeftSummary(SummaryNode* summaryAux) {
	leftSummary = summaryAux;
	updateFullCapacity();
}

void SummaryNode::setRightSummary(SummaryNode* summaryAux) {
	rightSummary = summaryAux;
	updateFullCapacity();
}

bool SummaryNode::isLevelOne() {
	// Si tiene un DataNode asociado a la izquierda, entonces estamos en el nivel 1 de los SummaryNodes
	return leftData != nullptr;
}

void SummaryNode::addToTheLeft(int number) {
	// Si está en nivel 1, pasa el número al DataNode de la izquierda para que lo maneje
	if (isLevelOne()) {
		leftData->addToTheLeft(number);
		updateUsedCapacity();
		updateFullCapacity();
	}
	// Si está en otro nivel, continúa bajando por los SummartNode de la izquierda hasta llegar al nivel 1
	else {
		leftSummary->addToTheLeft(number);
	}
}

void SummaryNode::printEntireArray() {
	if (isLevelOne()) {
		leftData->printAllLinkedData();
	}
	else {
		leftSummary->printEntireArray();
	}
}