#ifndef STRUCTS
#define STRUCTS

#include "./model/Activity.hpp"
struct ActivityDateComparator
{
  bool operator()(const std::shared_ptr<Activity> &a,
                  const std::shared_ptr<Activity> &b) const
  {
    if (a->date.getFormattedDate() != b->date.getFormattedDate())
    {
      return a->date < b->date;
    }

    if (a->compareTime.getHour() != b->compareTime.getHour())
    {
      return a->compareTime.getHour() < b->compareTime.getHour();
    }

    if (a->priority != b->priority)
    {
      return a->priority > b->priority;
    }

    return a->getId() < b->getId();
  }
};

typedef struct
{
  bool hasOverlapCheck = false;
} ConvertOptions;

#endif
