#pragma once
#include <iostream>
#include <ctime>

/*
 A class that produces a random stream of int values. Use the next() method
 to get the next int from the stream.
 */
class RandomIntStream {
protected:

    // seed of random number generator
    time_t seed;

    // this stream returns values between 0 and maxVal inclusive.
    int maxValue;

public:

    /*
     Creates a RandomIntStream that returns random integers between 0 and
     99. The random number generator is seeded using the current time.
     */
    RandomIntStream() {
        maxValue = 99;
        time(&seed);
        srand((unsigned int)seed);
    }

    /*
     Returns the next int from this stream
     */
    int next() {
        return rand() % (maxValue + 1);
    }

    // Random int stream had more elements, so this always returns true
   
    /*
     Sets the seed of the random number generator
     */
    void setSeed(int seed) {
        this->seed = seed;
        srand((unsigned int)seed);
    }

    /*
     Sets the maximum integer that this stream will produce.
     */
    void setMaxOutput(int maxVal) {
        this->maxValue = maxVal;
    }

    /*
     Returns the maximum integer that this stream will produce.
     */
    int getMaxOutput() {
        return this->maxValue;
    }
};
