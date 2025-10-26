#include "../../includes/main.hpp"

Subject::Subject(string name, string difficulty, int count)
{
  _name = name;
  _difficulty = difficulty;
  _count = count;
}

Subject::Subject(string name)
{
  _name = name;
}

string Subject::getName()
{
  return _name;
}

string Subject::getDifficulty()
{
  return _difficulty;
}

int Subject::getCount()
{
  return _count;
}
void Subject::decreaseCount()
{
  _count--;
}

int Subject::getPriority()
{
  return _priority;
}

void Subject::setPriority(int num)
{
  _priority = num;
}
