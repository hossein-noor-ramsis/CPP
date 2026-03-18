//
// Created by Hossein on 18/03/2026.
//

#ifndef A1_MATH_H
#define A1_MATH_H
#include <vector>

using namespace std;

class Grade
{
public:
  double gradeValue;
  int weight;

  Grade() = default;
  Grade(double gradeValue, int weight);
};

class Math
{
public:
  static double CalculateGPA(const vector<Grade>& grades);
};

#endif // A1_MATH_H
