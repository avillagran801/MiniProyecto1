#pragma once
#include <iostream>
using namespace std;

class SummaryNode{
private:
	int fullCapacity;
	int usedCapacity;
	SummaryNode* leftSummary;
	SummaryNode* rightSummary;
};

