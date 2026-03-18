#include "App.h"
#include "Controller/OfferedCoursesController.h"
#include "Controller/TakenCoursesController.h"
#include "consts.h"

using namespace std;

int main()
{
  DB db;
  App& app = App::build();

  // controllers start
  const auto offeredCoursesController = OfferedCoursesController(db);
  const auto takenCoursesController = TakenCoursesController(db);
  // controllers end

  // commands start
  app.addCommand(Command::ADD_OFFERED_COURSES, [&](const vector<string>& body) {
    offeredCoursesController.AddOfferedCourses(body);
  });

  app.addCommand(Command::ADD_TAKEN_COURSES, [&](const vector<string>& body) {
    takenCoursesController.AddTakenCourses(body);
  });

  app.addCommand(Command::GET_OFFERED_COURSES, [&](const vector<string>& body) {
    offeredCoursesController.AddOfferedCourses(body);
  });
  // commands end

  app.run();

  return 0;
}

// fix all fixable errors: Ctrl + .
