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
	LinkedList();//Inicializa la lista sin recibir ning�n par�metro
	void addToTheLeft(int number); //A�ade un n�mero y nodo al inicio de la lista
	void addToTheRight(int number); //A�ade un n�mero y nodo al final de la lista
	void add(int number, int pos); //A�ade un n�mero y nodo en una posici�n dada de la lista
	bool find(int number); //Decide si un n�mero dado se encuentra en la lista
	int size(); //Devuelve la cantidad de elementos en la lista
	void print(); //Muestra en consola la cantidad de elementos y elemntos de la lista
};

