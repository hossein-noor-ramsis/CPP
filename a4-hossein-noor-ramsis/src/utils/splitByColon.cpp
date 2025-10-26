#include "../../includes/main.hpp"

vector<string> splitByColon(const string &input)
{
  vector<string> parts;
  stringstream ss(input);
  string item;

  while (getline(ss, item, ':'))
  {
    parts.push_back(item);
  }

  return parts;
}
