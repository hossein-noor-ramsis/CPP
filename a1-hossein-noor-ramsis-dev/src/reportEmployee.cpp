#include "../includes/main.hpp"

int reportEmployee(const System &system)
{
  Employee selectedEmployee;
  string employeeName;
  int i = 1;

  cin >> employeeName;

  selectedEmployee = system.employees.at(employeeName);

  cout << selectedEmployee.name << " has done ";
  cout << selectedEmployee.countOfDoneTasks << " tasks. \n";

  if (selectedEmployee.ongoingTasks.size() == 0)
  {
    cout << selectedEmployee.name << " is currently not working on any tasks." << endl;
    return 0;
  }

  cout << selectedEmployee.name << " is currently working on these tasks:\n";
  for (auto taskName : selectedEmployee.ongoingTasks)
  {
    cout << i << ". " << taskName << '\n';
    i++;
  }

  cout << endl;

  return 0;
}
