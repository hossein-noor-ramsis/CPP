#include "../../includes/main.hpp"

int System::loadQuestions(const vector<vector<string>> &data)
{
  for (auto i : data)
  {
    Quest *quest = new Quest(i);

    if (_questsBySubject.find(i[7]) != _questsBySubject.end())
    {
      _questsBySubject[i[7]].push_back(quest);
      continue;
    }

    vector<Quest *> quests = {quest};
    _questsBySubject.insert({i[7], quests});
    SubjectHistory subjectHistory;
    user.getSubjectHistory().insert({trim(i[7]), subjectHistory});
  }

  return 0;
}

System::System(const vector<vector<string>> &data)
{
  loadQuestions(data);
}

System::~System()
{
  for (auto &[subject, questList] : _questsBySubject)
  {
    for (Quest *quest : questList)
    {
      delete quest;
    }
  }

  _questsBySubject.clear();

  for (auto &[subject, test] : _tests)
  {
    delete test;
  }

  _tests.clear();
}

vector<pair<string, Test *>> System::getSortedTests()
{

  vector<pair<string, Test *>> _sortedTests(_tests.begin(), _tests.end());

  sort(_sortedTests.begin(), _sortedTests.end(), [](const pair<string, Test *> &a, const pair<string, Test *> &b)
       {
         if (!a.second->isAttended() && b.second->isAttended())
         {
           return false;
         }

         if (a.second->isAttended() && !b.second->isAttended())
         {
           return true;
         }
         
         return a.second->getAttendedDate() < b.second->getAttendedDate(); });

  return _sortedTests;
}

int System::sortQuestions()
{
  for (auto &i : _questsBySubject)
  {
    for (auto &j : i.second)
    {
      int newPriority = 3 * j->getNumOfIncorrects() + j->getNumOfBlanks() - 2 * j->getNumOfCorrects();
      j->setPriority(newPriority);
    }
  }

  for (auto &i : _questsBySubject)
  {
    sort(i.second.begin(), i.second.end(), compareByPriorityAndName);
  }

  return 0;
}

void System::addTemplate(Template newTemplate)
{
  if (!isTemplateExist(newTemplate.getName()))
  {
    _templates[newTemplate.getName()] = newTemplate;
  }
}

void System::addTest(Test *newTest)
{
  if (!isTestExist(newTest->getName()))
  {
    _tests[newTest->getName()] = newTest;
  }
}

Template System::getTemplate(string templateName)
{
  return _templates.find(templateName)->second;
}

Test *System::getTest(string testName)
{
  return _tests[testName];
}

bool System::isTemplateExist(const string &templateName)
{
  return _templates.find(templateName) != _templates.end();
}

bool System::isTestExist(const string &testName)
{
  return _tests.find(testName) != _tests.end();
}

map<string, vector<Quest *>> &System::getQuestsBySubject()
{
  return _questsBySubject;
}
