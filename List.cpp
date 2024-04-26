#include "List.h"
#include <sstream>
#include <iostream>

using namespace std;

template<typename T>
List<T>::List() {
	this->mainStack = new Stack<T>();
	this->auxStack = new Stack<T>();
}

//Copy constructor
template <typename T>
List<T>::List(const List<T>& l) {
	this->mainStack = new Stack<T>(*(l.mainStack));
	this->auxStack = new Stack<T>(*(l.auxStack));
}

//Destructor
template <typename T>
List<T>::~List() {
	    std::cout << "~List here..." << std::endl;
    std::cout << " deleting mainStack..." << std::endl;
	delete mainStack;
	    std::cout << " deleting auxStack..." << std::endl;
	delete auxStack;
}

template<typename T>
int List<T>::getSize() const {
	return this->mainStack->getSize(); 
	}

	template<typename T>
	string List<T>::toString() const {
		ostringstream sout;
		sout << "Stack at" << this << endl;
		sout << "This list stores items at size" << sizeof(T) << "bytes." << endl;
		sout << "This list contains"<< this->getSize() << "items." << endl;
		return sout.str();
	}

	template<typename T>
	bool List<T>::isEmpty() const {
		return this->mainStack->isEmpty();
	}

	template<typename T>
	void List<T>::addAtEnd(T data) {
		mainStack->push(data);
	}

	template<typename T>
	T List<T>::peek(int ndx) const {
		// calculate the number of items to pop
		int num = getSize() - ndx;

		// use a for loop to pop that many items off the main
		// stack and push them onto the aux stack
		for (int j = 0; j < num; j++) { 
			auxStack->push(mainStack->pop()); 
		}
		// use auxStack's peek() function to get the value at the top
		// and store that value in a variable
		T result = auxStack->peek(); 

		// while auxStack is not empty, pop of it and push onto mainStack
		while (!auxStack->isEmpty()) {
			mainStack->push(auxStack->pop());
		}

		// finally return result
		return result;
	}

	template<typename T>
	 void List<T>::insertBefore(int ndx, T data) {
		 int num = getSize() - ndx;

		 for (int j = 0; j < num; j++) {
			 auxStack->push(mainStack->pop());
		 }
		 mainStack->push(data);

		 while (!auxStack->isEmpty()) {
			 mainStack->push(auxStack->pop());
		 }
	 }

	 template<typename T>
	 T List<T>::remove(int ndx) {
		 int num = getSize() - ndx;

		 for (int j = 0; j < num; j++) {
			 auxStack->push(mainStack->pop());
		 }
		
		 T result = auxStack->pop();

		 while (!auxStack->isEmpty()) {
			 mainStack->push(auxStack->pop());
		 }
		 return result;
	 }
	 
	 template<typename T>
	 void List<T>::joinBefore(List<T>* suffix) {
		 for (int k = 0; k < suffix->getSize(); k++) {
			 this->mainStack->push(suffix->peek(k));
		 }
	 }

	 template<typename T>
	 List<T>* List<T>::splitBefore(int ndx) {
		 int numToPop = this->getSize() - ndx;
		 List<T>* result = new List<T>();
		 for (int k = 0; k < numToPop; k++) {
			 T tempData = this->mainStack->pop();
			 result->insertBefore(0, tempData);
		 }
		 return result;
	 }

	 template <typename T>
	 ostream& operator<<(ostream& outStream, const List<T>& c) {
		 outStream << c.toString();
		 return outStream;
	 }
	 