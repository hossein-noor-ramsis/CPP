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
    throw runtime_error(StatusMessage::BAD_REQUEST);

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

int Client::input(Server &server)
{
  Request req;
  string command;
  string method;
  string path;

  while (getline(cin, command))
  {
    try
    {
      map<string, string> arguments = parseInput(command, method, path);

      req.setMethod(trim(method));
      req.setPath(trim(path));
      req.setArguments(arguments);

      req.setUsername(username);
      req.setPassword(password);

      Response res = server.router(req);

      if ((res.getStatusCode() == StatuesCode::OK) && (method == Method::POST))
      {
        if (path == ServerRoutes::SIGNUP)
        {
          isLoggedIn = true;
          username = arguments.at(UserKey::USERNAME);
          password = arguments.at(UserKey::PASSWORD);
        }

        if (path == ServerRoutes::LOGIN)
        {
          isLoggedIn = true;
          username = arguments.at(UserKey::USERNAME);
          password = arguments.at(UserKey::PASSWORD);
        }

        if (path == ServerRoutes::LOGOUT)
        {
          isLoggedIn = false;
          username = "";
          password = "";
        }
      }

      output(res);
    }
    catch (const exception &e)
    {
      Response res;
      res.setStatusCode(StatuesCode::BAD_REQUEST);
      res.setStatusMessage(StatusMessage::BAD_REQUEST);
      output(res);
    }
  }

  return 0;
}

int Client::output(Response res)
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
