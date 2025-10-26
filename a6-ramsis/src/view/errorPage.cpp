#include "../../includes/main.hpp"

string Client::errorPage(MyResponse myRes)
{
  string body;
  string errCode = to_string(myRes.getStatusCode());

  body += "<!DOCTYPE html>";
  body += "<html lang=\"en\">";
  body += "<head>";
  body += "<meta charset=\"utf-8\" />";
  body += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" />";
  body += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" />";

  body += "<title>Error 👀</title>";
  body += "<link rel=\"stylesheet\" href=\"/style.css\" />";
  body += "</head>";

  body += "<body class=\"bg-light\">";
  body += "<div id=\"notfound\">";
  body += "<div class=\"notfound\">";
  body += "<div class=\"notfound-404\">";
  body += "<div></div>";
  body += "<h1>" + errCode + "</h1>";
  body += "</div>";
  body += "<p>";
  body += "Oops! " + myRes.getStatusMessage();
  body += "</p>";
  body += "<br />";
  body += "<a href=\"/\">home page</a>";
  body += "</div>";
  body += "</div>";
  body += "</body>";
  body += "</html>";

  return body;
}
