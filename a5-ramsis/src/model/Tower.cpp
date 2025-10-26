#include "../../includes/main.hpp"

Tower::Tower() {}

Tower::Tower(System system, float x, float y)
{
  _x = x;
  _y = y;

  rangeCircle.setRadius(range);
  rangeCircle.setPosition(x - (2 * range / 3), y - (2 * range / 3));
  rangeCircle.setFillColor(Color(255, 255, 255, 50));
  rangeCircle.setOutlineThickness(2);
  rangeCircle.setOutlineColor(Color(200, 200, 200, 100));

  eventStartTimeInSec = system.clock.getElapsedTime().asSeconds();
}

Tower::Tower(float x, float y)
{
  _x = x;
  _y = y;

  rangeCircle.setRadius(range);
  rangeCircle.setPosition(x - (2 * range / 3), y - (2 * range / 3));
  rangeCircle.setFillColor(Color(255, 255, 255, 50));
  rangeCircle.setOutlineThickness(2);
  rangeCircle.setOutlineColor(Color(200, 200, 200, 100));
}

Tower::~Tower()
{
}

void Tower::draw(RenderWindow &window)
{
  window.draw(sprite);
  window.draw(rangeCircle);
}

bool Tower::isBalloonInRange(const Sprite &balloon)
{
  FloatRect rangeCircleBounds = rangeCircle.getGlobalBounds();
  Vector2f balloonPos = balloon.getPosition();

  return rangeCircleBounds.contains(balloonPos);
}

void Tower::attack(System &system, shared_ptr<Enemy> enemy)
{
  (void)system;
  (void)enemy;
}

void Tower::coolDownTimer(System system)
{
  if (isCoolingDown)
  {
    if (system.clock.getElapsedTime().asSeconds() - eventStartTimeInSec >= coolDowneventStartTimeInSec)
    {
      isCoolingDown = false;
    }
  }
}
