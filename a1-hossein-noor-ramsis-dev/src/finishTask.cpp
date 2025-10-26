#include "../includes/main.hpp"

int finishTask(System &system)
{
  string taskName;
  vector<string> taskEmployees;

  cin >> taskName;

  for (auto &task : system.ongoingTasks)
  {
    if (task.name == taskName)
    {
      task.status = "done";
      system.doneTasks.push_back(task);
      // system.ongoingTasks.remove_if([&](Task t)
      //                               { return t.name == taskName; });
      taskEmployees = task.employees;
      break;
    }
  }

  system.ongoingTasks.remove_if([&](Task t)
                                { return t.name == taskName; });

  for (auto &employeeName : taskEmployees)
  {
    for (auto &employee : system.employees)
    {
      if (employee.second.name == employeeName)
      {
        employee.second.countOfDoneTasks++;
        employee.second.ongoingTasks.remove(taskName);
        break;
      }
    }
  }

  return 0;
}
