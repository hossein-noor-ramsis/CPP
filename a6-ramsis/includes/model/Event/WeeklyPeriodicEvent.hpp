#ifndef WEEKLY_PERIODIC_EVENT_HPP
#define WEEKLY_PERIODIC_EVENT_HPP

class WeeklyPeriodicEvent : public EventBase
{
public:
  Date startDate;
  Date endDate;

  vector<Date> overlapDates;

  vector<string> weakDays;
  vector<int> weakDaysCode;
  Date currentDate = Date(CURRENT_DATE);

public:
  WeeklyPeriodicEvent();
  WeeklyPeriodicEvent(int id, map<string, string> args);

  bool isDateMatchesWithOneOfWeakDays(Date date);

  int saveOverlapDatesWithEvents(User user);
  int saveOverlapDatesWithJoinEvents(User user);
  int saveOverlapDatesWithPeriodicEvents(User user);
  int saveOverlapDatesWithHolidays(User user, set<Date> holidays);

  ~WeeklyPeriodicEvent();
};

#endif
