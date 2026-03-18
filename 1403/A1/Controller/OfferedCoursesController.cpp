//
// Created by Hossein on 18/03/2026.
//

#include "OfferedCoursesController.h"

#include "../Utils/String.h"

#include <iostream>

OfferedCoursesController::OfferedCoursesController(DB &db) : _db(db)
{
}

void OfferedCoursesController::AddOfferedCourses(const vector<string> &body) const
{
    const int count = stoi(body[0]);
    string courseRaw;

    for (int i = 0; i < count; ++i)
    {
        OfferedCourse course;

        getline(cin, courseRaw, '\n');
        vector<string> courseVec = String::split(courseRaw, ' ');

        course.Name(courseVec[0]);
        course.Units(stoi(courseVec[1]));
        course.Prerequisites(String::split(courseVec[2], ','));

        _db.offeredCourses.insert(course);
    }
}

void OfferedCoursesController::GetOfferedCourses(const vector<string> &body)
{
}