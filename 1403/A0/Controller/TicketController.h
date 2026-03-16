//
// Created by Hossein on 16/03/2026.
//

#ifndef A0_TICKET_CONTROLLER_H
#define A0_TICKET_CONTROLLER_H
#include "../DB.h"


class TicketController {
    DB _db;

public:
    explicit TicketController(const DB &db);
};


#endif //A0_TICKET_CONTROLLER_H
