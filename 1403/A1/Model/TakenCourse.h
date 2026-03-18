//
// Created by Hossein on 18/03/2026.
//

#ifndef A1_TAKEN_COURSES_H
#define A1_TAKEN_COURSES_H

#include <optional>
#include <string>

using namespace std;

enum CourseStatus
{
  NONE,
  PASSED,
  FAILED,
};

class TakenCourse
{
  string _name;
  int _units = 0;
  optional<double> _grade;
  CourseStatus _status = NONE;

  void CheckStatus();

public:
  TakenCourse() = default;

  TakenCourse(const TakenCourse& other);

  TakenCourse& operator=(const TakenCourse& other);

  friend bool operator==(const TakenCourse& lhs, const TakenCourse& rhs);

  friend bool operator!=(const TakenCourse& lhs, const TakenCourse& rhs);

  friend bool operator<(const TakenCourse& lhs, const TakenCourse& rhs);

  friend bool operator>(const TakenCourse& lhs, const TakenCourse& rhs);

  string Name() const;

  void Name(const string& name);

  int Units() const;

  void Units(int units);

  optional<double> Grade() const;

  void Grade(const double& grade);

  bool IsPassed() const;

  CourseStatus Status() const;
};

#endif // A1_TAKEN_COURSES_H
