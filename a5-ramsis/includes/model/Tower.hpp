class Tower
{
public:
  float _x;
  float _y;
  float range = 120;

  Texture texture;
  Sprite sprite;
  CircleShape rangeCircle;

  bool isCoolingDown = true;
  float coolDowneventStartTimeInSec = 2;
  float eventStartTimeInSec = 0;

  Tower();
  Tower(float x, float y);
  Tower(System system, float x, float y);
  virtual ~Tower();

  virtual void attack(System &system, shared_ptr<Enemy> enemy);

  void draw(RenderWindow &window);
  bool isBalloonInRange(const Sprite &balloon);
  void coolDownTimer(System system);
};
