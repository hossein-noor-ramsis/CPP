#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "../model/User.hpp"

class Request
{
private:
  shared_ptr<User> _user;

  string _username;
  string _password;

  string _method;
  string _path;

  map<string, string> _args;

public:
  Request();

  int setUser(shared_ptr<User> user);
  shared_ptr<User> getUser();

  int setUsername(string username);
  string getUsername();

  int setPassword(string password);
  string getPassword();

  int setMethod(string method);
  string getMethod();

  int setPath(string path);
  string getPath();

  int setArguments(map<string, string> args);
  map<string, string> getArguments();

  int insertArgument(string key, string value);
  bool isArgumentExist(string key);
  string getArgument(string key);

  ~Request();
};

#endif
