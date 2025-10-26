#include "../../../includes/main.hpp"

Bomb::Bomb(Tower &tower, shared_ptr<Enemy> enemy) : Bullet(tower, enemy)
{
  damage = 100;

  if (!texture.loadFromFile(AssetsSpace::NORMAL_BULLET_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::NORMAL_BULLET_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x / 2, BoardSpace::TILE_SIZE / textureSize.y / 2);
    sprite.setPosition(fromX, fromY);
    sprite.setColor(Color::Black);
  }

  rangeCircle.setRadius(range);
  rangeCircle.setPosition(fromX - (2 * range / 3), fromY - (2 * range / 3));

  rangeCircle.setFillColor(Color(255, 255, 255, 50));
  rangeCircle.setOutlineThickness(2);
  rangeCircle.setOutlineColor(Color(200, 200, 200, 100));
}

Bomb::~Bomb()
{
}

void Bomb::update(System &system)
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
  rangeCircle.setPosition(newX - (2 * range / 3), newY - (2 * range / 3));

  float distToTarget = sqrt((toX - newX) * (toX - newX) + (toY - newY) * (toY - newY));

  if (distToTarget < speed)
  {
    sprite.setPosition(-500, -500);

    for (size_t i = 0; i < system.attackingPlan.size(); i++)
    {
      for (auto &enemy : system.attackingPlan[i])
      {
        if (rangeCircle.getGlobalBounds().contains(enemy.second->sprite.getPosition()))
        {
          enemy.second->damage(system, *this);
        }
      }
    }
  }
}
