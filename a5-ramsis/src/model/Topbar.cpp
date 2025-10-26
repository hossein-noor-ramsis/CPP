#include "../../includes/main.hpp"

TopBar::TopBar() {}

TopBar::TopBar(int width, int height)
{
  hp = PlayerSpace::HP;
  money = PlayerSpace::MONEY;

  background.setSize(Vector2f(width, height));
  background.setFillColor(Color(51, 62, 94));
  background.setPosition(0, 0);

  hpText.setString("HP: " + to_string(PlayerSpace::HP) + '%');
  hpText.setCharacterSize(40);
  hpText.setFillColor(Color::White);
  hpText.setPosition(20, height / 2 - 34);

  moneyText.setString("Money: " + to_string(PlayerSpace::MONEY) + '$');
  moneyText.setCharacterSize(40);
  moneyText.setFillColor(Color::White);
  moneyText.setPosition(width / 3 + 70, height / 2 - 34);

  roundText.setString("Round: " + to_string(round));
  roundText.setCharacterSize(40);
  roundText.setFillColor(Color::White);
  roundText.setPosition(width - 180, height / 2 - 34);
}

void TopBar::setFont(Font &font)
{
  hpText.setFont(font);
  moneyText.setFont(font);
  roundText.setFont(font);
}

void TopBar::setHP(int newHP)
{
  hp = newHP;
  updateTexts();
}

void TopBar::setMoney(int newMoney)
{
  money = newMoney;
  updateTexts();
}

void TopBar::setRound(int newRound)
{
  round = newRound;
  updateTexts();
}

void TopBar::updateTexts()
{
  hpText.setString("HP: " + to_string(hp) + '%');
  moneyText.setString("Money: " + to_string(money) + '$');
  roundText.setString("Round: " + to_string(round));
}

void TopBar::draw(RenderWindow &window)
{
  window.draw(background);
  window.draw(hpText);
  window.draw(moneyText);
  window.draw(roundText);
}
