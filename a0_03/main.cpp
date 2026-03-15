#include <iostream>

#include "App.h"
using namespace std;

int main() {
    App &app = App::getInstance();
    app.run();

    return 0;
}

// fix all fixable errors: Ctrl + .
