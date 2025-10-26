#include "../../includes/main.hpp"

int waveHandler(System &system, Clock &updateTimer)
{
  bool &isWaveStarted = system.isWaveStart;
  bool &isWaveEnded = system.isWaveEnd;

  int roundIndex = system.topBar.round - 1;

  float enemyLaunchGapMsMin = ATTACKING_PLAN[roundIndex].enemyLaunchGapMs.first;
  float enemyLaunchGapMsMax = ATTACKING_PLAN[roundIndex].enemyLaunchGapMs.second;

  float enemyLaunchGapMs = getRandomFloat(enemyLaunchGapMsMin, enemyLaunchGapMsMax) / 1000.f;

  if (!isWaveStarted)
  {
    if (updateTimer.getElapsedTime().asSeconds() >= WAVE_LAUNCH_GAP_SECS)
    {
      isWaveStarted = true;

      system.topBar.updateTexts();

      updateTimer.restart();
    }
  }

  if (isWaveStarted)
  {
    if (updateTimer.getElapsedTime().asSeconds() >= enemyLaunchGapMs)
    {
      isWaveEnded = true;

      for (auto &enemy : system.attackingPlan[roundIndex])
      {
        if (!enemy.second->isSpawned)
        {
          enemy.second->isSpawned = true;
          isWaveEnded = false;
          break;
        }
      }

      if (isWaveEnded)
      {
        if ((unsigned int)system.topBar.round < system.attackingPlan.size())
        {
          system.topBar.round++;
          isWaveStarted = false;
        }
      }

      updateTimer.restart();
    }
  }

  return 0;
}
