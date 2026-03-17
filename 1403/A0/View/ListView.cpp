//
// Created by Hossein on 17/03/2026.
//

#include "ListView.h"

#include <iostream>

void ListView::print(const vector<string> &messages) {
    // system("cls");

    cout << "=============================================================" << endl;

    for (const auto &message: messages) {
        cout << "* " << message << " *" << endl;
    }

    cout << "=============================================================" << endl;
    cout << "* enter help: to show the help menu, exit: to close the app *\n" << endl;
}
