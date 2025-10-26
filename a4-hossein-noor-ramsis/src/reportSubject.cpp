#include "../includes/main.hpp"

int reportSubject(System &system)
{
  string subjectName;
  cin >> subjectName;

  auto subjects = system.user.getSubjectHistory();
  auto subject = subjects[subjectName];

  cout << "Results for " << subjectName << ":\n " << endl;

  cout << "Easy: " << subject.getEasyCorrects() << " corrects, ";
  cout << subject.getEasyIncorrects() << " incorrects and ";
  cout << subject.getEasyBlanks() << " blanks." << endl;

  cout << "Medium: " << subject.getMediumCorrects() << " corrects, ";
  cout << subject.getMediumIncorrects() << " incorrects and ";
  cout << subject.getMediumBlanks() << " blanks." << endl;

  cout << "Hard: " << subject.getHardCorrects() << " corrects, ";
  cout << subject.getHardIncorrects() << " incorrects and ";
  cout << subject.getHardBlanks() << " blanks.\n " << endl;

  double totalScore = (double)subject.getCorrects() / subject.getSeenCount() * 100.0;
  cout << "Total score: " << fixed << setprecision(3) << truncateTo(totalScore, 3) << "%." << endl;

  return 0;
}
