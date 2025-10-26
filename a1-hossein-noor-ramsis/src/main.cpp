#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <list>

using namespace std;

//* defines
#define ERROR_MESSAGE "Unknown command"
#define ADD_TASK "add_task"
#define ADD_EMPLOYEE "add_employee"
#define ASSIGN_EMPLOYEE "assign_employee"
#define FINISH_TASK "finish_task"
#define REPORT "report"
#define EXIT "exit"

//* structs
typedef struct
{
  int priority;
  string name;
  string status; // ongoing | done | todo
  vector<string> employees;
} Task;

typedef struct
{
  string name;
  int countOfDoneTasks;
  list<string> ongoingTasks;
} Employee;

typedef struct
{
  list<Task> tasks;
  list<Task> ongoingTasks;
  list<Task> doneTasks;
  vector<Employee> employees;
} System;

struct CompareTask
{
  bool operator()(const Task &a, const Task &b) const
  {
    if (a.priority != b.priority)
      return a.priority < b.priority;
    return a.name < b.name;
  }
};

//* prototypes
int addTask(System &system);

int addEmployee(System &system);

int assignEmployee(System &system);

int finishTask(System &system);

int reportAll(System &system);

int reportOngoing(System &system);

int reportEmployee(System &system);

//* main app
int main()
{
  System system;
  string command;
  string flag;
  char ch;

  while (getline(cin, command, ' '))
  {
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

    cin.get(ch);
  }
}

//* functions
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

int addEmployee(System &system)
{
  Employee employee;
  string name;

  cin >> name;

  employee.name = name;
  employee.countOfDoneTasks = 0;

  system.employees.push_back(employee);

  return 0;
}

int assignEmployee(System &system)
{
  string taskName;
  string employeeName;

  cin >> taskName;
  cin >> employeeName;

  bool isNewTask = true; // 1

  for (auto &task : system.ongoingTasks) // 2
  {
    if (task.name == taskName) // 3
    {
      task.employees.push_back(employeeName); // 4
      isNewTask = false;                      // 5
      break;                                  // 6
    }
  }

  if (isNewTask) // 7
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
                         { return t.name == taskName; }); // 8

  for (auto &employee : system.employees)
  {
    if (employee.name == employeeName)
    {
      employee.ongoingTasks.push_back(taskName);
      break;
    }
  }

  return 0;
}

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

      taskEmployees = task.employees;
      break;
    }
  }

  system.ongoingTasks.remove_if([&](const Task &t)
                                { return t.name == taskName; }); // 9

  for (auto &employeeName : taskEmployees)
  {
    for (auto &employee : system.employees)
    {
      if (employee.name == employeeName)
      {
        employee.countOfDoneTasks++;
        employee.ongoingTasks.remove(taskName);
        break;
      }
    }
  }

  return 0;
}

int reportAll(System &system)
{
  int allTasksCount = (int)system.tasks.size();
  int ongoingTasksCount = (int)system.ongoingTasks.size();
  int doneTasksCount = (int)system.doneTasks.size();

  cout << "TODO: " << allTasksCount << endl;
  cout << "ONGOING: " << ongoingTasksCount << endl;
  cout << "DONE: " << doneTasksCount << endl;

  return 0;
}

int reportEmployee(System &system)
{
  Employee selectedEmployee;
  string employeeName;
  int i = 1;

  cin >> employeeName;

  for (auto employee : system.employees)
  {
    if (employee.name == employeeName)
    {
      selectedEmployee = employee;
      break;
    }
  }

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

int reportOngoing(System &system)
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
