#pragma once
#include <iostream>
using namespace std;

class DataNode{
private:
	int fullCapacity;
	int usedCapacity;
	int* data;
	DataNode* next;
public:
	DataNode(int capacity);
	void addToTheLeft(int number);
	int getFullCapacity();
	int getUsedCapacity();
	void printAllLinkedData();
};