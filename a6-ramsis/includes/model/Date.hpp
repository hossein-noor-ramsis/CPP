#ifndef DATE_HPP
#define DATE_HPP

class Date
{
private:
  int _year;
  int _month;
  int _day;

public:
  Date();
  Date(string date);

  string getFormattedDate() const;
  int setDate(string date);

  int getYear();
  int getMonth();
  int getDay();

  int setYear(int num);
  int setMonth(int num);
  int setDay(int num);

  int goToNextDay();
  int goToNextMonth();

  bool operator<(const Date &other) const;
  bool operator<=(const Date &other) const;
  bool operator>(const Date & other) const;
  bool operator==(const Date &other) const;

  ~Date();
};

#endif
