#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    surnames[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    // с помощью двоичного поиска
    ostringstream os;
    auto nameit = names.upper_bound(year);
    auto surnameit = surnames.upper_bound(year);
    if (nameit == names.begin() && surnameit == surnames.begin())
      os << "Incognito";
    else if (nameit != names.begin() && surnameit == surnames.begin())
      os << prev(nameit)->second << " with unknown last name";
    else if (nameit == names.begin() && surnameit != surnames.begin())
      os << prev(surnameit)->second << " with unknown first name";
    else
      os << prev(nameit)->second << " " << prev(surnameit)->second;

    return os.str();
  }
private:
  // приватные поля
  map<int, string> names;
  map<int, string> surnames;
};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
