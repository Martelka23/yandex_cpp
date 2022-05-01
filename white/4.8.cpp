#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
    Student(const string& n, const string& s, const int& d, const int& m, const int& y)
    {
        name = n;
        surname = s;
        day = d;
        month = m;
        year = y;
    }
    void ShowName()
    {
        cout << name << " " << surname << endl;
    }
    void ShowDate()
    {
        cout << day << "." << month << "." << year << endl;
    }
private:
    string name, surname;
    long int day, month, year;
};

int main()
{
    vector<Student> students;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, surname;
        long int day, month, year;
        cin >> name >> surname >> day >> month >> year;
        students.push_back(Student(name, surname, day, month, year));
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        int k;
        cin >> command >> k;
        if (k > (int)students.size() || k < 1)
        {
            cout << "bad request" << endl;
            continue;
        }
        k--;
        if (command == "name")
            students[k].ShowName();
        else if (command == "date")
            students[k].ShowDate();
        else
            cout << "bad request" << endl;
    }

    return 0;
}