#ifndef STRUCTS
#define STRUCTS

typedef struct structs
{
  Sprite draggingSprite;
  bool isDragging = false;
  TowerTypes towerType = TowerTypes::BASIC_TOWER;
} DragObj;

typedef struct
{
  map<string, int> enemiesCount;

  pair<int, int> enemyLaunchGapMs;
} AttackWave;

#endif
