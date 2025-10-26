#include "../../includes/main.hpp"

User::User()
{
}

User::User(int id, string username, string password)
{
  _id = id;
  _username = username;
  _password = password;
}

string User::getUsername()
{
  return _username;
}

string User::getPassword()
{
  return _password;
}

int User::generateTaskId()
{
  _lastTaskId++;
  return _lastTaskId;
}

int User::generateEventId()
{
  _lastEventId++;
  return _lastEventId;
}

int User::generateDailyPeriodicEventId()
{
  _lastDailyPeriodicEventId++;
  return _lastDailyPeriodicEventId;
}

int User::generateWeeklyPeriodicEventId()
{
  _lastWeeklyPeriodicEventId++;
  return _lastWeeklyPeriodicEventId;
}

int User::generateMonthlyPeriodicEventId()
{
  _lastMonthlyPeriodicEventId++;
  return _lastMonthlyPeriodicEventId;
}

vector<shared_ptr<Event>> User::convertDailyPeriodicEventsToEvents(ConvertOptions options)
{
  vector<shared_ptr<Event>> dailyEvents;

  Date startDate;
  Date endDate;
  int id = 0;

  for (auto &dailyPeriodicEvent : dailyPeriodicEvents)
  {
    startDate = dailyPeriodicEvent.second->startDate;
    endDate = dailyPeriodicEvent.second->endDate;

    while (startDate <= endDate)
    {
      if (options.hasOverlapCheck)
      {
        bool isOverlapDate = false;

        for (auto &overlapDate : dailyPeriodicEvent.second->overlapDates)
        {
          if (startDate.getFormattedDate() == overlapDate.getFormattedDate())
          {
            isOverlapDate = true;
            break;
          }
        }

        if (isOverlapDate)
        {
          startDate.goToNextDay();
          continue;
        }
      }

      id = generateEventId();
      dailyPeriodicEvent.second->initData[PeriodicEventKey::DATE] = startDate.getFormattedDate();
      shared_ptr<Event> dailyEvent = make_shared<Event>(id, dailyPeriodicEvent.second->initData);

      dailyEvents.push_back(dailyEvent);

      startDate.goToNextDay();
    }
  }

  return dailyEvents;
}

vector<shared_ptr<Event>> User::convertWeeklyPeriodicEventsToEvents(ConvertOptions options)
{
  vector<shared_ptr<Event>> weeklyEvents;

  Date startDate;
  Date endDate;
  int id = 0;

  for (auto &weeklyPeriodicEvent : weeklyPeriodicEvents)
  {
    startDate = weeklyPeriodicEvent.second->startDate;
    endDate = weeklyPeriodicEvent.second->endDate;

    while (startDate <= endDate)
    {
      if (!weeklyPeriodicEvent.second->isDateMatchesWithOneOfWeakDays(startDate))
      {
        startDate.goToNextDay();
        continue;
      }

      if (options.hasOverlapCheck)
      {
        bool isOverlapDate = false;

        for (auto &overlapDate : weeklyPeriodicEvent.second->overlapDates)
        {
          if (startDate.getFormattedDate() == overlapDate.getFormattedDate())
          {
            isOverlapDate = true;
            break;
          }
        }

        if (isOverlapDate)
        {
          startDate.goToNextDay();
          continue;
        }
      }

      id = generateEventId();
      weeklyPeriodicEvent.second->initData[PeriodicEventKey::DATE] = startDate.getFormattedDate();
      shared_ptr<Event> weeklyEvent = make_shared<Event>(id, weeklyPeriodicEvent.second->initData);

      weeklyEvents.push_back(weeklyEvent);

      startDate.goToNextDay();
    }
  }

  return weeklyEvents;
}

vector<shared_ptr<Event>> User::convertMonthlyPeriodicEventsToEvents(ConvertOptions options)
{
  vector<shared_ptr<Event>> monthlyEvents;

  Date startDate;
  Date endDate;
  Date date;
  int id = 0;

  for (auto &monthlyPeriodicEvent : monthlyPeriodicEvents)
  {
    startDate = monthlyPeriodicEvent.second->startDate;
    endDate = monthlyPeriodicEvent.second->endDate;

    while (startDate <= endDate)
    {
      if ((startDate.getYear() == endDate.getYear() && (startDate.getMonth() == endDate.getMonth())))
      {
        if (endDate.getDay() < monthlyPeriodicEvent.second->day)
        {
          startDate.goToNextMonth();
          continue;
        }
      }

      if (startDate.getMonth() == monthlyPeriodicEvent.second->startDate.getMonth())
      {
        if (startDate.getDay() > monthlyPeriodicEvent.second->day)
        {
          startDate.goToNextMonth();
          continue;
        }
      }

      if (options.hasOverlapCheck)
      {
        bool isOverlapDate = false;

        for (auto &overlapDate : monthlyPeriodicEvent.second->overlapDates)
        {
          if (startDate.getFormattedDate() == overlapDate.getFormattedDate())
          {
            isOverlapDate = true;
            break;
          }
        }

        if (isOverlapDate)
        {
          startDate.goToNextMonth();
          continue;
        }
      }

      id = generateEventId();
      date = startDate;
      date.setDay(monthlyPeriodicEvent.second->day);
      monthlyPeriodicEvent.second->initData[PeriodicEventKey::DATE] = date.getFormattedDate();
      shared_ptr<Event> monthlyEvent = make_shared<Event>(id, monthlyPeriodicEvent.second->initData);

      monthlyEvents.push_back(monthlyEvent);

      startDate.goToNextMonth();
    }
  }

  return monthlyEvents;
}

vector<Event> User::convertDailyPeriodicEventToEvents(DailyPeriodicEvent dailyPeriodicEvent)
{
  vector<Event> dailyEvents;

  Date startDate;
  Date endDate;
  int id = 0;

  startDate = dailyPeriodicEvent.startDate;
  endDate = dailyPeriodicEvent.endDate;

  while (startDate <= endDate)
  {
    id = generateEventId();
    dailyPeriodicEvent.initData[PeriodicEventKey::DATE] = startDate.getFormattedDate();
    Event dailyEvent = Event(id, dailyPeriodicEvent.initData);

    dailyEvents.push_back(dailyEvent);

    startDate.goToNextDay();
  }

  return dailyEvents;
}

vector<Event> User::convertWeeklyPeriodicEventToEvents(WeeklyPeriodicEvent weeklyPeriodicEvent)
{
  vector<Event> weeklyEvents;

  Date startDate;
  Date endDate;
  int id = 0;

  startDate = weeklyPeriodicEvent.startDate;
  endDate = weeklyPeriodicEvent.endDate;

  while (startDate <= endDate)
  {
    if (!weeklyPeriodicEvent.isDateMatchesWithOneOfWeakDays(startDate))
    {
      startDate.goToNextDay();
      continue;
    }

    id = generateEventId();
    weeklyPeriodicEvent.initData[PeriodicEventKey::DATE] = startDate.getFormattedDate();
    Event weeklyEvent = Event(id, weeklyPeriodicEvent.initData);

    weeklyEvents.push_back(weeklyEvent);

    startDate.goToNextDay();
  }

  return weeklyEvents;
}

vector<Event> User::convertMonthlyPeriodicEventToEvents(MonthlyPeriodicEvent monthlyPeriodicEvent)
{
  vector<Event> monthlyEvents;

  Date startDate;
  Date endDate;
  Date date;
  int id = 0;

  startDate = monthlyPeriodicEvent.startDate;
  endDate = monthlyPeriodicEvent.endDate;

  while (startDate <= endDate)
  {
    if ((startDate.getYear() == endDate.getYear() && (startDate.getMonth() == endDate.getMonth())))
    {
      if (endDate.getDay() < monthlyPeriodicEvent.day)
      {
        startDate.goToNextMonth();
        continue;
      }
    }

    if (startDate.getMonth() == monthlyPeriodicEvent.startDate.getMonth())
    {
      if (startDate.getDay() > monthlyPeriodicEvent.day)
      {
        startDate.goToNextMonth();
        continue;
      }
    }

    id = generateEventId();
    date = startDate;
    date.setDay(monthlyPeriodicEvent.day);
    monthlyPeriodicEvent.initData[PeriodicEventKey::DATE] = date.getFormattedDate();
    Event monthlyEvent = Event(id, monthlyPeriodicEvent.initData);

    monthlyEvents.push_back(monthlyEvent);

    startDate.goToNextMonth();
  }

  return monthlyEvents;
}

bool User::doseEventHaveOverlapWithEvents(Event event)
{
  bool condition1 = false;
  bool condition2 = false;

  for (auto &e : events)
  {
    if (e.second->date.getFormattedDate() == event.date.getFormattedDate())
    {
      condition1 = e.second->startTime.getHour() < event.endTime.getHour();
      condition2 = event.startTime.getHour() < e.second->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e.second->startTime.getHour() == event.startTime.getHour();
      condition2 = e.second->endTime.getHour() == event.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  return false;
}

bool User::doseEventHaveOverlapWithJoinEvents(Event event)
{
  bool condition1 = false;
  bool condition2 = false;

  for (auto &e : joinEvents)
  {
    if (e.second->date.getFormattedDate() == event.date.getFormattedDate())
    {
      condition1 = e.second->startTime.getHour() < event.endTime.getHour();
      condition2 = event.startTime.getHour() < e.second->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e.second->startTime.getHour() == event.startTime.getHour();
      condition2 = e.second->endTime.getHour() == event.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  return false;
}

bool User::doseEventHaveOverlapWithPeriodicEvents(Event event)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<shared_ptr<Event>> dailyEvents = convertDailyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> weeklyEvents = convertWeeklyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> monthlyEvents = convertMonthlyPeriodicEventsToEvents(ConvertOptions());

  for (auto &e : dailyEvents)
  {
    if (e->date.getFormattedDate() == event.date.getFormattedDate())
    {
      condition1 = e->startTime.getHour() < event.endTime.getHour();
      condition2 = event.startTime.getHour() < e->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e->startTime.getHour() == event.startTime.getHour();
      condition2 = e->endTime.getHour() == event.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
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
        return true;
      }

      condition1 = e->startTime.getHour() == event.startTime.getHour();
      condition2 = e->endTime.getHour() == event.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
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
        return true;
      }

      condition1 = e->startTime.getHour() == event.startTime.getHour();
      condition2 = e->endTime.getHour() == event.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  return false;
}

bool User::doseJoinEventHaveOverlapWithEvents(JoinEvent joinEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  for (auto &e : events)
  {
    if (e.second->date.getFormattedDate() == joinEvent.date.getFormattedDate())
    {
      condition1 = e.second->startTime.getHour() < joinEvent.endTime.getHour();
      condition2 = joinEvent.startTime.getHour() < e.second->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e.second->startTime.getHour() == joinEvent.startTime.getHour();
      condition2 = e.second->endTime.getHour() == joinEvent.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  return false;
}

bool User::doseJoinEventHaveOverlapWithJoinEvents(JoinEvent joinEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  for (auto &e : joinEvents)
  {
    if (e.second->date.getFormattedDate() == joinEvent.date.getFormattedDate())
    {
      condition1 = e.second->startTime.getHour() < joinEvent.endTime.getHour();
      condition2 = joinEvent.startTime.getHour() < e.second->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e.second->startTime.getHour() == joinEvent.startTime.getHour();
      condition2 = e.second->endTime.getHour() == joinEvent.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  return false;
}

bool User::doseJoinEventHaveOverlapWithPeriodicEvents(JoinEvent joinEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<shared_ptr<Event>> dailyEvents = convertDailyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> weeklyEvents = convertWeeklyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> monthlyEvents = convertMonthlyPeriodicEventsToEvents(ConvertOptions());

  for (auto &e : dailyEvents)
  {
    if (e->date.getFormattedDate() == joinEvent.date.getFormattedDate())
    {
      condition1 = e->startTime.getHour() < joinEvent.endTime.getHour();
      condition2 = joinEvent.startTime.getHour() < e->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e->startTime.getHour() == joinEvent.startTime.getHour();
      condition2 = e->endTime.getHour() == joinEvent.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  for (auto &e : weeklyEvents)
  {
    if (e->date.getFormattedDate() == joinEvent.date.getFormattedDate())
    {
      condition1 = e->startTime.getHour() < joinEvent.endTime.getHour();
      condition2 = joinEvent.startTime.getHour() < e->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e->startTime.getHour() == joinEvent.startTime.getHour();
      condition2 = e->endTime.getHour() == joinEvent.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  for (auto &e : monthlyEvents)
  {
    if (e->date.getFormattedDate() == joinEvent.date.getFormattedDate())
    {
      condition1 = e->startTime.getHour() < joinEvent.endTime.getHour();
      condition2 = joinEvent.startTime.getHour() < e->endTime.getHour();

      if (condition1 && condition2)
      {
        return true;
      }

      condition1 = e->startTime.getHour() == joinEvent.startTime.getHour();
      condition2 = e->endTime.getHour() == joinEvent.endTime.getHour();

      if (condition1 || condition2)
      {
        return true;
      }
    }
  }

  return false;
}

bool User::doseDailyPeriodicEventHaveOverlapWithEvents(DailyPeriodicEvent dailyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newDailyEvents = convertDailyPeriodicEventToEvents(dailyPeriodicEvent);

  for (auto &event : events)
  {
    for (auto &e : newDailyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {
        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseDailyPeriodicEventHaveOverlapWithJoinEvents(DailyPeriodicEvent dailyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newDailyEvents = convertDailyPeriodicEventToEvents(dailyPeriodicEvent);

  for (auto &event : joinEvents)
  {
    for (auto &e : newDailyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {
        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseDailyPeriodicEventHaveOverlapWithPeriodicEvents(DailyPeriodicEvent dailyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newDailyEvents = convertDailyPeriodicEventToEvents(dailyPeriodicEvent);

  vector<shared_ptr<Event>> dailyEvents = convertDailyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> weeklyEvents = convertWeeklyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> monthlyEvents = convertMonthlyPeriodicEventsToEvents(ConvertOptions());

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
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
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
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
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
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseWeeklyPeriodicEventHaveOverlapWithEvents(WeeklyPeriodicEvent weeklyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newWeeklyEvents = convertWeeklyPeriodicEventToEvents(weeklyPeriodicEvent);

  for (auto &event : events)
  {
    for (auto &e : newWeeklyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {
        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseWeeklyPeriodicEventHaveOverlapWithJoinEvents(WeeklyPeriodicEvent weeklyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newWeeklyEvents = convertWeeklyPeriodicEventToEvents(weeklyPeriodicEvent);

  for (auto &event : joinEvents)
  {
    for (auto &e : newWeeklyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {
        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseWeeklyPeriodicEventHaveOverlapWithPeriodicEvents(WeeklyPeriodicEvent weeklyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newWeeklyEvents = convertWeeklyPeriodicEventToEvents(weeklyPeriodicEvent);

  vector<shared_ptr<Event>> dailyEvents = convertDailyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> weeklyEvents = convertWeeklyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> monthlyEvents = convertMonthlyPeriodicEventsToEvents(ConvertOptions());

  for (auto &event : newWeeklyEvents)
  {
    for (auto &e : dailyEvents)
    {
      if (e->date.getFormattedDate() == event.date.getFormattedDate())
      {
        condition1 = e->startTime.getHour() < event.endTime.getHour();
        condition2 = event.startTime.getHour() < e->endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
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
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
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
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseMonthlyPeriodicEventHaveOverlapWithEvents(MonthlyPeriodicEvent monthlyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newMonthlyEvents = convertMonthlyPeriodicEventToEvents(monthlyPeriodicEvent);

  for (auto &event : events)
  {
    for (auto &e : newMonthlyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {
        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseMonthlyPeriodicEventHaveOverlapWithJoinEvents(MonthlyPeriodicEvent monthlyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newMonthlyEvents = convertMonthlyPeriodicEventToEvents(monthlyPeriodicEvent);

  for (auto &event : joinEvents)
  {
    for (auto &e : newMonthlyEvents)
    {
      if (e.date.getFormattedDate() == event.second->date.getFormattedDate())
      {
        condition1 = e.startTime.getHour() < event.second->endTime.getHour();
        condition2 = event.second->startTime.getHour() < e.endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e.startTime.getHour() == event.second->startTime.getHour();
        condition2 = e.endTime.getHour() == event.second->endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

bool User::doseMonthlyPeriodicEventHaveOverlapWithPeriodicEvents(MonthlyPeriodicEvent monthlyPeriodicEvent)
{
  bool condition1 = false;
  bool condition2 = false;

  vector<Event> newMonthlyEvents = convertMonthlyPeriodicEventToEvents(monthlyPeriodicEvent);

  vector<shared_ptr<Event>> dailyEvents = convertDailyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> weeklyEvents = convertWeeklyPeriodicEventsToEvents(ConvertOptions());
  vector<shared_ptr<Event>> monthlyEvents = convertMonthlyPeriodicEventsToEvents(ConvertOptions());

  for (auto &event : newMonthlyEvents)
  {
    for (auto &e : dailyEvents)
    {
      if (e->date.getFormattedDate() == event.date.getFormattedDate())
      {
        condition1 = e->startTime.getHour() < event.endTime.getHour();
        condition2 = event.startTime.getHour() < e->endTime.getHour();

        if (condition1 && condition2)
        {
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
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
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
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
          return true;
        }

        condition1 = e->startTime.getHour() == event.startTime.getHour();
        condition2 = e->endTime.getHour() == event.endTime.getHour();

        if (condition1 || condition2)
        {
          return true;
        }
      }
    }
  }

  return false;
}

int User::addEventsToCalendar(Date startDate, Date endDate)
{
  for (auto &event : events)
  {
    if (event.second->date > endDate)
    {
      continue;
    }

    if (event.second->date < startDate)
    {
      continue;
    }

    calendar.insert(event.second);
  }

  return 0;
}

int User::addJoinEventsToCalendar(Date startDate, Date endDate)
{
  for (auto &event : joinEvents)
  {
    if (event.second->date > endDate)
    {
      continue;
    }

    if (event.second->date < startDate)
    {
      continue;
    }

    if (event.second->hostUsername == getUsername())
    {
      if (!event.second->isApprovedAtLeastByOneGuest)
      {
        continue;
      }
    }
    else
    {
      if (!event.second->isGuestApprovedThisEvent[getUsername()])
      {
        continue;
      }
    }

    calendar.insert(event.second);
  }

  return 0;
}

int User::addDailyPeriodicEventsToCalendar(Date startDate, Date endDate)
{
  ConvertOptions convertOptions = ConvertOptions();
  convertOptions.hasOverlapCheck = true;

  vector<shared_ptr<Event>> dailyEvents = convertDailyPeriodicEventsToEvents(convertOptions);
  for (auto &&e : dailyEvents)
  {

    if (e->date > endDate)
    {
      continue;
    }

    if (e->date < startDate)
    {
      continue;
    }

    e->type = PeriodicEventsType::DAILY;

    calendar.insert(e);
  }

  return 0;
}

int User::addWeeklyPeriodicEventsToCalendar(Date startDate, Date endDate)
{
  ConvertOptions convertOptions = ConvertOptions();
  convertOptions.hasOverlapCheck = true;

  vector<shared_ptr<Event>> weeklyEvents = convertWeeklyPeriodicEventsToEvents(convertOptions);
  for (auto &&e : weeklyEvents)
  {
    if (e->date > endDate)
    {
      continue;
    }

    if (e->date < startDate)
    {
      continue;
    }

    e->type = PeriodicEventsType::WEEKLY;

    calendar.insert(e);
  }

  return 0;
}

int User::addMonthlyPeriodicEventsToCalendar(Date startDate, Date endDate)
{
  ConvertOptions convertOptions = ConvertOptions();
  convertOptions.hasOverlapCheck = true;

  vector<shared_ptr<Event>> monthlyEvents = convertMonthlyPeriodicEventsToEvents(convertOptions);
  for (auto &&e : monthlyEvents)
  {
    if (e->date > endDate)
    {
      continue;
    }

    if (e->date < startDate)
    {
      continue;
    }

    e->type = PeriodicEventsType::MONTHLY;

    calendar.insert(e);
  }

  return 0;
}

int User::addTasksToCalendar(Date startDate, Date endDate)
{
  for (auto &&task : tasks)
  {
    if (task.second->date > endDate)
    {
      continue;
    }

    if (task.second->date < startDate)
    {
      continue;
    }

    calendar.insert(task.second);
  }

  return 0;
}

User::~User()
{
}
