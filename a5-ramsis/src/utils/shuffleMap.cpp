#include "../../includes/main.hpp"

map<int, shared_ptr<Enemy>> shuffleWave(const map<int, shared_ptr<Enemy>> &wave)
{
  vector<int> keys;
  vector<shared_ptr<Enemy>> values;

  for (const auto &pair : wave)
  {
    keys.push_back(pair.first);
    values.push_back(pair.second);
  }

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine rng(seed);

  shuffle(keys.begin(), keys.end(), rng);
  shuffle(values.begin(), values.end(), rng);

  map<int, shared_ptr<Enemy>> result;
  for (size_t i = 0; i < keys.size(); ++i)
  {
    result[keys[i]] = values[i];
  }

  return result;
}
