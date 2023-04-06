#pragma once
using namespace std;

class ListArr{
private:
	// Hay que declarar nodos por aquí
	int capacity;
	int saved;

public:
	int size();
	void insert_left(int v);
	void insert_right(int v);
	void insert(int v, int i);
	void print();
	bool find(int v);
};