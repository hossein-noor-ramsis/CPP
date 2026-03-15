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
    explicit Time(const string &time);

    string getTime() const; // NOLINT(*-use-nodiscard)
};

#endif //A0_03_TIME_H
