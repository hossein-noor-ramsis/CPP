#include "../../includes/main.hpp"

int DataBase::addJoinEventHandler(Request &req, Response &res)
{
  shared_ptr<User> user = req.getUser();

  if (!req.isArgumentExist(JoinEventKey::DATE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(JoinEventKey::START_TIME))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(JoinEventKey::END_TIME))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (req.getArgument(JoinEventKey::START_TIME) == req.getArgument(JoinEventKey::END_TIME))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(JoinEventKey::TITLE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(JoinEventKey::GUESTS))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (req.getArgument(JoinEventKey::GUESTS).size() == 0)
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  shared_ptr<JoinEvent> joinEvent = make_shared<JoinEvent>(1, req.getArguments(), user->getUsername());

  if (user->doseJoinEventHaveOverlapWithEvents(*joinEvent))
  {
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (user->doseJoinEventHaveOverlapWithJoinEvents(*joinEvent))
  {
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (user->doseJoinEventHaveOverlapWithPeriodicEvents(*joinEvent))
  {
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (doesJoinEventHaveOverlapWithHolidays(*joinEvent))
  {
    throw runtime_error(StatusMessage::HOLIDAY_FOUND);
  }

  for (auto &gustName : joinEvent->guestsNames)
  {
    if (!isUserExist(gustName))
    {
      throw runtime_error(StatusMessage::NOT_FOUND);
    }
  }

  int id = generateJoinEventId();
  joinEvent->setId(id);

  for (auto &gustName : joinEvent->guestsNames)
  {
    getUser(gustName)->joinEventsInvitations.insert({id, joinEvent});
  }

  user->joinEvents.insert({id, joinEvent});

  (void)res;
  return 0;
}
