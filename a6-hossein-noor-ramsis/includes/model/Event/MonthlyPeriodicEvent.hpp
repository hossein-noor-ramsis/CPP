#ifndef MONTHLY_PERIODIC_EVENT_HPP
#define MONTHLY_PERIODIC_EVENT_HPP

class MonthlyPeriodicEvent : public EventBase
{
public:
  Date startDate;
  Date endDate;

  vector<Date> overlapDates;

  int day;

public:
  MonthlyPeriodicEvent();
  MonthlyPeriodicEvent(int id, map<string, string> args);

  int saveOverlapDatesWithEvents(User user);
  int saveOverlapDatesWithJoinEvents(User user);
  int saveOverlapDatesWithPeriodicEvents(User user);
  int saveOverlapDatesWithHolidays(User user, set<Date> holidays);

  ~MonthlyPeriodicEvent();
};

#endif
