#include "../includes/main.hpp"

int reportOngoing(const System &system)
{
  set<Task, CompareTask> ongoingTasks;

  for (auto task : system.ongoingTasks)
  {
    ongoingTasks.insert(task);
  }

  for (auto task : ongoingTasks)
  {
    cout << task.name;
    cout << " (" << task.priority << "):";
    for (unsigned int i = 0; i < task.employees.size(); i++)
    {
      cout << ' ' << task.employees[i];

      if (i < task.employees.size() - 1)
      {
        cout << ',';
      }
    }
    cout << endl;
  }

  return 0;
}
