#include "../../includes/main.hpp"

float getRandomFloat(float min, float max)
{
  static random_device rd;
  static mt19937 gen(rd());

  uniform_real_distribution<float> dist(min, max);

  return dist(gen);
}