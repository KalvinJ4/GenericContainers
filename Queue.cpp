#include "Queue.h"
#include <sstream>

using namespace std;

template<typename T>
Queue<T>::Queue() {
    this->lst = new List<T>();
}

template <typename T>
string Queue<T>::toString() {
    std::ostringstream sout;
    sout << "Queue at " << this << std::endl;
    sout << " storing " << sizeof(T) << "bytes of data at" << &(this->data) << std::endl;
    return sout.str();
}

template <typename T>
void Queue<T>::enqueue(T data) {
    this->lst->addAtEnd(data);
}

template<typename T>
T Queue<T>::dequeue() {
    return this->lst->remove(0);
}

template<typename T>
bool Queue<T>::isEmpty() {
    return this->lst->isEmpty();
}

template<typename T>
int Queue<T>::getSize() {
    return this->lst->getSize();
}

template<typename T>
T Queue<T>::peekAtFront() {
    return this->lst->peek(0);
}








