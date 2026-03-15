//
// Created by Hossein on 15/03/2026.
//

#include "Time.h"

#include <sstream>
#include <stdexcept>
#include <vector>

#include "../Utils/String.h"

Time::Time() = default;

Time::Time(const string &time) {
    const vector<string> parts = String::split(time, ':');

    const int hour = stoi(parts[0]);
    const int minute = stoi(parts[1]);

    if (hour < 0 || hour > 23) {
        throw invalid_argument("in Time -> hour: min(0), max(23);");
    }

    if (minute < 0 || minute > 59) {
        throw invalid_argument("in Time -> minute: min(0), max(59);");
    }

    _hour = hour;
    _minute = minute;
}

string Time::getTime() const {
    string hour = to_string(_hour);
    string minute = to_string(_minute);

    if (_hour < 10) {
        hour = "0" + to_string(_hour);
    }

    if (_minute < 10) {
        minute = "0" + to_string(_minute);
    }

    return hour + ":" + minute;
}
