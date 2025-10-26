#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <memory>
#include <limits>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <queue>
#include <atomic>
#include <random>
#include <type_traits>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

#include "./forwards.hpp"
#include "./enums.hpp"
#include "./structs.hpp"
#include "./consts.hpp"

#include "./model/Enemy.hpp"
#include "./model/Enemies/NormalBalloon.hpp"
#include "./model/Enemies/PregnantBalloon.hpp"
#include "./model/Round.hpp"

#include "./model/Bullet.hpp"
#include "./model/Bullets/Bomb.hpp"
#include "./model/Bullets/NormalBullet.hpp"
#include "./model/Bullets/IceBullet.hpp"

#include "./model/Tower.hpp"

#include "./model/Towers/NormalTower.hpp"
#include "./model/Towers/BombTower.hpp"
#include "./model/Towers/IceTower.hpp"

#include "./model/Tile.hpp"
#include "./model/Board.hpp"
#include "./model/TopBar.hpp"
#include "./model/SideBar.hpp"

#include "./model/Player.hpp"
#include "./model/System.hpp"

#include "./prototypes.hpp"

#endif
