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
  
  map<string, Employee> employees;
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
