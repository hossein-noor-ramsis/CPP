#include "../includes/main.hpp"

int app(System &system)
{
  string command;

  while (getline(cin, command, ' '))
  {
    command = trim(command);

    if (command == CommandSpace::CREATE_TEMPLATE)
    {
      createTemplate(system);
      continue;
    }
    else if (command == CommandSpace::GENERATE_TEST)
    {
      generateTest(system);
      continue;
    }
    else if (command == CommandSpace::AUTO_GENERATE)
    {
      autoGenerate(system);
      continue;
    }
    else if (command == CommandSpace::ATTEND)
    {
      attend(system);
      continue;
    }
    else if (command == CommandSpace::REPORT)
    {
      string flag;
      cin >> flag;

      flag = trim(flag);

      if (flag == ReportFlagSpace::ALL)
      {
        reportAll(system);
        continue;
      }
      else if (flag == ReportFlagSpace::SUBJECT)
      {
        reportSubject(system);
        continue;
      }
      else if (flag == ReportFlagSpace::TEST)
      {
        reportTest(system);
        continue;
      }
      else if (flag == ReportFlagSpace::TESTS)
      {
        reportTests(system);
        continue;
      }
      else
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
  }

  return 0;
}