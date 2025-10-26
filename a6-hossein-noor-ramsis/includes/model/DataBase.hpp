#ifndef SYSTEM_HPP
#define SYSTEM_HPP

class DataBase
{
private:
  int _lastUserId = 0;
  int _lastJoinEventId = 0;

  Date _currentDate = Date(CURRENT_DATE);
  set<Date> _holidays;

  map<int, shared_ptr<User>> _users;
  map<int, shared_ptr<JoinEvent>> _joinEvents;

public:
  DataBase();

  int generateUserId();
  int generateJoinEventId();

  bool isUserExist(string username);
  shared_ptr<User> getUser(string username);

  Date getCurrentDate();
  set<Date> getHolidays();

  int loadData(vector<vector<string>> data);

  bool doesEventHaveOverlapWithHolidays(Event event);
  bool doesJoinEventHaveOverlapWithHolidays(JoinEvent joinEvent);

  bool doesDailyPeriodicEventHaveOverlapWithHolidays(DailyPeriodicEvent dailyPeriodicEvent);
  bool doesWeeklyPeriodicEventHaveOverlapWithHolidays(WeeklyPeriodicEvent weeklyPeriodicEvent);
  bool doesMonthlyPeriodicEventHaveOverlapWithHolidays(MonthlyPeriodicEvent monthlyPeriodicEvent);

  vector<Event> convertDailyPeriodicEventToEvents(DailyPeriodicEvent dailyPeriodicEvent);
  vector<Event> convertWeeklyPeriodicEventToEvents(WeeklyPeriodicEvent weeklyPeriodicEvent);
  vector<Event> convertMonthlyPeriodicEventToEvents(MonthlyPeriodicEvent monthlyPeriodicEvent);

  int signupHandler(Request &req, Response &res);
  int loginHandler(Request &req, Response &res);
  int logoutHandler(Request &req, Response &res);

  int addEventHandler(Request &req, Response &res);
  int addPeriodicEventHandler(Request &req, Response &res);

  int addTaskHandler(Request &req, Response &res);
  int editTaskHandler(Request &req, Response &res);
  int deleteTaskHandler(Request &req, Response &res);

  int reportHandler(Request &req, Response &res);

  int reportEventHandler(Request &req, Response &res);
  int reportJoinEventHandler(Request &req, Response &res);
  int reportPeriodicEventHandler(Request &req, Response &res);

  int reportTaskHandler(Request &req, Response &res);

  int addJoinEventHandler(Request &req, Response &res);
  int confirmJoinEventHandler(Request &req, Response &res);
  int rejectJoinEventHandler(Request &req, Response &res);
  int getJoinEventHandler(Request &req, Response &res);

  ~DataBase();
};

#endif
