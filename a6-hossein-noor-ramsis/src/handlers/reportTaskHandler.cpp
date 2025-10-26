#include "../../includes/main.hpp"

int DataBase::reportTaskHandler(Request &req, Response &res)
{
  shared_ptr<User> user = req.getUser();
  Date startDate = _currentDate;
  Date endDate = Date(req.getArgument(ReportKey::TO));

  if (req.isArgumentExist(ReportKey::FROM))
  {
    startDate = req.getArgument(ReportKey::FROM);
  }

  user->calendar.clear();
  user->addTasksToCalendar(startDate, endDate);

  vector<string> tasksFormattedLog;
  for (auto &task : user->calendar)
  {
    tasksFormattedLog.push_back(task->formattedLog());
  }

  if (tasksFormattedLog.size() == 0)
  {
    throw runtime_error(StatusMessage::EMPTY);
  }

  res.setBody(tasksFormattedLog);
  return 0;
}