#include <iostream>
#include <string>
#include <iomanip>

#define kStudents 10
#define kMarks 5

using namespace std;

struct Student {
	string full_name;
	int group_number;
	int marks[kMarks];
};

bool isNumber(string s) {
	bool result = true;
	for (int i = 0; i < int(s.length()); i++)
	{
		if ((s[i] < '0') || (s[i] > '9')) {
			result = false;
			break;
		}
	}
	return result;
}

void addStudents(Student *a) {
	string buf;
	for (int i = 0; i < kStudents; i++) {
		cout << i + 1 << ". Input the surname and initials (e.g., Ivanov I.I.): ";
		getline(cin, a[i].full_name);

	repeat_group:
		cout << "Input the Group number of the student(e.g., 11): ";
		getline(cin, buf);
		if (isNumber(buf))
			a[i].group_number = atoi(buf.c_str());
		else {
			cout << "Error: group number must be digits only!" << endl;
			goto repeat_group;
		}
		cout << "Input his marks (5 marks [2..5]):" << endl;
		for (int j = 0; j < kMarks; j++) {
		repeat_mark:
			cout << string(25, ' ') << "Mark " << j + 1 << " = ";
			getline(cin, buf);
			if (isNumber(buf))
				a[i].marks[j] = atoi(buf.c_str());
			else {
				cout << "Error: marks must be digits only!" << endl;
				goto repeat_mark;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void sortStudents(Student *a) {
	for (int i = 0; i < kStudents; i++) {
		for (int j = 0; j < kStudents - i - 1; j++) {
			if (a[j].group_number > a[j + 1].group_number) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void printStudents(Student *a) {
	for (int i = 0; i < kStudents; i++) {
		cout << i + 1 << ". " << a[i].full_name << endl;
	}
	cout << endl;
}

void printHonours(Student *a) {
	bool have_honours = false;
	double average_mark;
	const double kEps = 1e-15;

	for (int i = 0; i < kStudents; i++)
	{
		average_mark = 0;
		for (int j = 0; j < kMarks; j++)
		{
			average_mark += static_cast<double>(a[i].marks[j]);
		}
		average_mark = average_mark / 5;
		if ((average_mark - 4.0) > kEps) {
			have_honours = true;
			cout << "|" << setw(4) << a[i].full_name << setw(4);
			cout << "|" << setw(4) << a[i].group_number << setw(4);
			cout << "|" << endl;
		}
	}

	if (!have_honours) {
		cout << "The average mark of all students is below 4";
		cout << endl;
	}
}

int main() {
	Student stud_list[kStudents];
	addStudents(stud_list);
	sortStudents(stud_list);
	printStudents(stud_list);
	cout << "Students with high average mark: ";
	cout << endl;
	printHonours(stud_list);
	return 0;
}