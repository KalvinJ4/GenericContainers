#pragma once
#include "Box.h"
using namespace std;

/*
 A node is a generic container that can link to another node.
 */
template <typename T>
class Node : public Box<T> {
protected:

    /*
     The pointer to the node that this one links to.
     */
    Node<T>* nextNode;

public:

    /*
     The default constructor creates an empty node with no successor.
     */
    Node();

    /*
     Creates a node containing the specified data, and whose successor is null.
     */
    Node(T data);

    /*
     Creates a node containing the specied data and with the specified successor.
     */
    Node(T data, Node<T>* nextNode);

    // Copy Constructor
    Node(const Node<T>& original);

    // Class destructor
    ~Node();
    /*
     Returns a pointer to the successor node of this one. A null pointer is returned
     if this node has no successor.
     */
    Node<T>* getNextNode() const;

    /*
     Sets this node's successor to the specified value.
     */
    void setNextNode(Node<T>* next);

    bool operator==(const Node<T>& another);

    bool operator!=(const Node<T>& another);

    /*
     Returns a string representation of this node.
     */
    std::string toString();
};

template <typename T>
ostream& operator<<(std::ostream& outStream, const Node<T>& c);

