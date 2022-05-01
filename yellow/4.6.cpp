#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};


// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons)
{
  // Median age
  cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
  // Median age for females
  auto it1 = partition(begin(persons), end(persons), [](const Person& x) { return x.gender == Gender::FEMALE; });
  cout << "Median age for females = " << ComputeMedianAge(begin(persons), it1) << endl;
  // Median age for males
  auto it2 = partition(begin(persons), end(persons), [](const Person& x) { return x.gender == Gender::MALE; });
  cout << "Median age for males = " << ComputeMedianAge(begin(persons), it2) << endl;
  // Median age for employed females
  auto it3 = partition(begin(persons), end(persons), [](const Person& x) { return x.gender == Gender::FEMALE && x.is_employed; });
  cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), it3) << endl;
  // Median age for unemployed females
  auto it4 = partition(begin(persons), end(persons), [](const Person& x) { return x.gender == Gender::FEMALE && !x.is_employed; });
  cout << "Median age for unemployed females = " << ComputeMedianAge(begin(persons), it4) << endl;
  // Median age for employed males
  auto it5 = partition(begin(persons), end(persons), [](const Person& x) { return x.gender == Gender::MALE && x.is_employed; });
  cout << "Median age for employed males = " << ComputeMedianAge(begin(persons), it5) << endl;
  // Median age for unemployed males
  auto it6 = partition(begin(persons), end(persons), [](const Person& x) { return x.gender == Gender::MALE && !x.is_employed; });
  cout << "Median age for unemployed males = " << ComputeMedianAge(begin(persons), it6) << endl;
}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}