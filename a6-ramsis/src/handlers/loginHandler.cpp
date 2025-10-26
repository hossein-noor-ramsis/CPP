#include "../../includes/main.hpp"

int DataBase::loginHandler(MyRequest &req, MyResponse &res)
{
  shared_ptr<User> user;

  if ((req.getUsername() != "") || (req.getPassword() != ""))
  {
    throw runtime_error(StatusMessage::PERMISSION_DENIED);
  }

  if (!req.isArgumentExist(UserKey::USERNAME))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(UserKey::PASSWORD))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if ((req.getArgument(UserKey::USERNAME) == "") || (req.getArgument(UserKey::PASSWORD) == ""))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!isUserExist(req.getArgument(UserKey::USERNAME)))
  {
    throw runtime_error(StatusMessage::NOT_FOUND);
  }

  user = getUser(req.getArgument(UserKey::USERNAME));

  if (user->getPassword() != req.getArgument(UserKey::PASSWORD))
  {
    throw runtime_error(StatusMessage::PERMISSION_DENIED);
  }

  (void)res;

  return 0;
}
