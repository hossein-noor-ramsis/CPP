#include "../../includes/main.hpp"

Client::Client()
{
}

map<string, string> Client::parseInput(const string &input, string &method, string &path)
{
  map<string, string> result;
  istringstream iss(input);
  string token;

  if (!(iss >> method))
    return result;

  if (!(iss >> path))
    return result;

  iss >> token;
  if (token != "?")
    return result;

  while (iss >> token)
  {
    string key = token;
    string value;
    if (!(iss >> quoted(value)))
      break;
    result[key] = value;
  }

  return result;
}

MyResponse Client::input(MyServer &myServer, string command, string username)
{
  MyRequest req;
  string method;
  string path;

  if (myServer.dataBase.isUserExist(username))
  {
    req.setUsername(username);
    req.setPassword(myServer.dataBase.getUser(username)->getPassword());
  }

  map<string, string> arguments = parseInput(command, method, path);

  req.setMethod(trim(method));
  req.setPath(trim(path));
  req.setArguments(arguments);

  MyResponse res = myServer.router(req);

  output(res);

  return res;
}

int Client::output(MyResponse res)
{
  if (res.getBody().size() == 0)
  {
    cout << res.getStatusMessage() << endl;
  }
  else
  {
    for (auto &&i : res.getBody())
    {
      cout << i << endl;
    }
  }

  return 0;
}

Client::~Client()
{
}
