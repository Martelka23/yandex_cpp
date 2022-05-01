#include "test_runner.h"
#include <vector>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template <typename T>
class Table {
public:

  // Конструктор
  Table(const size_t& l, const size_t& c) {
    Resize(l, c);
  }

  // Изменение размеров
  void Resize(size_t l, size_t c) {
    if (!(l && c)) {
      l = 0;
      c = 0;
    }
    table.resize(l);
    for (auto& item : table)
      item.resize(c);
    line = l;
    column = c;
  }


  // Размер таблицы
  pair<size_t, size_t> Size() const {
    return make_pair(line, column);
  }

  // Операторы возврата
  const vector<T>& operator[](const int& index) const { return table[index]; }
  vector<T>& operator[](const int& index) { return table[index]; }

private:

  vector<vector<T>> table;
  size_t line, column;
  
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
  ASSERT_EQUAL(t[0][0], 42);

}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);

  return 0;
}
