class Bullet
{
public:
  Texture texture;
  Sprite sprite;

  Effect effect = Effect::NONE;

  float fromX;
  float fromY;

  float toX;
  float toY;

  float speed = 20.f;
  float damage = 0;

  shared_ptr<Enemy> targetEnemy;

public:
  Bullet(Tower &tower, shared_ptr<Enemy> enemy);
  virtual ~Bullet();

  virtual void update(System &system);
  void draw(RenderWindow &window);
};
