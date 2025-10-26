#include "../../includes/main.hpp"

int towerHandler(System &system)
{
  shared_ptr<Tower> tower;
  shared_ptr<Enemy> nearestEnemy = system.attackingPlan[0][1];

  float nearestEnemyDistance = 2000;
  float newNearestEnemyDistance = 0;

  for (auto &line : system.towers)
  {
    for (auto &tower : line)
    {
      if ((tower->_x < 0) || (tower->_y < 0))
      {
        continue;
      }

      tower->coolDownTimer(system);

      for (auto &wave : system.attackingPlan)
      {
        for (auto &enemy : wave)
        {
          if (enemy.second->hp < 0)
          {
            continue;
          }

          if (!enemy.second->isSpawned)
          {
            continue;
          }

          newNearestEnemyDistance = getDistanceBetweenSprites(tower->sprite, enemy.second->sprite);
          if (newNearestEnemyDistance < nearestEnemyDistance)
          {
            nearestEnemy = enemy.second;
            nearestEnemyDistance = newNearestEnemyDistance;
          }

          enemy.second->sprite;
        }
      }

      if (!tower->isBalloonInRange(nearestEnemy->sprite))
      {
        continue;
      }

      if (tower->isCoolingDown)
      {
        continue;
      }

      tower->attack(system, nearestEnemy);
    }
  }

  return 0;
}