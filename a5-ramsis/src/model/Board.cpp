#include "../../includes/main.hpp"

Board::Board(const string &filename, float tileSize)
{
  ifstream file(filename);
  string line;
  int row = 2;

  tiles = vector<vector<shared_ptr<Tile>>>(BoardSpace::HEIGHT + 2, vector<shared_ptr<Tile>>(BoardSpace::WIDTH, make_shared<Tile>(-500, -500)));

  while (getline(file, line))
  {
    for (unsigned int col = 0; col < line.size(); ++col)
    {
      shared_ptr<Tile> tile = make_shared<Tile>(col * tileSize, row * tileSize);

      switch (line[col])
      {
      case '-':
        tile->setType(TileTypes::GRASS);
        tiles[row][col] = tile;

        break;
      case 'O':
        tile->setType(TileTypes::ROAD);
        tiles[row][col] = tile;
        road.push_back(tile);

        break;
      case 'S':
        tile->setType(TileTypes::ROAD);
        tile->isStartTile = true;
        tiles[row][col] = tile;

        startTile = tile;
        break;
      case 'F':
        tile->setType(TileTypes::ROAD);
        tile->isFinishTile = true;
        tiles[row][col] = tile;

        finishTile = tile;
        break;
      default:
        continue;
      }
    }

    ++row;
  }

  hight = row;
  width = line.size();
}

Board::~Board()
{
}

void Board::draw(RenderWindow &window)
{
  for (auto &line : tiles)
  {
    for (auto &tile : line)
    {
      tile->draw(window);
    }
  }
}
