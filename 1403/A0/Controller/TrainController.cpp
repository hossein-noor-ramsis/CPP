//
// Created by Hossein on 16/03/2026.
//

#include "TrainController.h"

#include <iostream>

#include "../Utils/String.h"


TrainController::TrainController(const DB &db) {
    _db = db;
}

void TrainController::addTrain(const vector<string> &body) {
    _db.trains.insert(Train(String::join(body, ' ')));
}

void TrainController::addTrains(const vector<string> &body) {
    string train;

    for (int i = 0; i < stoi(body[0]); ++i) {
        getline(cin, train, '\n');
        _db.trains.insert(Train());
    }
}

