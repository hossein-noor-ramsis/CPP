#include "../../includes/main.hpp"

vector<string> splitBySlash(const string &input)
{
  vector<string> result;
  stringstream ss(input);
  string item;

  while (getline(ss, item, '/'))
  {
    if (!item.empty())
      result.push_back(item);
  }

  return result;
}
