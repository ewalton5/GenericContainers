#include "List.h"
#include <sstream>
#include <iostream>
using namespace std;

template <typename T>
List<T>::List() {
	this->mainStack = new Stack<T>();
	this->auxStack = new Stack<T>();
}

template <typename T>
List<T>::List(T data) {
	this->mainStack = new Stack<T>();
	this->auxStack = new Stack<T>();
	this->mainStack->push(data);
}

template <typename T>
List<T>::List(const List<T>& l) {
	this->mainStack = new Stack<T>(*(l.mainStack));
	this->auxStack = new Stack<T>(*(l.auxStack));
}

template <typename T>
List<T>::~List() {
	delete mainStack;
	delete auxStack;
}

template <typename T>
bool List<T>::isEmpty() const {
	return this->mainStack->isEmpty();
}

template <typename T>
int List<T>::getSize() const {
	return this->mainStack->getSize();
}

template <typename T>
void List<T>::addAtEnd(T data) {
	mainStack->push(data);
}

template <typename T>
T List<T>::peek(int ndx) const {
	int num2Pop = getSize() - ndx;
	T result;
	for (int k = 0; k < num2Pop; k++) {
		T data = mainStack->pop();
		auxStack->push(data);
	}
	result = auxStack->peek();
	while (!auxStack->isEmpty()) {
		T data2 = auxStack->pop();
		mainStack->push(data2);
	}
	return result;
}

template <typename T>
void List<T>::insertBefore(int ndx, T data) {
	int num2Pop = getSize() - ndx;
	for (int k = 0; k < num2Pop; k++) {
		T data = mainStack->pop();
		auxStack->push(data);
	}
	mainStack->push(data);
	while (!auxStack->isEmpty()) {
		T data2 = auxStack->pop();
		mainStack->push(data2);
	}
}

template <typename T>
T List<T>::remove(int ndx) {
	int num2Pop = getSize() - ndx;
	T result;
	for (int k = 0; k < num2Pop; k++) {
		T data = mainStack->pop();
		auxStack->push(data);
	}
	result = auxStack->pop();
	while (!auxStack->isEmpty()) {
		T data2 = auxStack->pop();
		mainStack->push(data2);
	}
	return result;
}

template <typename T>
void List<T>::joinBefore(List<T>* suffix) {
	for (int k = 0; k < suffix->getSize(); k++) {
		this->mainStack->push(suffix->peek(k));
	}
}

template <typename T>
List<T>* List<T>::splitBefore(int ndx) {
	int num2Pop = getSize() - ndx;
	List<T>* result = new List<T>();
	for (int k = 0; k < num2Pop; k++) {
		T tempData = this->mainStack->pop();
		result->insertBefore(0, tempData);
	}
	return result;
}

template <typename T>
string List<T>::toString() const {
	ostringstream sout;
	sout << "List at " << this << endl;
	sout << "   This list stores items of size " << sizeof(T) << " bytes" << endl;
	sout << "   This list contains " <<  this->getSize()  << " items" << endl;
	return sout.str();
}

template  <typename T>
ostream& operator<<(ostream& outStream, const List<T>& l) {
	outStream << l.toString();
	return outStream;
}