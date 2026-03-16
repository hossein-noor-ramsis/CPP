//
// Created by Hossein on 16/03/2026.
//

#ifndef A0_TRAIN_CONTROLLER_H
#define A0_TRAIN_CONTROLLER_H
#include <vector>

#include "../DB.h"

using namespace std;

class TrainController {
    DB _db;

public:
    explicit TrainController(const DB &db);

    void addTrain(const vector<string> &body);

    void addTrains(const vector<string> &body);
};

#endif //A0_TRAIN_CONTROLLER_H
