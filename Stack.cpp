#include "Stack.h"
#include <sstream>
#include <iostream>
using namespace std;

template <typename T>
Stack<T>::Stack() {
	this->top = nullptr;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return this->top == nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
	this->top = nullptr;
	if (s.top != nullptr) {
		this->top = new Node<T>(*s.top);
		Node<T>* currOrigNode = s.top;
		Node<T>* currCopyNode = this->top;
		while (currOrigNode->getNextNode() != nullptr) {
			Node<T>* nextCopyNode = new Node<T>(*(currOrigNode->getNextNode()));
			currCopyNode->setNextNode(nextCopyNode);
			currCopyNode = nextCopyNode;
			currOrigNode = currOrigNode->getNextNode();
		}
	}
}

template <typename T>
Stack<T>::~Stack() {
	Node<T>* currNode = this->top;
	int cnt = 0;
	while (currNode != nullptr) {
		Node<T>* nextNode = currNode->getNextNode();
		delete currNode;
		currNode = nextNode;
		cnt++;
	}
}

template <typename T>
int Stack<T>::getSize() const {
	if (this->top == nullptr) {
		return 0;
	}
	else {
		Node<T>* currentNode = this->top;
		int count = 1;
		while (currentNode->getNextNode() != nullptr) {
			count++;
			currentNode = currentNode->getNextNode();
		}
		return count;
	}
}

template <typename T>
void Stack<T>::push(T data) {
	if (this->isEmpty()) {
		this->top = new Node<T>(data);
	}
	else {
		Node<T>* newTop = new Node<T>(data);
		newTop->setNextNode(this->top);
		this->top = newTop;
	}
}

template <typename T>
T Stack<T>::pop() {
	if (this->isEmpty()) {
		throw runtime_error("Cannot pop from an empty stack");
	}
	else if (this->getSize() == 1) {
		T result = this->top->getData();
		this->top = nullptr;
		return result;
	}
	else {
		T result = this->top->getData();
		this->top = this->top->getNextNode();
		return result;
	}
}

template <typename T>
T Stack<T>::peek() const {
	if (this->isEmpty()) {
		throw runtime_error("Cannot peek from an empty stack");
	}
	return this->top->getData();
}

template <typename T>
string Stack<T>::toString() const {
	ostringstream sout;
	sout << "Stack at " << this << endl;
	sout << "   This stack is currently storing " << this->getSize() << " items" << endl;
	sout << "   Each item of this stack occupies " << sizeof(T) << " bytes of storage" << endl;
	return sout.str();
}

template  <typename T>
ostream& operator<<(ostream& outStream, const Stack<T>& s) {
	outStream << s.toString();
	return outStream;
}