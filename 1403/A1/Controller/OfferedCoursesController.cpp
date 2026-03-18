//
// Created by Hossein on 18/03/2026.
//

#include "OfferedCoursesController.h"

#include "../Utils/String.h"
#include "../View/DefaultView.h"
#include "../View/ErrorView.h"
#include "../consts.h"

#include <iostream>

#include "../Utils/Math.h"

OfferedCoursesController::OfferedCoursesController(DB& db) : _db(db)
{
}

void OfferedCoursesController::AddOfferedCourses(const vector<string>& body) const
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

void OfferedCoursesController::GetOfferedCourses([[maybe_unused]] const vector<string>& body) const
{
  string coursesNameRaw;
  getline(cin, coursesNameRaw, '\n');

  int units = 0;
  vector<Grade> grades;

  for (const auto& prevCourse : _db.previousTakenCourses)
  {
    auto grade = Grade(prevCourse.Grade().value(), prevCourse.Units());

    grades.push_back(grade);
  }

  const double gpa = Math::CalculateGPA(grades);

  int maxUnitsLimit = 24;
  int minUnitsLimit = 12;

  if (gpa < 12)
  {
    maxUnitsLimit = 14;
  }

  if (gpa < 17)
  {
    maxUnitsLimit = 20;
  }

  const vector<string> coursesNameVec = String::split(coursesNameRaw, ' ');

  for (const auto& courseName : coursesNameVec)
  {
    OfferedCourse offeredCourse;
    offeredCourse.Name(courseName);

    auto offeredCourseIt = _db.offeredCourses.find(offeredCourse);

    if (offeredCourseIt == _db.offeredCourses.end())
    {
      ErrorView::print(Results::COURSE_NOT_OFFERED);
      return;
    }

    for (const auto& pre : offeredCourseIt->Prerequisites())
    {
      TakenCourse takenCourse;
      takenCourse.Name(pre);

      auto takenCourseIt = _db.previousTakenCourses.find(takenCourse);

      if (takenCourseIt == _db.previousTakenCourses.end())
      {
        ErrorView::print(Results::PREREQUISITES_NOT_MET);
        return;
      }
    }

    TakenCourse takenCourse;
    takenCourse.Name(courseName);

    auto prevTakenCourseIt = _db.previousTakenCourses.find(takenCourse);

    if (prevTakenCourseIt != _db.previousTakenCourses.end() && prevTakenCourseIt->Status() == PASSED)
    {
      ErrorView::print(Results::COURSE_ALREADY_TAKEN);
      return;
    }

    units += offeredCourseIt->Units();
  }

  if (units < minUnitsLimit)
  {
    ErrorView::print(Results::MINIMUM_UNITS_VALIDATION_FAILED);
    return;
  }

  if (units > maxUnitsLimit)
  {
    ErrorView::print(Results::MAXIMUM_UNITS_VALIDATION_FAILED);
    return;
  }

  DefaultView::print(Results::OK);
}
