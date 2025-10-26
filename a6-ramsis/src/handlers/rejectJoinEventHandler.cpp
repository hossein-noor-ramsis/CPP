#include "../../includes/main.hpp"

int DataBase::rejectJoinEventHandler(MyRequest &req, MyResponse &res)
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

  user->joinEventsInvitations.erase(inventionId);

  (void)res;
  return 0;
}
