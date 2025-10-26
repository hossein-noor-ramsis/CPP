#include "../../includes/main.hpp"

string Client::reportPage(MyResponse myRes)
{
  string body;

  body += "<!DOCTYPE html>\n";
  body += "<html lang=\"en\">\n";
  body += "<head>\n";
  body += "<meta charset=\"UTF-8\" />\n";
  body += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n";
  body += "<title>Report</title>\n";
  body += "\n";
  body += "<link rel=\"stylesheet\" href=\"/bootstrap.css\" />\n";
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
  body += "<a class=\"nav-link\" href=\"/event\">Event</a>\n";
  body += "</li>\n";
  body += "<li class=\"nav-item\">\n";
  body += "<a class=\"nav-link\" href=\"/join_event\">Join Event</a>\n";
  body += "</li>\n";
  body += "<li class=\"nav-item active\">\n";
  body += "<a class=\"nav-link active\" href=\"/report_page\">Report</a>\n";
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
  body += "<div class=\"container mt-5\">\n";
  body += "<h2 class=\"mb-4\">Generate Report</h2>\n";
  body += "\n";
  body += "<form\n";
  body += "id=\"report-form\"";
  body += "action=\"/report\"\n";
  body += "method=\"GET\"\n";
  body += "class=\"bg-white p-4 rounded shadow-sm\"\n";
  body += ">\n";
  body += "<div class=\"mb-3\">\n";
  body += "<label for=\"from\" class=\"form-label\">From Date</label>\n";
  body += "<input\n";
  body += "type=\"text\"\n";
  body += "class=\"form-control\"\n";
  body += "id=\"from\"\n";
  body += "name=\"from\"\n";
  body += "placeholder=\"YYYY/MM/DD\"\n";
  body += "value=\"1404/01/01\"";
  body += "/>\n";
  body += "</div>\n";
  body += "\n";
  body += "<div class=\"mb-3\">\n";
  body += "<label for=\"to\" class=\"form-label\">To Date</label>\n";
  body += "<input\n";
  body += "type=\"text\"\n";
  body += "class=\"form-control\"\n";
  body += "id=\"to\"\n";
  body += "name=\"to\"\n";
  body += "placeholder=\"YYYY/MM/DD\"\n";
  body += "required\n";
  body += "/>\n";
  body += "</div>\n";
  body += "\n";
  body += "<div class=\"mb-3\">\n";
  body += "<label for=\"type\" class=\"form-label\">Type</label>\n";
  body += "<select class=\"form-select\" id=\"type\" name=\"type\">\n";
  body += "<option value=\"all\">Select type</option>\n";
  body += "<option value=\"all\">All</option>\n";
  body += "<option value=\"task\">Task</option>\n";
  body += "<option value=\"event\">Event</option>\n";
  body += "<option value=\"periodic_event\">Periodic Event</option>\n";
  body += "<option value=\"join_event\">Join Event</option>\n";
  body += "</select>\n";
  body += "</div>\n";
  body += "\n";
  body += "<button type=\"submit\" class=\"btn btn-primary\">Get Report</button>\n";
  body += "</form>\n";
  body += "\n";
  body += "<div class=\"mt-5\">\n";
  body += "<h2>Report Result</h2>\n";
  body += "<pre\n";
  body += "id=\"reportResult\"\n";
  body += "class=\"bg-dark text-white p-3 rounded\"\n";
  body += "style=\"min-height: 100px\"\n";
  body += ">\n";
  body += "<!-- Report response will be shown here -->\n";

  if (myRes.getStatusCode() == StatuesCode::OK)
  {
    for (auto &&i : myRes.getBody())
    {
      body += "<p class=\"h5\">" + i + "</p>\n";
    }
  }
  else
  {
    body += "<p class=\"h5\">" + myRes.getStatusMessage() + "</p>\n";
  }

  body += "</pre>\n";
  body += "</div>\n";
  body += "</div>\n";
  body += "</body>\n";
  body += "\n";
  body += "<script src=\"/bootstrap.bundle.js\"></script>\n";
  body += "<script>\n";
  body += "document.getElementById(\"report-form\").addEventListener(\"submit\", function(event) {\n";
  body += "const input = document.getElementById(\"from\");\n";
  body += "if (!input.value.trim()) {\n";
  body += "input.value = \"1404/01/01\";\n";
  body += "}\n";
  body += "});\n";
  body += "</script>\n";
  body += "</html>\n";

  return body;
}
