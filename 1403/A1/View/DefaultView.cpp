//
// Created by Hossein on 17/03/2026.
//

#include "DefaultView.h"

#include <iostream>
#include <sstream>

void DefaultView::print(const string& message)
{
  // system("cls");

  cout << "=============================================================" << endl;
  cout << "* " << message << " *" << endl;
  cout << "=============================================================" << endl;
  cout << "* enter help: to show the help menu, exit: to close the app *\n" << endl;
}
