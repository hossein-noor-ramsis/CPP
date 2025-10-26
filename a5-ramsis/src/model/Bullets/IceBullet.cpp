#include "../../../includes/main.hpp"

IceBullet::IceBullet(Tower &tower, shared_ptr<Enemy> enemy) : Bullet(tower, enemy)
{
  damage = 0;
  effect = Effect::FREEZE;

  if (!texture.loadFromFile(AssetsSpace::ICE_BULLET_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::ICE_BULLET_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x / 2, BoardSpace::TILE_SIZE / textureSize.y / 2);
    sprite.setPosition(fromX, fromY);
  }
}

IceBullet::~IceBullet()
{
}
