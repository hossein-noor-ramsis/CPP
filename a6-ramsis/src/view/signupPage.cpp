#include "../../includes/main.hpp"

string Client::signupPage(MyResponse myRes)
{
  string body;

  body += "<!DOCTYPE html>";
  body += "<html lang=\"en\">";
  body += "<head>";
  body += "<meta charset=\"UTF-8\" />";
  body += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />";
  body += "<title>Signup</title>";
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
  body += "<h3 class=\"text-center mb-4\">Sign Up</h3>";

  body += "<form action=\"/signup\" method=\"post\">";
  body += "<div class=\"mb-3\">";
  body += "<label for=\"username\" class=\"form-label\">Username</label>";
  body += "<input ";
  body += "type=\"text\"";
  body += "class=\"form-control\"";
  body += "id=\"username\"";
  body += "placeholder=\"Choose a username\"";
  body += "name=\"username\"";
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
  body += "placeholder=\"Choose a password\"";
  body += "required";
  body += "/>";
  body += "</div>";

  body += "<button type=\"submit\" class=\"btn btn-success w-100\">Sign Up</button>";
  body += "</form>";

  body += "<div class=\"text-center mt-3\">";
  body += "<span>Already have an account?</span>";
  body += "<a href=\"/login\">Login</a>";
  body += "</div>";
  body += "</div>";
  body += "</div>";
  body += "<script src=\"/bootstrap.bundle.js\"></script>";
  body += "</body>";

  body += "</html>";

  (void)myRes;
  return body;
}
