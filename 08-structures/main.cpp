#include <iostream>
#include <string>

using namespace std;

constexpr auto kNumMarks = 5;

struct Student
{
    string full_name, group_name;
    int marks[kNumMarks];
};

bool IsNumber(string number);
void AddStudents(Student* students, const int kNumStudents);
double* ComputeAverageMarks(Student* students, const int kNumStudents);
void PrintStudents(Student* students, const int kNumStudents);
void SortStudents(Student* students, const int kNumStudents);
void PrintGoodStudents(Student* students, const int kNumStudents);

int main()
{
    const int kNumStudents = 10;
    Student students[kNumStudents];
    AddStudents(students, kNumStudents);
    cout << string(80, '-') << endl;

    SortStudents(students, kNumStudents);
    PrintStudents(students, kNumStudents);
    cout << endl << string(80, '-') << endl;

    cout << "\nStudents with an average mark of more than 4:\n";
    PrintGoodStudents(students, kNumStudents);
    return 0;
}

bool IsNumber(string number)
{
    for (size_t i = 0; i < number.length(); i++)
        if (!isdigit(number[i]))
            return 0;
    return 1;
}

void AddStudents(Student* students, const int kNumStudents)
{
    string buf;
    for (int i = 0; i < kNumStudents; i++)
    {
        cout << i + 1 << ". Input the surname and initials (e.g., Ivanov I.I.): ";
        getline(cin, students[i].full_name);

        cout << "Input the group name of the student (e.g., IZ.11): ";
        getline(cin, students[i].group_name);

        cout << "Input his marks (5 marks [2..5]):\n";
        for (int j = 0; j < kNumMarks; j++)
        {
        repeat_mark:
            cout << string(25, ' ') << "Mark " << j + 1 << " = ";
            getline(cin, buf);
            if (!IsNumber(buf))
            {
                cout << "Error: marks must be digits only!\n";
                goto repeat_mark;
            }
            students[i].marks[j] = stoi(buf);
        }
        cout << endl;
    }
}

void SortStudents(Student* students, const int kNumStudents)
{
    for (int i = 0; i < kNumStudents - 1; i++)
        for (int j = 0; j < kNumStudents - i - 1; j++)
            if (students[j].group_name > students[j + 1].group_name)
                swap(students[j], students[j + 1]);
}

double* ComputeAverageMarks(Student* students, const int kNumStudents)
{
    double* average_marks = new double[kNumStudents];
    for (int i = 0; i < kNumStudents; i++)
    {
        average_marks[i] = 0;
        for (int j = 0; j < kNumMarks; j++)
            average_marks[i] += students[i].marks[j];
        average_marks[i] /= kNumMarks;
    }
    return average_marks;
}

void PrintStudents(Student* students, const int kNumStudents)
{
    double* average_marks = ComputeAverageMarks(students, kNumStudents);
    for (int i = 0; i < kNumStudents; i++)
    {
        cout << "\nFull name: " << students[i].full_name;
        cout << "\nGroup: " << students[i].group_name;
        cout << "\nAverage mark: " << average_marks[i] << endl;
    }
    delete[] average_marks;
}

void PrintGoodStudents(Student* students, const int kNumStudents)
{
    double* average_marks = ComputeAverageMarks(students, kNumStudents);

    bool students_found = false;
    for (int i = 0; i < kNumStudents; i++)
    {
        if (average_marks[i] > 4)
        {
            students_found = true;
            cout << "\nFull name: " << students[i].full_name;
            cout << "\nGroup: " << students[i].group_name << endl;
        }
    }
    if (!students_found)
        cout << "No students were found.\n";

    delete[] average_marks;
}