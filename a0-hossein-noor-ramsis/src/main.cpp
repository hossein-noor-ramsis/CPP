#include <iostream>
using namespace std;

string encrypt(string input, int key);
string decrypt(string input, int key);

int main()
{
	string input;

	string output;

	int key;
	string command;

	getline(cin, input);
	cin >> key;
	cin >> command;

	if (command == "Encrypt")
	{
		output = encrypt(input, key);
	}
	else if (command == "Decrypt")
	{
		output = decrypt(input, key);
	}

	cout << output << endl;

	return 0;
}

string encrypt(string input, int key)
{
	string output = input;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		char value = input[i];

		if (input[i] >= 65 && input[i] <= 90)
		{
			value = input[i] + key <= 90 ? input[i] + key : input[i] + key - 26;
		}

		if (input[i] >= 97 && input[i] <= 122)
		{
			value = input[i] + key <= 122 ? input[i] + key : input[i] + key - 26;
		}

		output[i] = value;
	}

	return output;
}

string decrypt(string input, int key)
{
	string output = input;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		char value = input[i];

		if (input[i] >= 65 && input[i] <= 90)
		{
			value = input[i] - key >= 65 ? input[i] - key : input[i] - key + 26;
		}

		if (input[i] >= 97 && input[i] <= 122)
		{
			value = input[i] - key >= 97 ? input[i] - key : input[i] - key + 26;
		}

		output[i] = value;
	}

	return output;
}

//* run & build
// cd ./a0-hossein-noor-ramsis
// g++ ./src/main.cpp -o ./src/build/main.exe
// ./src/build/main.exe

//* test
// dos2unix judge.sh
// ./judge.sh -t
