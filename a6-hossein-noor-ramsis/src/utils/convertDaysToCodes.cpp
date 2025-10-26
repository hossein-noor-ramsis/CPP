#include "../../includes/main.hpp"

vector<int> convertDaysToCodes(const vector<string> &days)
{
  map<string, int> dayToCode = {
      {DayOfWeek::FRIDAY, 0},
      {DayOfWeek::SATURDAY, 1},
      {DayOfWeek::SUNDAY, 2},
      {DayOfWeek::MONDAY, 3},
      {DayOfWeek::TUESDAY, 4},
      {DayOfWeek::WEDNESDAY, 5},
      {DayOfWeek::THURSDAY, 6}};

  vector<int> codes;

  for (const auto &day : days)
  {
    auto it = dayToCode.find(day);
    if (it != dayToCode.end())
    {
      codes.push_back(it->second);
    }
    else
    {
      runtime_error(StatusMessage::BAD_REQUEST);
    }
  }

  return codes;
}
