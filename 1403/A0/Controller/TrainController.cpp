//
// Created by Hossein on 16/03/2026.
//

#include "TrainController.h"

#include <iostream>

#include "../Utils/String.h"
#include "../View/DefaultView.h"


TrainController::TrainController(DB &db) : _db(db) {
}

void TrainController::addTrain(const vector<string> &body) const {
    _db.trains.insert(Train(String::join(body, ' ')));
    DefaultView::print("Train added successfully!");
}

void TrainController::addTrains(const vector<string> &body) const {
    string train;

    for (int i = 0; i < stoi(body[0]); ++i) {
        getline(cin, train, '\n');
        _db.trains.insert(Train(train));
    }

    DefaultView::print("Trains added successfully!");
}

// STL lists save data objects by copy so if you work with entities there will be a problem
// so you need to work with ptrs too
