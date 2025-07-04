#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Student
{
    int roll;
    string name;
    float marks;
};

Student students[MAX];

void addStudent()
{
    int count = 0;
    if (count >= MAX)
    {
        cout << "Maximum limit reached !" << endl;
        return;
    }
    cout << "Enter roll number: ";
    cin >> students[count].roll;
    cin.ignore(); // clear buffer

    cout << "Enter name: ";
    getline(cin, students[count].name);

    cout << "Enter marks: ";
    cin >> students[count].marks;

    count++;
    cout << "Student added successfully!\n\n";
}
void displayStudents()
{
    int count = 0;
    if (count == 0)
    {
        cout << "No student records found.\n";
        return;
    }

    cout << "Student List : \n";
    for (int i = 0; i < count; i++)
    {
        cout << "Roll :" << students[i].roll << endl;
        cout << "Name :" << students[i].name << endl;
        cout << "Marks :" << students[i].marks << endl;
    }
    cout << endl;
}
void searchStudent()
{
    int count = 0;
    int roll;
    cout << "Enter roll number to search :";
    cin >> roll;

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            cout << "Found :" << students[i].name << "(Marks :" << students[i].marks << ")\n\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Students not found ! \n\n";
    }
}
void sortByName()
{
    int count = 0;
    sort(students, students + count, [](Student a, Student b)
         { return a.name < b.name; });
    cout << "Students sorted by name! \n\n";
}

int main()
{
    int choice;
    do
    {
        cout << "\n-- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2.Display Students \n";
        cout << "3.Search Student by Roll Number \n";
        cout << "4.Sort Students by Name\n";
        cout << "5.Exit\n";
        cout << "Enter choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            sortByName();
            break;
        case 5:
            cout << "Exiting... \n";
            break;

        default:
            cout << "Invalid choice !\n";
        }
    } while (choice != 5);
    return 0;
}
