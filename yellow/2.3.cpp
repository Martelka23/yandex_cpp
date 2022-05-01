#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};

void TestAll()
{
    {
        Person person;
        AssertEqual(person.GetFullName(2000), "Incognito", "1 test");
        person.ChangeFirstName(2000, "Andrew");
        AssertEqual(person.GetFullName(2000), "Andrew with unknown last name", "2 test");
        AssertEqual(person.GetFullName(1999), "Incognito", "3 test");
        person.ChangeLastName(2001, "Isupov");
        AssertEqual(person.GetFullName(2020), "Andrew Isupov", "4 test");
        AssertEqual(person.GetFullName(1999), "Incognito", "5 test");
        person.ChangeLastName(2014, "Martel");
        AssertEqual(person.GetFullName(2020), "Andrew Martel", "6 test");
        AssertEqual(person.GetFullName(1999), "Incognito", "7 test");
    }
    {
        Person person;
        person.ChangeLastName(2001, "Isupov");
        AssertEqual(person.GetFullName(1999), "Incognito", "8 test");
        AssertEqual(person.GetFullName(2001), "Isupov with unknown first name", "9 test");
        AssertEqual(person.GetFullName(2010), "Isupov with unknown first name", "10 test");
        person.ChangeFirstName(2000, "Andrew");
        AssertEqual(person.GetFullName(2001), "Andrew Isupov", "11 test");
        person.ChangeFirstName(2003, "Andrei");
        AssertEqual(person.GetFullName(2003), "Andrei Isupov", "12 test");
    }
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestAll, "TestAll");

  return 0;
}
