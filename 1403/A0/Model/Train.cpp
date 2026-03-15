//
// Created by Hossein on 15/03/2026.
//

#include "Train.h"

#include <vector>

#include "../Utils/String.h"

Train::Train(const string &train) {
    const vector<string> parts = String::split(train, ' ');

    _name = parts[0];
    _source = parts[1];
    _destination = parts[2];
    _time = Time(parts[3]);
    _remainingCapacity = stoi(parts[4]);
}

string Train::getName() const {
    return _name;
}

string Train::getSource() const {
    return _source;
}

string Train::getDestination() const {
    return _destination;
}

string Train::getTime() const {
    return _time.getTime();
}

string Train::getRemainingCapacity() const {
    return to_string(_remainingCapacity);
}
