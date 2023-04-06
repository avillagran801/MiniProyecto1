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

	// Si está en el nivel cero, significa que tiene punteros a DataNodes
	if (leftData != nullptr) {
		aux += leftData->getUsedCapacity();
		if (rightData != nullptr) {
			aux += rightData->getUsedCapacity();
		}
	}

	// Si está en otro nivel, significa que tiene punteros a SummaryNodes y llamará la función recursivamente
	if (leftSummary != nullptr) {
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
	if (leftData != nullptr) {
		aux += leftData->getFullCapacity();
		if (rightData != nullptr) {
			aux += rightData->getFullCapacity();
		}
	}

	// Si está en otro nivel, significa que tiene punteros a SummaryNodes y llamará la función recursivamente
	if (leftSummary != nullptr) {
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