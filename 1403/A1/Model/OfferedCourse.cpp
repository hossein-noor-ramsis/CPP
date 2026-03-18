//
// Created by Hossein on 18/03/2026.
//

#include "OfferedCourse.h"

OfferedCourse::OfferedCourse(const OfferedCourse &other)
{
    _name = other._name;
    _units = other._units;

    for (const auto &prerequisite : other._prerequisites)
    {
        _prerequisites.push_back(prerequisite);
    }
}

OfferedCourse &OfferedCourse::operator=(const OfferedCourse &other)
{
    if (this == &other)
        return *this;

    _name = other._name;
    _units = other._units;
    _prerequisites = other._prerequisites;

    return *this;
}

bool operator==(const OfferedCourse &lhs, const OfferedCourse &rhs)
{
    return lhs._name == rhs._name && lhs._units == rhs._units;
}

bool operator!=(const OfferedCourse &lhs, const OfferedCourse &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const OfferedCourse &lhs, const OfferedCourse &rhs)
{
    return lhs._name < rhs._name;
}

bool operator>(const OfferedCourse &lhs, const OfferedCourse &rhs)
{
    return lhs._name > rhs._name;
}

string OfferedCourse::Name() const
{
    return _name;
}

void OfferedCourse::Name(const string &name)
{
    this->_name = name;
}

int OfferedCourse::Units() const
{
    return _units;
}

void OfferedCourse::Units(const int units)
{
    this->_units = units;
}

vector<string> OfferedCourse::Prerequisites() const
{
    return _prerequisites;
}

void OfferedCourse::Prerequisites(const vector<string> &prerequisites)
{
    this->_prerequisites = prerequisites;
}
