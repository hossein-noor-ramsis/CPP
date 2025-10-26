#include "../../includes/main.hpp"

MyResponse::MyResponse()
{
}

int MyResponse::setStatusCode(int num)
{
  _statusCode = num;
  return 0;
}

int MyResponse::setStatusMessage(string str)
{
  _statusMessage = str;
  return 0;
}

int MyResponse::setBody(vector<string> data)
{
  _body = data;
  return 0;
}

int MyResponse::getStatusCode()
{
  return _statusCode;
}

string MyResponse::getStatusMessage()
{
  return _statusMessage;
}

vector<string> MyResponse::getBody()
{
  return _body;
}

MyResponse::~MyResponse()
{
}
