//
// Created by Hossein on 18/03/2026.
//

#ifndef A1_TAKEN_COURSES_CONTROLLER_H
#define A1_TAKEN_COURSES_CONTROLLER_H
#include "../DB.h"

class TakenCoursesController
{
    DB &_db;

  public:
    explicit TakenCoursesController(DB &db);

    /**
     * add_taken_courses <int> \n
     * <course_name> <units> <grade>
     */
    void AddTakenCourses(const vector<string> &body) const;
};

#endif // A1_TAKEN_COURSES_CONTROLLER_H
