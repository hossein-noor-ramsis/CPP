#include "../../includes/main.hpp"

bool compareByPriorityAndName(Quest *a, Quest *b)
{
  if (a->getPriority() > b->getPriority())
  {
    return true;
  }

  return a->getQuestionText() < b->getQuestionText();
}
