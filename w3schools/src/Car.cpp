#include "../includes/main.hpp"

// define static variable
int Car::count = 0;

// define constructor
Car::Car(string newBrand, string newModel, int newYear)
{
  this->brand = newBrand;
  this->model = newModel;
  this->year = newYear;

  Car::count++;
}

// define set methods
void Car::setBrand(string newBrand)
{
  this->brand = newBrand;
}

void Car::setModel(string newModel)
{
  this->model = newModel;
}

void Car::setYear(int newYear)
{
  this->year = newYear;
}

// define get methods
string Car::getBrand()
{
  return brand;
}

string Car::getModel()
{
  return model;
}

int Car::getYear()
{
  return year;
}

int Car::getCount()
{
  return count;
}

// define static variable
string Car1::country = "USA";
string Car2::country = "Germany";
