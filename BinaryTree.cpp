#include "BinaryTree.h"
#include <sstream>
#include <cmath>
using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree() {
	this->parent = nullptr;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->label = 0;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getRoot() {
	if (this->parent == nullptr) {
		return this;
	}
	else {
		return this->parent->getRoot();
	}
}

template <typename T>
int BinaryTree<T>::getSize() {
	if (this->leftChild != nullptr && this->rightChild != nullptr) {
		return 1 + this->leftChild->getSize() + this->rightChild->getSize();
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) {
		return 1 + this->leftChild->getSize();
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr) {
		return 1 + this->rightChild->getSize();
	}
	else {
		return 1;
	}
}

template <typename T>
T BinaryTree<T>::getData() {
	return this->data;
}

template <typename T>
void BinaryTree<T>::setData(T data) {
	this->data = data;
}

template <typename T>
bool BinaryTree<T>::hasLeftChild() {
	return this->leftChild != nullptr;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild() {
	return this->leftChild;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::setLeftChild(BinaryTree<T>* bTree) {
	BinaryTree<T>* result = this->leftChild;
	if (this->leftChild != nullptr) {
		this->leftChild->parent = nullptr;
	}
	this->leftChild = bTree;
	if (this->leftChild != nullptr) {
		this->leftChild->parent = this;
	}
	return result;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::removeLeftChild() {
	BinaryTree<T>* result = this->leftChild;
	if (this->leftChild != nullptr) {
		this->leftChild->parent = nullptr;
		this->leftChild = nullptr;
	}
	return result;
}

template <typename T>
bool BinaryTree<T>::hasRightChild() {
	return this->rightChild != nullptr;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild() {
	return this->rightChild;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::setRightChild(BinaryTree<T>* bTree) {
	BinaryTree<T>* result = this->rightChild;
	if (this->rightChild != nullptr) {
		this->rightChild->parent = nullptr;
	}
	this->rightChild = bTree;
	if (this->rightChild != nullptr) {
		this->rightChild->parent = this;
	}
	return result;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::removeRightChild() {
	BinaryTree<T>* result = this->rightChild;
	if (this->rightChild != nullptr) {
		this->rightChild->parent = nullptr;
		this->rightChild = nullptr;
	}
	return result;
}

template <typename T>
bool BinaryTree<T>::hasParent() {
	return this->parent != nullptr;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getParent() {
	return this->parent;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::removeParent() {
	BinaryTree<T>* result = nullptr;
	if (this->parent != nullptr) {
		if (this->parent->leftChild == this) {
			this->parent->leftChild = nullptr;
		}
		else if (this->parent->rightChild == this) {
			this->parent->rightChild = nullptr;
		}
		result = this->parent;
		this->parent = nullptr;
	}
	return result;
}

template <typename T>
List<BinaryTree<T>*>* BinaryTree<T>::parentLastOrdering() {
	List<BinaryTree<T>*>* result = nullptr;
	if (this->leftChild != nullptr && this->rightChild != nullptr) {
		result = this->leftChild->parentLastOrdering();
		result->joinBefore(this->rightChild->parentLastOrdering());
		result->addAtEnd(this);
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) {
		result = this->leftChild->parentLastOrdering();
		result->addAtEnd(this);
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr) {
		result = this->rightChild->parentLastOrdering();
		result->addAtEnd(this);
	}
	else {
		result = new List<BinaryTree<T>*>(this);
	}
	return result;
}

template <typename T>
List<BinaryTree<T>*>* BinaryTree<T>::parentFirstOrdering() {
	List<BinaryTree<T>*>* result = nullptr;
	if (this->leftChild != nullptr && this->rightChild != nullptr) {
		result = this->leftChild->parentFirstOrdering();
		result->joinBefore(this->rightChild->parentFirstOrdering());
		result->insertBefore(0 , this);
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) {
		result = this->leftChild->parentFirstOrdering();
		result->insertBefore(0, this);
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr) {
		result = this->rightChild->parentFirstOrdering();
		result->insertBefore(0, this);
	}
	else {
		result = new List<BinaryTree<T>*>(this);
	}
	return result;
}

template <typename T>
List<BinaryTree<T>*>* BinaryTree<T>::parentMiddleOrdering() {
	List<BinaryTree<T>*>* result = nullptr;
	if (this->leftChild != nullptr && this->rightChild != nullptr) {
		result = leftChild->parentMiddleOrdering();
		result->addAtEnd(this);
		List<BinaryTree<T>*>* rChildOrder = rightChild->parentMiddleOrdering();
		result->joinBefore(rChildOrder);
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) {
		result = this->leftChild->parentMiddleOrdering();
		result->addAtEnd(this);
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr) {
		result = this->rightChild->parentMiddleOrdering();
		result->insertBefore(0, this);
	}
	else {
		result = new List<BinaryTree<T>*>(this);
	}
	return result;
}

template <typename T>
bool BinaryTree<T>::isLeaf() {
	return this->leftChild == nullptr && this->rightChild == nullptr;
}

template <typename T>
int BinaryTree<T>::getLevel() {
	int level = 0;
	BinaryTree<T>* currentVertex = this;
	while (currentVertex->parent != nullptr) {
		level++;
		currentVertex = currentVertex->parent;
	}
	return level;
}

template <typename T>
int BinaryTree<T>::getHeight() {
	if (this->leftChild != nullptr && this->rightChild != nullptr) {
		return 1 + max(this->leftChild->getHeight(), this->rightChild->getHeight());
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) {
		return 1 + this->leftChild->getHeight();
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr) {
		return 1 + this->rightChild->getHeight();
	}
	else {
		return 0;
	}
}

template <typename T>
string BinaryTree<T>::toString() {
	ostringstream sout;
	sout << "BinaryTree at " << this << endl;
	return sout.str();
}