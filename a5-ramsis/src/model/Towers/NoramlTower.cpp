#include "../../../includes/main.hpp"

NormalTower::NormalTower(System system, float x, float y) : Tower(system, x, y)
{
  if (!texture.loadFromFile(AssetsSpace::NORMAL_TOWER_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::NORMAL_TOWER_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }
}

NormalTower::NormalTower(float x, float y) : Tower(x, y)
{
  if (!texture.loadFromFile(AssetsSpace::NORMAL_TOWER_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::NORMAL_TOWER_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }
}

NormalTower::~NormalTower()
{
}

void NormalTower::attack(System &system, shared_ptr<Enemy> enemy)
{
  isCoolingDown = true;
  eventStartTimeInSec = system.clock.getElapsedTime().asSeconds();

  system.bullets.push_back(make_shared<NormalBullet>(*this, enemy));
}
