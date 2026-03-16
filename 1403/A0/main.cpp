#include "App.h"
#include "consts.h"
#include "Controller/TicketController.h"
#include "Controller/TrainController.h"

using namespace std;

int main() {
    const DB db;
    App &app = App::build();

    // controllers start
    auto trainController = TrainController(db);
    auto ticketController = TicketController(db);
    // controllers end

    // commands start
    app.addCommand(Command::ADD_TRAIN, [&](const vector<string> &body) {
        trainController.addTrain(body);
    });

    // commands end


    app.run();

    return 0;
}

// fix all fixable errors: Ctrl + .
