#include "../../includes/main.hpp"

int DataBase::addPeriodicEventHandler(MyRequest &req, MyResponse &res)
{
  shared_ptr<User> user = req.getUser();

  if (!req.isArgumentExist(PeriodicEventKey::START_DATE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(PeriodicEventKey::END_DATE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(PeriodicEventKey::START_TIME))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(PeriodicEventKey::DURATION))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (stoi(req.getArgument(PeriodicEventKey::DURATION)) <= 0)
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(PeriodicEventKey::TITLE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(PeriodicEventKey::TYPE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (req.getArgument(PeriodicEventKey::TYPE) == PeriodicEventsType::DAILY)
  {
    int id = user->generateDailyPeriodicEventId();
    shared_ptr<DailyPeriodicEvent> dailyPeriodicEvent = make_shared<DailyPeriodicEvent>(id, req.getArguments());

    if (user->doseDailyPeriodicEventHaveOverlapWithEvents(*dailyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (user->doseDailyPeriodicEventHaveOverlapWithJoinEvents(*dailyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (user->doseDailyPeriodicEventHaveOverlapWithPeriodicEvents(*dailyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (doesDailyPeriodicEventHaveOverlapWithHolidays(*dailyPeriodicEvent))
    {
      res.setStatusMessage(StatusMessage::HOLIDAY_FOUND);
      res.setStatusCode(StatuesCode::CONFLICT);
    }

    dailyPeriodicEvent->saveOverlapDatesWithHolidays(*user, getHolidays());

    user->dailyPeriodicEvents.insert({id, dailyPeriodicEvent});
  }
  else if (req.getArgument(PeriodicEventKey::TYPE) == PeriodicEventsType::WEEKLY)
  {
    if (!req.isArgumentExist(PeriodicEventKey::WEEK_DAYS))
    {
      throw runtime_error(StatusMessage::BAD_REQUEST);
    }

    int id = user->generateWeeklyPeriodicEventId();
    shared_ptr<WeeklyPeriodicEvent> weeklyPeriodicEvent = make_shared<WeeklyPeriodicEvent>(id, req.getArguments());

    if (user->doseWeeklyPeriodicEventHaveOverlapWithEvents(*weeklyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (user->doseWeeklyPeriodicEventHaveOverlapWithJoinEvents(*weeklyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (user->doseWeeklyPeriodicEventHaveOverlapWithPeriodicEvents(*weeklyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (doesWeeklyPeriodicEventHaveOverlapWithHolidays(*weeklyPeriodicEvent))
    {
      res.setStatusMessage(StatusMessage::HOLIDAY_FOUND);
      res.setStatusCode(StatuesCode::CONFLICT);
    }

    weeklyPeriodicEvent->saveOverlapDatesWithHolidays(*user, getHolidays());

    user->weeklyPeriodicEvents.insert({id, weeklyPeriodicEvent});
  }
  else if (req.getArgument(PeriodicEventKey::TYPE) == PeriodicEventsType::MONTHLY)
  {
    if (!req.isArgumentExist(PeriodicEventKey::DAY))
    {
      throw runtime_error(StatusMessage::BAD_REQUEST);
    }

    int id = user->generateMonthlyPeriodicEventId();
    shared_ptr<MonthlyPeriodicEvent> monthlyPeriodicEvent = make_shared<MonthlyPeriodicEvent>(id, req.getArguments());

    if (user->doseMonthlyPeriodicEventHaveOverlapWithEvents(*monthlyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (user->doseMonthlyPeriodicEventHaveOverlapWithJoinEvents(*monthlyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (user->doseMonthlyPeriodicEventHaveOverlapWithPeriodicEvents(*monthlyPeriodicEvent))
    {
      throw runtime_error(StatusMessage::OVERLAP);
    }

    if (doesMonthlyPeriodicEventHaveOverlapWithHolidays(*monthlyPeriodicEvent))
    {
      res.setStatusMessage(StatusMessage::HOLIDAY_FOUND);
      res.setStatusCode(StatuesCode::CONFLICT);
    }

    monthlyPeriodicEvent->saveOverlapDatesWithHolidays(*user, getHolidays());

    user->monthlyPeriodicEvents.insert({id, monthlyPeriodicEvent});
  }
  else
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  (void)res;
  return 0;
}
