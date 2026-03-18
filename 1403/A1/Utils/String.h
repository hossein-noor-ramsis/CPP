//
// Created by Hossein on 16/03/2026.
//

#ifndef A0_STRING_H
#define A0_STRING_H
#include <string>
#include <vector>

using namespace std;

class String
{
public:
  static vector<string> split(const string& str, char delim);

  static string join(const vector<string>& vec, char delim);
};

#endif //A0_STRING_H
