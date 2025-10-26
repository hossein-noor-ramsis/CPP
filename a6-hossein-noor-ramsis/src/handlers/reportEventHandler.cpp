#include "../../includes/main.hpp"

int DataBase::reportEventHandler(Request &req, Response &res)
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
  user->addEventsToCalendar(startDate, endDate);

  vector<string> eventsFormattedLog;
  for (auto &event : user->calendar)
  {
    eventsFormattedLog.push_back(event->formattedLog());
  }

  if (eventsFormattedLog.size() == 0)
  {
    throw runtime_error(StatusMessage::EMPTY);
  }

  res.setBody(eventsFormattedLog);

  return 0;
}