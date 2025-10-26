#include "../includes/main.hpp"

int main(int, char *argv[])
{
  vector<vector<string>> data = readCSV(argv[1]);

  System system = System(data);

  app(system);

  return 0;
}
