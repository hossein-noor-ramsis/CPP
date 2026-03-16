//
// Created by Hossein on 15/03/2026.
//

#ifndef A0_03_TIME_H
#define A0_03_TIME_H
#include <string>
using namespace std;

class Time {
    int _hour = 0;
    int _minute = 0;

public:
    Time();

    explicit Time(const string &time);

    // Overload the compare operators
    bool operator==(const Time &other) const;

    bool operator>(const Time &other) const;

    bool operator<(const Time &other) const;

    string toString() const;

    Time getTime() const;
};

#endif //A0_03_TIME_H
