#include "../../includes/main.hpp"

Task::Task()
{
}

Task::Task(int id, map<string, string> args) : Activity(id, args)
{
  priority = 1;
  time.setHour(stoi(args.at(TaskKey::TIME)));
}

string Task::formattedLog()
{
  string info, details, result;

  info = "task \"" + getTitle() + "\" on " + date.getFormattedDate() + " at " + to_string(time.getHour()) + ":";
  details = " \"" + getDescription() + '\"';

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

Task::~Task()
{
}
