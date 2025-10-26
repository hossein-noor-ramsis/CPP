#ifndef PROTOTYPES_HPP
#define PROTOTYPES_HPP

vector<vector<string>> readCSV(string filePath);

vector<string> splitByColon(const string &input);

string trim(const string &s);

double truncateTo(double value, int decimals);

bool compareByPriorityAndName(Quest *a, Quest *b);

bool compareQuests(Quest *a, Quest *b);

int app(System &system);

int createTemplate(System &system);

int autoGenerate(System &system);

int generateTest(System &system);

int attend(System &system);

int reportAll(System &system);

int reportSubject(System &system);

int reportTest(System &system);

int reportTests(System &system);

#endif
