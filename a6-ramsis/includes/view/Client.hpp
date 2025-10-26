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

  MyResponse input(MyServer &server, string command, string username);
  int output(MyResponse res);

  string errorPage(MyResponse myRes);
  
  string signupPage(MyResponse myRes);
  string loginPage(MyResponse myRes);
  
  string homePage(MyResponse myRes);
  string taskPage(MyResponse myRes);
  string eventPage(MyResponse myRes);
  string joinEventPage(MyResponse myRes);
  string reportPage(MyResponse myRes);

  ~Client();
};

#endif
