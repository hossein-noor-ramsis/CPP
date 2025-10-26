#include "../../includes/main.hpp"

SubjectHistory::SubjectHistory()
{
  _easyCorrects = 0;
  _easyIncorrects = 0;
  _easyBlanks = 0;

  _mediumCorrects = 0;
  _mediumIncorrects = 0;
  _mediumBlanks = 0;

  _hardCorrects = 0;
  _hardIncorrects = 0;
  _hardBlanks = 0;

  _corrects = 0;
  _incorrects = 0;
  _blanks = 0;

  _seenCount = 0;
}

SubjectHistory::~SubjectHistory()
{
}

int SubjectHistory::getEasyCorrects()
{
  return _easyCorrects;
}

void SubjectHistory::increaseEasyCorrects()
{
  _easyCorrects++;
}

int SubjectHistory::getEasyIncorrects()
{
  return _easyIncorrects;
}
void SubjectHistory::increaseEasyIncorrects()
{
  _easyIncorrects++;
}

int SubjectHistory::getEasyBlanks()
{
  return _easyBlanks;
}
void SubjectHistory::increaseEasyBlanks()
{
  _easyBlanks++;
}

int SubjectHistory::getMediumCorrects()
{
  return _mediumCorrects;
}
void SubjectHistory::increaseMediumCorrects()
{
  _mediumCorrects++;
}

int SubjectHistory::getMediumIncorrects()
{
  return _mediumIncorrects;
}
void SubjectHistory::increaseMediumIncorrects()
{
  _mediumIncorrects++;
}

int SubjectHistory::getMediumBlanks()
{
  return _mediumBlanks;
}
void SubjectHistory::increaseMediumBlanks()
{
  _mediumBlanks++;
}

int SubjectHistory::getHardCorrects()
{
  return _hardCorrects;
}
void SubjectHistory::increaseHardCorrects()
{
  _hardCorrects++;
}

int SubjectHistory::getHardIncorrects()
{
  return _hardIncorrects;
}
void SubjectHistory::increaseHardIncorrects()
{
  _hardIncorrects++;
}

int SubjectHistory::getHardBlanks()
{
  return _hardBlanks;
}
void SubjectHistory::increaseHardBlanks()
{
  _hardBlanks++;
}

int SubjectHistory::getCorrects()
{
  return _corrects;
}
void SubjectHistory::increaseCorrects()
{
  _corrects++;
}

int SubjectHistory::getIncorrects()
{
  return _incorrects;
}
void SubjectHistory::increaseIncorrects()
{
  _incorrects++;
}

int SubjectHistory::getBlanks()
{
  return _blanks;
}
void SubjectHistory::increaseBlanks()
{
  _blanks++;
}

int SubjectHistory::getSeenCount()
{
  return _seenCount;
}
void SubjectHistory::increaseSeenCount()
{
  _seenCount++;
}