//
// Created by Hossein on 18/03/2026.
//

#include "TakenCourse.h"

TakenCourse::TakenCourse(const TakenCourse &other)
{
    _name = other._name;
    _units = other._units;
    _grade = other._grade;
    _status = other._status;
}

TakenCourse &TakenCourse::operator=(const TakenCourse &other)
{
    if (this == &other)
        return *this;

    _name = other._name;
    _units = other._units;
    _grade = other._grade;
    _status = other._status;

    return *this;
}

bool operator==(const TakenCourse &lhs, const TakenCourse &rhs)
{
    if (lhs._name != rhs._name)
    {
        return false;
    }

    if (lhs._units != rhs._units)
    {
        return false;
    }

    if (lhs._grade != rhs._grade)
    {
        return false;
    }

    if (lhs._name != rhs._name)
    {
        return false;
    }

    return true;
}

bool operator!=(const TakenCourse &lhs, const TakenCourse &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const TakenCourse &lhs, const TakenCourse &rhs)
{
    return lhs._name < rhs._name;
}

bool operator>(const TakenCourse &lhs, const TakenCourse &rhs)
{
    return lhs._name > rhs._name;
}

string TakenCourse::Name() const
{
    return _name;
}

void TakenCourse::Name(const string &name)
{
    _name = name;
}

int TakenCourse::Units() const
{
    return _units;
}

void TakenCourse::Units(const int units)
{
    this->_units = units;
}

optional<double> TakenCourse::Grade() const
{
    return _grade;
}

void TakenCourse::Grade(const double &grade)
{
    _grade = grade;
}

bool TakenCourse::IsPassed() const
{
    return _grade > 10;
}

CourseStatus TakenCourse::Status() const
{
    return _status;
}

void TakenCourse::Status(const CourseStatus &status)
{
    _status = status;
}
