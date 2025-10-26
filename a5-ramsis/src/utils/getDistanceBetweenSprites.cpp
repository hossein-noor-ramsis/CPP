#include "../../includes/main.hpp"

float getDistanceBetweenSprites(const Sprite &sprite1, const Sprite &sprite2)
{
  Vector2f pos1 = sprite1.getPosition();
  Vector2f pos2 = sprite2.getPosition();

  float dx = pos2.x - pos1.x;
  float dy = pos2.y - pos1.y;

  return sqrt(dx * dx + dy * dy);
}

float getCenterDistanceBetweenSprites(const sf::Sprite &sprite1, const sf::Sprite &sprite2)
{
  sf::Vector2f center1 = sprite1.getPosition() +
                         sf::Vector2f(sprite1.getTextureRect().width * sprite1.getScale().x / 2.f,
                                      sprite1.getTextureRect().height * sprite1.getScale().y / 2.f);

  sf::Vector2f center2 = sprite2.getPosition() +
                         sf::Vector2f(sprite2.getTextureRect().width * sprite2.getScale().x / 2.f,
                                      sprite2.getTextureRect().height * sprite2.getScale().y / 2.f);

  float dx = center2.x - center1.x;
  float dy = center2.y - center1.y;

  return std::sqrt(dx * dx + dy * dy);
}