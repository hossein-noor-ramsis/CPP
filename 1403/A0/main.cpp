#include "App.h"
#include "consts.h"
#include "Controller/TicketController.h"
#include "Controller/TrainController.h"

using namespace std;

int main() {
    DB db;
    App &app = App::build();

    // controllers start
    const auto trainController = TrainController(db);
    const auto ticketController = TicketController(db);
    // controllers end

    // commands start
    app.addCommand(Command::ADD_TRAIN, [&](const vector<string> &body) {
        trainController.addTrain(body);
    });

    app.addCommand(Command::ADD_TRAINS, [&](const vector<string> &body) {
        trainController.addTrains(body);
    });

    app.addCommand(Command::FIND_TICKETS, [&](const vector<string> &body) {
        ticketController.findTicket(body);
    });
    // commands end

    app.run();

    return 0;
}

// fix all fixable errors: Ctrl + .
