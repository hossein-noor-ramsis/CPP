#ifndef JOIN_EVENT_HPP
#define JOIN_EVENT_HPP

class JoinEvent : public EventBase
{
public:
  string hostUsername;
  bool isApprovedAtLeastByOneGuest = false;

  vector<string> guestsNames;
  map<string, bool> isGuestApprovedThisEvent;

public:
  JoinEvent();
  JoinEvent(int id, map<string, string> args, string username);

  ~JoinEvent();
};

#endif
