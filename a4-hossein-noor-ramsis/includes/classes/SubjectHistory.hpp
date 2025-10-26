class SubjectHistory
{
private:
  int _easyCorrects = 0;
  int _easyIncorrects = 0;
  int _easyBlanks = 0;

  int _mediumCorrects = 0;
  int _mediumIncorrects = 0;
  int _mediumBlanks = 0;

  int _hardCorrects = 0;
  int _hardIncorrects = 0;
  int _hardBlanks = 0;

  int _corrects = 0;
  int _incorrects = 0;
  int _blanks = 0;

  int _seenCount = 0;

public:
  SubjectHistory();
  ~SubjectHistory();

  int getEasyCorrects();
  void increaseEasyCorrects();

  int getEasyIncorrects();
  void increaseEasyIncorrects();

  int getEasyBlanks();
  void increaseEasyBlanks();

  int getMediumCorrects();
  void increaseMediumCorrects();

  int getMediumIncorrects();
  void increaseMediumIncorrects();

  int getMediumBlanks();
  void increaseMediumBlanks();

  int getHardCorrects();
  void increaseHardCorrects();

  int getHardIncorrects();
  void increaseHardIncorrects();

  int getHardBlanks();
  void increaseHardBlanks();

  int getCorrects();
  void increaseCorrects();

  int getIncorrects();
  void increaseIncorrects();

  int getBlanks();
  void increaseBlanks();

  int getSeenCount();
  void increaseSeenCount();
};
