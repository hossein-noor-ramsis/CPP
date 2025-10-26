#include "../../includes/main.hpp"

MyRequest::MyRequest()
{
}

int MyRequest::setUser(shared_ptr<User> user)
{
  _user = user;
  return 0;
}

shared_ptr<User> MyRequest::getUser()
{
  return _user;
}

int MyRequest::setUsername(string username)
{
  _username = username;
  return 0;
}

string MyRequest::getUsername()
{
  return _username;
}

int MyRequest::setPassword(string password)
{
  _password = password;
  return 0;
}

string MyRequest::getPassword()
{
  return _password;
}

int MyRequest::setMethod(string method)
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

string MyRequest::getMethod()
{
  return _method;
}

int MyRequest::setPath(string path)
{
  _path = path;
  return 0;
}

string MyRequest::getPath()
{
  return _path;
}

int MyRequest::setArguments(map<string, string> args)
{
  _args = args;
  return 0;
}

map<string, string> MyRequest::getArguments()
{
  return _args;
}

int MyRequest::insertArgument(string key, string value)
{
  _args.insert({key, value});
  return 0;
}

bool MyRequest::isArgumentExist(string key)
{
  return _args.find(key) != _args.end();
}

string MyRequest::getArgument(string key)
{
  return _args.at(key);
}

MyRequest::~MyRequest()
{
}
