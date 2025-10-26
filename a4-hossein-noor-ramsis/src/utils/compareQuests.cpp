#include "../../includes/main.hpp"

bool compareQuests(Quest *a, Quest *b)
{
  if (a->getSubject() != b->getSubject())
  {
    return a->getSubject() < b->getSubject();
  }

  return a->getQuestionText() < b->getQuestionText();
}
