#ifndef DAILY_PERIODIC_EVENT_HPP
#define DAILY_PERIODIC_EVENT_HPP

#include "../User.hpp"

class DailyPeriodicEvent : public EventBase
{
public:
  Date startDate;
  Date endDate;

  vector<Date> overlapDates;

public:
  DailyPeriodicEvent();
  DailyPeriodicEvent(int id, map<string, string> args);

  int saveOverlapDatesWithEvents(User user);
  int saveOverlapDatesWithJoinEvents(User user);
  int saveOverlapDatesWithPeriodicEvents(User user);
  int saveOverlapDatesWithHolidays(User user, set<Date> holidays);

  ~DailyPeriodicEvent();
};

#endif
