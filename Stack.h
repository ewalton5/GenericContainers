#pragma once
#include "Node.h"
#include <string>
using namespace std;

template <typename T>
class Stack {
protected:
    
    //  Pointer to the node at the top of the stack.
    Node<T>* top; 

public:

    //  Creates an empty stack.    
    Stack();

    //  Returns true if and only if this stack contains no data.
    bool isEmpty() const;

    //  Returns the number of data items on this stack.
    int getSize() const;

    //  Copy Constructor
    Stack(const Stack<T>& s);

    //  Destructor
    ~Stack();

    //  Pushes the specified data item onto the top of stack.
    void push(T data);

    //  Pops the data off of the top of the stack. If this stack is empty a
    //  std::runtime_error exception is thrown
    T pop();

    //  Returns the value at the top of the stack, but does not pop that value
    //  off the stack. If this stack is empty a std::runtime_error is thrown.
    T peek() const;

    //  Returns a string representation of this stack.
    string toString() const;
};

template <typename T>
ostream& operator<<(ostream& outStream, const Stack<T>& s);