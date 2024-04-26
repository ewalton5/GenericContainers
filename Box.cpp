#include "Box.h"
#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
Box<T>::Box() {}

template  <typename T>
Box<T>::Box(T data) { 
    this->data = data; 
}

template <typename T>
Box<T>::Box(const Box<T>& aBox) {
    this->data = aBox.data;
}

template <typename T>
Box<T>::~Box() {}

template  <typename T>
T Box<T>::getData() const { 
    return this->data; 
}

template  <typename T>
void Box<T>::setData(T data) { 
    this->data = data; 
}

template  <typename T>
bool Box<T>::operator==(const Box<T>& another) {
    return (this->data == another.data);
}

template  <typename T>
bool Box<T>::operator!=(const Box<T>& another) {
    return !(*this == another);
}

template  <typename T>
string Box<T>::toString() const {
    ostringstream sout;
    sout << "Box at " << this << endl;
    sout << "   storing data of size " << sizeof(T) << " bytes." << endl;
    return sout.str();
}

template  <typename T>
ostream& operator<<(ostream& outStream, const Box<T>& b) {
    outStream << b.toString();
    return outStream;
}