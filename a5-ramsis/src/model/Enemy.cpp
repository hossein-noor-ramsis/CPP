#include "../../includes/main.hpp"

Enemy::Enemy(System &system, int id)
{
  _x = system.board.startTile->sprite.getPosition().x;
  _y = system.board.startTile->sprite.getPosition().y;

  this->id = id;
}

Enemy::~Enemy()
{
}

int Enemy::update(System &system)
{
  if (effect == Effect::FREEZE)
  {
    return 0;
  }

  int i = sprite.getPosition().y / BoardSpace::TILE_SIZE;
  int j = sprite.getPosition().x / BoardSpace::TILE_SIZE;

  if (direction == Direction::NONE)
  {
    if (j == 0)
    {
      direction = Direction::RIGHT;
    }
    else if (i == (int)system.board.tiles[i].size() - 1)
    {
      direction = Direction::TOP;
    }
    else if (i == 0)
    {
      direction = Direction::DOWN;
    }
    else
    {
      direction = Direction::LEFT;
    }
  }

  if (direction == Direction::TOP)
  {
    i = (sprite.getPosition().y + BoardSpace::TILE_SIZE * 90.0 / 100.0) / BoardSpace::TILE_SIZE;
  }

  if (direction == Direction::LEFT)
  {
    j = (sprite.getPosition().x + BoardSpace::TILE_SIZE * 90.0 / 100.0) / BoardSpace::TILE_SIZE;
  }

  shared_ptr<Tile> currTile = system.board.tiles[i][j];

  if (currTile->isFinishTile)
  {
    system.topBar.hp = system.topBar.hp - 10;
    system.topBar.updateTexts();
    hp = 0;
    sprite.setPosition(-500, -500);

    return 0;
  }

  shared_ptr<Tile> topTile = system.board.tiles[((i - 1) >= 1) ? i - 1 : 1][j];
  shared_ptr<Tile> downTile = system.board.tiles[(i + 1) % system.board.tiles.size()][j];
  shared_ptr<Tile> rightTile = system.board.tiles[i][j + 1 % system.board.tiles[0].size()];
  shared_ptr<Tile> leftTile = system.board.tiles[i][((j - 1) >= 0) ? j - 1 : 0];

  if ((rightTile->type == TileTypes::ROAD) && (direction == Direction::RIGHT))
  {
    sprite.setPosition(sprite.getPosition().x + speed, sprite.getPosition().y);
  }
  else if ((leftTile->type == TileTypes::ROAD) && (direction == Direction::LEFT))
  {
    sprite.setPosition(sprite.getPosition().x - speed, sprite.getPosition().y);
  }
  else if ((topTile->type == TileTypes::ROAD) && (direction == Direction::TOP))
  {
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - speed);
  }
  else if ((downTile->type == TileTypes::ROAD) && (direction == Direction::DOWN))
  {
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + speed);
  }
  else
  {
    if ((direction == Direction::RIGHT) || (direction == Direction::LEFT))
    {
      if (topTile->type == TileTypes::ROAD)
      {
        direction = Direction::TOP;
      }
      else
      {
        direction = Direction::DOWN;
      }
    }
    else if ((direction == Direction::TOP) || (direction == Direction::DOWN))
    {
      if (rightTile->type == TileTypes::ROAD)
      {
        direction = Direction::RIGHT;
      }
      else
      {
        direction = Direction::LEFT;
      }
    }
  }

  return 0;
}

void Enemy::damage(System &system, Bullet &bullet)
{
  (void)system;
  (void)bullet;
}

void Enemy::freeze(System &system)
{
  effect = Effect::FREEZE;
  eventStartTimeInSec = system.clock.getElapsedTime().asSeconds();
}

void Enemy::unFreeze(System &system)
{
  if (effect == Effect::FREEZE)
  {
    if (system.clock.getElapsedTime().asSeconds() - eventStartTimeInSec >= FREEZE_TIME_IN_SEC)
    {
      effect = Effect::NONE;
    }
  }
}
