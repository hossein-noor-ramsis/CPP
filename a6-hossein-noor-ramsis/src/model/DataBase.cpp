#include "../../includes/main.hpp"

DataBase::DataBase()
{
}

int DataBase::generateUserId()
{
  _lastUserId++;
  return _lastUserId;
}

int DataBase::generateJoinEventId()
{
  _lastJoinEventId++;
  return _lastJoinEventId;
}

bool DataBase::isUserExist(string username)
{
  for (auto &&user : _users)
  {
    if (user.second->getUsername() == username)
    {
      return true;
    }
  }

  return false;
}

shared_ptr<User> DataBase::getUser(string username)
{
  shared_ptr<User> selectedUser;

  for (auto &&user : _users)
  {
    if (user.second->getUsername() != username)
    {
      continue;
    }

    selectedUser = user.second;
    break;
  }

  return selectedUser;
}

Date DataBase::getCurrentDate()
{
  return _currentDate.getFormattedDate();
}

set<Date> DataBase::getHolidays()
{
  return _holidays;
}

int DataBase::loadData(vector<vector<string>> data)
{
  for (auto &&i : data)
  {
    Date holiday;

    holiday.setYear(stoi(i[2]));
    holiday.setMonth(stoi(i[1]));
    holiday.setDay(stoi(i[0]));

    _holidays.insert(holiday);
  }

  return 0;
}

bool DataBase::doesEventHaveOverlapWithHolidays(Event event)
{
  for (auto &date : _holidays)
  {
    if (date.getFormattedDate() == event.date.getFormattedDate())
    {
      return true;
    }
  }

  return false;
}

bool DataBase::doesJoinEventHaveOverlapWithHolidays(JoinEvent joinEvent)
{
  for (auto &date : _holidays)
  {
    if (date.getFormattedDate() == joinEvent.date.getFormattedDate())
    {
      return true;
    }
  }

  return false;
}

bool DataBase::doesDailyPeriodicEventHaveOverlapWithHolidays(DailyPeriodicEvent dailyPeriodicEvent)
{
  vector dailyEvents = convertDailyPeriodicEventToEvents(dailyPeriodicEvent);

  for (auto &event : dailyEvents)
  {
    for (auto &date : _holidays)
    {
      if (date.getFormattedDate() == event.date.getFormattedDate())
      {
        return true;
      }
    }
  }

  return false;
}

bool DataBase::doesWeeklyPeriodicEventHaveOverlapWithHolidays(WeeklyPeriodicEvent weeklyPeriodicEvent)
{
  vector weeklyEvents = convertWeeklyPeriodicEventToEvents(weeklyPeriodicEvent);

  for (auto &event : weeklyEvents)
  {
    for (auto &date : _holidays)
    {
      if (date.getFormattedDate() == event.date.getFormattedDate())
      {
        return true;
      }
    }
  }

  return false;
}

bool DataBase::doesMonthlyPeriodicEventHaveOverlapWithHolidays(MonthlyPeriodicEvent monthlyPeriodicEvent)
{
  vector monthlyEvents = convertMonthlyPeriodicEventToEvents(monthlyPeriodicEvent);

  for (auto &event : monthlyEvents)
  {
    for (auto &date : _holidays)
    {
      if (date.getFormattedDate() == event.date.getFormattedDate())
      {
        return true;
      }
    }
  }

  return false;
}

vector<Event> DataBase::convertDailyPeriodicEventToEvents(DailyPeriodicEvent dailyPeriodicEvent)
{
  vector<Event> dailyEvents;

  Date startDate;
  Date endDate;
  int id = 0;

  startDate = dailyPeriodicEvent.startDate;
  endDate = dailyPeriodicEvent.endDate;

  while (startDate <= endDate)
  {
    id = 1;
    dailyPeriodicEvent.initData[EventKey::DATE] = startDate.getFormattedDate();
    Event dailyEvent = Event(id, dailyPeriodicEvent.initData);

    dailyEvents.push_back(dailyEvent);

    startDate.goToNextDay();
  }

  return dailyEvents;
}

vector<Event> DataBase::convertWeeklyPeriodicEventToEvents(WeeklyPeriodicEvent weeklyPeriodicEvent)
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

    id = 1;
    weeklyPeriodicEvent.initData[EventKey::DATE] = startDate.getFormattedDate();
    Event weeklyEvent = Event(id, weeklyPeriodicEvent.initData);

    weeklyEvents.push_back(weeklyEvent);

    startDate.goToNextDay();
  }

  return weeklyEvents;
}

vector<Event> DataBase::convertMonthlyPeriodicEventToEvents(MonthlyPeriodicEvent monthlyPeriodicEvent)
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

    id = 1;
    date = startDate;
    date.setDay(monthlyPeriodicEvent.day);
    monthlyPeriodicEvent.initData[EventKey::DATE] = date.getFormattedDate();
    Event monthlyEvent = Event(id, monthlyPeriodicEvent.initData);

    monthlyEvents.push_back(monthlyEvent);

    startDate.goToNextMonth();
  }

  return monthlyEvents;
}

DataBase::~DataBase()
{
}
