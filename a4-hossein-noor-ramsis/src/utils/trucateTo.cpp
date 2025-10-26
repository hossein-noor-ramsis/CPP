#include "../../includes/main.hpp"

double truncateTo(double value, int decimals)
{
  double factor = pow(10.0, decimals);
  return floor(value * factor) / factor;
}
