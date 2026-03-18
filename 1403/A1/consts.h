//
// Created by Hossein on 16/03/2026.
//

#ifndef A0_03_CONSTS_H
#define A0_03_CONSTS_H

namespace Command
{
  inline auto EXIT = "exit";
  inline auto ADD_OFFERED_COURSES = "add_offered_courses";
  inline auto ADD_TAKEN_COURSES = "add_taken_courses";
  inline auto GET_OFFERED_COURSES = "get_offered_courses";
} // namespace Command

namespace Results
{
  inline auto OK = "OK!";
  inline auto COURSE_NOT_OFFERED = "Course Not Offered!";
  inline auto MINIMUM_UNITS_VALIDATION_FAILED = "Minimum Units Validation Failed!";
  inline auto MAXIMUM_UNITS_VALIDATION_FAILED = "Maximum Units Validation Failed!";
  inline auto COURSE_ALREADY_TAKEN = "Course Already Taken!";
  inline auto PREREQUISITES_NOT_MET = "Prerequisites Not Met!";
} // namespace Results

#endif // A0_03_CONSTS_H
