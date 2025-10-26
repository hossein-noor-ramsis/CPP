class Bomb : public Bullet
{
private:
  CircleShape rangeCircle;
  float range = 80;

public:
  Bomb(Tower &tower, shared_ptr<Enemy> enemy);
  ~Bomb();

  virtual void update(System &system) override;
};
