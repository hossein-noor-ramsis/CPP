#include "../../includes/main.hpp"

Time::Time()
{
}

Time::Time(int num)
{
  if ((num > 23) || (num < 0))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  _hour = num;
}

int Time::getHour()
{
  return _hour;
}

int Time::setHour(int num)
{
  if ((num > 23) || (num < 0))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  _hour = num;
  return 0;
}

Time::~Time()
{
}
