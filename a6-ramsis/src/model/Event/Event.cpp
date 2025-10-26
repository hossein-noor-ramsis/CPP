#include "../../../includes/main.hpp"

Event::Event()
{
}

Event::Event(int id, map<string, string> args) : EventBase(id, args)
{
  type = EventsType::EVENT;

  duration.setHour(stoi(args.at(EventKey::DURATION)));
  endTime.setHour(startTime.getHour() + duration.getHour());
}

Event::~Event()
{
}
