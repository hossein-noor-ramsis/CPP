#ifndef HANDLERS_HPP_INCLUDE
#define HANDLERS_HPP_INCLUDE

class GetHomeHandler : public RequestHandler
{
public:
  GetHomeHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class GetLoginHandler : public RequestHandler
{
public:
  GetLoginHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostLoginHandler : public RequestHandler
{
public:
  PostLoginHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class GetSignupHandler : public RequestHandler
{
public:
  GetSignupHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostSignupHandler : public RequestHandler
{
public:
  PostSignupHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostLogoutHandler : public RequestHandler
{
public:
  PostLogoutHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class GetTaskHandler : public RequestHandler
{
public:
  GetTaskHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostTaskHandler : public RequestHandler
{
public:
  PostTaskHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PutTaskHandler : public RequestHandler
{
public:
  PutTaskHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class DeleteTaskHandler : public RequestHandler
{
public:
  DeleteTaskHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class GetEventHandler : public RequestHandler
{
public:
  GetEventHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class GetJoinEventHandler : public RequestHandler
{
public:
  GetJoinEventHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class GetReportPageHandler : public RequestHandler
{
public:
  GetReportPageHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostEventHandler : public RequestHandler
{
public:
  PostEventHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostJoinEventHandler : public RequestHandler
{
public:
  PostJoinEventHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostConfirmJoinEventHandler : public RequestHandler
{
public:
  PostConfirmJoinEventHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostRejectJoinEventHandler : public RequestHandler
{
public:
  PostRejectJoinEventHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class PostPeriodicEventHandler : public RequestHandler
{
public:
  PostPeriodicEventHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

class GetReportHandler : public RequestHandler
{
public:
  GetReportHandler(MyServer &myServer, Client client);

  MyServer &myServer;
  Client client;

  Response *callback(Request *) override;
};

#endif
