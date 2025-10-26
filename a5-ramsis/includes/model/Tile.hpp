class Tile
{
public:
  Sprite sprite;
  Texture texture;
  TileTypes type = TileTypes::GRASS;

  bool isFinishTile = false;
  bool isStartTile = false;

public:
  Tile();
  Tile(float x, float y);

  void draw(RenderWindow &window);
  void setType(TileTypes type);
};
