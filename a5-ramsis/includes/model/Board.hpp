class Board
{
public:
  int hight;
  int width;

  vector<vector<shared_ptr<Tile>>> tiles;

  vector<shared_ptr<Tile>> road;
  shared_ptr<Tile> startTile;
  shared_ptr<Tile> finishTile;

  Board(const string &filename, float tileSize);
  ~Board();

  void draw(RenderWindow &window);
};
