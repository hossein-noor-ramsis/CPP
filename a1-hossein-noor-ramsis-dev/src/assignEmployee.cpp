#include "../includes/main.hpp"

int assignEmployee(System &system)
{
  string taskName;
  string employeeName;

  cin >> taskName;
  cin >> employeeName;

  bool isNewTask = true;

  for (auto &task : system.ongoingTasks)
  {
    if (task.name == taskName)
    {
      task.employees.push_back(employeeName);
      isNewTask = false;
      
      break;
    }
  }

  if (isNewTask)
  {
    for (auto &task : system.tasks)
    {
      if (task.name == taskName)
      {
        task.status = "ongoing";
        task.employees.push_back(employeeName);

        system.ongoingTasks.push_back(task);

        break;
      }
    }
  }

  system.tasks.remove_if([&](const Task &t)
                         { return t.name == taskName; });

  for (auto &employee : system.employees)
  {
    if (employee.second.name == employeeName)
    {
      employee.second.ongoingTasks.push_back(taskName);
      break;
    }
  }

  return 0;
}
