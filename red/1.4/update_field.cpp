#include "airline_ticket.h"
#include "test_runner.h"

#include <iomanip>

using namespace std;

// Перегрузка операторов для дат
#define DATE_OPERATORS(op) \
bool operator op (const Date& a, const Date& b) { \
  return vector<int> {a.year, a.month, a.day} op vector<int> {b.year, b.month, b.day}; \
}

DATE_OPERATORS(==);
DATE_OPERATORS(<);

// Перегрузка оператора вывода для дат
ostream& operator<<(ostream& os, const Date& a) {
  os << setw(4) << setfill('0') << a.year << setw(2) << a.month << setw(2) << a.day;
  return os;
}

// // Перегрузка оператора присваивания для даты
// Date& Date::operator=(const Date& a) {
//   year = a.year;
//   month = a.month;
//   day = a.day;

//   return *this;
// }
// Перегрузка оператора ввода для даты
istream& operator>>(istream& is, Date& a) {
  is >> a.year;
  is.ignore(1);
  is >> a.month;
  is.ignore(1);
  is >> a.day;

  return is;
}

// Перегрузка операторов для времени
#define TIME_OPERATOR(op) \
bool operator op (const Time& a, const Time& b) { \
  return vector<int> {a.hours, a.minutes} op vector<int> {b.hours, b.minutes}; \
}

TIME_OPERATOR(==);
TIME_OPERATOR(<);


// // Перегрузка оператора присваивания для времени
// Time& Time::operator=(const Time& a) {
//   hours = a.hours;
//   minutes = a.minutes;

//   return *this;
// }

// Перегрузка оператора ввода для времени
istream& operator>>(istream& is, Time& a) {
  is >> a.hours;
  is.ignore(1);
  is >> a.minutes;

  return is;
}

// Вывод Time
ostream& operator<<(ostream& os, const Time& time) {
  os << setfill('0') << setw(2) << time.hours << ":" << setw(2) << time.minutes;

  return os;
}

// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time
#define UPDATE_FIELD(ticket, field, values) \
{ \
  map<string, string>::const_iterator it; \
  it = values.find(#field); \
  if (it != values.end()) \
  { \
    istringstream is(it->second); \
    is >> ticket.field; \
  } \
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
