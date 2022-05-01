#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
using namespace std;

// Перегрузка операторов для дат
#define DATE_OPERATORS(op) \
bool operator op (const Date& a, const Date& b) { \
  return vector<int> {a.year, a.month, a.day} op vector<int> {b.year, b.month, b.day}; \
}

DATE_OPERATORS(==);
DATE_OPERATORS(<);

// Перегрузка операторов для времени
#define TIME_OPERATOR(op) \
bool operator op (const Time& a, const Time& b) { \
  return vector<int> {a.hours, a.minutes} op vector<int> {b.hours, b.minutes}; \
}

TIME_OPERATOR(==);
TIME_OPERATOR(<);

// // Перегрузка оператора сравнения для дат
// bool operator<(const Date& a, const Date& b) {
//   return vector<int> {a.year, a.month, a.day} < vector<int> {b.year, b.month, b.day};
// }
// // Перегрузка оператора равенства для дат
// bool operator==(const Date& a, const Date& b) {
//   return vector<int> {a.year, a.month, a.day} == vector<int> {b.year, b.month, b.day};
// }
// Перегрузка оператора вывода для дат
ostream& operator<<(ostream& os, const Date& a) {
  os << setw(4) << setfill('0') << a.year << setw(2) << a.month << setw(2) << a.day;
  return os;
}

// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time
#define SORT_BY(field) \
[](const AirlineTicket& a, const AirlineTicket& b) \
{ return a.field < b.field; }

void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}
