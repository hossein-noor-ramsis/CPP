#include "../../includes/main.hpp"

Response::Response()
{
}

int Response::setStatusCode(int num)
{
  _statusCode = num;
  return 0;
}

int Response::setStatusMessage(string str)
{
  _statusMessage = str;
  return 0;
}

int Response::setBody(vector<string> data)
{
  _body = data;
  return 0;
}

int Response::getStatusCode()
{
  return _statusCode;
}

string Response::getStatusMessage()
{
  return _statusMessage;
}

vector<string> Response::getBody()
{
  return _body;
}

Response::~Response()
{
}
