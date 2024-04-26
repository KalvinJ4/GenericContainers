#include <sstream>
#include "BinaryTree.h"

using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree() {
	this->parent = nullptr;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->label = 0;
}

template <typename T>
string BinaryTree<T>::toString() {
	ostringstream sout;
	sout << "BinaryTree at " << this << endl;
	return sout.str();
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getRoot() {
	if (this->parent == nullptr) {
		return this;
	}
	else {
		return this->parent->getRoot();
	}
}

template <typename T>
bool BinaryTree<T>::hasLeftChild() {
	return this->leftChild != nullptr;
}

template <typename T>
bool BinaryTree<T>::hasRightChild() {
	return this->rightChild != nullptr;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild() {
	return this->leftChild;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild() {
	return this->rightChild;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::setLeftChild(BinaryTree<T>* bTree) {
	BinaryTree<T>* result = this->leftChild;
	// if there is an actual left child
	if (this->leftChild != nullptr) {
		// then set its parent attribute to nullptr
		this->leftChild->parent = nullptr;
	}
	// set the input tree  as the left child of this one
	this->leftChild = bTree;
	// if we actually have a new left child
	if (this->leftChild != nullptr) {
		// set its parent attribute to point to this binary tree
		this->leftChild->parent = this;
	}
	return result;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::setRightChild(BinaryTree<T>* bTree) {
	BinaryTree<T>* result = this->rightChild;
	// if there is an actual left child
	if (this->rightChild != nullptr) {
		// then set its parent attribute to nullptr
		this->rightChild->parent = nullptr;
	}
	// set the input tree  as the left child of this one
	this->rightChild = bTree;
	// if we actually have a new left child
	if (this->rightChild != nullptr) {
		// set its parent attribute to point to this binary tree
		this->rightChild->parent = this;
	}
	return result;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::removeLeftChild() {
	BinaryTree<T>* result = this->leftChild;
	if (this->leftChild != nullptr) {
		//remove this binary tree as the parent of the left child
		this->leftChild->parent = nullptr;
		//remove left child from this binary tree
		this->leftChild = nullptr;
	}

	return result;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::removeRightChild() {
	BinaryTree<T>* result = this->rightChild;
	if (this->rightChild != nullptr) {
		//remove this binary tree as the parent of the right child
		this->rightChild->parent = nullptr;
		//remove right child from this binary tree
		this->rightChild = nullptr;
	}

	return result;
}

template <typename T>
int BinaryTree<T>::getSize() {
	if (this->leftChild != nullptr && this->rightChild != nullptr) {
		return 1 + this->leftChild->getSize() + this->rightChild->getSize();
	}
	else if (this->leftChild != nullptr && this->rightChild == nullptr) {
		return 1 + this->leftChild->getSize();
	}
	else if (this->leftChild == nullptr && this->rightChild != nullptr) {
		return 1 + this->rightChild->getSize();
	}
	else {
		return 1;
	}
}

	template <typename T>
	T BinaryTree<T>::getData() {
		return this->data;
	}

	template <typename T>
	void BinaryTree<T>::setData(T data) {
		this->data = data; 
	}

	template <typename T>
	bool BinaryTree<T>::hasParent() {
		return this->parent != nullptr;
	}

	template <typename T>
	BinaryTree<T>* BinaryTree<T>::getParent() {
		if (this->parent != nullptr) {
			return this->parent;
		}
		else {
			this->parent = nullptr;
		}
	}

	template <typename T>
	List<BinaryTree<T>*>* BinaryTree<T>::parentLastOrdering() {
		List<BinaryTree<T>*>* result = new List<BinaryTree<T>*>();
		if (this->leftChild == nullptr && this->rightChild == nullptr) {
			//result = new List<BinaryTree<T>*>(this);
			result->addAtEnd(this);
		}
		else if (this->leftChild != nullptr && this->rightChild == nullptr) {
			result = this->leftChild->parentLastOrdering();
			result->addAtEnd(this);
		}
		else if (this->leftChild == nullptr && this->rightChild != nullptr) {
			result = this->rightChild->parentLastOrdering();
			result->addAtEnd(this);
		}
		else {
			result = this->leftChild->parentLastOrdering();
			result->joinBefore(this->rightChild->parentLastOrdering());
			result->addAtEnd(this);
		}
		return result;
	}

	template <typename T>
	List<BinaryTree<T>*>* BinaryTree<T>::parentFirstOrdering() {
		List<BinaryTree<T>*>* result = new List<BinaryTree<T>*>();
		if (this->leftChild != nullptr && this->rightChild != nullptr) {
			//result = new List<BinaryTree<T>*>(this);
			result->addAtEnd(this);
			result->joinBefore(this->leftChild->parentFirstOrdering());
			result->joinBefore(this->rightChild->parentFirstOrdering());
		}
		else if (this->leftChild != nullptr && this->rightChild == nullptr) {
			result->addAtEnd(this);
			result->joinBefore(this->leftChild->parentFirstOrdering());
		}
		else if (this->leftChild == nullptr && this->rightChild != nullptr) {
			result = this->rightChild->parentFirstOrdering();
			result->joinBefore(this->rightChild->parentFirstOrdering());
		}
		else {
			result->addAtEnd(this);
		}
		return result;
	}

	template <typename T>
	List<BinaryTree<T>*>* BinaryTree<T>::parentMiddleOrdering() {
		List<BinaryTree<T>*>* result = new List<BinaryTree<T>*>();
		if (this->leftChild != nullptr && this->rightChild != nullptr) {
			result = this->leftChild->parentMiddleOrdering();
			result->addAtEnd(this);
			result->joinBefore(this->rightChild->parentMiddleOrdering());
		}
		else if (this->leftChild != nullptr && this->rightChild == nullptr) {
			result = this->leftChild->parentMiddleOrdering();
			result->addAtEnd(this->rightChild);
		}
		else if (this->leftChild == nullptr && this->rightChild != nullptr) {
			result->addAtEnd(this);
			result->joinBefore(this->rightChild->parentMiddleOrdering());
		}
		else {
			result->addAtEnd(this);
		}
		return result;
	}

	template <typename T>
	bool BinaryTree<T>::isLeaf() {
		return this->leftChild == nullptr && this->rightChild == nullptr;
	}

	template <typename T>
	int BinaryTree<T>::getLevel() {
		int level = 0;
		BinaryTree<T>* currentVertex = this;
		while (currentVertex->parent != nullptr) {
			level++;
			currentVertex = currentVertex->parent;
		}
		return level;
	}

	template <typename T>
	int BinaryTree<T>::getHeight() {
		if (this->leftChild != nullptr && this->rightChild != nullptr) {
			return 1 + max(this->leftChild->getHeight(), this->rightChild->getHeight());
		}
		else if (this->leftChild != nullptr && this->rightChild == nullptr) {
			return 1 + this->leftChild->getHeight();
		}
		else if (this->leftChild == nullptr && this->rightChild != nullptr) {
			return 1 + this->rightChild->getHeight();
		}
		else {
			return 0;
		}
	}

	/*
 Sets the parent attribute of this tree to nullptr (the empty tree),
 and returns the old parent, minus this tree.
 */
	template <typename T>
	BinaryTree<T>* BinaryTree<T>::removeParent() {
		// storage to return the parent
		BinaryTree<T>* result = nullptr;
		if (this->parent != nullptr) {
			// clean up the parent tree
			if (this->parent->leftChild == this) {
				// remove the left child from the parent
				this->parent->leftChild = nullptr;
			}
			else if (this->parent->rightChild == this) {
				// remove the right child from the parent
				this->parent->rightChild = nullptr;
			}
			// save the parent tree to return
			result = this->parent;
			// remove this tree's parent
			this->parent = nullptr;
		}
		// return the parent tree
		return result;
	}
