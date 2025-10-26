#include "../../includes/main.hpp"

string Client::homePage(MyResponse myRes)
{
  string body;
  body += "<!DOCTYPE html>";
  body += "  <html lang=\"en\">";
  body += "    <head>";
  body += "      <meta charset=\"UTF-8\" />";
  body += "      <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />";
  body += "      <title>UTrello</title>";
  body += "      <link rel=\"stylesheet\" href=\"/bootstrap.css\" />";
  body += "    </head>";

  body += "    <body class=\"bg-light\" style=\"text-align: center\">";
  body += "      <nav class=\"navbar navbar-expand-sm navbar-light bg-light z-3\">";
  body += "        <div class=\"container\">";
  body += "          <a class=\"navbar-brand fw-semibold\" href=\"/\">UTrello</a>";
  body += "          <button";
  body += "            class=\"navbar-toggler d-lg-none\"";
  body += "            type=\"button\"";
  body += "            data-bs-toggle=\"collapse\"";
  body += "            data-bs-target=\"#collapsibleNavId\"";
  body += "            aria-controls=\"collapsibleNavId\"";
  body += "            aria-expanded=\"false\"";
  body += "            aria-label=\"Toggle navigation\"";
  body += "          >";
  body += "            <span class=\"navbar-toggler-icon\"></span>";
  body += "          </button>";
  body += "          <div class=\"collapse navbar-collapse\" id=\"collapsibleNavId\">";
  body += "            <ul class=\"navbar-nav me-auto mt-2 mt-lg-0\">";
  body += "              <li class=\"nav-item\">";
  body += "                <a class=\"nav-link active\" href=\"/\"";
  body += "                  >Home <span class=\"visually-hidden\">(current)</span></a";
  body += "                >";
  body += "              </li>";
  body += "              <li class=\"nav-item\">";
  body += "                <a class=\"nav-link\" href=\"/task\">Task</a>";
  body += "              </li>";
  body += "              <li class=\"nav-item\">";
  body += "                <a class=\"nav-link\" href=\"/event\">Event</a>";
  body += "              </li>";
  body += "              <li class=\"nav-item\">";
  body += "                <a class=\"nav-link\" href=\"/join_event\">Join Event</a>";
  body += "              </li>";
  body += "              <li class=\"nav-item\">";
  body += "                <a class=\"nav-link\" href=\"/report_page\">Report</a>";
  body += "              </li>";
  body += "            </ul>";
  body += "            <form action=\"/logout\" method=\"post\">";
  body += "              <button class=\"btn btn-danger\" type=\"submit\">logout</button>";
  body += "            </form>";
  body += "          </div>";
  body += "        </div>";
  body += "      </nav>";
  body += "      <h1 class=\"translate-middle position-fixed top-50 start-50\">";
  body += "        Welcome to UTrello 📝";
  body += "      </h1>";
  body += "    <script src=\"/bootstrap.bundle.js\"></script>";
  body += "    </body>";

  body += "  </html>";

  (void)myRes;
  return body;
}
