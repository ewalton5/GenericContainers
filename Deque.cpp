#include "Deque.h"
#include <sstream>
using namespace std;

template <typename T>
Deque<T>::Deque() {
	this->lst = new List<T>();
}

template <typename T>
bool Deque<T>::isEmpty() {
	return this->lst->isEmpty();
}

template <typename T>
int Deque<T>::getSize() {
	return this->lst->getSize();
}

template <typename T>
void Deque<T>::enqueueFront(T data) {
	this->lst->insertBefore(0 , data);
}

template <typename T>
void Deque<T>::enqueueBack(T data) {
	this->lst->addAtEnd(data);
}

template <typename T>
T Deque<T>::dequeueFront() {
	return this->lst->remove(0);
}

template <typename T>
T Deque<T>::dequeueBack() {
	return this->lst->remove(getSize() - 1);
}

template <typename T>
T Deque<T>::peekAtFront() {
	return this->lst->peek(0);
}

template <typename T>
T Deque<T>::peekAtBack() {
	return this->lst->peek(getSize() - 1);
}

template <typename T>
string Deque<T>::toString() {
	ostringstream sout;
	sout << "Deque at " << this << endl;
	sout << "   This Deque stores items of size " << sizeof(T) << " bytes" << endl;
	sout << "   This Deque contains " << this->getSize() << " items" << endl;
	return sout.str();
}