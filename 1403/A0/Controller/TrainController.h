//
// Created by Hossein on 16/03/2026.
//

#ifndef A0_TRAIN_CONTROLLER_H
#define A0_TRAIN_CONTROLLER_H
#include <vector>

#include "../DB.h"

using namespace std;

class TrainController {
    DB &_db;

public:
    explicit TrainController(DB &db);

    /**
     * add_train <train_name> <source> <destination> <time> <remaining_capacity>
     */
    void addTrain(const vector<string> &body) const;

    /**
     * add_trains 5\n
     * <train_name> <source> <destination> <time> <remaining_capacity>
     */
    void addTrains(const vector<string> &body) const;
};

#endif //A0_TRAIN_CONTROLLER_H
