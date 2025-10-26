#include "../includes/main.hpp"

int view(System &system)
{
  Clock updateTimer;
  Clock clock;

  RenderWindow window(VideoMode(WindowSpace::WIDTH, WindowSpace::HEIGHT), WindowSpace::WINDOW_NAME);
  window.setVerticalSyncEnabled(false);

  Font arialFont;
  if (!arialFont.loadFromFile(AssetsSpace::FONT_PATH))
  {
    cerr << "Failed to load font!" << endl;
  }
  system.topBar.setFont(arialFont);
  system.sideBar.setFont(arialFont);

  Music music;
  if (!music.openFromFile(AssetsSpace::MUSIC_PATH))
  {
    cerr << "Could not load music file!" << endl;
  }
  music.setVolume(40);
  music.setLoop(true);
  music.play();

  while (window.isOpen())
  {
    Event e;
    while (window.pollEvent(e))
    {
      if (e.type == Event::Closed)
      {
        window.close();
      }
    }

    controller(system, window, updateTimer);

    window.clear();

    system.board.draw(window);
    system.draw(window);
    system.sideBar.draw(window);
    system.topBar.draw(window);
    window.draw(system.dragObj.draggingSprite);

    if (system.gameState == GAME_STATE::GAME_OVER_SCREEN)
    {
      gameOverHandler(system, window);
    }

    if (system.gameState == GAME_STATE::VICTORY_SCREEN)
    {
      winGameHandler(system, window);
    }

    window.display();
  }

  music.stop();

  return 0;
}