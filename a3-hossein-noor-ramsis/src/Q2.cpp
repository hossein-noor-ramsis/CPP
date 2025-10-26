#include <iostream>
#include <algorithm>
#include <list>
#include <set>

using namespace std;

typedef struct
{
  int id;
  int age;
  int giftBudget;
  int receivedEidGift;
  bool isExist;
} Person;

int initData(list<Person> &personsList, list<int> &agesList);
int givingEidGift(list<Person> &personsList, list<int> &agesList);
list<Person>::iterator findNextOlderPerson(list<Person>::iterator notFound, list<Person>::iterator person, int age);
list<Person>::iterator findPrevOlderPerson(list<Person>::iterator notFound, list<Person>::iterator person, int age);

int main()
{
  list<Person> personsList;
  list<int> agesList;

  initData(personsList, agesList);

  givingEidGift(personsList, agesList);

  for (auto person : personsList)
  {
    cout << person.receivedEidGift << " ";
  }

  cout << endl;

  return 0;
}

int givingEidGift(list<Person> &personsList, list<int> &agesList)
{
  auto person = find_if(personsList.begin(), personsList.end(), [agesList](const Person p)
                        { return p.age == agesList.front(); });

  if (person == personsList.end())
  {
    return 0;
  }

  list<Person>::iterator nextPerson = person;
  list<Person>::iterator prevPerson = person;

  for (auto age : agesList)
  {
    if (age == person->age)
    {
      continue;
    }

    nextPerson = findNextOlderPerson(person, person, age);
    
    if (nextPerson != person)
    {
      break;
    }
  }

  for (auto age : agesList)
  {
    if (age == person->age)
    {
      continue;
    }

    prevPerson = findPrevOlderPerson(person, person, age);

    if (prevPerson != person && prevPerson->isExist)
    {
      break;
    }
  }

  if ((prevPerson != person) && (nextPerson != person))
  {
    prevPerson->receivedEidGift += person->giftBudget / 2;
    nextPerson->receivedEidGift += person->giftBudget / 2;
  }
  else if (nextPerson != person)
  {
    nextPerson->receivedEidGift += person->giftBudget;
  }
  else if (prevPerson != person)
  {
    prevPerson->receivedEidGift += person->giftBudget;
  }
  else
  {
    person->receivedEidGift += person->giftBudget;
  }

  person->isExist = false;

  agesList.pop_front();
  givingEidGift(personsList, agesList);

  return 0;
}

int initData(list<Person> &personsList, list<int> &agesList)
{
  int age = 0;
  int giftBudget;

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    Person person;
    person.id = i;
    person.isExist = true;
    person.receivedEidGift = 0;

    personsList.push_back(person);
  }

  for (auto &person : personsList)
  {
    cin >> age;

    person.age = age;

    agesList.push_back(age);
  }

  for (auto &person : personsList)
  {
    cin >> giftBudget;
    person.giftBudget = giftBudget;
  }

  agesList.sort([](int a, int b)
                { return a > b; });

  return 0;
}

list<Person>::iterator findNextOlderPerson(list<Person>::iterator notFound, list<Person>::iterator person, int age)
{
  if (!next(person)->isExist)
  {
    return notFound;
  }

  if (next(person)->age == age)
  {
    return next(person);
  }

  return findNextOlderPerson(notFound, next(person), age);
}

list<Person>::iterator findPrevOlderPerson(list<Person>::iterator notFound, list<Person>::iterator person, int age)
{
  if (!prev(person)->isExist)
  {
    return notFound;
  }

  if (prev(person)->age == age)
  {
    return prev(person);
  }

  return findPrevOlderPerson(notFound, prev(person), age);
}
