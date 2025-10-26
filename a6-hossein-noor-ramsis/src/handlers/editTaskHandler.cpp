#include "../../includes/main.hpp"

int DataBase::editTaskHandler(Request &req, Response &res)
{
  shared_ptr<User> user = req.getUser();

  bool isDateExist = req.isArgumentExist(TaskKey::DATE);
  bool isTimeExist = req.isArgumentExist(TaskKey::TIME);
  bool isTitleExist = req.isArgumentExist(TaskKey::TITLE);
  bool isDescriptionExist = req.isArgumentExist(TaskKey::DESCRIPTION);

  if (!(isDateExist || isTimeExist || isTitleExist || isDescriptionExist))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (!req.isArgumentExist(TaskKey::TASK_ID))
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  if (user->tasks.find(stoi(req.getArgument(TaskKey::TASK_ID))) == user->tasks.end())
  {
    throw runtime_error(StatusMessage::NOT_FOUND);
  }

  int id = stoi(req.getArgument(TaskKey::TASK_ID));
  shared_ptr<Task> selectedTask = user->tasks.find(stoi(req.getArgument(TaskKey::TASK_ID)))->second;

  map<string, string> initData = selectedTask->initData;

  if (isDateExist)
  {
    initData[TaskKey::DATE] = req.getArgument(TaskKey::DATE);
  }

  if (isTimeExist)
  {
    initData[TaskKey::TIME] = req.getArgument(TaskKey::TIME);
  }

  if (isTitleExist)
  {
    initData[TaskKey::TITLE] = req.getArgument(TaskKey::TITLE);
  }

  if (isDescriptionExist)
  {
    initData[TaskKey::DESCRIPTION] = req.getArgument(TaskKey::DESCRIPTION);
  }

  shared_ptr<Task> editedTask = make_shared<Task>(id, initData);

  user->tasks[id] = editedTask;

  (void)res;
  return 0;
}
