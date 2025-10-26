class User
{
private:
  map<Subject, vector<Quest *>> _subjects;
  map<string, Test *> _tests;
  map<string, SubjectHistory> _subjectsHistory;
  vector<string> _defaultTemplates;

public:
  User();

  ~User();

  void generateDefaultTemplate(System &system);
  map<string, SubjectHistory> &getSubjectHistory();

  vector<string> getDefaultTemplates();
};
