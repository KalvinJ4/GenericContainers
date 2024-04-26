#include "Node.h"
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
Node<T>::Node() {
    this->nextNode = nullptr;
};

template <typename T>
Node<T>::Node(T data) : Box<T>(data) {
    this->nextNode = nullptr;
}

template <typename T>
Node<T>::Node(T data, Node<T>* nextNode) : Box(data, nextNode) {}

template <typename T>
Node<T>::Node(const Node<T>& another) {
    cout << "Node Copy Constructor here." << endl;
    this->data = another.data;
    this->nextNode = another.nextNode;
}

template <typename T>
Node<T>::~Node() {
    std::cout << "Node Destructor here: " << std::endl;
}

template <typename T>
Node<T>* Node<T>::getNextNode() const {
    return this->nextNode;
}

template <typename T>
void Node<T>::setNextNode(Node* next) {
    this->nextNode = next;
}

template <typename T>
bool Node<T>::operator==(const Node<T>& another) {
    return (this->data == another.data && this->nextNode == another.nextNode);
}

template <typename T>
bool Node<T>::operator!=(const Node<T>& another) {
    return  !(*this == another);
}

template <typename T>
ostream& operator<<(ostream& outStream, const Node<T>& c) {
    outStream << c.toString();
    return outStream;
}

template <typename T>
std::string Node<T>::toString() {
    std::ostringstream sout;
    sout << "Node at " << this << std::endl;
    sout << " storing " << sizeof(T) << " bytes of data at " << &(this->data) << std::endl;
    return sout.str();
}