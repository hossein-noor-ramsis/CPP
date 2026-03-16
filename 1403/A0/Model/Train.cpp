//
// Created by Hossein on 15/03/2026.
//

#include "Train.h"

#include <vector>

#include "../Utils/String.h"

Train::Train() = default;

Train::Train(const string &train) {
    const vector<string> parts = String::split(train, ' ');

    _name = parts[0];
    _source = parts[1];
    _destination = parts[2];
    _time = Time(parts[3]);
    _remainingCapacity = stoi(parts[4]);
}

Train::Train(const Train &other) {
    this->_name = other.getName();
    this->_source = other.getSource();
    this->_destination = other.getDestination();
    this->_time = Time(other.getTime());
    this->_remainingCapacity = getRemainingCapacity();
}

Train &Train::operator=(const Train &other) {
    if (this != &other) {
        // Check for self-assignment
        _name = other._name;
        _source = other._source;
        _destination = other._destination;
        _time = Time(other._time);
        _remainingCapacity = other._remainingCapacity;
    }

    return *this;
}

bool Train::operator==(const Train &other) const {
    return this->getTime() == other.getTime();
}

bool Train::operator>(const Train &other) const {
    return this->getTime() > other.getTime();
}

bool Train::operator<(const Train &other) const {
    return this->getTime() < other.getTime();
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

Time Train::getTime() const {
    return _time.getTime();
}

int Train::getRemainingCapacity() const {
    return _remainingCapacity;
}
