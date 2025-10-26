class NormalBullet : public Bullet
{
private:
  /* data */
public:
  NormalBullet(Tower &tower, shared_ptr<Enemy> enemy);
  ~NormalBullet();
};
