#include "../../../includes/main.hpp"

PregnantBalloon::PregnantBalloon(System &system, int id) : Enemy(system, id)
{
  if (!texture.loadFromFile(AssetsSpace::PREGNANT_BALLOON_PATH))
  {
    cerr << "Failed to load texture: " << AssetsSpace::PREGNANT_BALLOON_PATH << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
    sprite.setPosition(_x, _y);
  }

  hp = 100;
  money = 10;
}

PregnantBalloon::~PregnantBalloon()
{
}

void PregnantBalloon::damage(System &system, Bullet &bullet)
{
  hp -= bullet.damage;

  if ((hp <= 0) && (sprite.getPosition().x >= 0))
  {
    float x = sprite.getPosition().x;
    float y = sprite.getPosition().y;

    sprite.setPosition(-500, -500);

    system.topBar.money += money;
    system.topBar.updateTexts();

    int id1 = generateUniqueId();
    int id2 = generateUniqueId();

    shared_ptr<NormalBalloon> normalBalloonOne = make_shared<NormalBalloon>(system, id);
    shared_ptr<NormalBalloon> normalBalloonTwo = make_shared<NormalBalloon>(system, id);

    if (direction == Direction::TOP || direction == Direction::DOWN)
    {
      normalBalloonOne->sprite.setPosition(x, y - 20);
      normalBalloonTwo->sprite.setPosition(x, y);
    }
    else
    {
      normalBalloonOne->sprite.setPosition(x - 20, y);
      normalBalloonTwo->sprite.setPosition(x, y);
    }

    normalBalloonOne->isSpawned = true;
    normalBalloonOne->direction = direction;

    normalBalloonTwo->isSpawned = true;
    normalBalloonTwo->direction = direction;

    system.attackingPlan[0][id1] = normalBalloonOne;
    system.attackingPlan[0][id2] = normalBalloonTwo;
  }
}
