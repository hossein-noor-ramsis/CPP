#include "../../../includes/main.hpp"

DailyPeriodicEvent::DailyPeriodicEvent()
{
}

DailyPeriodicEvent::DailyPeriodicEvent(int id, map<string, string> args) : EventBase(id, args)
{
  type = PeriodicEventsType::DAILY;

  duration.setHour(stoi(args.at(PeriodicEventKey::DURATION)));
  endTime.setHour(startTime.getHour() + duration.getHour());

  startDate = args.at(PeriodicEventKey::START_DATE);
  endDate = args.at(PeriodicEventKey::END_DATE);
}

int DailyPeriodicEvent::saveOverlapDatesWithEvents(User user)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newDailyEvents = user.convertDailyPeriodicEventToEvents(*this);

  for (auto &event : user.events)
  {
    for (auto &e : newDailyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {

        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          overlapDates.push_back(event.second->date);

          break;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          overlapDates.push_back(event.second->date);

          break;
        }
      }
    }
  }

  return 0;
}

int DailyPeriodicEvent::saveOverlapDatesWithJoinEvents(User user)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newDailyEvents = user.convertDailyPeriodicEventToEvents(*this);

  for (auto &event : user.joinEvents)
  {
    for (auto &e : newDailyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {

        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          overlapDates.push_back(event.second->date);

          break;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          overlapDates.push_back(event.second->date);

          break;
        }
      }
    }
  }

  return 0;
}

int DailyPeriodicEvent::saveOverlapDatesWithPeriodicEvents(User user)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newDailyEvents = user.convertDailyPeriodicEventToEvents(*this);

  vector<shared_ptr<Event>> dailyEvents = user.convertDailyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> weeklyEvents = user.convertWeeklyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> monthlyEvents = user.convertMonthlyPeriodicEventsToEvents(ConvertOptions());

  for (auto &event : newDailyEvents)
  {
    for (auto &e : dailyEvents)
    {
      if (e->date.getFormattedDate() == event.date.getFormattedDate())
      {
        condition1 = e->startTime.getHour() < event.endTime.getHour();
        condition2 = event.startTime.getHour() < e->endTime.getHour();

        if (condition1 && condition2)
        {
          overlapDates.push_back(event.date);

          break;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          overlapDates.push_back(event.date);

          break;
        }
      }
    }

    for (auto &e : weeklyEvents)
    {
      if (e->date.getFormattedDate() == event.date.getFormattedDate())
      {
        condition1 = e->startTime.getHour() < event.endTime.getHour();
        condition2 = event.startTime.getHour() < e->endTime.getHour();

        if (condition1 && condition2)
        {
          overlapDates.push_back(event.date);

          break;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          overlapDates.push_back(event.date);

          break;
        }
      }
    }

    for (auto &e : monthlyEvents)
    {
      if (e->date.getFormattedDate() == event.date.getFormattedDate())
      {
        condition1 = e->startTime.getHour() < event.endTime.getHour();
        condition2 = event.startTime.getHour() < e->endTime.getHour();

        if (condition1 && condition2)
        {
          overlapDates.push_back(event.date);

          break;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          overlapDates.push_back(event.date);

          break;
        }
      }
    }
  }

  return 0;
}

int DailyPeriodicEvent::saveOverlapDatesWithHolidays(User user, set<Date> holidays)
{
  vector dailyEvents = user.convertDailyPeriodicEventToEvents(*this);

  for (auto &event : dailyEvents)
  {
    for (auto &date : holidays)
    {
      if (date.getFormattedDate() == event.date.getFormattedDate())
      {
        overlapDates.push_back(date);
        break;
      }
    }
  }

  return 0;
}

DailyPeriodicEvent::~DailyPeriodicEvent()
{
}
