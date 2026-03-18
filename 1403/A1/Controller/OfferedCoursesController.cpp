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

  const vector<string> coursesNameVec = String::split(coursesNameRaw, ' ');

  int units = 0;
  vector<Grade> grades;

  for (const auto& prevCourse : _db.previousTakenCourses)
  {
    auto grade = Grade(prevCourse.Grade().value(), prevCourse.Units());

    grades.push_back(grade);
  }

  const double gpa = Math::CalculateGPA(grades);


  int maxUnitsLimit = 24;
  constexpr int minUnitsLimit = 12;

  if (gpa < 17)
  {
    maxUnitsLimit = 20;
  }

  if (gpa < 12)
  {
    maxUnitsLimit = 14;
  }


  for (const auto& courseName : coursesNameVec)
  {
    //* COURSE_NOT_OFFERED
    auto offeredCourseIt = _db.offeredCourses.find(OfferedCourse(courseName));

    if (offeredCourseIt == _db.offeredCourses.end())
    {
      ErrorView::print(Results::COURSE_NOT_OFFERED);
      return;
    }

    //* PREREQUISITES_NOT_MET
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

    //* COURSE_ALREADY_TAKEN
    auto prevTakenCourseIt = _db.previousTakenCourses.find(TakenCourse(courseName));

    if (prevTakenCourseIt != _db.previousTakenCourses.end() && prevTakenCourseIt->Status() == PASSED)
    {
      ErrorView::print(Results::COURSE_ALREADY_TAKEN);
      return;
    }

    cout << "log: " << offeredCourseIt->Units() << endl;

    units += offeredCourseIt->Units();
  }

  //* MINIMUM_UNITS_VALIDATION_FAILED
  if (units < minUnitsLimit)
  {
    ErrorView::print(Results::MINIMUM_UNITS_VALIDATION_FAILED);
    return;
  }

  //* MAXIMUM_UNITS_VALIDATION_FAILED
  cout << "log: " << units << endl;
  cout << "log: " << maxUnitsLimit << endl;
  cout << "log: " << gpa << endl;

  if (units > maxUnitsLimit)
  {
    ErrorView::print(Results::MAXIMUM_UNITS_VALIDATION_FAILED);
    return;
  }

  //* OK
  for (const auto& courseName : coursesNameVec)
  {
    const auto courseIt = _db.offeredCourses.find(OfferedCourse(courseName));

    TakenCourse course;
    course.Name(courseIt->Name());
    course.Units(course.Units());
    _db.currentTakenCourses.insert(course);
  }

  DefaultView::print(Results::OK);
}
