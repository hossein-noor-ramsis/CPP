#include "../../includes/main.hpp"

int DataBase::reportJoinEventHandler(Request &req, Response &res)
{
  shared_ptr<User> user = req.getUser();
  Date startDate = _currentDate;
  Date endDate = Date(req.getArgument(ReportKey::TO));
  multiset<shared_ptr<Activity>, ActivityDateComparator> calendar;

  if (req.isArgumentExist(ReportKey::FROM))
  {
    startDate = req.getArgument(ReportKey::FROM);
  }

  user->calendar.clear();
  user->addJoinEventsToCalendar(startDate, endDate);

  vector<string> joinEventsFormattedLog;
  for (auto &event : user->calendar)
  {
    joinEventsFormattedLog.push_back(event->formattedLog());
  }

  if (joinEventsFormattedLog.size() == 0)
  {
    throw runtime_error(StatusMessage::EMPTY);
  }

  res.setBody(joinEventsFormattedLog);

  return 0;
}