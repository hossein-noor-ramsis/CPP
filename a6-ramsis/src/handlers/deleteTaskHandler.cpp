#include "../../includes/main.hpp"

int DataBase::deleteTaskHandler(MyRequest &req, MyResponse &res)
{
  shared_ptr<User> user = req.getUser();

  if (!req.isArgumentExist(TaskKey::TASK_ID))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  int taskId = stoi(req.getArgument(TaskKey::TASK_ID));

  if (user->tasks.find(taskId) == user->tasks.end())
  {
    throw runtime_error(StatusMessage::NOT_FOUND);
  }

  user->tasks.erase(taskId);

  (void)res;
  return 0;
}
