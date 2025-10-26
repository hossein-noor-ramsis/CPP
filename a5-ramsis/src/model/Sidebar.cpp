#include "../../includes/main.hpp"

SideBar::SideBar() {}

SideBar::SideBar(int w, int h, int posX)
{
  background.setSize(Vector2f(w, h));
  background.setFillColor(Color(216, 228, 254));
  background.setPosition(posX, 0);

  normalTowerText.setString("NORM: \n50$");
  normalTowerText.setCharacterSize(22);
  normalTowerText.setFillColor(Color::Black);
  normalTowerText.setPosition(900, 215);
  normalTowerText.setStyle(Text::Bold);

  iceTowerText.setString("ICE: \n100$");
  iceTowerText.setCharacterSize(22);
  iceTowerText.setFillColor(Color::Black);
  iceTowerText.setPosition(900, 365);
  iceTowerText.setStyle(Text::Bold);

  bombTowerText.setString("BOMB: \n200$");
  bombTowerText.setCharacterSize(22);
  bombTowerText.setFillColor(Color::Black);
  bombTowerText.setPosition(900, 515);
  bombTowerText.setStyle(Text::Bold);
}

void SideBar::draw(RenderWindow &window)
{
  window.draw(background);

  window.draw(normalTower.sprite);
  window.draw(iceTower.sprite);
  window.draw(bombTower.sprite);

  window.draw(normalTowerText);
  window.draw(iceTowerText);
  window.draw(bombTowerText);
}

void SideBar::setFont(Font &font)
{
  normalTowerText.setFont(font);
  iceTowerText.setFont(font);
  bombTowerText.setFont(font);
}
