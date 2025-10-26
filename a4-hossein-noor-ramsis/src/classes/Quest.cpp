#include "../../includes/main.hpp"

Quest::Quest(vector<string> &data)
{
  _questionText = data[0];

  _option1 = data[1];
  _option2 = data[2];
  _option3 = data[3];
  _option4 = data[4];

  _currectAnswer = stoi(data[5]);

  _difficulty = data[6];
  _subject = data[7];

  _numOfCorrects = 0;
  _numOfIncorrects = 0;
  _numOfBlanks = 0;

  _priority = 0;

  _selectedAnswer = 0;
}

Quest::~Quest()
{
}

string Quest::getSubject()
{
  return _subject;
}

string Quest::getQuestionText()
{
  return _questionText;
}

string Quest::getDifficulty()
{
  return _difficulty;
}

string Quest::getOption1()
{
  return _option1;
}
string Quest::getOption2()
{
  return _option2;
}
string Quest::getOption3()
{
  return _option3;
}
string Quest::getOption4()
{
  return _option4;
}

int Quest::getCurrectAnswer()
{
  return _currectAnswer;
}

int Quest::getPriority()
{
  return _priority;
}

void Quest::setPriority(int newPriority)
{
  _priority = newPriority;
}

int Quest::getNumOfCorrects()
{
  return _numOfCorrects;
}

void Quest::setNumOfCorrects(int num)
{
  _numOfCorrects = num;
}

int Quest::getNumOfIncorrects()
{
  return _numOfIncorrects;
}

void Quest::setNumOfIncorrects(int num)
{
  _numOfIncorrects = num;
}

int Quest::getNumOfBlanks()
{
  return _numOfBlanks;
}

void Quest::setNumOfBlanks(int num)
{
  _numOfBlanks = num;
}

int Quest::getSelectedAnswer()
{
  return _selectedAnswer;
}

void Quest::setSelectedAnswer(int num)
{
  _selectedAnswer = num;
}