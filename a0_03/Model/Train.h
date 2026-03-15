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
    unsigned int _capacity = 0;

public:
    void setName(const string &name);

    string getName() const;

    void setSource(const string &source);

    string getSource() const;

    void setDestination(const string &destination);

    string getDestination() const;

    void setTime(const string &time);

    string getTime() const;

    void setCapacity(const string &capacity);

    string getCapacity() const;
};

#endif //A0_03_TRAIN_H
