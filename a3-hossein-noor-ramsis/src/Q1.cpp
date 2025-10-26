#include <algorithm>
#include <iostream>
using namespace std;

string latex(int num, int to, int curr = 1);

int main()
{
  int command;
  int num = 1;

  cin >> command;
  string l = latex(num, command);

  cout << l << endl;

  return 0;
}

string latex(int num, int to, int curr)
{
  string str = to_string(num);

  if (curr == to)
  {
    return str;
  }

  curr++;

  string a = latex(2 * num, to, curr);
  string b = latex((2 * num) + 1, to, curr);

  string frac = "+\\frac{" + a + "}{" + b + "}";

  str.append(frac);

  return str;
}
