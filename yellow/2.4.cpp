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

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational();
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};

void TestConstructor()
{
    {
        Rational test;
        AssertEqual(test.Numerator(), 0, "1 Constructor test");
        AssertEqual(test.Denominator(), 1, "2 Constructor test");
    }
    {
        Rational test(3, 4);
        AssertEqual(test.Numerator(), 3, "3 Constructor test");
        AssertEqual(test.Denominator(), 4, "4 Constructor test");
    }
    {
        Rational test(2, 4);
        AssertEqual(test.Numerator(), 1, "5 Constructor test");
        AssertEqual(test.Denominator(), 2, "6 Constructor test");
    }
    {
        Rational test(-2, 4);
        AssertEqual(test.Numerator(), -1, "7 Constructor test");
        AssertEqual(test.Denominator(), 2, "8 Constructor test");
    }
    {
        Rational test(6, -9);
        AssertEqual(test.Numerator(), -2, "9 Constructor test");
        AssertEqual(test.Denominator(), 3, "10 Constructor test");
    }
    {
        Rational test(-10, -10);
        AssertEqual(test.Numerator(), 1, "11 Constructor test");
        AssertEqual(test.Denominator(), 1, "12 Constructor test");
    }
    {
        Rational test(0, 25);
        AssertEqual(test.Numerator(), 0, "13 Constructor test");
        AssertEqual(test.Denominator(), 1, "14 Constructor test");
    }
}

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestConstructor, "TestConstructor");

  return 0;
}
