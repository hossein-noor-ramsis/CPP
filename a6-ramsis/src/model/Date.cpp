#include "../../includes/main.hpp"

Date::Date()
{
}

Date::Date(string date)
{
  vector<string> splittedDate = splitBySlash(date);

  setDay(stoi(splittedDate[2]));
  setMonth(stoi(splittedDate[1]));
  setYear(stoi(splittedDate[0]));
}

int Date::setDate(string date)
{
  vector<string> splittedDate = splitBySlash(date);

  setDay(stoi(splittedDate[2]));
  setMonth(stoi(splittedDate[1]));
  setYear(stoi(splittedDate[0]));

  return 0;
}

string Date::getFormattedDate() const
{
  string formattedDay = to_string(_day);
  string formattedMonth = to_string(_month);
  string formattedYear = to_string(_year);

  if (to_string(_day).length() < 2)
  {
    formattedDay = "0" + to_string(_day);
  }

  if (to_string(_month).length() < 2)
  {
    formattedMonth = "0" + to_string(_month);
  }

  return formattedYear + "/" + formattedMonth + "/" + formattedDay;
}

int Date::getYear()
{
  return _year;
}

int Date::getMonth()
{
  return _month;
}

int Date::getDay()
{
  return _day;
}

int Date::setYear(int num)
{
  _year = num;
  return 0;
}

int Date::setMonth(int num)
{
  if ((num > 12) || (num < 1))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  _month = num;
  return 0;
}

int Date::setDay(int num)
{
  if ((num > 30) || (num < 1))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  _day = num;
  return 0;
}

int Date::goToNextDay()
{
  if (_day < 30)
  {
    _day++;
    return 0;
  }

  _day = 1;

  if (_month < 12)
  {
    _month++;
    return 0;
  }

  _month = 1;
  _year++;

  return 0;
}

int Date::goToNextMonth()
{
  if (_month < 12)
  {
    _month++;
    return 0;
  }

  _month = 1;
  _year++;

  return 0;
}

bool Date::operator<(const Date &other) const
{
  if (_year != other._year)
  {
    return _year < other._year;
  }

  if (_month != other._month)
  {
    return _month < other._month;
  }

  return _day < other._day;
}

bool Date::operator<=(const Date &other) const
{
  bool condition1 = false;
  bool condition2 = false;

  if (*this < other)
  {
    condition1 = true;
  }

  if (*this == other)
  {
    condition2 = true;
  }

  return condition1 || condition2;
}

bool Date::operator>(const Date &other) const
{
  if (_year != other._year)
  {
    return _year > other._year;
  }

  if (_month != other._month)
  {
    return _month > other._month;
  }

  return _day > other._day;
}

bool Date::operator==(const Date &other) const
{
  if (_year != other._year)
  {
    return false;
  }

  if (_month != other._month)
  {
    return false;
  }

  return _day == other._day;
}

Date::~Date()
{
}
