enum GAME_STATE
{
  IN_GAME,
  PAUSE_MENU,
  MAIN_MENU,
  VICTORY_SCREEN,
  GAME_OVER_SCREEN,
  EXIT,
};

enum TileTypes
{
  GRASS,
  ROAD,
};

enum TowerTypes
{
  BASIC_TOWER,
  ICE_TOWER,
  BOMB_TOWER,
};

enum Direction
{
  NONE,
  LEFT,
  RIGHT,
  TOP,
  DOWN,
};

enum class Effect
{
  NONE,
  FREEZE,
};
