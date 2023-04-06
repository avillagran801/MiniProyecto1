#pragma once
#include "SummaryNode.h"
using namespace std;

class ListArr{
private:
	SummaryNode* root;
	int fullCapacity;
	int usedCapacity;

public:
	ListArr(int arrayCapacity);
	int size();
	void insert_left(int v);
	void insert_right(int v);
	void insert(int v, int i);
	void print();
	bool find(int v);
};