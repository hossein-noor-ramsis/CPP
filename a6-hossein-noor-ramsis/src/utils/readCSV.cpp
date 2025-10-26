#include "../../includes/main.hpp"

vector<vector<string>> readCSV(string filePath)
{
  vector<vector<string>> data;
  string line;

  ifstream file(filePath);
  if (!file.is_open())
  {
    cerr << "Error: Could not open file '" << filePath << "'." << endl;
    return data;
  }

  getline(file, line);
  while (getline(file, line))
  {
    vector<string> row;
    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ','))
    {
      row.push_back(trim(cell));
    }

    data.push_back(row);
  }

  file.close();
  return data;
}
