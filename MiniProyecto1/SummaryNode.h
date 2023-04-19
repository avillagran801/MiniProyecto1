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
	void updateUsedCapacity();
	void updateFullCapacity();
	int getNumDataNodes();
	void setLeftData(DataNode* dataAux);
	void setRightData(DataNode* dataAux);
	void setLeftSummary(SummaryNode* summaryAux);
	void setRightSummary(SummaryNode* summaryAux);
	DataNode* getLeftData();
	DataNode* getRightData();
	SummaryNode* getLeftSummary();
	SummaryNode* getRightSummary();
	bool isLastLevel();
	void addToTheLeft(int number);
	void addToTheRight(int number);
	void add(int number, int pos);
	void printEntireArray();
};

