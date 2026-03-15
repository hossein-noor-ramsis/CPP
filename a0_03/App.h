//
// Created by Hossein on 15/03/2026.
//

#ifndef A0_03_APP_H
#define A0_03_APP_H
#include <iostream>
#include <ostream>

using namespace std;

class App {
    static App _instance; // Initialized once, thread-safe in C++11+

    App() {
        cout << "App created!" << endl;
    }

public:
    App(const App &) = delete;

    App &operator=(const App &) = delete;

    static App &getInstance() {
        return _instance;
    }

    void run();
};

#endif //A0_03_APP_H
