#include"LinkedList.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList() {
	usedCapacity = 0;
	top = nullptr;
}

void LinkedList::addToTheLeft(int number) {
	Node* newNode = new Node(number);
	Node* aux = top;
	top = newNode;
	newNode->next = aux;
	++usedCapacity;
}

void LinkedList::addToTheRight(int number) {
	Node* newNode = new Node(number);
	if (top != nullptr) {
		Node* current = top;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	else {
		top = newNode;
	}
	++usedCapacity;
}

void LinkedList::add(int number, int pos) {  //Para ser consistentes, igualmente se cuenta desde el 1
	Node* newNode = new Node(number);
	if (pos <= usedCapacity + 1 && pos>=1) {
		if (pos == 1) {
			Node* aux = top;
			top = newNode;
			newNode->next = aux;
		}
		else {
			Node* current = top;
			Node* aux;
			for (int i = 1; i < pos-1; ++i) {
				current = current->next;
			}
			aux = current->next;
			current->next = newNode;
			newNode->next = aux;
			
		}
		++usedCapacity;
	}
	else {
		cout << "Error: Posición inexistente";
		return;
	}
}

bool LinkedList::find(int number) {
	Node* current = top;
	if (current == nullptr) return false;
	while (current->next != nullptr) {
		if (current->data == number) return true;
		else current = current->next;
	}
	if (current->data == number) return true;
	return false;
}

int LinkedList::size() {
	return usedCapacity;
}

void LinkedList::print() {
	cout << "NUMERO DE DATOS INGRESADOS: " << usedCapacity << endl;
	Node* current = top;
	if (current == nullptr) return;
	if (current->next == nullptr) {
		cout << current->data << endl;
		return;
	}
	while (current->next != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
	cout << current->data << endl;
}