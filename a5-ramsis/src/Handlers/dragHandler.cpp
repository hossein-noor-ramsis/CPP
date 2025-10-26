#include "../../includes/main.hpp"

int dragHandler(System &system, RenderWindow &window)
{
  Vector2i mousePos = Mouse::getPosition(window);
  Vector2f worldPos = window.mapPixelToCoords(mousePos);

  NormalTower normalTower = system.sideBar.normalTower;
  IceTower iceTower = system.sideBar.iceTower;
  BombTower bombTower = system.sideBar.bombTower;

  if (Mouse::isButtonPressed(Mouse::Left))
  {
    if (!system.dragObj.isDragging && normalTower.sprite.getGlobalBounds().contains(worldPos))
    {
      if (system.topBar.money >= TowerSpace::NORMAL_COST)
      {
        system.dragObj.towerType = TowerTypes::BASIC_TOWER;
        system.dragObj.draggingSprite = normalTower.sprite;
        system.dragObj.isDragging = true;
      }
    }

    if (!system.dragObj.isDragging && iceTower.sprite.getGlobalBounds().contains(worldPos))
    {
      if (system.topBar.money >= TowerSpace::ICE_COST)
      {
        system.dragObj.towerType = TowerTypes::ICE_TOWER;
        system.dragObj.draggingSprite = iceTower.sprite;
        system.dragObj.isDragging = true;
      }
    }

    if (!system.dragObj.isDragging && bombTower.sprite.getGlobalBounds().contains(worldPos))
    {
      if (system.topBar.money >= TowerSpace::BOMB_COST)
      {
        system.dragObj.towerType = TowerTypes::BOMB_TOWER;
        system.dragObj.draggingSprite = bombTower.sprite;
        system.dragObj.isDragging = true;
      }
    }
  }
  else
  {
    if (system.dragObj.isDragging)
    {
      Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));

      int i = mousePos.y / BoardSpace::TILE_SIZE;
      int j = mousePos.x / BoardSpace::TILE_SIZE;

      if (i <= 1 || i >= 10)
      {
        system.dragObj.draggingSprite.setPosition(-500, -500);
        system.dragObj.isDragging = false;

        return 0;
      }

      if (j >= 12)
      {
        system.dragObj.draggingSprite.setPosition(-500, -500);
        system.dragObj.isDragging = false;

        return 0;
      }

      if (system.board.tiles[i][j]->type != TileTypes::GRASS)
      {
        system.dragObj.draggingSprite.setPosition(-500, -500);
        system.dragObj.isDragging = false;

        return 0;
      }

      if (system.towers[i][j]->_x >= 0)
      {
        system.dragObj.draggingSprite.setPosition(-500, -500);
        system.dragObj.isDragging = false;

        return 0;
      }

      if (system.dragObj.towerType == TowerTypes::BASIC_TOWER)
      {
        if (system.topBar.money < TowerSpace::NORMAL_COST)
        {
          system.dragObj.draggingSprite.setPosition(-500, -500);
          system.dragObj.isDragging = false;

          return 0;
        }

        system.topBar.setMoney(system.topBar.money - TowerSpace::NORMAL_COST);
        system.towers[i][j] = make_shared<NormalTower>(system, j * 72, i * 71);
        system.dragObj.draggingSprite.setPosition(-500, -500);
      }

      if (system.dragObj.towerType == TowerTypes::ICE_TOWER)
      {
        if (system.topBar.money < TowerSpace::ICE_COST)
        {
          system.dragObj.draggingSprite.setPosition(-500, -500);
          system.dragObj.isDragging = false;

          return 0;
        }

        system.topBar.setMoney(system.topBar.money - TowerSpace::ICE_COST);
        system.towers[i][j] = make_shared<IceTower>(system, j * 72, i * 71);
        system.dragObj.draggingSprite.setPosition(-500, -500);
      }

      if (system.dragObj.towerType == TowerTypes::BOMB_TOWER)
      {
        if (system.topBar.money < TowerSpace::BOMB_COST)
        {
          system.dragObj.draggingSprite.setPosition(-500, -500);
          system.dragObj.isDragging = false;

          return 0;
        }

        system.topBar.setMoney(system.topBar.money - TowerSpace::BOMB_COST);
        system.towers[i][j] = make_shared<BombTower>(system, j * 72, i * 71);
        system.dragObj.draggingSprite.setPosition(-500, -500);
      }

      system.dragObj.isDragging = false;
    }
  }

  if (system.dragObj.isDragging)
  {
    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
    system.dragObj.draggingSprite.setPosition(mousePos.x - 40, mousePos.y - 40);
  }

  return 0;
}
