class IceBullet : public Bullet
{
private:
  /* data */
public:
  IceBullet(Tower &tower, shared_ptr<Enemy> enemy);
  ~IceBullet();
};
