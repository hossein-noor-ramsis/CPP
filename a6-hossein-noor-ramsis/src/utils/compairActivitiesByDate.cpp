#include "../../includes/main.hpp"

bool compareActivitiesByDate(const std::shared_ptr<Activity> &a,
                             const std::shared_ptr<Activity> &b)
{
  return a->date < b->date;
}
