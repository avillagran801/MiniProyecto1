#pragma once

class Array {
private:
	int fullCapacity;
	int usedCapacity;
	int* data;

public:
	Array(int capacity);
	void addToTheLeft(int number);
	void addToTheRight(int number);
	void add(int number, int pos);
	bool find(int number);
	int size();
	void print();
};