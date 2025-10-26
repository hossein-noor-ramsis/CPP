#include "../../includes/main.hpp"

vector<string> splitWeekDays(const string &input)
{
  vector<string> result;
  stringstream ss(input);
  string day;

  vector<string> weekDays = {DayOfWeek::SATURDAY, DayOfWeek::SUNDAY, DayOfWeek::MONDAY, DayOfWeek::THURSDAY, DayOfWeek::WEDNESDAY, DayOfWeek::TUESDAY, DayOfWeek::FRIDAY};
  bool isWeekDayValid = false;

  while (getline(ss, day, ','))
  {
    isWeekDayValid = false;

    for (auto &weekDay : weekDays)
    {
      if (day == weekDay)
      {
        isWeekDayValid = true;
        break;
      }
    }

    if (!isWeekDayValid)
    {
      throw runtime_error(StatusMessage::BAD_REQUEST);
    }

    result.push_back(day);
  }

  return result;
}
