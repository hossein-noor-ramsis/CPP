#include "../../includes/main.hpp"

Template::Template(string name)
{
  _name = name;
}

string Template::getName()
{
  return _name;
}

int Template::addSubject(Subject newSubject)
{
  _subjects.push_back(newSubject);

  return 0;
}

vector<Subject> Template::getSubjects()
{
  return _subjects;
}
