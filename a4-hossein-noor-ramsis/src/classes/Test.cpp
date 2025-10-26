#include "../../includes/main.hpp"

Test::Test(System &system, string testName, string templateName)
{
  _name = testName;
  Template t = system.getTemplate(templateName);

  for (auto &i : t.getSubjects())
  {
    vector<Quest *> questions = system.getQuestsBySubject().find(i.getName())->second;

    for (auto &j : questions)
    {

      if (j->getDifficulty() == i.getDifficulty())
      {
        _questions.push_back(j);
        i.decreaseCount();
      }

      if (!i.getCount())
      {
        break;
      }
    }
  }

  sort(_questions.begin(), _questions.end(), compareQuests);
}

string Test::getName()
{
  return _name;
}

vector<Quest *> Test::getQuestions()
{
  return _questions;
}

map<string, SubjectHistory> &Test::getSubjectHistory()
{
  return _subjectsHistory;
}

int Test::getCorrects()
{
  return _corrects;
}
void Test::increaseCorrects()
{
  _corrects++;
}

int Test::getIncorrects()
{
  return _incorrects;
}
void Test::increaseIncorrects()
{
  _incorrects++;
}

int Test::getBlanks()
{
  return _blanks;
}
void Test::increaseBlanks()
{
  _blanks++;
}

double Test::getScore()
{
  return _score;
}
void Test::setScore(double num)
{
  _score = num;
}

bool Test::isAttended()
{
  return _isAttended;
}
void Test::setIsAttended(bool status)
{
  _isAttended = status;
}

chrono::system_clock::time_point Test::getAttendedDate()
{
  return _attendDate;
}
void Test::setAttendedDate(chrono::system_clock::time_point date)
{
  _attendDate = date;
}