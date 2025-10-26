#include "../includes/main.hpp"

int attend(System &system)
{
  string testName;
  getline(cin, testName, '\'');
  getline(cin, testName, '\'');
  testName = '\'' + testName + '\'';
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (!system.isTestExist(testName))
  {
    cout << "Could not find test: " << testName << endl;
    return 1;
  }

  Test *test = system.getTest(testName);

  testName = testName.substr(1, testName.length() - 2);
  string answer;
  int qNum = 1;

  vector<Quest *> questions = test->getQuestions();

  cout << testName << ":" << endl;
  for (unsigned int i = 0; i < questions.size(); i++)
  {
    cout << '\n'
         << qNum << ") " << questions[i]->getQuestionText() << endl;

    cout << "    1. " << questions[i]->getOption1() << ((questions[i]->getSelectedAnswer() == 1) ? " <-" : " ") << endl;
    cout << "    2. " << questions[i]->getOption2() << ((questions[i]->getSelectedAnswer() == 2) ? " <-" : " ") << endl;
    cout << "    3. " << questions[i]->getOption3() << ((questions[i]->getSelectedAnswer() == 3) ? " <-" : " ") << endl;
    cout << "    4. " << questions[i]->getOption4() << ((questions[i]->getSelectedAnswer() == 4) ? " <-" : " ") << endl;

    while (true)
    {
      cout << "Your answer: ";
      getline(cin, answer);

      if ((trim(answer) == "previous") && (i != 0))
      {
        qNum = qNum - 2;
        i = i - 2;
        break;
      }

      if (trim(answer) == "1")
      {
        questions[i]->setSelectedAnswer(1);
        break;
      }
      else if (trim(answer) == "2")
      {
        questions[i]->setSelectedAnswer(2);
        break;
      }
      else if (trim(answer) == "3")
      {
        questions[i]->setSelectedAnswer(3);
        break;
      }
      else if (trim(answer) == "4")
      {
        questions[i]->setSelectedAnswer(4);
        break;
      }
      else if (trim(answer) == "")
      {
        questions[i]->setSelectedAnswer(0);
        break;
      }
      else
      {
        cout << "Invalid answer, please try again." << endl;
      }
    }

    qNum++;
  }

  for (auto &i : questions)
  {
    if (i->getSelectedAnswer() == 0)
    {
      i->setNumOfBlanks(i->getNumOfBlanks() + 1);

      test->increaseBlanks();
      test->getSubjectHistory()[i->getSubject()].increaseBlanks();

      if (i->getDifficulty() == DifficultySpace::EASY)
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseEasyBlanks();
      }
      else if (i->getDifficulty() == DifficultySpace::MEDIUM)
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseMediumBlanks();
      }
      else
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseHardBlanks();
      }

      system.user.getSubjectHistory()[i->getSubject()].increaseBlanks();
    }
    else if (i->getSelectedAnswer() == i->getCurrectAnswer())
    {
      i->setNumOfCorrects(i->getNumOfCorrects() + 1);

      test->increaseCorrects();
      test->getSubjectHistory()[i->getSubject()].increaseCorrects();

      if (i->getDifficulty() == DifficultySpace::EASY)
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseEasyCorrects();
      }
      else if (i->getDifficulty() == DifficultySpace::MEDIUM)
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseMediumCorrects();
      }
      else
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseHardCorrects();
      }

      system.user.getSubjectHistory()[i->getSubject()].increaseCorrects();
    }
    else
    {
      i->setNumOfIncorrects(i->getNumOfIncorrects() + 1);

      test->increaseIncorrects();
      test->getSubjectHistory()[i->getSubject()].increaseIncorrects();

      if (i->getDifficulty() == DifficultySpace::EASY)
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseEasyIncorrects();
      }
      else if (i->getDifficulty() == DifficultySpace::MEDIUM)
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseMediumIncorrects();
      }
      else
      {
        system.user.getSubjectHistory()[i->getSubject()].increaseHardIncorrects();
      }

      system.user.getSubjectHistory()[i->getSubject()].increaseIncorrects();
    }

    test->setScore((double)test->getCorrects() / test->getQuestions().size() * 100);
    test->getSubjectHistory()[i->getSubject()].increaseSeenCount();

    system.user.getSubjectHistory()[i->getSubject()].increaseSeenCount();
    i->setSelectedAnswer(0);
  }

  test->setAttendedDate(chrono::system_clock::now());
  test->setIsAttended(true);

  cout << "\nFinished " << testName << "." << endl;

  return 0;
}
