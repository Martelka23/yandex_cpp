#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  // Увеличение забронированной памяти
  void Expansion(size_t expected_size) {
    while (capacity < size) {
      capacity *= 2;
    }
    T* old_data = *data;
    data = new T[capacity];
    
  }

  // Конструктор по умолчанию
  SimpleVector() data(nullptr) {}

  // Конструктор
  explicit SimpleVector(size_t new_size) {
    capacity = 1;
    size = new_size;
    
  }

  // Деструктор
  ~SimpleVector();

  T& operator[](size_t index) { return *(data + index); }

  T* begin() { return data; }
  T* end() {return (data + size); }

  size_t Size() const { return size; }
  size_t Capacity() const { return capacity; }
  void PushBack(const T& value);

private:
  // Добавьте поля для хранения данных вектора
  T* data;
  size_t size = 0;
  size_t capacity = 0;
};
