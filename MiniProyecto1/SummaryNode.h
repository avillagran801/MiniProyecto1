#pragma once
#include <iostream>
#include "DataNode.h"
using namespace std;

class SummaryNode{
private:
	int fullCapacity;
	int usedCapacity;
	SummaryNode* leftSummary;
	SummaryNode* rightSummary;
	DataNode* leftData;
	DataNode* rightData;

public:
	SummaryNode();
	int getUsedCapacity();
	int getFullCapacity();
	void updateFullCapacity();
	void setLeftData(DataNode* dataAux);
	void setRightData(DataNode* dataAux);
	void setLeftSummary(SummaryNode* summaryAux);
	void setRightSummary(SummaryNode* summaryAux);
	bool isLevelOne();
};

