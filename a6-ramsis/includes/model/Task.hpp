#ifndef TASK_HPP
#define TASK_HPP

#include "./Date.hpp"
#include "./Time.hpp"

class Task : public Activity
{
private:
public:
  Time time;

public:
  Task();
  Task(int id, map<string, string> args);

  string formattedLog() override;

  ~Task();
};

#endif
