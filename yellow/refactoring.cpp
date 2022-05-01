#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Human {
public:
	Human(const string& type) : Type(type) {}

	string GetType() const {
		return Type;
	}

	void IntroduceSelf() const {
		cout << GetType() << ": " << GetName();
	}

	void JustWalk(const string& destination) const {
		IntroduceSelf();
		cout << " walks to: " << destination << endl;
	}

	virtual void Walk(const string& destination) const = 0;

	virtual string GetName() const = 0;

	virtual ~Human() = default;

private:
	const string Type;
};

class Student : public Human {
public:

    Student(const string& name, const string& favouriteSong)
		: Human("Student"), Name(name), FavouriteSong(favouriteSong) {}

    string GetName() const override {
    	return Name;
    }

    string GetFavouriteSong() const {
    	return FavouriteSong;
    }

    void Learn() {
    	IntroduceSelf();
        cout << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        JustWalk(destination);
        SingSong();
    }

    void SingSong() const {
    	IntroduceSelf();
        cout << " sings a song: " << GetFavouriteSong() << endl;
    }

private:
    const string Name;
    const string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const string& name, const string& subject)
		: Human("Teacher"), Name(name), Subject(subject) {}

    string GetName() const override {
    	return Name;
    }

    string GetSubject() const {
    	return Subject;
    }

    void Teach() {
    	IntroduceSelf();
        cout << " teaches: " << GetSubject() << endl;
    }

    void Walk(const string& destination) const override {
        JustWalk(destination);
    }

private:
    const string Name;
    const string Subject;
};


class Policeman : public Human {
public:
    Policeman(const string& name)
		: Human("Policeman"),  Name(name) {}

    string GetName() const override {
    	return Name;
    }

    void Check(const Human& human) const {
    	IntroduceSelf();
    	cout << " checks " << human.GetType() << ". " << human.GetType()
    			<< "'s name is: " << human.GetName() << endl;
    }

    void Walk(const string& destination) const override {
        JustWalk(destination);
    }

private:
    const string Name;
};

void VisitPlaces(const Human& human, const vector<string>& places) {
	for (const string& place : places) {
		human.Walk(place);
	}
}