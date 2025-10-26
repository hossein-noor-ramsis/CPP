#include "../includes/main.hpp"

void mapServerPaths(Server &server, MyServer &myServer)
{
  Client client;

  server.get("/style.css", new ShowFile("static/style.css", "text/css"));

  server.get("/bootstrap.css", new ShowFile("static/bootstrap.css", "text/css"));
  server.get("/bootstrap.bundle.js", new ShowFile("static/bootstrap.bundle.js", "application/javascript"));

  server.get("/bootstrap.css.map", new ShowFile("static/bootstrap.css.map", "text/css"));
  server.get("/bootstrap.bundle.js.map", new ShowFile("static/bootstrap.bundle.js.map", "application/javascript"));

  server.get("/", new GetHomeHandler(myServer, client));

  server.get("/signup", new GetSignupHandler(myServer, client));
  server.get("/login", new GetLoginHandler(myServer, client));

  server.get("/task", new GetTaskHandler(myServer, client));
  server.get("/event", new GetEventHandler(myServer, client));
  server.get("/join_event", new GetJoinEventHandler(myServer, client));
  server.get("/report_page", new GetReportPageHandler(myServer, client));

  server.post("/signup", new PostSignupHandler(myServer, client));
  server.post("/login", new PostLoginHandler(myServer, client));
  server.post("/logout", new PostLogoutHandler(myServer, client));

  server.post("/task", new PostTaskHandler(myServer, client));
  server.post("/task_put", new PutTaskHandler(myServer, client));
  server.post("/task_delete", new DeleteTaskHandler(myServer, client));

  server.post("/event", new PostEventHandler(myServer, client));
  server.post("/join_event", new PostJoinEventHandler(myServer, client));
  server.post("/confirm_join_event", new PostConfirmJoinEventHandler(myServer, client));
  server.post("/reject_join_event", new PostRejectJoinEventHandler(myServer, client));
  server.post("/periodic_event", new PostPeriodicEventHandler(myServer, client));

  server.get("/report", new GetReportHandler(myServer, client));

  server.setNotFoundErrPage("./static/404.html");
}

int app(int argc, char *argv[])
{
  try
  {
    vector<vector<string>> data = readCSV(argv[1]);

    MyServer myServer;
    myServer.dataBase.loadData(data);

    int port = 5000;
    Server server(port);

    mapServerPaths(server, myServer);

    std::cout << "Server running on port: " << port << std::endl;
    server.run();
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << std::endl;
  }
  catch (const Server::Exception &e)
  {
    std::cerr << e.getMessage() << std::endl;
  }

  (void)argc;
  return 0;
}
