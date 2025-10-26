#include "../../../includes/main.hpp"

JoinEvent::JoinEvent()
{
}

JoinEvent::JoinEvent(int id, map<string, string> args, string username) : EventBase(id, args)
{
  type = EventsType::JOIN_EVENT;
  hostUsername = username;

  endTime.setHour(stoi(args.at(JoinEventKey::END_TIME)));
  duration.setHour(endTime.getHour() - startTime.getHour());

  guestsNames = splitByComma(args.at(JoinEventKey::GUESTS));

  for (auto &&name : guestsNames)
  {
    isGuestApprovedThisEvent[name] = false;
  }
}

JoinEvent::~JoinEvent()
{
}
