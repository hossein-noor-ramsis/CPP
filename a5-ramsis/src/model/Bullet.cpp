#include "../../includes/main.hpp"

Bullet::Bullet(Tower &tower, shared_ptr<Enemy> enemy)
{
  fromX = tower.sprite.getPosition().x;
  fromY = tower.sprite.getPosition().y;

  targetEnemy = enemy;

  toX = enemy->sprite.getPosition().x;
  toY = enemy->sprite.getPosition().y;
}

void Bullet::update(System &system)
{
  float currX = sprite.getPosition().x;
  float currY = sprite.getPosition().y;

  float dx = toX - fromX;
  float dy = toY - fromY;

  float length = std::sqrt(dx * dx + dy * dy);

  float dirX = dx / length;
  float dirY = dy / length;

  float newX = currX + dirX * speed;
  float newY = currY + dirY * speed;

  sprite.setPosition(newX, newY);

  float distToTarget = sqrt((toX - newX) * (toX - newX) + (toY - newY) * (toY - newY));

  if (distToTarget < speed)
  {
    sprite.setPosition(-500, -500);
    targetEnemy->damage(system, *this);

    if (effect == Effect::FREEZE)
    {
      targetEnemy->freeze(system);
    }
  }
}

void Bullet::draw(RenderWindow &window)
{
  window.draw(sprite);
}

Bullet::~Bullet()
{
}
