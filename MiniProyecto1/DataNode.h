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
	void add(int number, int pos);
	void setNext(DataNode* auxNext);
	DataNode* getNext();
	int getFullCapacity();
	int getUsedCapacity();
	void printAllLinkedData();
};