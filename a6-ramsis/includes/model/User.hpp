#ifndef USER_HPP
#define USER_HPP

class User
{
private:
  int _id;
  string _username;
  string _password;

  int _lastTaskId = 0;
  int _lastEventId = 0;
  int _lastDailyPeriodicEventId = 0;
  int _lastWeeklyPeriodicEventId = 0;
  int _lastMonthlyPeriodicEventId = 0;

public:
  map<int, shared_ptr<Event>> events;
  map<int, shared_ptr<JoinEvent>> joinEvents;
  map<int, shared_ptr<JoinEvent>> joinEventsInvitations;

  map<int, shared_ptr<DailyPeriodicEvent>> dailyPeriodicEvents;
  map<int, shared_ptr<WeeklyPeriodicEvent>> weeklyPeriodicEvents;
  map<int, shared_ptr<MonthlyPeriodicEvent>> monthlyPeriodicEvents;

  map<int, shared_ptr<Task>> tasks;

  multiset<shared_ptr<Activity>, ActivityDateComparator> calendar;

public:
  User();
  User(int id, string username, string password);

  string getUsername();
  string getPassword();

  int generateTaskId();
  int generateEventId();
  int generateDailyPeriodicEventId();
  int generateWeeklyPeriodicEventId();
  int generateMonthlyPeriodicEventId();

  vector<shared_ptr<Event>> convertDailyPeriodicEventsToEvents(ConvertOptions options);
  vector<shared_ptr<Event>> convertWeeklyPeriodicEventsToEvents(ConvertOptions options);
  vector<shared_ptr<Event>> convertMonthlyPeriodicEventsToEvents(ConvertOptions options);

  vector<Event> convertDailyPeriodicEventToEvents(DailyPeriodicEvent dailyPeriodicEvent);
  vector<Event> convertWeeklyPeriodicEventToEvents(WeeklyPeriodicEvent weeklyPeriodicEvent);
  vector<Event> convertMonthlyPeriodicEventToEvents(MonthlyPeriodicEvent monthlyPeriodicEvent);

  bool doseEventHaveOverlapWithEvents(Event event);
  bool doseEventHaveOverlapWithJoinEvents(Event event);
  bool doseEventHaveOverlapWithPeriodicEvents(Event event);

  bool doseJoinEventHaveOverlapWithEvents(JoinEvent joinEvent);
  bool doseJoinEventHaveOverlapWithJoinEvents(JoinEvent joinEvent);
  bool doseJoinEventHaveOverlapWithPeriodicEvents(JoinEvent joinEvent);

  bool doseDailyPeriodicEventHaveOverlapWithEvents(DailyPeriodicEvent dailyPeriodicEvent);
  bool doseDailyPeriodicEventHaveOverlapWithJoinEvents(DailyPeriodicEvent dailyPeriodicEvent);
  bool doseDailyPeriodicEventHaveOverlapWithPeriodicEvents(DailyPeriodicEvent dailyPeriodicEvent);

  bool doseWeeklyPeriodicEventHaveOverlapWithEvents(WeeklyPeriodicEvent weeklyPeriodicEvent);
  bool doseWeeklyPeriodicEventHaveOverlapWithJoinEvents(WeeklyPeriodicEvent weeklyPeriodicEvent);
  bool doseWeeklyPeriodicEventHaveOverlapWithPeriodicEvents(WeeklyPeriodicEvent weeklyPeriodicEvent);

  bool doseMonthlyPeriodicEventHaveOverlapWithEvents(MonthlyPeriodicEvent monthlyPeriodicEvent);
  bool doseMonthlyPeriodicEventHaveOverlapWithJoinEvents(MonthlyPeriodicEvent monthlyPeriodicEvent);
  bool doseMonthlyPeriodicEventHaveOverlapWithPeriodicEvents(MonthlyPeriodicEvent monthlyPeriodicEvent);

  int addEventsToCalendar(Date startDate, Date endDate);
  int addJoinEventsToCalendar(Date startDate, Date endDate);

  int addDailyPeriodicEventsToCalendar(Date startDate, Date endDate);
  int addWeeklyPeriodicEventsToCalendar(Date startDate, Date endDate);
  int addMonthlyPeriodicEventsToCalendar(Date startDate, Date endDate);

  int addTasksToCalendar(Date startDate, Date endDate);

  ~User();
};

#endif
