#include "Queue.h"
#include <sstream>
using namespace std;

template <typename T>
Queue<T>::Queue() {
	this->lst = new List<T>();
}

template <typename T>
bool Queue<T>::isEmpty() {
	return this->lst->isEmpty();
}

template <typename T>
int Queue<T>::getSize() {
	return this->lst->getSize();
}

template <typename T>
void Queue<T>::enqueue(T data) {
	this->lst->addAtEnd(data);
}

template <typename T>
T Queue<T>::dequeue() {
	return this->lst->remove(0);
}

template <typename T>
T Queue<T>::peekAtFront() {
	return this->lst->peek(0);
}

template <typename T>
string Queue<T>::toString() {
	ostringstream sout;
	sout << "Queue at " << this << endl;
	sout << "   This Queue stores items of size " << sizeof(T) << " bytes" << endl;
	sout << "   This Queue contains " << this->getSize() << " items" << endl;
	return sout.str();
}