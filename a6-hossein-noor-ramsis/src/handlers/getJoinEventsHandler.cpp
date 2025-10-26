#include "../../includes/main.hpp"

int DataBase::getJoinEventHandler(Request &req, Response &res)
{
  shared_ptr<User> user = req.getUser();

  vector<string> joinEventsFormattedLog;
  for (auto &event : user->joinEventsInvitations)
  {
    JoinEvent e = *event.second;
    string result = to_string(e.getId()) + ": " + "\"" + e.getTitle() + "\"" + " - " + e.date.getFormattedDate() + " - " + to_string(e.startTime.getHour()) + " - " + to_string(e.endTime.getHour());
    joinEventsFormattedLog.push_back(result);
  }

  if (joinEventsFormattedLog.size() == 0)
  {
    throw runtime_error(StatusMessage::EMPTY);
  }

  res.setBody(joinEventsFormattedLog);
  return 0;
}
