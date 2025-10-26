#ifndef EVENT_HPP
#define EVENT_HPP

class Event : public EventBase
{
public:
public:
  Event();
  Event(int id, map<string, string> args);

  ~Event();
};

#endif
