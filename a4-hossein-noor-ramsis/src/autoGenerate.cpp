#include "../includes/main.hpp"

int autoGenerate(System &system)
{
  string testName;
  getline(cin, testName, '\'');
  getline(cin, testName, '\'');
  testName = '\'' + testName + '\'';

  system.user.generateDefaultTemplate(system);

  vector<string> defaultTemplates = system.user.getDefaultTemplates();

  if (!system.isTemplateExist(defaultTemplates.back()))
  {
    cout << "Could not find template: " << defaultTemplates.back() << endl;
    return 1;
  }

  system.sortQuestions();

  Test *test = new Test(system, testName, defaultTemplates.back());
  system.addTest(test);

  cout << "Test " << testName << " was generated successfully." << endl;

  return 0;
}
