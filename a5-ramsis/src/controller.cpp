#include "../includes/main.hpp"

int controller(System &system, RenderWindow &window, Clock &updateTimer)
{

  gameOverHandler(system, window);
  winGameHandler(system, window);

  if (system.gameState == GAME_STATE::VICTORY_SCREEN)
  {
    return 0;
  }

  if (system.gameState == GAME_STATE::GAME_OVER_SCREEN)
  {
    return 0;
  }

  sideBarHandler(system);
  dragHandler(system, window);

  waveHandler(system, updateTimer);
  towerHandler(system);

  return 0;
}
