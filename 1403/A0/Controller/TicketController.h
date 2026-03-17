//
// Created by Hossein on 16/03/2026.
//

#ifndef A0_TICKET_CONTROLLER_H
#define A0_TICKET_CONTROLLER_H
#include <vector>

#include "../DB.h"

using namespace std;

class TicketController {
    DB &_db;

public:
    explicit TicketController(DB &db);

    /**
     * find_ticket <source> <destination> <first_possible_time> <count>
     */
    void findTicket(const vector<string> &body) const;
};


#endif //A0_TICKET_CONTROLLER_H
