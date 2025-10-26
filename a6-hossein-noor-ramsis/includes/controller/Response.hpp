#ifndef RESPONSE_HPP
#define RESPONSE_HPP

class Response
{
private:
  int _statusCode = 200;
  string _statusMessage = StatusMessage::OK;
  vector<string> _body;

public:
  Response();

  int setStatusCode(int num);
  int setStatusMessage(string str);
  int setBody(vector<string> data);

  int getStatusCode();
  string getStatusMessage();
  vector<string> getBody();

  ~Response();
};

#endif
