#include "../../includes/main.hpp"

int DataBase::confirmJoinEventHandler(Request &req, Response &res)
{
  shared_ptr<User> user = req.getUser();

  if (!req.isArgumentExist(JoinEventKey::INVITATION_ID))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  int inventionId = stoi(req.getArgument(JoinEventKey::INVITATION_ID));

  if (user->joinEventsInvitations.find(inventionId) == user->joinEventsInvitations.end())
  {
    throw runtime_error(StatusMessage::NOT_FOUND);
  }

  shared_ptr<JoinEvent> joinEvent = user->joinEventsInvitations.at(inventionId);

  if (user->doseJoinEventHaveOverlapWithEvents(*joinEvent))
  {
    user->joinEventsInvitations.erase(inventionId);
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (user->doseJoinEventHaveOverlapWithJoinEvents(*joinEvent))
  {
    user->joinEventsInvitations.erase(inventionId);
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (user->doseJoinEventHaveOverlapWithPeriodicEvents(*joinEvent))
  {
    user->joinEventsInvitations.erase(inventionId);
    throw runtime_error(StatusMessage::OVERLAP);
  }

  if (doesJoinEventHaveOverlapWithHolidays(*joinEvent))
  {
    user->joinEventsInvitations.erase(inventionId);
    throw runtime_error(StatusMessage::HOLIDAY_FOUND);
  }

  joinEvent->isApprovedAtLeastByOneGuest = true;
  joinEvent->isGuestApprovedThisEvent[user->getUsername()] = true;

  user->joinEvents.insert({inventionId, joinEvent});
  user->joinEventsInvitations.erase(inventionId);

  (void)res;
  return 0;
}
