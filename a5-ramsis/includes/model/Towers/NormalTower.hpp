class NormalTower : public Tower
{
private:
public:
  NormalTower(System system, float x, float y);
  NormalTower(float x, float y);
  ~NormalTower();

  void attack(System &system, shared_ptr<Enemy> enemy) override;
};
