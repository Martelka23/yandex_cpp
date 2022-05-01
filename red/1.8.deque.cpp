#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Deque {
public:
    // Конструктор
    Deque() = default;
    // Проверка на пустоту
    bool Empty() const {
        return deque.empty() && rdeque.empty();
    }
    // Размер дека
    size_t Size() const {
        return deque.size() + rdeque.size();
    }
    // Перегрузки операторов индексации
    T& operator[](size_t index) {
        if (index >= rdeque.size())
            return deque[index - rdeque.size()];
        else
            return rdeque[rdeque.size() - 1 - index];
    }
    const T& operator[](size_t index) const {
        if (index >= rdeque.size())
            return deque[index - rdeque.size()];
        else
            return rdeque[rdeque.size() - 1 - index];
    }
    // Обращение к элементу
    T& At(const size_t& index) {
        if (index >= Size() || index < 0)
            throw out_of_range("Index out of range!");
        else
            return (*this)[index];
    }
    // Константное обращение к элементу
    const T& At(const size_t& index) const {
        if (index >= Size() || index < 0)
            throw out_of_range("Index out of range!");
        else
            return (*this)[index];
    }
    // Возвращение первого элемента
    T& Front() {
        return At(0);
    }
    // Константное возвращение первого элемента
    const T& Front() const {
        return At(0);
    }
    // Возвращение последнего элемента
    T& Back() {
        return (Empty()) ? At(0) : At(Size() - 1);
    }
    // Константное возвращение последнего элемента
    const T& Back() const {
        return (Empty()) ? At(0) : At(Size() - 1);
    }
    // Вставка элемента на первую позицию
    void PushFront(const T& elem) {
        rdeque.push_back(elem);
    }
    // Вставка элемента на последнюю позицию
    void PushBack(const T& elem) {
        deque.push_back(elem);
    }
private:
    vector<T> deque = vector<T>(0);
    vector<T> rdeque = vector<T>(0);
};

int main() {
    Deque<int> d;
    d.PushBack(1);
    d.PushBack(2);
    // d.PushFront(3);
    // d.PushFront(4);
    // d.PushFront(5);
    cout << d.Front() << endl;
    // for (int i = 0; i < 5; i++)
    //     cout << d[i] << ' ';
    return 0;
}