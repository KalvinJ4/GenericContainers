#include "Box.h"
#include <sstream>
#include <iostream>

using namespace std;



template <typename T>
Box<T>::Box() {}

template  <typename T>
Box<T>::Box(T data) { this->data = data; }

template <typename T>
Box<T>::Box(const Box<T>& aBox) {
    cout << "Box copy constructor here: " << endl;
    this->data = aBox.data;
}

template <typename T>
Box<T>::~Box() {
    std::cout << "Box destructor here:" << std::endl; 
}

template  <typename T>
T Box<T>::getData() const { return this->data; }

template  <typename T>
void Box<T>::setData(T data) { this->data = data; }

template <typename T>
bool Box<T>::operator==(const Box<T>& another) {
    cout << "Box<T>::operator== here:" << endl;
    return (this->data == another.data);
}

template <typename T>
bool Box<T>::operator!=(const Box<T>& another) {
    return !(*this == another);
}


template <typename T>
ostream& operator<<(ostream& outStream, const Box<T>& c) {
    outStream << c.toString();
    return outStream;
}


template  <typename T>
std::string Box<T>::toString() {
    std::ostringstream sout;
    sout << "Box at " << this << std::endl;
    sout << " storing data of size " << sizeof(T) << " bytes." << std::endl;
    return sout.str();
}






