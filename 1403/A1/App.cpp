//
// Created by Hossein on 15/03/2026.
//

#include "App.h"
#include "Utils/String.h"
#include "Views/ErrorView.h"

App App::_instance; // Definition

App& App::build()
{
  return _instance;
}

void App::addCommand(const string& name, const function<void(const vector<string>& body)>& callback)
{
  commands.insert({name, callback});
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void App::run()
{ // NOLINT(*-convert-member-functions-to-static)
  try
  {
    cout << "App Started!" << endl;
    string cmd;

    while (true)
    {
      getline(cin, cmd, '\n');

      vector<string> parts = String::split(cmd, ' ');
      const string& command = parts[0];

      if (command == "exit")
      {
        break;
      }

      // ReSharper disable once CppTooWideScopeInitStatement
      auto it = commands.find(command);

      if (it != commands.end())
      {
        parts.erase(parts.begin());
        it->second(parts);
      }
      else
      {
        cout << "Command not found" << endl;
      }
    }

    cout << "App Closed!" << endl;
  }
  catch (const exception& e)
  {
    ErrorView::print("Error: " + string(e.what()));
  }
}
