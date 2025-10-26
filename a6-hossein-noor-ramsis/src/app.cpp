#include "../includes/main.hpp"

int app(char *argv[])
{
  vector<vector<string>> data = readCSV(argv[1]);

  Server server;
  server.dataBase.loadData(data);

  Client client;
  client.input(server);

  return 0;
}
