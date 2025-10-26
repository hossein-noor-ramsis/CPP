#ifndef CLIENT_HPP
#define CLIENT_HPP

class Client
{
public:
  bool isLoggedIn = false;

  string username;
  string password;

public:
  Client();

  map<string, string> parseInput(const string &input, string &method, string &path);

  int input(Server &server);
  int output(Response res);

  ~Client();
};

#endif
