#include "../includes/main.hpp"

int reportTests(System &system)
{
  cout << "Results per attended tests: \n"
       << endl;

  for (auto &&i : system.getSortedTests())
  {
    string testName = i.first.substr(1, i.first.length() - 2);

    if (!i.second->isAttended())
    {
      continue;
    }

    cout << testName << ": " << i.second->getCorrects() << " corrects, ";
    cout << i.second->getIncorrects() << " incorrects and " << i.second->getBlanks() << " blanks.";
    cout << " Score: " << fixed << setprecision(3) << truncateTo(i.second->getScore(), 3) << "%." << endl;
  }

  return 0;
}
