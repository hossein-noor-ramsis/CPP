#include "../../../includes/main.hpp"

BombTower::BombTower(System system, float x, float y) : Tower(system, x, y)
{
  if (!texture.loadFromFile(AssetsSpace::BOMB_TOWER_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::BOMB_TOWER_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }

  coolDowneventStartTimeInSec = 4;
}

BombTower::BombTower(float x, float y) : Tower(x, y)
{
  if (!texture.loadFromFile(AssetsSpace::BOMB_TOWER_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::BOMB_TOWER_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }

  coolDowneventStartTimeInSec = 4;
}

BombTower::~BombTower()
{
}

void BombTower::attack(System &system, shared_ptr<Enemy> enemy)
{
  isCoolingDown = true;
  eventStartTimeInSec = system.clock.getElapsedTime().asSeconds();

  system.bullets.push_back(make_shared<Bomb>(*this, enemy));
}
