//
// Created by Hossein on 16/03/2026.
//

#ifndef A0_DB_H
#define A0_DB_H

#include "Model/OfferedCourse.h"
#include "Model/TakenCourse.h"

#include <set>

using namespace std;

class DB
{
public:
  set<OfferedCourse> offeredCourses;
  set<TakenCourse> previousTakenCourses;
  set<TakenCourse> currentTakenCourses;
};

#endif // A0_DB_H
