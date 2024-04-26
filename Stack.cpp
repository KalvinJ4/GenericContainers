
#include <iostream>
#include <sstream>
#include "Stack.h"

using namespace std;

// Implement the default constructor
template <typename T> 
Stack<T>::Stack() {
	this->top = nullptr;

}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
	this->top = nullptr;
	if (s.top != nullptr) {
		this->top = new Node<T>(*s.top);
		Node<T>* currOrigNode = s.top;
		Node<T>* currCopyNode = this->top;
		while (currOrigNode->getNextNode() != nullptr) {
			Node<T>* nextCopyNode = new Node<T>(*(currOrigNode->getNextNode()));
			currCopyNode->setNextNode(nextCopyNode);
			currCopyNode = nextCopyNode;
			currOrigNode = currOrigNode->getNextNode();
		}
	}
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
	    std::cout << "~Stack() here:" << std::endl;
	Node* currNode = this->top;
	int cnt = 0;
	while (currNode != nullptr) {
		Node* nextNode = currNode->getNextNode();
		delete currNode;
		currNode = nextNode;
		cnt++;
	}
}

// Implement isEmpty()
template <typename T>
bool Stack<T>::isEmpty() const {
	return this->top == nullptr;
}

// Implement getSize()
template <typename T>
int Stack<T>::getSize() const {
	if (this->top == nullptr) {
		return 0;
	}
	else {
		Node<T>* currentNode = this->top;
		int count = 1;
		while (currentNode->getNextNode() != nullptr) {
			count++;
			currentNode = currentNode->getNextNode();
		}
		return count;
	}
	
}

// Implementation of push(T data)
template <typename T>
void Stack<T>::push(T data) {
	if (this->isEmpty()) {
		// create top node, store data in it
		this->top = new Node<T>(data);
	}
	else {
		// create a node, put data in it. The new node's next node pointer should point to the current top of the stack. Then we set the top to point to the newly created code.
		Node<T>* newTop = new Node<T>(data);
		newTop->setNextNode(this->top);
		this->top = newTop;
	}
}

// implement pop()
template<typename T>
T Stack<T>::pop() {
	if (this->isEmpty()) {
		// error situation
		throw runtime_error("Cannot pop from an empty stack!");
	}
	else if(this->getSize() == 1) {
		// grab data off the top, then set top = nullptr
		T result = this->top->getData();
		this->top = nullptr;
		return result;
	}
	else {
		// grab data off the top, then set top to point to top->getNextNode()
		T result = this->top->getData();
		this->top = this->top->getNextNode();
		return result;
	}
}

template<typename T>
T Stack<T>::peek() const {
	if (this->isEmpty()) {
		// error situation
		throw runtime_error("Cannot pop from an empty stack!");
	}
	else {
		// grab data off the top, then set top to point to top->getNextNode()
		return this->top->getData();
		
	}
}

template <typename T>
ostream& operator<<(ostream& outStream, const Stack<T>& c) {
	outStream << c.toString();
	return outStream;
}

template<typename T>
string Stack<T>::toString() const {
	ostringstream sout;
	sout << "Stack at" << this << endl;
	sout << "This stack is currently storing" << this->getSize() << "items." << endl;
	sout << "Each item on this stack occupies" << sizeof(T) << "bytes of storage." << endl;
}