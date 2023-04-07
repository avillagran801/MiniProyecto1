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

	return aux;
}

int SummaryNode::getFullCapacity() {
	return fullCapacity;
}


void SummaryNode::updateFullCapacity() {
	int aux = 0;

	// Si está en el nivel cero, significa que tiene punteros a DataNodes
	if (isLevelOne()) {
		aux += leftData->getFullCapacity();
		if (rightData != nullptr) {
			aux += rightData->getFullCapacity();
		}
	}

	// Si está en otro nivel, significa que tiene punteros a SummaryNodes y llamará la función recursivamente
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