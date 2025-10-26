#include "../includes/main.hpp"

GetHomeHandler::GetHomeHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetHomeHandler::callback(Request *req)
{
  MyResponse myRes = MyResponse();
  Response *res = new Response();

  if (req->getSessionId().size() == 0)
  {
    return Response::redirect("/signup");
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(client.homePage(myRes));

  return res;
}

GetLoginHandler::GetLoginHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetLoginHandler::callback(Request *req)
{
  if (req->getSessionId().size() != 0)
  {
    return Response::redirect("/");
  }

  MyResponse myRes = MyResponse();
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");
  res->setBody(client.loginPage(myRes));

  return res;
}

PostLoginHandler::PostLoginHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostLoginHandler::callback(Request *req)
{
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");

  string command;
  command = string(Method::POST) + " " + string(ServerRoutes::LOGIN) + " ? ";
  command += "username \"" + username + "\" password \"" + password + "\"";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      return Response::redirect("/");
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res = Response::redirect("/");
  res->setSessionId(username);

  return res;
}

GetSignupHandler::GetSignupHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetSignupHandler::callback(Request *req)
{
  if (req->getSessionId().size() != 0)
  {
    return Response::redirect("/");
  }

  MyResponse myRes = MyResponse();
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");
  res->setBody(client.signupPage(myRes));

  return res;
}

PostSignupHandler::PostSignupHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostSignupHandler::callback(Request *req)
{
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");

  string command;

  command = string(Method::POST) + " " + string(ServerRoutes::SIGNUP) + " ? ";
  command += "username \"" + username + "\" password \"" + password + "\"";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      return Response::redirect("/");
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res = Response::redirect("/");
  res->setSessionId(username);

  return res;
}

PostLogoutHandler::PostLogoutHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostLogoutHandler::callback(Request *req)
{
  string command;
  command = string(Method::POST) + " " + string(ServerRoutes::LOGOUT) + " ?";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");
  res = Response::redirect("/signup");
  res->setSessionId("");
  res->redirect("/signup");

  return res;
}

GetTaskHandler::GetTaskHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetTaskHandler::callback(Request *req)
{
  MyResponse myRes = MyResponse();
  Response *res = new Response();

  if (req->getSessionId().size() == 0)
  {
    return Response::redirect("/signup");
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(client.taskPage(myRes));

  return res;
}

PostTaskHandler::PostTaskHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostTaskHandler::callback(Request *req)
{
  string command;

  string date = req->getBodyParam("date");
  string time = req->getBodyParam("time");
  string title = req->getBodyParam("title");
  string description = req->getBodyParam("description");

  command = string(Method::POST) + " " + string(ServerRoutes::TASK) + " ? ";
  command += "date " + date + " time " + time + " title \"" + title + "\" description \"" + description + "\"";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.taskPage(myRes));
  return res;
}

PutTaskHandler::PutTaskHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PutTaskHandler::callback(Request *req)
{
  string command;

  string taskId = req->getBodyParam("task_id");
  string date = req->getBodyParam("date");
  string time = req->getBodyParam("time");
  string title = req->getBodyParam("title");
  string description = req->getBodyParam("description");

  command = string(Method::PUT) + " " + string(ServerRoutes::TASK) + " ? ";
  command += "task_id " + taskId + " date " + date + " time " + time + " title \"" + title + "\" description \"" + description + "\"";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.taskPage(myRes));
  return res;
}

DeleteTaskHandler::DeleteTaskHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *DeleteTaskHandler::callback(Request *req)
{
  string command;

  string taskId = req->getBodyParam("task_id");

  command = string(Method::DELETE) + " " + string(ServerRoutes::TASK) + " ? ";
  command += "task_id " + taskId;

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.taskPage(myRes));
  return res;
}

GetEventHandler::GetEventHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetEventHandler::callback(Request *req)
{
  MyResponse myRes = MyResponse();
  Response *res = new Response();

  if (req->getSessionId().size() == 0)
  {
    return Response::redirect("/signup");
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(client.eventPage(myRes));

  return res;
}

GetJoinEventHandler::GetJoinEventHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetJoinEventHandler::callback(Request *req)
{
  string command;
  command = string(Method::GET) + " " + string(ServerRoutes::JOIN_EVENT) + " ? ";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    return Response::redirect("/signup");
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(client.joinEventPage(myRes));

  return res;
}

GetReportPageHandler::GetReportPageHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetReportPageHandler::callback(Request *req)
{
  MyResponse myRes = MyResponse();
  Response *res = new Response();

  if (req->getSessionId().size() == 0)
  {
    return Response::redirect("/signup");
  }

  res->setHeader("Content-Type", "text/html");
  res->setBody(client.reportPage(myRes));

  return res;
}

PostEventHandler::PostEventHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostEventHandler::callback(Request *req)
{
  string command;

  string date = req->getBodyParam("date");
  string startTime = req->getBodyParam("start_time");
  string duration = req->getBodyParam("duration");
  string title = req->getBodyParam("title");
  string description = req->getBodyParam("description");

  command = string(Method::POST) + " " + string(ServerRoutes::EVENT) + " ? ";
  command += "date " + date + " start_time " + startTime + " duration " + duration + " title \"" + title + "\" description \"" + description + "\"";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.eventPage(myRes));
  return res;
}

PostJoinEventHandler::PostJoinEventHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostJoinEventHandler::callback(Request *req)
{
  string command;

  string guests = req->getBodyParam("guests");
  string date = req->getBodyParam("date");
  string startTime = req->getBodyParam("start_time");
  string endTime = req->getBodyParam("end_time");
  string title = req->getBodyParam("title");
  string description = req->getBodyParam("description");

  command = string(Method::POST) + " " + string(ServerRoutes::JOIN_EVENT) + " ? ";
  command += "guests \"" + guests + "\" ";
  command += "date " + date + " start_time " + startTime + " end_time " + endTime + " title \"" + title + "\" description \"" + description + "\"";

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.eventPage(myRes));
  return res;
}

PostConfirmJoinEventHandler::PostConfirmJoinEventHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostConfirmJoinEventHandler::callback(Request *req)
{
  string command;

  string invitationId = req->getBodyParam("invitation_id");

  command = string(Method::POST) + " " + string(ServerRoutes::CONFIRM_JOIN_EVENT) + " ? ";
  command += "invitation_id " + invitationId;

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.joinEventPage(myRes));
  return res;
}

PostRejectJoinEventHandler::PostRejectJoinEventHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostRejectJoinEventHandler::callback(Request *req)
{
  string command;

  string invitationId = req->getBodyParam("invitation_id");

  command = string(Method::POST) + " " + string(ServerRoutes::REJECT_JOIN_EVENT) + " ? ";
  command += "invitation_id " + invitationId;

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.joinEventPage(myRes));
  return res;
}

PostPeriodicEventHandler::PostPeriodicEventHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *PostPeriodicEventHandler::callback(Request *req)
{
  string command;

  string type = req->getBodyParam("type");
  string weekDays = req->getBodyParam("week_days");
  string startDate = req->getBodyParam("start_date");
  string endDate = req->getBodyParam("end_date");
  string startTime = req->getBodyParam("start_time");
  string duration = req->getBodyParam("duration");
  string title = req->getBodyParam("title");
  string description = req->getBodyParam("description");

  if (type == string(PeriodicEventsType::WEEKLY))
  {
    command = string(Method::POST) + " " + string(ServerRoutes::PERIODIC_EVENT) + " ? ";
    command += "type " + type + " week_days " + weekDays + " ";
    command += "start_date " + startDate + " end_date " + endDate + " start_time " + startTime + " duration " + duration + " title \"" + title + "\" description \"" + description + "\"";
  }
  else
  {
    Response *res = new Response();
    MyResponse myRes = MyResponse();

    myRes.setStatusCode(StatuesCode::BAD_REQUEST);
    myRes.setStatusMessage(StatusMessage::BAD_REQUEST);

    res->setBody(client.errorPage(myRes));
    return res;
  }

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }

    res->setBody(client.errorPage(myRes));
    return res;
  }

  res->setBody(client.eventPage(myRes));
  return res;
}

GetReportHandler::GetReportHandler(MyServer &myServer, Client client) : myServer(myServer), client(client)
{
}

Response *GetReportHandler::callback(Request *req)
{
  string command;

  string to = req->getQueryParam("to");
  string from = req->getQueryParam("from");
  string type = req->getQueryParam("type");

  command = string(Method::GET) + " " + string(ServerRoutes::REPORT) + " ? ";
  command += "to " + to + ((from.length() != 0) ? " from " + from : "") + ((type != "all") ? " type " + type : "");

  MyResponse myRes = client.input(myServer, command, req->getSessionId());
  Response *res = new Response();

  res->setHeader("Content-Type", "text/html");

  if (req->getSessionId().size() == 0)
  {
    res = Response::redirect("/signup");
    return res;
  }

  if (myRes.getStatusMessage() != StatusMessage::OK)
  {
    if (myRes.getStatusMessage() == StatusMessage::PERMISSION_DENIED)
    {
      res = Response::redirect("/signup");
      res->setSessionId("");
      return res;
    }
  }

  res->setBody(client.reportPage(myRes));
  return res;
}
