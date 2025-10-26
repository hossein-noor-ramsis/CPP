class TopBar
{
public:
  RectangleShape background;

  Text hpText;
  Text moneyText;
  Text roundText;

  int hp = 0;
  int money = 0;
  int round = 1;

public:
  TopBar();
  TopBar(int width, int height);

  void setFont(Font &font);

  void setHP(int newHP);
  void setMoney(int newMoney);
  void setRound(int newRound);

  void updateTexts();
  void draw(RenderWindow &window);
};
