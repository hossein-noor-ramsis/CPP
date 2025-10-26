class Enemy
{
public:
  int id = 1;
  int tileIndex = 0;

  string type;
  int hp = 50;
  int money = 5;
  Effect effect = Effect::NONE;
  float eventStartTimeInSec = 0;

  Texture texture;
  Sprite sprite;

  float _x;
  float _y;

  bool isSpawned = false;
  float speed = 1;
  Direction direction = Direction::NONE;

public:
  Enemy(System &system, int id);
  virtual ~Enemy();

  int update(System &system);
  
  void freeze(System &system);
  void unFreeze(System &system);

  virtual void damage(System &system, Bullet &bullet);
};
