#ifndef EVENT_BASE_HPP
#define EVENT_BASE_HPP

class EventBase : public Activity
{
public:
  string type;

  Time startTime;
  Time endTime;
  Time duration;

public:
  EventBase();
  EventBase(int id, map<string, string> args);

  string formattedLog() override;

  virtual ~EventBase();
};

#endif
