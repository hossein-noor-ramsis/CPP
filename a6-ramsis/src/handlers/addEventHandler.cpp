#include "../../includes/main.hpp"

int DataBase::addEventHandler(MyRequest &req, MyResponse &res)
{
  shared_ptr<User> user = req.getUser();

  if (!req.isArgumentExist(EventKey::DATE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(EventKey::START_TIME))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(EventKey::DURATION))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (stoi(req.getArgument(EventKey::DURATION)) <= 0)
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(EventKey::TITLE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  int id = user->generateEventId();
  shared_ptr<Event> event = make_shared<Event>(id, req.getArguments());

  if (doesEventHaveOverlapWithHolidays(*event))
  {
    throw runtime_error(StatusMessage::HOLIDAY_FOUND);
  }

  if (user->doseEventHaveOverlapWithEvents(*event))
  {
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (user->doseEventHaveOverlapWithJoinEvents(*event))
  {
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (user->doseEventHaveOverlapWithPeriodicEvents(*event))
  {
    throw runtime_error(StatusMessage::OVERLAP);
  }

  user->events.insert({id, event});

  (void)res;
  return 0;
}
