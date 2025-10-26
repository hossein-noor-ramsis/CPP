#include "../includes/main.hpp"

int addTask(System &system)
{
  Task task;
  string taskName;
  int priority = 0;

  cin >> taskName;
  cin >> priority;

  task.priority = priority;
  task.name = taskName;
  task.status = "todo";

  system.tasks.push_back(task);

  return 0;
}
