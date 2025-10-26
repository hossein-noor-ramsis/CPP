#include "../includes/main.hpp"

int main()
{
  // Create an object of Car
  Car1 carObj1("Ford", "Mustang", 1969);
  Car2 carObj2("BMW", "X5", 1999);

  Car1 *ptr1 = &carObj1;
  unique_ptr<Car2> ptr2 = make_unique<Car2>("Mercedes", "Benz", 1934); // Smart pointer
  // Car2 *ptr2 = new Car2("Mercedes", "Benz", 1934);

  // Print attribute values
  // cout << carObj1.getBrand() << " " << carObj1.getModel() << " " << carObj1.getYear() << endl;
  // cout << carObj2.getBrand() << " " << carObj2.getModel() << " " << carObj2.getYear() << endl;

  // cout << carObj1.getCountry() << endl;
  // cout << carObj2.getCountry() << endl;

  // cout << "Total cars: " << Car::getCount() << endl;

  // delete ptr2;

  cout << ptr1->getBrand() << endl;
  cout << ptr2->getBrand() << endl;

  return 0;
}
