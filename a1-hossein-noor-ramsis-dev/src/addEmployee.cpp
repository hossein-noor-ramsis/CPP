#include "../includes/main.hpp"

int addEmployee(System &system)
{
  Employee employee;
  string name;

  cin >> name;

  employee.name = name;
  employee.countOfDoneTasks = 0;

  system.employees.insert({name, employee});

  return 0;
}