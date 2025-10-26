#include "../includes/main.hpp"

int reportAll(const System &system)
{
  int allTasksCount = (int)system.tasks.size();
  int ongoingTasksCount = (int)system.ongoingTasks.size();
  int doneTasksCount = (int)system.doneTasks.size();

  cout << "TODO: " << allTasksCount << endl;
  cout << "ONGOING: " << ongoingTasksCount << endl;
  cout << "DONE: " << doneTasksCount << endl;

  return 0;
}