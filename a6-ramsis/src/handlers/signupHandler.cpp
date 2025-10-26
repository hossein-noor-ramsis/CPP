#include "../../includes/main.hpp"

int DataBase::signupHandler(MyRequest &req, MyResponse &res)
{
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

  if (isUserExist(req.getArgument(UserKey::USERNAME)))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  int id = generateUserId();
  shared_ptr<User> user = make_shared<User>(id, req.getArgument(UserKey::USERNAME), req.getArgument(UserKey::PASSWORD));
  _users.insert({id, user});

  (void)res;

  return 0;
}
