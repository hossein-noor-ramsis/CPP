#ifndef CONSTS_HPP
#define CONSTS_HPP

constexpr int SIDE_BAR_WIDTH = 216;
constexpr int TOP_BAR_HIGHT = 144;

namespace WindowSpace
{
  constexpr int HEIGHT = 720;
  constexpr int WIDTH = 1080;

  constexpr const char *WINDOW_NAME = "Bloons Tower Defense";
}

namespace AssetsSpace
{
  constexpr const char *BOARD_PATH = "./assets/board.txt";
  constexpr const char *FONT_PATH = "./assets/arial.ttf";
  constexpr const char *MUSIC_PATH = "./assets/music.mp3";

  constexpr const char *GRASS_PATH = "./assets/grass.png";
  constexpr const char *ROAD_PATH = "./assets/road.png";

  constexpr const char *BALLOON_PATH = "./assets/balloon.png";
  constexpr const char *PREGNANT_BALLOON_PATH = "./assets/heart_balloon.png";

  constexpr const char *NORMAL_TOWER_PATH = "./assets/normal_tower.png";
  constexpr const char *ICE_TOWER_PATH = "./assets/ice_tower.png";
  constexpr const char *BOMB_TOWER_PATH = "./assets/bomb_tower.png";

  constexpr const char *NORMAL_BULLET_PATH = "./assets/sprites/normal_bullet.png";
  constexpr const char *ICE_BULLET_PATH = "./assets/sprites/ice_bullet.png";
}

namespace BoardSpace
{
  constexpr float TILE_SIZE = 72;
  constexpr int HEIGHT = 8;
  constexpr int WIDTH = 12;
}

namespace TowerSpace
{
  constexpr int NORMAL_COST = 50;
  constexpr int ICE_COST = 100;
  constexpr int BOMB_COST = 200;
}
namespace PlayerSpace
{
  constexpr int MONEY = 210;
  constexpr int HP = 100;
}

const int WAVE_LAUNCH_GAP_SECS = 10;

const vector<AttackWave> ATTACKING_PLAN = {
    {{{"Normal", 5}}, {500, 700}},
    {{{"Normal", 10}, {"Pregnant", 5}}, {400, 600}},
    {{{"Normal", 15}, {"Pregnant", 10}}, {200, 400}},
};

const int FREEZE_TIME_IN_SEC = 5;

#endif
