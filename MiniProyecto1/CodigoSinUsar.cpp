/*
while (auxLastNode != nullptr) {
	if (auxLastNode->isLevelOne()) {
		if (auxLastNode->getRightData() != nullptr) { // Si ya existe un DataNode a la derecha del todo, se activa el newRootFlag
			newRootFlag = 1;
			break;
		}
		else { // Si está disponible el espacio a la derecha, se activa el availableRightFlag
			availableRightFlag = 1;
			break;
		}
		break;
	}


	else {
		if (auxLastNode->getRightSummary() == nullptr) { // Si es que no queda camino por la derecha, pasamos a la izquierda
			auxLastNode = auxLastNode->getLeftSummary();
		}
	}
}

// CASO #1: No queda espacio a la derecha el último SummaryNode. Creamos una nueva rama a la derecha para guardar el DataNode y designamos un nuevo root
if (newRootFlag) {
	SummaryNode* newRight = new SummaryNode();
	newRight->setLeftData(newDataNode);
	SummaryNode* newRoot = new SummaryNode();
	newRoot->setLeftSummary(auxRoot);
	newRoot->setRightSummary(newRight);
	root = newRoot;
}

// CASO #2: Queda espacio a la derecha del último SummaryNode
if(availableRightFlag){
	auxLastNode->setRightData(newDataNode);
}
*/