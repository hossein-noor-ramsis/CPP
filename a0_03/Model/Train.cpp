//
// Created by Hossein on 15/03/2026.
//

#include "Train.h"

void Train::setName(const string &name) {
    this->_name = name;
}

string Train::getName() const {
    return _name;
}

void Train::setSource(const string &source) {
    this->_source = source;
}

string Train::getSource() const {
    return _source;
}

void Train::setDestination(const string &destination) {
    this->_destination = destination;
}

string Train::getDestination() const {
    return _destination;
}

void Train::setTime(const string &time) {
    this->_time = Time(time);
}

string Train::getTime() const {
    return _time.getTime();
}

void Train::setCapacity(const string &capacity) {
    this->_capacity = stoi(capacity);
}

string Train::getCapacity() const {
    return to_string(_capacity);
}

