#include "../../includes/main.hpp"

int sideBarHandler(System &system)
{
  if (system.topBar.money < TowerSpace::BOMB_COST)
  {
    system.sideBar.bombTower.sprite.setColor(Color::Red);
  }
  else
  {
    system.sideBar.bombTower.sprite.setColor(Color::White);
  }

  if (system.topBar.money < TowerSpace::ICE_COST)
  {
    system.sideBar.iceTower.sprite.setColor(Color::Red);
  }
  else
  {
    system.sideBar.iceTower.sprite.setColor(Color::White);
  }

  if (system.topBar.money < TowerSpace::NORMAL_COST)
  {
    system.sideBar.normalTower.sprite.setColor(Color(128, 50, 50));
  }
  else
  {
    system.sideBar.normalTower.sprite.setColor(Color::White);
  }

  return 0;
}