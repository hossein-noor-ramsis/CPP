#include "../includes/main.hpp"

int reportAll(System &system)
{
  cout << "Total report: \n " << endl;

  int totalCorrects = 0, totalIncorrects = 0, totalBlanks = 0;

  for (auto &&i : system.user.getSubjectHistory())
  {
    if (i.second.getSeenCount() == 0)
    {
      continue;
    }

    double score = (double)i.second.getCorrects() / i.second.getSeenCount() * 100;

    cout << i.first << ": " << i.second.getCorrects() << " corrects, ";
    cout << i.second.getIncorrects() << " incorrects and " << i.second.getBlanks() << " blanks.";
    cout << " Score: " << fixed << setprecision(3) << truncateTo(score, 3) << "%." << endl;

    totalCorrects += i.second.getCorrects();
    totalIncorrects += i.second.getIncorrects();
    totalBlanks += i.second.getBlanks();
  }

  cout << "\nTotal results: " << totalCorrects << " corrects, ";
  cout << totalIncorrects << " incorrects and " << totalBlanks << " blanks.";

  double totalScore = (double)totalCorrects / (totalCorrects + totalBlanks + totalIncorrects) * 100.0;
  cout << "\nTotal score: " << fixed << setprecision(3) << truncateTo(totalScore, 3) << "%." << endl;

  return 0;
}
