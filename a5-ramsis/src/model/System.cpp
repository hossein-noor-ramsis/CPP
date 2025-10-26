#include "../../includes/main.hpp"

System::System()
{
  towers = vector<vector<shared_ptr<Tower>>>(board.hight, vector<shared_ptr<Tower>>(board.width, make_shared<NormalTower>(-500, -500)));

  for (auto &i : ATTACKING_PLAN)
  {
    map<int, shared_ptr<Enemy>> wave;

    int id = generateUniqueId();

    if (i.enemiesCount.find("Normal") != i.enemiesCount.end())
    {
      for (int j = 0; j < i.enemiesCount.at("Normal"); j++)
      {
        id = generateUniqueId();

        wave[id] = make_shared<NormalBalloon>(*this, id);
      }
    }

    if (i.enemiesCount.find("Pregnant") != i.enemiesCount.end())
    {
      for (int j = 0; j < i.enemiesCount.at("Pregnant"); j++)
      {
        id = generateUniqueId();

        wave[id] = make_shared<PregnantBalloon>(*this, id);
      }
    }

    wave = shuffleWave(wave);
    attackingPlan.push_back(wave);
  }
}

System::~System()
{
}

void System::draw(RenderWindow &window)
{
  for (auto &line : towers)
  {
    for (auto &tower : line)
    {
      window.draw(tower->rangeCircle);
    }
  }

  for (auto &line : towers)
  {
    for (auto &tower : line)
    {
      window.draw(tower->sprite);
    }
  }

  for (auto &wave : attackingPlan)
  {
    for (auto &enemy : wave)
    {
      if (enemy.second->isSpawned)
      {
        window.draw(enemy.second->sprite);
      }
    }
  }

  if (topBar.hp > 0)
  {
    for (auto &wave : attackingPlan)
    {
      for (auto &enemy : wave)
      {
        if (enemy.second->isSpawned && (enemy.second->hp > 0))
        {
          enemy.second->update(*this);
          enemy.second->unFreeze(*this);
        }
      }
    }
  }

  for (auto &bullet : bullets)
  {
    bullet->draw(window);

    if (bullet->sprite.getPosition().x >= 0)
    {
      bullet->update(*this);
    }
  }
}
