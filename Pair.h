#pragma once
#include <string>

/*
 A templated class to hold paired data. The first and second attributes of the
 pair are public. They may be of different types.
 */
template <typename T, typename U>
class Pair {
public:

    /*
     The first element of the pair.
     */
    T first;

    /*
     The second element of the pair.
     */
    U second;

    /*
     Constructs a pair with undefined contents.
     */
    Pair<T, U>();

    /*
     Constructs a pair and initializes the first and second data members.
     */
    Pair<T, U>(T first, U second);

    /*
     Creates a new pair whose first element is this one's second, and whose
     second element is this one's first.
     */
    Pair<U, T>* swap();

    /*
     Returns a string representation of this pair.
     */
    std::string toString();

};

