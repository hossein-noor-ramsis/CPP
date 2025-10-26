class PregnantBalloon : public Enemy
{
public:
public:
  PregnantBalloon(System &system, int id);
  ~PregnantBalloon();

  void damage(System &system, Bullet &bullet) override;
};
