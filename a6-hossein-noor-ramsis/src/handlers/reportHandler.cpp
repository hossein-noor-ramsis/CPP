#include "../../includes/main.hpp"

int DataBase::reportHandler(Request &req, Response &res)
{
  if (!req.isArgumentExist(ReportKey::TO))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (req.isArgumentExist(ReportKey::TYPE))
  {
    if (req.getArgument(ReportKey::TYPE) == ReportType::EVENT)
    {
      reportEventHandler(req, res);
      return 0;
    }
    else if (req.getArgument(ReportKey::TYPE) == ReportType::JOIN_EVENT)
    {
      reportJoinEventHandler(req, res);
      return 0;
    }
    else if (req.getArgument(ReportKey::TYPE) == ReportType::PERIODIC_EVENT)
    {
      reportPeriodicEventHandler(req, res);
      return 0;
    }
    else if (req.getArgument(ReportKey::TYPE) == ReportType::TASK)
    {
      reportTaskHandler(req, res);
      return 0;
    }
    else
    {
      throw runtime_error(StatusMessage::BAD_REQUEST);
    }
  }

  shared_ptr<User> user = req.getUser();
  Date startDate = _currentDate;
  Date endDate = Date(req.getArgument(ReportKey::TO));

  if (req.isArgumentExist(ReportKey::FROM))
  {
    startDate = req.getArgument(ReportKey::FROM);
  }

  user->calendar.clear();
  user->addEventsToCalendar(startDate, endDate);
  user->addJoinEventsToCalendar(startDate, endDate);

  user->addDailyPeriodicEventsToCalendar(startDate, endDate);
  user->addWeeklyPeriodicEventsToCalendar(startDate, endDate);
  user->addMonthlyPeriodicEventsToCalendar(startDate, endDate);

  user->addTasksToCalendar(startDate, endDate);

  vector<string> activitiesFormattedLog;
  for (auto &activity : user->calendar)
  {
    activitiesFormattedLog.push_back(activity->formattedLog());
  }

  if (activitiesFormattedLog.size() == 0)
  {
    throw runtime_error(StatusMessage::EMPTY);
  }

  res.setBody(activitiesFormattedLog);
  return 0;
}