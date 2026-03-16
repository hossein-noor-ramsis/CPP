#include <iostream>

#include "App.h"
#include "Controller/TicketController.h"
#include "Controller/TrainController.h"
using namespace std;

int main() {
    DB db;
    App &app = App::build();
    // controllers start
    auto trainController = TrainController(db);
    auto ticketController = TicketController(db);
    // controllers end

    app.run();

    return 0;
}

// fix all fixable errors: Ctrl + .
