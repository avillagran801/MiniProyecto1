#include"Array.h"
#include<iostream>

using namespace std;

Array::Array(int capacity) {
	data = new int[capacity];
	fullCapacity = capacity;
	usedCapacity = 0;
}

void Array::addToTheLeft(int number) { 
	if (usedCapacity + 1 <= fullCapacity) {
		for (int i = 0; i < fullCapacity; i++) {
			data[fullCapacity - i] = data[fullCapacity - i - 1];
		}
		data[0] = number;
		++usedCapacity;
	}
	else {
		cout << "Error: Arreglo Lleno";
		return;
	}
}

void Array::addToTheRight(int number) {
	if (usedCapacity + 1 <= fullCapacity) {
		for (int i = 0; i <= fullCapacity - usedCapacity; i++) {
			data[fullCapacity - i] = data[fullCapacity - i - 1];
		}
		data[usedCapacity] = number;
		++usedCapacity;
	}
	else {
		cout << "Error: Arreglo Lleno";
		return;
	}
}

void Array::add(int number, int pos) { //Para ser consistentes, igualmente se cuenta desde el 1
	if (usedCapacity + 1 <= fullCapacity && usedCapacity >= pos-1) {
		for (int i = 0; i <= fullCapacity - pos; i++) {
			data[fullCapacity - i] = data[fullCapacity - i - 1];
		}
		data[pos-1] = number;
		++usedCapacity;
	}
	else {
		cout << "Error: Arreglo Lleno";
		return;
	}
}

bool Array::find(int number) {
	for (int i = 0; i < usedCapacity; ++i) {
		if (data[i] == number) return true;
	}
	return false;
}

int Array::size(){
	return usedCapacity;
}

void Array::print() {
	cout << "NUMERO DE DATOS INGRESADOS: " << usedCapacity << endl;
	for (int i = 0; i < usedCapacity; ++i) {
		cout << data[i] << endl;
	}
}