#include "../../includes/main.hpp"

User::User()
{
}

User::~User()
{
}

void User::generateDefaultTemplate(System &system)
{
  vector<pair<string, int>> analyzedQuestsBySubject;

  for (auto &&i : _subjectsHistory)
  {
    string subjectName = i.first;

    double priority = (double)i.second.getCorrects() / i.second.getSeenCount();

    analyzedQuestsBySubject.push_back({subjectName, priority});
  }

  sort(analyzedQuestsBySubject.begin(), analyzedQuestsBySubject.end(),
       [](const pair<string, int> &a, const pair<string, int> &b)
       {
         if (a.second != b.second)
         {
           return a.second < b.second;
         }

         return a.first < b.first;
       });

  string templateName = "\'default " + to_string(_defaultTemplates.size() + 1) + "\'";

  _defaultTemplates.push_back(templateName);
  Template newTemplate = Template(templateName);

  auto it = analyzedQuestsBySubject.begin();

  Subject newSubject = Subject(it->first, DifficultySpace::EASY, 3);

  newSubject = Subject(it->first, DifficultySpace::EASY, 3);
  newTemplate.addSubject(newSubject);

  newSubject = Subject(it->first, DifficultySpace::MEDIUM, 2);
  newTemplate.addSubject(newSubject);

  newSubject = Subject(it->first, DifficultySpace::HARD, 1);
  newTemplate.addSubject(newSubject);

  ++it;

  newSubject = Subject(it->first, DifficultySpace::EASY, 2);
  newTemplate.addSubject(newSubject);

  newSubject = Subject(it->first, DifficultySpace::MEDIUM, 1);
  newTemplate.addSubject(newSubject);

  newSubject = Subject(it->first, DifficultySpace::HARD, 1);
  newTemplate.addSubject(newSubject);

  system.addTemplate(newTemplate);
}

map<string, SubjectHistory> &User::getSubjectHistory()
{
  return _subjectsHistory;
}

vector<string> User::getDefaultTemplates()
{
  return _defaultTemplates;
}
