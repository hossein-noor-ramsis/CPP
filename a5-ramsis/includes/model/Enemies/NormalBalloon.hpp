class NormalBalloon : public Enemy
{
public:
public:
  NormalBalloon(System &system, int id);
  ~NormalBalloon();

  void damage(System &system, Bullet &bullet) override;
};
