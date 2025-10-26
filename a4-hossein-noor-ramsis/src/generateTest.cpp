#include "../includes/main.hpp"

int generateTest(System &system)
{
  string testName;
  getline(cin, testName, '\'');
  getline(cin, testName, '\'');
  testName = '\'' + testName + '\'';

  string templateName;
  getline(cin, templateName, '\'');
  getline(cin, templateName, '\'');
  templateName = '\'' + templateName + '\'';

  if (!system.isTemplateExist(templateName))
  {
    cout << "Could not find template: " << templateName << endl;
    return 1;
  }

  system.sortQuestions();

  Test *test = new Test(system, testName, templateName);
  system.addTest(test);

  cout << "Test " << testName << " was generated successfully." << endl;
  return 0;
}
