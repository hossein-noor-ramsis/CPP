// Create a Car class with some attributes
class Car
{
private:
  static int count;

  string brand;
  string model;
  int year;

public:
  // declare constructor
  Car(string brand, string model, int year);

  // declare set methods
  void setBrand(string brand);

  void setModel(string model);

  void setYear(int year);

  // declare get methods
  string getBrand();

  string getModel();

  int getYear();

  static int getCount();
};

// Car1 class
class Car1 : public Car
{
private:
  static string country;

public:
  Car1(string newBrand, string newModel, int newYear) : Car(newBrand, newModel, newYear)
  {
    cout << "Car1 constructor" << endl;
  }

  // get methods
  string getCountry()
  {
    return country;
  }
};

// Car2 class
class Car2 : public Car
{
private:
  static string country;

public:
  Car2(string newBrand, string newModel, int newYear) : Car(newBrand, newModel, newYear) {}

  // get methods
  string getCountry()
  {
    return country;
  }
};
