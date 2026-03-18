//
// Created by Hossein on 16/03/2026.
//

#include "String.h"

#include <sstream>

vector<string> String::split(const string& str, const char delim)
{
  stringstream ss(str);
  vector<string> parts;
  string part;

  while (getline(ss, part, delim))
  {
    parts.push_back(part);
  }

  return parts;
}

string String::join(const vector<string>& vec, const char delim)
{
  string str;

  if (!vec.empty())
  {
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
      str.append(vec[i]);
      str.push_back(delim);
    }

    str.append(vec.back());
  }

  return str;
}
