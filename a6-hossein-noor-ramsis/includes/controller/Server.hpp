#ifndef SERVER_HPP
#define SERVER_HPP

class Server
{
private:
  Request _req;
  Response _res;

public:
  DataBase dataBase;

public:
  Server();

  Response router(Request req);
  int middleware();

  int errorHandler(const std::exception &e);

  ~Server();
};

#endif
