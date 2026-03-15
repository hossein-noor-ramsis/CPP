//
// Created by Hossein on 15/03/2026.
//

#include "App.h"

// ReSharper disable once CppMemberFunctionMayBeStatic
void App::run() { // NOLINT(*-convert-member-functions-to-static)
    cout << "App Started!" << endl;
    string cmd;

    while (true) {
        getline(cin, cmd, ' ');

        if (cmd == "exit") {
            break;
        }

        if (cmd == "add") {
            // addTrains();
        }

        if (cmd == "buy") {
            // buyTickets();
        }
    }

    cout << "App Closed!" << endl;
}
