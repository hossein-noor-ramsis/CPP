#include "../../../includes/main.hpp"

NormalBullet::NormalBullet(Tower &tower, shared_ptr<Enemy> enemy) : Bullet(tower, enemy)
{
  damage = 50;

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
  }
}

NormalBullet::~NormalBullet()
{
}
