//
// Created by Hossein on 18/03/2026.
//

#ifndef A1_OFFERED_COURSES_CONTROLLER_H
#define A1_OFFERED_COURSES_CONTROLLER_H

#include "../DB.h"

using namespace std;

class OfferedCoursesController
{
  DB& _db;

public:
  explicit OfferedCoursesController(DB& db);

  /**
   * add_offered_courses <int> \n
   * <course_name> <units> <prerequisites>
   */
  void AddOfferedCourses(const vector<string>& body) const;

  /**
   * get_offered_courses <int_k> \n
   * <course_name_1> <course_name_2> ... <course_name_k>
   */
  void GetOfferedCourses(const vector<string>& body);
};

#endif // A1_OFFERED_COURSES_CONTROLLER_H
