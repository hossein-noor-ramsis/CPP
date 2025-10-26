#include "../../includes/main.hpp"

Server::Server()
{
}

int Server::middleware()
{
  shared_ptr<User> user;

  if ((_req.getUsername() == "") || (_req.getPassword() == ""))
  {
    throw runtime_error(StatusMessage::PERMISSION_DENIED);
  }

  if (!dataBase.isUserExist(_req.getUsername()))
  {
    throw runtime_error(StatusMessage::PERMISSION_DENIED);
  }

  user = dataBase.getUser(_req.getUsername());

  if (user->getPassword() != _req.getPassword())
  {
    throw runtime_error(StatusMessage::PERMISSION_DENIED);
  }

  _req.setUser(user);

  return 0;
}

Response Server::router(Request req)
{
  _req = req;
  _res = Response();

  _res.setStatusCode(StatuesCode::OK);
  _res.setStatusMessage(StatusMessage::OK);

  string method = req.getMethod();
  string path = req.getPath();

  try
  {
    if (method == Method::POST)
    {
      if (path == ServerRoutes::SIGNUP)
      {
        dataBase.signupHandler(_req, _res);
      }
      else if (path == ServerRoutes::LOGIN)
      {
        dataBase.loginHandler(_req, _res);
      }
      else if (path == ServerRoutes::LOGOUT)
      {
        middleware();
        dataBase.logoutHandler(_req, _res);
      }
      else if (path == ServerRoutes::EVENT)
      {
        middleware();
        dataBase.addEventHandler(_req, _res);
      }
      else if (path == ServerRoutes::PERIODIC_EVENT)
      {
        middleware();
        dataBase.addPeriodicEventHandler(_req, _res);
      }
      else if (path == ServerRoutes::TASK)
      {
        middleware();
        dataBase.addTaskHandler(_req, _res);
      }
      else if (path == ServerRoutes::JOIN_EVENT)
      {
        middleware();
        dataBase.addJoinEventHandler(_req, _res);
      }
      else if (path == ServerRoutes::CONFIRM_JOIN_EVENT)
      {
        middleware();
        dataBase.confirmJoinEventHandler(_req, _res);
      }
      else if (path == ServerRoutes::REJECT_JOIN_EVENT)
      {
        middleware();
        dataBase.rejectJoinEventHandler(_req, _res);
      }
      else
      {
        throw runtime_error(StatusMessage::NOT_FOUND);
      }
    }
    else if (method == Method::GET)
    {
      if (path == ServerRoutes::REPORT)
      {
        middleware();
        dataBase.reportHandler(_req, _res);
      }
      else if (path == ServerRoutes::JOIN_EVENT)
      {
        middleware();
        dataBase.getJoinEventHandler(_req, _res);
      }
      else
      {
        throw runtime_error(StatusMessage::NOT_FOUND);
      }
    }
    else if (method == Method::PUT)
    {
      if (path == ServerRoutes::TASK)
      {
        middleware();
        dataBase.editTaskHandler(_req, _res);
      }
      else
      {
        throw runtime_error(StatusMessage::NOT_FOUND);
      }
    }
    else if (method == Method::DELETE)
    {
      if (path == ServerRoutes::TASK)
      {
        middleware();
        dataBase.deleteTaskHandler(_req, _res);
      }
      else
      {
        throw runtime_error(StatusMessage::NOT_FOUND);
      }
    }
    else
    {
      throw runtime_error(StatusMessage::BAD_REQUEST);
    }
  }
  catch (const std::exception &e)
  {
    errorHandler(e);
    return _res;
  }

  return _res;
}

int Server::errorHandler(const std::exception &e)
{
  if (e.what() == string(StatusMessage::BAD_REQUEST))
  {
    _res.setStatusCode(StatuesCode::BAD_REQUEST);
    _res.setStatusMessage(StatusMessage::BAD_REQUEST);
  }
  else if (e.what() == string(StatusMessage::NOT_FOUND))
  {
    _res.setStatusCode(StatuesCode::NOT_FOUND);
    _res.setStatusMessage(StatusMessage::NOT_FOUND);
  }
  else if (e.what() == string(StatusMessage::PERMISSION_DENIED))
  {
    _res.setStatusCode(StatuesCode::PERMISSION_DENIED);
    _res.setStatusMessage(StatusMessage::PERMISSION_DENIED);
  }
  else if (e.what() == string(StatusMessage::EMPTY))
  {
    _res.setStatusCode(StatuesCode::EMPTY);
    _res.setStatusMessage(StatusMessage::EMPTY);
  }
  else if (e.what() == string(StatusMessage::OVERLAP))
  {
    _res.setStatusCode(StatuesCode::CONFLICT);
    _res.setStatusMessage(StatusMessage::OVERLAP);
  }
  else if (e.what() == string(StatusMessage::HOLIDAY_FOUND))
  {
    _res.setStatusCode(StatuesCode::CONFLICT);
    _res.setStatusMessage(StatusMessage::HOLIDAY_FOUND);
  }
  else
  {
    _res.setStatusCode(StatuesCode::INTERNAL_SERVER_ERROR);
    _res.setStatusMessage(StatusMessage::BAD_REQUEST);
  }

  return 0;
}

Server::~Server()
{
}
