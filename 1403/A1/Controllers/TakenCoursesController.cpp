//
// Created by Hossein on 18/03/2026.
//

#include "TakenCoursesController.h"

#include "../Utils/String.h"

#include <iostream>

TakenCoursesController::TakenCoursesController(DB& db) : _db(db)
{
}

void TakenCoursesController::AddTakenCourses(const vector<string>& body) const
{
  const int count = stoi(body[0]);
  string courseRaw;

  for (int i = 0; i < count; ++i)
  {
    TakenCourse course;

    getline(cin, courseRaw, '\n');
    vector<string> courseVec = String::split(courseRaw, ' ');

    course.Name(courseVec[0]);
    course.Units(stoi(courseVec[1]));
    course.Grade(stoi(courseVec[2]));

    _db.previousTakenCourses.insert(course);
  }
}
