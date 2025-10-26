#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <memory>
#include <limits>
#include <iomanip>
#include <chrono>
#include <atomic>
#include <random>

using namespace std;

#include "./forwards.hpp"
#include "./enums.hpp"
#include "./consts.hpp"
#include "./structs.hpp"
#include "./prototypes.hpp"

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

#include "./view/Client.hpp"

#endif
