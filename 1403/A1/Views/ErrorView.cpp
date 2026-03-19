//
// Created by Hossein on 17/03/2026.
//

#include "ErrorView.h"

#include <iostream>
#include <ostream>

void ErrorView::print(const string& message)
{
  // system("cls");

  cerr << "=============================================================" << endl;
  cerr << "* " << message << " *" << endl;
  cerr << "=============================================================" << endl;
  cerr << "* enter help: to show the help menu, exit: to close the app *\n" << endl;
}
