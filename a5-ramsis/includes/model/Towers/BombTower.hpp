class BombTower : public Tower
{
private:
  /* data */
public:
  BombTower(System system, float x, float y);
  BombTower(float x, float y);
  ~BombTower();

  void attack(System &system, shared_ptr<Enemy> enemy) override;
};
