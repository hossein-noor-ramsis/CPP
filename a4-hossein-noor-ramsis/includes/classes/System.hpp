class System
{
private:
  map<string, vector<Quest *>> _questsBySubject;
  map<string, Template> _templates;
  map<string, Test *> _tests;

  int loadQuestions(const vector<vector<string>> &data);

public:
  User user;

  System(const vector<vector<string>> &data);
  ~System();

  void addTemplate(Template newTemplate);
  Template getTemplate(string templateName);

  void addTest(Test *newTest);
  Test *getTest(string testName);
  vector<pair<string, Test *>> getSortedTests();

  int sortQuestions();
  map<string, vector<Quest *>> &getQuestsBySubject();

  bool isTemplateExist(const string &templateName);
  bool isTestExist(const string &testName);
};
