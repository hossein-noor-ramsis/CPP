class Quest
{
private:
  string _questionText;

  string _option1;
  string _option2;
  string _option3;
  string _option4;

  int _currectAnswer = 0;

  string _difficulty;
  string _subject;

  int _numOfCorrects = 0;
  int _numOfIncorrects = 0;
  int _numOfBlanks = 0;

  int _priority = 0;

  int _selectedAnswer = 0;

public:
  Quest(vector<string> &data);
  ~Quest();

  int getPriority();
  void setPriority(int newPriority);

  string getSubject();
  string getDifficulty();

  string getQuestionText();
  string getOption1();
  string getOption2();
  string getOption3();
  string getOption4();

  int getCurrectAnswer();

  int getNumOfCorrects();
  void setNumOfCorrects(int num);

  int getNumOfIncorrects();
  void setNumOfIncorrects(int num);

  int getNumOfBlanks();
  void setNumOfBlanks(int num);

  int getSelectedAnswer();
  void setSelectedAnswer(int num);
};
