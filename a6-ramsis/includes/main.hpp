#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <cmath>
#include <atomic>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <memory>
#include <random>
#include <cstdlib>
#include <regex>

using namespace std;

#include "./consts.hpp"
#include "./enums.hpp"
#include "./forwards.hpp"
#include "./prototypes.hpp"
#include "./structs.hpp"

#include "./controller/Request.hpp"
#include "./controller/Response.hpp"

#include "./model/Time.hpp"
#include "./model/Date.hpp"
#include "./model/Task.hpp"

#include "./model/Activity.hpp"
#include "./model/Event/EventBase.hpp"
#include "./model/Event/Event.hpp"
#include "./model/Event/JoinEvent.hpp"
#include "./model/Event/DailyPeriodicEvent.hpp"
#include "./model/Event/WeeklyPeriodicEvent.hpp"
#include "./model/Event/MonthlyPeriodicEvent.hpp"

#include "./model/User.hpp"
#include "./model/DataBase.hpp"

#include "./controller/Server.hpp"
#include "../server/server.hpp"

#include "./view/Client.hpp"
#include "./handlers.hpp"

#endif
