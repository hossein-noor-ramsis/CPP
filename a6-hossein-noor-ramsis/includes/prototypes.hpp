#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

int app(char *argv[]);

string trim(const string &s);
vector<vector<string>> readCSV(string filePath);

vector<string> splitBySlash(const string &input);
vector<string> splitByComma(const string &input);
vector<string> splitWeekDays(const string &input);

vector<int> convertDaysToCodes(const vector<string> &days);

#endif
