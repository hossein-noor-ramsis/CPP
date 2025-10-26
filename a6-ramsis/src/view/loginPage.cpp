#include "../../includes/main.hpp"

string Client::loginPage(MyResponse myRes)
{
  string body;

  body += "<!DOCTYPE html>";
  body += "<html lang=\"en\">";
  body += "<head>";
  body += "<meta charset=\"UTF-8\" />";
  body += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />";
  body += "<title>Login</title>";
  body += "<link rel=\"stylesheet\" href=\"/bootstrap.css\" />";
  body += "</head>";

  body += "<body class=\"bg-light\">";
  body += "<div ";
  body += "class=\"container d-flex justify-content-center align-items-center min-vh-100\"";
  body += ">";
  body += "<div ";
  body += "class=\"card p-4 shadow rounded-4\"";
  body += "style=\"width: 100%; max-width: 400px\"";
  body += ">";
  body += "<h3 class=\"text-center mb-4\">Login</h3>";

  body += "<form action=\"/login\" method=\"post\">";
  body += "<div class=\"mb-3\">";
  body += "<label for=\"text\" class=\"form-label\">Username</label>";
  body += "<input ";
  body += "type=\"text\"";
  body += "class=\"form-control\"";
  body += "id=\"text\"";
  body += "name=\"username\"";

  body += "placeholder=\"Enter username\"";
  body += "required";
  body += "/>";
  body += "</div>";

  body += "<div class=\"mb-3\">";
  body += "<label for=\"password\" class=\"form-label\">Password</label>";
  body += "<input ";
  body += "type=\"password\"";
  body += "class=\"form-control\"";
  body += "id=\"password\"";
  body += "name=\"password\"";
  body += "placeholder=\"Enter password\"";
  body += "required";
  body += "/>";
  body += "</div>";

  body += "<button type=\"submit\" class=\"btn btn-primary w-100\">Login</button>";
  body += "</form>";

  body += "<div class=\"text-center mt-3\">";
  body += "<span>Don't have an account?</span>";
  body += "<a href=\"/signup\">Sign up</a>";
  body += "</div>";
  body += "</div>";
  body += "</div>";
  body += "<script src=\"/bootstrap.bundle.js\"></script>";
  body += "</body>";

  body += "</html>";

  (void)myRes;
  return body;
}
