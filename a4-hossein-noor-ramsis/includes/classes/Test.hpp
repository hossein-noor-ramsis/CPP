class Test
{
private:
  string _name;
  vector<Quest *> _questions;

  map<string, SubjectHistory> _subjectsHistory;

  int _corrects = 0;
  int _incorrects = 0;
  int _blanks = 0;
  double _score = 0;
  bool _isAttended = false;

  chrono::system_clock::time_point _attendDate;

public:
  Test() = default;
  Test(System &system, string testName, string templateName);

  string getName();
  vector<Quest *> getQuestions();

  map<string, SubjectHistory> &getSubjectHistory();

  int getCorrects();
  void increaseCorrects();

  int getIncorrects();
  void increaseIncorrects();

  int getBlanks();
  void increaseBlanks();

  double getScore();
  void setScore(double num);

  bool isAttended();
  void setIsAttended(bool status);

  chrono::system_clock::time_point getAttendedDate();
  void setAttendedDate(chrono::system_clock::time_point date);
};
