//
// Created by Hossein on 18/03/2026.
//

#ifndef A1_OFFERED_COURSES_H
#define A1_OFFERED_COURSES_H
#include <string>
#include <vector>

using namespace std;

class OfferedCourse
{
    string _name;
    int _units = 0;
    vector<string> _prerequisites;

  public:
    OfferedCourse() = default;

    OfferedCourse(const OfferedCourse &other);

    OfferedCourse &operator=(const OfferedCourse &other);

    friend bool operator==(const OfferedCourse &lhs, const OfferedCourse &rhs);

    friend bool operator!=(const OfferedCourse &lhs, const OfferedCourse &rhs);

    friend bool operator<(const OfferedCourse &lhs, const OfferedCourse &rhs);

    friend bool operator>(const OfferedCourse &lhs, const OfferedCourse &rhs);

    string Name() const;

    void Name(const string &name);

    int Units() const;

    void Units(int units);

    vector<string> Prerequisites() const;

    void Prerequisites(const vector<string> &prerequisites);
};

#endif // A1_OFFERED_COURSES_H
