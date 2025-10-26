#include "../includes/main.hpp"

int createTemplate(System &system)
{
  string subjectString;
  vector<string> subjectParts;

  string templateName;
  getline(cin, templateName, '\'');
  getline(cin, templateName, '\'');
  templateName = '\'' + templateName + '\'';

  if (system.isTemplateExist(templateName))
  {
    cout << "Duplicate name: " << templateName << endl;
    return 1;
  }

  Template newTemplate = Template(templateName);

  string line;
  getline(cin, line);
  stringstream ss(line);

  while (ss >> subjectString)
  {
    subjectParts = splitByColon(subjectString);
    Subject newSubject = Subject(subjectParts[0], subjectParts[1], stoi(subjectParts[2]));
    newTemplate.addSubject(newSubject);
  }

  system.addTemplate(newTemplate);

  cout << "Template " << templateName << " was created successfully." << endl;

  return 0;
}
