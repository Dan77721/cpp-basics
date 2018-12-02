#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string sentences;
	ifstream fin("file.txt");

	if (!fin.is_open()) {
		cout << "can't open file!" << endl;
		return 1;
	}

	int number = 0;
	char buf;
	while ((!fin.eof()) && (number < 3)) {
		fin.get(buf);
		sentences += buf;
		if ((buf == '.') || (buf == '?') || (buf == '!'))
			number++;
	}

	cout << "Sentences: " << endl;
	for (int i = 0; i < static_cast<int>(sentences.length()); i++)
	{
		cout << sentences[i];
	}

	cout << endl << endl << "Inverted sentences: " << endl;
	for (int i = sentences.length() - 1; i >= 0; i--)
	{
		cout << sentences[i];
	}
	cout << endl;
	fin.close();
	return 0;
}