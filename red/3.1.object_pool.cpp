#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate() {
    T* p = (reserv.empty()) ? new T : reserv.front();
    in_use.insert(p);
    if (!reserv.empty())
      reserv.pop();
    return p;
  }

  T* TryAllocate() {
    T* p = (reserv.empty()) ? nullptr : reserv.front();
    if (!reserv.empty()) {
      reserv.pop();
      in_use.insert(p);
    }
    return p;
  }

  void Deallocate(T* object) {
    if (in_use.count(object)) {
      reserv.push(object);
      in_use.erase(object);
    } else
      throw invalid_argument("err");
  }

  ~ObjectPool() {
    while (!reserv.empty()) {
      delete reserv.front();
      reserv.pop();
    }
    for (T* x : in_use) {
      delete x;
    }
  }
  

private:
  // Добавьте сюда поля
  set<T*> in_use;
  queue<T*> reserv;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
