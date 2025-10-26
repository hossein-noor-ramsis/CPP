class Template
{
private:
  string _name;
  vector<Subject> _subjects;

public:
  Template() = default;
  Template(string name);
  string getName();

  int addSubject(Subject newSubject);
  vector<Subject> getSubjects();
};
