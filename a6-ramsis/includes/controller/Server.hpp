#ifndef MY_SERVER_HPP
#define MY_SERVER_HPP

class MyServer
{
private:
  MyRequest _req;
  MyResponse _res;

public:
  DataBase dataBase;

public:
  MyServer();

  MyResponse router(MyRequest req);
  int middleware();

  int errorHandler(const std::exception &e);

  ~MyServer();
};

#endif
