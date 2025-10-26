#include "../../../includes/main.hpp"

NormalBalloon::NormalBalloon(System &system, int id) : Enemy(system, id)
{
  if (!texture.loadFromFile(AssetsSpace::BALLOON_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::BALLOON_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }

  hp = 50;
  money = 5;
}

NormalBalloon::~NormalBalloon()
{
}

void NormalBalloon::damage(System &system, Bullet &bullet)
{
  hp -= bullet.damage;

  if ((hp <= 0) && (sprite.getPosition().x >= 0))
  {
    sprite.setPosition(-500, -500);
    system.topBar.money += money;
    system.topBar.updateTexts();
  }
}
