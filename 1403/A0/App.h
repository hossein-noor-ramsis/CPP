//
// Created by Hossein on 15/03/2026.
//

#ifndef A0_03_APP_H
#define A0_03_APP_H
#include <functional>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>

#include "DB.h"

using namespace std;

class App {
    static App _instance; // Initialized once, thread-safe in C++11+

    map<string, function<void (const vector<string> &body)> > commands = {};

    App() {
        cout << "App created!" << endl;
    }

public:
    App(const App &) = delete;

    App &operator=(const App &) = delete;

    static App &build();

    void addCommand(const string &name, const function<void (const vector<string> &body)> &callback);

    void run();
};

#endif //A0_03_APP_H
