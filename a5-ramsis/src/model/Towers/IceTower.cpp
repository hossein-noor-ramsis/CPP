#include "../../../includes/main.hpp"

IceTower::IceTower(System system, float x, float y) : Tower(system, x, y)
{
  if (!texture.loadFromFile(AssetsSpace::ICE_TOWER_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::ICE_TOWER_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }
}

IceTower::IceTower(float x, float y) : Tower(x, y)
{
  if (!texture.loadFromFile(AssetsSpace::ICE_TOWER_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::ICE_TOWER_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }
}

IceTower::~IceTower()
{
}

void IceTower::attack(System &system, shared_ptr<Enemy> enemy)
{
  isCoolingDown = true;
  eventStartTimeInSec = system.clock.getElapsedTime().asSeconds();

  if (enemy->effect == Effect::FREEZE)
  {
    return;
  }

  system.bullets.push_back(make_shared<IceBullet>(*this, enemy));
}
