#pragma once

class LinkedList {
private:
	int usedCapacity;
	struct Node
	{	
		Node(int number) {
			data = number;
			next = nullptr;
		}
		int data;
		Node* next;
	};
	Node* top;
public:
	LinkedList();
	void addToTheLeft(int number);
	void addToTheRight(int number);
	void add(int number, int pos);
	bool find(int number);
	int size();
	void print();
};