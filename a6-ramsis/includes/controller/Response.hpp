#ifndef MY_RESPONSE_HPP
#define MY_RESPONSE_HPP

class MyResponse
{
private:
  int _statusCode = 200;
  string _statusMessage = StatusMessage::OK;
  vector<string> _body;

public:
  MyResponse();

  int setStatusCode(int num);
  int setStatusMessage(string str);
  int setBody(vector<string> data);

  int getStatusCode();
  string getStatusMessage();
  vector<string> getBody();

  ~MyResponse();
};

#endif
