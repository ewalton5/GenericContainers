#pragma once
#include "Stack.h"
#include <string>
using namespace std;

//  A class that sorts an incoming stream of integers using two Stacks.

 class IntStreamSorter {
protected:

    //  the main stack holds the sorted list of integers
    Stack<int>* mainStack;

    //  the auxilliary stack is used for temporary storage when we are adding
    //  a new integer to the main stack.
    Stack<int>* auxStack;

public:

    //  Creates a new IntStreamSorter

     IntStreamSorter() {
        this->mainStack = new Stack<int>();
        this->auxStack = new Stack<int>();
    }

    //  The method takes the input integer n and places it in the main stack in
    //  sorted order.

     void processNext(int n) {
         while (!mainStack->isEmpty() && mainStack->peek() > n) {
             auxStack->push(mainStack->pop());
         }
         mainStack->push(n);
         while (!auxStack->isEmpty()) {
             mainStack->push(auxStack->pop());
         }
     }
    //  This method returns the list of sorted integers as a Stack.
    Stack<int>* getSortedData() {
        return this->mainStack;
    }
};