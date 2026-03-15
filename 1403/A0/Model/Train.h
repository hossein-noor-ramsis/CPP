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
    unsigned int _remainingCapacity = 0;

public:
    explicit Train(const string &train);

    string getName() const;

    string getSource() const;

    string getDestination() const;

    string getTime() const;

    string getRemainingCapacity() const;
};

#endif //A0_03_TRAIN_H
