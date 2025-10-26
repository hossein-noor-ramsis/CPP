#include "../../includes/main.hpp"

int generateUniqueId()
{
  static std::atomic<int> id(0);
  return id++;
}