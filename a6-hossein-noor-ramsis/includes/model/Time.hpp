#ifndef TIME_HPP
#define TIME_HPP

class Time
{
private:
  int _hour;

public:
  Time();
  Time(int num);
  
  int getHour();
  int setHour(int num);
  
  ~Time();
};

#endif