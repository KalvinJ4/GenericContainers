#include "Pair.h"
#include <sstream>
#include <string>

using namespace std;

template<typename T, typename U>
Pair<T, U>::Pair() {}

template<typename T, typename U>
Pair<T, U>::Pair(T first, U second) {
	this->first = first;
	this->second = second;
}

template<typename T, typename U>
Pair<U, T>* Pair<T, U>::swap() {
	return new Pair<U, T>(this->second, this->first);
}


template<typename T, typename U>
string Pair<T, U>::toString() {
	ostringstream sout;
	sout << "Pair at " << this << endl;
	sout << "First element stores " << sizeof(T) << "bytes of data. " << endl;
	sout << "Second element stores " << sizeof(U) << "bytes of data. " << endl;
	return sout.str();
}