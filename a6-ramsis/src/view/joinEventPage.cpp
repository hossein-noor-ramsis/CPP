#include "../../includes/main.hpp"

string Client::joinEventPage(MyResponse myRes)
{
  string body;

  body += "<!DOCTYPE html>\n";
  body += "<html lang=\"en\">\n";
  body += "<head>\n";
  body += "<meta charset=\"UTF-8\" />\n";
  body += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n";
  body += "<title>Join Event</title>\n";
  body += "\n";
  body += "<link rel=\"stylesheet\" href=\"/bootstrap.css\" />\n";
  body += "\n";
  body += "<style>\n";
  body += ".invitation-card {\n";
  body += "background: white;\n";
  body += "border-radius: 1rem;\n";
  body += "padding: 1.5rem;\n";
  body += "box-shadow: 0 2px 10px rgba(0, 0, 0, 0.08);\n";
  body += "}\n";
  body += ".event-title {\n";
  body += "font-size: 1.25rem;\n";
  body += "font-weight: 600;\n";
  body += "}\n";
  body += ".event-meta {\n";
  body += "color: #6c757d;\n";
  body += "}\n";
  body += ".action-btns {\n";
  body += "display: flex;\n";
  body += "gap: 1rem;\n";
  body += "margin-top: 1rem;\n";
  body += "}\n";
  body += ".btn-confirm {\n";
  body += "background-color: #198754;\n";
  body += "color: white;\n";
  body += "}\n";
  body += ".btn-reject {\n";
  body += "background-color: #dc3545;\n";
  body += "color: white;\n";
  body += "}\n";
  body += "</style>\n";
  body += "</head>\n";
  body += "\n";
  body += "<body class=\"bg-light\" style=\"text-align: center\">\n";
  body += "<nav class=\"navbar navbar-expand-sm navbar-light bg-light z-3\">\n";
  body += "<div class=\"container\">\n";
  body += "<a class=\"navbar-brand fw-semibold\" href=\"/\">UTrello</a>\n";
  body += "<button\n";
  body += "class=\"navbar-toggler d-lg-none\"\n";
  body += "type=\"button\"\n";
  body += "data-bs-toggle=\"collapse\"\n";
  body += "data-bs-target=\"#collapsibleNavId\"\n";
  body += "aria-controls=\"collapsibleNavId\"\n";
  body += "aria-expanded=\"false\"\n";
  body += "aria-label=\"Toggle navigation\"\n";
  body += ">\n";
  body += "<span class=\"navbar-toggler-icon\"></span>\n";
  body += "</button>\n";
  body += "<div class=\"collapse navbar-collapse\" id=\"collapsibleNavId\">\n";
  body += "<ul class=\"navbar-nav me-auto mt-2 mt-lg-0\">\n";
  body += "<li class=\"nav-item\">\n";
  body += "<a class=\"nav-link\" href=\"/\">Home</a>\n";
  body += "</li>\n";
  body += "<li class=\"nav-item\">\n";
  body += "<a class=\"nav-link\" href=\"/task\">Task</a>\n";
  body += "</li>\n";
  body += "<li class=\"nav-item\">\n";
  body += "<a class=\"nav-link\" href=\"/event\"\n";
  body += ">Event <span class=\"visually-hidden\">(current)</span></a\n";
  body += ">\n";
  body += "</li>\n";
  body += "<li class=\"nav-item\">\n";
  body += "<a class=\"nav-link active\" href=\"/join_event\"\n";
  body += ">Join Event <span class=\"visually-hidden\">(current)</span></a\n";
  body += ">\n";
  body += "</li>\n";
  body += "<li class=\"nav-item\">\n";
  body += "<a class=\"nav-link\" href=\"/report_page\">Report</a>\n";
  body += "</li>\n";
  body += "</ul>\n";
  body += "\n";
  body += "<form action=\"/logout\" method=\"post\">\n";
  body += "<button class=\"btn btn-danger\" type=\"submit\">logout</button>\n";
  body += "</form>\n";
  body += "</div>\n";
  body += "</div>\n";
  body += "</nav>\n";
  body += "\n";
  body += "<section class=\"container my-5\">";
  body += "<h2 class=\"mb-4\">Join Event Invitations</h2>\n";
  body += "<div\n";
  body += "class=\"h-auto mx-auto flex-wrap justify-content-center gap-4 align-items-center\"\n";
  body += "style=\"display: flex\"\n";
  body += ">\n";

  if (myRes.getStatusCode() == StatuesCode::OK)
  {
    for (auto &&i : myRes.getBody())
    {
      smatch match;
      regex pattern("^\\d+");

      regex_search(i, match, pattern);

      string id = match[0];

      body += "<!-- Invitation Card Start -->\n";
      body += "<div class=\"invitation-card\" style=\"max-width: 500px\">\n";
      body += "<div class=\"event-title\">" + i + "</div>\n";
      body += "<div class=\"action-btns flex-row justify-content-around\">\n";
      body += "<form\n";
      body += "action=\"/confirm_join_event\"\n";
      body += "method=\"POST\"\n";
      body += "class=\"flex-row w-50\"\n";
      body += ">\n";
      body += "<input type=\"hidden\" name=\"invitation_id\" value=\"" + id + "\" />\n";
      body += "<button type=\"submit\" class=\"btn btn-success w-100\">\n";
      body += "✅ Confirm\n";
      body += "</button>\n";
      body += "</form>\n";
      body += "<form action=\"/reject_join_event\" method=\"POST\" class=\"flex-row w-50\">\n";
      body += "<input type=\"hidden\" name=\"invitation_id\" value=\"" + id + "\" />\n";
      body += "<button type=\"submit\" class=\"btn btn-danger w-100\">\n";
      body += "❌ Reject\n";
      body += "</button>\n";
      body += "</form>\n";
      body += "</div>\n";
      body += "</div>\n";
      body += "<!-- Invitation Card End -->\n";
    }
  }
  else
  {
    body += "<h4 class=\"mt-4\">Empty 👀</h4>";
  }
  body += "</div>\n";
  body += "</section>";
  body += "</body>\n";
  body += "\n";
  body += "<script src=\"/bootstrap.bundle.js\"></script>\n";
  body += "</html>\n";

  return body;
}
