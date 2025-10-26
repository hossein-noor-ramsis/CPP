class Subject
{
private:
  string _name;
  string _difficulty;
  int _count;
  int _priority;

public:
  Subject(string name, string difficulty, int count);
  Subject(string name);

  string getName();
  string getDifficulty();

  int getCount();
  void decreaseCount();

  int getPriority();
  void setPriority(int num);
};
