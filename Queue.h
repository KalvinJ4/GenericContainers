#pragma once

#include <string>
#include "List.h"

template <typename T>
class Queue {
protected:

    /*
     The list backing up this queue.
     */
    List<T>* lst;

public:

    /*
     Creates an empty queue.
     */
    Queue();

    /*
     Returns true if and only if this queue is empty.
     */
    bool isEmpty();

    /*
     Returns the number of items in the queue.
     */
    int getSize();

    /*
     Adds the specified data to the back of the queue.
     */
    void enqueue(T data);

    /*
     Removes and returns the data at the front of the queue.
     */
    T dequeue();

    /*
     Returns the data at the front of the queue, but does not remove it.
     */
    T peekAtFront();

    /*
     Returns a string representation of this queue.
     */
    std::string toString();

};