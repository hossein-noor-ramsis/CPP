class System
{
public:
  System();
  ~System();

  Clock clock;

  GAME_STATE gameState = GAME_STATE::MAIN_MENU;
  Player player;

  Board board = Board(AssetsSpace::BOARD_PATH, BoardSpace::TILE_SIZE);

  SideBar sideBar = SideBar(SIDE_BAR_WIDTH, WindowSpace::HEIGHT, WindowSpace::WIDTH - SIDE_BAR_WIDTH);
  TopBar topBar = TopBar(WindowSpace::WIDTH, TOP_BAR_HIGHT);

  vector<vector<shared_ptr<Tower>>> towers;
  vector<shared_ptr<Bullet>> bullets;

  DragObj dragObj;

  vector<Round> rounds;
  vector<map<int, shared_ptr<Enemy>>> attackingPlan;

  bool isWaveStart = false;
  bool isWaveEnd = true;

  void draw(RenderWindow &window);
};
