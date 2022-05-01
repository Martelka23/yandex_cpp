#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовый класс
class Person
{
public:
    Person(const string& n, const string& t) : name(n), profession(t) {}

    virtual void Walk(const string& destination) const
    {
        cout << Who() << " walks to: " << destination << endl;
    }

    string Who() const { return profession + ": " + name; }

public:
    const string profession;  // Профессия человека
    const string name;
};

// Классы наследники
class Student : public Person
{
public:
    Student(const string& name, const string& favouriteSong) : Person(name, "Student")
    {
        FavouriteSong = favouriteSong;
    }

    void Learn() const
    {
        cout << Who() << " learns" << endl;
    }

    void Walk(const string& destination) const override
    {
        Person::Walk(destination);
        SingSong();
    }

    void SingSong() const
    {
        cout << Who() << " sings a song: " << FavouriteSong << endl;
    }

public:
    string FavouriteSong;
};


class Teacher : public Person
{
public:

    Teacher(const string& name, const string& subject) : Person(name, "Teacher")
    {
        Subject = subject;
    }

    void Teach() const
    {
        cout << Who() << " teaches: " << Subject << endl;
    }

public:
    string Subject;
};


class Policeman : public Person
{
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(const Person& person) const
    {
        cout << Who() << " checks " << person.profession << ". " 
            << person.profession << "'s name is: " << person.name << endl;
    }
};

// Функция посещения места
void VisitPlaces(const Person& person, const vector<string>& places)
{
    for (const string& p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
