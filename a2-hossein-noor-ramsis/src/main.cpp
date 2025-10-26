#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <sstream>

using namespace std;

const string SHOW_TABLE_INFO = "show_table_info";
const string ENTER = "enter";
const string RESERVE_TABLE = "reserve_table";
const string EXIT = "exit";
const string SWITCH = "switch";

struct TableType
{
	static constexpr const char *DOOR = "door";
	static constexpr const char *WINDOW = "window";
	static constexpr const char *MIDDLE = "middle";
};

typedef struct
{
	int id;
	string name;

	int friendId;
	int enemyId;

	string friendName;
	string enemyName;

	int sitsTableId;
	int waitingTableId;
} Student;

typedef struct
{
	int id;
	int x;
	int y;

	int capacity;
	int remainingCapacity;
	list<string> peopleAtTheTable;

	string type;
	int bonus;

	list<string> waitingQueue;
	int waitingQueueLength;

	int score;
} Table;

typedef struct
{
	vector<Table> tables;
	vector<Student> students;
} System;

int app(System &system);
int loadData(System &system, char *argv[]);

int loadTables(System &system, string tablePath);
int loadStudents(System &system, string studentPath);
vector<vector<string>> readCSV(string filePath);

int showTableInfo(const System &system);
int enterStudent(System &system);
int reserveTable(System &system);
int exitStudent(System &system);
int switchStudents(System &system);

vector<Table> findBestTables(System &system, int studentId);
bool compareByScore(const Table &a, const Table &b);
bool compareByname(const string &a, const string &b);
bool isIncludesName(const list<string> &names, const string &target);

int main(int, char *argv[])
{
	System system;

	loadData(system, argv);
	app(system);

	return 0;
}

int loadData(System &system, char *argv[])
{
	string tablesPath = argv[1];
	string studentsPath = argv[2];

	loadTables(system, tablesPath);
	loadStudents(system, studentsPath);

	return 0;
}

int app(System &system)
{
	string command;

	while (getline(cin, command, ' '))
	{
		while (!command.empty() && (command.back() == '\r' || command.back() == '\n'))
		{
			command.pop_back();
		}

		command.erase(0, command.find_first_not_of("\r\n"));

		if (command == SHOW_TABLE_INFO)
		{
			showTableInfo(system);
			continue;
		}
		else if (command == ENTER)
		{
			enterStudent(system);
			continue;
		}
		else if (command == RESERVE_TABLE)
		{
			reserveTable(system);
			continue;
		}
		else if (command == EXIT)
		{
			exitStudent(system);
			continue;
		}
		else if (command == SWITCH)
		{
			switchStudents(system);
			continue;
		}
		else
		{
			continue;
		}
	}

	return 0;
}

int loadTables(System &system, string tablePath)
{
	vector<vector<string>> data = readCSV(tablePath);

	for (const auto &row : data)
	{
		Table table;
		table.id = stoi(row[0]);
		table.x = stoi(row[1]);
		table.y = stoi(row[2]);
		table.capacity = stoi(row[3]);
		table.type = row[4];

		table.remainingCapacity = table.capacity;
		table.waitingQueueLength = 0;
		table.score = 0;

		if (!table.type.empty() && table.type.back() == '\r')
		{
			table.type.pop_back();
		}

		if (table.type == TableType::WINDOW)
		{
			table.bonus = 6;
		}
		else if (table.type == TableType::DOOR)
		{
			table.bonus = 4;
		}
		else if (table.type == TableType::MIDDLE)
		{
			table.bonus = 2;
		}
		else
		{
			table.bonus = 0;
		}

		system.tables.push_back(table);
	}

	return 0;
}

int loadStudents(System &system, string studentPath)
{
	vector<vector<string>> data = readCSV(studentPath);

	for (const auto &row : data)
	{
		if (row.size() < 4)
		{
			cerr << "Error: Invalid row size in students data." << endl;
			continue;
		}

		Student student;
		student.id = stoi(row[0]);
		student.name = row[1];
		student.friendId = stoi(row[2]);
		student.enemyId = stoi(row[3]);

		student.sitsTableId = 0;
		student.waitingTableId = 0;

		system.students.push_back(student);
	}

	for (auto &student1 : system.students)
	{
		for (auto &student2 : system.students)
		{
			if (student1.friendId == student2.id)
			{
				student1.friendName = student2.name;
			}

			if (student1.enemyId == student2.id)
			{
				student1.enemyName = student2.name;
			}
		}
	}

	return 0;
}

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
			row.push_back(cell);
		}

		data.push_back(row);
	}

	file.close();
	return data;
}

int showTableInfo(const System &system)
{
	int tableId = 0;
	Table selectedTable;

	cin >> tableId;

	for (auto &table : system.tables)
	{
		if (table.id == tableId)
		{
			selectedTable = table;
		}
	}

	vector<string> sortedPeopleAtTheTable(selectedTable.peopleAtTheTable.begin(), selectedTable.peopleAtTheTable.end());
	sort(sortedPeopleAtTheTable.begin(), sortedPeopleAtTheTable.end(), compareByname);

	cout << "Table ID: " << selectedTable.id << endl;

	cout << "People at the table: ";
	for (size_t i = 0; i < sortedPeopleAtTheTable.size(); i++)
	{
		cout << sortedPeopleAtTheTable[i];
		if (i < sortedPeopleAtTheTable.size() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;

	cout << "Table remaining capacity: " << selectedTable.remainingCapacity << endl;
	cout << "Waiting queue length: " << selectedTable.waitingQueueLength << endl;

	return 0;
}

int enterStudent(System &system)
{
	int studentId;
	cin >> studentId;

	vector<Table> bestTables = findBestTables(system, studentId);

	for (auto table : bestTables)
	{
		cout << "Table " << table.id << ": " << table.remainingCapacity << ' ' << table.waitingQueueLength << endl;
	}

	return 0;
}

int reserveTable(System &system)
{
	string inputLine;
	int studentId = 0;
	int tableId = 0;
	Table bestTable;

	getline(cin, inputLine);
	istringstream iss(inputLine);

	iss >> studentId;
	iss >> tableId;

	auto student = find_if(system.students.begin(), system.students.end(),
												 [studentId](const Student &s)
												 { return s.id == studentId; })
										 .base();

	if (tableId)
	{
		auto table = find_if(system.tables.begin(), system.tables.end(),
												 [tableId](const Table &t)
												 { return t.id == tableId; })
										 .base();

		if (table->remainingCapacity == 0)
		{
			table->waitingQueue.push_back(student->name);
			table->waitingQueueLength++;
			student->waitingTableId = table->id;

			cout << student->name << " enters the waiting queue of table " << table->id << endl;
			return 0;
		}

		table->peopleAtTheTable.push_back(student->name);
		table->remainingCapacity--;
		student->sitsTableId = table->id;

		cout << student->name << " sits at table " << table->id << endl;

		return 0;
	}

	bestTable = findBestTables(system, studentId)[0];
	auto table = find_if(system.tables.begin(), system.tables.end(),
											 [bestTable](const Table &t)
											 { return t.id == bestTable.id; })
									 .base();

	if (table->remainingCapacity == 0)
	{
		table->waitingQueue.push_back(student->name);
		table->waitingQueueLength++;
		student->waitingTableId = table->id;

		cout << student->name << " enters the waiting queue of table " << table->id << endl;
		return 0;
	}

	table->peopleAtTheTable.push_back(student->name);
	table->remainingCapacity--;
	student->sitsTableId = table->id;

	cout << student->name << " sits at table " << table->id << endl;

	cin.clear();
	return 0;
}

int exitStudent(System &system)
{
	int studentId = 0;
	cin >> studentId;

	auto student = find_if(system.students.begin(), system.students.end(), [studentId](Student s)
												 { return s.id == studentId; })
										 .base();

	if (student->waitingTableId)
	{
		auto table = find_if(system.tables.begin(), system.tables.end(), [student](Table t)
												 { return t.id == student->waitingTableId; })
										 .base();

		table->waitingQueue.remove(student->name);
		table->waitingQueueLength--;
		student->waitingTableId = 0;
	}

	if (student->sitsTableId)
	{
		auto table = find_if(system.tables.begin(), system.tables.end(), [student](Table t)
												 { return t.id == student->sitsTableId; })
										 .base();

		table->peopleAtTheTable.remove(student->name);
		table->remainingCapacity++;
		student->sitsTableId = 0;

		if (isIncludesName(table->waitingQueue, student->friendName))
		{
			auto studentFriend = find_if(system.students.begin(), system.students.end(), [student](Student s)
																	 { return s.id == student->friendId; })
															 .base();

			table->waitingQueue.remove(studentFriend->name);
			table->peopleAtTheTable.push_back(studentFriend->name);
			table->remainingCapacity--;
			table->waitingQueueLength--;
			studentFriend->sitsTableId = table->id;
			studentFriend->waitingTableId = 0;
		}
		else if (table->waitingQueueLength)
		{
			auto waitingStudent = find_if(system.students.begin(), system.students.end(), [table](Student s)
																		{ return s.name == table->waitingQueue.front(); })
																.base();

			table->waitingQueue.pop_front();

			table->peopleAtTheTable.push_back(waitingStudent->name);
			table->remainingCapacity--;
			table->waitingQueueLength--;
			waitingStudent->sitsTableId = table->id;
			waitingStudent->waitingTableId = 0;
		}
	}

	cout << student->name << " exits!" << endl;

	return 0;
}

int switchStudents(System &system)
{
	int studentId;

	int tableId1;
	int tableId2;

	cin >> studentId;

	auto student = find_if(system.students.begin(), system.students.end(), [studentId](Student s)
												 { return s.id == studentId; })
										 .base();

	auto studentFriend = find_if(system.students.begin(), system.students.end(), [student](Student s)
															 { return s.id == student->friendId; })
													 .base();

	tableId1 = student->sitsTableId;
	tableId2 = studentFriend->sitsTableId;

	auto table1 = find_if(system.tables.begin(), system.tables.end(), [tableId1](Table t)
												{ return t.id == tableId1; })
										.base();

	auto table2 = find_if(system.tables.begin(), system.tables.end(), [tableId2](Table t)
												{ return t.id == tableId2; })
										.base();

	table1->peopleAtTheTable.remove(student->name);
	table2->peopleAtTheTable.push_back(student->name);
	student->sitsTableId = tableId2;

	table2->peopleAtTheTable.remove(studentFriend->name);
	table1->peopleAtTheTable.push_back(studentFriend->name);
	studentFriend->sitsTableId = tableId1;

	cout << student->name << " switches seats with " << studentFriend->name << '!' << endl;
	return 0;
}

vector<Table> findBestTables(System &system, int studentId)
{
	int distanceToEnemy = 0;
	int distanceToFriend = 0;

	bool hasFriend = false;
	bool hasEnemy = false;

	vector<Table> tables = system.tables;
	Student selectedStudent;

	for (auto student : system.students)
	{
		if (student.id == studentId)
		{
			selectedStudent = student;
		}
	}

	for (auto &table1 : tables)
	{
		for (auto &table2 : tables)
		{
			hasFriend = false;
			hasEnemy = false;

			if (table1.id == table2.id)
			{
				continue;
			}

			for (auto people : table2.peopleAtTheTable)
			{
				if (selectedStudent.friendName == people)
				{
					hasFriend = true;
				}

				if (selectedStudent.enemyName == people)
				{
					hasEnemy = true;
				}
			}

			if (hasFriend)
			{
				distanceToFriend = abs(table1.x - table2.x) + abs(table1.y - table2.y);
			}

			if (hasEnemy)
			{
				distanceToEnemy = abs(table1.x - table2.x) + abs(table1.y - table2.y);
			}
		}

		table1.score = distanceToEnemy - distanceToFriend + table1.bonus;

		distanceToFriend = 0;
		distanceToEnemy = 0;
	}

	sort(tables.begin(), tables.end(), compareByScore);

	return tables;
}

bool compareByScore(const Table &a, const Table &b)
{
	if (a.score == b.score)
	{
		return a.id < b.id;
	}

	return a.score > b.score;
}

bool compareByname(const string &a, const string &b)
{
	if (a == b)
	{
		return false;
	}

	bool aIsUpper = isupper(a[0]);
	bool bIsUpper = isupper(b[0]);

	if (aIsUpper && !bIsUpper)
	{
		return true;
	}

	if (!aIsUpper && bIsUpper)
	{
		return false;
	}

	return a < b;
}

bool isIncludesName(const list<string> &names, const string &target)
{
	return find(names.begin(), names.end(), target) != names.end();
}
