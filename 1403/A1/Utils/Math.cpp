//
// Created by Hossein on 18/03/2026.
//

#include "Math.h"

Grade::Grade(const double gradeValue, const int weight)
{
  this->weight = weight;
  this->gradeValue = gradeValue;
}

double Math::CalculateGPA(const vector<Grade>& grades)
{
  if (grades.empty())
  {
    return 0.0;
  }

  double weightedSum = 0.0;
  double totalWeight = 0.0;

  for (const auto& grade : grades)
  {
    weightedSum += grade.weight * grade.gradeValue;
    totalWeight += grade.weight;
  }

  if (totalWeight == 0.0)
  {
    return 0.0;
  }

  return weightedSum / totalWeight;
}
