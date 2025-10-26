#include "../../includes/main.hpp"

Tile::Tile()
{
}

Tile::Tile(float x, float y)
{
  sprite.setPosition(x, y);
}

void Tile::draw(RenderWindow &window)
{
  window.draw(sprite);
}

void Tile::setType(TileTypes t)
{
  string texturePath;
  type = t;

  if (t == TileTypes::GRASS)
  {
    texturePath = AssetsSpace::GRASS_PATH;
  }
  else
  {
    texturePath = AssetsSpace::ROAD_PATH;
  }

  if (!texture.loadFromFile(texturePath))
  {
    cerr << "Failed to load texture: " << texturePath << endl;
  }
  else
  {
    sprite.setTexture(texture);

    Vector2u textureSize = texture.getSize();
    sprite.setScale(BoardSpace::TILE_SIZE / textureSize.x, BoardSpace::TILE_SIZE / textureSize.y);
  }
}
