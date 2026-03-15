//
// Created by Hossein on 15/03/2026.
//

#include "App.h"
#include "consts.h"

App App::_instance; // Definition

// ReSharper disable once CppMemberFunctionMayBeStatic
void App::run() { // NOLINT(*-convert-member-functions-to-static)
    cout << "App Started!" << endl;
    string cmd;

    while (true) {
        getline(cin, cmd, '\n');

        if (cmd == Command::EXIT) {
            break;
        }

        if (cmd == Command::ADD_TRAINS) {
            // addTrains();
        }

        if (cmd == Command::FIND_TICKETS) {
            // buyTickets();
        }
    }

    cout << "App Closed!" << endl;
}
