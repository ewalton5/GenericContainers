#include "Node.h"
#include <sstream>
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node() {
    this->nextNode = nullptr;
}

template <typename T>
Node<T>::Node(T data) : Box<T>(data) {}

template <typename T>
Node<T>::Node(T data, Node<T>* nextNode) : Box(data, nextNode) {}

template <typename T>
Node<T>::Node(const Node<T>& aNode) {
    this->data = aNode.data;
    this->nextNode = aNode.nextNode;
}

template <typename T>
Node<T>::~Node() {}

template <typename T>
Node<T>* Node<T>::getNextNode() const {
    return this->nextNode;
}

template <typename T>
void Node<T>::setNextNode(Node* next) {
    this->nextNode = next;
}

template  <typename T>
bool Node<T>::operator==(const Node<T>& another) {
    return (this->data = another.data && this->nextNode == another.nextNode);
}

template  <typename T>
bool Node<T>::operator!=(const Node<T>& another) {

}

template <typename T>
string Node<T>::toString() const {
    ostringstream sout;
    sout << "Node at " << this << endl;
    sout << "   storing " << sizeof(T) << " bytes of data at " << &(this->data) << endl;
    return sout.str();
}

template  <typename T>
ostream& operator<<(ostream& outStream, const Node<T>& n) {
    outStream << n.toString();
    return outStream;
}