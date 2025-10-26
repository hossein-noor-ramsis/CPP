#ifndef MY_REQUEST_HPP
#define MY_REQUEST_HPP

#include "../model/User.hpp"

class MyRequest
{
private:
  shared_ptr<User> _user;

  string _username;
  string _password;

  string _method;
  string _path;

  map<string, string> _args;

public:
  MyRequest();

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

  ~MyRequest();
};

#endif
