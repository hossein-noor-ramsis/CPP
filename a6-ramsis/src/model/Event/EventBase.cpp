#include "../../../includes/main.hpp"

EventBase::EventBase()
{
}

EventBase::EventBase(int id, map<string, string> args) : Activity(id, args)
{
  startTime.setHour(stoi(args.at(EventKey::START_TIME)));
}

string EventBase::formattedLog()
{
  string info, details, result;

  if (type == EventsType::EVENT)
  {
    info = "event \"" + getTitle() + "\" on " + date.getFormattedDate() + " from " + to_string(startTime.getHour()) + " for " + to_string(duration.getHour()) + " hours:";
    details = " \"" + getDescription() + '\"';
  }
  else if (type == EventsType::JOIN_EVENT)
  {
    string hostName = dynamic_cast<JoinEvent *>(this)->hostUsername;

    info = "join_event \"" + getTitle() + "\" on " + date.getFormattedDate() + " from " + to_string(startTime.getHour()) + " to " + to_string(endTime.getHour()) + " hosted by " + "\"" + hostName + "\"" + ":";
    details = " \"" + getDescription() + '\"';
  }
  else
  {
    info = "periodic_event \"" + getTitle() + "\" on " + date.getFormattedDate() + " from " + to_string(startTime.getHour()) + " for " + to_string(duration.getHour()) + " hours " + type + ":";
    details = " \"" + getDescription() + "\"";
  }

  if (getDescription().size() == 0)
  {
    result = info;
  }
  else
  {
    result = info + details;
  }

  return result;
}

EventBase::~EventBase()
{
}
