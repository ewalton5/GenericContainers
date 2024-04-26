#pragma once
#include "Box.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
class Node : public Box<T> {
protected:
    
    //  The pointer to the node that this one links to.
    Node<T>* nextNode; 

public:

    //  The default constructor creates an empty node with no successor.
    Node();

    //  Creates a node containing the specified data, and whose successor is null.
    Node(T data);

    //  Creates a node containing the specied data and with the specified successor.
    Node(T data, Node<T>* nextNode);

    //  Copy constructor
    Node(const Node<T>& aNode);

    //  Destructor
    ~Node();

    //  Returns a pointer to the successor node of this one. A null pointer is returned
    //  if this node has no successor.
    Node<T>* getNextNode() const;

    //  Sets this node's successor to the specified value.
    void setNextNode(Node<T>* next);

    //  Two nodes are equal if their data attributes are the same
    bool operator==(const Node<T>& another);

    //  Two nodes are not equal if their data attributes are not the same
    bool operator!=(const Node<T>& another);

    //  Returns a string representation of this node.
    string toString() const;
};

template <typename T>
ostream& operator<<(ostream& outStream, const Node<T>& n);