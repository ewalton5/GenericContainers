#pragma once
#include <string>
using namespace std;

template <typename T>
class Box {
protected:

    //  The data held by this box
    T data;

public:

    //  Creates a box. The data field is uninitialized.
    Box();

    //  Creates a box containing the specified data.
    Box(T data);

    //  Copy constructor
    Box(const Box<T>& aBox); 

    //  Destructor
    ~Box();

    //  Returns the data held by this box.
    T getData() const;

    //  Stores the specified data in this box. Any data previously
    //  stored in this box is overwritten.
    void setData(T data);

    //  Two boxes are equal if their data attributes are the same
    bool operator==(const Box<T>& another);

    //  Two boxes are not equal if their data atributes are not the same
    bool operator!=(const Box<T>& another);

    //  Returns a string representation of this box.
    string toString() const;
};

template <typename T>
ostream& operator<<(ostream& outStream, const Box<T>& b);