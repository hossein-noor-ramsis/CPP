#include "../includes/main.hpp"

int main()
{
  System system;
  string command;
  string flag;

  while (true)
  {
    cin >> command;

    if (command == ADD_TASK)
    {
      addTask(system);
    }
    else if (command == ADD_EMPLOYEE)
    {
      addEmployee(system);
    }
    else if (command == ASSIGN_EMPLOYEE)
    {
      assignEmployee(system);
    }
    else if (command == FINISH_TASK)
    {
      finishTask(system);
    }
    else if (command == REPORT)
    {
      cin >> flag;

      if (flag == "all")
      {
        reportAll(system);
      }
      else if (flag == "ongoing")
      {
        reportOngoing(system);
      }
      else if (flag == "employee")
      {
        reportEmployee(system);
      }
      else
      {
        cout << ERROR_MESSAGE << " <" << command << ">" << endl;
      }
    }
    else if (command == EXIT)
    {
      break;
    }
    else
    {
      cout << ERROR_MESSAGE << " <" << command << ">" << endl;
    }
  }
}
