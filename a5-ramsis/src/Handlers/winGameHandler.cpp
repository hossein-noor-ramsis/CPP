#include "../../includes/main.hpp"

int winGameHandler(System &system, RenderWindow &window)
{
  if (system.gameState == GAME_STATE::VICTORY_SCREEN)
  {
    Font font;
    if (!font.loadFromFile(AssetsSpace::FONT_PATH))
    {
      cerr << "Failed to load font!" << endl;
    }

    RectangleShape backgroundOverlay(Vector2f(window.getSize()));
    backgroundOverlay.setFillColor(Color(0, 100, 0, 180));

    Text winText("YOU WIN!", font, 80);
    winText.setFillColor(Color::Green);
    winText.setStyle(Text::Bold);

    winText.setPosition(
        window.getSize().x / 2 - winText.getLocalBounds().width / 2,
        window.getSize().y / 2 - winText.getLocalBounds().height / 2);

    window.draw(backgroundOverlay);
    window.draw(winText);
  }
  else
  {
    bool isWinGame = true;

    for (size_t i = 0; i < system.attackingPlan.size(); i++)
    {
      for (auto &enemy : system.attackingPlan[i])
      {
        if (enemy.second->hp > 0)
        {
          isWinGame = false;
          break;
        }
      }
    }

    if (isWinGame)
    {
      system.gameState = GAME_STATE::VICTORY_SCREEN;
    }
  }

  return 0;
}
