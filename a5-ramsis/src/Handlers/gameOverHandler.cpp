#include "../../includes/main.hpp"

int gameOverHandler(System &system, RenderWindow &window)
{
  if (system.gameState == GAME_STATE::GAME_OVER_SCREEN)
  {
    Font font;
    if (!font.loadFromFile(AssetsSpace::FONT_PATH))
    {
      cerr << "Failed to load font!" << endl;
    }

    Text gameOverText("GAME OVER", font, 72);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(
        window.getSize().x / 2 - gameOverText.getLocalBounds().width / 2,
        window.getSize().y / 2 - gameOverText.getLocalBounds().height / 2);

    RectangleShape backgroundOverlay(Vector2f(window.getSize()));
    backgroundOverlay.setFillColor(Color(0, 0, 0, 180));

    window.draw(backgroundOverlay);
    window.draw(gameOverText);
  }
  else
  {
    if (system.topBar.hp <= 0)
    {
      system.gameState = GAME_STATE::GAME_OVER_SCREEN;
    }
  }

  return 0;
}
