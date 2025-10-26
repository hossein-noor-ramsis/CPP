#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//? test case 3 feild because the (2s) time limit

typedef struct
{
  int id;
  string name;
  float price;
} Item;

typedef struct
{
  int id;
  vector<Item> items;
  float totalPrice;
  float totalPriceWithTax;
  float discount;
} Collection;

typedef struct
{
  float discountPercentage;
  float maxDiscount;
  float minimumPurchase;
  float maximumOptimalPurchase;
  float tax;
} PricingRules;

int getData(vector<Item> &menuList, PricingRules &rules);
void findSubLists(vector<Item> &menuList, vector<vector<Item>> &subLists, vector<Item> &currentSubList, unsigned int index);
int calculateCollectionsValue(vector<vector<Item>> &subLists, vector<Collection> &collections, PricingRules rules);
int findBestCollections(vector<Collection> &collections, Collection &bestCollection, PricingRules rules);

int main()
{
  vector<Item> menuList;
  vector<Item> currentSubList;
  vector<vector<Item>> subLists;

  vector<Collection> collections;
  Collection bestCollection;

  PricingRules rules;

  getData(menuList, rules);
  findSubLists(menuList, subLists, currentSubList, 0);

  calculateCollectionsValue(subLists, collections, rules);

  findBestCollections(collections, bestCollection, rules);

  for (auto &item : bestCollection.items)
  {
    cout << item.name << endl;
  }

  return 0;
}

int getData(vector<Item> &menuList, PricingRules &rules)
{
  int menuItemCount;

  cin >> menuItemCount;
  cin >> rules.discountPercentage;
  cin >> rules.minimumPurchase;
  cin >> rules.maxDiscount;
  rules.tax = 10;
  rules.maximumOptimalPurchase = rules.maxDiscount / rules.discountPercentage * 100;

  for (int i = 0; i < menuItemCount; i++)
  {
    Item item;

    item.id = i + 1;
    cin >> item.name;
    cin >> item.price;

    menuList.push_back(item);
  }

  return 0;
}

void findSubLists(vector<Item> &menuList, vector<vector<Item>> &subLists, vector<Item> &currentSubList, unsigned int index)
{
  if (index == menuList.size())
  {
    subLists.push_back(currentSubList);
    return;
  }

  currentSubList.push_back(menuList[index]);
  findSubLists(menuList, subLists, currentSubList, index + 1);

  currentSubList.pop_back();
  findSubLists(menuList, subLists, currentSubList, index + 1);
}

int calculateCollectionsValue(vector<vector<Item>> &subLists, vector<Collection> &collections, PricingRules rules)
{
  int id = 1;
  for (auto &list : subLists)
  {
    Collection collection;
    collection.id = id;
    collection.items = list;
    collection.totalPrice = 0;
    collection.discount = 0;

    for (auto &item : list)
    {
      collection.totalPrice += item.price;
    }

    collection.totalPriceWithTax = collection.totalPrice + (collection.totalPrice / 100 * rules.tax);

    if (collection.totalPriceWithTax >= rules.minimumPurchase)
    {
      collection.discount = collection.totalPriceWithTax * rules.discountPercentage / 100;
    }

    collections.push_back(collection);
    id++;
  }

  return 0;
}

int findBestCollections(vector<Collection> &collections, Collection &bestCollection, PricingRules rules)
{
  vector<Collection> bestCollections;

  for (auto &collection : collections)
  {
    if (collection.totalPriceWithTax < rules.minimumPurchase)
    {

      continue;
    }

    if (collection.discount > rules.maxDiscount)
    {
      continue;
    }

    bestCollections.push_back(collection);
  }

  sort(bestCollections.begin(), bestCollections.end(), [](Collection a, Collection b)
       { return a.totalPriceWithTax > b.totalPriceWithTax; });

  bestCollection = bestCollections.front();

  return 0;
}
