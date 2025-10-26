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

  int signupHandler(MyRequest &req, MyResponse &res);
  int loginHandler(MyRequest &req, MyResponse &res);
  int logoutHandler(MyRequest &req, MyResponse &res);

  int addEventHandler(MyRequest &req, MyResponse &res);
  int addPeriodicEventHandler(MyRequest &req, MyResponse &res);

  int addTaskHandler(MyRequest &req, MyResponse &res);
  int editTaskHandler(MyRequest &req, MyResponse &res);
  int deleteTaskHandler(MyRequest &req, MyResponse &res);

  int reportHandler(MyRequest &req, MyResponse &res);

  int reportEventHandler(MyRequest &req, MyResponse &res);
  int reportJoinEventHandler(MyRequest &req, MyResponse &res);
  int reportPeriodicEventHandler(MyRequest &req, MyResponse &res);

  int reportTaskHandler(MyRequest &req, MyResponse &res);

  int addJoinEventHandler(MyRequest &req, MyResponse &res);
  int confirmJoinEventHandler(MyRequest &req, MyResponse &res);
  int rejectJoinEventHandler(MyRequest &req, MyResponse &res);
  int getJoinEventHandler(MyRequest &req, MyResponse &res);

  ~DataBase();
};

#endif
