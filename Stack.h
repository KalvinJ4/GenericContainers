#pragma once
#include "Node.h"
using namespace std;
/*
 A stack is a chain of nodes with the property that items can only be added or
 removed from one end of the stack, called the "top". The "push" operation
 places data on top of the stack, while the "pop" operation returns the data
 item at the top of the stack and removes that item from the stack. The peek
 operation returns the data item at the top of the stack, but does not remove
 that item from the stack. A stack can be empty.
 */

template <typename T>
class Stack {
protected:
    /*
    Pointer to the node at the top of the stack.
    */
    Node<T>* top;

public:
    
    /*
     Creates an empty stack.
     */
    Stack();

    // Copy Constructor
    Stack(const Stack<T>& s);

    // Destructor
    ~Stack();

    /*
     Returns true if and only if this stack contains no data.
     */
    bool isEmpty() const;

    /*
     Returns the number of data items on this stack.
     */
    int getSize() const;

    /*
     Pushes the specified data item onto the top of stack.
     */
    void push(T data);

    /*
     Pops the data off of the top of the stack. If this stack is empty a
     std::runtime_error exception is thrown
     */
    T pop();

    /*
     Returns the value at the top of the stack, but does not pop that value
     off the stack. If this stack is empty a std::runtime_error is thrown.
     */
    T peek() const;

    /*
     Returns a string representation of this stack.
     */
    std::string toString() const;

};

template <typename T>
ostream& operator<<(std::ostream& outStream, const Stack<T>& c);