//
// Created by Hossein on 16/03/2026.
//

#include "TicketController.h"

#include <algorithm>

#include "../View/ListView.h"

TicketController::TicketController(DB &db) : _db(db) {
}

void TicketController::findTicket(const vector<string> &body) const {
    const string &source = body[0];
    const string &destination = body[1];
    const auto firstPossibleTime = Time(body[2]);
    const int count = stoi(body[3]);

    auto trains = vector(_db.trains.begin(), _db.trains.end());

    vector<Train> filteredTrains;

    ranges::copy_if(trains, back_inserter(filteredTrains), [&](const Train &train) {
        if (train.getSource() != source) {
            return false;
        }

        if (train.getDestination() != destination) {
            return false;
        }

        if (train.getTime() < firstPossibleTime) {
            return false;
        }

        if (train.getRemainingCapacity() < count) {
            return false;
        }

        return true;
    });

    vector<string> formatedFilteredTrains;

    for (const auto &train: filteredTrains) {
        formatedFilteredTrains.push_back(train.toString());
    }

    ListView::print(formatedFilteredTrains);
}
