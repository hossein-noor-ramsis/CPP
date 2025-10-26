class IceTower : public Tower
{
private:
  /* data */
public:
  IceTower(System system, float x, float y);
  IceTower(float x, float y);
  ~IceTower();

  void attack(System &system, shared_ptr<Enemy> enemy) override;
};
