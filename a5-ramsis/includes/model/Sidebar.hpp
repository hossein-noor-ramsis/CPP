class SideBar
{
public:
  RectangleShape background;

  NormalTower normalTower = NormalTower(980, 200);
  IceTower iceTower = IceTower(980, 350);
  BombTower bombTower = BombTower(980, 500);

  Text normalTowerText;
  Text bombTowerText;
  Text iceTowerText;

public:
  SideBar();
  SideBar(int w, int h, int posX);

  void setFont(Font &font);

  void draw(RenderWindow &window);
};
