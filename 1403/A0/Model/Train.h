//
// Created by Hossein on 15/03/2026.
//

#ifndef A0_03_TRAIN_H
#define A0_03_TRAIN_H
#include <string>
#include "Time.h"
using namespace std;

class Train {
    string _name;
    string _source;
    string _destination;

    Time _time;
    int _remainingCapacity = 0;

public:
    Train();

    explicit Train(const string &train);

    // Copy constructor
    Train(const Train &other);

    // Overload the assignment operator
    Train &operator=(const Train &other);

    // Overload the compare operators
    bool operator==(const Train &other) const;

    bool operator>(const Train &other) const;

    bool operator<(const Train &other) const;

    string getName() const;

    string getSource() const;

    string getDestination() const;

    Time getTime() const;

    int getRemainingCapacity() const;

    string toString() const;
};

#endif //A0_03_TRAIN_H
