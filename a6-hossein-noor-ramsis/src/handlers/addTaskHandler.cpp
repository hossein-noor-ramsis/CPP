#include "../../includes/main.hpp"

int DataBase::addTaskHandler(Request &req, Response &res)
{
  shared_ptr<User> user = req.getUser();

  if (!req.isArgumentExist(TaskKey::DATE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(TaskKey::TIME))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(TaskKey::TITLE))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  shared_ptr<Task> task = make_shared<Task>(0, req.getArguments());

  int id = user->generateTaskId();
  task->setId(id);

  user->tasks.insert({id, task});

  (void)res;
  return 0;
}
