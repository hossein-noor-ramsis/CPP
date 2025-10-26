#include "../../includes/main.hpp"

Request::Request()
{
}

int Request::setUser(shared_ptr<User> user)
{
  _user = user;
  return 0;
}

shared_ptr<User> Request::getUser()
{
  return _user;
}

int Request::setUsername(string username)
{
  _username = username;
  return 0;
}

string Request::getUsername()
{
  return _username;
}

int Request::setPassword(string password)
{
  _password = password;
  return 0;
}

string Request::getPassword()
{
  return _password;
}

int Request::setMethod(string method)
{
  if (method == Method::GET)
  {
    _method = Method::GET;
  }
  else if (method == Method::POST)
  {
    _method = Method::POST;
  }
  else if (method == Method::PATCH)
  {
    _method = Method::PATCH;
  }
  else if (method == Method::PUT)
  {
    _method = Method::PUT;
  }
  else if (method == Method::DELETE)
  {
    _method = Method::DELETE;
  }
  else
  {
    throw runtime_error(StatusMessage::BAD_REQUEST);
  }

  return 0;
}

string Request::getMethod()
{
  return _method;
}

int Request::setPath(string path)
{
  _path = path;
  return 0;
}

string Request::getPath()
{
  return _path;
}

int Request::setArguments(map<string, string> args)
{
  _args = args;
  return 0;
}

map<string, string> Request::getArguments()
{
  return _args;
}

int Request::insertArgument(string key, string value)
{
  _args.insert({key, value});
  return 0;
}

bool Request::isArgumentExist(string key)
{
  return _args.find(key) != _args.end();
}

string Request::getArgument(string key)
{
  return _args.at(key);
}

Request::~Request()
{
}
