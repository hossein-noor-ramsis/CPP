#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include "./Date.hpp"
#include "./Time.hpp"

class Activity
{
private:
  int _id;
  string _title;

  string _description = "";

public:
  int priority = 10;

  Date date;
  Time compareTime;

public:
  Activity();
  Activity(int id, map<string, string> args);

  map<string, string> initData;

  int getId();
  void setId(int num);

  string getTitle();
  string getDescription();

  virtual string formattedLog() = 0;

  virtual ~Activity();
};

#endif
