#ifndef CONSTS_HPP
#define CONSTS_HPP

constexpr const char *CURRENT_DATE = "1404/1/1";

namespace Method
{
  constexpr const char *GET = "GET";
  constexpr const char *POST = "POST";
  constexpr const char *PATCH = "PATCH";
  constexpr const char *PUT = "PUT";
  constexpr const char *DELETE = "DELETE";
}

namespace StatuesCode
{
  constexpr int OK = 200;
  constexpr int EMPTY = 204;
  constexpr int NOT_FOUND = 404;
  constexpr int BAD_REQUEST = 400;
  constexpr int PERMISSION_DENIED = 403;
  constexpr int CONFLICT = 409;
  constexpr int INTERNAL_SERVER_ERROR = 500;
};

namespace StatusMessage
{
  constexpr const char *OK = "OK";
  constexpr const char *EMPTY = "Empty";
  constexpr const char *NOT_FOUND = "Not Found";
  constexpr const char *BAD_REQUEST = "Bad Request";
  constexpr const char *PERMISSION_DENIED = "Permission Denied";
  constexpr const char *OVERLAP = "Overlap";
  constexpr const char *HOLIDAY_FOUND = "Holiday Found";
};

namespace ServerRoutes
{
  constexpr const char *SIGNUP = "signup";
  constexpr const char *LOGIN = "login";
  constexpr const char *LOGOUT = "logout";

  constexpr const char *TASK = "task";
  constexpr const char *EVENT = "event";
  constexpr const char *PERIODIC_EVENT = "periodic_event";

  constexpr const char *JOIN_EVENT = "join_event";
  constexpr const char *CONFIRM_JOIN_EVENT = "confirm_join_event";
  constexpr const char *REJECT_JOIN_EVENT = "reject_join_event";

  constexpr const char *REPORT = "report";
}

namespace PeriodicEventsType
{
  constexpr const char *DAILY = "Daily";
  constexpr const char *WEEKLY = "Weekly";
  constexpr const char *MONTHLY = "Monthly";
}

namespace EventsType
{
  constexpr const char *EVENT = "Event";
  constexpr const char *JOIN_EVENT = "Join_Event";
}

namespace UserKey
{
  constexpr const char *USERNAME = "username";
  constexpr const char *PASSWORD = "password";
}

namespace TaskKey
{
  constexpr const char *TASK_ID = "task_id";

  constexpr const char *DATE = "date";
  constexpr const char *TIME = "time";

  constexpr const char *TITLE = "title";
  constexpr const char *DESCRIPTION = "description";
}

namespace EventKey
{
  constexpr const char *TYPE = "type";

  constexpr const char *DATE = "date";
  constexpr const char *START_TIME = "start_time";
  constexpr const char *DURATION = "duration";

  constexpr const char *TITLE = "title";
  constexpr const char *DESCRIPTION = "description";
}

namespace JoinEventKey
{
  constexpr const char *INVITATION_ID = "invitation_id";
  constexpr const char *TYPE = "type";

  constexpr const char *DATE = "date";
  constexpr const char *START_TIME = "start_time";
  constexpr const char *END_TIME = "end_time";

  constexpr const char *TITLE = "title";
  constexpr const char *DESCRIPTION = "description";

  constexpr const char *GUESTS = "guests";
}

namespace PeriodicEventKey
{
  constexpr const char *TYPE = "type";

  constexpr const char *DATE = "date";

  constexpr const char *START_DATE = "start_date";
  constexpr const char *END_DATE = "end_date";

  constexpr const char *START_TIME = "start_time";
  constexpr const char *DURATION = "duration";

  constexpr const char *TITLE = "title";
  constexpr const char *DESCRIPTION = "description";

  constexpr const char *WEEK_DAYS = "week_days";
  constexpr const char *DAY = "day";
}

namespace ActivityKey
{
  constexpr const char *DATE = "date";
  constexpr const char *TIME = "time";
  constexpr const char *START_TIME = "start_time";

  constexpr const char *TITLE = "title";
  constexpr const char *DESCRIPTION = "description";
}

namespace ReportKey
{
  constexpr const char *TYPE = "type";

  constexpr const char *FROM = "from";
  constexpr const char *TO = "to";
}

namespace ReportType
{
  constexpr const char *PERIODIC_EVENT = "periodic_event";
  constexpr const char *EVENT = "event";
  constexpr const char *TASK = "task";
  constexpr const char *JOIN_EVENT = "join_event";
}

namespace DayOfWeek
{
  constexpr const char *FRIDAY = "Friday";
  constexpr const char *SATURDAY = "Saturday";
  constexpr const char *SUNDAY = "Sunday";
  constexpr const char *MONDAY = "Monday";
  constexpr const char *TUESDAY = "Tuesday";
  constexpr const char *WEDNESDAY = "Wednesday";
  constexpr const char *THURSDAY = "Thursday";
}

#endif
