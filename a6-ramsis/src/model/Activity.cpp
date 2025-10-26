#include "../../includes/main.hpp"

Activity::Activity()
{
}

Activity::Activity(int id, map<string, string> args)
{

  _id = id;
  _title = args.at(ActivityKey::TITLE);

  if (args.find(ActivityKey::DATE) != args.end())
  {
    date.setDate(args.at(ActivityKey::DATE));
  }

  if (args.find(ActivityKey::DESCRIPTION) != args.end())
  {
    _description = args.at(ActivityKey::DESCRIPTION);
  }

  if (args.find(ActivityKey::START_TIME) != args.end())
  {
    compareTime.setHour(stoi(args.at(ActivityKey::START_TIME)));
  }
  else if (args.find(ActivityKey::TIME) != args.end())
  {
    compareTime.setHour(stoi(args.at(ActivityKey::TIME)));
  }

  initData = args;
}

int Activity::getId()
{
  return _id;
}

void Activity::setId(int num)
{
  _id = num;
}

string Activity::getTitle()
{
  return _title;
}

string Activity::getDescription()
{
  return _description;
}

Activity::~Activity()
{
}
